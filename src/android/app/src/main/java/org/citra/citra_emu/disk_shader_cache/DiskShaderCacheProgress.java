package org.citra.citra_emu.disk_shader_cache;

import android.app.Activity;
import android.app.Dialog;
import android.os.Bundle;
import android.os.Handler;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.ProgressBar;
import android.widget.SeekBar;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.fragment.app.DialogFragment;
import androidx.fragment.app.FragmentManager;

import org.citra.citra_emu.CitraApplication;
import org.citra.citra_emu.NativeLibrary;
import org.citra.citra_emu.R;
import org.citra.citra_emu.activities.EmulationActivity;

import java.util.Objects;

public class DiskShaderCacheProgress {

    // Equivalent to VideoCore::LoadCallbackStage
    public enum LoadCallbackStage {
        Prepare,
        Decompile,
        Build,
        Complete,
    }

    private static final Object finishLock = new Object();
    private static ProgressDialogFragment fragment;

    public static class ProgressDialogFragment extends DialogFragment {

        private final Handler updateHandler = new Handler();

        ProgressBar progressBar;
        TextView progressText;
        AlertDialog dialog;

        static ProgressDialogFragment newInstance(String title, String message) {
            ProgressDialogFragment frag = new ProgressDialogFragment();
            Bundle args = new Bundle();
            args.putString("title", title);
            args.putString("message", message);
            frag.setArguments(args);
            return frag;
        }

        @NonNull
        @Override
        public Dialog onCreateDialog(Bundle savedInstanceState) {
            final Activity emulationActivity = Objects.requireNonNull(getActivity());

            final String title = Objects.requireNonNull(Objects.requireNonNull(getArguments()).getString("title"));
            final String message = Objects.requireNonNull(Objects.requireNonNull(getArguments()).getString("message"));

            LayoutInflater inflater = LayoutInflater.from(emulationActivity);
            View view = inflater.inflate(R.layout.dialog_progress_bar, null);

            progressBar = view.findViewById(R.id.progress_bar);
            progressText = view.findViewById(R.id.progress_text);
            progressText.setText("");

            setCancelable(false);
            setRetainInstance(true);

            AlertDialog.Builder builder = new AlertDialog.Builder(emulationActivity);
            builder.setTitle(title);
            builder.setMessage(message);
            builder.setView(view);
            builder.setNegativeButton(R.string.abort_button, (dialog, whichButton) -> {

            });

            dialog = builder.create();
            dialog.create();

            synchronized (finishLock) {
                finishLock.notifyAll();
            }

            return dialog;
        }

        private void onUpdateProgress(LoadCallbackStage stage, int progress, int max) {
            updateHandler.post(()->{
                progressBar.setProgress(progress);
                progressBar.setMax(max);
                progressText.setText(String.format("%d/%d", progress, max));
                if (stage == LoadCallbackStage.Build){
                    dialog.setMessage("Building shaders");
                }
            });
        }
    }

    private static void prepareDialog() {
        NativeLibrary.sEmulationActivity.get().runOnUiThread(() -> {
            final EmulationActivity emulationActivity = NativeLibrary.sEmulationActivity.get();
            fragment = ProgressDialogFragment.newInstance("Loading...", "Preparing shaders");
            fragment.show(emulationActivity.getSupportFragmentManager(), "diskShaders");
        });

        synchronized (finishLock) {
            try {
                finishLock.wait();
            } catch (Exception ignored) {
            }
        }
    }

    public static void loadProgress(LoadCallbackStage stage, int progress, int max) {
        switch (stage) {
            case Prepare:
                prepareDialog();
                break;
            case Decompile:
            case Build:
                fragment.onUpdateProgress(stage, progress, max);
                break;
            case Complete:
                // Workaround for when dialog is dismissed when the app is in the background
                fragment.dismissAllowingStateLoss();
                break;
        }
    }
}
