LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

LOCAL_WHOLE_STATIC_LIBRARIES := gear2d_static space2d renderer2 logo mouse audiosource touch kinematic2d

include $(BUILD_SHARED_LIBRARY)
