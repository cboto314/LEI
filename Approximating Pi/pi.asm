	
	.data
	
l_cubo:		.double		1.0
delta:		.double		1E-2
zero:		.double		0.0
dois:		.double		2.0
six:		.double		6.0

	
	.text
	.globl main
	
main:
	la	$a0,l_cubo
	l.d	$f20,0($a0)	#l_cubo
	la	$a0,dois
	
	l.d	$f4,0($a0)
	div.d	$f22,$f20,$f4	#r_esfera
	la	$a0,delta
	l.d	$f24,0($a0)	#delta
	la	$a0,zero
	l.d 	$f26,0($a0)		#v_cubo ou v_total
	l.d	$f28,0($a0)		#v_esfera
	
	l.d	$f4,0($a0)		#x
	l.d	$f6,0($a0)		#y
	l.d	$f8,0($a0)		#z
	
loop_x:

	c.lt.d	$f4,$f20
	bc1f	end_loop_x
	l.d	$f6,0($a0)
	loop_y:

		c.lt.d	$f6,$f20
		bc1f	end_loop_y
		l.d	$f8,0($a0)
		loop_z:

			c.lt.d	$f8,$f20
			bc1f	end_loop_z
			add.d	$f26,$f26,$f24
			mov.d	$f12,$f4
			mov.d	$f14,$f6
			mov.d	$f30,$f8
			
			jal in_esfera
			

			l.d	$f10,0($a0)
			
			beqz	$v0,continue

				add.d	$f28,$f28,$f24
			continue:
				add.d	$f8,$f8,$f24
				j loop_z
			end_loop_z:
		add.d	$f6,$f6,$f24
		j loop_y
		end_loop_y:
		add.d	$f4,$f4,$f24
		j loop_x
end_loop_x:

mul.d	$f24,$f24,$f24
mul.d	$f28,$f28,$f24
mul.d	$f26,$f26,$f24

div.d	$f28,$f28,$f26

la	$a0,six
l.d	$f10,0($a0)
mul.d	$f28,$f28,$f10

li	$v0,3		#
mov.d	$f12,$f28 	#
syscall			# print pi

li $v0,10		#
syscall			#exit

####################################

	.text
	.globl	in_esfera

in_esfera:

	sub.d	$f12,$f12,$f22
	mul.d	$f12,$f12,$f12
	sub.d	$f14,$f14,$f22
	mul.d	$f14,$f14,$f14
	sub.d	$f30,$f30,$f22
	mul.d	$f30,$f30,$f30
	add.d	$f30,$f12,$f30
	add.d	$f30,$f14,$f30

	mul.d	$f16,$f22,$f22

	li $v0,0
	c.le.d	$f30,$f16
	bc1f	continue2
		li $v0,1
	continue2:
		jr	$ra
		
