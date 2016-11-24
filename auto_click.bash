#!/bin/bash

right_click(){
	xdotool click 3
	sleep 1
}

left_click(){
	xdotool click 1
	sleep 1
}

mouse_move(){
	local x="$1"
	local y="$2"
	xdotool mousemove $x $y
}
multi_clicks(){
	local fnc=""
        local action="$1"
	local number_of_clicks="$2"
	case $action in
		right) fnc="right_click"
		;;
		left) fnc="left_click"
		;;
		*)
		;;
	esac

        for (( i=1; i<=$number_of_clicks; i++))
	do
		$fnc
	done	
}

right_action(){
	local x="$1"
	local y="$2"
	mouse_move $1 $2
	sleep 1
	#multi_clicks right 5
	multi_clicks right 2
}

left_action(){
	local x="$1"
	local y="$2"
	mouse_move $1 $2
	sleep 1
	#multi_clicks left 5
	multi_clicks left 2
}

shaiya(){
        tail -n4 setup > tmp
        mv tmp setup

        local enter_quest=$(awk '/enter/{print $2,$3}' setup)
        local open_quest1=$(awk '/q1/{print $2,$3}' setup)
        local accept_quest=$(awk '/act/{print $2,$3}' setup)
        local open_quest2=$(awk '/q2/{print $2,$3}' setup)


	while [ 1 ];do
          #when finished quest
		echo =====================Start===========================
                left_action $enter_quest 
                
		right_action $open_quest1
                left_action $accept_quest 
		echo =====================Q1-Q2===========================
                sleep 1
		right_action $open_quest2
                left_action $accept_quest
                sleep 5
		echo =====================Done===========================
	done	
}
shaiya
