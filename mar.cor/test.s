.name"test"
.comment"I'M ALIIIIVE and readY tO FiGht"

live %2

l2:		sti r1, %:live, %1
		and r1, %0, r1

zjmp %:live
live:	live %1
		zjmp %:live
live:	live %1
zjmp %:live
sti r1, %:live, %2
