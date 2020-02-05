.name "zork"
.comment "just a basic living prog"

l2:		sti r1 , :live , %1
		and r1, 54, r1
		add r5, r1, r23
live:   live %4     
 		zjmp %:live
		zjmp %:l2
