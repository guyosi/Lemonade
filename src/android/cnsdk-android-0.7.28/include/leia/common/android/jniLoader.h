/*
 * Copyright 2023 (c) Leia Inc.  All rights reserved.
 *
 * NOTICE:  All information contained herein is, and remains
 * the property of Leia Inc. and its suppliers, if any.  The
 * intellectual and technical concepts contained herein are
 * proprietary to Leia Inc. and its suppliers and may be covered
 * by U.S. and Foreign Patents, patents in process, and are
 * protected by trade secret or copyright law.  Dissemination of
 * this information or reproduction of this materials strictly
 * forbidden unless prior written permission is obtained from
 * Leia Inc.
 */
#pragma once

#include "leia/common/api.h"
#include "leia/common/jniTypes.h"

BEGIN_CAPI_DECL

LEIA_COMMON_API
void leia_jni_init_native_app(JavaVM* vm);
LEIA_COMMON_API
void leia_jni_deinit_native_app();

LEIA_COMMON_API
jint leia_jni_on_load(JavaVM* vm);
LEIA_COMMON_API
void leia_jni_on_unload(JavaVM* vm);

LEIA_COMMON_API
bool leia_jni_is_initialized();
LEIA_COMMON_API
JavaVM* leia_jni_get_java_vm();

END_CAPI_DECL
