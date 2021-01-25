#!/bin/bash

root_path=$HOME
cur_path=`pwd`
target_vi='.vimrc'
target_tmux='.tmux.conf'
target_install=("vim" "tmux")
target_all_cnt=0

parameter_cnt=$#
parameters=$@

function set()
{
	local parameter=$1

	if [ ${parameter} == "all" ]; then
		for target in ${target_all[@]}
		do
			set_configuration ${target}
		done
	fi	
}

#function download()
#{
#	echo "========Downloading ${1}...========"
#	apt install ${1} -y
#	echo "========	 Done ${1}...    ========"
#}

function set_configuration()
{
	echo "I'm set_conf and get ${1}"
}

# 1. Check Parameter( parameter is coming like "all" "vi" "tmux" etc.. )
if [ ${parameter_cnt} -eq 0 ]; then
	echo "No Parameter Error!"
	exit -1
fi

# 2. send to set function one parameter at a time
for parameter in ${parameters[@]}
do
	set ${parameter}
done
