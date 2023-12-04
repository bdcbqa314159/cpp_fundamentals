dependency:
	cd build && cmake .. && make

prepare:
	rm -rf build
	mkdir build

executable:
	# cd build/app && ./first_exec
	# cd build/exercises_activities_chapter_1 && ./ch_1_ex_1
	# cd build/exercises_activities_chapter_1 && ./ch_1_ex_2
	# cd build/exercises_activities_chapter_1 && ./ch_1_act_1
	# cd build/exercises_activities_chapter_1 && ./ch_1_act_2
	# cd build/exercises_activities_chapter_2 && ./ch_2_ex_3
	# cd build/exercises_activities_chapter_2 && ./ch_2_ex_4
	# cd build/exercises_activities_chapter_2 && ./ch_2_ex_5
	# cd build/exercises_activities_chapter_2 && ./ch_2_ex_6
	# cd build/exercises_activities_chapter_2 && ./ch_2_act_3
	cd build/exercises_activities_chapter_2 && ./ch_2_act_4

stream:
	clear && make prepare && make dependency && make executable