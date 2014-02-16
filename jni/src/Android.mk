LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

LOCAL_WHOLE_STATIC_LIBRARIES := gear2d_static logo gear2d_components

include $(BUILD_SHARED_LIBRARY)
