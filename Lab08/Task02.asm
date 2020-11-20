	// This program runs n times and and the base address of array will
	// be 20 and it will print 0, 1, 2, 3,..... until n-1

	@20			// A = 20
	D=A 		// D = A; D = 20
	@arr 		// A = 16 
	M=D 		// RAM[16] = D; arr = 20;

	@R0			// A = 0
	D=M 		// D = RAM[0]
	@n 			// A = 17
	M=D 		// RAM[17] = D; n=RAM[0]
	@i 			// A = 18
	M=0			// RAM[18] = 0; assigning i=0

(LOOP)		// LABLE

	@i   		// A = 18
	D=M 		// D =  RAM[18]; assigning D = i
	@n 			// A = 17
	D=D-M		// D = D-RAM[17]; D=i-n
	@END 		// Refference to LABLE END
	D;JEQ 	// if D >= 0 jump to end
	@arr  	// A = 16
	D=M 		// D = RAM[16]; D = arr
	@i 			// A = 18
	A=D+M 	// A = D+RAM[18]
	M=A-D 	// RAM[18] = A-D

	@i 			// A = 18
	M=M+1 	// RAM[18] = RAM[18] + 1; or i++

	@LOOP 	// Refference to LABLE LOOP
	0;JMP 	// Unconditional Jump to LABLE LOOP

(END) 		// LABLE 

	@END  	// Refference to LABLE END
	0;JMP 	// Unconditional Jump to LABLE END