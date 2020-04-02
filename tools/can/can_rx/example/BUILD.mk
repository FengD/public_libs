##############################################################################
#
# Freescale Confidential Proprietary
#
# Copyright (c) 2016 Freescale Semiconductor;
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

ARM_APP = canrx_example

# ARM_DEFS += -fopenmp

##############################################################################
# ARM_APP
##############################################################################

ARM_APP_SRCS += main.cpp

##############################################################################
# include
##############################################################################
ARM_INCS += -I$(SDK_ROOT)/include

ARM_INCS += -I../../../../../tools/hlog/include
ARM_INCS += -I../../../../../util/include
ARM_INCS += -I../../../../../tools/can/can_pack_unpack/include
ARM_INCS += -I../../../../../communication/socket_can/include
ARM_INCS += -I../../../../../tools/can/can_rx/include
##############################################################################
# static libs
##############################################################################
ARM_APP_LIBS += ../../../../../tools/hlog/$(ODIR)/libhlog.a
ARM_APP_LIBS += ../../../../../util/$(ODIR)/libutil.a
ARM_APP_LIBS += ../../../../../tools/can/can_pack_unpack/$(ODIR)/libcan_pack_unpack.a
ARM_APP_LIBS += ../../../../../communication/socket_can/$(ODIR)/libsocket_can.a
ARM_APP_LIBS += ../../../../../tools/can/can_rx/$(ODIR)/libcanRxBase.a

##############################################################################
# dynamic libs
##############################################################################
ARM_LDOPTS += -lyaml-cpp
