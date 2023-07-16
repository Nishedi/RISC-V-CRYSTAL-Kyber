.data
V: .word 41, 2995, 26962, 292, 19169, 32391, 23281, 19718, 6334, 4827, 5705, 17421, 11478, 3902, 9961, 5447, 18467, 11942, 24464, 12382, 15724, 14604, 16827, 19895, 26500, 5436, 28145, 18716, 29358, 153, 491, 21726
PowerTab: .word 1, 30048, 4312, 11419, 6214, 31747, 22779, 482, 4740, 24017, 25646, 27729, 8433, 22854, 4061, 2050
_j: .word 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 0, 1, 4, 5, 8, 9, 12, 13, 16, 17, 20, 21, 24, 25, 28, 29, 0, 1, 2, 3, 8, 9, 10, 11, 16, 17, 18, 19, 24, 25, 26, 27, 0, 1, 2, 3, 4, 5, 6, 7, 16, 17, 18, 19, 20, 21, 22, 23, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
_jm: .word 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 2, 3, 6, 7, 10, 11, 14, 15, 18, 19, 22, 23, 26, 27, 30, 31, 4, 5, 6, 7, 12, 13, 14, 15, 20, 21, 22, 23, 28, 29, 30, 31, 8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
_k: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 8, 0, 4, 8, 12, 0, 4, 8, 12, 0, 4, 8, 12, 0, 4, 8, 12, 0, 2, 4, 6, 8, 10, 12, 14, 0, 2, 4, 6, 8, 10, 12, 14, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
v0: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32
v1: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32
v2: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32
v3: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32
v4: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32
v5: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32
v6: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32
v7: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32
mod: .word 32609
str1: .string "\n"
str2: .string " "
nby2: .word 16
n: .word 32

offset: .word 0
offset0: .word 0
.text

 #a3 - vm dlugosc, a4 - rs1 adres src, a5 - vd adres dest, a6 - vs2 indeks
.macro vlxwu_v  vd, rs1,  vs2
	lw a3, nby2
	la a5, \vd
	la a4, \rs1
	la a6, \vs2
        addi t0, a4, 0 
	jal ra, vlxwu_vf
	
.endm     
#a3 - vm, a4 - rs1 adres src, a5 - vs3 adres dest, a6 - vs2 indeks        
.macro vsxw_v  vs3, rs1,  vs2
	lw a3, nby2
	la a4, \rs1
	la a5, \vs3
	la a6, \vs2
        addi t0, a5, 0 
	jal ra, vsxw_vf
.endm   
#a3 - vm, a4 - vs2, a5 - vs1, a6 - vd
.macro vsub_vv  vd, vs2, vs1
	lw a3, nby2
	la a4, \vs2
	la a5, \vs1
	la a6, \vd
	jal ra, vsub_vvf
.endm
#a3 - vm, a4 - vs2, a5 - vs1, a6 - vd        
.macro vadd_vv vd, vs2, vs1

	lw a3, nby2
	la a4, \vs2
	la a5, \vs1
	la a6, \vd
	jal ra, vadd_vvf
.endm 
        #a3 - vm dlugosc, a4 - vs2, rs1 / vd src/dest, a5 mod
.macro vremu_vx  vec, mod
	lw a3, nby2
	la a4, \vec
	lw a5, \mod
	jal ra, vremu_vxf
.endm      
#a3 - vm dlugosc, a4 - vs1 src1, a5 - vs2 src2, a6 - vd dest
.macro vmul_vv  vd, vs2, vs1
	lw a3, nby2
	la a4, \vs1
	la a5, \vs2
	la a6, \vd
	jal ra, vmul_vvf
.endm
#a4 - vm dlugosc
#a0 a1 uzytkowe
.macro printResult V
        lw a3, n
	la a4, \V
	jal ra, printResultf
.endm
#a3 - vm dlugosc, a4 - G src, a5 - memory dest
#a0 a1 uzytkowe
.macro vwritepoly  vd, memory, offset, len
	la a4, \memory	
	la a5, \vd
	lw a7, \offset
	add a4, a4, a7
	lw a3, \len
	jal ra, vwritepolyf
.endm

vlxwu_vf:
#a3 - vm dlugosc, a4 - rs1 adres src, a5 - vd adres dest, a6 - vs2 indeks
loop1:   
        lw a0, 0(a6)
        addi t1, zero, 4
        mul t1, a0, t1
        add t1, t1, t0
        lw a0, 0(t1)
        sw a0, 0(a5)
        addi a5, a5, 4
        addi a3, a3, -1  # Zdekrementuj zawartosc rejestru $t0 o 1
        addi a4, a4, 4
        addi a6, a6, 4
        bne a3, zero, loop1
ret

#a3 - vm, a4 - rs1 adres src, a5 - vs3 adres dest, a6 - vs2 indeks        
vsxw_vf:
loop2:   
        lw a0, 0(a6)
        addi t1, zero, 4
        mul a0, a0, t1
        add a5, t0 , a0
        sw a0, 0(a5)
        lw a0, 0(a4)
        sw a0, 0(a5)        
        addi a3, a3, -1  # Zdekrementuj zawartosc rejestru $t0 o 1
        addi a4, a4, 4
        addi a5, a5, 4
        addi a6, a6, 4
        bne a3, zero, loop2
