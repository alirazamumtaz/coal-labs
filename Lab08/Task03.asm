	// This program is printing n+1 lines(turning all bits of a single register to 1)
	// By skiping 1 row (As adding 64 moves to next+1 line of screen).
	// Because Adding 32 will moves to next line on screen

	@R0		
	D = M			// D = RAM[0]
	@n				// A = 16
	M = D			// RAM[16] = D; assigning RAM[0] to a variabele n at RAM[16]

	@i				// A = 17 
	M = 0			// RAM[17] = 0; Assigning 0 to a variable i at RAM[17]

	@SCREEN		// A = 16384 
	D = A 		// D = address of SCREEN MAPING IN RAM (16384)
	@addr 		// A = 18
	M = D			// RAM[18] = D; storing SCREEN MAMPING address in variable
						// addr at RAM[18] 
(LOOP)			// LABLE
	@i 				// A = 17
	D = M 		// D = RAM[17] or D = i
	@n				// A = 16
	D = D-M		// D = D - RAM[16]; D = D-i
	@END			// A = 33
	D;JGT			// jump to ROM[33] (END) if D>0
	@addr 		// A = 18
	A = M 		// A = RAM[18]
	M = -1 		// RAM[A] = -1
	@i 				// A = 17
	M = M+1 	// RAM[17] = RAM[17] + 1; i++

	@64 			// A = 64
	D = A 		// D = A or D = 64

	@addr 		// A = 18
	M = D+M 	// RAM[18] = D + RAM[18]
	@LOOP 		// Refference to LABLE LOOP
	0;JMP 		// Unconditional Jump to LABLE LOOP

(END) 			// LABLE 

	@END  		// Refference to LABLE END
	0;JMP 		// Unconditional Jump to LABLE END