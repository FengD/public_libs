##############################################################################
#
# Freescale Confidential Proprietary
#
# Copyright (c) 2014 Freescale Semiconductor;
# All Rights Reserved
#
##############################################################################
#
# THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
# INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
# IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
# THE POSSIBILITY OF SUCH DAMAGE.
#
##############################################################################

SDK_ROOT := $(call path_relative_to,$(CURDIR),$(CURR_SDK_ROOT))

ARM_LIB = libcommunication_protobuf.a

##############################################################################
# libcommunication_protobuf.a
##############################################################################

ARM_LIB_SRCS += itd_ipd_geometry_msgs.pb.cc
ARM_LIB_SRCS += itd_ipd_sensor_msgs.pb.cc
ARM_LIB_SRCS += itd_ipd_std_msgs.pb.cc
ARM_LIB_SRCS += itd_ipd_nmea_msgs.pb.cc
ARM_LIB_SRCS += msg_transformer.cpp

ARM_INCS += -I$(SDK_ROOT)/include
ARM_INCS += -I../include
ARM_INCS += -I$(CROSS_COMPILE_SYSROOT)/usr/include/eigen3
ARM_INCS += -I$(CROSS_COMPILE_SYSROOT)/usr/include/pcl-1.8

##############################################################################
ARM_LDOPTS += -lprotobuf
ARM_LDOPTS += -lpcl_common