ret 

#a3 - vm, a4 - vs2, a5 - vs1, a6 - vd
vsub_vvf:
loop3:
        lw a0, 0(a4)
        lw a1, 0(a5)
        addi a4, a4, 4
        addi a5, a5, 4
        sub a0, a0, a1 
        sw a0, 0(a6)
        addi a6, a6, 4
        addi a3, a3, -1  # Zdekrementuj zawartosc rejestru $t0 o 1
        bne a3, zero, loop3
ret
#a3 - vm, a4 - vs2, a5 - vs1, a6 - vd        
vadd_vvf:
loop4:        
        lw a0, 0(a4)
        lw a1, 0(a5)
        addi a4, a4, 4
        addi a5, a5, 4
        add a0, a0, a1
        sw a0, 0(a6)
        addi a6, a6, 4
        addi a3, a3 ,-1  # Zdekrementuj zawartosc rejestru $t0 o 1
        bne a3, zero, loop4
ret

        #a3 - vm dlugosc, a4 - vs2, rs1 / vd src/dest, a5 mod



.globl _start
_start:

	addi s3, zero, 5 # levels
	vwritepoly v0, V, offset0, n #vwritepoly(v0, vector, n)# //v0 wektor
	#for (s3 = levels# s3 >0# s3--) {
ll: 
	addi a0, zero, 5
	sub a0, a0, s3 #a0 = levels - s3
	addi s4, zero, 64
	mul a0, a0, s4 
	la a1, offset 
	sw a0, 0(a1) #offset = (levels - s3) * n/2

	vwritepoly v2, _jm, offset, nby2 #vwritepoly(v2, _jm + offset, n / 2)#//v2 = _jm 
	
	vlxwu_v v5, v0,  v2 #vlxwu_v(v5, v0, v2, n / 2)# //v5 = b1 = vector[jm] 

	vwritepoly v1, _k,  offset, nby2 # vwritepoly(v1, _k + offset, n / 2)#//G4 = k = _k[iter]

	vwritepoly  v4, PowerTab, offset0, nby2 # vwritepoly(v4, powTable, n / 2)#//v6 = powertable
	
	vlxwu_v v7, v4, v1 # vlxwu_v(v7, v4, v1, n / 2)#//v1 = powertable[k]
	
	vmul_vv v5, v5,  v7 # vmul_vv(v5, v5, v7, n / 2)#

	vremu_vx  v5, mod # vremu_vx(v5, v5, mod, n / 2)#

	vwritepoly  v7, _j, offset, nby2 # vwritepoly(v7, _j + offset, n / 2)# //v1 indeksy j 

	vlxwu_v  v3, v0,  v7
	
	vadd_vv  v4, v3, v5 # vadd_vv(v4, v3, v5, n / 2)#//v4=(a+b)%mod
	
	vremu_vx  v4, mod # vremu_vx(v4, v4, mod, n / 2)#

	vsxw_v  v0, v4,  v7 # vsxw_v(v0, v4, v7, n / 2)#
	
	vsub_vv  v4, v3, v5 # vsub_vv(v4, v3, v5, n / 2)#//v4=(a-b)%mod
	
	vremu_vx  v4, mod # vremu_vx(v4, v4, mod, n / 2)#
	
	vsxw_v  v0, v4, v2 # vsxw_v(v0, v4, v2, n / 2)#

	addi s3, s3, -1
	bne s3, zero, ll

	vwritepoly V, v0,  offset0, n # vwritepoly(v0, vector, n)# 
	
	printResult V
	
	# Exit program
	li a7, 10
	ecall
vremu_vxf:
loop5:
        lw a0, 0(a4)
        add a0, a0, a5
        rem a0, a0, a5
        sw a0, 0(a4)
        addi a4, a4, 4
        addi a3, a3, -1  # Zdekrementuj zawartosc rejestru $t0 o 1
        bne a3, zero, loop5
ret    

#a3 - vm dlugosc, a4 - vs1 src1, a5 - vs2 src2, a6 - vd dest
vmul_vvf:
loop6:
        lw a0, 0(a4)
        lw a1, 0(a5)
        addi a4, a4, 4
        addi a5, a5, 4
        mul a0, a0, a1
        sw a0, 0(a6)
        addi a6, a6, 4
        addi a3, a3, -1  # Zdekrementuj zawartosc rejestru $t0 o 1
        bne a3, zero, loop6
ret
     
   
#a4 - vm dlugosc
#a0 a1 uzytkowe
printResultf:
loop7:    
        lw a0, 0(a4)
        addi a4, a4, 4
        mv  a1, a0
        mv a0, a1
        li a7, 1
        ecall
        la a0, str2
        li a7, 4
        ecall
        addi a3, a3, -1  # Zdekrementuj zawartosc rejestru $t0 o 1
        bne a3, zero, loop7
        la a0, str1
        li a7, 4
        ecall
ret


#a3 - vm dlugosc, a4 - G src, a5 - memory dest
#a0 a1 uzytkowe
vwritepolyf:
loop8:   
        lw a0, 0(a4)
        addi a4, a4, 4
        sw a0, 0(a5)
        addi a5, a5, 4
        addi a3, a3, -1  # Zdekrementuj zawartosc rejestru $t0 o 1
        bne a3, zero, loop8
ret       
