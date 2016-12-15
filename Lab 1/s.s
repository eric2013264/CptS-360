    .global main, mymain, myprintf
main:    
    pushl  %ebp      # establish stack fram
    movl   %esp, %ebp
	
# (1). Write ASSEMBLY code to call myprintf(FMT)
#      HELP: How does mysum() call printf() in the class notes.
	pushl b			# Push a onto stack
	pushl a			# Push b onto stack
	pushl $fmt		# Push fmt onto stack
	call myprintf	# Call myprintf
	addl $12, %esp	# Reset frame

# (2). Write ASSEMBLY code to call mymain(argc, argv, env)
#      HELP: When crt0.o calls main(int argc, char *argv[], char *env[]), 
#            it passes argc, argv, env to main(). 
#            Draw a diagram to see where are argc, argv, env?
	pushl 16(%ebp)	# Push env
	pushl 12(%ebp)	# Push argv
	pushl 8(%ebp)	# Push argc
	call mymain		# Call mymain
	addl $12, %esp	# Reset frame

# (3). Write code to call myprintf(fmt,a,b)	
#      HELP: same as in (1) above
	pushl b 		# Push a onto stack
    pushl a 		# Push b onto stack
    pushl $fmt 		# Push fmt onto stack
    call myprintf	# Call myprintf
    addl $12, %esp	# Reset frame

# (4). Return to caller
    movl  %ebp, %esp
    popl  %ebp
    ret

#---------- DATA section of assembly code ---------------
    .data
FMT:.asciz "main() in assembly call mymain() in C\n"
a:	.long 1234
b:	.long 5678
fmt:.asciz "a=%d b=%d\n"