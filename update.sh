#!/bin/bash
 
#####################################################
# Copyright (c) 2021 Roee Xu. All Rights Reserved
#####################################################
# File:    update.sh
# Author:  roeexu
# Date:    2021-02-03 22:34:11
# Brief:
#####################################################

TIME=`date +'%Y-%m-%d %H:%M:%S'`
git pull
git add *; git commit -m "$TIME"; git push

# vim: set expandtab ts=4 sw=4 sts=4 tw=100

