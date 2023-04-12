	.file	"<artificial>"
	.text
.Ltext0:
	.p2align 4
	.type	ma_biquad_reinit, @function
ma_biquad_reinit:
.LVL0:
.LFB66:
	.file 1 "/home/user/Documents/_code_/Grume/source/3rd_party/miniaudio.cpp"
	.loc 1 33054 1 view -0
	.cfi_startproc
	.loc 1 33054 1 is_stmt 0 view .LVU1
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
1:	call	mcount
	.loc 1 33054 1 view .LVU2
	.loc 1 33055 5 is_stmt 1 view .LVU3
	.loc 1 33059 5 view .LVU4
	.loc 1 33059 18 is_stmt 0 view .LVU5
	movsd	32(%rdi), %xmm1
	.loc 1 33059 5 view .LVU6
	comisd	.LC0(%rip), %xmm1
	je	.L8
	.loc 1 33064 5 is_stmt 1 view .LVU7
	.loc 1 33064 18 is_stmt 0 view .LVU8
	movl	(%rdi), %eax
	.loc 1 33064 42 view .LVU9
	cmpl	$2, %eax
	je	.L11
	cmpl	$5, %eax
	jne	.L8
.L11:
	.loc 1 33069 5 is_stmt 1 view .LVU10
	.loc 1 33069 14 is_stmt 0 view .LVU11
	movl	(%rsi), %edx
	.loc 1 33069 42 view .LVU12
	testl	%edx, %edx
	je	.L12
	cmpl	%edx, %eax
	jne	.L10
.L12:
	.loc 1 33074 5 is_stmt 1 view .LVU13
	.loc 1 33074 14 is_stmt 0 view .LVU14
	movl	4(%rsi), %edx
	.loc 1 33074 57 view .LVU15
	movl	4(%rdi), %ecx
	.loc 1 33074 5 view .LVU16
	testl	%edx, %edx
	jne	.L23
.L5:
	.loc 1 33079 5 is_stmt 1 view .LVU17
	.loc 1 33080 5 view .LVU18
	.loc 1 33079 19 is_stmt 0 view .LVU19
	movd	%eax, %xmm0
	movd	%ecx, %xmm5
	.loc 1 33085 43 view .LVU20
	movsd	16(%rdi), %xmm4
	.loc 1 33086 43 view .LVU21
	movsd	24(%rdi), %xmm2
	.loc 1 33079 19 view .LVU22
	punpckldq	%xmm5, %xmm0
	.loc 1 33087 43 view .LVU23
	movsd	40(%rdi), %xmm3
	.loc 1 33079 19 view .LVU24
	movq	%xmm0, (%rsi)
	.loc 1 33083 5 is_stmt 1 view .LVU25
	movsd	.LC1(%rip), %xmm0
	divsd	%xmm1, %xmm0
	.loc 1 33084 43 is_stmt 0 view .LVU26
	movsd	8(%rdi), %xmm1
	.loc 1 33085 43 view .LVU27
	mulsd	%xmm0, %xmm4
	.loc 1 33084 43 view .LVU28
	mulsd	%xmm0, %xmm1
	.loc 1 33086 43 view .LVU29
	mulsd	%xmm0, %xmm2
	.loc 1 33087 43 view .LVU30
	mulsd	%xmm0, %xmm3
	.loc 1 33088 43 view .LVU31
	mulsd	48(%rdi), %xmm0
	.loc 1 33084 23 view .LVU32
	unpcklpd	%xmm4, %xmm1
	.loc 1 33083 5 view .LVU33
	cmpl	$5, %eax
	je	.L24
	.loc 1 33090 9 is_stmt 1 view .LVU34
.LVL1:
.LBB80:
.LBI80:
	.loc 1 32906 17 view .LVU35
.LBB81:
	.loc 1 32908 5 view .LVU36
	.loc 1 32908 5 is_stmt 0 view .LVU37
.LBE81:
.LBE80:
	.loc 1 33091 9 is_stmt 1 view .LVU38
	.loc 1 32908 5 view .LVU39
	.loc 1 33092 9 view .LVU40
	.loc 1 32908 5 view .LVU41
	.loc 1 33093 9 view .LVU42
	.loc 1 32908 5 view .LVU43
.LBB85:
.LBB86:
	.loc 1 32908 25 is_stmt 0 view .LVU44
	mulsd	.LC3(%rip), %xmm0
.LBE86:
.LBE85:
.LBB90:
.LBB82:
	movapd	.LC2(%rip), %xmm4
	unpcklpd	%xmm3, %xmm2
.LBE82:
.LBE90:
	.loc 1 33098 1 view .LVU45
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
.LBB91:
.LBB83:
	.loc 1 32908 25 view .LVU46
	mulpd	%xmm4, %xmm1
	mulpd	%xmm4, %xmm2
.LBE83:
.LBE91:
.LBB92:
.LBB87:
	.loc 1 32908 61 view .LVU47
	cvttsd2sil	%xmm0, %eax
.LBE87:
.LBE92:
.LBB93:
.LBB84:
	cvttpd2dq	%xmm1, %xmm1
	cvttpd2dq	%xmm2, %xmm2
	punpcklqdq	%xmm2, %xmm1
.LBE84:
.LBE93:
.LBB94:
.LBB88:
	movl	%eax, 24(%rsi)
.LBE88:
.LBE94:
	.loc 1 33097 12 view .LVU48
	xorl	%eax, %eax
	.loc 1 33090 21 view .LVU49
	movups	%xmm1, 8(%rsi)
	.loc 1 33094 9 is_stmt 1 view .LVU50
.LVL2:
.LBB95:
.LBI85:
	.loc 1 32906 17 view .LVU51
.LBB89:
	.loc 1 32908 5 view .LVU52
	.loc 1 32908 5 is_stmt 0 view .LVU53
.LBE89:
.LBE95:
	.loc 1 33098 1 view .LVU54
	ret
	.p2align 4,,10
	.p2align 3
.L23:
	.cfi_restore_state
	.loc 1 33074 28 discriminator 1 view .LVU55
	cmpl	%ecx, %edx
	je	.L5
.L10:
	.loc 1 33070 16 view .LVU56
	movl	$-3, %eax
	.loc 1 33098 1 view .LVU57
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
	.p2align 4,,10
	.p2align 3
.L24:
	.cfi_restore_state
	.loc 1 33084 9 is_stmt 1 view .LVU58
	.loc 1 33085 9 view .LVU59
	.loc 1 33086 9 view .LVU60
	.loc 1 33087 9 view .LVU61
	.loc 1 33084 23 is_stmt 0 view .LVU62
	unpcklpd	%xmm3, %xmm2
	cvtpd2ps	%xmm1, %xmm1
	.loc 1 33097 12 view .LVU63
	xorl	%eax, %eax
	.loc 1 33088 23 view .LVU64
	cvtsd2ss	%xmm0, %xmm0
	.loc 1 33084 23 view .LVU65
	cvtpd2ps	%xmm2, %xmm2
	movlhps	%xmm2, %xmm1
	.loc 1 33088 23 view .LVU66
	movss	%xmm0, 24(%rsi)
	.loc 1 33098 1 view .LVU67
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	.loc 1 33084 21 view .LVU68
	movups	%xmm1, 8(%rsi)
	.loc 1 33088 9 is_stmt 1 view .LVU69
	.loc 1 33098 1 is_stmt 0 view .LVU70
	ret
	.p2align 4,,10
	.p2align 3
.L8:
	.cfi_restore_state
	.loc 1 33060 16 view .LVU71
	movl	$-2, %eax
	.loc 1 33098 1 view .LVU72
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE66:
	.size	ma_biquad_reinit, .-ma_biquad_reinit
	.p2align 4
	.type	_ZL47ma_resampling_backend_get_input_latency__linearPvPKv, @function
_ZL47ma_resampling_backend_get_input_latency__linearPvPKv:
.LVL3:
.LFB67:
	.loc 1 39283 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 39283 1 is_stmt 0 view .LVU74
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
1:	call	mcount
	.loc 1 39283 1 view .LVU75
	.loc 1 39284 5 is_stmt 1 view .LVU76
	.loc 1 39286 5 view .LVU77
.LVL4:
.LBB96:
.LBI96:
	.loc 1 39092 18 view .LVU78
.LBB97:
	.loc 1 39094 5 view .LVU79
	testq	%rsi, %rsi
	je	.L27
	.loc 1 39098 5 view .LVU80
.LVL5:
.LBB98:
.LBI98:
	.loc 1 34106 18 view .LVU81
.LBB99:
	.loc 1 34108 5 view .LVU82
	.loc 1 34112 5 view .LVU83
	.loc 1 34112 27 is_stmt 0 view .LVU84
	movl	80(%rsi), %edx
.LBE99:
.LBE98:
	.loc 1 39098 14 view .LVU85
	movl	76(%rsi), %eax
.LBE97:
.LBE96:
	.loc 1 39287 1 view .LVU86
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
.LBB102:
.LBB100:
	.loc 1 39098 51 view .LVU87
	leal	1(%rax,%rdx,2), %eax
.LBE100:
.LBE102:
	.loc 1 39287 1 view .LVU88
	ret
	.p2align 4,,10
	.p2align 3
.L27:
	.cfi_restore_state
.LBB103:
.LBB101:
	.loc 1 39095 16 view .LVU89
	xorl	%eax, %eax
.LVL6:
	.loc 1 39095 16 view .LVU90
.LBE101:
.LBE103:
	.loc 1 39287 1 view .LVU91
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE67:
	.size	_ZL47ma_resampling_backend_get_input_latency__linearPvPKv, .-_ZL47ma_resampling_backend_get_input_latency__linearPvPKv
	.p2align 4
	.type	_ZL48ma_resampling_backend_get_output_latency__linearPvPKv, @function
_ZL48ma_resampling_backend_get_output_latency__linearPvPKv:
.LVL7:
.LFB68:
	.loc 1 39290 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 39290 1 is_stmt 0 view .LVU93
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
1:	call	mcount
	.loc 1 39290 1 view .LVU94
	.loc 1 39291 5 is_stmt 1 view .LVU95
	.loc 1 39293 5 view .LVU96
.LVL8:
.LBB104:
.LBI104:
	.loc 1 39101 18 view .LVU97
.LBB105:
	.loc 1 39103 5 view .LVU98
	testq	%rsi, %rsi
	je	.L30
	.loc 1 39107 5 view .LVU99
.LVL9:
.LBB106:
.LBI106:
	.loc 1 39092 18 view .LVU100
.LBB107:
	.loc 1 39094 5 view .LVU101
	.loc 1 39098 5 view .LVU102
.LBB108:
.LBI108:
	.loc 1 34106 18 view .LVU103
.LBB109:
	.loc 1 34108 5 view .LVU104
	.loc 1 34112 5 view .LVU105
	.loc 1 34112 27 is_stmt 0 view .LVU106
	movl	80(%rsi), %edx
.LBE109:
.LBE108:
	.loc 1 39098 14 view .LVU107
	movl	76(%rsi), %eax
.LBE107:
.LBE106:
	.loc 1 39107 118 view .LVU108
	movl	8(%rsi), %ecx
.LBE105:
.LBE104:
	.loc 1 39294 1 view .LVU109
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
.LBB114:
.LBB112:
.LBB111:
.LBB110:
	.loc 1 39098 51 view .LVU110
	leal	1(%rax,%rdx,2), %eax
.LBE110:
.LBE111:
	.loc 1 39107 83 view .LVU111
	movl	12(%rsi), %edx
	.loc 1 39107 62 view .LVU112
	imulq	%rdx, %rax
	.loc 1 39107 118 view .LVU113
	xorl	%edx, %edx
	divq	%rcx
.LBE112:
.LBE114:
	.loc 1 39294 1 view .LVU114
	ret
	.p2align 4,,10
	.p2align 3
.L30:
	.cfi_restore_state
.LBB115:
.LBB113:
	.loc 1 39104 16 view .LVU115
	xorl	%eax, %eax
.LVL10:
	.loc 1 39104 16 view .LVU116
.LBE113:
.LBE115:
	.loc 1 39294 1 view .LVU117
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE68:
	.size	_ZL48ma_resampling_backend_get_output_latency__linearPvPKv, .-_ZL48ma_resampling_backend_get_output_latency__linearPvPKv
	.p2align 4
	.type	_ZL60ma_resampling_backend_get_required_input_frame_count__linearPvPKvyPy, @function
_ZL60ma_resampling_backend_get_required_input_frame_count__linearPvPKvyPy:
.LVL11:
.LFB69:
	.loc 1 39297 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 39297 1 is_stmt 0 view .LVU119
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
1:	call	mcount
	.loc 1 39297 1 view .LVU120
	.loc 1 39298 5 is_stmt 1 view .LVU121
	.loc 1 39300 5 view .LVU122
.LVL12:
.LBB120:
.LBI120:
	.loc 1 39110 18 view .LVU123
.LBB121:
	.loc 1 39112 5 view .LVU124
	.loc 1 39114 5 view .LVU125
	testq	%rcx, %rcx
	je	.L34
	.loc 1 39118 5 view .LVU126
	.loc 1 39118 23 is_stmt 0 view .LVU127
	movq	$0, (%rcx)
	.loc 1 39120 5 is_stmt 1 view .LVU128
	testq	%rsi, %rsi
	je	.L34
	.loc 1 39124 5 view .LVU129
	.loc 1 39125 16 is_stmt 0 view .LVU130
	xorl	%r8d, %r8d
	.loc 1 39124 5 view .LVU131
	testq	%rdx, %rdx
	je	.L31
.LVL13:
.LBB122:
.LBI122:
	.loc 1 39110 18 is_stmt 1 view .LVU132
.LBB123:
	.loc 1 39129 5 view .LVU133
	.loc 1 39133 55 is_stmt 0 view .LVU134
	movl	32(%rsi), %eax
	.loc 1 39130 22 view .LVU135
	subq	$1, %rdx
.LVL14:
	.loc 1 39129 21 view .LVU136
	movl	40(%rsi), %edi
.LVL15:
	.loc 1 39130 5 is_stmt 1 view .LVU137
	.loc 1 39133 5 view .LVU138
	.loc 1 39133 41 is_stmt 0 view .LVU139
	imulq	%rdx, %rax
	.loc 1 39133 21 view .LVU140
	addq	%rax, %rdi
.LVL16:
	.loc 1 39134 5 is_stmt 1 view .LVU141
	.loc 1 39136 5 view .LVU142
	.loc 1 39134 82 is_stmt 0 view .LVU143
	movl	36(%rsi), %eax
.LVL17:
	.loc 1 39134 68 view .LVU144
	imulq	%rdx, %rax
.LVL18:
	.loc 1 39134 37 view .LVU145
	movl	44(%rsi), %edx
.LVL19:
	.loc 1 39134 119 view .LVU146
	movl	12(%rsi), %esi
.LVL20:
	.loc 1 39134 48 view .LVU147
	addq	%rdx, %rax
	.loc 1 39134 98 view .LVU148
	xorl	%edx, %edx
.LVL21:
	.loc 1 39134 98 view .LVU149
	divq	%rsi
	.loc 1 39134 21 view .LVU150
	addq	%rdi, %rax
	movq	%rax, (%rcx)
	.loc 1 39138 5 is_stmt 1 view .LVU151
.LVL22:
.L31:
	.loc 1 39138 5 is_stmt 0 view .LVU152
.LBE123:
.LBE122:
.LBE121:
.LBE120:
	.loc 1 39301 1 view .LVU153
	movl	%r8d, %eax
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL23:
.L34:
	.cfi_restore_state
.LBB125:
.LBB124:
	.loc 1 39115 16 view .LVU154
	movl	$-2, %r8d
	jmp	.L31
.LBE124:
.LBE125:
	.cfi_endproc
.LFE69:
	.size	_ZL60ma_resampling_backend_get_required_input_frame_count__linearPvPKvyPy, .-_ZL60ma_resampling_backend_get_required_input_frame_count__linearPvPKvyPy
	.p2align 4
	.type	_ZL61ma_resampling_backend_get_expected_output_frame_count__linearPvPKvyPy, @function
_ZL61ma_resampling_backend_get_expected_output_frame_count__linearPvPKvyPy:
.LVL24:
.LFB71:
	.loc 1 39304 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 39304 1 is_stmt 0 view .LVU156
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
1:	call	mcount
	.loc 1 39304 1 view .LVU157
	.loc 1 39305 5 is_stmt 1 view .LVU158
	.loc 1 39307 5 view .LVU159
.LVL25:
.LBB126:
.LBI126:
	.loc 1 39141 18 view .LVU160
.LBB127:
	.loc 1 39143 5 view .LVU161
	.loc 1 39144 5 view .LVU162
	.loc 1 39145 5 view .LVU163
	.loc 1 39147 5 view .LVU164
.LBE127:
.LBE126:
	.loc 1 39304 1 is_stmt 0 view .LVU165
	movq	%rdx, %r8
	movq	%rcx, %rdi
.LVL26:
.LBB131:
.LBB128:
	.loc 1 39147 5 view .LVU166
	testq	%rcx, %rcx
	je	.L43
	.loc 1 39151 5 is_stmt 1 view .LVU167
	.loc 1 39151 24 is_stmt 0 view .LVU168
	movq	$0, (%rcx)
	.loc 1 39153 5 is_stmt 1 view .LVU169
	testq	%rsi, %rsi
	je	.L43
	.loc 1 39163 5 view .LVU170
	.loc 1 39163 62 is_stmt 0 view .LVU171
	movl	12(%rsi), %r9d
	.loc 1 39163 41 view .LVU172
	movq	%rdx, %rax
	.loc 1 39163 98 view .LVU173
	movl	8(%rsi), %r10d
	.loc 1 39163 22 view .LVU174
	xorl	%edx, %edx
.LVL27:
	.loc 1 39163 22 view .LVU175
.LBE128:
.LBE131:
	.loc 1 39308 1 view .LVU176
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
.LBB132:
.LBB129:
	.loc 1 39163 41 view .LVU177
	imulq	%r9, %rax
.LVL28:
	.loc 1 39163 22 view .LVU178
	divq	%r10
	.loc 1 39169 55 view .LVU179
	movl	44(%rsi), %edx
	.loc 1 39163 22 view .LVU180
	movq	%rax, %rcx
.LVL29:
	.loc 1 39169 5 is_stmt 1 view .LVU181
	.loc 1 39170 5 view .LVU182
	.loc 1 39177 5 view .LVU183
	.loc 1 39169 97 is_stmt 0 view .LVU184
	movl	36(%rsi), %eax
.LVL30:
	.loc 1 39169 84 view .LVU185
	imulq	%rcx, %rax
.LVL31:
	.loc 1 39169 66 view .LVU186
	addq	%rdx, %rax
.LVL32:
	.loc 1 39169 40 view .LVU187
	xorl	%edx, %edx
.LVL33:
	.loc 1 39169 40 view .LVU188
	divq	%r9
	.loc 1 39170 97 view .LVU189
	movl	32(%rsi), %edx
	.loc 1 39170 55 view .LVU190
	movl	40(%rsi), %esi
.LVL34:
	.loc 1 39170 84 view .LVU191
	imulq	%rcx, %rdx
.LVL35:
	.loc 1 39170 66 view .LVU192
	addq	%rsi, %rdx
	.loc 1 39170 40 view .LVU193
	addq	%rdx, %rax
	.loc 1 39178 26 view .LVU194
	cmpq	%rax, %r8
	sbbq	$-1, %rcx
.LVL36:
	.loc 1 39181 5 is_stmt 1 view .LVU195
	.loc 1 39183 12 is_stmt 0 view .LVU196
	xorl	%eax, %eax
	.loc 1 39181 24 view .LVU197
	movq	%rcx, (%rdi)
	.loc 1 39183 5 is_stmt 1 view .LVU198
.LVL37:
	.loc 1 39183 5 is_stmt 0 view .LVU199
.LBE129:
.LBE132:
	.loc 1 39308 1 view .LVU200
	ret
.LVL38:
.L43:
	.cfi_restore_state
.LBB133:
.LBB130:
	.loc 1 39148 16 view .LVU201
	movl	$-2, %eax
.LBE130:
.LBE133:
	.loc 1 39308 1 view .LVU202
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE71:
	.size	_ZL61ma_resampling_backend_get_expected_output_frame_count__linearPvPKvyPy, .-_ZL61ma_resampling_backend_get_expected_output_frame_count__linearPvPKvyPy
	.p2align 4
	.type	_ZL35ma_resampling_backend_reset__linearPvS_, @function
_ZL35ma_resampling_backend_reset__linearPvS_:
.LVL39:
.LFB72:
	.loc 1 39311 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 39311 1 is_stmt 0 view .LVU204
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$8, %rsp
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	.cfi_offset 3, -40
1:	call	mcount
	.loc 1 39311 1 view .LVU205
	.loc 1 39312 5 is_stmt 1 view .LVU206
	.loc 1 39314 5 view .LVU207
.LVL40:
.LBB148:
.LBI148:
	.loc 1 39186 18 view .LVU208
.LBB149:
	.loc 1 39188 5 view .LVU209
	.loc 1 39190 5 view .LVU210
.LBE149:
.LBE148:
	.loc 1 39311 1 is_stmt 0 view .LVU211
	movq	%rsi, %rbx
.LBB176:
.LBB174:
	.loc 1 39190 5 view .LVU212
	testq	%rsi, %rsi
	je	.L69
	.loc 1 39195 5 is_stmt 1 view .LVU213
	.loc 1 39196 5 view .LVU214
	.loc 1 39195 28 is_stmt 0 view .LVU215
	movq	.LC4(%rip), %rax
	.loc 1 39199 5 view .LVU216
	cmpl	$5, (%rsi)
	.loc 1 39195 28 view .LVU217
	movq	%rax, 40(%rsi)
	.loc 1 39199 5 is_stmt 1 view .LVU218
	.loc 1 39200 58 is_stmt 0 view .LVU219
	movl	4(%rsi), %eax
	.loc 1 39199 5 view .LVU220
	je	.L87
.LVL41:
	.loc 1 39205 37 is_stmt 1 view .LVU221
	testl	%eax, %eax
	je	.L56
	.loc 1 39206 28 is_stmt 0 view .LVU222
	movq	48(%rsi), %rdi
.LVL42:
	.loc 1 39206 28 view .LVU223
	leaq	(%rax,%rax), %r13
	.loc 1 39207 28 view .LVU224
	movq	56(%rsi), %r12
	leaq	(%rdi,%r13), %rdx
	cmpq	%rdx, %r12
	jnb	.L73
	leaq	(%r12,%r13), %rdx
	cmpq	%rdx, %rdi
	jb	.L71
.L73:
	.loc 1 39206 42 view .LVU225
	movq	%r13, %rdx
	xorl	%esi, %esi
.LVL43:
	.loc 1 39206 42 view .LVU226
	call	memset
.LVL44:
	.loc 1 39207 42 view .LVU227
	movq	%r13, %rdx
	xorl	%esi, %esi
	movq	%r12, %rdi
	call	memset
.LVL45:
.L56:
.LBB150:
.LBB151:
.LBB152:
.LBB153:
	.loc 1 34001 35 view .LVU228
	movl	76(%rbx), %edx
	.loc 1 34001 27 view .LVU229
	testl	%edx, %edx
	je	.L52
	movq	88(%rbx), %rax
	subl	$1, %edx
	leaq	(%rdx,%rdx,4), %rcx
	leaq	40(%rax), %rdx
	leaq	(%rdx,%rcx,8), %rcx
	jmp	.L64
.LVL46:
	.p2align 4,,10
	.p2align 3
.L63:
.LBB154:
.LBB155:
	.loc 1 33427 21 view .LVU230
	movl	$0, 8(%rax)
.L62:
.LVL47:
	.loc 1 33427 21 view .LVU231
.LBE155:
.LBE154:
	.loc 1 34001 27 view .LVU232
	movq	%rdx, %rax
	cmpq	%rcx, %rdx
	je	.L52
.L88:
	addq	$40, %rdx
.L64:
.LVL48:
.LBB157:
.LBB156:
	.loc 1 33420 5 view .LVU233
	testq	%rax, %rax
	je	.L62
	.loc 1 33424 5 view .LVU234
	cmpl	$5, (%rax)
	jne	.L63
	.loc 1 33425 21 view .LVU235
	movl	$0x00000000, 8(%rax)
.LVL49:
	.loc 1 33425 21 view .LVU236
.LBE156:
.LBE157:
	.loc 1 34001 27 view .LVU237
	movq	%rdx, %rax
	cmpq	%rcx, %rdx
	jne	.L88
.L52:
.LVL50:
	.loc 1 34005 35 view .LVU238
	movl	80(%rbx), %edx
	.loc 1 34005 27 view .LVU239
	testl	%edx, %edx
	je	.L67
	movq	96(%rbx), %rax
	leal	-1(%rdx), %edi
	salq	$6, %rdi
	leaq	64(%rax), %rdx
	addq	%rdx, %rdi
	jmp	.L68
.LVL51:
	.p2align 4,,10
	.p2align 3
.L66:
.LBB158:
.LBB159:
.LBB160:
.LBB161:
	.loc 1 33110 23 view .LVU240
	movl	$0, (%rsi)
	.loc 1 33111 23 view .LVU241
	movl	$0, (%rcx)
.LVL52:
.L65:
	.loc 1 33111 23 view .LVU242
.LBE161:
.LBE160:
.LBE159:
.LBE158:
	.loc 1 34005 27 view .LVU243
	movq	%rdx, %rax
	cmpq	%rdi, %rdx
	je	.L67
.LVL53:
.L89:
	.loc 1 34005 27 view .LVU244
	addq	$64, %rdx
.L68:
.LVL54:
.LBB172:
.LBB170:
	.loc 1 33640 5 view .LVU245
	testq	%rax, %rax
	je	.L65
.LVL55:
.LBB168:
.LBI160:
	.loc 1 33100 18 is_stmt 1 view .LVU246
.LBB166:
	.loc 1 33106 5 is_stmt 0 view .LVU247
	cmpl	$5, (%rax)
	movq	32(%rax), %rsi
	movq	40(%rax), %rcx
	jne	.L66
.LBB162:
.LBI162:
	.loc 1 33100 18 is_stmt 1 view .LVU248
.LVL56:
.LBB163:
	.loc 1 33107 23 is_stmt 0 view .LVU249
	movl	$0x00000000, (%rsi)
.LBE163:
.LBE162:
.LBE166:
.LBE168:
.LBE170:
.LBE172:
	.loc 1 34005 27 view .LVU250
	movq	%rdx, %rax
.LVL57:
.LBB173:
.LBB171:
.LBB169:
.LBB167:
.LBB165:
.LBB164:
	.loc 1 33108 23 view .LVU251
	movl	$0x00000000, (%rcx)
.LVL58:
	.loc 1 33108 23 view .LVU252
.LBE164:
.LBE165:
.LBE167:
.LBE169:
.LBE171:
.LBE173:
	.loc 1 34005 27 view .LVU253
	cmpq	%rdi, %rdx
	jne	.L89
.LVL59:
.L67:
	.loc 1 34005 27 view .LVU254
.LBE153:
.LBE152:
.LBE151:
.LBE150:
	.loc 1 39214 12 view .LVU255
	xorl	%eax, %eax
.LVL60:
.L48:
	.loc 1 39214 12 view .LVU256
.LBE174:
.LBE176:
	.loc 1 39315 1 view .LVU257
	addq	$8, %rsp
	popq	%rbx
.LVL61:
	.loc 1 39315 1 view .LVU258
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL62:
	.p2align 4,,10
	.p2align 3
.L87:
	.cfi_restore_state
.LBB177:
.LBB175:
	.loc 1 39200 37 is_stmt 1 view .LVU259
	testl	%eax, %eax
	je	.L56
	.loc 1 39202 28 is_stmt 0 view .LVU260
	movq	56(%rsi), %r12
	leaq	0(,%rax,4), %r13
	.loc 1 39201 28 view .LVU261
	movq	48(%rsi), %rdi
.LVL63:
	.loc 1 39201 28 view .LVU262
	leaq	(%r12,%r13), %rdx
	cmpq	%rdx, %rdi
	jnb	.L73
	leaq	(%rdi,%r13), %rdx
	cmpq	%rdx, %r12
	jnb	.L73
	.loc 1 39202 28 view .LVU263
	xorl	%edx, %edx
.LVL64:
	.p2align 4,,10
	.p2align 3
.L54:
	.loc 1 39201 13 is_stmt 1 view .LVU264
	.loc 1 39201 42 is_stmt 0 view .LVU265
	movl	$0x00000000, (%rdi,%rdx,4)
	.loc 1 39202 13 is_stmt 1 view .LVU266
	.loc 1 39202 42 is_stmt 0 view .LVU267
	movl	$0x00000000, (%r12,%rdx,4)
	.loc 1 39200 9 is_stmt 1 view .LVU268
.LVL65:
	.loc 1 39200 37 view .LVU269
	addq	$1, %rdx
.LVL66:
	.loc 1 39200 37 is_stmt 0 view .LVU270
	cmpq	%rdx, %rax
	jne	.L54
	jmp	.L56
.LVL67:
.L71:
	.loc 1 39207 28 view .LVU271
	xorl	%edx, %edx
.LVL68:
	.p2align 4,,10
	.p2align 3
.L58:
	.loc 1 39206 13 is_stmt 1 view .LVU272
	.loc 1 39206 42 is_stmt 0 view .LVU273
	xorl	%ecx, %ecx
	.loc 1 39207 42 view .LVU274
	xorl	%esi, %esi
	.loc 1 39206 42 view .LVU275
	movw	%cx, (%rdi,%rdx,2)
	.loc 1 39207 13 is_stmt 1 view .LVU276
	.loc 1 39207 42 is_stmt 0 view .LVU277
	movw	%si, (%r12,%rdx,2)
	.loc 1 39205 9 is_stmt 1 view .LVU278
.LVL69:
	.loc 1 39205 37 view .LVU279
	addq	$1, %rdx
.LVL70:
	.loc 1 39205 37 is_stmt 0 view .LVU280
	cmpq	%rdx, %rax
	jne	.L58
	jmp	.L56
.LVL71:
.L69:
	.loc 1 39191 16 view .LVU281
	movl	$-2, %eax
.LVL72:
	.loc 1 39191 16 view .LVU282
.LBE175:
.LBE177:
	.loc 1 39314 68 view .LVU283
	jmp	.L48
	.cfi_endproc
.LFE72:
	.size	_ZL35ma_resampling_backend_reset__linearPvS_, .-_ZL35ma_resampling_backend_reset__linearPvS_
	.p2align 4
	.type	_ZL48ma_calculate_channel_position_rectangular_weighthh, @function
_ZL48ma_calculate_channel_position_rectangular_weighthh:
.LVL73:
.LFB74:
	.loc 1 39715 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 39715 1 is_stmt 0 view .LVU285
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
1:	call	mcount
	.loc 1 39715 1 view .LVU286
	.loc 1 39746 5 is_stmt 1 view .LVU287
.LVL74:
	.loc 1 39754 5 view .LVU288
	.loc 1 39755 1 is_stmt 0 view .LVU289
	popq	%rbp
	.cfi_def_cfa 7, 8
	.loc 1 39747 51 view .LVU290
	movzbl	%dil, %edi
.LVL75:
	.loc 1 39747 97 view .LVU291
	movzbl	%sil, %esi
.LVL76:
	.loc 1 39747 51 view .LVU292
	leaq	(%rdi,%rdi,2), %rax
	.loc 1 39747 97 view .LVU293
	leaq	(%rsi,%rsi,2), %rdx
	.loc 1 39747 51 view .LVU294
	salq	$3, %rax
	.loc 1 39747 97 view .LVU295
	salq	$3, %rdx
	.loc 1 39747 53 view .LVU296
	movss	_ZL22g_maChannelPlaneRatios.lto_priv.0(%rax), %xmm0
	.loc 1 39748 53 view .LVU297
	movss	_ZL22g_maChannelPlaneRatios.lto_priv.0+4(%rax), %xmm1
	.loc 1 39747 53 view .LVU298
	mulss	_ZL22g_maChannelPlaneRatios.lto_priv.0(%rdx), %xmm0
	.loc 1 39750 53 view .LVU299
	movss	_ZL22g_maChannelPlaneRatios.lto_priv.0+12(%rax), %xmm2
	.loc 1 39748 53 view .LVU300
	mulss	_ZL22g_maChannelPlaneRatios.lto_priv.0+4(%rdx), %xmm1
	.loc 1 39750 53 view .LVU301
	mulss	_ZL22g_maChannelPlaneRatios.lto_priv.0+12(%rdx), %xmm2
	.loc 1 39746 11 view .LVU302
	addss	%xmm1, %xmm0
	.loc 1 39749 53 view .LVU303
	movss	_ZL22g_maChannelPlaneRatios.lto_priv.0+8(%rax), %xmm1
	mulss	_ZL22g_maChannelPlaneRatios.lto_priv.0+8(%rdx), %xmm1
	.loc 1 39746 11 view .LVU304
	addss	%xmm2, %xmm1
	.loc 1 39751 53 view .LVU305
	movss	_ZL22g_maChannelPlaneRatios.lto_priv.0+16(%rdx), %xmm2
	.loc 1 39746 11 view .LVU306
	addss	%xmm1, %xmm0
	.loc 1 39751 53 view .LVU307
	movss	_ZL22g_maChannelPlaneRatios.lto_priv.0+16(%rax), %xmm1
	mulss	%xmm1, %xmm2
	.loc 1 39752 53 view .LVU308
	movss	_ZL22g_maChannelPlaneRatios.lto_priv.0+20(%rax), %xmm1
	mulss	_ZL22g_maChannelPlaneRatios.lto_priv.0+20(%rdx), %xmm1
	.loc 1 39746 11 view .LVU309
	addss	%xmm2, %xmm1
	addss	%xmm1, %xmm0
	.loc 1 39755 1 view .LVU310
	ret
	.cfi_endproc
.LFE74:
	.size	_ZL48ma_calculate_channel_position_rectangular_weighthh, .-_ZL48ma_calculate_channel_position_rectangular_weighthh
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC6:
	.string	"miniaudio"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC7:
	.string	"ma_result ma_context_open_client__jack(ma_context*, ma_jack_client_t**)"
	.align 8
.LC8:
	.string	"/home/user/Documents/_code_/Grume/source/3rd_party/miniaudio.cpp"
	.section	.rodata.str1.1
.LC9:
	.string	"pContext != __null"
	.text
	.p2align 4
	.type	_ZL28ma_context_open_client__jackP10ma_contextPP16ma_jack_client_t, @function
_ZL28ma_context_open_client__jackP10ma_contextPP16ma_jack_client_t:
.LVL77:
.LFB76:
	.loc 1 18993 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 18993 1 is_stmt 0 view .LVU312
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$272, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
1:	call	mcount
	.loc 1 18993 1 view .LVU313
	.loc 1 18994 5 is_stmt 1 view .LVU314
	.loc 1 18995 5 view .LVU315
	.loc 1 18996 5 view .LVU316
	.loc 1 18997 5 view .LVU317
	.loc 1 18999 5 view .LVU318
	.loc 1 18993 1 is_stmt 0 view .LVU319
	movq	%rdi, %r12
	movq	%rsi, %rbx
	.loc 1 18999 5 view .LVU320
	testq	%rdi, %rdi
	je	.L109
	.loc 1 19000 5 is_stmt 1 view .LVU321
	.loc 1 19002 5 view .LVU322
	.loc 1 19003 9 view .LVU323
	.loc 1 19003 19 is_stmt 0 view .LVU324
	movq	$0, (%rsi)
	.loc 1 19006 5 is_stmt 1 view .LVU325
	.loc 1 19006 94 is_stmt 0 view .LVU326
	call	*448(%rdi)
.LVL78:
	.loc 1 19007 93 view .LVU327
	movq	560(%r12), %r8
	.loc 1 19006 94 view .LVU328
	movslq	%eax, %rsi
.LVL79:
	.loc 1 19007 5 is_stmt 1 view .LVU329
	.loc 1 19007 17 is_stmt 0 view .LVU330
	movl	$.LC6, %eax
	testq	%r8, %r8
	cmove	%rax, %r8
.LVL80:
.LBB182:
.LBI182:
	.loc 1 976 12 is_stmt 1 view .LVU331
.LBB183:
	.loc 1 978 5 view .LVU332
	.loc 1 979 5 view .LVU333
	.loc 1 981 5 view .LVU334
	.loc 1 984 5 view .LVU335
	testl	%esi, %esi
	je	.L98
.LVL81:
.LBB184:
.LBI184:
	.loc 1 976 12 view .LVU336
	.loc 1 976 12 is_stmt 0 view .LVU337
.LBE184:
.LBE183:
.LBE182:
	.loc 1 19007 30 view .LVU338
	cmpq	$256, %rsi
	movl	$256, %eax
	cmova	%rax, %rsi
.LVL82:
.LBB191:
.LBB189:
.LBB187:
.LBB185:
	.loc 1 997 30 view .LVU339
	subq	$1, %rsi
.LVL83:
	.loc 1 997 30 view .LVU340
	je	.L100
	leaq	-272(%rbp), %rdx
.LVL84:
	.loc 1 997 12 view .LVU341
	xorl	%eax, %eax
	jmp	.L96
.LVL85:
	.p2align 4,,10
	.p2align 3
.L111:
	.loc 1 997 5 view .LVU342
	addq	$1, %rax
.LVL86:
	.loc 1 998 16 view .LVU343
	movb	%cl, (%rdx)
	.loc 1 997 30 view .LVU344
	leaq	1(%rdx), %rdx
	cmpq	%rax, %rsi
	je	.L110
.LVL87:
.L96:
	.loc 1 997 38 view .LVU345
	movzbl	(%r8,%rax), %ecx
	.loc 1 998 14 view .LVU346
	movq	%rdx, %rdi
	.loc 1 997 30 view .LVU347
	testb	%cl, %cl
	jne	.L111
.LVL88:
.L95:
	.loc 1 1002 16 view .LVU348
	movb	$0, (%rdi)
.LVL89:
.L98:
	.loc 1 1002 16 view .LVU349
.LBE185:
.LBE187:
.LBE189:
.LBE191:
	.loc 1 19009 5 is_stmt 1 view .LVU350
	.loc 1 19009 119 is_stmt 0 view .LVU351
	xorl	%esi, %esi
	movl	568(%r12), %eax
	.loc 1 19009 74 view .LVU352
	leaq	-276(%rbp), %rdx
	leaq	-272(%rbp), %rdi
	.loc 1 19009 119 view .LVU353
	testl	%eax, %eax
	sete	%sil
	.loc 1 19009 74 view .LVU354
	xorl	%ecx, %ecx
	xorl	%eax, %eax
	call	*432(%r12)
.LVL90:
	.loc 1 19010 5 is_stmt 1 view .LVU355
	testq	%rax, %rax
	je	.L101
	.loc 1 19014 5 view .LVU356
	.loc 1 19015 9 view .LVU357
	.loc 1 19015 19 is_stmt 0 view .LVU358
	movq	%rax, (%rbx)
	.loc 1 19018 5 is_stmt 1 view .LVU359
	.loc 1 19018 12 is_stmt 0 view .LVU360
	xorl	%eax, %eax
.LVL91:
.L91:
	.loc 1 19019 1 view .LVU361
	addq	$272, %rsp
	popq	%rbx
.LVL92:
	.loc 1 19019 1 view .LVU362
	popq	%r12
.LVL93:
	.loc 1 19019 1 view .LVU363
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL94:
	.p2align 4,,10
	.p2align 3
.L110:
	.cfi_restore_state
.LBB192:
.LBB190:
.LBB188:
.LBB186:
	.loc 1 1002 14 view .LVU364
	leaq	-272(%rbp), %rax
.LVL95:
	.loc 1 1002 14 view .LVU365
	leaq	(%rax,%rsi), %rdi
	jmp	.L95
.LVL96:
.L100:
	.loc 1 997 30 view .LVU366
	leaq	-272(%rbp), %rdi
.LVL97:
	.loc 1 997 30 view .LVU367
	jmp	.L95
.LVL98:
.L101:
	.loc 1 997 30 view .LVU368
.LBE186:
.LBE188:
.LBE190:
.LBE192:
	.loc 1 19011 16 view .LVU369
	movl	$-301, %eax
.LVL99:
	.loc 1 19011 16 view .LVU370
	jmp	.L91
.LVL100:
.L109:
	.loc 1 18999 5 discriminator 1 view .LVU371
	movl	$.LC7, %ecx
	movl	$18999, %edx
	movl	$.LC8, %esi
	movl	$.LC9, %edi
.LVL101:
	.loc 1 18999 5 discriminator 1 view .LVU372
	call	__assert_fail
.LVL102:
	.cfi_endproc
.LFE76:
	.size	_ZL28ma_context_open_client__jackP10ma_contextPP16ma_jack_client_t, .-_ZL28ma_context_open_client__jackP10ma_contextPP16ma_jack_client_t
	.section	.rodata.str1.8
	.align 8
.LC10:
	.string	"ma_result ma_context_enumerate_devices__jack(ma_context*, ma_enum_devices_callback_proc, void*)"
	.section	.rodata.str1.1
.LC11:
	.string	"callback != __null"
.LC12:
	.string	"Default Playback Device"
.LC13:
	.string	"Default Capture Device"
	.text
	.p2align 4
	.type	_ZL34ma_context_enumerate_devices__jackP10ma_contextPFjS0_14ma_device_typePK14ma_device_infoPvES5_, @function
_ZL34ma_context_enumerate_devices__jackP10ma_contextPFjS0_14ma_device_typePK14ma_device_infoPvES5_:
.LVL103:
.LFB77:
	.loc 1 19023 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 19023 1 is_stmt 0 view .LVU374
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$1552, %rsp
	.cfi_offset 14, -24
	.cfi_offset 13, -32
	.cfi_offset 12, -40
	.cfi_offset 3, -48
1:	call	mcount
	.loc 1 19023 1 view .LVU375
	.loc 1 19024 5 is_stmt 1 view .LVU376
.LVL104:
	.loc 1 19026 5 view .LVU377
	.loc 1 19023 1 is_stmt 0 view .LVU378
	movq	%rdi, %r12
	movq	%rsi, %rbx
	movq	%rdx, %r13
	.loc 1 19026 5 view .LVU379
	testq	%rdi, %rdi
	je	.L127
	.loc 1 19027 5 is_stmt 1 view .LVU380
	testq	%rsi, %rsi
	je	.L128
	.loc 1 19030 5 view .LVU381
.LBB208:
	.loc 1 19031 9 view .LVU382
	.loc 1 19032 9 view .LVU383
.LVL105:
.LBB209:
.LBI209:
	.loc 1 776 23 view .LVU384
.LBB210:
	.loc 1 781 5 view .LVU385
	.loc 1 782 9 view .LVU386
	.loc 1 782 15 is_stmt 0 view .LVU387
	leaq	-1584(%rbp), %r14
.LVL106:
	.loc 1 782 15 view .LVU388
	movl	$193, %ecx
	xorl	%eax, %eax
.LBE210:
.LBE209:
.LBB212:
.LBB213:
.LBB214:
.LBB215:
	.loc 1 997 38 view .LVU389
	movl	$68, %edx
.LVL107:
	.loc 1 997 38 view .LVU390
.LBE215:
.LBE214:
.LBE213:
.LBE212:
.LBB222:
.LBB211:
	.loc 1 782 15 view .LVU391
	movq	%r14, %rdi
.LVL108:
	.loc 1 782 15 view .LVU392
	rep stosq
.LVL109:
	.loc 1 782 15 view .LVU393
.LBE211:
.LBE222:
	.loc 1 19033 9 is_stmt 1 view .LVU394
.LBB223:
.LBI212:
	.loc 1 976 12 view .LVU395
.LBB220:
	.loc 1 978 5 view .LVU396
	.loc 1 979 5 view .LVU397
	.loc 1 981 5 view .LVU398
	.loc 1 984 5 view .LVU399
	.loc 1 987 5 view .LVU400
.LBB218:
.LBI214:
	.loc 1 976 12 view .LVU401
	.loc 1 976 12 is_stmt 0 view .LVU402
	jmp	.L115
.LVL110:
	.p2align 4,,10
	.p2align 3
.L117:
.LBB216:
	.loc 1 997 38 view .LVU403
	movzbl	.LC12(%rax), %edx
	.loc 1 997 30 view .LVU404
	testb	%dl, %dl
	je	.L129
.LVL111:
.L115:
	.loc 1 998 16 view .LVU405
	movb	%dl, -1328(%rbp,%rax)
	.loc 1 997 5 view .LVU406
	addq	$1, %rax
.LVL112:
	.loc 1 997 30 view .LVU407
	cmpq	$255, %rax
	jne	.L117
	leaq	-1073(%rbp), %rax
.LVL113:
.L116:
	.loc 1 1002 16 view .LVU408
	movb	$0, (%rax)
.LVL114:
	.loc 1 1002 16 view .LVU409
.LBE216:
.LBE218:
.LBE220:
.LBE223:
	.loc 1 19034 9 is_stmt 1 view .LVU410
	.loc 1 19035 28 is_stmt 0 view .LVU411
	movq	%r13, %rcx
	movq	%r14, %rdx
	movl	$1, %esi
.LVL115:
	.loc 1 19034 30 view .LVU412
	movl	$1, -1072(%rbp)
	.loc 1 19035 9 is_stmt 1 view .LVU413
	.loc 1 19035 28 is_stmt 0 view .LVU414
	movq	%r12, %rdi
	call	*%rbx
.LVL116:
	.loc 1 19035 28 view .LVU415
.LBE208:
	.loc 1 19039 5 is_stmt 1 view .LVU416
.LBB225:
	testl	%eax, %eax
	jne	.L130
.LVL117:
.L118:
	.loc 1 19039 5 is_stmt 0 view .LVU417
.LBE225:
	.loc 1 19047 5 is_stmt 1 view .LVU418
	.loc 1 19049 5 view .LVU419
	.loc 1 19050 1 is_stmt 0 view .LVU420
	addq	$1552, %rsp
	xorl	%eax, %eax
	popq	%rbx
.LVL118:
	.loc 1 19050 1 view .LVU421
	popq	%r12
.LVL119:
	.loc 1 19050 1 view .LVU422
	popq	%r13
.LVL120:
	.loc 1 19050 1 view .LVU423
	popq	%r14
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL121:
	.p2align 4,,10
	.p2align 3
.L129:
	.cfi_restore_state
.LBB244:
.LBB224:
.LBB221:
.LBB219:
.LBB217:
	.loc 1 1002 14 view .LVU424
	leaq	-1328(%rbp), %rcx
.LVL122:
	.loc 1 1002 14 view .LVU425
	addq	%rcx, %rax
.LVL123:
	.loc 1 1002 14 view .LVU426
	jmp	.L116
.LVL124:
	.p2align 4,,10
	.p2align 3
.L130:
	.loc 1 1002 14 view .LVU427
.LBE217:
.LBE219:
.LBE221:
.LBE224:
.LBE244:
.LBB245:
.LBB226:
	.loc 1 19040 9 is_stmt 1 view .LVU428
	.loc 1 19041 9 view .LVU429
.LBB227:
.LBI227:
	.loc 1 776 23 view .LVU430
.LBB228:
	.loc 1 781 5 view .LVU431
	.loc 1 782 9 view .LVU432
	.loc 1 782 15 is_stmt 0 view .LVU433
	movl	$193, %ecx
	xorl	%eax, %eax
.LVL125:
	.loc 1 782 15 view .LVU434
	movq	%r14, %rdi
.LBE228:
.LBE227:
.LBB230:
.LBB231:
.LBB232:
.LBB233:
	.loc 1 997 38 view .LVU435
	movl	$68, %edx
.LBE233:
.LBE232:
.LBE231:
.LBE230:
.LBB240:
.LBB229:
	.loc 1 782 15 view .LVU436
	rep stosq
.LVL126:
	.loc 1 782 15 view .LVU437
.LBE229:
.LBE240:
	.loc 1 19042 9 is_stmt 1 view .LVU438
.LBB241:
.LBI230:
	.loc 1 976 12 view .LVU439
.LBB238:
	.loc 1 978 5 view .LVU440
	.loc 1 979 5 view .LVU441
	.loc 1 981 5 view .LVU442
	.loc 1 984 5 view .LVU443
	.loc 1 987 5 view .LVU444
.LBB236:
.LBI232:
	.loc 1 976 12 view .LVU445
	.loc 1 976 12 is_stmt 0 view .LVU446
	jmp	.L119
.LVL127:
	.p2align 4,,10
	.p2align 3
.L121:
.LBB234:
	.loc 1 997 38 view .LVU447
	movzbl	.LC13(%rax), %edx
	.loc 1 997 30 view .LVU448
	testb	%dl, %dl
	je	.L131
.LVL128:
.L119:
	.loc 1 998 16 view .LVU449
	movb	%dl, -1328(%rbp,%rax)
	.loc 1 997 5 view .LVU450
	addq	$1, %rax
.LVL129:
	.loc 1 997 30 view .LVU451
	cmpq	$255, %rax
	jne	.L121
	leaq	-1073(%rbp), %rax
.LVL130:
.L120:
	.loc 1 1002 16 view .LVU452
	movb	$0, (%rax)
.LVL131:
	.loc 1 1002 16 view .LVU453
.LBE234:
.LBE236:
.LBE238:
.LBE241:
	.loc 1 19043 9 is_stmt 1 view .LVU454
	.loc 1 19044 28 is_stmt 0 view .LVU455
	movq	%r13, %rcx
	movq	%r14, %rdx
	movl	$2, %esi
	.loc 1 19043 30 view .LVU456
	movl	$1, -1072(%rbp)
	.loc 1 19044 9 is_stmt 1 view .LVU457
	.loc 1 19044 28 is_stmt 0 view .LVU458
	movq	%r12, %rdi
	call	*%rbx
.LVL132:
	.loc 1 19044 28 view .LVU459
.LBE226:
	jmp	.L118
.LVL133:
	.p2align 4,,10
	.p2align 3
.L131:
.LBB243:
.LBB242:
.LBB239:
.LBB237:
.LBB235:
	.loc 1 1002 14 view .LVU460
	leaq	-1328(%rbp), %rsi
.LVL134:
	.loc 1 1002 14 view .LVU461
	addq	%rsi, %rax
.LVL135:
	.loc 1 1002 14 view .LVU462
	jmp	.L120
.LVL136:
.L127:
	.loc 1 1002 14 view .LVU463
.LBE235:
.LBE237:
.LBE239:
.LBE242:
.LBE243:
.LBE245:
	.loc 1 19026 5 discriminator 1 view .LVU464
	movl	$.LC10, %ecx
	movl	$19026, %edx
.LVL137:
	.loc 1 19026 5 discriminator 1 view .LVU465
	movl	$.LC8, %esi
	movl	$.LC9, %edi
.LVL138:
	.loc 1 19026 5 discriminator 1 view .LVU466
	call	__assert_fail
.LVL139:
.L128:
	.loc 1 19027 5 discriminator 1 view .LVU467
	movl	$.LC10, %ecx
	movl	$19027, %edx
.LVL140:
	.loc 1 19027 5 discriminator 1 view .LVU468
	movl	$.LC8, %esi
	movl	$.LC11, %edi
.LVL141:
	.loc 1 19027 5 discriminator 1 view .LVU469
	call	__assert_fail
.LVL142:
	.cfi_endproc
.LFE77:
	.size	_ZL34ma_context_enumerate_devices__jackP10ma_contextPFjS0_14ma_device_typePK14ma_device_infoPvES5_, .-_ZL34ma_context_enumerate_devices__jackP10ma_contextPFjS0_14ma_device_typePK14ma_device_infoPvES5_
	.section	.rodata.str1.8
	.align 8
.LC14:
	.string	"ma_result ma_context_get_device_info__jack(ma_context*, ma_device_type, const ma_device_id*, ma_device_info*)"
	.section	.rodata.str1.1
.LC15:
	.string	"[JACK] Failed to open client."
.LC16:
	.string	"32 bit float mono audio"
	.section	.rodata.str1.8
	.align 8
.LC17:
	.string	"[JACK] Failed to query physical ports."
	.text
	.p2align 4
	.type	_ZL32ma_context_get_device_info__jackP10ma_context14ma_device_typePK12ma_device_idP14ma_device_info, @function
_ZL32ma_context_get_device_info__jackP10ma_context14ma_device_typePK12ma_device_idP14ma_device_info:
.LVL143:
.LFB78:
	.loc 1 19053 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 19053 1 is_stmt 0 view .LVU471
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	.cfi_offset 3, -40
1:	call	mcount
	.loc 1 19053 1 view .LVU472
	.loc 1 19054 5 is_stmt 1 view .LVU473
	.loc 1 19055 5 view .LVU474
	.loc 1 19056 5 view .LVU475
	.loc 1 19058 5 view .LVU476
	.loc 1 19053 1 is_stmt 0 view .LVU477
	movq	%rdi, %r12
	movq	%rcx, %rbx
	.loc 1 19058 5 view .LVU478
	testq	%rdi, %rdi
	je	.L158
	.loc 1 19060 5 is_stmt 1 view .LVU479
	testq	%rdx, %rdx
	je	.L134
	.loc 1 19060 27 is_stmt 0 discriminator 1 view .LVU480
	movl	(%rdx), %eax
	testl	%eax, %eax
	jne	.L149
.L134:
	.loc 1 19065 5 is_stmt 1 view .LVU481
	.loc 1 19066 35 is_stmt 0 view .LVU482
	leaq	256(%rbx), %rcx
.LVL144:
.LBB258:
.LBB259:
.LBB260:
.LBB261:
	.loc 1 997 12 view .LVU483
	xorl	%eax, %eax
	.loc 1 997 38 view .LVU484
	movl	$68, %edx
.LVL145:
	.loc 1 997 38 view .LVU485
.LBE261:
.LBE260:
.LBE259:
.LBE258:
	.loc 1 19065 5 view .LVU486
	cmpl	$1, %esi
	jne	.L137
	jmp	.L136
.LVL146:
	.p2align 4,,10
	.p2align 3
.L143:
.LBB268:
.LBB269:
.LBB270:
.LBB271:
	.loc 1 997 38 view .LVU487
	movzbl	.LC13(%rax), %edx
	.loc 1 997 30 view .LVU488
	testb	%dl, %dl
	je	.L159
.LVL147:
.L137:
	.loc 1 998 16 view .LVU489
	movb	%dl, 256(%rbx,%rax)
	.loc 1 997 5 view .LVU490
	addq	$1, %rax
.LVL148:
	.loc 1 997 30 view .LVU491
	cmpq	$255, %rax
	jne	.L143
	.loc 1 1002 14 view .LVU492
	leaq	511(%rbx), %rax
.LVL149:
.L142:
	.loc 1 1002 16 view .LVU493
	movb	$0, (%rax)
	.loc 1 1002 16 view .LVU494
.LBE271:
.LBE270:
.LBE269:
.LBE268:
	.loc 1 19072 5 is_stmt 1 view .LVU495
	.loc 1 19078 42 is_stmt 0 view .LVU496
	leaq	-40(%rbp), %rsi
.LVL150:
	.loc 1 19078 42 view .LVU497
	movq	%r12, %rdi
.LVL151:
	.loc 1 19072 28 view .LVU498
	movl	$1, 512(%rbx)
	.loc 1 19075 5 is_stmt 1 view .LVU499
	.loc 1 19075 46 is_stmt 0 view .LVU500
	movl	$5, 520(%rbx)
	.loc 1 19078 5 is_stmt 1 view .LVU501
	.loc 1 19078 42 is_stmt 0 view .LVU502
	call	_ZL28ma_context_open_client__jackP10ma_contextPP16ma_jack_client_t
.LVL152:
	movl	%eax, %r13d
.LVL153:
	.loc 1 19079 5 is_stmt 1 view .LVU503
	testl	%eax, %eax
	jne	.L140
	.loc 1 19084 5 view .LVU504
	.loc 1 19084 119 is_stmt 0 view .LVU505
	movq	-40(%rbp), %rdi
	call	*480(%r12)
.LVL154:
	.loc 1 19087 70 view .LVU506
	movl	$6, %ecx
	.loc 1 19085 50 view .LVU507
	movl	$0, 524(%rbx)
	.loc 1 19084 50 view .LVU508
	movl	%eax, 528(%rbx)
	.loc 1 19085 5 is_stmt 1 view .LVU509
	.loc 1 19087 5 view .LVU510
	.loc 1 19087 55 is_stmt 0 view .LVU511
	movq	496(%r12), %rax
.L148:
	.loc 1 19087 70 discriminator 4 view .LVU512
	movq	-40(%rbp), %rdi
	movl	$.LC16, %edx
	xorl	%esi, %esi
	call	*%rax
.LVL155:
	movq	%rax, %rdi
.LVL156:
	.loc 1 19088 5 is_stmt 1 discriminator 4 view .LVU513
	testq	%rax, %rax
	je	.L160
	.loc 1 19094 5 view .LVU514
	.loc 1 19094 64 view .LVU515
	.loc 1 19094 54 is_stmt 0 view .LVU516
	movl	524(%rbx), %edx
	.loc 1 19094 64 view .LVU517
	cmpq	$0, (%rdi,%rdx,8)
	.loc 1 19094 54 view .LVU518
	movq	%rdx, %rax
.LVL157:
	.loc 1 19094 64 view .LVU519
	je	.L146
	addl	$1, %eax
	.p2align 4,,10
	.p2align 3
.L147:
	.loc 1 19095 9 is_stmt 1 view .LVU520
	.loc 1 19094 5 view .LVU521
	.loc 1 19094 64 view .LVU522
	.loc 1 19094 54 is_stmt 0 view .LVU523
	movl	%eax, %edx
	movl	%eax, %ecx
	.loc 1 19094 64 view .LVU524
	addl	$1, %eax
	cmpq	$0, (%rdi,%rdx,8)
	jne	.L147
	movl	%ecx, 524(%rbx)
.L146:
	.loc 1 19098 5 is_stmt 1 view .LVU525
	.loc 1 19098 45 is_stmt 0 view .LVU526
	movl	$0, 532(%rbx)
	.loc 1 19099 5 is_stmt 1 view .LVU527
	.loc 1 19105 12 is_stmt 0 view .LVU528
	xorl	%r13d, %r13d
.LVL158:
	.loc 1 19099 40 view .LVU529
	movl	$1, 516(%rbx)
	.loc 1 19101 5 is_stmt 1 view .LVU530
	.loc 1 19101 50 is_stmt 0 view .LVU531
	call	*552(%r12)
.LVL159:
	.loc 1 19102 5 is_stmt 1 view .LVU532
	.loc 1 19102 66 is_stmt 0 view .LVU533
	movq	-40(%rbp), %rdi
	call	*440(%r12)
.LVL160:
.L132:
	.loc 1 19106 1 view .LVU534
	addq	$24, %rsp
	movl	%r13d, %eax
	popq	%rbx
.LVL161:
	.loc 1 19106 1 view .LVU535
	popq	%r12
.LVL162:
	.loc 1 19106 1 view .LVU536
	popq	%r13
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL163:
	.p2align 4,,10
	.p2align 3
.L139:
	.cfi_restore_state
.LBB275:
.LBB266:
.LBB264:
.LBB262:
	.loc 1 997 38 view .LVU537
	movzbl	.LC12(%rax), %edx
	.loc 1 997 30 view .LVU538
	testb	%dl, %dl
	je	.L161
.LVL164:
.L136:
	.loc 1 998 16 view .LVU539
	movb	%dl, 256(%rbx,%rax)
	.loc 1 997 5 view .LVU540
	addq	$1, %rax
.LVL165:
	.loc 1 997 30 view .LVU541
	cmpq	$255, %rax
	jne	.L139
	.loc 1 1002 14 view .LVU542
	leaq	511(%rbx), %rax
.LVL166:
.L138:
	.loc 1 1002 16 view .LVU543
	movb	$0, (%rax)
	.loc 1 1002 16 view .LVU544
.LBE262:
.LBE264:
.LBE266:
.LBE275:
	.loc 1 19072 5 is_stmt 1 view .LVU545
	.loc 1 19078 42 is_stmt 0 view .LVU546
	leaq	-40(%rbp), %rsi
.LVL167:
	.loc 1 19078 42 view .LVU547
	movq	%r12, %rdi
.LVL168:
	.loc 1 19072 28 view .LVU548
	movl	$1, 512(%rbx)
	.loc 1 19075 5 is_stmt 1 view .LVU549
	.loc 1 19075 46 is_stmt 0 view .LVU550
	movl	$5, 520(%rbx)
	.loc 1 19078 5 is_stmt 1 view .LVU551
	.loc 1 19078 42 is_stmt 0 view .LVU552
	call	_ZL28ma_context_open_client__jackP10ma_contextPP16ma_jack_client_t
.LVL169:
	movl	%eax, %r13d
.LVL170:
	.loc 1 19079 5 is_stmt 1 view .LVU553
	testl	%eax, %eax
	jne	.L140
	.loc 1 19084 5 view .LVU554
	.loc 1 19084 119 is_stmt 0 view .LVU555
	movq	-40(%rbp), %rdi
	call	*480(%r12)
.LVL171:
	.loc 1 19087 70 view .LVU556
	movl	$5, %ecx
	.loc 1 19085 50 view .LVU557
	movl	$0, 524(%rbx)
	.loc 1 19084 50 view .LVU558
	movl	%eax, 528(%rbx)
	.loc 1 19085 5 is_stmt 1 view .LVU559
	.loc 1 19087 5 view .LVU560
	.loc 1 19087 55 is_stmt 0 view .LVU561
	movq	496(%r12), %rax
	jmp	.L148
.LVL172:
	.p2align 4,,10
	.p2align 3
.L159:
.LBB276:
.LBB274:
.LBB273:
.LBB272:
	.loc 1 1002 14 view .LVU562
	addq	%rcx, %rax
.LVL173:
	.loc 1 1002 14 view .LVU563
	jmp	.L142
.LVL174:
	.p2align 4,,10
	.p2align 3
.L140:
	.loc 1 1002 14 view .LVU564
.LBE272:
.LBE273:
.LBE274:
.LBE276:
	.loc 1 19080 9 is_stmt 1 view .LVU565
.LBB277:
.LBI277:
	.loc 1 28929 16 view .LVU566
.LBB278:
	.loc 1 28931 5 view .LVU567
	.loc 1 28935 5 view .LVU568
	.loc 1 28935 5 is_stmt 0 view .LVU569
.LBE278:
.LBE277:
	.loc 1 19080 21 view .LVU570
	movq	112(%r12), %rdi
	movl	$.LC15, %edx
	movl	$1, %esi
	xorl	%eax, %eax
.LVL175:
	.loc 1 19080 21 view .LVU571
	call	ma_log_postf
.LVL176:
	.loc 1 19081 9 is_stmt 1 view .LVU572
	.loc 1 19106 1 is_stmt 0 view .LVU573
	addq	$24, %rsp
	movl	%r13d, %eax
	popq	%rbx
.LVL177:
	.loc 1 19106 1 view .LVU574
	popq	%r12
.LVL178:
	.loc 1 19106 1 view .LVU575
	popq	%r13
.LVL179:
	.loc 1 19106 1 view .LVU576
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL180:
	.p2align 4,,10
	.p2align 3
.L161:
	.cfi_restore_state
.LBB279:
.LBB267:
.LBB265:
.LBB263:
	.loc 1 1002 14 view .LVU577
	addq	%rcx, %rax
.LVL181:
	.loc 1 1002 14 view .LVU578
	jmp	.L138
.LVL182:
.L149:
	.loc 1 1002 14 view .LVU579
.LBE263:
.LBE265:
.LBE267:
.LBE279:
	.loc 1 19061 16 view .LVU580
	movl	$-104, %r13d
	jmp	.L132
.LVL183:
.L160:
	.loc 1 19089 9 is_stmt 1 view .LVU581
	.loc 1 19089 70 is_stmt 0 view .LVU582
	movq	-40(%rbp), %rdi
	.loc 1 19091 16 view .LVU583
	movl	$-301, %r13d
.LVL184:
	.loc 1 19089 70 view .LVU584
	call	*440(%r12)
.LVL185:
	.loc 1 19090 9 is_stmt 1 view .LVU585
.LBB280:
.LBI280:
	.loc 1 28929 16 view .LVU586
.LBB281:
	.loc 1 28931 5 view .LVU587
	.loc 1 28935 5 view .LVU588
	.loc 1 28935 5 is_stmt 0 view .LVU589
.LBE281:
.LBE280:
	.loc 1 19090 21 view .LVU590
	movq	112(%r12), %rdi
	movl	$.LC17, %edx
	xorl	%eax, %eax
	movl	$1, %esi
	call	ma_log_postf
.LVL186:
	.loc 1 19091 9 is_stmt 1 view .LVU591
	.loc 1 19091 16 is_stmt 0 view .LVU592
	jmp	.L132
.LVL187:
.L158:
	.loc 1 19058 5 discriminator 1 view .LVU593
	movl	$.LC14, %ecx
.LVL188:
	.loc 1 19058 5 discriminator 1 view .LVU594
	movl	$19058, %edx
.LVL189:
	.loc 1 19058 5 discriminator 1 view .LVU595
	movl	$.LC8, %esi
.LVL190:
	.loc 1 19058 5 discriminator 1 view .LVU596
	movl	$.LC9, %edi
.LVL191:
	.loc 1 19058 5 discriminator 1 view .LVU597
	call	__assert_fail
.LVL192:
	.cfi_endproc
.LFE78:
	.size	_ZL32ma_context_get_device_info__jackP10ma_context14ma_device_typePK12ma_device_idP14ma_device_info, .-_ZL32ma_context_get_device_info__jackP10ma_context14ma_device_typePK12ma_device_idP14ma_device_info
	.section	.rodata.str1.8
	.align 8
.LC18:
	.string	"ma_result ma_device_uninit__jack(ma_device*)"
	.section	.rodata.str1.1
.LC19:
	.string	"pDevice != __null"
	.text
	.p2align 4
	.type	_ZL22ma_device_uninit__jackP9ma_device, @function
_ZL22ma_device_uninit__jackP9ma_device:
.LVL193:
.LFB79:
	.loc 1 19110 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 19110 1 is_stmt 0 view .LVU599
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$8, %rsp
	.cfi_offset 3, -24
1:	call	mcount
	.loc 1 19110 1 view .LVU600
	.loc 1 19111 5 is_stmt 1 view .LVU601
	.loc 1 19113 5 view .LVU602
	.loc 1 19110 1 is_stmt 0 view .LVU603
	movq	%rdi, %rbx
	.loc 1 19113 5 view .LVU604
	testq	%rdi, %rdi
	je	.L206
	.loc 1 19115 5 is_stmt 1 view .LVU605
	.loc 1 19115 14 is_stmt 0 view .LVU606
	movq	(%rdi), %rax
.LVL194:
	.loc 1 19116 5 is_stmt 1 view .LVU607
	testq	%rax, %rax
	je	.L207
	.loc 1 19118 5 view .LVU608
	.loc 1 19118 23 is_stmt 0 view .LVU609
	movq	3344(%rdi), %rdi
.LVL195:
	.loc 1 19118 5 view .LVU610
	testq	%rdi, %rdi
	je	.L165
	.loc 1 19119 9 is_stmt 1 view .LVU611
	.loc 1 19119 70 is_stmt 0 view .LVU612
	call	*440(%rax)
.LVL196:
.L165:
	.loc 1 19122 5 is_stmt 1 view .LVU613
	.loc 1 19122 18 is_stmt 0 view .LVU614
	movl	8(%rbx), %eax
	.loc 1 19122 49 view .LVU615
	leal	-2(%rax), %edx
	.loc 1 19122 5 view .LVU616
	cmpl	$1, %edx
	jbe	.L208
.L166:
	.loc 1 19127 5 is_stmt 1 view .LVU617
	andl	$-3, %eax
	.loc 1 19127 50 is_stmt 0 view .LVU618
	cmpl	$1, %eax
	je	.L209
.L185:
	.loc 1 19133 1 view .LVU619
	movq	-8(%rbp), %rbx
.LVL197:
	.loc 1 19133 1 view .LVU620
	xorl	%eax, %eax
	leave
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL198:
	.p2align 4,,10
	.p2align 3
.L209:
	.cfi_restore_state
	.loc 1 19128 9 is_stmt 1 view .LVU621
	.loc 1 19128 31 is_stmt 0 view .LVU622
	movq	3368(%rbx), %rdi
	.loc 1 19128 70 view .LVU623
	movq	(%rbx), %rax
.LVL199:
.LBB314:
.LBI314:
	.loc 1 44086 13 is_stmt 1 view .LVU624
.LBB315:
	.loc 1 44088 5 view .LVU625
	testq	%rdi, %rdi
	je	.L171
	.loc 1 44092 5 view .LVU626
	movq	312(%rax), %rdx
.LVL200:
.LBB316:
.LBI316:
	.loc 1 44086 13 view .LVU627
.LBB317:
	.loc 1 44093 9 is_stmt 0 view .LVU628
	testq	%rdx, %rdx
	je	.L185
	.loc 1 44094 41 view .LVU629
	movq	288(%rax), %rsi
	call	*%rdx
.LVL201:
	.loc 1 44094 41 view .LVU630
.LBE317:
.LBE316:
.LBE315:
.LBE314:
	.loc 1 19129 58 view .LVU631
	movq	(%rbx), %rax
.L171:
	.loc 1 19129 9 is_stmt 1 view .LVU632
	.loc 1 19129 31 is_stmt 0 view .LVU633
	movq	3352(%rbx), %rdi
.LVL202:
.LBB318:
.LBI318:
	.loc 1 44086 13 is_stmt 1 view .LVU634
.LBB319:
	.loc 1 44088 5 view .LVU635
	testq	%rdi, %rdi
	je	.L185
	.loc 1 44092 5 view .LVU636
	movq	288(%rax), %rsi
	movq	312(%rax), %rax
.LVL203:
.LBB320:
.LBI320:
	.loc 1 44086 13 view .LVU637
.LBB321:
	.loc 1 44093 9 is_stmt 0 view .LVU638
	testq	%rax, %rax
	je	.L185
	.loc 1 44094 41 view .LVU639
	call	*%rax
.LVL204:
	.loc 1 44094 41 view .LVU640
.LBE321:
.LBE320:
.LBE319:
.LBE318:
	.loc 1 19133 1 view .LVU641
	movq	-8(%rbp), %rbx
.LVL205:
	.loc 1 19133 1 view .LVU642
	xorl	%eax, %eax
	leave
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL206:
	.p2align 4,,10
	.p2align 3
.L208:
	.cfi_restore_state
	.loc 1 19123 9 is_stmt 1 view .LVU643
	.loc 1 19123 31 is_stmt 0 view .LVU644
	movq	3376(%rbx), %rdi
	.loc 1 19123 69 view .LVU645
	movq	(%rbx), %rdx
.LVL207:
.LBB322:
.LBI322:
	.loc 1 44086 13 is_stmt 1 view .LVU646
.LBB323:
	.loc 1 44088 5 view .LVU647
	testq	%rdi, %rdi
	je	.L167
	.loc 1 44092 5 view .LVU648
	movq	312(%rdx), %rcx
.LVL208:
.LBB324:
.LBI324:
	.loc 1 44086 13 view .LVU649
.LBB325:
	.loc 1 44093 9 is_stmt 0 view .LVU650
	testq	%rcx, %rcx
	je	.L166
	.loc 1 44094 41 view .LVU651
	movq	288(%rdx), %rsi
	call	*%rcx
.LVL209:
	.loc 1 44094 41 view .LVU652
.LBE325:
.LBE324:
.LBE323:
.LBE322:
	.loc 1 19124 57 view .LVU653
	movq	(%rbx), %rdx
.L167:
	.loc 1 19124 9 is_stmt 1 view .LVU654
	.loc 1 19124 31 is_stmt 0 view .LVU655
	movq	3360(%rbx), %rdi
.LVL210:
.LBB326:
.LBI326:
	.loc 1 44086 13 is_stmt 1 view .LVU656
.LBB327:
	.loc 1 44088 5 view .LVU657
	testq	%rdi, %rdi
	je	.L205
	.loc 1 44092 5 view .LVU658
	movq	312(%rdx), %rax
.LVL211:
.LBB328:
.LBI328:
	.loc 1 44086 13 view .LVU659
	.loc 1 44086 13 is_stmt 0 view .LVU660
	movq	288(%rdx), %rsi
.LBB329:
	.loc 1 44093 9 view .LVU661
	testq	%rax, %rax
	je	.L205
	.loc 1 44094 41 view .LVU662
	call	*%rax
.LVL212:
.L205:
	.loc 1 44094 41 view .LVU663
.LBE329:
.LBE328:
.LBE327:
.LBE326:
	.loc 1 19127 18 view .LVU664
	movl	8(%rbx), %eax
.LBB333:
.LBB332:
.LBB331:
.LBB330:
	jmp	.L166
.L206:
	.loc 1 19127 18 view .LVU665
.LBE330:
.LBE331:
.LBE332:
.LBE333:
	.loc 1 19113 5 discriminator 1 view .LVU666
	movl	$.LC18, %ecx
	movl	$19113, %edx
	movl	$.LC8, %esi
	movl	$.LC19, %edi
	call	__assert_fail
.LVL213:
.L207:
	.loc 1 19116 5 discriminator 1 view .LVU667
	movl	$.LC18, %ecx
	movl	$19116, %edx
	movl	$.LC8, %esi
	movl	$.LC9, %edi
	call	__assert_fail
.LVL214:
	.loc 1 19116 5 discriminator 1 view .LVU668
	.cfi_endproc
.LFE79:
	.size	_ZL22ma_device_uninit__jackP9ma_device, .-_ZL22ma_device_uninit__jackP9ma_device
	.section	.rodata.str1.8
	.align 8
.LC20:
	.string	"void ma_device__jack_shutdown_callback(void*)"
	.text
	.p2align 4
	.type	_ZL33ma_device__jack_shutdown_callbackPv, @function
_ZL33ma_device__jack_shutdown_callbackPv:
.LVL215:
.LFB81:
	.loc 1 19136 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 19136 1 is_stmt 0 view .LVU670
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
1:	call	mcount
	.loc 1 19136 1 view .LVU671
	.loc 1 19138 5 is_stmt 1 view .LVU672
.LVL216:
	.loc 1 19139 5 view .LVU673
	testq	%rdi, %rdi
	je	.L218
	.loc 1 19141 5 view .LVU674
.LVL217:
.LBB346:
.LBI346:
	.loc 1 29817 18 view .LVU675
.LBB347:
.LBB348:
.LBB349:
.LBI349:
	.loc 1 29890 24 view .LVU676
.LBB350:
	.loc 1 29896 5 view .LVU677
	.loc 1 29896 29 is_stmt 0 view .LVU678
	movl	16(%rdi), %eax
.LVL218:
	.loc 1 29896 29 view .LVU679
.LBE350:
.LBE349:
.LBE348:
	.loc 1 29825 5 view .LVU680
	testl	%eax, %eax
	je	.L210
.LVL219:
.LBB351:
.LBB352:
.LBI352:
	.loc 1 29890 24 is_stmt 1 view .LVU681
.LBB353:
	.loc 1 29896 5 view .LVU682
	.loc 1 29896 29 is_stmt 0 view .LVU683
	movl	16(%rdi), %eax
.LVL220:
	.loc 1 29896 29 view .LVU684
.LBE353:
.LBE352:
.LBE351:
	.loc 1 29829 5 view .LVU685
	cmpl	$1, %eax
	je	.L210
.LBE347:
.LBE346:
	.loc 1 19142 1 view .LVU686
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
.LBB355:
.LBB354:
	jmp	ma_device_stop.part.0.isra.0
.LVL221:
	.p2align 4,,10
	.p2align 3
.L210:
	.cfi_restore_state
	.loc 1 19142 1 view .LVU687
.LBE354:
.LBE355:
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL222:
.L218:
	.cfi_restore_state
.LBB356:
.LBI356:
	.loc 1 19135 13 is_stmt 1 view .LVU688
.LBB357:
	.loc 1 19139 5 is_stmt 0 view .LVU689
	movl	$.LC20, %ecx
	movl	$19139, %edx
	movl	$.LC8, %esi
	movl	$.LC19, %edi
.LVL223:
	.loc 1 19139 5 view .LVU690
	call	__assert_fail
.LVL224:
.LBE357:
.LBE356:
	.cfi_endproc
.LFE81:
	.size	_ZL33ma_device__jack_shutdown_callbackPv, .-_ZL33ma_device__jack_shutdown_callbackPv
	.section	.rodata.str1.8
	.align 8
.LC21:
	.string	"int ma_device__jack_buffer_size_callback(ma_jack_nframes_t, void*)"
	.text
	.p2align 4
	.type	_ZL36ma_device__jack_buffer_size_callbackjPv, @function
_ZL36ma_device__jack_buffer_size_callbackjPv:
.LVL225:
.LFB84:
	.loc 1 19145 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 19145 1 is_stmt 0 view .LVU692
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 14, -24
	.cfi_offset 13, -32
	.cfi_offset 12, -40
	.cfi_offset 3, -48
1:	call	mcount
	.loc 1 19145 1 view .LVU693
	.loc 1 19146 5 is_stmt 1 view .LVU694
.LVL226:
	.loc 1 19147 5 view .LVU695
	.loc 1 19145 1 is_stmt 0 view .LVU696
	movl	%edi, %r12d
	movq	%rsi, %rbx
	.loc 1 19147 5 view .LVU697
	testq	%rsi, %rsi
	je	.L261
	.loc 1 19149 5 is_stmt 1 view .LVU698
.LBB398:
	.loc 1 19149 18 is_stmt 0 view .LVU699
	movl	8(%rsi), %eax
	.loc 1 19149 49 view .LVU700
	leal	-2(%rax), %edx
	.loc 1 19149 5 view .LVU701
	cmpl	$1, %edx
	jbe	.L262
.LVL227:
.L221:
	.loc 1 19149 5 view .LVU702
.LBE398:
	.loc 1 19162 5 is_stmt 1 view .LVU703
.LBB427:
	andl	$-3, %eax
.LBE427:
	.loc 1 19175 12 is_stmt 0 view .LVU704
	xorl	%r8d, %r8d
.LBB455:
	.loc 1 19162 50 view .LVU705
	cmpl	$1, %eax
	je	.L263
.LBE455:
	.loc 1 19176 1 view .LVU706
	addq	$32, %rsp
	movl	%r8d, %eax
	popq	%rbx
.LVL228:
	.loc 1 19176 1 view .LVU707
	popq	%r12
.LVL229:
	.loc 1 19176 1 view .LVU708
	popq	%r13
	popq	%r14
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL230:
	.p2align 4,,10
	.p2align 3
.L263:
	.cfi_restore_state
.LBB456:
.LBB428:
	.loc 1 19163 9 is_stmt 1 view .LVU709
.LBB429:
.LBI429:
	.loc 1 44154 18 view .LVU710
.LBB430:
	.loc 1 44156 5 view .LVU711
	.loc 1 44156 15 is_stmt 0 view .LVU712
	movabsq	$17179869188, %rax
	movdqa	.LC22(%rip), %xmm0
.LBE430:
.LBE429:
	.loc 1 19163 43 view .LVU713
	movl	1304(%rbx), %r14d
.LBB434:
.LBB431:
	.loc 1 44156 15 view .LVU714
	movq	%rax, -48(%rbp)
	.loc 1 44164 5 is_stmt 1 view .LVU715
.LVL231:
	.loc 1 44164 5 is_stmt 0 view .LVU716
.LBE431:
.LBE434:
	.loc 1 19164 72 view .LVU717
	movq	(%rbx), %rdx
.LBB435:
.LBB432:
	.loc 1 44164 24 view .LVU718
	movslq	1300(%rbx), %rax
.LBE432:
.LBE435:
	.loc 1 19163 43 view .LVU719
	imull	%r12d, %r14d
.LBB436:
.LBB433:
	.loc 1 44156 15 view .LVU720
	movaps	%xmm0, -64(%rbp)
.LBE433:
.LBE436:
	.loc 1 19163 140 view .LVU721
	imull	-64(%rbp,%rax,4), %r14d
.LVL232:
	.loc 1 19164 9 is_stmt 1 view .LVU722
.LBB437:
.LBI437:
	.loc 1 44063 14 view .LVU723
.LBB438:
	.loc 1 44065 5 view .LVU724
.LBB439:
.LBI439:
	.loc 1 44050 14 view .LVU725
.LBB440:
	.loc 1 44052 5 view .LVU726
	.loc 1 44053 9 view .LVU727
	.loc 1 44053 35 is_stmt 0 view .LVU728
	movq	296(%rdx), %rax
	.loc 1 44053 9 view .LVU729
	testq	%rax, %rax
	je	.L224
	.loc 1 44054 13 is_stmt 1 view .LVU730
	.loc 1 44054 50 is_stmt 0 view .LVU731
	movq	288(%rdx), %rsi
	movq	%r14, %rdi
	call	*%rax
.LVL233:
	.loc 1 44054 50 view .LVU732
	movq	%rax, %r13
.LVL234:
	.loc 1 44054 50 view .LVU733
.LBE440:
.LBE439:
	.loc 1 44066 5 is_stmt 1 view .LVU734
	testq	%rax, %rax
	je	.L224
	.loc 1 44067 9 view .LVU735
.LVL235:
.LBB441:
.LBI441:
	.loc 1 776 23 view .LVU736
.LBB442:
	.loc 1 781 5 view .LVU737
	testq	%r14, %r14
	jne	.L264
.LVL236:
.L227:
	.loc 1 781 5 is_stmt 0 view .LVU738
.LBE442:
.LBE441:
	.loc 1 44070 5 is_stmt 1 view .LVU739
	.loc 1 44070 5 is_stmt 0 view .LVU740
.LBE438:
.LBE437:
	.loc 1 19165 9 is_stmt 1 view .LVU741
	.loc 1 19169 9 view .LVU742
	.loc 1 19169 31 is_stmt 0 view .LVU743
	movq	3368(%rbx), %rdi
.LVL237:
.LBB446:
.LBI446:
	.loc 1 44086 13 is_stmt 1 view .LVU744
.LBB447:
	.loc 1 44088 5 view .LVU745
	testq	%rdi, %rdi
	je	.L228
.LBE447:
.LBE446:
	.loc 1 19169 70 is_stmt 0 view .LVU746
	movq	(%rbx), %rdx
.LBB451:
.LBB450:
	.loc 1 44092 5 is_stmt 1 view .LVU747
	movq	312(%rdx), %rax
.LVL238:
.LBB448:
.LBI448:
	.loc 1 44086 13 view .LVU748
.LBB449:
	.loc 1 44093 9 is_stmt 0 view .LVU749
	testq	%rax, %rax
	je	.L228
	.loc 1 44094 41 view .LVU750
	movq	288(%rdx), %rsi
	call	*%rax
.LVL239:
.L228:
	.loc 1 44094 41 view .LVU751
.LBE449:
.LBE448:
.LBE450:
.LBE451:
	.loc 1 19171 9 is_stmt 1 view .LVU752
	.loc 1 19171 51 is_stmt 0 view .LVU753
	movq	%r13, 3368(%rbx)
	.loc 1 19172 9 is_stmt 1 view .LVU754
.LBE428:
.LBE456:
	.loc 1 19175 12 is_stmt 0 view .LVU755
	xorl	%r8d, %r8d
.LBB457:
.LBB453:
	.loc 1 19172 54 view .LVU756
	movl	%r12d, 1568(%rbx)
.LBE453:
.LBE457:
	.loc 1 19176 1 view .LVU757
	addq	$32, %rsp
	movl	%r8d, %eax
	popq	%rbx
.LVL240:
	.loc 1 19176 1 view .LVU758
	popq	%r12
.LVL241:
	.loc 1 19176 1 view .LVU759
	popq	%r13
.LVL242:
	.loc 1 19176 1 view .LVU760
	popq	%r14
.LVL243:
	.loc 1 19176 1 view .LVU761
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL244:
	.p2align 4,,10
	.p2align 3
.L262:
	.cfi_restore_state
.LBB458:
.LBB399:
	.loc 1 19150 9 is_stmt 1 view .LVU762
.LBB400:
.LBI400:
	.loc 1 44154 18 view .LVU763
.LBB401:
	.loc 1 44156 5 view .LVU764
	.loc 1 44156 15 is_stmt 0 view .LVU765
	movabsq	$17179869188, %rax
	movdqa	.LC22(%rip), %xmm0
.LBE401:
.LBE400:
	.loc 1 19150 43 view .LVU766
	movl	2736(%rsi), %r14d
.LBB405:
.LBB402:
	.loc 1 44156 15 view .LVU767
	movq	%rax, -48(%rbp)
	.loc 1 44164 5 is_stmt 1 view .LVU768
.LVL245:
	.loc 1 44164 5 is_stmt 0 view .LVU769
.LBE402:
.LBE405:
	.loc 1 19151 72 view .LVU770
	movq	(%rsi), %rdx
.LBB406:
.LBB403:
	.loc 1 44164 24 view .LVU771
	movslq	2732(%rsi), %rax
.LBE403:
.LBE406:
	.loc 1 19150 43 view .LVU772
	imull	%edi, %r14d
.LBB407:
.LBB404:
	.loc 1 44156 15 view .LVU773
	movaps	%xmm0, -64(%rbp)
.LBE404:
.LBE407:
	.loc 1 19150 138 view .LVU774
	imull	-64(%rbp,%rax,4), %r14d
.LVL246:
	.loc 1 19151 9 is_stmt 1 view .LVU775
.LBB408:
.LBI408:
	.loc 1 44063 14 view .LVU776
.LBB409:
	.loc 1 44065 5 view .LVU777
.LBB410:
.LBI410:
	.loc 1 44050 14 view .LVU778
.LBB411:
	.loc 1 44052 5 view .LVU779
	.loc 1 44053 9 view .LVU780
	.loc 1 44053 35 is_stmt 0 view .LVU781
	movq	296(%rdx), %rax
	.loc 1 44053 9 view .LVU782
	testq	%rax, %rax
	je	.L224
	.loc 1 44054 13 is_stmt 1 view .LVU783
	.loc 1 44054 50 is_stmt 0 view .LVU784
	movq	288(%rdx), %rsi
	movq	%r14, %rdi
.LVL247:
	.loc 1 44054 50 view .LVU785
	call	*%rax
.LVL248:
	.loc 1 44054 50 view .LVU786
	movq	%rax, %r13
.LVL249:
	.loc 1 44054 50 view .LVU787
.LBE411:
.LBE410:
	.loc 1 44066 5 is_stmt 1 view .LVU788
	testq	%rax, %rax
	je	.L224
	.loc 1 44067 9 view .LVU789
.LVL250:
.LBB412:
.LBI412:
	.loc 1 776 23 view .LVU790
.LBB413:
	.loc 1 781 5 view .LVU791
	testq	%r14, %r14
	jne	.L265
.LVL251:
.L225:
	.loc 1 781 5 is_stmt 0 view .LVU792
.LBE413:
.LBE412:
	.loc 1 44070 5 is_stmt 1 view .LVU793
	.loc 1 44070 5 is_stmt 0 view .LVU794
.LBE409:
.LBE408:
	.loc 1 19152 9 is_stmt 1 view .LVU795
	.loc 1 19156 9 view .LVU796
	.loc 1 19156 31 is_stmt 0 view .LVU797
	movq	3376(%rbx), %rdi
.LVL252:
.LBB417:
.LBI417:
	.loc 1 44086 13 is_stmt 1 view .LVU798
.LBB418:
	.loc 1 44088 5 view .LVU799
	testq	%rdi, %rdi
	je	.L226
.LBE418:
.LBE417:
	.loc 1 19156 69 is_stmt 0 view .LVU800
	movq	(%rbx), %rdx
.LBB422:
.LBB421:
	.loc 1 44092 5 is_stmt 1 view .LVU801
	movq	312(%rdx), %rax
.LVL253:
.LBB419:
.LBI419:
	.loc 1 44086 13 view .LVU802
.LBB420:
	.loc 1 44093 9 is_stmt 0 view .LVU803
	testq	%rax, %rax
	je	.L226
	.loc 1 44094 41 view .LVU804
	movq	288(%rdx), %rsi
	call	*%rax
.LVL254:
.L226:
	.loc 1 44094 41 view .LVU805
.LBE420:
.LBE419:
.LBE421:
.LBE422:
	.loc 1 19158 9 is_stmt 1 view .LVU806
	.loc 1 19158 50 is_stmt 0 view .LVU807
	movq	%r13, 3376(%rbx)
	.loc 1 19159 9 is_stmt 1 view .LVU808
.LBE399:
.LBE458:
.LBB459:
	.loc 1 19162 18 is_stmt 0 view .LVU809
	movl	8(%rbx), %eax
.LBE459:
.LBB460:
.LBB424:
	.loc 1 19159 54 view .LVU810
	movl	%r12d, 1568(%rbx)
.LBE424:
	jmp	.L221
.LVL255:
	.p2align 4,,10
	.p2align 3
.L224:
	.loc 1 19159 54 view .LVU811
.LBE460:
	.loc 1 19176 1 view .LVU812
	addq	$32, %rsp
.LBB461:
.LBB425:
	.loc 1 19153 20 view .LVU813
	movl	$-4, %r8d
.LBE425:
.LBE461:
	.loc 1 19176 1 view .LVU814
	popq	%rbx
.LVL256:
	.loc 1 19176 1 view .LVU815
	movl	%r8d, %eax
	popq	%r12
.LVL257:
	.loc 1 19176 1 view .LVU816
	popq	%r13
	popq	%r14
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL258:
	.p2align 4,,10
	.p2align 3
.L264:
	.cfi_restore_state
.LBB462:
.LBB454:
.LBB452:
.LBB445:
.LBB444:
.LBB443:
	.loc 1 782 9 is_stmt 1 view .LVU817
	.loc 1 782 15 is_stmt 0 view .LVU818
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	call	memset
.LVL259:
	.loc 1 782 15 view .LVU819
	jmp	.L227
.LVL260:
	.p2align 4,,10
	.p2align 3
.L265:
	.loc 1 782 15 view .LVU820
.LBE443:
.LBE444:
.LBE445:
.LBE452:
.LBE454:
.LBE462:
.LBB463:
.LBB426:
.LBB423:
.LBB416:
.LBB415:
.LBB414:
	.loc 1 782 9 is_stmt 1 view .LVU821
	.loc 1 782 15 is_stmt 0 view .LVU822
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	call	memset
.LVL261:
	.loc 1 782 15 view .LVU823
	jmp	.L225
.LVL262:
.L261:
	.loc 1 782 15 view .LVU824
.LBE414:
.LBE415:
.LBE416:
.LBE423:
.LBE426:
.LBE463:
	.loc 1 19147 5 discriminator 1 view .LVU825
	movl	$.LC21, %ecx
	movl	$19147, %edx
	movl	$.LC8, %esi
	movl	$.LC19, %edi
.LVL263:
	.loc 1 19147 5 discriminator 1 view .LVU826
	call	__assert_fail
.LVL264:
	.cfi_endproc
.LFE84:
	.size	_ZL36ma_device__jack_buffer_size_callbackjPv, .-_ZL36ma_device__jack_buffer_size_callbackjPv
	.section	.rodata.str1.8
	.align 8
.LC23:
	.string	"int ma_device__jack_process_callback(ma_jack_nframes_t, void*)"
	.align 8
.LC24:
	.string	"void ma_device__read_frames_from_client(ma_device*, ma_uint32, void*)"
	.section	.rodata.str1.1
.LC25:
	.string	"frameCount > 0"
	.text
	.p2align 4
	.type	_ZL32ma_device__jack_process_callbackjPv, @function
_ZL32ma_device__jack_process_callbackjPv:
.LVL265:
.LFB87:
	.loc 1 19179 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 19179 1 is_stmt 0 view .LVU828
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
1:	call	mcount
	.loc 1 19179 1 view .LVU829
	.loc 1 19180 5 is_stmt 1 view .LVU830
	.loc 1 19181 5 view .LVU831
	.loc 1 19182 5 view .LVU832
	.loc 1 19184 5 view .LVU833
.LVL266:
	.loc 1 19185 5 view .LVU834
	.loc 1 19179 1 is_stmt 0 view .LVU835
	movl	%edi, %r14d
	movq	%rsi, %r12
	.loc 1 19185 5 view .LVU836
	testq	%rsi, %rsi
	je	.L314
	.loc 1 19187 5 is_stmt 1 view .LVU837
	.loc 1 19187 14 is_stmt 0 view .LVU838
	movq	(%rsi), %rbx
.LVL267:
	.loc 1 19188 5 is_stmt 1 view .LVU839
	testq	%rbx, %rbx
	je	.L315
	.loc 1 19190 5 view .LVU840
.LBB487:
	.loc 1 19190 18 is_stmt 0 view .LVU841
	movl	8(%rsi), %eax
	.loc 1 19190 49 view .LVU842
	leal	-2(%rax), %edx
	.loc 1 19190 5 view .LVU843
	cmpl	$1, %edx
	jbe	.L316
.LVL268:
.L269:
	.loc 1 19190 5 view .LVU844
.LBE487:
	.loc 1 19209 5 is_stmt 1 view .LVU845
.LBB510:
	movl	%eax, %edx
	andl	$-3, %edx
	.loc 1 19209 50 is_stmt 0 view .LVU846
	cmpl	$1, %edx
	je	.L317
.L297:
.LBE510:
	.loc 1 19229 1 view .LVU847
	addq	$24, %rsp
	xorl	%eax, %eax
	popq	%rbx
.LVL269:
	.loc 1 19229 1 view .LVU848
	popq	%r12
.LVL270:
	.loc 1 19229 1 view .LVU849
	popq	%r13
	popq	%r14
.LVL271:
	.loc 1 19229 1 view .LVU850
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL272:
	.p2align 4,,10
	.p2align 3
.L317:
	.cfi_restore_state
.LBB535:
.LBB511:
	.loc 1 19210 9 is_stmt 1 view .LVU851
	.loc 1 19210 71 is_stmt 0 view .LVU852
	movq	3368(%r12), %r8
.LVL273:
.LBB512:
.LBI512:
	.loc 1 29960 18 is_stmt 1 view .LVU853
.LBB513:
	.loc 1 29966 5 is_stmt 0 view .LVU854
	testq	%r8, %r8
	je	.L280
	.loc 1 29970 5 view .LVU855
	cmpl	$3, %eax
	je	.L318
.LVL274:
.LBB514:
.LBI514:
	.loc 1 6941 13 is_stmt 1 view .LVU856
.LBB515:
	.loc 1 6943 5 view .LVU857
	.loc 1 6944 5 view .LVU858
	testl	%r14d, %r14d
	je	.L319
	.loc 1 6945 5 view .LVU859
	.loc 1 6947 5 view .LVU860
.LBB516:
	cmpb	$0, 1884(%r12)
	jne	.L320
.LBE516:
	movq	%r8, %rdx
	movl	%r14d, %esi
	movq	%r12, %rdi
	call	_ZL34ma_device__read_frames_from_clientP9ma_devicejPv.part.0.lto_priv.0
.LVL275:
	.p2align 4,,10
	.p2align 3
.L280:
	.loc 1 6947 5 is_stmt 0 view .LVU861
.LBE515:
.LBE514:
.LBE513:
.LBE512:
.LBB524:
	.loc 1 19213 37 is_stmt 1 discriminator 1 view .LVU862
	movl	1304(%r12), %eax
	testl	%eax, %eax
	je	.L297
	leal	-1(%r14), %eax
	.loc 1 19213 37 is_stmt 0 view .LVU863
	xorl	%r15d, %r15d
	leaq	4(,%rax,4), %rax
	movq	%rax, -56(%rbp)
	jmp	.L292
.LVL276:
	.p2align 4,,10
	.p2align 3
.L286:
.LBB525:
.LBB526:
.LBB527:
	.loc 1 19222 47 view .LVU864
	movl	1304(%r12), %edi
.L287:
	.loc 1 19222 47 view .LVU865
.LBE527:
.LBE526:
.LBE525:
	.loc 1 19213 9 is_stmt 1 discriminator 2 view .LVU866
	addl	$1, %r15d
.LVL277:
	.loc 1 19213 37 discriminator 2 view .LVU867
	cmpl	%edi, %r15d
	jnb	.L297
.LVL278:
.L292:
.LBB530:
	.loc 1 19214 13 view .LVU868
	.loc 1 19214 102 is_stmt 0 view .LVU869
	movq	3352(%r12), %rax
	.loc 1 19214 150 view .LVU870
	movl	%r15d, %r13d
	.loc 1 19214 102 view .LVU871
	movl	%r14d, %esi
	movq	(%rax,%r13,8), %rdi
	call	*544(%rbx)
.LVL279:
	.loc 1 19215 13 is_stmt 1 view .LVU872
.LBB529:
	testq	%rax, %rax
	je	.L286
.LBB528:
	.loc 1 19216 17 view .LVU873
	.loc 1 19216 30 is_stmt 0 view .LVU874
	movq	3368(%r12), %rcx
	.loc 1 19222 47 view .LVU875
	movl	1304(%r12), %edi
	.loc 1 19216 30 view .LVU876
	leaq	(%rcx,%r13,4), %rdx
.LVL280:
	.loc 1 19217 17 is_stmt 1 view .LVU877
	.loc 1 19218 17 view .LVU878
	.loc 1 19218 41 view .LVU879
	testl	%r14d, %r14d
	je	.L287
	movq	-56(%rbp), %rsi
	.loc 1 19222 47 is_stmt 0 view .LVU880
	movl	%edi, %ecx
	.loc 1 19222 26 view .LVU881
	salq	$2, %rcx
	addq	%rax, %rsi
	cmpl	$1, %edi
	jne	.L289
	.p2align 4,,10
	.p2align 3
.L291:
	.loc 1 19219 21 is_stmt 1 view .LVU882
	.loc 1 19219 29 is_stmt 0 view .LVU883
	movss	(%rdx), %xmm0
	.loc 1 19221 26 view .LVU884
	addq	$4, %rax
.LVL281:
	.loc 1 19222 26 view .LVU885
	addq	%rcx, %rdx
.LVL282:
	.loc 1 19219 27 view .LVU886
	movss	%xmm0, -4(%rax)
	.loc 1 19221 21 is_stmt 1 view .LVU887
.LVL283:
	.loc 1 19222 21 view .LVU888
	.loc 1 19218 17 view .LVU889
	.loc 1 19218 41 view .LVU890
	cmpq	%rax, %rsi
	jne	.L291
	jmp	.L287
	.p2align 4,,10
	.p2align 3
.L289:
	.loc 1 19219 21 discriminator 2 view .LVU891
	.loc 1 19219 29 is_stmt 0 discriminator 2 view .LVU892
	movss	(%rdx), %xmm0
	.loc 1 19221 26 discriminator 2 view .LVU893
	addq	$4, %rax
.LVL284:
	.loc 1 19222 26 discriminator 2 view .LVU894
	addq	%rcx, %rdx
.LVL285:
	.loc 1 19219 27 discriminator 2 view .LVU895
	movss	%xmm0, -4(%rax)
	.loc 1 19221 21 is_stmt 1 discriminator 2 view .LVU896
.LVL286:
	.loc 1 19222 21 discriminator 2 view .LVU897
	.loc 1 19218 17 discriminator 2 view .LVU898
	.loc 1 19218 41 discriminator 2 view .LVU899
	cmpq	%rax, %rsi
	jne	.L289
	jmp	.L287
.LVL287:
	.p2align 4,,10
	.p2align 3
.L316:
	.loc 1 19218 41 is_stmt 0 discriminator 2 view .LVU900
.LBE528:
.LBE529:
.LBE530:
.LBE524:
.LBE511:
.LBE535:
.LBB536:
.LBB488:
.LBB489:
	.loc 1 19192 37 is_stmt 1 view .LVU901
	movl	2736(%rsi), %edx
	testl	%edx, %edx
	je	.L270
	leal	-1(%rdi), %eax
	.loc 1 19192 23 is_stmt 0 view .LVU902
	xorl	%r15d, %r15d
	leaq	4(,%rax,4), %rax
	movq	%rax, -56(%rbp)
	jmp	.L277
.LVL288:
	.p2align 4,,10
	.p2align 3
.L271:
.LBB490:
.LBB491:
.LBB492:
	.loc 1 19200 46 view .LVU903
	movl	2736(%r12), %edi
.L272:
	.loc 1 19200 46 view .LVU904
.LBE492:
.LBE491:
.LBE490:
	.loc 1 19192 9 is_stmt 1 discriminator 2 view .LVU905
	addl	$1, %r15d
.LVL289:
	.loc 1 19192 37 discriminator 2 view .LVU906
	cmpl	%edi, %r15d
	jnb	.L321
.LVL290:
.L277:
.LBB497:
	.loc 1 19193 13 view .LVU907
	.loc 1 19193 114 is_stmt 0 view .LVU908
	movq	3360(%r12), %rax
	.loc 1 19193 161 view .LVU909
	movl	%r15d, %r13d
	.loc 1 19193 114 view .LVU910
	movl	%r14d, %esi
	movq	(%rax,%r13,8), %rdi
	call	*544(%rbx)
.LVL291:
	.loc 1 19194 13 is_stmt 1 view .LVU911
.LBB495:
	testq	%rax, %rax
	je	.L271
.LBB493:
	.loc 1 19195 17 view .LVU912
	.loc 1 19195 24 is_stmt 0 view .LVU913
	movq	3376(%r12), %rcx
	.loc 1 19200 46 view .LVU914
	movl	2736(%r12), %edi
	.loc 1 19195 24 view .LVU915
	leaq	(%rcx,%r13,4), %rdx
.LVL292:
	.loc 1 19196 17 is_stmt 1 view .LVU916
	.loc 1 19197 17 view .LVU917
	.loc 1 19197 41 view .LVU918
	testl	%r14d, %r14d
	je	.L272
	movq	-56(%rbp), %rsi
	.loc 1 19200 46 is_stmt 0 view .LVU919
	movl	%edi, %ecx
	.loc 1 19200 26 view .LVU920
	salq	$2, %rcx
	addq	%rax, %rsi
	cmpl	$1, %edi
	jne	.L274
	.p2align 4,,10
	.p2align 3
.L276:
	.loc 1 19198 21 is_stmt 1 view .LVU921
	.loc 1 19198 29 is_stmt 0 view .LVU922
	movss	(%rax), %xmm0
	.loc 1 19201 26 view .LVU923
	addq	$4, %rax
.LVL293:
	.loc 1 19198 27 view .LVU924
	movss	%xmm0, (%rdx)
	.loc 1 19200 21 is_stmt 1 view .LVU925
	.loc 1 19200 26 is_stmt 0 view .LVU926
	addq	%rcx, %rdx
.LVL294:
	.loc 1 19201 21 is_stmt 1 view .LVU927
	.loc 1 19197 17 view .LVU928
	.loc 1 19197 41 view .LVU929
	cmpq	%rax, %rsi
	jne	.L276
.LBE493:
.LBE495:
.LBE497:
	.loc 1 19192 9 view .LVU930
	addl	$1, %r15d
.LVL295:
	.loc 1 19192 37 view .LVU931
	cmpl	%edi, %r15d
	jb	.L277
.LVL296:
.L321:
	.loc 1 19192 37 is_stmt 0 view .LVU932
.LBE489:
.LBB499:
.LBB500:
	.loc 1 29970 18 view .LVU933
	movl	8(%r12), %eax
.LVL297:
.L270:
	.loc 1 29970 18 view .LVU934
.LBE500:
.LBE499:
	.loc 1 19206 9 is_stmt 1 view .LVU935
	.loc 1 19206 77 is_stmt 0 view .LVU936
	movq	3376(%r12), %rdx
.LVL298:
.LBB505:
.LBI499:
	.loc 1 29960 18 is_stmt 1 view .LVU937
.LBB503:
	.loc 1 29966 5 is_stmt 0 view .LVU938
	testq	%rdx, %rdx
	je	.L269
	.loc 1 29970 5 view .LVU939
	cmpl	$3, %eax
	je	.L322
	.loc 1 29979 9 view .LVU940
	leal	-2(%rax), %ecx
	.loc 1 29979 53 view .LVU941
	andl	$-3, %ecx
	jne	.L269
	.loc 1 29984 45 view .LVU942
	movl	%r14d, %esi
	movq	%r12, %rdi
	call	_ZL32ma_device__send_frames_to_clientP9ma_devicejPKv.lto_priv.0
.LVL299:
	.loc 1 29984 45 view .LVU943
.LBE503:
.LBE505:
.LBE488:
.LBE536:
.LBB537:
	.loc 1 19209 18 view .LVU944
	movl	8(%r12), %eax
	jmp	.L269
.LVL300:
	.p2align 4,,10
	.p2align 3
.L274:
	.loc 1 19209 18 view .LVU945
.LBE537:
.LBB538:
.LBB508:
.LBB506:
.LBB498:
.LBB496:
.LBB494:
	.loc 1 19198 21 is_stmt 1 discriminator 2 view .LVU946
	.loc 1 19198 29 is_stmt 0 discriminator 2 view .LVU947
	movss	(%rax), %xmm0
	.loc 1 19201 26 discriminator 2 view .LVU948
	addq	$4, %rax
.LVL301:
	.loc 1 19198 27 discriminator 2 view .LVU949
	movss	%xmm0, (%rdx)
	.loc 1 19200 21 is_stmt 1 discriminator 2 view .LVU950
	.loc 1 19200 26 is_stmt 0 discriminator 2 view .LVU951
	addq	%rcx, %rdx
.LVL302:
	.loc 1 19201 21 is_stmt 1 discriminator 2 view .LVU952
	.loc 1 19197 17 discriminator 2 view .LVU953
	.loc 1 19197 41 discriminator 2 view .LVU954
	cmpq	%rax, %rsi
	jne	.L274
	jmp	.L272
.LVL303:
.L318:
	.loc 1 19197 41 is_stmt 0 discriminator 2 view .LVU955
.LBE494:
.LBE496:
.LBE498:
.LBE506:
.LBE508:
.LBE538:
.LBB539:
.LBB533:
.LBB531:
.LBB522:
.LBB519:
.LBI519:
	.loc 1 29960 18 is_stmt 1 view .LVU956
.LBB520:
	.loc 1 29976 55 is_stmt 0 view .LVU957
	leaq	408(%r12), %rcx
	movq	%r8, %rdx
	movl	%r14d, %esi
	movq	%r12, %rdi
	call	_ZL42ma_device__handle_duplex_callback_playbackP9ma_devicejPvP9ma_pcm_rb.isra.0
.LVL304:
	.loc 1 29976 55 view .LVU958
	jmp	.L280
.LVL305:
.L322:
	.loc 1 29976 55 view .LVU959
.LBE520:
.LBE519:
.LBE522:
.LBE531:
.LBE533:
.LBE539:
.LBB540:
.LBB509:
.LBB507:
.LBB504:
.LBB501:
.LBI501:
	.loc 1 29960 18 is_stmt 1 view .LVU960
.LBB502:
	.loc 1 29972 54 is_stmt 0 view .LVU961
	leaq	408(%r12), %rcx
	movl	%r14d, %esi
	movq	%r12, %rdi
	call	_ZL41ma_device__handle_duplex_callback_captureP9ma_devicejPKvP9ma_pcm_rb.isra.0
.LVL306:
	.loc 1 29972 54 view .LVU962
.LBE502:
.LBE501:
.LBE504:
.LBE507:
.LBE509:
.LBE540:
.LBB541:
	.loc 1 19209 18 view .LVU963
	movl	8(%r12), %eax
	jmp	.L269
.LVL307:
.L320:
.LBB534:
.LBB532:
.LBB523:
.LBB521:
.LBB518:
.LBB517:
	.loc 1 6948 9 is_stmt 1 view .LVU964
	.loc 1 6948 40 is_stmt 0 view .LVU965
	movl	%r14d, %edx
	movq	%r8, %rsi
	movq	%r12, %rdi
	call	_ZL31ma_device__handle_data_callbackP9ma_devicePvPKvj.constprop.1
.LVL308:
	.loc 1 6948 40 view .LVU966
	jmp	.L280
.LVL309:
.L319:
	.loc 1 6948 40 view .LVU967
.LBE517:
	.loc 1 6944 5 view .LVU968
	movl	$.LC24, %ecx
	movl	$6944, %edx
	movl	$.LC8, %esi
	movl	$.LC25, %edi
	call	__assert_fail
.LVL310:
.L315:
	.loc 1 6944 5 view .LVU969
.LBE518:
.LBE521:
.LBE523:
.LBE532:
.LBE534:
.LBE541:
	.loc 1 19188 5 discriminator 1 view .LVU970
	movl	$.LC23, %ecx
	movl	$19188, %edx
	movl	$.LC8, %esi
.LVL311:
	.loc 1 19188 5 discriminator 1 view .LVU971
	movl	$.LC9, %edi
.LVL312:
	.loc 1 19188 5 discriminator 1 view .LVU972
	call	__assert_fail
.LVL313:
.L314:
	.loc 1 19185 5 discriminator 1 view .LVU973
	movl	$.LC23, %ecx
	movl	$19185, %edx
	movl	$.LC8, %esi
.LVL314:
	.loc 1 19185 5 discriminator 1 view .LVU974
	movl	$.LC19, %edi
.LVL315:
	.loc 1 19185 5 discriminator 1 view .LVU975
	call	__assert_fail
.LVL316:
	.cfi_endproc
.LFE87:
	.size	_ZL32ma_device__jack_process_callbackjPv, .-_ZL32ma_device__jack_process_callbackjPv
	.section	.rodata.str1.8
	.align 8
.LC26:
	.string	"ma_result ma_device_init__jack(ma_device*, const ma_device_config*, ma_device_descriptor*, ma_device_descriptor*)"
	.section	.rodata.str1.1
.LC27:
	.string	"pConfig != __null"
	.section	.rodata.str1.8
	.align 8
.LC28:
	.string	"[JACK] Loopback mode not supported."
	.align 8
.LC29:
	.string	"[JACK] Only default devices are supported."
	.align 8
.LC30:
	.string	"[JACK] Exclusive mode not supported."
	.align 8
.LC31:
	.string	"[JACK] Failed to set process callback."
	.align 8
.LC32:
	.string	"[JACK] Failed to set buffer size callback."
	.section	.rodata.str1.1
.LC34:
	.string	"capture"
	.section	.rodata.str1.8
	.align 8
.LC35:
	.string	"[JACK] Failed to register ports."
	.section	.rodata.str1.1
.LC36:
	.string	"playback"
	.text
	.p2align 4
	.type	_ZL20ma_device_init__jackP9ma_devicePK16ma_device_configP20ma_device_descriptorS5_, @function
_ZL20ma_device_init__jackP9ma_devicePK16ma_device_configP20ma_device_descriptorS5_:
.LVL317:
.LFB89:
	.loc 1 19232 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 19232 1 is_stmt 0 view .LVU977
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$120, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
1:	call	mcount
	.loc 1 19232 1 view .LVU978
	.loc 1 19233 5 is_stmt 1 view .LVU979
	.loc 1 19234 5 view .LVU980
	.loc 1 19236 5 view .LVU981
	.loc 1 19232 1 is_stmt 0 view .LVU982
	movq	%rsi, -128(%rbp)
	movq	%rdi, %r12
	movq	%rdx, %r13
	movq	%rcx, %r14
	.loc 1 19236 5 view .LVU983
	testq	%rsi, %rsi
	je	.L484
	.loc 1 19237 5 is_stmt 1 view .LVU984
	testq	%rdi, %rdi
	je	.L485
	.loc 1 19239 5 view .LVU985
	.loc 1 19239 18 is_stmt 0 view .LVU986
	movl	(%rsi), %eax
.LBB680:
.LBB681:
.LBB682:
	.loc 1 29685 21 view .LVU987
	movq	(%rdi), %rdi
.LVL318:
	.loc 1 29685 21 view .LVU988
.LBE682:
.LBE681:
.LBE680:
	.loc 1 19239 5 view .LVU989
	cmpl	$4, %eax
	je	.L486
	.loc 1 19245 5 is_stmt 1 view .LVU990
	.loc 1 19245 58 is_stmt 0 view .LVU991
	movl	%eax, %edx
.LVL319:
	.loc 1 19245 58 view .LVU992
	andl	$-3, %edx
	.loc 1 19245 5 view .LVU993
	cmpl	$1, %edx
	je	.L487
	.loc 1 19246 58 view .LVU994
	subl	$2, %eax
	.loc 1 19245 195 view .LVU995
	cmpl	$1, %eax
	jbe	.L488
.LVL320:
.L334:
	.loc 1 19259 5 is_stmt 1 view .LVU996
	.loc 1 19259 82 is_stmt 0 view .LVU997
	leaq	3344(%r12), %rsi
	.loc 1 19259 42 view .LVU998
	call	_ZL28ma_context_open_client__jackP10ma_contextPP16ma_jack_client_t
.LVL321:
	movl	%eax, -116(%rbp)
.LVL322:
	.loc 1 19260 5 is_stmt 1 view .LVU999
	testl	%eax, %eax
	jne	.L489
	.loc 1 19266 5 view .LVU1000
	.loc 1 19266 69 is_stmt 0 view .LVU1001
	movq	(%r12), %rax
.LVL323:
	.loc 1 19266 95 view .LVU1002
	movq	3344(%r12), %rdi
	movq	%r12, %rdx
	movl	$_ZL32ma_device__jack_process_callbackjPv, %esi
	call	*456(%rax)
.LVL324:
	.loc 1 19266 5 view .LVU1003
	testl	%eax, %eax
	jne	.L490
	.loc 1 19270 5 is_stmt 1 view .LVU1004
	.loc 1 19270 73 is_stmt 0 view .LVU1005
	movq	(%r12), %rax
	.loc 1 19270 103 view .LVU1006
	movq	3344(%r12), %rdi
	movq	%r12, %rdx
	movl	$_ZL36ma_device__jack_buffer_size_callbackjPv, %esi
	call	*464(%rax)
.LVL325:
	movl	%eax, -116(%rbp)
.LVL326:
	.loc 1 19270 5 view .LVU1007
	testl	%eax, %eax
	jne	.L491
	.loc 1 19275 5 is_stmt 1 view .LVU1008
	.loc 1 19275 56 is_stmt 0 view .LVU1009
	movq	(%r12), %rax
	.loc 1 19275 73 view .LVU1010
	movq	%r12, %rdx
	movl	$_ZL33ma_device__jack_shutdown_callbackPv, %esi
	movq	3344(%r12), %rdi
	call	*472(%rax)
.LVL327:
	.loc 1 19279 5 is_stmt 1 view .LVU1011
	.loc 1 19279 81 is_stmt 0 view .LVU1012
	movq	(%r12), %rax
	.loc 1 19279 102 view .LVU1013
	movq	3344(%r12), %rdi
	call	*488(%rax)
.LVL328:
	movl	%eax, -120(%rbp)
.LVL329:
	.loc 1 19281 5 is_stmt 1 view .LVU1014
.LBB687:
	.loc 1 19281 18 is_stmt 0 view .LVU1015
	movq	-128(%rbp), %rax
.LVL330:
	.loc 1 19281 18 view .LVU1016
	movl	(%rax), %eax
	.loc 1 19281 55 view .LVU1017
	leal	-2(%rax), %edx
	.loc 1 19281 5 view .LVU1018
	cmpl	$1, %edx
	jbe	.L492
.LVL331:
.L346:
	.loc 1 19281 5 view .LVU1019
.LBE687:
	.loc 1 19332 5 is_stmt 1 view .LVU1020
.LBB771:
	andl	$-3, %eax
	.loc 1 19332 56 is_stmt 0 view .LVU1021
	cmpl	$1, %eax
	jne	.L323
.LBB772:
	.loc 1 19333 9 is_stmt 1 view .LVU1022
	.loc 1 19334 9 view .LVU1023
	.loc 1 19336 9 view .LVU1024
	.loc 1 19337 9 view .LVU1025
	.loc 1 19336 41 is_stmt 0 view .LVU1026
	movq	.LC33(%rip), %rax
	movq	%rax, 12(%r13)
	.loc 1 19338 9 is_stmt 1 view .LVU1027
	.loc 1 19338 98 is_stmt 0 view .LVU1028
	movq	(%r12), %rax
	.loc 1 19338 119 view .LVU1029
	movq	3344(%r12), %rdi
	call	*480(%rax)
.LVL332:
	.loc 1 19339 37 view .LVU1030
	movl	16(%r13), %esi
	.loc 1 19338 41 view .LVU1031
	movl	%eax, 20(%r13)
	.loc 1 19339 9 is_stmt 1 view .LVU1032
.LVL333:
.LBB773:
.LBI773:
	.loc 1 42992 13 view .LVU1033
.LBB774:
	.loc 1 42994 5 view .LVU1034
	.loc 1 42996 5 view .LVU1035
	.loc 1 42996 51 is_stmt 0 view .LVU1036
	testl	%esi, %esi
	je	.L369
.LBE774:
.LBE773:
	.loc 1 19339 89 view .LVU1037
	leaq	24(%r13), %rdi
.LVL334:
.LBB776:
.LBB775:
	.loc 1 19339 89 view .LVU1038
	call	ma_channel_map_init_standard.part.0.constprop.1
.LVL335:
.L369:
	.loc 1 19339 89 view .LVU1039
.LBE775:
.LBE776:
	.loc 1 19341 9 is_stmt 1 view .LVU1040
	.loc 1 19341 68 is_stmt 0 view .LVU1041
	movq	(%r12), %rax
	.loc 1 19341 83 view .LVU1042
	movl	$5, %ecx
	movl	$.LC16, %edx
	xorl	%esi, %esi
	movq	3344(%r12), %rdi
	call	*496(%rax)
.LVL336:
	movq	%rax, -136(%rbp)
.LVL337:
	.loc 1 19342 9 is_stmt 1 view .LVU1043
	testq	%rax, %rax
	je	.L482
	.loc 1 19348 45 is_stmt 0 view .LVU1044
	movl	16(%r13), %edx
	movq	%rax, %rsi
	.loc 1 19348 9 is_stmt 1 view .LVU1045
	.loc 1 19348 55 view .LVU1046
	cmpq	$0, (%rsi,%rdx,8)
	.loc 1 19348 45 is_stmt 0 view .LVU1047
	movq	%rdx, %rax
.LVL338:
	.loc 1 19348 53 view .LVU1048
	leaq	0(,%rdx,8), %rdi
	.loc 1 19348 55 view .LVU1049
	je	.L372
	addl	$1, %eax
	.p2align 4,,10
	.p2align 3
.L373:
	.loc 1 19349 13 is_stmt 1 view .LVU1050
	.loc 1 19348 9 view .LVU1051
	.loc 1 19348 55 view .LVU1052
	.loc 1 19348 45 is_stmt 0 view .LVU1053
	movl	%eax, %edx
	movl	%eax, %ecx
	.loc 1 19348 55 view .LVU1054
	addl	$1, %eax
	cmpq	$0, (%rsi,%rdx,8)
	.loc 1 19348 53 view .LVU1055
	leaq	0(,%rdx,8), %rdi
	.loc 1 19348 55 view .LVU1056
	jne	.L373
	movl	%ecx, 16(%r13)
.L372:
	.loc 1 19352 9 is_stmt 1 view .LVU1057
	.loc 1 19352 142 is_stmt 0 view .LVU1058
	movq	(%r12), %rax
.LVL339:
.LBB777:
.LBI777:
	.loc 1 44050 14 is_stmt 1 view .LVU1059
.LBB778:
	.loc 1 44052 5 view .LVU1060
	.loc 1 44053 9 view .LVU1061
	.loc 1 44053 35 is_stmt 0 view .LVU1062
	movq	296(%rax), %rdx
	.loc 1 44053 9 view .LVU1063
	testq	%rdx, %rdx
	je	.L493
	.loc 1 44054 13 is_stmt 1 view .LVU1064
	.loc 1 44054 50 is_stmt 0 view .LVU1065
	movq	288(%rax), %rsi
.LVL340:
	.loc 1 44054 50 view .LVU1066
	call	*%rdx
.LVL341:
	.loc 1 44054 50 view .LVU1067
.LBE778:
.LBE777:
	.loc 1 19352 39 view .LVU1068
	movq	%rax, 3352(%r12)
	.loc 1 19353 9 is_stmt 1 view .LVU1069
	testq	%rax, %rax
	je	.L494
.LVL342:
.LBB779:
	.loc 1 19358 31 view .LVU1070
	movl	16(%r13), %eax
	.loc 1 19358 20 is_stmt 0 view .LVU1071
	xorl	%r14d, %r14d
	leaq	-112(%rbp), %rbx
	.loc 1 19358 31 view .LVU1072
	testl	%eax, %eax
	je	.L391
	movq	%r13, -128(%rbp)
.LVL343:
	.p2align 4,,10
	.p2align 3
.L377:
.LBB780:
.LBB781:
.LBB782:
.LBB783:
.LBB784:
	.loc 1 934 12 view .LVU1073
	xorl	%eax, %eax
	.loc 1 934 44 view .LVU1074
	movl	$112, %edx
	jmp	.L380
.LVL344:
	.p2align 4,,10
	.p2align 3
.L473:
	.loc 1 934 44 view .LVU1075
	movzbl	.LC36(%rax), %edx
	.loc 1 934 36 view .LVU1076
	testb	%dl, %dl
	je	.L381
.LVL345:
.L380:
	.loc 1 935 16 view .LVU1077
	movb	%dl, (%rbx,%rax)
	.loc 1 934 5 view .LVU1078
	addq	$1, %rax
.LVL346:
	.loc 1 934 36 view .LVU1079
	cmpq	$64, %rax
	jne	.L473
	.loc 1 943 12 view .LVU1080
	movb	$0, -112(%rbp)
.L393:
.LVL347:
	.loc 1 943 12 view .LVU1081
.LBE784:
.LBE783:
.LBE782:
.LBE781:
	.loc 1 19361 13 is_stmt 1 view .LVU1082
	.loc 1 19361 22 is_stmt 0 view .LVU1083
	movl	$56, %edx
	leaq	-104(%rbp), %rsi
	movl	%r14d, %edi
	.loc 1 19363 43 view .LVU1084
	movl	%r14d, %r15d
	.loc 1 19361 22 view .LVU1085
	call	_Z9ma_itoa_siPcmi.constprop.0
.LVL348:
	.loc 1 19363 13 is_stmt 1 view .LVU1086
	.loc 1 19363 124 is_stmt 0 view .LVU1087
	xorl	%r8d, %r8d
	movl	$2, %ecx
	movq	%rbx, %rsi
	.loc 1 19363 48 view .LVU1088
	movq	3352(%r12), %rax
	.loc 1 19363 124 view .LVU1089
	movq	3344(%r12), %rdi
	movl	$.LC16, %edx
	.loc 1 19363 48 view .LVU1090
	leaq	(%rax,%r15,8), %r13
	.loc 1 19363 105 view .LVU1091
	movq	(%r12), %rax
	.loc 1 19363 124 view .LVU1092
	call	*528(%rax)
.LVL349:
	.loc 1 19363 50 view .LVU1093
	movq	%rax, 0(%r13)
	.loc 1 19364 13 is_stmt 1 view .LVU1094
	.loc 1 19364 52 is_stmt 0 view .LVU1095
	movq	3352(%r12), %rax
	.loc 1 19364 13 view .LVU1096
	cmpq	$0, (%rax,%r15,8)
	je	.L495
.LBE780:
	.loc 1 19358 9 is_stmt 1 view .LVU1097
	.loc 1 19358 31 is_stmt 0 view .LVU1098
	movq	-128(%rbp), %rax
	.loc 1 19358 70 view .LVU1099
	addl	$1, %r14d
.LVL350:
	.loc 1 19358 31 is_stmt 1 view .LVU1100
	cmpl	%r14d, 16(%rax)
	ja	.L377
	movq	%rax, %r13
.LVL351:
.L391:
	.loc 1 19358 31 is_stmt 0 view .LVU1101
.LBE779:
	.loc 1 19372 9 is_stmt 1 view .LVU1102
	.loc 1 19372 53 is_stmt 0 view .LVU1103
	movq	(%r12), %rax
	.loc 1 19372 63 view .LVU1104
	movq	-136(%rbp), %rdi
	call	*552(%rax)
.LVL352:
	.loc 1 19374 9 is_stmt 1 view .LVU1105
	.loc 1 19377 207 is_stmt 0 view .LVU1106
	movq	(%r12), %rcx
	.loc 1 19374 49 view .LVU1107
	movl	-120(%rbp), %esi
.LBB834:
.LBB835:
.LBB836:
.LBB837:
	.loc 1 44156 15 view .LVU1108
	movabsq	$17179869188, %rax
	movq	%rax, -96(%rbp)
	.loc 1 44164 24 view .LVU1109
	movslq	12(%r13), %rax
	.loc 1 44156 15 view .LVU1110
	movdqa	.LC22(%rip), %xmm0
.LBE837:
.LBE836:
.LBE835:
.LBE834:
	.loc 1 19374 49 view .LVU1111
	movl	%esi, 280(%r13)
	.loc 1 19375 9 is_stmt 1 view .LVU1112
	.loc 1 19375 49 is_stmt 0 view .LVU1113
	movl	$1, 288(%r13)
	.loc 1 19377 9 is_stmt 1 view .LVU1114
.LVL353:
.LBB842:
.LBI834:
	.file 2 "/home/user/Documents/_code_/Grume/source/3rd_party/miniaudio.hpp"
	.loc 2 2066 28 view .LVU1115
.LBB840:
	.loc 2 2066 91 view .LVU1116
.LBB839:
.LBI836:
	.loc 1 44154 18 view .LVU1117
.LBB838:
	.loc 1 44156 5 view .LVU1118
	.loc 1 44164 5 view .LVU1119
	.loc 1 44156 15 is_stmt 0 view .LVU1120
	movaps	%xmm0, -112(%rbp)
	.loc 1 44164 24 view .LVU1121
	movl	-112(%rbp,%rax,4), %edx
.LVL354:
	.loc 1 44164 24 view .LVU1122
.LBE838:
.LBE839:
	.loc 2 2066 132 view .LVU1123
	imull	16(%r13), %edx
.LBE840:
.LBE842:
.LBB843:
.LBB844:
.LBB845:
.LBB846:
	.loc 1 44053 35 view .LVU1124
	movq	296(%rcx), %rax
.LBE846:
.LBE845:
.LBE844:
.LBE843:
.LBB856:
.LBB841:
	.loc 2 2066 132 view .LVU1125
	movl	%edx, %r13d
.LBE841:
.LBE856:
	.loc 1 19377 70 view .LVU1126
	imull	%esi, %r13d
.LVL355:
.LBB857:
.LBI843:
	.loc 1 44063 14 is_stmt 1 view .LVU1127
.LBB853:
	.loc 1 44065 5 view .LVU1128
.LBB848:
.LBI845:
	.loc 1 44050 14 view .LVU1129
.LBB847:
	.loc 1 44052 5 view .LVU1130
	.loc 1 44053 9 view .LVU1131
	testq	%rax, %rax
	je	.L379
	.loc 1 44054 13 view .LVU1132
	.loc 1 44054 50 is_stmt 0 view .LVU1133
	movq	288(%rcx), %rsi
	movq	%r13, %rdi
	call	*%rax
.LVL356:
	.loc 1 44054 50 view .LVU1134
	movq	%rax, %rcx
.LVL357:
	.loc 1 44054 50 view .LVU1135
.LBE847:
.LBE848:
	.loc 1 44066 5 is_stmt 1 view .LVU1136
	testq	%rax, %rax
	je	.L379
	.loc 1 44067 9 view .LVU1137
.LVL358:
.LBB849:
.LBI849:
	.loc 1 776 23 view .LVU1138
.LBB850:
	.loc 1 781 5 view .LVU1139
	testq	%r13, %r13
	jne	.L496
.LVL359:
.L392:
	.loc 1 781 5 is_stmt 0 view .LVU1140
.LBE850:
.LBE849:
	.loc 1 44070 5 is_stmt 1 view .LVU1141
	.loc 1 44070 5 is_stmt 0 view .LVU1142
.LBE853:
.LBE857:
	.loc 1 19377 51 view .LVU1143
	movq	%rcx, 3368(%r12)
	.loc 1 19378 9 is_stmt 1 view .LVU1144
.LVL360:
.L323:
	.loc 1 19378 9 is_stmt 0 view .LVU1145
.LBE772:
.LBE771:
	.loc 1 19385 1 view .LVU1146
	movl	-116(%rbp), %eax
	addq	$120, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL361:
	.p2align 4,,10
	.p2align 3
.L487:
	.cfi_restore_state
	.loc 1 19245 131 discriminator 1 view .LVU1147
	movq	0(%r13), %rcx
.LVL362:
	.loc 1 19245 107 discriminator 1 view .LVU1148
	testq	%rcx, %rcx
	je	.L330
	.loc 1 19245 149 discriminator 3 view .LVU1149
	movl	(%rcx), %esi
.LVL363:
	.loc 1 19245 149 discriminator 3 view .LVU1150
	testl	%esi, %esi
	jne	.L331
.L330:
	.loc 1 19246 58 view .LVU1151
	subl	$2, %eax
	.loc 1 19245 195 view .LVU1152
	cmpl	$1, %eax
	jbe	.L497
	.loc 1 19252 107 view .LVU1153
	cmpl	$1, 8(%r13)
	jne	.L334
.L396:
	.loc 1 19254 9 is_stmt 1 view .LVU1154
.LVL364:
.LBB884:
.LBI884:
	.loc 1 29688 16 view .LVU1155
.LBE884:
	.loc 1 29690 5 view .LVU1156
	.loc 1 29681 5 view .LVU1157
	.loc 1 29685 5 view .LVU1158
.LBB887:
.LBB885:
.LBI885:
	.loc 1 28929 16 view .LVU1159
.LBB886:
	.loc 1 28931 5 view .LVU1160
	testq	%rdi, %rdi
	je	.L335
	.loc 1 28935 5 view .LVU1161
	.loc 1 28935 22 is_stmt 0 view .LVU1162
	movq	112(%rdi), %rdi
.L335:
.LVL365:
	.loc 1 28935 22 view .LVU1163
.LBE886:
.LBE885:
.LBE887:
	.loc 1 19254 20 view .LVU1164
	movl	$.LC30, %edx
	movl	$1, %esi
	call	ma_log_post
.LVL366:
	.loc 1 19255 9 is_stmt 1 view .LVU1165
	.loc 1 19255 16 is_stmt 0 view .LVU1166
	movl	$-102, -116(%rbp)
	jmp	.L323
.LVL367:
	.p2align 4,,10
	.p2align 3
.L381:
.LBB888:
.LBB872:
.LBB858:
.LBB828:
.LBB788:
.LBB787:
.LBB786:
.LBB785:
	.loc 1 939 16 view .LVU1167
	movb	$0, -112(%rbp,%rax)
	.loc 1 940 16 view .LVU1168
	jmp	.L393
.LVL368:
	.p2align 4,,10
	.p2align 3
.L489:
	.loc 1 940 16 view .LVU1169
.LBE785:
.LBE786:
.LBE787:
.LBE788:
.LBE828:
.LBE858:
.LBE872:
.LBE888:
	.loc 1 19261 9 is_stmt 1 view .LVU1170
.LBB889:
.LBI889:
	.loc 1 29688 16 view .LVU1171
.LBE889:
	.loc 1 29690 5 view .LVU1172
.LBB894:
.LBB890:
.LBI890:
	.loc 1 29679 20 view .LVU1173
.LBB891:
	.loc 1 29681 5 view .LVU1174
	.loc 1 29685 5 view .LVU1175
	.loc 1 29685 21 is_stmt 0 view .LVU1176
	movq	(%r12), %rax
.LVL369:
	.loc 1 29685 21 view .LVU1177
.LBE891:
.LBE890:
.LBB892:
.LBI892:
	.loc 1 28929 16 is_stmt 1 view .LVU1178
.LBB893:
	.loc 1 28931 5 view .LVU1179
	testq	%rax, %rax
	je	.L323
	.loc 1 28935 5 view .LVU1180
	.loc 1 28935 22 is_stmt 0 view .LVU1181
	movq	112(%rax), %r14
.LVL370:
	.loc 1 28935 22 view .LVU1182
.LBE893:
.LBE892:
.LBE894:
.LBB895:
.LBI895:
	.loc 1 2100 18 is_stmt 1 view .LVU1183
.LBB896:
	.loc 1 2102 5 view .LVU1184
	testq	%r14, %r14
	je	.L323
	.loc 1 2106 5 view .LVU1185
.LVL371:
.LBB897:
.LBI897:
	.loc 1 2031 13 view .LVU1186
.LBB898:
	.loc 1 2034 5 view .LVU1187
	.loc 1 2034 18 is_stmt 0 view .LVU1188
	leaq	104(%r14), %r13
.LVL372:
.LBB899:
.LBI899:
	.loc 1 4800 13 is_stmt 1 view .LVU1189
.LBE899:
.LBE898:
.LBE897:
.LBE896:
.LBE895:
	.loc 1 4802 5 view .LVU1190
	.loc 1 4811 5 view .LVU1191
.LBB923:
.LBB920:
.LBB908:
.LBB906:
.LBB904:
.LBB900:
.LBI900:
	.loc 1 4556 13 view .LVU1192
.LBB901:
	.loc 1 4558 5 view .LVU1193
	leaq	8(%r14), %rbx
.LBE901:
.LBE900:
.LBE904:
.LBE906:
.LBE908:
.LBB909:
	.loc 1 2109 19 is_stmt 0 view .LVU1194
	xorl	%r12d, %r12d
.LVL373:
	.loc 1 2109 19 view .LVU1195
.LBE909:
.LBB910:
.LBB907:
.LBB905:
.LBB903:
.LBB902:
	.loc 1 4558 23 view .LVU1196
	movq	%r13, %rdi
	call	pthread_mutex_lock
.LVL374:
	.loc 1 4558 23 view .LVU1197
.LBE902:
.LBE903:
.LBE905:
.LBE907:
.LBE910:
	.loc 1 2107 5 is_stmt 1 view .LVU1198
.LBB911:
	.loc 1 2108 9 view .LVU1199
	.loc 1 2109 9 view .LVU1200
	.loc 1 2109 29 view .LVU1201
	.loc 1 2109 37 is_stmt 0 view .LVU1202
	movl	64(%r14), %edx
	.loc 1 2109 29 view .LVU1203
	testl	%edx, %edx
	je	.L339
.LVL375:
.L341:
	.loc 1 2110 13 is_stmt 1 view .LVU1204
	.loc 1 2110 39 is_stmt 0 view .LVU1205
	movq	-8(%rbx), %rax
	.loc 1 2110 13 view .LVU1206
	testq	%rax, %rax
	je	.L338
	.loc 1 2111 17 is_stmt 1 view .LVU1207
	.loc 1 2111 44 is_stmt 0 view .LVU1208
	movq	(%rbx), %rdi
	movl	$.LC15, %edx
	.loc 1 2109 57 view .LVU1209
	addl	$1, %r12d
.LVL376:
	.loc 1 2109 29 view .LVU1210
	addq	$16, %rbx
	.loc 1 2111 44 view .LVU1211
	movl	$1, %esi
	call	*%rax
.LVL377:
	.loc 1 2109 37 view .LVU1212
	movl	64(%r14), %edx
	.loc 1 2109 9 is_stmt 1 view .LVU1213
.LVL378:
	.loc 1 2109 29 view .LVU1214
	cmpl	%edx, %r12d
	jb	.L341
.LVL379:
.L339:
	.loc 1 2109 29 is_stmt 0 view .LVU1215
.LBE911:
	.loc 1 2115 5 is_stmt 1 view .LVU1216
.LBB912:
.LBI912:
	.loc 1 2040 13 view .LVU1217
.LBE912:
.LBE920:
.LBE923:
	.loc 1 2043 5 view .LVU1218
.LBB924:
.LBB921:
.LBB917:
.LBB913:
.LBI913:
	.loc 1 4815 13 view .LVU1219
.LBE913:
.LBE917:
.LBE921:
.LBE924:
	.loc 1 4817 5 view .LVU1220
	.loc 1 4826 5 view .LVU1221
.LBB925:
.LBB922:
.LBB918:
.LBB916:
.LBB914:
.LBI914:
	.loc 1 4561 13 view .LVU1222
.LBB915:
	.loc 1 4563 5 view .LVU1223
	.loc 1 4563 25 is_stmt 0 view .LVU1224
	movq	%r13, %rdi
	call	pthread_mutex_unlock
.LVL380:
	.loc 1 4563 25 view .LVU1225
.LBE915:
.LBE914:
.LBE916:
.LBE918:
	.loc 1 2117 5 is_stmt 1 view .LVU1226
	.loc 1 2117 12 is_stmt 0 view .LVU1227
	jmp	.L323
.LVL381:
	.p2align 4,,10
	.p2align 3
.L338:
.LBB919:
	.loc 1 2109 9 is_stmt 1 view .LVU1228
	.loc 1 2109 57 is_stmt 0 view .LVU1229
	addl	$1, %r12d
.LVL382:
	.loc 1 2109 29 is_stmt 1 view .LVU1230
	addq	$16, %rbx
	cmpl	%r12d, %edx
	ja	.L341
	jmp	.L339
.LVL383:
	.p2align 4,,10
	.p2align 3
.L492:
	.loc 1 2109 29 is_stmt 0 view .LVU1231
.LBE919:
.LBE922:
.LBE925:
.LBB926:
.LBB688:
	.loc 1 19282 9 is_stmt 1 view .LVU1232
	.loc 1 19283 9 view .LVU1233
	.loc 1 19285 9 view .LVU1234
	.loc 1 19286 9 view .LVU1235
	.loc 1 19285 40 is_stmt 0 view .LVU1236
	movq	.LC33(%rip), %rax
	movq	%rax, 12(%r14)
	.loc 1 19287 9 is_stmt 1 view .LVU1237
	.loc 1 19287 97 is_stmt 0 view .LVU1238
	movq	(%r12), %rax
	.loc 1 19287 118 view .LVU1239
	movq	3344(%r12), %rdi
	call	*480(%rax)
.LVL384:
	.loc 1 19288 37 view .LVU1240
	movl	16(%r14), %esi
	.loc 1 19287 40 view .LVU1241
	movl	%eax, 20(%r14)
	.loc 1 19288 9 is_stmt 1 view .LVU1242
.LVL385:
.LBB689:
.LBI689:
	.loc 1 42992 13 view .LVU1243
.LBB690:
	.loc 1 42994 5 view .LVU1244
	.loc 1 42996 5 view .LVU1245
	.loc 1 42996 51 is_stmt 0 view .LVU1246
	testl	%esi, %esi
	je	.L347
.LBE690:
.LBE689:
	.loc 1 19288 88 view .LVU1247
	leaq	24(%r14), %rdi
.LVL386:
.LBB692:
.LBB691:
	.loc 1 19288 88 view .LVU1248
	call	ma_channel_map_init_standard.part.0.constprop.1
.LVL387:
.L347:
	.loc 1 19288 88 view .LVU1249
.LBE691:
.LBE692:
	.loc 1 19290 9 is_stmt 1 view .LVU1250
	.loc 1 19290 68 is_stmt 0 view .LVU1251
	movq	(%r12), %rax
	.loc 1 19290 83 view .LVU1252
	movl	$6, %ecx
	movl	$.LC16, %edx
	xorl	%esi, %esi
	movq	3344(%r12), %rdi
	call	*496(%rax)
.LVL388:
	movq	%rax, -144(%rbp)
.LVL389:
	.loc 1 19291 9 is_stmt 1 view .LVU1253
	testq	%rax, %rax
	je	.L482
	.loc 1 19297 44 is_stmt 0 view .LVU1254
	movl	16(%r14), %edx
	movq	%rax, %rsi
	.loc 1 19297 9 is_stmt 1 view .LVU1255
	.loc 1 19297 54 view .LVU1256
	cmpq	$0, (%rsi,%rdx,8)
	.loc 1 19297 44 is_stmt 0 view .LVU1257
	movq	%rdx, %rax
.LVL390:
	.loc 1 19297 52 view .LVU1258
	leaq	0(,%rdx,8), %rdi
	.loc 1 19297 54 view .LVU1259
	je	.L350
	addl	$1, %eax
	.p2align 4,,10
	.p2align 3
.L351:
	.loc 1 19298 13 is_stmt 1 view .LVU1260
	.loc 1 19297 9 view .LVU1261
	.loc 1 19297 54 view .LVU1262
	.loc 1 19297 44 is_stmt 0 view .LVU1263
	movl	%eax, %edx
	movl	%eax, %ecx
	.loc 1 19297 54 view .LVU1264
	addl	$1, %eax
	cmpq	$0, (%rsi,%rdx,8)
	.loc 1 19297 52 view .LVU1265
	leaq	0(,%rdx,8), %rdi
	.loc 1 19297 54 view .LVU1266
	jne	.L351
	movl	%ecx, 16(%r14)
.L350:
	.loc 1 19301 9 is_stmt 1 view .LVU1267
	.loc 1 19301 139 is_stmt 0 view .LVU1268
	movq	(%r12), %rdx
.LVL391:
.LBB693:
.LBI693:
	.loc 1 44050 14 is_stmt 1 view .LVU1269
.LBB694:
	.loc 1 44052 5 view .LVU1270
	.loc 1 44053 9 view .LVU1271
	.loc 1 44053 35 is_stmt 0 view .LVU1272
	movq	296(%rdx), %rax
	.loc 1 44053 9 view .LVU1273
	testq	%rax, %rax
	je	.L498
	.loc 1 44054 13 is_stmt 1 view .LVU1274
	.loc 1 44054 50 is_stmt 0 view .LVU1275
	movq	288(%rdx), %rsi
.LVL392:
	.loc 1 44054 50 view .LVU1276
	call	*%rax
.LVL393:
	.loc 1 44054 50 view .LVU1277
.LBE694:
.LBE693:
	.loc 1 19301 38 view .LVU1278
	movq	%rax, 3360(%r12)
	.loc 1 19302 9 is_stmt 1 view .LVU1279
	testq	%rax, %rax
	je	.L480
.LVL394:
.LBB695:
	.loc 1 19306 31 view .LVU1280
	movl	16(%r14), %edx
	.loc 1 19306 20 is_stmt 0 view .LVU1281
	xorl	%r15d, %r15d
	leaq	-112(%rbp), %rbx
	.loc 1 19306 31 view .LVU1282
	testl	%edx, %edx
	je	.L367
	movq	%r14, -136(%rbp)
	movq	%r13, -152(%rbp)
	movq	%r12, %r13
.LVL395:
	.loc 1 19306 31 view .LVU1283
	movl	%r15d, %r12d
.LVL396:
	.p2align 4,,10
	.p2align 3
.L353:
.LBB696:
.LBB697:
.LBB698:
.LBB699:
.LBB700:
	.loc 1 934 12 view .LVU1284
	xorl	%eax, %eax
	.loc 1 934 44 view .LVU1285
	movl	$99, %edx
	jmp	.L356
.LVL397:
	.p2align 4,,10
	.p2align 3
.L472:
	.loc 1 934 44 view .LVU1286
	movzbl	.LC34(%rax), %edx
	.loc 1 934 36 view .LVU1287
	testb	%dl, %dl
	je	.L357
.LVL398:
.L356:
	.loc 1 935 16 view .LVU1288
	movb	%dl, (%rbx,%rax)
	.loc 1 934 5 view .LVU1289
	addq	$1, %rax
.LVL399:
	.loc 1 934 36 view .LVU1290
	cmpq	$64, %rax
	jne	.L472
	.loc 1 943 12 view .LVU1291
	movb	$0, -112(%rbp)
.L394:
.LVL400:
	.loc 1 943 12 view .LVU1292
.LBE700:
.LBE699:
.LBE698:
.LBE697:
	.loc 1 19309 13 is_stmt 1 view .LVU1293
	.loc 1 19309 22 is_stmt 0 view .LVU1294
	movl	$57, %edx
	leaq	-105(%rbp), %rsi
	movl	%r12d, %edi
	.loc 1 19311 42 view .LVU1295
	movl	%r12d, %r15d
	.loc 1 19309 22 view .LVU1296
	call	_Z9ma_itoa_siPcmi.constprop.0
.LVL401:
	.loc 1 19311 13 is_stmt 1 view .LVU1297
	.loc 1 19311 123 is_stmt 0 view .LVU1298
	xorl	%r8d, %r8d
	movl	$1, %ecx
	movq	%rbx, %rsi
	.loc 1 19311 47 view .LVU1299
	movq	3360(%r13), %rax
	.loc 1 19311 123 view .LVU1300
	movq	3344(%r13), %rdi
	movl	$.LC16, %edx
	.loc 1 19311 47 view .LVU1301
	leaq	(%rax,%r15,8), %r14
	.loc 1 19311 104 view .LVU1302
	movq	0(%r13), %rax
	.loc 1 19311 123 view .LVU1303
	call	*528(%rax)
.LVL402:
	.loc 1 19311 49 view .LVU1304
	movq	%rax, (%r14)
	.loc 1 19312 13 is_stmt 1 view .LVU1305
	.loc 1 19312 51 is_stmt 0 view .LVU1306
	movq	3360(%r13), %rax
	.loc 1 19312 13 view .LVU1307
	cmpq	$0, (%rax,%r15,8)
	je	.L499
.LBE696:
	.loc 1 19306 9 is_stmt 1 view .LVU1308
	.loc 1 19306 31 is_stmt 0 view .LVU1309
	movq	-136(%rbp), %rax
	.loc 1 19306 69 view .LVU1310
	addl	$1, %r12d
.LVL403:
	.loc 1 19306 31 is_stmt 1 view .LVU1311
	cmpl	%r12d, 16(%rax)
	ja	.L353
	movq	%r13, %r12
.LVL404:
	.loc 1 19306 31 is_stmt 0 view .LVU1312
	movq	-152(%rbp), %r13
.LVL405:
	.loc 1 19306 31 view .LVU1313
	movq	%rax, %r14
.LVL406:
.L367:
	.loc 1 19306 31 view .LVU1314
.LBE695:
	.loc 1 19320 9 is_stmt 1 view .LVU1315
	.loc 1 19320 53 is_stmt 0 view .LVU1316
	movq	(%r12), %rax
	.loc 1 19320 63 view .LVU1317
	movq	-144(%rbp), %rdi
	call	*552(%rax)
.LVL407:
	.loc 1 19322 9 is_stmt 1 view .LVU1318
	.loc 1 19325 203 is_stmt 0 view .LVU1319
	movq	(%r12), %rcx
	.loc 1 19322 48 view .LVU1320
	movl	-120(%rbp), %esi
.LBB734:
.LBB735:
.LBB736:
.LBB737:
	.loc 1 44156 15 view .LVU1321
	movabsq	$17179869188, %rax
	movq	%rax, -96(%rbp)
	.loc 1 44164 24 view .LVU1322
	movslq	12(%r14), %rax
	.loc 1 44156 15 view .LVU1323
	movdqa	.LC22(%rip), %xmm0
.LBE737:
.LBE736:
.LBE735:
.LBE734:
	.loc 1 19322 48 view .LVU1324
	movl	%esi, 280(%r14)
	.loc 1 19323 9 is_stmt 1 view .LVU1325
	.loc 1 19323 48 is_stmt 0 view .LVU1326
	movl	$1, 288(%r14)
	.loc 1 19325 9 is_stmt 1 view .LVU1327
.LVL408:
.LBB742:
.LBI734:
	.loc 2 2066 28 view .LVU1328
.LBB740:
	.loc 2 2066 91 view .LVU1329
.LBB739:
.LBI736:
	.loc 1 44154 18 view .LVU1330
.LBB738:
	.loc 1 44156 5 view .LVU1331
	.loc 1 44164 5 view .LVU1332
	.loc 1 44156 15 is_stmt 0 view .LVU1333
	movaps	%xmm0, -112(%rbp)
	.loc 1 44164 24 view .LVU1334
	movl	-112(%rbp,%rax,4), %edx
.LVL409:
	.loc 1 44164 24 view .LVU1335
.LBE738:
.LBE739:
	.loc 2 2066 132 view .LVU1336
	imull	16(%r14), %edx
.LBE740:
.LBE742:
.LBB743:
.LBB744:
.LBB745:
.LBB746:
	.loc 1 44053 35 view .LVU1337
	movq	296(%rcx), %rax
.LBE746:
.LBE745:
.LBE744:
.LBE743:
.LBB756:
.LBB741:
	.loc 2 2066 132 view .LVU1338
	movl	%edx, %r14d
.LBE741:
.LBE756:
	.loc 1 19325 69 view .LVU1339
	imull	%esi, %r14d
.LVL410:
.LBB757:
.LBI743:
	.loc 1 44063 14 is_stmt 1 view .LVU1340
.LBB753:
	.loc 1 44065 5 view .LVU1341
.LBB748:
.LBI745:
	.loc 1 44050 14 view .LVU1342
.LBB747:
	.loc 1 44052 5 view .LVU1343
	.loc 1 44053 9 view .LVU1344
	testq	%rax, %rax
	je	.L355
	.loc 1 44054 13 view .LVU1345
	.loc 1 44054 50 is_stmt 0 view .LVU1346
	movq	288(%rcx), %rsi
	movq	%r14, %rdi
	call	*%rax
.LVL411:
	.loc 1 44054 50 view .LVU1347
	movq	%rax, %rcx
.LVL412:
	.loc 1 44054 50 view .LVU1348
.LBE747:
.LBE748:
	.loc 1 44066 5 is_stmt 1 view .LVU1349
	testq	%rax, %rax
	je	.L355
	.loc 1 44067 9 view .LVU1350
.LVL413:
.LBB749:
.LBI749:
	.loc 1 776 23 view .LVU1351
.LBB750:
	.loc 1 781 5 view .LVU1352
	testq	%r14, %r14
	jne	.L500
.LVL414:
.L368:
	.loc 1 781 5 is_stmt 0 view .LVU1353
.LBE750:
.LBE749:
	.loc 1 44070 5 is_stmt 1 view .LVU1354
	.loc 1 44070 5 is_stmt 0 view .LVU1355
.LBE753:
.LBE757:
.LBE688:
.LBE926:
.LBB927:
	.loc 1 19332 18 view .LVU1356
	movq	-128(%rbp), %rax
.LBE927:
.LBB928:
.LBB764:
	.loc 1 19325 50 view .LVU1357
	movq	%rcx, 3376(%r12)
	.loc 1 19326 9 is_stmt 1 view .LVU1358
.LBE764:
.LBE928:
.LBB929:
	.loc 1 19332 18 is_stmt 0 view .LVU1359
	movl	(%rax), %eax
	jmp	.L346
.LVL415:
	.p2align 4,,10
	.p2align 3
.L357:
	.loc 1 19332 18 view .LVU1360
.LBE929:
.LBB930:
.LBB765:
.LBB758:
.LBB730:
.LBB704:
.LBB703:
.LBB702:
.LBB701:
	.loc 1 939 16 view .LVU1361
	movb	$0, -112(%rbp,%rax)
	.loc 1 940 16 view .LVU1362
	jmp	.L394
.LVL416:
.L488:
	.loc 1 940 16 view .LVU1363
.LBE701:
.LBE702:
.LBE703:
.LBE704:
.LBE730:
.LBE758:
.LBE765:
.LBE930:
	.loc 1 19246 130 view .LVU1364
	movq	(%rcx), %rax
	.loc 1 19246 107 view .LVU1365
	testq	%rax, %rax
	je	.L395
.LVL417:
.L398:
	.loc 1 19246 149 discriminator 1 view .LVU1366
	movl	(%rax), %ecx
	testl	%ecx, %ecx
	jne	.L331
	.loc 1 19252 5 is_stmt 1 view .LVU1367
	cmpl	$1, %edx
	jne	.L395
.L399:
	.loc 1 19252 107 is_stmt 0 view .LVU1368
	cmpl	$1, 8(%r13)
	je	.L396
.L395:
	.loc 1 19253 107 view .LVU1369
	cmpl	$1, 8(%r14)
	jne	.L334
	jmp	.L396
	.p2align 4,,10
	.p2align 3
.L497:
	.loc 1 19246 130 view .LVU1370
	movq	(%r14), %rax
	.loc 1 19246 107 view .LVU1371
	testq	%rax, %rax
	jne	.L398
	jmp	.L399
.LVL418:
.L495:
.LBB931:
.LBB873:
.LBB859:
.LBB829:
	.loc 1 19365 17 is_stmt 1 view .LVU1372
	.loc 1 19365 61 is_stmt 0 view .LVU1373
	movq	(%r12), %rax
	.loc 1 19365 71 view .LVU1374
	movq	-136(%rbp), %rdi
	call	*552(%rax)
.LVL419:
	.loc 1 19366 17 is_stmt 1 view .LVU1375
	.loc 1 19366 39 is_stmt 0 view .LVU1376
	movq	%r12, %rdi
	call	_ZL22ma_device_uninit__jackP9ma_device
.LVL420:
	.loc 1 19367 17 is_stmt 1 view .LVU1377
.LBB789:
.LBI789:
	.loc 1 29688 16 view .LVU1378
.LBE789:
.LBE829:
.LBE859:
.LBE873:
.LBE931:
	.loc 1 29690 5 view .LVU1379
.LBB932:
.LBB874:
.LBB860:
.LBB830:
.LBB794:
.LBB790:
.LBI790:
	.loc 1 29679 20 view .LVU1380
.LBB791:
	.loc 1 29681 5 view .LVU1381
	.loc 1 29685 5 view .LVU1382
	.loc 1 29685 21 is_stmt 0 view .LVU1383
	movq	(%r12), %rax
.LVL421:
	.loc 1 29685 21 view .LVU1384
.LBE791:
.LBE790:
.LBB792:
.LBI792:
	.loc 1 28929 16 is_stmt 1 view .LVU1385
.LBB793:
	.loc 1 28931 5 view .LVU1386
	testq	%rax, %rax
	je	.L385
	.loc 1 28935 5 view .LVU1387
	.loc 1 28935 22 is_stmt 0 view .LVU1388
	movq	112(%rax), %r13
.LVL422:
	.loc 1 28935 22 view .LVU1389
.LBE793:
.LBE792:
.LBE794:
.LBB795:
.LBI795:
	.loc 1 2100 18 is_stmt 1 view .LVU1390
.LBB796:
	.loc 1 2102 5 view .LVU1391
	testq	%r13, %r13
	je	.L385
	.loc 1 2106 5 view .LVU1392
.LVL423:
.LBB797:
.LBI797:
	.loc 1 2031 13 view .LVU1393
.LBB798:
	.loc 1 2034 5 view .LVU1394
	.loc 1 2034 18 is_stmt 0 view .LVU1395
	leaq	104(%r13), %r14
.LVL424:
.LBB799:
.LBI799:
	.loc 1 4800 13 is_stmt 1 view .LVU1396
.LBE799:
.LBE798:
.LBE797:
.LBE796:
.LBE795:
.LBE830:
.LBE860:
.LBE874:
.LBE932:
	.loc 1 4802 5 view .LVU1397
	.loc 1 4811 5 view .LVU1398
.LBB933:
.LBB875:
.LBB861:
.LBB831:
.LBB824:
.LBB820:
.LBB808:
.LBB806:
.LBB804:
.LBB800:
.LBI800:
	.loc 1 4556 13 view .LVU1399
.LBB801:
	.loc 1 4558 5 view .LVU1400
	leaq	8(%r13), %rbx
.LBE801:
.LBE800:
.LBE804:
.LBE806:
.LBE808:
.LBB809:
	.loc 1 2109 19 is_stmt 0 view .LVU1401
	xorl	%r12d, %r12d
.LVL425:
	.loc 1 2109 19 view .LVU1402
.LBE809:
.LBB810:
.LBB807:
.LBB805:
.LBB803:
.LBB802:
	.loc 1 4558 23 view .LVU1403
	movq	%r14, %rdi
	call	pthread_mutex_lock
.LVL426:
	.loc 1 4558 23 view .LVU1404
.LBE802:
.LBE803:
.LBE805:
.LBE807:
.LBE810:
	.loc 1 2107 5 is_stmt 1 view .LVU1405
.LBB811:
	.loc 1 2108 9 view .LVU1406
	.loc 1 2109 9 view .LVU1407
	.loc 1 2109 29 view .LVU1408
	.loc 1 2109 37 is_stmt 0 view .LVU1409
	movl	64(%r13), %edx
	.loc 1 2109 29 view .LVU1410
	testl	%edx, %edx
	je	.L388
.LVL427:
.L390:
	.loc 1 2110 13 is_stmt 1 view .LVU1411
	.loc 1 2110 39 is_stmt 0 view .LVU1412
	movq	-8(%rbx), %rax
	.loc 1 2110 13 view .LVU1413
	testq	%rax, %rax
	je	.L387
	.loc 1 2111 17 is_stmt 1 view .LVU1414
	.loc 1 2111 44 is_stmt 0 view .LVU1415
	movq	(%rbx), %rdi
	movl	$.LC35, %edx
	.loc 1 2109 57 view .LVU1416
	addl	$1, %r12d
.LVL428:
	.loc 1 2109 29 view .LVU1417
	addq	$16, %rbx
	.loc 1 2111 44 view .LVU1418
	movl	$1, %esi
	call	*%rax
.LVL429:
	.loc 1 2109 37 view .LVU1419
	movl	64(%r13), %edx
	.loc 1 2109 9 is_stmt 1 view .LVU1420
.LVL430:
	.loc 1 2109 29 view .LVU1421
	cmpl	%edx, %r12d
	jb	.L390
.LVL431:
.L388:
	.loc 1 2109 29 is_stmt 0 view .LVU1422
.LBE811:
	.loc 1 2115 5 is_stmt 1 view .LVU1423
.LBB812:
.LBI812:
	.loc 1 2040 13 view .LVU1424
.LBE812:
.LBE820:
.LBE824:
.LBE831:
.LBE861:
.LBE875:
.LBE933:
	.loc 1 2043 5 view .LVU1425
.LBB934:
.LBB876:
.LBB862:
.LBB832:
.LBB825:
.LBB821:
.LBB817:
.LBB813:
.LBI813:
	.loc 1 4815 13 view .LVU1426
.LBE813:
.LBE817:
.LBE821:
.LBE825:
.LBE832:
.LBE862:
.LBE876:
.LBE934:
	.loc 1 4817 5 view .LVU1427
	.loc 1 4826 5 view .LVU1428
.LBB935:
.LBB877:
.LBB863:
.LBB833:
.LBB826:
.LBB822:
.LBB818:
.LBB816:
.LBB814:
.LBI814:
	.loc 1 4561 13 view .LVU1429
.LBB815:
	.loc 1 4563 5 view .LVU1430
	.loc 1 4563 25 is_stmt 0 view .LVU1431
	movq	%r14, %rdi
	call	pthread_mutex_unlock
.LVL432:
	.loc 1 4563 25 view .LVU1432
.LBE815:
.LBE814:
.LBE816:
.LBE818:
	.loc 1 2117 5 is_stmt 1 view .LVU1433
.L385:
.LBE822:
.LBE826:
	.loc 1 19368 17 view .LVU1434
	.loc 1 19368 24 is_stmt 0 view .LVU1435
	movl	$-301, -116(%rbp)
	jmp	.L323
.LVL433:
.L387:
.LBB827:
.LBB823:
.LBB819:
	.loc 1 2109 9 is_stmt 1 view .LVU1436
	.loc 1 2109 57 is_stmt 0 view .LVU1437
	addl	$1, %r12d
.LVL434:
	.loc 1 2109 29 is_stmt 1 view .LVU1438
	addq	$16, %rbx
	cmpl	%r12d, %edx
	ja	.L390
	jmp	.L388
.LVL435:
.L499:
	.loc 1 2109 29 is_stmt 0 view .LVU1439
.LBE819:
.LBE823:
.LBE827:
.LBE833:
.LBE863:
.LBE877:
.LBE935:
.LBB936:
.LBB766:
.LBB759:
.LBB731:
	.loc 1 19313 17 is_stmt 1 view .LVU1440
	.loc 1 19313 61 is_stmt 0 view .LVU1441
	movq	0(%r13), %rax
	.loc 1 19313 71 view .LVU1442
	movq	-144(%rbp), %rdi
	call	*552(%rax)
.LVL436:
	.loc 1 19314 17 is_stmt 1 view .LVU1443
	.loc 1 19314 39 is_stmt 0 view .LVU1444
	movq	%r13, %rdi
	call	_ZL22ma_device_uninit__jackP9ma_device
.LVL437:
	.loc 1 19315 17 is_stmt 1 view .LVU1445
.LBB705:
.LBI705:
	.loc 1 29688 16 view .LVU1446
.LBE705:
.LBE731:
.LBE759:
.LBE766:
.LBE936:
	.loc 1 29690 5 view .LVU1447
.LBB937:
.LBB767:
.LBB760:
.LBB732:
.LBB710:
.LBB706:
.LBI706:
	.loc 1 29679 20 view .LVU1448
.LBB707:
	.loc 1 29681 5 view .LVU1449
	.loc 1 29685 5 view .LVU1450
	.loc 1 29685 21 is_stmt 0 view .LVU1451
	movq	0(%r13), %rax
.LVL438:
	.loc 1 29685 21 view .LVU1452
.LBE707:
.LBE706:
.LBB708:
.LBI708:
	.loc 1 28929 16 is_stmt 1 view .LVU1453
.LBB709:
	.loc 1 28931 5 view .LVU1454
	testq	%rax, %rax
	je	.L385
	.loc 1 28935 5 view .LVU1455
	.loc 1 28935 22 is_stmt 0 view .LVU1456
	movq	112(%rax), %r13
.LVL439:
	.loc 1 28935 22 view .LVU1457
.LBE709:
.LBE708:
.LBE710:
.LBB711:
.LBI711:
	.loc 1 2100 18 is_stmt 1 view .LVU1458
.LBB712:
	.loc 1 2102 5 view .LVU1459
	testq	%r13, %r13
	je	.L385
	.loc 1 2106 5 view .LVU1460
.LVL440:
.LBB713:
.LBI713:
	.loc 1 2031 13 view .LVU1461
.LBB714:
	.loc 1 2034 5 view .LVU1462
	.loc 1 2034 18 is_stmt 0 view .LVU1463
	leaq	104(%r13), %r14
.LVL441:
.LBB715:
.LBI715:
	.loc 1 4800 13 is_stmt 1 view .LVU1464
.LBE715:
.LBE714:
.LBE713:
.LBE712:
.LBE711:
.LBE732:
.LBE760:
.LBE767:
.LBE937:
	.loc 1 4802 5 view .LVU1465
	.loc 1 4811 5 view .LVU1466
.LBB938:
.LBB768:
.LBB761:
.LBB733:
.LBB729:
.LBB728:
.LBB724:
.LBB722:
.LBB720:
.LBB716:
.LBI716:
	.loc 1 4556 13 view .LVU1467
.LBB717:
	.loc 1 4558 5 view .LVU1468
	leaq	8(%r13), %rbx
.LBE717:
.LBE716:
.LBE720:
.LBE722:
.LBE724:
.LBB725:
	.loc 1 2109 19 is_stmt 0 view .LVU1469
	xorl	%r12d, %r12d
.LVL442:
	.loc 1 2109 19 view .LVU1470
.LBE725:
.LBB726:
.LBB723:
.LBB721:
.LBB719:
.LBB718:
	.loc 1 4558 23 view .LVU1471
	movq	%r14, %rdi
	call	pthread_mutex_lock
.LVL443:
	.loc 1 4558 23 view .LVU1472
.LBE718:
.LBE719:
.LBE721:
.LBE723:
.LBE726:
	.loc 1 2107 5 is_stmt 1 view .LVU1473
.LBB727:
	.loc 1 2108 9 view .LVU1474
	.loc 1 2109 9 view .LVU1475
	.loc 1 2109 29 view .LVU1476
	.loc 1 2109 37 is_stmt 0 view .LVU1477
	movl	64(%r13), %edx
	.loc 1 2109 29 view .LVU1478
	testl	%edx, %edx
	je	.L388
.LVL444:
.L366:
	.loc 1 2110 13 is_stmt 1 view .LVU1479
	.loc 1 2110 39 is_stmt 0 view .LVU1480
	movq	-8(%rbx), %rax
	.loc 1 2110 13 view .LVU1481
	testq	%rax, %rax
	je	.L363
.L501:
	.loc 1 2111 17 is_stmt 1 view .LVU1482
	.loc 1 2111 44 is_stmt 0 view .LVU1483
	movq	(%rbx), %rdi
	movl	$.LC35, %edx
	.loc 1 2109 57 view .LVU1484
	addl	$1, %r12d
.LVL445:
	.loc 1 2109 29 view .LVU1485
	addq	$16, %rbx
	.loc 1 2111 44 view .LVU1486
	movl	$1, %esi
	call	*%rax
.LVL446:
	.loc 1 2109 37 view .LVU1487
	movl	64(%r13), %edx
	.loc 1 2109 9 is_stmt 1 view .LVU1488
.LVL447:
	.loc 1 2109 29 view .LVU1489
	cmpl	%r12d, %edx
	jbe	.L388
	.loc 1 2110 13 view .LVU1490
	.loc 1 2110 39 is_stmt 0 view .LVU1491
	movq	-8(%rbx), %rax
	.loc 1 2110 13 view .LVU1492
	testq	%rax, %rax
	jne	.L501
.L363:
	.loc 1 2109 9 is_stmt 1 view .LVU1493
	.loc 1 2109 57 is_stmt 0 view .LVU1494
	addl	$1, %r12d
.LVL448:
	.loc 1 2109 29 is_stmt 1 view .LVU1495
	addq	$16, %rbx
	cmpl	%edx, %r12d
	jb	.L366
	jmp	.L388
.LVL449:
.L379:
	.loc 1 2109 29 is_stmt 0 view .LVU1496
.LBE727:
.LBE728:
.LBE729:
.LBE733:
.LBE761:
.LBE768:
.LBE938:
.LBB939:
.LBB878:
.LBB864:
.LBB854:
	.loc 1 44070 5 is_stmt 1 view .LVU1497
	.loc 1 44070 5 is_stmt 0 view .LVU1498
.LBE854:
.LBE864:
	.loc 1 19377 51 view .LVU1499
	movq	$0, 3368(%r12)
	.loc 1 19378 9 is_stmt 1 view .LVU1500
	.loc 1 19379 13 view .LVU1501
	.loc 1 19379 35 is_stmt 0 view .LVU1502
	movq	%r12, %rdi
	call	_ZL22ma_device_uninit__jackP9ma_device
.LVL450:
	.loc 1 19380 13 is_stmt 1 view .LVU1503
	.loc 1 19380 20 is_stmt 0 view .LVU1504
	movl	$-4, -116(%rbp)
	jmp	.L323
.LVL451:
.L355:
	.loc 1 19380 20 view .LVU1505
.LBE878:
.LBE939:
.LBB940:
.LBB769:
.LBB762:
.LBB754:
	.loc 1 44070 5 is_stmt 1 view .LVU1506
	.loc 1 44070 5 is_stmt 0 view .LVU1507
.LBE754:
.LBE762:
	.loc 1 19325 50 view .LVU1508
	movq	$0, 3376(%r12)
	.loc 1 19326 9 is_stmt 1 view .LVU1509
	.loc 1 19327 13 view .LVU1510
	.loc 1 19327 35 is_stmt 0 view .LVU1511
	movq	%r12, %rdi
	call	_ZL22ma_device_uninit__jackP9ma_device
.LVL452:
.L480:
	.loc 1 19328 13 is_stmt 1 view .LVU1512
	.loc 1 19328 20 is_stmt 0 view .LVU1513
	movl	$-4, -116(%rbp)
	jmp	.L323
.LVL453:
.L496:
	.loc 1 19328 20 view .LVU1514
.LBE769:
.LBE940:
.LBB941:
.LBB879:
.LBB865:
.LBB855:
.LBB852:
.LBB851:
	.loc 1 782 9 is_stmt 1 view .LVU1515
	.loc 1 782 15 is_stmt 0 view .LVU1516
	movq	%r13, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	call	memset
.LVL454:
	.loc 1 782 15 view .LVU1517
	movq	%rax, %rcx
	jmp	.L392
.LVL455:
.L500:
	.loc 1 782 15 view .LVU1518
.LBE851:
.LBE852:
.LBE855:
.LBE865:
.LBE879:
.LBE941:
.LBB942:
.LBB770:
.LBB763:
.LBB755:
.LBB752:
.LBB751:
	.loc 1 782 9 is_stmt 1 view .LVU1519
	.loc 1 782 15 is_stmt 0 view .LVU1520
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	call	memset
.LVL456:
	.loc 1 782 15 view .LVU1521
	movq	%rax, %rcx
	jmp	.L368
.LVL457:
.L498:
	.loc 1 782 15 view .LVU1522
.LBE751:
.LBE752:
.LBE755:
.LBE763:
	.loc 1 19301 38 view .LVU1523
	movq	$0, 3360(%r12)
	.loc 1 19302 9 is_stmt 1 view .LVU1524
	.loc 1 19303 20 is_stmt 0 view .LVU1525
	movl	$-4, -116(%rbp)
	jmp	.L323
.LVL458:
.L493:
	.loc 1 19303 20 view .LVU1526
.LBE770:
.LBE942:
.LBB943:
.LBB880:
	.loc 1 19352 39 view .LVU1527
	movq	$0, 3352(%r12)
	.loc 1 19353 9 is_stmt 1 view .LVU1528
.LVL459:
.L375:
	.loc 1 19354 13 view .LVU1529
	.loc 1 19354 20 is_stmt 0 view .LVU1530
	movq	3360(%r12), %rdi
	.loc 1 19354 51 view .LVU1531
	leaq	288(%rax), %rsi
	.loc 1 19354 20 view .LVU1532
	call	ma_free
.LVL460:
	.loc 1 19355 13 is_stmt 1 view .LVU1533
	.loc 1 19355 20 is_stmt 0 view .LVU1534
	movl	$-4, -116(%rbp)
	jmp	.L323
.LVL461:
	.p2align 4,,10
	.p2align 3
.L491:
	.loc 1 19355 20 view .LVU1535
.LBE880:
.LBE943:
	.loc 1 19271 9 is_stmt 1 view .LVU1536
.LBB944:
.LBI944:
	.loc 1 29688 16 view .LVU1537
.LBE944:
	.loc 1 29690 5 view .LVU1538
.LBB949:
.LBB945:
.LBI945:
	.loc 1 29679 20 view .LVU1539
.LBB946:
	.loc 1 29681 5 view .LVU1540
	.loc 1 29685 5 view .LVU1541
	.loc 1 29685 21 is_stmt 0 view .LVU1542
	movq	(%r12), %rdi
.LVL462:
	.loc 1 29685 21 view .LVU1543
.LBE946:
.LBE945:
.LBB947:
.LBI947:
	.loc 1 28929 16 is_stmt 1 view .LVU1544
.LBB948:
	.loc 1 28931 5 view .LVU1545
	testq	%rdi, %rdi
	je	.L345
	.loc 1 28935 5 view .LVU1546
	.loc 1 28935 22 is_stmt 0 view .LVU1547
	movq	112(%rdi), %rdi
.LVL463:
.L345:
	.loc 1 28935 22 view .LVU1548
.LBE948:
.LBE947:
.LBE949:
	.loc 1 19271 20 view .LVU1549
	movl	$.LC32, %edx
	movl	$1, %esi
	call	ma_log_post
.LVL464:
	.loc 1 19272 9 is_stmt 1 view .LVU1550
	.loc 1 19272 16 is_stmt 0 view .LVU1551
	movl	$-301, -116(%rbp)
	jmp	.L323
.LVL465:
.L490:
	.loc 1 19267 9 is_stmt 1 view .LVU1552
.LBB950:
.LBI950:
	.loc 1 29688 16 view .LVU1553
.LBE950:
	.loc 1 29690 5 view .LVU1554
.LBB955:
.LBB951:
.LBI951:
	.loc 1 29679 20 view .LVU1555
.LBB952:
	.loc 1 29681 5 view .LVU1556
	.loc 1 29685 5 view .LVU1557
	.loc 1 29685 21 is_stmt 0 view .LVU1558
	movq	(%r12), %rdi
.LVL466:
	.loc 1 29685 21 view .LVU1559
.LBE952:
.LBE951:
.LBB953:
.LBI953:
	.loc 1 28929 16 is_stmt 1 view .LVU1560
.LBB954:
	.loc 1 28931 5 view .LVU1561
	testq	%rdi, %rdi
	je	.L343
	.loc 1 28935 5 view .LVU1562
	.loc 1 28935 22 is_stmt 0 view .LVU1563
	movq	112(%rdi), %rdi
.LVL467:
.L343:
	.loc 1 28935 22 view .LVU1564
.LBE954:
.LBE953:
.LBE955:
	.loc 1 19267 20 view .LVU1565
	movl	$.LC31, %edx
	movl	$1, %esi
	call	ma_log_post
.LVL468:
	.loc 1 19268 9 is_stmt 1 view .LVU1566
	.loc 1 19268 16 is_stmt 0 view .LVU1567
	movl	$-301, -116(%rbp)
.LVL469:
	.loc 1 19268 16 view .LVU1568
	jmp	.L323
.L331:
	.loc 1 19247 9 is_stmt 1 view .LVU1569
.LVL470:
.LBB956:
.LBI956:
	.loc 1 29688 16 view .LVU1570
.LBE956:
	.loc 1 29690 5 view .LVU1571
	.loc 1 29681 5 view .LVU1572
	.loc 1 29685 5 view .LVU1573
.LBB959:
.LBB957:
.LBI957:
	.loc 1 28929 16 view .LVU1574
.LBB958:
	.loc 1 28931 5 view .LVU1575
	testq	%rdi, %rdi
	je	.L333
	.loc 1 28935 5 view .LVU1576
	.loc 1 28935 22 is_stmt 0 view .LVU1577
	movq	112(%rdi), %rdi
.L333:
.LVL471:
	.loc 1 28935 22 view .LVU1578
.LBE958:
.LBE957:
.LBE959:
	.loc 1 19247 20 view .LVU1579
	movl	$.LC29, %edx
	movl	$1, %esi
	call	ma_log_post
.LVL472:
	.loc 1 19248 9 is_stmt 1 view .LVU1580
	.loc 1 19248 16 is_stmt 0 view .LVU1581
	movl	$-104, -116(%rbp)
	jmp	.L323
.LVL473:
.L486:
	.loc 1 19240 9 is_stmt 1 view .LVU1582
.LBB960:
.LBI680:
	.loc 1 29688 16 view .LVU1583
.LBE960:
	.loc 1 29690 5 view .LVU1584
.LBB961:
.LBB684:
.LBI681:
	.loc 1 29679 20 view .LVU1585
.LBB683:
	.loc 1 29681 5 view .LVU1586
	.loc 1 29685 5 view .LVU1587
	.loc 1 29685 5 is_stmt 0 view .LVU1588
.LBE683:
.LBE684:
.LBB685:
.LBI685:
	.loc 1 28929 16 is_stmt 1 view .LVU1589
.LBB686:
	.loc 1 28931 5 view .LVU1590
	testq	%rdi, %rdi
	je	.L327
	.loc 1 28935 5 view .LVU1591
	.loc 1 28935 22 is_stmt 0 view .LVU1592
	movq	112(%rdi), %rdi
.L327:
.LVL474:
	.loc 1 28935 22 view .LVU1593
.LBE686:
.LBE685:
.LBE961:
	.loc 1 19240 20 view .LVU1594
	movl	$.LC28, %edx
.LVL475:
	.loc 1 19240 20 view .LVU1595
	movl	$1, %esi
.LVL476:
	.loc 1 19240 20 view .LVU1596
	call	ma_log_post
.LVL477:
	.loc 1 19241 9 is_stmt 1 view .LVU1597
	.loc 1 19241 16 is_stmt 0 view .LVU1598
	movl	$-101, -116(%rbp)
	jmp	.L323
.LVL478:
.L482:
.LBB962:
.LBB881:
	.loc 1 19343 13 is_stmt 1 view .LVU1599
.LBB866:
.LBI866:
	.loc 1 29688 16 view .LVU1600
.LBE866:
.LBE881:
.LBE962:
	.loc 1 29690 5 view .LVU1601
.LBB963:
.LBB882:
.LBB871:
.LBB867:
.LBI867:
	.loc 1 29679 20 view .LVU1602
.LBB868:
	.loc 1 29681 5 view .LVU1603
	.loc 1 29685 5 view .LVU1604
	.loc 1 29685 21 is_stmt 0 view .LVU1605
	movq	(%r12), %rdi
.LVL479:
	.loc 1 29685 21 view .LVU1606
.LBE868:
.LBE867:
.LBB869:
.LBI869:
	.loc 1 28929 16 is_stmt 1 view .LVU1607
.LBB870:
	.loc 1 28931 5 view .LVU1608
	testq	%rdi, %rdi
	je	.L371
	.loc 1 28935 5 view .LVU1609
	.loc 1 28935 22 is_stmt 0 view .LVU1610
	movq	112(%rdi), %rdi
.LVL480:
.L371:
	.loc 1 28935 22 view .LVU1611
.LBE870:
.LBE869:
.LBE871:
	.loc 1 19343 24 view .LVU1612
	movl	$.LC17, %edx
	movl	$1, %esi
	call	ma_log_post
.LVL481:
	.loc 1 19344 13 is_stmt 1 view .LVU1613
	.loc 1 19344 20 is_stmt 0 view .LVU1614
	movl	$-301, -116(%rbp)
	jmp	.L323
.LVL482:
.L485:
	.loc 1 19344 20 view .LVU1615
.LBE882:
.LBE963:
	.loc 1 19237 5 discriminator 1 view .LVU1616
	movl	$.LC26, %ecx
.LVL483:
	.loc 1 19237 5 discriminator 1 view .LVU1617
	movl	$19237, %edx
.LVL484:
	.loc 1 19237 5 discriminator 1 view .LVU1618
	movl	$.LC8, %esi
.LVL485:
	.loc 1 19237 5 discriminator 1 view .LVU1619
	movl	$.LC19, %edi
.LVL486:
	.loc 1 19237 5 discriminator 1 view .LVU1620
	call	__assert_fail
.LVL487:
.L484:
	.loc 1 19236 5 discriminator 1 view .LVU1621
	movl	$.LC26, %ecx
.LVL488:
	.loc 1 19236 5 discriminator 1 view .LVU1622
	movl	$19236, %edx
.LVL489:
	.loc 1 19236 5 discriminator 1 view .LVU1623
	movl	$.LC8, %esi
.LVL490:
	.loc 1 19236 5 discriminator 1 view .LVU1624
	movl	$.LC27, %edi
.LVL491:
	.loc 1 19236 5 discriminator 1 view .LVU1625
	call	__assert_fail
.LVL492:
.L494:
.LBB964:
.LBB883:
	.loc 1 19354 61 view .LVU1626
	movq	(%r12), %rax
	jmp	.L375
.LBE883:
.LBE964:
	.cfi_endproc
.LFE89:
	.size	_ZL20ma_device_init__jackP9ma_devicePK16ma_device_configP20ma_device_descriptorS5_, .-_ZL20ma_device_init__jackP9ma_devicePK16ma_device_configP20ma_device_descriptorS5_
	.section	.rodata.str1.8
	.align 8
.LC37:
	.string	"[JACK] Failed to activate the JACK client."
	.align 8
.LC38:
	.string	"[JACK] Failed to retrieve physical ports."
	.align 8
.LC39:
	.string	"[JACK] Failed to connect ports."
	.text
	.p2align 4
	.type	_ZL21ma_device_start__jackP9ma_device, @function
_ZL21ma_device_start__jackP9ma_device:
.LVL493:
.LFB91:
	.loc 1 19389 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 19389 1 is_stmt 0 view .LVU1628
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
1:	call	mcount
	.loc 1 19389 1 view .LVU1629
	.loc 1 19390 5 is_stmt 1 view .LVU1630
	.loc 1 19390 17 is_stmt 0 view .LVU1631
	movq	(%rdi), %r12
.LVL494:
	.loc 1 19391 5 is_stmt 1 view .LVU1632
	.loc 1 19392 5 view .LVU1633
	.loc 1 19394 5 view .LVU1634
	.loc 1 19389 1 is_stmt 0 view .LVU1635
	movq	%rdi, %rbx
	.loc 1 19394 71 view .LVU1636
	movq	3344(%rdi), %rdi
.LVL495:
	.loc 1 19394 71 view .LVU1637
	call	*504(%r12)
.LVL496:
	movl	%eax, -52(%rbp)
.LVL497:
	.loc 1 19395 5 is_stmt 1 view .LVU1638
	testl	%eax, %eax
	jne	.L563
	.loc 1 19400 5 view .LVU1639
.LBB1022:
	.loc 1 19400 18 is_stmt 0 view .LVU1640
	movl	8(%rbx), %eax
.LVL498:
	.loc 1 19400 49 view .LVU1641
	leal	-2(%rax), %edx
	.loc 1 19400 5 view .LVU1642
	cmpl	$1, %edx
	jbe	.L564
.LVL499:
.L506:
	.loc 1 19400 5 view .LVU1643
.LBE1022:
	.loc 1 19424 5 is_stmt 1 view .LVU1644
.LBB1058:
	andl	$-3, %eax
	.loc 1 19424 50 is_stmt 0 view .LVU1645
	cmpl	$1, %eax
	jne	.L502
.LBB1059:
	.loc 1 19425 9 is_stmt 1 view .LVU1646
	.loc 1 19425 93 is_stmt 0 view .LVU1647
	movq	3344(%rbx), %rdi
	movl	$5, %ecx
	movl	$.LC16, %edx
	xorl	%esi, %esi
	call	*496(%r12)
.LVL500:
	movq	%rax, %r13
.LVL501:
	.loc 1 19426 9 is_stmt 1 view .LVU1648
	testq	%rax, %rax
	je	.L561
.LVL502:
.LBB1060:
	.loc 1 19432 38 view .LVU1649
	.loc 1 19432 36 is_stmt 0 view .LVU1650
	movq	(%rax), %r14
	xorl	%r15d, %r15d
	.loc 1 19432 38 view .LVU1651
	testq	%r14, %r14
	jne	.L521
	jmp	.L528
.LVL503:
	.p2align 4,,10
	.p2align 3
.L522:
	.loc 1 19432 9 is_stmt 1 discriminator 2 view .LVU1652
	.loc 1 19432 38 discriminator 2 view .LVU1653
	addq	$8, %r15
	.loc 1 19432 36 is_stmt 0 discriminator 2 view .LVU1654
	movq	0(%r13,%r15), %r14
.LVL504:
	.loc 1 19432 38 discriminator 2 view .LVU1655
	testq	%r14, %r14
	je	.L528
.LVL505:
.L521:
.LBB1061:
	.loc 1 19433 13 is_stmt 1 view .LVU1656
	.loc 1 19434 13 view .LVU1657
	.loc 1 19434 94 is_stmt 0 view .LVU1658
	movq	3352(%rbx), %rax
	movq	(%rax,%r15), %rdi
	call	*536(%r12)
.LVL506:
	.loc 1 19436 77 view .LVU1659
	movq	3344(%rbx), %rdi
	movq	%r14, %rdx
	.loc 1 19434 94 view .LVU1660
	movq	%rax, %rsi
.LVL507:
	.loc 1 19436 13 is_stmt 1 view .LVU1661
	.loc 1 19436 77 is_stmt 0 view .LVU1662
	call	*520(%r12)
.LVL508:
	.loc 1 19437 13 is_stmt 1 view .LVU1663
	testl	%eax, %eax
	je	.L522
	.loc 1 19438 17 view .LVU1664
	.loc 1 19438 62 is_stmt 0 view .LVU1665
	movq	%r13, %rdi
	call	*552(%r12)
.LVL509:
	.loc 1 19439 17 is_stmt 1 view .LVU1666
	.loc 1 19439 74 is_stmt 0 view .LVU1667
	movq	3344(%rbx), %rdi
	call	*512(%r12)
.LVL510:
	.loc 1 19440 17 is_stmt 1 view .LVU1668
.LBB1062:
.LBI1062:
	.loc 1 29688 16 view .LVU1669
.LBE1062:
.LBE1061:
.LBE1060:
.LBE1059:
.LBE1058:
	.loc 1 29690 5 view .LVU1670
.LBB1124:
.LBB1117:
.LBB1106:
.LBB1101:
.LBB1067:
.LBB1063:
.LBI1063:
	.loc 1 29679 20 view .LVU1671
.LBB1064:
	.loc 1 29681 5 view .LVU1672
	.loc 1 29685 5 view .LVU1673
	.loc 1 29685 21 is_stmt 0 view .LVU1674
	movq	(%rbx), %rax
.LVL511:
	.loc 1 29685 21 view .LVU1675
.LBE1064:
.LBE1063:
.LBB1065:
.LBI1065:
	.loc 1 28929 16 is_stmt 1 view .LVU1676
.LBB1066:
	.loc 1 28931 5 view .LVU1677
	testq	%rax, %rax
	je	.L559
	.loc 1 28935 5 view .LVU1678
	.loc 1 28935 22 is_stmt 0 view .LVU1679
	movq	112(%rax), %r14
.LVL512:
	.loc 1 28935 22 view .LVU1680
.LBE1066:
.LBE1065:
.LBE1067:
.LBB1068:
.LBI1068:
	.loc 1 2100 18 is_stmt 1 view .LVU1681
.LBB1069:
	.loc 1 2102 5 view .LVU1682
	testq	%r14, %r14
	je	.L559
	.loc 1 2106 5 view .LVU1683
.LVL513:
.LBB1070:
.LBI1070:
	.loc 1 2031 13 view .LVU1684
.LBB1071:
	.loc 1 2034 5 view .LVU1685
	.loc 1 2034 18 is_stmt 0 view .LVU1686
	leaq	104(%r14), %r13
.LVL514:
.LBB1072:
.LBI1072:
	.loc 1 4800 13 is_stmt 1 view .LVU1687
.LBE1072:
.LBE1071:
.LBE1070:
.LBE1069:
.LBE1068:
.LBE1101:
.LBE1106:
.LBE1117:
.LBE1124:
	.loc 1 4802 5 view .LVU1688
	.loc 1 4811 5 view .LVU1689
.LBB1125:
.LBB1118:
.LBB1107:
.LBB1102:
.LBB1097:
.LBB1093:
.LBB1081:
.LBB1079:
.LBB1077:
.LBB1073:
.LBI1073:
	.loc 1 4556 13 view .LVU1690
.LBB1074:
	.loc 1 4558 5 view .LVU1691
	leaq	8(%r14), %rbx
.LVL515:
	.loc 1 4558 5 is_stmt 0 view .LVU1692
.LBE1074:
.LBE1073:
.LBE1077:
.LBE1079:
.LBE1081:
.LBB1082:
	.loc 1 2109 19 view .LVU1693
	xorl	%r12d, %r12d
.LVL516:
	.loc 1 2109 19 view .LVU1694
.LBE1082:
.LBB1083:
.LBB1080:
.LBB1078:
.LBB1076:
.LBB1075:
	.loc 1 4558 23 view .LVU1695
	movq	%r13, %rdi
	call	pthread_mutex_lock
.LVL517:
	.loc 1 4558 23 view .LVU1696
.LBE1075:
.LBE1076:
.LBE1078:
.LBE1080:
.LBE1083:
	.loc 1 2107 5 is_stmt 1 view .LVU1697
.LBB1084:
	.loc 1 2108 9 view .LVU1698
	.loc 1 2109 9 view .LVU1699
	.loc 1 2109 29 view .LVU1700
	.loc 1 2109 37 is_stmt 0 view .LVU1701
	movl	64(%r14), %edx
	.loc 1 2109 29 view .LVU1702
	testl	%edx, %edx
	je	.L525
.LVL518:
.L527:
	.loc 1 2110 13 is_stmt 1 view .LVU1703
	.loc 1 2110 39 is_stmt 0 view .LVU1704
	movq	-8(%rbx), %rax
	.loc 1 2110 13 view .LVU1705
	testq	%rax, %rax
	je	.L524
	.loc 1 2111 17 is_stmt 1 view .LVU1706
	.loc 1 2111 44 is_stmt 0 view .LVU1707
	movq	(%rbx), %rdi
	movl	$.LC39, %edx
	.loc 1 2109 57 view .LVU1708
	addl	$1, %r12d
.LVL519:
	.loc 1 2109 29 view .LVU1709
	addq	$16, %rbx
	.loc 1 2111 44 view .LVU1710
	movl	$1, %esi
	call	*%rax
.LVL520:
	.loc 1 2109 37 view .LVU1711
	movl	64(%r14), %edx
	.loc 1 2109 9 is_stmt 1 view .LVU1712
.LVL521:
	.loc 1 2109 29 view .LVU1713
	cmpl	%edx, %r12d
	jb	.L527
.LVL522:
.L525:
	.loc 1 2109 29 is_stmt 0 view .LVU1714
.LBE1084:
	.loc 1 2115 5 is_stmt 1 view .LVU1715
.LBB1085:
.LBI1085:
	.loc 1 2040 13 view .LVU1716
.LBE1085:
.LBE1093:
.LBE1097:
.LBE1102:
.LBE1107:
.LBE1118:
.LBE1125:
	.loc 1 2043 5 view .LVU1717
.LBB1126:
.LBB1119:
.LBB1108:
.LBB1103:
.LBB1098:
.LBB1094:
.LBB1090:
.LBB1086:
.LBI1086:
	.loc 1 4815 13 view .LVU1718
.LBE1086:
.LBE1090:
.LBE1094:
.LBE1098:
.LBE1103:
.LBE1108:
.LBE1119:
.LBE1126:
	.loc 1 4817 5 view .LVU1719
	.loc 1 4826 5 view .LVU1720
.LBB1127:
.LBB1120:
.LBB1109:
.LBB1104:
.LBB1099:
.LBB1095:
.LBB1091:
.LBB1089:
.LBB1087:
.LBI1087:
	.loc 1 4561 13 view .LVU1721
.LBB1088:
	.loc 1 4563 5 view .LVU1722
	.loc 1 4563 25 is_stmt 0 view .LVU1723
	movq	%r13, %rdi
	call	pthread_mutex_unlock
.LVL523:
	.loc 1 4563 25 view .LVU1724
.LBE1088:
.LBE1087:
.LBE1089:
.LBE1091:
	.loc 1 2117 5 is_stmt 1 view .LVU1725
.LBE1095:
.LBE1099:
	.loc 1 19441 24 is_stmt 0 view .LVU1726
	movl	$-1, -52(%rbp)
.L502:
.LBE1104:
.LBE1109:
.LBE1120:
.LBE1127:
	.loc 1 19449 1 view .LVU1727
	movl	-52(%rbp), %eax
	addq	$24, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL524:
	.p2align 4,,10
	.p2align 3
.L564:
	.cfi_restore_state
.LBB1128:
.LBB1023:
	.loc 1 19401 9 is_stmt 1 view .LVU1728
	.loc 1 19401 93 is_stmt 0 view .LVU1729
	movq	3344(%rbx), %rdi
	movl	$6, %ecx
	movl	$.LC16, %edx
	xorl	%esi, %esi
	call	*496(%r12)
.LVL525:
	movq	%rax, %r13
.LVL526:
	.loc 1 19402 9 is_stmt 1 view .LVU1730
	testq	%rax, %rax
	je	.L561
.LVL527:
.LBB1024:
	.loc 1 19408 38 view .LVU1731
	.loc 1 19408 36 is_stmt 0 view .LVU1732
	movq	(%rax), %r14
	xorl	%r15d, %r15d
	.loc 1 19408 38 view .LVU1733
	testq	%r14, %r14
	jne	.L509
	jmp	.L518
.LVL528:
	.p2align 4,,10
	.p2align 3
.L510:
	.loc 1 19408 9 is_stmt 1 discriminator 2 view .LVU1734
	.loc 1 19408 38 discriminator 2 view .LVU1735
	addq	$8, %r15
	.loc 1 19408 36 is_stmt 0 discriminator 2 view .LVU1736
	movq	0(%r13,%r15), %r14
.LVL529:
	.loc 1 19408 38 discriminator 2 view .LVU1737
	testq	%r14, %r14
	je	.L518
.LVL530:
.L509:
.LBB1025:
	.loc 1 19409 13 is_stmt 1 view .LVU1738
	.loc 1 19410 13 view .LVU1739
	.loc 1 19410 94 is_stmt 0 view .LVU1740
	movq	3360(%rbx), %rax
	movq	(%rax,%r15), %rdi
	call	*536(%r12)
.LVL531:
	.loc 1 19412 77 view .LVU1741
	movq	3344(%rbx), %rdi
	movq	%r14, %rsi
	.loc 1 19410 94 view .LVU1742
	movq	%rax, %rdx
.LVL532:
	.loc 1 19412 13 is_stmt 1 view .LVU1743
	.loc 1 19412 77 is_stmt 0 view .LVU1744
	call	*520(%r12)
.LVL533:
	.loc 1 19413 13 is_stmt 1 view .LVU1745
	testl	%eax, %eax
	je	.L510
	.loc 1 19414 17 view .LVU1746
	.loc 1 19414 62 is_stmt 0 view .LVU1747
	movq	%r13, %rdi
	call	*552(%r12)
.LVL534:
	.loc 1 19415 17 is_stmt 1 view .LVU1748
	.loc 1 19415 74 is_stmt 0 view .LVU1749
	movq	3344(%rbx), %rdi
	call	*512(%r12)
.LVL535:
	.loc 1 19416 17 is_stmt 1 view .LVU1750
.LBB1026:
.LBI1026:
	.loc 1 29688 16 view .LVU1751
.LBE1026:
.LBE1025:
.LBE1024:
.LBE1023:
.LBE1128:
	.loc 1 29690 5 view .LVU1752
.LBB1129:
.LBB1055:
.LBB1053:
.LBB1051:
.LBB1031:
.LBB1027:
.LBI1027:
	.loc 1 29679 20 view .LVU1753
.LBB1028:
	.loc 1 29681 5 view .LVU1754
	.loc 1 29685 5 view .LVU1755
	.loc 1 29685 21 is_stmt 0 view .LVU1756
	movq	(%rbx), %rax
.LVL536:
	.loc 1 29685 21 view .LVU1757
.LBE1028:
.LBE1027:
.LBB1029:
.LBI1029:
	.loc 1 28929 16 is_stmt 1 view .LVU1758
.LBB1030:
	.loc 1 28931 5 view .LVU1759
	testq	%rax, %rax
	je	.L559
	.loc 1 28935 5 view .LVU1760
	.loc 1 28935 22 is_stmt 0 view .LVU1761
	movq	112(%rax), %r14
.LVL537:
	.loc 1 28935 22 view .LVU1762
.LBE1030:
.LBE1029:
.LBE1031:
.LBB1032:
.LBI1032:
	.loc 1 2100 18 is_stmt 1 view .LVU1763
.LBB1033:
	.loc 1 2102 5 view .LVU1764
	testq	%r14, %r14
	je	.L559
	.loc 1 2106 5 view .LVU1765
.LVL538:
.LBB1034:
.LBI1034:
	.loc 1 2031 13 view .LVU1766
.LBB1035:
	.loc 1 2034 5 view .LVU1767
	.loc 1 2034 18 is_stmt 0 view .LVU1768
	leaq	104(%r14), %r13
.LVL539:
.LBB1036:
.LBI1036:
	.loc 1 4800 13 is_stmt 1 view .LVU1769
.LBE1036:
.LBE1035:
.LBE1034:
.LBE1033:
.LBE1032:
.LBE1051:
.LBE1053:
.LBE1055:
.LBE1129:
	.loc 1 4802 5 view .LVU1770
	.loc 1 4811 5 view .LVU1771
.LBB1130:
.LBB1056:
.LBB1054:
.LBB1052:
.LBB1050:
.LBB1049:
.LBB1045:
.LBB1043:
.LBB1041:
.LBB1037:
.LBI1037:
	.loc 1 4556 13 view .LVU1772
.LBB1038:
	.loc 1 4558 5 view .LVU1773
	leaq	8(%r14), %rbx
.LVL540:
	.loc 1 4558 5 is_stmt 0 view .LVU1774
.LBE1038:
.LBE1037:
.LBE1041:
.LBE1043:
.LBE1045:
.LBB1046:
	.loc 1 2109 19 view .LVU1775
	xorl	%r12d, %r12d
.LVL541:
	.loc 1 2109 19 view .LVU1776
.LBE1046:
.LBB1047:
.LBB1044:
.LBB1042:
.LBB1040:
.LBB1039:
	.loc 1 4558 23 view .LVU1777
	movq	%r13, %rdi
	call	pthread_mutex_lock
.LVL542:
	.loc 1 4558 23 view .LVU1778
.LBE1039:
.LBE1040:
.LBE1042:
.LBE1044:
.LBE1047:
	.loc 1 2107 5 is_stmt 1 view .LVU1779
.LBB1048:
	.loc 1 2108 9 view .LVU1780
	.loc 1 2109 9 view .LVU1781
	.loc 1 2109 29 view .LVU1782
	.loc 1 2109 37 is_stmt 0 view .LVU1783
	movl	64(%r14), %edx
	.loc 1 2109 29 view .LVU1784
	testl	%edx, %edx
	je	.L525
.LVL543:
.L517:
	.loc 1 2110 13 is_stmt 1 view .LVU1785
	.loc 1 2110 39 is_stmt 0 view .LVU1786
	movq	-8(%rbx), %rax
	.loc 1 2110 13 view .LVU1787
	testq	%rax, %rax
	je	.L514
.L565:
	.loc 1 2111 17 is_stmt 1 view .LVU1788
	.loc 1 2111 44 is_stmt 0 view .LVU1789
	movq	(%rbx), %rdi
	movl	$.LC39, %edx
	.loc 1 2109 57 view .LVU1790
	addl	$1, %r12d
.LVL544:
	.loc 1 2109 29 view .LVU1791
	addq	$16, %rbx
	.loc 1 2111 44 view .LVU1792
	movl	$1, %esi
	call	*%rax
.LVL545:
	.loc 1 2109 37 view .LVU1793
	movl	64(%r14), %edx
	.loc 1 2109 9 is_stmt 1 view .LVU1794
.LVL546:
	.loc 1 2109 29 view .LVU1795
	cmpl	%edx, %r12d
	jnb	.L525
	.loc 1 2110 13 view .LVU1796
	.loc 1 2110 39 is_stmt 0 view .LVU1797
	movq	-8(%rbx), %rax
	.loc 1 2110 13 view .LVU1798
	testq	%rax, %rax
	jne	.L565
.L514:
	.loc 1 2109 9 is_stmt 1 view .LVU1799
	.loc 1 2109 57 is_stmt 0 view .LVU1800
	addl	$1, %r12d
.LVL547:
	.loc 1 2109 29 is_stmt 1 view .LVU1801
	addq	$16, %rbx
	cmpl	%r12d, %edx
	ja	.L517
	jmp	.L525
.LVL548:
	.p2align 4,,10
	.p2align 3
.L528:
	.loc 1 2109 29 is_stmt 0 view .LVU1802
.LBE1048:
.LBE1049:
.LBE1050:
.LBE1052:
.LBE1054:
.LBE1056:
.LBE1130:
.LBB1131:
.LBB1121:
	.loc 1 19445 9 is_stmt 1 view .LVU1803
	.loc 1 19445 54 is_stmt 0 view .LVU1804
	movq	%r13, %rdi
	call	*552(%r12)
.LVL549:
	jmp	.L502
.LVL550:
	.p2align 4,,10
	.p2align 3
.L518:
	.loc 1 19445 54 view .LVU1805
.LBE1121:
.LBE1131:
.LBB1132:
.LBB1057:
	.loc 1 19421 9 is_stmt 1 view .LVU1806
	.loc 1 19421 54 is_stmt 0 view .LVU1807
	movq	%r13, %rdi
	call	*552(%r12)
.LVL551:
.LBE1057:
.LBE1132:
.LBB1133:
	.loc 1 19424 18 view .LVU1808
	movl	8(%rbx), %eax
.LBE1133:
.LBB1134:
	jmp	.L506
.LVL552:
	.p2align 4,,10
	.p2align 3
.L524:
	.loc 1 19424 18 view .LVU1809
.LBE1134:
.LBB1135:
.LBB1122:
.LBB1110:
.LBB1105:
.LBB1100:
.LBB1096:
.LBB1092:
	.loc 1 2109 9 is_stmt 1 view .LVU1810
	.loc 1 2109 57 is_stmt 0 view .LVU1811
	addl	$1, %r12d
.LVL553:
	.loc 1 2109 29 is_stmt 1 view .LVU1812
	addq	$16, %rbx
	cmpl	%edx, %r12d
	jb	.L527
	jmp	.L525
.LVL554:
.L561:
	.loc 1 2109 29 is_stmt 0 view .LVU1813
.LBE1092:
.LBE1096:
.LBE1100:
.LBE1105:
.LBE1110:
	.loc 1 19427 13 is_stmt 1 view .LVU1814
	.loc 1 19427 70 is_stmt 0 view .LVU1815
	movq	3344(%rbx), %rdi
	call	*512(%r12)
.LVL555:
	.loc 1 19428 13 is_stmt 1 view .LVU1816
.LBB1111:
.LBI1111:
	.loc 1 29688 16 view .LVU1817
.LBE1111:
.LBE1122:
.LBE1135:
	.loc 1 29690 5 view .LVU1818
.LBB1136:
.LBB1123:
.LBB1116:
.LBB1112:
.LBI1112:
	.loc 1 29679 20 view .LVU1819
.LBB1113:
	.loc 1 29681 5 view .LVU1820
	.loc 1 29685 5 view .LVU1821
	.loc 1 29685 21 is_stmt 0 view .LVU1822
	movq	(%rbx), %rdi
.LVL556:
	.loc 1 29685 21 view .LVU1823
.LBE1113:
.LBE1112:
.LBB1114:
.LBI1114:
	.loc 1 28929 16 is_stmt 1 view .LVU1824
.LBB1115:
	.loc 1 28931 5 view .LVU1825
	testq	%rdi, %rdi
	je	.L520
	.loc 1 28935 5 view .LVU1826
	.loc 1 28935 22 is_stmt 0 view .LVU1827
	movq	112(%rdi), %rdi
.LVL557:
.L520:
	.loc 1 28935 22 view .LVU1828
.LBE1115:
.LBE1114:
.LBE1116:
	.loc 1 19428 24 view .LVU1829
	movl	$.LC38, %edx
	movl	$1, %esi
	call	ma_log_post
.LVL558:
.L559:
	.loc 1 19429 13 is_stmt 1 view .LVU1830
	.loc 1 19429 20 is_stmt 0 view .LVU1831
	movl	$-1, -52(%rbp)
	jmp	.L502
.LVL559:
.L563:
	.loc 1 19429 20 view .LVU1832
.LBE1123:
.LBE1136:
	.loc 1 19396 9 is_stmt 1 view .LVU1833
.LBB1137:
.LBI1137:
	.loc 1 29688 16 view .LVU1834
.LBE1137:
	.loc 1 29690 5 view .LVU1835
.LBB1142:
.LBB1138:
.LBI1138:
	.loc 1 29679 20 view .LVU1836
.LBB1139:
	.loc 1 29681 5 view .LVU1837
	.loc 1 29685 5 view .LVU1838
	.loc 1 29685 21 is_stmt 0 view .LVU1839
	movq	(%rbx), %rdi
.LVL560:
	.loc 1 29685 21 view .LVU1840
.LBE1139:
.LBE1138:
.LBB1140:
.LBI1140:
	.loc 1 28929 16 is_stmt 1 view .LVU1841
.LBB1141:
	.loc 1 28931 5 view .LVU1842
	testq	%rdi, %rdi
	je	.L504
	.loc 1 28935 5 view .LVU1843
	.loc 1 28935 22 is_stmt 0 view .LVU1844
	movq	112(%rdi), %rdi
.LVL561:
.L504:
	.loc 1 28935 22 view .LVU1845
.LBE1141:
.LBE1140:
.LBE1142:
	.loc 1 19396 20 view .LVU1846
	movl	$.LC37, %edx
	movl	$1, %esi
	call	ma_log_post
.LVL562:
	.loc 1 19397 9 is_stmt 1 view .LVU1847
	.loc 1 19397 16 is_stmt 0 view .LVU1848
	movl	$-302, -52(%rbp)
.LVL563:
	.loc 1 19397 16 view .LVU1849
	jmp	.L502
	.cfi_endproc
.LFE91:
	.size	_ZL21ma_device_start__jackP9ma_device, .-_ZL21ma_device_start__jackP9ma_device
	.section	.rodata.str1.8
	.align 8
.LC40:
	.string	"[JACK] An error occurred when deactivating the JACK client."
	.text
	.p2align 4
	.type	_ZL20ma_device_stop__jackP9ma_device, @function
_ZL20ma_device_stop__jackP9ma_device:
.LVL564:
.LFB92:
	.loc 1 19452 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 19452 1 is_stmt 0 view .LVU1851
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$16, %rsp
	.cfi_offset 14, -24
	.cfi_offset 13, -32
	.cfi_offset 12, -40
	.cfi_offset 3, -48
1:	call	mcount
	.loc 1 19452 1 view .LVU1852
	.loc 1 19453 5 is_stmt 1 view .LVU1853
.LVL565:
	.loc 1 19455 5 view .LVU1854
	.loc 1 19452 1 is_stmt 0 view .LVU1855
	movq	%rdi, %rbx
	.loc 1 19455 66 view .LVU1856
	movq	3344(%rdi), %rdi
.LVL566:
	.loc 1 19455 50 view .LVU1857
	movq	(%rbx), %rax
	.loc 1 19455 66 view .LVU1858
	call	*512(%rax)
.LVL567:
	.loc 1 19455 66 view .LVU1859
	movl	%eax, %r12d
	.loc 1 19455 5 view .LVU1860
	testl	%eax, %eax
	jne	.L585
	.loc 1 19460 5 is_stmt 1 view .LVU1861
.LVL568:
.LBB1170:
.LBI1170:
	.loc 1 6755 6 view .LVU1862
.LBB1171:
	.loc 1 6757 5 view .LVU1863
.LBB1172:
.LBI1172:
	.loc 1 6725 31 view .LVU1864
.LBB1173:
	.loc 1 6727 5 view .LVU1865
	.loc 1 6729 5 view .LVU1866
.LBB1174:
.LBI1174:
	.loc 1 776 23 view .LVU1867
.LBB1175:
	.loc 1 781 5 view .LVU1868
	.loc 1 782 9 view .LVU1869
.LBE1175:
.LBE1174:
.LBE1173:
.LBE1172:
.LBB1179:
.LBB1180:
	.loc 1 6740 31 is_stmt 0 view .LVU1870
	movq	32(%rbx), %rax
.LBE1180:
.LBE1179:
.LBB1183:
.LBB1178:
.LBB1177:
.LBB1176:
	.loc 1 782 15 view .LVU1871
	movl	$0, -36(%rbp)
.LVL569:
	.loc 1 782 15 view .LVU1872
.LBE1176:
.LBE1177:
	.loc 1 6730 5 is_stmt 1 view .LVU1873
	.loc 1 6730 26 is_stmt 0 view .LVU1874
	movq	%rbx, -48(%rbp)
	.loc 1 6731 5 is_stmt 1 view .LVU1875
	.loc 1 6731 26 is_stmt 0 view .LVU1876
	movl	$1, -40(%rbp)
	.loc 1 6733 5 is_stmt 1 view .LVU1877
.LVL570:
	.loc 1 6733 5 is_stmt 0 view .LVU1878
.LBE1178:
.LBE1183:
.LBB1184:
.LBI1179:
	.loc 1 6736 13 is_stmt 1 view .LVU1879
.LBB1181:
	.loc 1 6738 5 view .LVU1880
	.loc 1 6740 5 view .LVU1881
	testq	%rax, %rax
	je	.L574
	.loc 1 6741 9 view .LVU1882
	.loc 1 6741 45 is_stmt 0 view .LVU1883
	leaq	-48(%rbp), %rdi
	call	*%rax
.LVL571:
.L574:
	.loc 1 6745 5 is_stmt 1 view .LVU1884
	.loc 1 6745 22 is_stmt 0 view .LVU1885
	movq	-48(%rbp), %rdi
	.loc 1 6745 31 view .LVU1886
	movq	40(%rdi), %rax
	.loc 1 6745 5 view .LVU1887
	testq	%rax, %rax
	je	.L566
	.loc 1 6745 46 view .LVU1888
	cmpl	$1, -40(%rbp)
	je	.L586
.LVL572:
.L566:
	.loc 1 6745 46 view .LVU1889
.LBE1181:
.LBE1184:
.LBE1171:
.LBE1170:
	.loc 1 19463 1 view .LVU1890
	addq	$16, %rsp
	movl	%r12d, %eax
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL573:
	.p2align 4,,10
	.p2align 3
.L586:
	.cfi_restore_state
.LBB1187:
.LBB1186:
.LBB1185:
.LBB1182:
	.loc 1 6746 9 is_stmt 1 view .LVU1891
	.loc 1 6746 37 is_stmt 0 view .LVU1892
	call	*%rax
.LVL574:
.LBE1182:
.LBE1185:
.LBE1186:
.LBE1187:
	.loc 1 19463 1 view .LVU1893
	addq	$16, %rsp
	movl	%r12d, %eax
	popq	%rbx
.LVL575:
	.loc 1 19463 1 view .LVU1894
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL576:
	.p2align 4,,10
	.p2align 3
.L585:
	.cfi_restore_state
	.loc 1 19463 1 view .LVU1895
	movq	(%rbx), %rax
.LBB1188:
.LBI1188:
	.loc 1 19451 18 is_stmt 1 view .LVU1896
.LVL577:
.LBB1189:
.LBB1190:
.LBB1191:
.LBB1192:
	.loc 1 28931 5 is_stmt 0 view .LVU1897
	testq	%rax, %rax
	je	.L577
	.loc 1 28935 22 view .LVU1898
	movq	112(%rax), %r14
.LVL578:
	.loc 1 28935 22 view .LVU1899
.LBE1192:
.LBE1191:
.LBE1190:
.LBB1193:
.LBI1193:
	.loc 1 2100 18 is_stmt 1 view .LVU1900
.LBB1194:
	.loc 1 2102 5 view .LVU1901
	testq	%r14, %r14
	je	.L577
	.loc 1 2106 5 view .LVU1902
.LVL579:
.LBB1195:
.LBI1195:
	.loc 1 2031 13 view .LVU1903
.LBB1196:
	.loc 1 2034 5 view .LVU1904
	.loc 1 2034 18 is_stmt 0 view .LVU1905
	leaq	104(%r14), %r13
.LVL580:
.LBB1197:
.LBI1197:
	.loc 1 4800 13 is_stmt 1 view .LVU1906
.LBE1197:
.LBE1196:
.LBE1195:
.LBE1194:
.LBE1193:
.LBE1189:
.LBE1188:
	.loc 1 4802 5 view .LVU1907
	.loc 1 4811 5 view .LVU1908
.LBB1231:
.LBB1228:
.LBB1225:
.LBB1222:
.LBB1206:
.LBB1204:
.LBB1202:
.LBB1198:
.LBI1198:
	.loc 1 4556 13 view .LVU1909
.LBB1199:
	.loc 1 4558 5 view .LVU1910
	leaq	8(%r14), %rbx
.LVL581:
	.loc 1 4558 5 is_stmt 0 view .LVU1911
.LBE1199:
.LBE1198:
.LBE1202:
.LBE1204:
.LBE1206:
.LBB1207:
	.loc 1 2109 19 view .LVU1912
	xorl	%r12d, %r12d
.LBE1207:
.LBB1208:
.LBB1205:
.LBB1203:
.LBB1201:
.LBB1200:
	.loc 1 4558 23 view .LVU1913
	movq	%r13, %rdi
	call	pthread_mutex_lock
.LVL582:
	.loc 1 4558 23 view .LVU1914
.LBE1200:
.LBE1201:
.LBE1203:
.LBE1205:
.LBE1208:
	.loc 1 2107 5 is_stmt 1 view .LVU1915
.LBB1209:
	.loc 1 2108 9 view .LVU1916
	.loc 1 2109 9 view .LVU1917
	.loc 1 2109 29 view .LVU1918
	.loc 1 2109 37 is_stmt 0 view .LVU1919
	movl	64(%r14), %edx
	.loc 1 2109 29 view .LVU1920
	testl	%edx, %edx
	je	.L571
.LVL583:
.L573:
	.loc 1 2110 13 is_stmt 1 view .LVU1921
	.loc 1 2110 39 is_stmt 0 view .LVU1922
	movq	-8(%rbx), %rax
	.loc 1 2110 13 view .LVU1923
	testq	%rax, %rax
	je	.L570
	.loc 1 2111 17 is_stmt 1 view .LVU1924
	.loc 1 2111 44 is_stmt 0 view .LVU1925
	movq	(%rbx), %rdi
	movl	$.LC40, %edx
	.loc 1 2109 57 view .LVU1926
	addl	$1, %r12d
.LVL584:
	.loc 1 2109 29 view .LVU1927
	addq	$16, %rbx
	.loc 1 2111 44 view .LVU1928
	movl	$1, %esi
	call	*%rax
.LVL585:
	.loc 1 2109 37 view .LVU1929
	movl	64(%r14), %edx
	.loc 1 2109 9 is_stmt 1 view .LVU1930
.LVL586:
	.loc 1 2109 29 view .LVU1931
	cmpl	%edx, %r12d
	jb	.L573
.LVL587:
.L571:
	.loc 1 2109 29 is_stmt 0 view .LVU1932
.LBE1209:
	.loc 1 2115 5 is_stmt 1 view .LVU1933
.LBB1210:
.LBI1210:
	.loc 1 2040 13 view .LVU1934
.LBE1210:
.LBE1222:
.LBE1225:
.LBE1228:
.LBE1231:
	.loc 1 2043 5 view .LVU1935
.LBB1232:
.LBB1229:
.LBB1226:
.LBB1223:
.LBB1218:
.LBB1211:
.LBI1211:
	.loc 1 4815 13 view .LVU1936
.LBE1211:
.LBE1218:
.LBE1223:
.LBE1226:
.LBE1229:
.LBE1232:
	.loc 1 4817 5 view .LVU1937
	.loc 1 4826 5 view .LVU1938
.LBB1233:
.LBB1230:
.LBB1227:
.LBB1224:
.LBB1219:
.LBB1216:
.LBB1212:
.LBI1212:
	.loc 1 4561 13 view .LVU1939
.LBB1213:
	.loc 1 4563 5 view .LVU1940
	.loc 1 4563 25 is_stmt 0 view .LVU1941
	movq	%r13, %rdi
.LBE1213:
.LBE1212:
.LBE1216:
.LBE1219:
	.loc 1 2117 12 view .LVU1942
	movl	$-1, %r12d
.LBB1220:
.LBB1217:
.LBB1215:
.LBB1214:
	.loc 1 4563 25 view .LVU1943
	call	pthread_mutex_unlock
.LVL588:
	.loc 1 4563 25 view .LVU1944
.LBE1214:
.LBE1215:
.LBE1217:
.LBE1220:
	.loc 1 2117 5 is_stmt 1 view .LVU1945
	.loc 1 2117 12 is_stmt 0 view .LVU1946
	jmp	.L566
.LVL589:
	.p2align 4,,10
	.p2align 3
.L570:
.LBB1221:
	.loc 1 2109 9 is_stmt 1 view .LVU1947
	.loc 1 2109 57 is_stmt 0 view .LVU1948
	addl	$1, %r12d
.LVL590:
	.loc 1 2109 29 is_stmt 1 view .LVU1949
	addq	$16, %rbx
	cmpl	%r12d, %edx
	ja	.L573
	jmp	.L571
.LVL591:
.L577:
	.loc 1 2109 29 is_stmt 0 view .LVU1950
.LBE1221:
	movl	$-1, %r12d
	.loc 1 2109 29 view .LVU1951
	jmp	.L566
.LBE1224:
.LBE1227:
.LBE1230:
.LBE1233:
	.cfi_endproc
.LFE92:
	.size	_ZL20ma_device_stop__jackP9ma_device, .-_ZL20ma_device_stop__jackP9ma_device
	.section	.rodata.str1.8
	.align 8
.LC41:
	.string	"ma_result ma_context_uninit__jack(ma_context*)"
	.align 8
.LC42:
	.string	"pContext->backend == ma_backend_jack"
	.text
	.p2align 4
	.type	_ZL23ma_context_uninit__jackP10ma_context, @function
_ZL23ma_context_uninit__jackP10ma_context:
.LVL592:
.LFB95:
	.loc 1 19467 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 19467 1 is_stmt 0 view .LVU1953
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$8, %rsp
	.cfi_offset 3, -24
1:	call	mcount
	.loc 1 19467 1 view .LVU1954
	.loc 1 19468 5 is_stmt 1 view .LVU1955
	.loc 1 19467 1 is_stmt 0 view .LVU1956
	movq	%rdi, %rbx
	.loc 1 19468 5 view .LVU1957
	testq	%rdi, %rdi
	je	.L597
	.loc 1 19469 5 is_stmt 1 view .LVU1958
	cmpl	$9, 104(%rdi)
	jne	.L598
	.loc 1 19471 5 view .LVU1959
	.loc 1 19471 28 is_stmt 0 view .LVU1960
	movq	560(%rdi), %rdi
.LVL593:
.LBB1248:
.LBI1248:
	.loc 1 44086 13 is_stmt 1 view .LVU1961
.LBB1249:
	.loc 1 44088 5 view .LVU1962
	testq	%rdi, %rdi
	je	.L590
	.loc 1 44092 5 view .LVU1963
	movq	312(%rbx), %rax
.LVL594:
.LBB1250:
.LBI1250:
	.loc 1 44086 13 view .LVU1964
.LBB1251:
	.loc 1 44093 9 is_stmt 0 view .LVU1965
	testq	%rax, %rax
	je	.L590
	.loc 1 44094 41 view .LVU1966
	movq	288(%rbx), %rsi
	call	*%rax
.LVL595:
.L590:
	.loc 1 44094 41 view .LVU1967
.LBE1251:
.LBE1250:
.LBE1249:
.LBE1248:
	.loc 1 19472 5 is_stmt 1 view .LVU1968
	.loc 1 19472 32 is_stmt 0 view .LVU1969
	movq	$0, 560(%rbx)
	.loc 1 19475 5 is_stmt 1 view .LVU1970
.LVL596:
.LBB1252:
.LBI1252:
	.loc 1 6631 13 view .LVU1971
.LBB1253:
	.loc 1 6636 5 view .LVU1972
	.loc 1 6636 12 is_stmt 0 view .LVU1973
	movq	424(%rbx), %rdi
	call	dlclose
.LVL597:
	.loc 1 6639 5 is_stmt 1 view .LVU1974
	.loc 1 6639 5 is_stmt 0 view .LVU1975
.LBE1253:
.LBE1252:
	.loc 1 19478 5 is_stmt 1 view .LVU1976
	.loc 1 19479 1 is_stmt 0 view .LVU1977
	movq	-8(%rbp), %rbx
.LVL598:
	.loc 1 19479 1 view .LVU1978
	xorl	%eax, %eax
	leave
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL599:
.L597:
	.cfi_restore_state
	.loc 1 19468 5 discriminator 1 view .LVU1979
	movl	$.LC41, %ecx
	movl	$19468, %edx
	movl	$.LC8, %esi
	movl	$.LC9, %edi
	call	__assert_fail
.LVL600:
.L598:
.LBB1254:
.LBI1254:
	.loc 1 19466 18 is_stmt 1 view .LVU1980
.LBB1255:
	.loc 1 19469 5 is_stmt 0 view .LVU1981
	movl	$.LC41, %ecx
	movl	$19469, %edx
	movl	$.LC8, %esi
	movl	$.LC42, %edi
	call	__assert_fail
.LVL601:
.LBE1255:
.LBE1254:
	.cfi_endproc
.LFE95:
	.size	_ZL23ma_context_uninit__jackP10ma_context, .-_ZL23ma_context_uninit__jackP10ma_context
	.section	.rodata.str1.1
.LC43:
	.string	"libjack.so"
.LC44:
	.string	"libjack.so.0"
.LC45:
	.string	"Loading library: %s\n"
.LC46:
	.string	"Failed to load library: %s\n"
.LC47:
	.string	"jack_client_open"
.LC48:
	.string	"Failed to load symbol: %s\n"
.LC49:
	.string	"jack_client_close"
.LC50:
	.string	"jack_client_name_size"
.LC51:
	.string	"jack_set_process_callback"
.LC52:
	.string	"jack_set_buffer_size_callback"
.LC53:
	.string	"jack_on_shutdown"
.LC54:
	.string	"jack_get_sample_rate"
.LC55:
	.string	"jack_get_buffer_size"
.LC56:
	.string	"jack_get_ports"
.LC57:
	.string	"jack_activate"
.LC58:
	.string	"jack_deactivate"
.LC59:
	.string	"jack_connect"
.LC60:
	.string	"jack_port_register"
.LC61:
	.string	"jack_port_name"
.LC62:
	.string	"jack_port_get_buffer"
.LC63:
	.string	"jack_free"
.LC64:
	.string	"Loading symbol: %s\n"
	.text
	.p2align 4
	.globl	_ZL21ma_context_init__jackP10ma_contextPK17ma_context_configP20ma_backend_callbacks.lto_priv.0
	.hidden	_ZL21ma_context_init__jackP10ma_contextPK17ma_context_configP20ma_backend_callbacks.lto_priv.0
	.type	_ZL21ma_context_init__jackP10ma_contextPK17ma_context_configP20ma_backend_callbacks.lto_priv.0, @function
_ZL21ma_context_init__jackP10ma_contextPK17ma_context_configP20ma_backend_callbacks.lto_priv.0:
.LVL602:
.LFB97:
	.loc 1 19482 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 19482 1 is_stmt 0 view .LVU1983
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
1:	call	mcount
	.loc 1 19482 1 view .LVU1984
	.loc 1 19484 5 is_stmt 1 view .LVU1985
	.loc 1 19484 17 is_stmt 0 view .LVU1986
	movl	$.LC43, %eax
	movq	%rax, %xmm0
	movhps	.LC65(%rip), %xmm0
	.loc 1 19482 1 view .LVU1987
	movq	%rsi, -88(%rbp)
	movq	%rdi, %rbx
	movq	%rdx, %r13
	leaq	-64(%rbp), %r15
	.loc 1 19484 17 view .LVU1988
	movaps	%xmm0, -64(%rbp)
	.loc 1 19493 5 is_stmt 1 view .LVU1989
	.loc 1 19495 5 view .LVU1990
.LVL603:
	.loc 1 19495 19 view .LVU1991
.L603:
	.loc 1 19496 9 view .LVU1992
	.loc 1 19496 42 is_stmt 0 view .LVU1993
	movq	(%r15), %r14
.LVL604:
.LBB1439:
.LBI1439:
	.loc 1 6596 18 is_stmt 1 view .LVU1994
.LBB1440:
	.loc 1 6598 5 view .LVU1995
	.loc 1 6600 5 view .LVU1996
.LBB1441:
.LBI1441:
	.loc 1 28929 16 view .LVU1997
.LBB1442:
	.loc 1 28931 5 view .LVU1998
	testq	%rbx, %rbx
	je	.L600
	.loc 1 28935 5 view .LVU1999
.LVL605:
	.loc 1 28935 5 is_stmt 0 view .LVU2000
.LBE1442:
.LBE1441:
	.loc 1 6600 17 view .LVU2001
	movq	112(%rbx), %rdi
	movq	%r14, %rcx
	movl	$.LC45, %edx
	xorl	%eax, %eax
	movl	$4, %esi
	call	ma_log_postf.constprop.0
.LVL606:
	.loc 1 6616 5 is_stmt 1 view .LVU2002
	.loc 1 6616 31 is_stmt 0 view .LVU2003
	movl	$2, %esi
	movq	%r14, %rdi
	call	dlopen
.LVL607:
	movq	%rax, %r12
.LVL608:
	.loc 1 6623 5 is_stmt 1 view .LVU2004
	testq	%rax, %rax
	je	.L653
.L601:
	.loc 1 6627 5 view .LVU2005
	.loc 1 6628 5 view .LVU2006
.LVL609:
	.loc 1 6628 5 is_stmt 0 view .LVU2007
.LBE1440:
.LBE1439:
.LBB1452:
.LBB1453:
	.loc 1 6646 17 view .LVU2008
	movq	112(%rbx), %rdi
	movl	$.LC47, %ecx
	movl	$.LC64, %edx
	xorl	%eax, %eax
.LBE1453:
.LBE1452:
	.loc 1 19496 31 view .LVU2009
	movq	%r12, 424(%rbx)
	.loc 1 19497 9 is_stmt 1 view .LVU2010
	.loc 1 19502 5 view .LVU2011
	.loc 1 19506 5 view .LVU2012
.LVL610:
.LBB1462:
.LBI1452:
	.loc 1 6642 16 view .LVU2013
.LBB1460:
	.loc 1 6644 5 view .LVU2014
	.loc 1 6646 5 view .LVU2015
.LBB1454:
.LBI1454:
	.loc 1 28929 16 view .LVU2016
.LBB1455:
	.loc 1 28931 5 view .LVU2017
	.loc 1 28935 5 view .LVU2018
	.loc 1 28935 5 is_stmt 0 view .LVU2019
.LBE1455:
.LBE1454:
	.loc 1 6646 17 view .LVU2020
	movl	$4, %esi
	call	ma_log_postf.constprop.0
.LVL611:
	.loc 1 6652 13 is_stmt 1 view .LVU2021
	.loc 1 6653 13 view .LVU2022
	.loc 1 6655 5 view .LVU2023
	.loc 1 6655 26 is_stmt 0 view .LVU2024
	movq	%r12, %rdi
	movl	$.LC47, %esi
	call	dlsym
.LVL612:
	movq	%rax, %r12
.LVL613:
	.loc 1 6657 13 is_stmt 1 view .LVU2025
	.loc 1 6661 5 view .LVU2026
	testq	%rax, %rax
	je	.L654
.LVL614:
.L604:
	.loc 1 6665 5 view .LVU2027
	.loc 1 6666 5 view .LVU2028
	.loc 1 6666 5 is_stmt 0 view .LVU2029
.LBE1460:
.LBE1462:
.LBB1463:
.LBB1464:
	.loc 1 6646 17 view .LVU2030
	movq	112(%rbx), %rdi
	movl	$.LC49, %ecx
	movl	$.LC64, %edx
	xorl	%eax, %eax
.LBE1464:
.LBE1463:
	.loc 1 19506 50 view .LVU2031
	movq	%r12, 432(%rbx)
	.loc 1 19507 5 is_stmt 1 view .LVU2032
	.loc 1 19507 69 is_stmt 0 view .LVU2033
	movq	424(%rbx), %r12
.LVL615:
.LBB1473:
.LBI1463:
	.loc 1 6642 16 is_stmt 1 view .LVU2034
.LBB1471:
	.loc 1 6644 5 view .LVU2035
	.loc 1 6646 5 view .LVU2036
.LBB1465:
.LBI1465:
	.loc 1 28929 16 view .LVU2037
.LBB1466:
	.loc 1 28931 5 view .LVU2038
	.loc 1 28935 5 view .LVU2039
	.loc 1 28935 5 is_stmt 0 view .LVU2040
.LBE1466:
.LBE1465:
	.loc 1 6646 17 view .LVU2041
	movl	$4, %esi
	call	ma_log_postf.constprop.0
.LVL616:
	.loc 1 6652 13 is_stmt 1 view .LVU2042
	.loc 1 6653 13 view .LVU2043
	.loc 1 6655 5 view .LVU2044
	.loc 1 6655 26 is_stmt 0 view .LVU2045
	movq	%r12, %rdi
	movl	$.LC49, %esi
	call	dlsym
.LVL617:
	movq	%rax, %r12
.LVL618:
	.loc 1 6657 13 is_stmt 1 view .LVU2046
	.loc 1 6661 5 view .LVU2047
	testq	%rax, %rax
	je	.L655
.LVL619:
.L605:
	.loc 1 6665 5 view .LVU2048
	.loc 1 6666 5 view .LVU2049
	.loc 1 6666 5 is_stmt 0 view .LVU2050
.LBE1471:
.LBE1473:
.LBB1474:
.LBB1475:
	.loc 1 6646 17 view .LVU2051
	movq	112(%rbx), %rdi
	movl	$.LC50, %ecx
	movl	$.LC64, %edx
	xorl	%eax, %eax
.LBE1475:
.LBE1474:
	.loc 1 19507 50 view .LVU2052
	movq	%r12, 440(%rbx)
	.loc 1 19508 5 is_stmt 1 view .LVU2053
	.loc 1 19508 69 is_stmt 0 view .LVU2054
	movq	424(%rbx), %r12
.LVL620:
.LBB1484:
.LBI1474:
	.loc 1 6642 16 is_stmt 1 view .LVU2055
.LBB1482:
	.loc 1 6644 5 view .LVU2056
	.loc 1 6646 5 view .LVU2057
.LBB1476:
.LBI1476:
	.loc 1 28929 16 view .LVU2058
.LBB1477:
	.loc 1 28931 5 view .LVU2059
	.loc 1 28935 5 view .LVU2060
	.loc 1 28935 5 is_stmt 0 view .LVU2061
.LBE1477:
.LBE1476:
	.loc 1 6646 17 view .LVU2062
	movl	$4, %esi
	call	ma_log_postf.constprop.0
.LVL621:
	.loc 1 6652 13 is_stmt 1 view .LVU2063
	.loc 1 6653 13 view .LVU2064
	.loc 1 6655 5 view .LVU2065
	.loc 1 6655 26 is_stmt 0 view .LVU2066
	movq	%r12, %rdi
	movl	$.LC50, %esi
	call	dlsym
.LVL622:
	movq	%rax, %r12
.LVL623:
	.loc 1 6657 13 is_stmt 1 view .LVU2067
	.loc 1 6661 5 view .LVU2068
	testq	%rax, %rax
	je	.L656
.LVL624:
.L606:
	.loc 1 6665 5 view .LVU2069
	.loc 1 6666 5 view .LVU2070
	.loc 1 6666 5 is_stmt 0 view .LVU2071
.LBE1482:
.LBE1484:
.LBB1485:
.LBB1486:
	.loc 1 6646 17 view .LVU2072
	movq	112(%rbx), %rdi
	movl	$.LC51, %ecx
	movl	$.LC64, %edx
	xorl	%eax, %eax
.LBE1486:
.LBE1485:
	.loc 1 19508 50 view .LVU2073
	movq	%r12, 448(%rbx)
	.loc 1 19509 5 is_stmt 1 view .LVU2074
	.loc 1 19509 69 is_stmt 0 view .LVU2075
	movq	424(%rbx), %r12
.LVL625:
.LBB1495:
.LBI1485:
	.loc 1 6642 16 is_stmt 1 view .LVU2076
.LBB1493:
	.loc 1 6644 5 view .LVU2077
	.loc 1 6646 5 view .LVU2078
.LBB1487:
.LBI1487:
	.loc 1 28929 16 view .LVU2079
.LBB1488:
	.loc 1 28931 5 view .LVU2080
	.loc 1 28935 5 view .LVU2081
	.loc 1 28935 5 is_stmt 0 view .LVU2082
.LBE1488:
.LBE1487:
	.loc 1 6646 17 view .LVU2083
	movl	$4, %esi
	call	ma_log_postf.constprop.0
.LVL626:
	.loc 1 6652 13 is_stmt 1 view .LVU2084
	.loc 1 6653 13 view .LVU2085
	.loc 1 6655 5 view .LVU2086
	.loc 1 6655 26 is_stmt 0 view .LVU2087
	movq	%r12, %rdi
	movl	$.LC51, %esi
	call	dlsym
.LVL627:
	movq	%rax, %r12
.LVL628:
	.loc 1 6657 13 is_stmt 1 view .LVU2088
	.loc 1 6661 5 view .LVU2089
	testq	%rax, %rax
	je	.L657
.LVL629:
.L607:
	.loc 1 6665 5 view .LVU2090
	.loc 1 6666 5 view .LVU2091
	.loc 1 6666 5 is_stmt 0 view .LVU2092
.LBE1493:
.LBE1495:
.LBB1496:
.LBB1497:
	.loc 1 6646 17 view .LVU2093
	movq	112(%rbx), %rdi
	movl	$.LC52, %ecx
	movl	$.LC64, %edx
	xorl	%eax, %eax
.LBE1497:
.LBE1496:
	.loc 1 19509 50 view .LVU2094
	movq	%r12, 456(%rbx)
	.loc 1 19510 5 is_stmt 1 view .LVU2095
	.loc 1 19510 69 is_stmt 0 view .LVU2096
	movq	424(%rbx), %r12
.LVL630:
.LBB1506:
.LBI1496:
	.loc 1 6642 16 is_stmt 1 view .LVU2097
.LBB1504:
	.loc 1 6644 5 view .LVU2098
	.loc 1 6646 5 view .LVU2099
.LBB1498:
.LBI1498:
	.loc 1 28929 16 view .LVU2100
.LBB1499:
	.loc 1 28931 5 view .LVU2101
	.loc 1 28935 5 view .LVU2102
	.loc 1 28935 5 is_stmt 0 view .LVU2103
.LBE1499:
.LBE1498:
	.loc 1 6646 17 view .LVU2104
	movl	$4, %esi
	call	ma_log_postf.constprop.0
.LVL631:
	.loc 1 6652 13 is_stmt 1 view .LVU2105
	.loc 1 6653 13 view .LVU2106
	.loc 1 6655 5 view .LVU2107
	.loc 1 6655 26 is_stmt 0 view .LVU2108
	movq	%r12, %rdi
	movl	$.LC52, %esi
	call	dlsym
.LVL632:
	movq	%rax, %r12
.LVL633:
	.loc 1 6657 13 is_stmt 1 view .LVU2109
	.loc 1 6661 5 view .LVU2110
	testq	%rax, %rax
	je	.L658
.LVL634:
.L608:
	.loc 1 6665 5 view .LVU2111
	.loc 1 6666 5 view .LVU2112
	.loc 1 6666 5 is_stmt 0 view .LVU2113
.LBE1504:
.LBE1506:
.LBB1507:
.LBB1508:
	.loc 1 6646 17 view .LVU2114
	movq	112(%rbx), %rdi
	movl	$.LC53, %ecx
	movl	$.LC64, %edx
	xorl	%eax, %eax
.LBE1508:
.LBE1507:
	.loc 1 19510 50 view .LVU2115
	movq	%r12, 464(%rbx)
	.loc 1 19511 5 is_stmt 1 view .LVU2116
	.loc 1 19511 69 is_stmt 0 view .LVU2117
	movq	424(%rbx), %r12
.LVL635:
.LBB1517:
.LBI1507:
	.loc 1 6642 16 is_stmt 1 view .LVU2118
.LBB1515:
	.loc 1 6644 5 view .LVU2119
	.loc 1 6646 5 view .LVU2120
.LBB1509:
.LBI1509:
	.loc 1 28929 16 view .LVU2121
.LBB1510:
	.loc 1 28931 5 view .LVU2122
	.loc 1 28935 5 view .LVU2123
	.loc 1 28935 5 is_stmt 0 view .LVU2124
.LBE1510:
.LBE1509:
	.loc 1 6646 17 view .LVU2125
	movl	$4, %esi
	call	ma_log_postf.constprop.0
.LVL636:
	.loc 1 6652 13 is_stmt 1 view .LVU2126
	.loc 1 6653 13 view .LVU2127
	.loc 1 6655 5 view .LVU2128
	.loc 1 6655 26 is_stmt 0 view .LVU2129
	movq	%r12, %rdi
	movl	$.LC53, %esi
	call	dlsym
.LVL637:
	movq	%rax, %r12
.LVL638:
	.loc 1 6657 13 is_stmt 1 view .LVU2130
	.loc 1 6661 5 view .LVU2131
	testq	%rax, %rax
	je	.L659
.LVL639:
.L609:
	.loc 1 6665 5 view .LVU2132
	.loc 1 6666 5 view .LVU2133
	.loc 1 6666 5 is_stmt 0 view .LVU2134
.LBE1515:
.LBE1517:
.LBB1518:
.LBB1519:
	.loc 1 6646 17 view .LVU2135
	movq	112(%rbx), %rdi
	movl	$.LC54, %ecx
	movl	$.LC64, %edx
	xorl	%eax, %eax
.LBE1519:
.LBE1518:
	.loc 1 19511 50 view .LVU2136
	movq	%r12, 472(%rbx)
	.loc 1 19512 5 is_stmt 1 view .LVU2137
	.loc 1 19512 69 is_stmt 0 view .LVU2138
	movq	424(%rbx), %r12
.LVL640:
.LBB1528:
.LBI1518:
	.loc 1 6642 16 is_stmt 1 view .LVU2139
.LBB1526:
	.loc 1 6644 5 view .LVU2140
	.loc 1 6646 5 view .LVU2141
.LBB1520:
.LBI1520:
	.loc 1 28929 16 view .LVU2142
.LBB1521:
	.loc 1 28931 5 view .LVU2143
	.loc 1 28935 5 view .LVU2144
	.loc 1 28935 5 is_stmt 0 view .LVU2145
.LBE1521:
.LBE1520:
	.loc 1 6646 17 view .LVU2146
	movl	$4, %esi
	call	ma_log_postf.constprop.0
.LVL641:
	.loc 1 6652 13 is_stmt 1 view .LVU2147
	.loc 1 6653 13 view .LVU2148
	.loc 1 6655 5 view .LVU2149
	.loc 1 6655 26 is_stmt 0 view .LVU2150
	movq	%r12, %rdi
	movl	$.LC54, %esi
	call	dlsym
.LVL642:
	movq	%rax, %r12
.LVL643:
	.loc 1 6657 13 is_stmt 1 view .LVU2151
	.loc 1 6661 5 view .LVU2152
	testq	%rax, %rax
	je	.L660
.LVL644:
.L610:
	.loc 1 6665 5 view .LVU2153
	.loc 1 6666 5 view .LVU2154
	.loc 1 6666 5 is_stmt 0 view .LVU2155
.LBE1526:
.LBE1528:
.LBB1529:
.LBB1530:
	.loc 1 6646 17 view .LVU2156
	movq	112(%rbx), %rdi
	movl	$.LC55, %ecx
	movl	$.LC64, %edx
	xorl	%eax, %eax
.LBE1530:
.LBE1529:
	.loc 1 19512 50 view .LVU2157
	movq	%r12, 480(%rbx)
	.loc 1 19513 5 is_stmt 1 view .LVU2158
	.loc 1 19513 69 is_stmt 0 view .LVU2159
	movq	424(%rbx), %r12
.LVL645:
.LBB1539:
.LBI1529:
	.loc 1 6642 16 is_stmt 1 view .LVU2160
.LBB1537:
	.loc 1 6644 5 view .LVU2161
	.loc 1 6646 5 view .LVU2162
.LBB1531:
.LBI1531:
	.loc 1 28929 16 view .LVU2163
.LBB1532:
	.loc 1 28931 5 view .LVU2164
	.loc 1 28935 5 view .LVU2165
	.loc 1 28935 5 is_stmt 0 view .LVU2166
.LBE1532:
.LBE1531:
	.loc 1 6646 17 view .LVU2167
	movl	$4, %esi
	call	ma_log_postf.constprop.0
.LVL646:
	.loc 1 6652 13 is_stmt 1 view .LVU2168
	.loc 1 6653 13 view .LVU2169
	.loc 1 6655 5 view .LVU2170
	.loc 1 6655 26 is_stmt 0 view .LVU2171
	movq	%r12, %rdi
	movl	$.LC55, %esi
	call	dlsym
.LVL647:
	movq	%rax, %r12
.LVL648:
	.loc 1 6657 13 is_stmt 1 view .LVU2172
	.loc 1 6661 5 view .LVU2173
	testq	%rax, %rax
	je	.L661
.LVL649:
.L611:
	.loc 1 6665 5 view .LVU2174
	.loc 1 6666 5 view .LVU2175
	.loc 1 6666 5 is_stmt 0 view .LVU2176
.LBE1537:
.LBE1539:
.LBB1540:
.LBB1541:
	.loc 1 6646 17 view .LVU2177
	movq	112(%rbx), %rdi
	movl	$.LC56, %ecx
	movl	$.LC64, %edx
	xorl	%eax, %eax
.LBE1541:
.LBE1540:
	.loc 1 19513 50 view .LVU2178
	movq	%r12, 488(%rbx)
	.loc 1 19514 5 is_stmt 1 view .LVU2179
	.loc 1 19514 69 is_stmt 0 view .LVU2180
	movq	424(%rbx), %r12
.LVL650:
.LBB1550:
.LBI1540:
	.loc 1 6642 16 is_stmt 1 view .LVU2181
.LBB1548:
	.loc 1 6644 5 view .LVU2182
	.loc 1 6646 5 view .LVU2183
.LBB1542:
.LBI1542:
	.loc 1 28929 16 view .LVU2184
.LBB1543:
	.loc 1 28931 5 view .LVU2185
	.loc 1 28935 5 view .LVU2186
	.loc 1 28935 5 is_stmt 0 view .LVU2187
.LBE1543:
.LBE1542:
	.loc 1 6646 17 view .LVU2188
	movl	$4, %esi
	call	ma_log_postf.constprop.0
.LVL651:
	.loc 1 6652 13 is_stmt 1 view .LVU2189
	.loc 1 6653 13 view .LVU2190
	.loc 1 6655 5 view .LVU2191
	.loc 1 6655 26 is_stmt 0 view .LVU2192
	movq	%r12, %rdi
	movl	$.LC56, %esi
	call	dlsym
.LVL652:
	movq	%rax, %r12
.LVL653:
	.loc 1 6657 13 is_stmt 1 view .LVU2193
	.loc 1 6661 5 view .LVU2194
	testq	%rax, %rax
	je	.L662
.LVL654:
.L612:
	.loc 1 6665 5 view .LVU2195
	.loc 1 6666 5 view .LVU2196
	.loc 1 6666 5 is_stmt 0 view .LVU2197
.LBE1548:
.LBE1550:
.LBB1551:
.LBB1552:
	.loc 1 6646 17 view .LVU2198
	movq	112(%rbx), %rdi
	movl	$.LC57, %ecx
	movl	$.LC64, %edx
	xorl	%eax, %eax
.LBE1552:
.LBE1551:
	.loc 1 19514 50 view .LVU2199
	movq	%r12, 496(%rbx)
	.loc 1 19515 5 is_stmt 1 view .LVU2200
	.loc 1 19515 69 is_stmt 0 view .LVU2201
	movq	424(%rbx), %r12
.LVL655:
.LBB1561:
.LBI1551:
	.loc 1 6642 16 is_stmt 1 view .LVU2202
.LBB1559:
	.loc 1 6644 5 view .LVU2203
	.loc 1 6646 5 view .LVU2204
.LBB1553:
.LBI1553:
	.loc 1 28929 16 view .LVU2205
.LBB1554:
	.loc 1 28931 5 view .LVU2206
	.loc 1 28935 5 view .LVU2207
	.loc 1 28935 5 is_stmt 0 view .LVU2208
.LBE1554:
.LBE1553:
	.loc 1 6646 17 view .LVU2209
	movl	$4, %esi
	call	ma_log_postf.constprop.0
.LVL656:
	.loc 1 6652 13 is_stmt 1 view .LVU2210
	.loc 1 6653 13 view .LVU2211
	.loc 1 6655 5 view .LVU2212
	.loc 1 6655 26 is_stmt 0 view .LVU2213
	movq	%r12, %rdi
	movl	$.LC57, %esi
	call	dlsym
.LVL657:
	movq	%rax, %r12
.LVL658:
	.loc 1 6657 13 is_stmt 1 view .LVU2214
	.loc 1 6661 5 view .LVU2215
	testq	%rax, %rax
	je	.L663
.LVL659:
.L613:
	.loc 1 6665 5 view .LVU2216
	.loc 1 6666 5 view .LVU2217
	.loc 1 6666 5 is_stmt 0 view .LVU2218
.LBE1559:
.LBE1561:
.LBB1562:
.LBB1563:
	.loc 1 6646 17 view .LVU2219
	movq	112(%rbx), %rdi
	movl	$.LC58, %ecx
	movl	$.LC64, %edx
	xorl	%eax, %eax
.LBE1563:
.LBE1562:
	.loc 1 19515 50 view .LVU2220
	movq	%r12, 504(%rbx)
	.loc 1 19516 5 is_stmt 1 view .LVU2221
	.loc 1 19516 69 is_stmt 0 view .LVU2222
	movq	424(%rbx), %r12
.LVL660:
.LBB1572:
.LBI1562:
	.loc 1 6642 16 is_stmt 1 view .LVU2223
.LBB1570:
	.loc 1 6644 5 view .LVU2224
	.loc 1 6646 5 view .LVU2225
.LBB1564:
.LBI1564:
	.loc 1 28929 16 view .LVU2226
.LBB1565:
	.loc 1 28931 5 view .LVU2227
	.loc 1 28935 5 view .LVU2228
	.loc 1 28935 5 is_stmt 0 view .LVU2229
.LBE1565:
.LBE1564:
	.loc 1 6646 17 view .LVU2230
	movl	$4, %esi
	call	ma_log_postf.constprop.0
.LVL661:
	.loc 1 6652 13 is_stmt 1 view .LVU2231
	.loc 1 6653 13 view .LVU2232
	.loc 1 6655 5 view .LVU2233
	.loc 1 6655 26 is_stmt 0 view .LVU2234
	movq	%r12, %rdi
	movl	$.LC58, %esi
	call	dlsym
.LVL662:
	movq	%rax, %r12
.LVL663:
	.loc 1 6657 13 is_stmt 1 view .LVU2235
	.loc 1 6661 5 view .LVU2236
	testq	%rax, %rax
	je	.L664
.LVL664:
.L614:
	.loc 1 6665 5 view .LVU2237
	.loc 1 6666 5 view .LVU2238
	.loc 1 6666 5 is_stmt 0 view .LVU2239
.LBE1570:
.LBE1572:
.LBB1573:
.LBB1574:
	.loc 1 6646 17 view .LVU2240
	movq	112(%rbx), %rdi
	movl	$.LC59, %ecx
	movl	$.LC64, %edx
	xorl	%eax, %eax
.LBE1574:
.LBE1573:
	.loc 1 19516 50 view .LVU2241
	movq	%r12, 512(%rbx)
	.loc 1 19517 5 is_stmt 1 view .LVU2242
	.loc 1 19517 69 is_stmt 0 view .LVU2243
	movq	424(%rbx), %r12
.LVL665:
.LBB1583:
.LBI1573:
	.loc 1 6642 16 is_stmt 1 view .LVU2244
.LBB1581:
	.loc 1 6644 5 view .LVU2245
	.loc 1 6646 5 view .LVU2246
.LBB1575:
.LBI1575:
	.loc 1 28929 16 view .LVU2247
.LBB1576:
	.loc 1 28931 5 view .LVU2248
	.loc 1 28935 5 view .LVU2249
	.loc 1 28935 5 is_stmt 0 view .LVU2250
.LBE1576:
.LBE1575:
	.loc 1 6646 17 view .LVU2251
	movl	$4, %esi
	call	ma_log_postf.constprop.0
.LVL666:
	.loc 1 6652 13 is_stmt 1 view .LVU2252
	.loc 1 6653 13 view .LVU2253
	.loc 1 6655 5 view .LVU2254
	.loc 1 6655 26 is_stmt 0 view .LVU2255
	movq	%r12, %rdi
	movl	$.LC59, %esi
	call	dlsym
.LVL667:
	movq	%rax, %r12
.LVL668:
	.loc 1 6657 13 is_stmt 1 view .LVU2256
	.loc 1 6661 5 view .LVU2257
	testq	%rax, %rax
	je	.L665
.LVL669:
.L615:
	.loc 1 6665 5 view .LVU2258
	.loc 1 6666 5 view .LVU2259
	.loc 1 6666 5 is_stmt 0 view .LVU2260
.LBE1581:
.LBE1583:
.LBB1584:
.LBB1585:
	.loc 1 6646 17 view .LVU2261
	movq	112(%rbx), %rdi
	movl	$.LC60, %ecx
	movl	$.LC64, %edx
	xorl	%eax, %eax
.LBE1585:
.LBE1584:
	.loc 1 19517 50 view .LVU2262
	movq	%r12, 520(%rbx)
	.loc 1 19518 5 is_stmt 1 view .LVU2263
	.loc 1 19518 69 is_stmt 0 view .LVU2264
	movq	424(%rbx), %r12
.LVL670:
.LBB1594:
.LBI1584:
	.loc 1 6642 16 is_stmt 1 view .LVU2265
.LBB1592:
	.loc 1 6644 5 view .LVU2266
	.loc 1 6646 5 view .LVU2267
.LBB1586:
.LBI1586:
	.loc 1 28929 16 view .LVU2268
.LBB1587:
	.loc 1 28931 5 view .LVU2269
	.loc 1 28935 5 view .LVU2270
	.loc 1 28935 5 is_stmt 0 view .LVU2271
.LBE1587:
.LBE1586:
	.loc 1 6646 17 view .LVU2272
	movl	$4, %esi
	call	ma_log_postf.constprop.0
.LVL671:
	.loc 1 6652 13 is_stmt 1 view .LVU2273
	.loc 1 6653 13 view .LVU2274
	.loc 1 6655 5 view .LVU2275
	.loc 1 6655 26 is_stmt 0 view .LVU2276
	movq	%r12, %rdi
	movl	$.LC60, %esi
	call	dlsym
.LVL672:
	movq	%rax, %r12
.LVL673:
	.loc 1 6657 13 is_stmt 1 view .LVU2277
	.loc 1 6661 5 view .LVU2278
	testq	%rax, %rax
	je	.L666
.LVL674:
.L616:
	.loc 1 6665 5 view .LVU2279
	.loc 1 6666 5 view .LVU2280
	.loc 1 6666 5 is_stmt 0 view .LVU2281
.LBE1592:
.LBE1594:
.LBB1595:
.LBB1596:
	.loc 1 6646 17 view .LVU2282
	movq	112(%rbx), %rdi
	movl	$.LC61, %ecx
	movl	$.LC64, %edx
	xorl	%eax, %eax
.LBE1596:
.LBE1595:
	.loc 1 19518 50 view .LVU2283
	movq	%r12, 528(%rbx)
	.loc 1 19519 5 is_stmt 1 view .LVU2284
	.loc 1 19519 69 is_stmt 0 view .LVU2285
	movq	424(%rbx), %r12
.LVL675:
.LBB1605:
.LBI1595:
	.loc 1 6642 16 is_stmt 1 view .LVU2286
.LBB1603:
	.loc 1 6644 5 view .LVU2287
	.loc 1 6646 5 view .LVU2288
.LBB1597:
.LBI1597:
	.loc 1 28929 16 view .LVU2289
.LBB1598:
	.loc 1 28931 5 view .LVU2290
	.loc 1 28935 5 view .LVU2291
	.loc 1 28935 5 is_stmt 0 view .LVU2292
.LBE1598:
.LBE1597:
	.loc 1 6646 17 view .LVU2293
	movl	$4, %esi
	call	ma_log_postf.constprop.0
.LVL676:
	.loc 1 6652 13 is_stmt 1 view .LVU2294
	.loc 1 6653 13 view .LVU2295
	.loc 1 6655 5 view .LVU2296
	.loc 1 6655 26 is_stmt 0 view .LVU2297
	movq	%r12, %rdi
	movl	$.LC61, %esi
	call	dlsym
.LVL677:
	movq	%rax, %r12
.LVL678:
	.loc 1 6657 13 is_stmt 1 view .LVU2298
	.loc 1 6661 5 view .LVU2299
	testq	%rax, %rax
	je	.L667
.LVL679:
.L617:
	.loc 1 6665 5 view .LVU2300
	.loc 1 6666 5 view .LVU2301
	.loc 1 6666 5 is_stmt 0 view .LVU2302
.LBE1603:
.LBE1605:
.LBB1606:
.LBB1607:
	.loc 1 6646 17 view .LVU2303
	movq	112(%rbx), %rdi
	movl	$.LC62, %ecx
	movl	$.LC64, %edx
	xorl	%eax, %eax
.LBE1607:
.LBE1606:
	.loc 1 19519 50 view .LVU2304
	movq	%r12, 536(%rbx)
	.loc 1 19520 5 is_stmt 1 view .LVU2305
	.loc 1 19520 69 is_stmt 0 view .LVU2306
	movq	424(%rbx), %r12
.LVL680:
.LBB1616:
.LBI1606:
	.loc 1 6642 16 is_stmt 1 view .LVU2307
.LBB1614:
	.loc 1 6644 5 view .LVU2308
	.loc 1 6646 5 view .LVU2309
.LBB1608:
.LBI1608:
	.loc 1 28929 16 view .LVU2310
.LBB1609:
	.loc 1 28931 5 view .LVU2311
	.loc 1 28935 5 view .LVU2312
	.loc 1 28935 5 is_stmt 0 view .LVU2313
.LBE1609:
.LBE1608:
	.loc 1 6646 17 view .LVU2314
	movl	$4, %esi
	call	ma_log_postf.constprop.0
.LVL681:
	.loc 1 6652 13 is_stmt 1 view .LVU2315
	.loc 1 6653 13 view .LVU2316
	.loc 1 6655 5 view .LVU2317
	.loc 1 6655 26 is_stmt 0 view .LVU2318
	movq	%r12, %rdi
	movl	$.LC62, %esi
	call	dlsym
.LVL682:
	movq	%rax, %r12
.LVL683:
	.loc 1 6657 13 is_stmt 1 view .LVU2319
	.loc 1 6661 5 view .LVU2320
	testq	%rax, %rax
	je	.L668
.LVL684:
.L618:
	.loc 1 6665 5 view .LVU2321
	.loc 1 6666 5 view .LVU2322
	.loc 1 6666 5 is_stmt 0 view .LVU2323
.LBE1614:
.LBE1616:
.LBB1617:
.LBB1618:
	.loc 1 6646 17 view .LVU2324
	movq	112(%rbx), %rdi
	movl	$.LC63, %ecx
	movl	$.LC64, %edx
	xorl	%eax, %eax
.LBE1618:
.LBE1617:
	.loc 1 19520 50 view .LVU2325
	movq	%r12, 544(%rbx)
	.loc 1 19521 5 is_stmt 1 view .LVU2326
	.loc 1 19521 69 is_stmt 0 view .LVU2327
	movq	424(%rbx), %r12
.LVL685:
.LBB1627:
.LBI1617:
	.loc 1 6642 16 is_stmt 1 view .LVU2328
.LBB1625:
	.loc 1 6644 5 view .LVU2329
	.loc 1 6646 5 view .LVU2330
.LBB1619:
.LBI1619:
	.loc 1 28929 16 view .LVU2331
.LBB1620:
	.loc 1 28931 5 view .LVU2332
	.loc 1 28935 5 view .LVU2333
	.loc 1 28935 5 is_stmt 0 view .LVU2334
.LBE1620:
.LBE1619:
	.loc 1 6646 17 view .LVU2335
	movl	$4, %esi
	call	ma_log_postf.constprop.0
.LVL686:
	.loc 1 6652 13 is_stmt 1 view .LVU2336
	.loc 1 6653 13 view .LVU2337
	.loc 1 6655 5 view .LVU2338
	.loc 1 6655 26 is_stmt 0 view .LVU2339
	movq	%r12, %rdi
	movl	$.LC63, %esi
	call	dlsym
.LVL687:
	movq	%rax, %r12
.LVL688:
	.loc 1 6657 13 is_stmt 1 view .LVU2340
	.loc 1 6661 5 view .LVU2341
	testq	%rax, %rax
	je	.L669
.LVL689:
.L619:
	.loc 1 6665 5 view .LVU2342
	.loc 1 6666 5 view .LVU2343
	.loc 1 6666 5 is_stmt 0 view .LVU2344
.LBE1625:
.LBE1627:
	.loc 1 19562 23 view .LVU2345
	movq	-88(%rbp), %rax
	.loc 1 19521 50 view .LVU2346
	movq	%r12, 552(%rbx)
	.loc 1 19562 5 is_stmt 1 view .LVU2347
	.loc 1 19562 23 is_stmt 0 view .LVU2348
	movq	112(%rax), %r12
	.loc 1 19562 5 view .LVU2349
	testq	%r12, %r12
	jne	.L670
.L628:
	.loc 1 19565 5 is_stmt 1 view .LVU2350
	.loc 1 19565 51 is_stmt 0 view .LVU2351
	movq	-88(%rbp), %rax
.LBB1628:
	.loc 1 19573 56 view .LVU2352
	leaq	-72(%rbp), %rsi
	movq	%rbx, %rdi
.LBE1628:
	.loc 1 19565 51 view .LVU2353
	movl	120(%rax), %eax
	.loc 1 19565 35 view .LVU2354
	movl	%eax, 568(%rbx)
	.loc 1 19571 5 is_stmt 1 view .LVU2355
.LBB1631:
	.loc 1 19572 9 view .LVU2356
	.loc 1 19573 9 view .LVU2357
	.loc 1 19573 56 is_stmt 0 view .LVU2358
	call	_ZL28ma_context_open_client__jackP10ma_contextPP16ma_jack_client_t
.LVL690:
	movl	%eax, %r12d
.LVL691:
	.loc 1 19574 9 is_stmt 1 view .LVU2359
	testl	%eax, %eax
	jne	.L671
	.loc 1 19582 9 view .LVU2360
	.loc 1 19582 70 is_stmt 0 view .LVU2361
	movq	-72(%rbp), %rdi
	call	*440(%rbx)
.LVL692:
	.loc 1 19582 70 view .LVU2362
.LBE1631:
	.loc 1 19586 5 is_stmt 1 view .LVU2363
	.loc 1 19587 5 view .LVU2364
	.loc 1 19588 5 view .LVU2365
	.loc 1 19589 5 view .LVU2366
	.loc 1 19590 5 view .LVU2367
	.loc 1 19591 5 view .LVU2368
	.loc 1 19592 5 view .LVU2369
	.loc 1 19593 5 view .LVU2370
	.loc 1 19586 43 is_stmt 0 view .LVU2371
	movl	$_ZL21ma_context_init__jackP10ma_contextPK17ma_context_configP20ma_backend_callbacks.lto_priv.0, %eax
	.loc 1 19596 43 view .LVU2372
	movq	$0, 80(%r13)
	.loc 1 19586 43 view .LVU2373
	movq	%rax, %xmm0
	movl	$_ZL34ma_context_enumerate_devices__jackP10ma_contextPFjS0_14ma_device_typePK14ma_device_infoPvES5_, %eax
	movhps	.LC66(%rip), %xmm0
	movups	%xmm0, 0(%r13)
	movq	%rax, %xmm0
	movl	$_ZL20ma_device_init__jackP9ma_devicePK16ma_device_configP20ma_device_descriptorS5_, %eax
	movhps	.LC67(%rip), %xmm0
	movups	%xmm0, 16(%r13)
	movq	%rax, %xmm0
	movl	$_ZL21ma_device_start__jackP9ma_device, %eax
	movhps	.LC68(%rip), %xmm0
	movups	%xmm0, 32(%r13)
	movq	%rax, %xmm0
	movhps	.LC69(%rip), %xmm0
	movups	%xmm0, 48(%r13)
	.loc 1 19594 5 is_stmt 1 view .LVU2374
	.loc 1 19595 5 view .LVU2375
	.loc 1 19594 43 is_stmt 0 view .LVU2376
	pxor	%xmm0, %xmm0
	movups	%xmm0, 64(%r13)
	.loc 1 19596 5 is_stmt 1 view .LVU2377
	.loc 1 19598 5 view .LVU2378
.LVL693:
.L599:
	.loc 1 19599 1 is_stmt 0 view .LVU2379
	addq	$56, %rsp
	movl	%r12d, %eax
	popq	%rbx
.LVL694:
	.loc 1 19599 1 view .LVU2380
	popq	%r12
	popq	%r13
.LVL695:
	.loc 1 19599 1 view .LVU2381
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL696:
	.p2align 4,,10
	.p2align 3
.L653:
	.cfi_restore_state
.LBB1632:
.LBB1449:
.LBB1443:
.LBI1443:
	.loc 1 6596 18 is_stmt 1 view .LVU2382
.LBB1444:
	.loc 1 6624 9 view .LVU2383
.LBB1445:
.LBI1445:
	.loc 1 28929 16 view .LVU2384
.LBB1446:
	.loc 1 28931 5 view .LVU2385
	.loc 1 28935 5 view .LVU2386
	.loc 1 28935 22 is_stmt 0 view .LVU2387
	movq	112(%rbx), %r12
.LVL697:
.L644:
	.loc 1 28935 22 view .LVU2388
.LBE1446:
.LBE1445:
	.loc 1 6624 21 view .LVU2389
	movq	%r14, %rcx
	movl	$.LC46, %edx
	movl	$3, %esi
	movq	%r12, %rdi
	xorl	%eax, %eax
.LBE1444:
.LBE1443:
.LBE1449:
.LBE1632:
	.loc 1 19495 19 view .LVU2390
	addq	$8, %r15
.LBB1633:
.LBB1450:
.LBB1448:
.LBB1447:
	.loc 1 6624 21 view .LVU2391
	call	ma_log_postf
.LVL698:
.LBE1447:
.LBE1448:
	.loc 1 6627 5 is_stmt 1 view .LVU2392
	.loc 1 6628 5 view .LVU2393
	.loc 1 6628 5 is_stmt 0 view .LVU2394
.LBE1450:
.LBE1633:
	.loc 1 19495 19 view .LVU2395
	leaq	-48(%rbp), %rax
	.loc 1 19496 31 view .LVU2396
	movq	$0, 424(%rbx)
	.loc 1 19497 9 is_stmt 1 view .LVU2397
	.loc 1 19495 5 view .LVU2398
	.loc 1 19495 19 view .LVU2399
	cmpq	%r15, %rax
	jne	.L603
	.loc 1 19503 16 is_stmt 0 view .LVU2400
	movl	$-103, %r12d
	jmp	.L599
	.p2align 4,,10
	.p2align 3
.L670:
	.loc 1 19563 9 is_stmt 1 view .LVU2401
.LVL699:
.LBB1634:
.LBI1634:
	.loc 1 1207 14 view .LVU2402
.LBB1635:
	.loc 1 1209 5 view .LVU2403
	.loc 1 1210 5 view .LVU2404
	.loc 1 1212 5 view .LVU2405
	.loc 1 1216 5 view .LVU2406
	.loc 1 1216 16 is_stmt 0 view .LVU2407
	movq	%r12, %rdi
	call	strlen
.LVL700:
	.loc 1 1216 8 view .LVU2408
	leaq	1(%rax), %r15
.LVL701:
	.loc 1 1217 5 is_stmt 1 view .LVU2409
.LBB1636:
.LBI1636:
	.loc 1 44050 14 view .LVU2410
.LBB1637:
	.loc 1 44052 5 view .LVU2411
	.loc 1 44053 9 view .LVU2412
	.loc 1 44053 35 is_stmt 0 view .LVU2413
	movq	296(%rbx), %rax
	.loc 1 44053 9 view .LVU2414
	testq	%rax, %rax
	je	.L620
	.loc 1 44054 13 is_stmt 1 view .LVU2415
	.loc 1 44054 50 is_stmt 0 view .LVU2416
	movq	%r15, %rdi
	movq	288(%rbx), %rsi
	call	*%rax
.LVL702:
	movq	%rax, %rdi
.LVL703:
	.loc 1 44054 50 view .LVU2417
.LBE1637:
.LBE1636:
	.loc 1 1218 5 is_stmt 1 view .LVU2418
	testq	%rax, %rax
	je	.L620
	movq	%rax, %rdx
	leaq	(%rdi,%r15), %rsi
	movq	%r12, %rax
.LVL704:
	.p2align 4,,10
	.p2align 3
.L623:
.LBB1638:
.LBB1639:
.LBB1640:
.LBB1641:
	.loc 1 934 44 is_stmt 0 view .LVU2419
	movzbl	(%rax), %ecx
	.loc 1 934 36 view .LVU2420
	testb	%cl, %cl
	je	.L621
	.loc 1 935 16 view .LVU2421
	movb	%cl, (%rdx)
.LVL705:
	.loc 1 934 36 view .LVU2422
	addq	$1, %rdx
.LVL706:
	.loc 1 934 36 view .LVU2423
	addq	$1, %rax
	cmpq	%rdx, %rsi
	jne	.L623
	.loc 1 943 12 view .LVU2424
	movb	$0, (%rdi)
.LVL707:
.L625:
	.loc 1 943 12 view .LVU2425
.LBE1641:
.LBE1640:
.LBE1639:
.LBE1638:
.LBE1635:
.LBE1634:
	.loc 1 19563 36 view .LVU2426
	movq	%rdi, 560(%rbx)
	jmp	.L628
.LVL708:
	.p2align 4,,10
	.p2align 3
.L669:
.LBB1647:
.LBB1626:
.LBB1621:
.LBI1621:
	.loc 1 6642 16 is_stmt 1 view .LVU2427
.LBB1622:
	.loc 1 6662 9 view .LVU2428
.LBB1623:
.LBI1623:
	.loc 1 28929 16 view .LVU2429
.LBB1624:
	.loc 1 28931 5 view .LVU2430
	.loc 1 28935 5 view .LVU2431
	.loc 1 28935 5 is_stmt 0 view .LVU2432
.LBE1624:
.LBE1623:
	.loc 1 6662 21 view .LVU2433
	movq	112(%rbx), %rdi
	movl	$.LC63, %ecx
	movl	$.LC48, %edx
	xorl	%eax, %eax
.LVL709:
	.loc 1 6662 21 view .LVU2434
	movl	$2, %esi
	call	ma_log_postf
.LVL710:
	jmp	.L619
.LVL711:
	.p2align 4,,10
	.p2align 3
.L668:
	.loc 1 6662 21 view .LVU2435
.LBE1622:
.LBE1621:
.LBE1626:
.LBE1647:
.LBB1648:
.LBB1615:
.LBB1610:
.LBI1610:
	.loc 1 6642 16 is_stmt 1 view .LVU2436
.LBB1611:
	.loc 1 6662 9 view .LVU2437
.LBB1612:
.LBI1612:
	.loc 1 28929 16 view .LVU2438
.LBB1613:
	.loc 1 28931 5 view .LVU2439
	.loc 1 28935 5 view .LVU2440
	.loc 1 28935 5 is_stmt 0 view .LVU2441
.LBE1613:
.LBE1612:
	.loc 1 6662 21 view .LVU2442
	movq	112(%rbx), %rdi
	movl	$.LC62, %ecx
	movl	$.LC48, %edx
	xorl	%eax, %eax
.LVL712:
	.loc 1 6662 21 view .LVU2443
	movl	$2, %esi
	call	ma_log_postf
.LVL713:
	jmp	.L618
.LVL714:
	.p2align 4,,10
	.p2align 3
.L667:
	.loc 1 6662 21 view .LVU2444
.LBE1611:
.LBE1610:
.LBE1615:
.LBE1648:
.LBB1649:
.LBB1604:
.LBB1599:
.LBI1599:
	.loc 1 6642 16 is_stmt 1 view .LVU2445
.LBB1600:
	.loc 1 6662 9 view .LVU2446
.LBB1601:
.LBI1601:
	.loc 1 28929 16 view .LVU2447
.LBB1602:
	.loc 1 28931 5 view .LVU2448
	.loc 1 28935 5 view .LVU2449
	.loc 1 28935 5 is_stmt 0 view .LVU2450
.LBE1602:
.LBE1601:
	.loc 1 6662 21 view .LVU2451
	movq	112(%rbx), %rdi
	movl	$.LC61, %ecx
	movl	$.LC48, %edx
	xorl	%eax, %eax
.LVL715:
	.loc 1 6662 21 view .LVU2452
	movl	$2, %esi
	call	ma_log_postf
.LVL716:
	jmp	.L617
.LVL717:
	.p2align 4,,10
	.p2align 3
.L666:
	.loc 1 6662 21 view .LVU2453
.LBE1600:
.LBE1599:
.LBE1604:
.LBE1649:
.LBB1650:
.LBB1593:
.LBB1588:
.LBI1588:
	.loc 1 6642 16 is_stmt 1 view .LVU2454
.LBB1589:
	.loc 1 6662 9 view .LVU2455
.LBB1590:
.LBI1590:
	.loc 1 28929 16 view .LVU2456
.LBB1591:
	.loc 1 28931 5 view .LVU2457
	.loc 1 28935 5 view .LVU2458
	.loc 1 28935 5 is_stmt 0 view .LVU2459
.LBE1591:
.LBE1590:
	.loc 1 6662 21 view .LVU2460
	movq	112(%rbx), %rdi
	movl	$.LC60, %ecx
	movl	$.LC48, %edx
	xorl	%eax, %eax
.LVL718:
	.loc 1 6662 21 view .LVU2461
	movl	$2, %esi
	call	ma_log_postf
.LVL719:
	jmp	.L616
.LVL720:
	.p2align 4,,10
	.p2align 3
.L665:
	.loc 1 6662 21 view .LVU2462
.LBE1589:
.LBE1588:
.LBE1593:
.LBE1650:
.LBB1651:
.LBB1582:
.LBB1577:
.LBI1577:
	.loc 1 6642 16 is_stmt 1 view .LVU2463
.LBB1578:
	.loc 1 6662 9 view .LVU2464
.LBB1579:
.LBI1579:
	.loc 1 28929 16 view .LVU2465
.LBB1580:
	.loc 1 28931 5 view .LVU2466
	.loc 1 28935 5 view .LVU2467
	.loc 1 28935 5 is_stmt 0 view .LVU2468
.LBE1580:
.LBE1579:
	.loc 1 6662 21 view .LVU2469
	movq	112(%rbx), %rdi
	movl	$.LC59, %ecx
	movl	$.LC48, %edx
	xorl	%eax, %eax
.LVL721:
	.loc 1 6662 21 view .LVU2470
	movl	$2, %esi
	call	ma_log_postf
.LVL722:
	jmp	.L615
.LVL723:
	.p2align 4,,10
	.p2align 3
.L664:
	.loc 1 6662 21 view .LVU2471
.LBE1578:
.LBE1577:
.LBE1582:
.LBE1651:
.LBB1652:
.LBB1571:
.LBB1566:
.LBI1566:
	.loc 1 6642 16 is_stmt 1 view .LVU2472
.LBB1567:
	.loc 1 6662 9 view .LVU2473
.LBB1568:
.LBI1568:
	.loc 1 28929 16 view .LVU2474
.LBB1569:
	.loc 1 28931 5 view .LVU2475
	.loc 1 28935 5 view .LVU2476
	.loc 1 28935 5 is_stmt 0 view .LVU2477
.LBE1569:
.LBE1568:
	.loc 1 6662 21 view .LVU2478
	movq	112(%rbx), %rdi
	movl	$.LC58, %ecx
	movl	$.LC48, %edx
	xorl	%eax, %eax
.LVL724:
	.loc 1 6662 21 view .LVU2479
	movl	$2, %esi
	call	ma_log_postf
.LVL725:
	jmp	.L614
.LVL726:
	.p2align 4,,10
	.p2align 3
.L663:
	.loc 1 6662 21 view .LVU2480
.LBE1567:
.LBE1566:
.LBE1571:
.LBE1652:
.LBB1653:
.LBB1560:
.LBB1555:
.LBI1555:
	.loc 1 6642 16 is_stmt 1 view .LVU2481
.LBB1556:
	.loc 1 6662 9 view .LVU2482
.LBB1557:
.LBI1557:
	.loc 1 28929 16 view .LVU2483
.LBB1558:
	.loc 1 28931 5 view .LVU2484
	.loc 1 28935 5 view .LVU2485
	.loc 1 28935 5 is_stmt 0 view .LVU2486
.LBE1558:
.LBE1557:
	.loc 1 6662 21 view .LVU2487
	movq	112(%rbx), %rdi
	movl	$.LC57, %ecx
	movl	$.LC48, %edx
	xorl	%eax, %eax
.LVL727:
	.loc 1 6662 21 view .LVU2488
	movl	$2, %esi
	call	ma_log_postf
.LVL728:
	jmp	.L613
.LVL729:
	.p2align 4,,10
	.p2align 3
.L662:
	.loc 1 6662 21 view .LVU2489
.LBE1556:
.LBE1555:
.LBE1560:
.LBE1653:
.LBB1654:
.LBB1549:
.LBB1544:
.LBI1544:
	.loc 1 6642 16 is_stmt 1 view .LVU2490
.LBB1545:
	.loc 1 6662 9 view .LVU2491
.LBB1546:
.LBI1546:
	.loc 1 28929 16 view .LVU2492
.LBB1547:
	.loc 1 28931 5 view .LVU2493
	.loc 1 28935 5 view .LVU2494
	.loc 1 28935 5 is_stmt 0 view .LVU2495
.LBE1547:
.LBE1546:
	.loc 1 6662 21 view .LVU2496
	movq	112(%rbx), %rdi
	movl	$.LC56, %ecx
	movl	$.LC48, %edx
	xorl	%eax, %eax
.LVL730:
	.loc 1 6662 21 view .LVU2497
	movl	$2, %esi
	call	ma_log_postf
.LVL731:
	jmp	.L612
.LVL732:
	.p2align 4,,10
	.p2align 3
.L661:
	.loc 1 6662 21 view .LVU2498
.LBE1545:
.LBE1544:
.LBE1549:
.LBE1654:
.LBB1655:
.LBB1538:
.LBB1533:
.LBI1533:
	.loc 1 6642 16 is_stmt 1 view .LVU2499
.LBB1534:
	.loc 1 6662 9 view .LVU2500
.LBB1535:
.LBI1535:
	.loc 1 28929 16 view .LVU2501
.LBB1536:
	.loc 1 28931 5 view .LVU2502
	.loc 1 28935 5 view .LVU2503
	.loc 1 28935 5 is_stmt 0 view .LVU2504
.LBE1536:
.LBE1535:
	.loc 1 6662 21 view .LVU2505
	movq	112(%rbx), %rdi
	movl	$.LC55, %ecx
	movl	$.LC48, %edx
	xorl	%eax, %eax
.LVL733:
	.loc 1 6662 21 view .LVU2506
	movl	$2, %esi
	call	ma_log_postf
.LVL734:
	jmp	.L611
.LVL735:
	.p2align 4,,10
	.p2align 3
.L660:
	.loc 1 6662 21 view .LVU2507
.LBE1534:
.LBE1533:
.LBE1538:
.LBE1655:
.LBB1656:
.LBB1527:
.LBB1522:
.LBI1522:
	.loc 1 6642 16 is_stmt 1 view .LVU2508
.LBB1523:
	.loc 1 6662 9 view .LVU2509
.LBB1524:
.LBI1524:
	.loc 1 28929 16 view .LVU2510
.LBB1525:
	.loc 1 28931 5 view .LVU2511
	.loc 1 28935 5 view .LVU2512
	.loc 1 28935 5 is_stmt 0 view .LVU2513
.LBE1525:
.LBE1524:
	.loc 1 6662 21 view .LVU2514
	movq	112(%rbx), %rdi
	movl	$.LC54, %ecx
	movl	$.LC48, %edx
	xorl	%eax, %eax
.LVL736:
	.loc 1 6662 21 view .LVU2515
	movl	$2, %esi
	call	ma_log_postf
.LVL737:
	jmp	.L610
.LVL738:
	.p2align 4,,10
	.p2align 3
.L659:
	.loc 1 6662 21 view .LVU2516
.LBE1523:
.LBE1522:
.LBE1527:
.LBE1656:
.LBB1657:
.LBB1516:
.LBB1511:
.LBI1511:
	.loc 1 6642 16 is_stmt 1 view .LVU2517
.LBB1512:
	.loc 1 6662 9 view .LVU2518
.LBB1513:
.LBI1513:
	.loc 1 28929 16 view .LVU2519
.LBB1514:
	.loc 1 28931 5 view .LVU2520
	.loc 1 28935 5 view .LVU2521
	.loc 1 28935 5 is_stmt 0 view .LVU2522
.LBE1514:
.LBE1513:
	.loc 1 6662 21 view .LVU2523
	movq	112(%rbx), %rdi
	movl	$.LC53, %ecx
	movl	$.LC48, %edx
	xorl	%eax, %eax
.LVL739:
	.loc 1 6662 21 view .LVU2524
	movl	$2, %esi
	call	ma_log_postf
.LVL740:
	jmp	.L609
.LVL741:
	.p2align 4,,10
	.p2align 3
.L658:
	.loc 1 6662 21 view .LVU2525
.LBE1512:
.LBE1511:
.LBE1516:
.LBE1657:
.LBB1658:
.LBB1505:
.LBB1500:
.LBI1500:
	.loc 1 6642 16 is_stmt 1 view .LVU2526
.LBB1501:
	.loc 1 6662 9 view .LVU2527
.LBB1502:
.LBI1502:
	.loc 1 28929 16 view .LVU2528
.LBB1503:
	.loc 1 28931 5 view .LVU2529
	.loc 1 28935 5 view .LVU2530
	.loc 1 28935 5 is_stmt 0 view .LVU2531
.LBE1503:
.LBE1502:
	.loc 1 6662 21 view .LVU2532
	movq	112(%rbx), %rdi
	movl	$.LC52, %ecx
	movl	$.LC48, %edx
	xorl	%eax, %eax
.LVL742:
	.loc 1 6662 21 view .LVU2533
	movl	$2, %esi
	call	ma_log_postf
.LVL743:
	jmp	.L608
.LVL744:
	.p2align 4,,10
	.p2align 3
.L657:
	.loc 1 6662 21 view .LVU2534
.LBE1501:
.LBE1500:
.LBE1505:
.LBE1658:
.LBB1659:
.LBB1494:
.LBB1489:
.LBI1489:
	.loc 1 6642 16 is_stmt 1 view .LVU2535
.LBB1490:
	.loc 1 6662 9 view .LVU2536
.LBB1491:
.LBI1491:
	.loc 1 28929 16 view .LVU2537
.LBB1492:
	.loc 1 28931 5 view .LVU2538
	.loc 1 28935 5 view .LVU2539
	.loc 1 28935 5 is_stmt 0 view .LVU2540
.LBE1492:
.LBE1491:
	.loc 1 6662 21 view .LVU2541
	movq	112(%rbx), %rdi
	movl	$.LC51, %ecx
	movl	$.LC48, %edx
	xorl	%eax, %eax
.LVL745:
	.loc 1 6662 21 view .LVU2542
	movl	$2, %esi
	call	ma_log_postf
.LVL746:
	jmp	.L607
.LVL747:
	.p2align 4,,10
	.p2align 3
.L656:
	.loc 1 6662 21 view .LVU2543
.LBE1490:
.LBE1489:
.LBE1494:
.LBE1659:
.LBB1660:
.LBB1483:
.LBB1478:
.LBI1478:
	.loc 1 6642 16 is_stmt 1 view .LVU2544
.LBB1479:
	.loc 1 6662 9 view .LVU2545
.LBB1480:
.LBI1480:
	.loc 1 28929 16 view .LVU2546
.LBB1481:
	.loc 1 28931 5 view .LVU2547
	.loc 1 28935 5 view .LVU2548
	.loc 1 28935 5 is_stmt 0 view .LVU2549
.LBE1481:
.LBE1480:
	.loc 1 6662 21 view .LVU2550
	movq	112(%rbx), %rdi
	movl	$.LC50, %ecx
	movl	$.LC48, %edx
	xorl	%eax, %eax
.LVL748:
	.loc 1 6662 21 view .LVU2551
	movl	$2, %esi
	call	ma_log_postf
.LVL749:
	jmp	.L606
.LVL750:
	.p2align 4,,10
	.p2align 3
.L655:
	.loc 1 6662 21 view .LVU2552
.LBE1479:
.LBE1478:
.LBE1483:
.LBE1660:
.LBB1661:
.LBB1472:
.LBB1467:
.LBI1467:
	.loc 1 6642 16 is_stmt 1 view .LVU2553
.LBB1468:
	.loc 1 6662 9 view .LVU2554
.LBB1469:
.LBI1469:
	.loc 1 28929 16 view .LVU2555
.LBB1470:
	.loc 1 28931 5 view .LVU2556
	.loc 1 28935 5 view .LVU2557
	.loc 1 28935 5 is_stmt 0 view .LVU2558
.LBE1470:
.LBE1469:
	.loc 1 6662 21 view .LVU2559
	movq	112(%rbx), %rdi
	movl	$.LC49, %ecx
	movl	$.LC48, %edx
	xorl	%eax, %eax
.LVL751:
	.loc 1 6662 21 view .LVU2560
	movl	$2, %esi
	call	ma_log_postf
.LVL752:
	jmp	.L605
.LVL753:
	.p2align 4,,10
	.p2align 3
.L654:
	.loc 1 6662 21 view .LVU2561
.LBE1468:
.LBE1467:
.LBE1472:
.LBE1661:
.LBB1662:
.LBB1461:
.LBB1456:
.LBI1456:
	.loc 1 6642 16 is_stmt 1 view .LVU2562
.LBB1457:
	.loc 1 6662 9 view .LVU2563
.LBB1458:
.LBI1458:
	.loc 1 28929 16 view .LVU2564
.LBB1459:
	.loc 1 28931 5 view .LVU2565
	.loc 1 28935 5 view .LVU2566
	.loc 1 28935 5 is_stmt 0 view .LVU2567
.LBE1459:
.LBE1458:
	.loc 1 6662 21 view .LVU2568
	movq	112(%rbx), %rdi
	movl	$.LC47, %ecx
	movl	$.LC48, %edx
	xorl	%eax, %eax
.LVL754:
	.loc 1 6662 21 view .LVU2569
	movl	$2, %esi
	call	ma_log_postf
.LVL755:
	jmp	.L604
.LVL756:
	.p2align 4,,10
	.p2align 3
.L600:
	.loc 1 6662 21 view .LVU2570
.LBE1457:
.LBE1456:
.LBE1461:
.LBE1662:
.LBB1663:
.LBB1451:
	.loc 1 6600 17 view .LVU2571
	movq	%r14, %rcx
	movl	$.LC45, %edx
	movl	$4, %esi
	xorl	%edi, %edi
	xorl	%eax, %eax
	call	ma_log_postf.constprop.0
.LVL757:
	.loc 1 6616 5 is_stmt 1 view .LVU2572
	.loc 1 6616 31 is_stmt 0 view .LVU2573
	movl	$2, %esi
	movq	%r14, %rdi
	call	dlopen
.LVL758:
	movq	%rax, %r12
.LVL759:
	.loc 1 6623 5 is_stmt 1 view .LVU2574
	testq	%rax, %rax
	jne	.L601
	jmp	.L644
.LVL760:
	.p2align 4,,10
	.p2align 3
.L621:
	.loc 1 6623 5 is_stmt 0 view .LVU2575
.LBE1451:
.LBE1663:
.LBB1664:
.LBB1646:
.LBB1645:
.LBB1644:
.LBB1643:
.LBB1642:
	.loc 1 939 16 view .LVU2576
	movb	$0, (%rdx)
	.loc 1 940 16 view .LVU2577
	jmp	.L625
.LVL761:
	.p2align 4,,10
	.p2align 3
.L620:
	.loc 1 940 16 view .LVU2578
.LBE1642:
.LBE1643:
.LBE1644:
.LBE1645:
	.loc 1 1219 16 view .LVU2579
	xorl	%edi, %edi
	jmp	.L625
.LVL762:
.L671:
	.loc 1 1219 16 view .LVU2580
.LBE1646:
.LBE1664:
.LBB1665:
	.loc 1 19575 13 is_stmt 1 view .LVU2581
	.loc 1 19575 20 is_stmt 0 view .LVU2582
	movq	560(%rbx), %rdi
	.loc 1 19575 49 view .LVU2583
	leaq	288(%rbx), %rsi
	.loc 1 19579 20 view .LVU2584
	movl	$-103, %r12d
	.loc 1 19575 20 view .LVU2585
	call	ma_free
.LVL763:
	.loc 1 19577 13 is_stmt 1 view .LVU2586
.LBB1629:
.LBI1629:
	.loc 1 6631 13 view .LVU2587
.LBB1630:
	.loc 1 6636 5 view .LVU2588
	.loc 1 6636 12 is_stmt 0 view .LVU2589
	movq	424(%rbx), %rdi
	call	dlclose
.LVL764:
	.loc 1 6639 5 is_stmt 1 view .LVU2590
	.loc 1 6639 5 is_stmt 0 view .LVU2591
.LBE1630:
.LBE1629:
	.loc 1 19579 13 is_stmt 1 view .LVU2592
	jmp	.L599
.LBE1665:
	.cfi_endproc
.LFE97:
	.size	_ZL21ma_context_init__jackP10ma_contextPK17ma_context_configP20ma_backend_callbacks.lto_priv.0, .-_ZL21ma_context_init__jackP10ma_contextPK17ma_context_configP20ma_backend_callbacks.lto_priv.0
	.p2align 4
	.globl	_ZL38ma_job_process__device__aaudio_rerouteP6ma_job.lto_priv.0
	.hidden	_ZL38ma_job_process__device__aaudio_rerouteP6ma_job.lto_priv.0
	.type	_ZL38ma_job_process__device__aaudio_rerouteP6ma_job.lto_priv.0, @function
_ZL38ma_job_process__device__aaudio_rerouteP6ma_job.lto_priv.0:
.LVL765:
.LFB103:
	.loc 1 26102 1 view -0
	.cfi_startproc
	.loc 1 26102 1 is_stmt 0 view .LVU2594
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
1:	call	mcount
	.loc 1 26102 1 view .LVU2595
	.loc 1 26103 5 is_stmt 1 view .LVU2596
.LVL766:
.LBB1666:
.LBI1666:
	.loc 1 5640 18 view .LVU2597
.LBB1667:
	.loc 1 5642 5 view .LVU2598
	testq	%rdi, %rdi
	je	.L674
	.loc 1 5645 5 view .LVU2599
	.loc 1 5647 5 view .LVU2600
.LVL767:
	.loc 1 5647 5 is_stmt 0 view .LVU2601
.LBE1667:
.LBE1666:
	.loc 1 26104 1 view .LVU2602
	xorl	%eax, %eax
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL768:
.L674:
	.cfi_restore_state
.LBB1669:
.LBB1668:
	.loc 1 26104 1 view .LVU2603
	call	_ZL20ma_job_process__noopP6ma_job.part.0.lto_priv.0
.LVL769:
	.loc 1 26104 1 view .LVU2604
.LBE1668:
.LBE1669:
	.cfi_endproc
.LFE103:
	.size	_ZL38ma_job_process__device__aaudio_rerouteP6ma_job.lto_priv.0, .-_ZL38ma_job_process__device__aaudio_rerouteP6ma_job.lto_priv.0
	.section	.rodata.str1.1
.LC70:
	.string	"void* ma_worker_thread(void*)"
	.section	.rodata.str1.8
	.align 8
.LC71:
	.string	"ma_device_get_state(pDevice) == ma_device_state_starting"
	.text
	.p2align 4
	.type	_ZL16ma_worker_threadPv, @function
_ZL16ma_worker_threadPv:
.LVL770:
.LFB104:
	.loc 1 28274 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 28274 1 is_stmt 0 view .LVU2606
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
1:	call	mcount
	.loc 1 28274 1 view .LVU2607
	.loc 1 28275 5 is_stmt 1 view .LVU2608
.LVL771:
	.loc 1 28276 5 view .LVU2609
	.loc 1 28274 1 is_stmt 0 view .LVU2610
	movq	%rdi, %rbx
	.loc 1 28276 5 view .LVU2611
	testq	%rdi, %rdi
	je	.L716
	.loc 1 28288 5 is_stmt 1 view .LVU2612
.LVL772:
.LBB1726:
.LBI1726:
	.loc 1 7221 23 view .LVU2613
.LBB1727:
	.loc 1 7223 5 view .LVU2614
	leaq	16(%rdi), %r14
	movl	$1, %eax
	xchgl	(%r14), %eax
.LVL773:
	.loc 1 7223 5 is_stmt 0 view .LVU2615
.LBE1727:
.LBE1726:
	.loc 1 28289 5 is_stmt 1 view .LVU2616
.LBB1728:
.LBI1728:
	.loc 1 4915 18 view .LVU2617
.LBE1728:
	.loc 1 4917 5 view .LVU2618
	.loc 1 4926 5 view .LVU2619
.LBB1735:
.LBB1729:
.LBI1729:
	.loc 1 4606 18 view .LVU2620
.LBB1730:
	.loc 1 4608 5 view .LVU2621
	.loc 1 4608 42 is_stmt 0 view .LVU2622
	leaq	296(%rdi), %r15
.LBE1730:
.LBE1729:
.LBE1735:
.LBB1736:
.LBB1737:
.LBB1738:
.LBB1739:
.LBB1740:
	.loc 1 4594 42 view .LVU2623
	leaq	104(%rbx), %r12
.LBE1740:
.LBE1739:
.LBE1738:
.LBE1737:
.LBE1736:
.LBB1812:
.LBB1733:
.LBB1731:
	.loc 1 4608 23 view .LVU2624
	movq	%r15, %rdi
.LVL774:
	.loc 1 4608 42 view .LVU2625
	movq	%r15, -80(%rbp)
.LBE1731:
.LBE1733:
.LBE1812:
.LBB1813:
.LBB1803:
.LBB1745:
.LBB1743:
.LBB1741:
	.loc 1 4597 48 view .LVU2626
	leaq	144(%rbx), %r13
.LBE1741:
.LBE1743:
.LBE1745:
.LBE1803:
.LBE1813:
.LBB1814:
.LBB1734:
.LBB1732:
	.loc 1 4608 23 view .LVU2627
	call	pthread_mutex_lock
.LVL775:
	.loc 1 4609 5 is_stmt 1 view .LVU2628
	.loc 1 4610 9 view .LVU2629
	.loc 1 4611 46 is_stmt 0 view .LVU2630
	leaq	336(%rbx), %rax
	.loc 1 4610 23 view .LVU2631
	movl	$1, 288(%rbx)
	.loc 1 4611 9 is_stmt 1 view .LVU2632
	.loc 1 4611 28 is_stmt 0 view .LVU2633
	movq	%rax, %rdi
	.loc 1 4611 46 view .LVU2634
	movq	%rax, -88(%rbp)
	.loc 1 4611 28 view .LVU2635
	call	pthread_cond_signal
.LVL776:
	.loc 1 4613 5 is_stmt 1 view .LVU2636
	.loc 1 4613 25 is_stmt 0 view .LVU2637
	movq	%r15, %rdi
	call	pthread_mutex_unlock
.LVL777:
	.loc 1 4615 5 is_stmt 1 view .LVU2638
	.p2align 4,,10
	.p2align 3
.L677:
	.loc 1 4615 5 is_stmt 0 view .LVU2639
.LBE1732:
.LBE1734:
.LBE1814:
	.loc 1 28291 5 is_stmt 1 view .LVU2640
.LBB1815:
.LBB1804:
	.loc 1 28292 9 view .LVU2641
	.loc 1 28293 9 view .LVU2642
	.loc 1 28296 9 view .LVU2643
.LBB1746:
.LBI1738:
	.loc 1 4900 18 view .LVU2644
.LBE1746:
.LBE1804:
.LBE1815:
	.loc 1 4902 5 view .LVU2645
	.loc 1 4911 5 view .LVU2646
.LBB1816:
.LBB1805:
.LBB1747:
.LBB1744:
.LBI1739:
	.loc 1 4592 18 view .LVU2647
.LBB1742:
	.loc 1 4594 5 view .LVU2648
	.loc 1 4594 23 is_stmt 0 view .LVU2649
	movq	%r12, %rdi
	call	pthread_mutex_lock
.LVL778:
	.loc 1 4595 5 is_stmt 1 view .LVU2650
	.loc 1 4596 9 view .LVU2651
	.loc 1 4596 30 view .LVU2652
	movl	96(%rbx), %edx
	testl	%edx, %edx
	jne	.L681
	.p2align 4,,10
	.p2align 3
.L682:
	.loc 1 4597 13 view .LVU2653
	.loc 1 4597 30 is_stmt 0 view .LVU2654
	movq	%r12, %rsi
	movq	%r13, %rdi
	call	pthread_cond_wait
.LVL779:
	.loc 1 4595 5 is_stmt 1 view .LVU2655
	.loc 1 4596 9 view .LVU2656
	.loc 1 4596 30 view .LVU2657
	movl	96(%rbx), %eax
	testl	%eax, %eax
	je	.L682
.L681:
	.loc 1 4599 9 view .LVU2658
	.loc 1 4599 23 is_stmt 0 view .LVU2659
	movl	$0, 96(%rbx)
	.loc 1 4601 5 is_stmt 1 view .LVU2660
	.loc 1 4601 25 is_stmt 0 view .LVU2661
	movq	%r12, %rdi
	call	pthread_mutex_unlock
.LVL780:
	.loc 1 4603 5 is_stmt 1 view .LVU2662
	.loc 1 4603 5 is_stmt 0 view .LVU2663
.LBE1742:
.LBE1744:
.LBE1747:
	.loc 1 28299 9 is_stmt 1 view .LVU2664
	.loc 1 28299 29 is_stmt 0 view .LVU2665
	movl	$0, 392(%rbx)
	.loc 1 28302 9 is_stmt 1 view .LVU2666
.LVL781:
.LBB1748:
.LBI1748:
	.loc 1 29890 24 view .LVU2667
.LBE1748:
.LBE1805:
.LBE1816:
	.loc 1 29892 5 view .LVU2668
.LBB1817:
.LBB1806:
.LBB1751:
.LBB1749:
.LBI1749:
	.loc 1 29890 24 view .LVU2669
.LBB1750:
	.loc 1 29896 5 view .LVU2670
	.loc 1 29896 29 is_stmt 0 view .LVU2671
	movl	(%r14), %eax
.LVL782:
	.loc 1 29896 29 view .LVU2672
.LBE1750:
.LBE1749:
.LBE1751:
	.loc 1 28302 9 view .LVU2673
	testl	%eax, %eax
	je	.L717
	.loc 1 28311 9 is_stmt 1 view .LVU2674
.LVL783:
.LBB1752:
.LBI1752:
	.loc 1 29890 24 view .LVU2675
.LBE1752:
.LBE1806:
.LBE1817:
	.loc 1 29892 5 view .LVU2676
.LBB1818:
.LBB1807:
.LBB1755:
.LBB1753:
.LBI1753:
	.loc 1 29890 24 view .LVU2677
.LBB1754:
	.loc 1 29896 5 view .LVU2678
	.loc 1 29896 29 is_stmt 0 view .LVU2679
	movl	(%r14), %eax
.LVL784:
	.loc 1 29896 29 view .LVU2680
.LBE1754:
.LBE1753:
.LBE1755:
	.loc 1 28311 9 view .LVU2681
	cmpl	$3, %eax
	jne	.L718
	.loc 1 28314 9 is_stmt 1 view .LVU2682
	.loc 1 28314 42 is_stmt 0 view .LVU2683
	movq	(%rbx), %rax
.LBB1756:
.LBB1757:
.LBB1758:
	.loc 1 4611 46 view .LVU2684
	leaq	240(%rbx), %rdx
	.loc 1 4608 42 view .LVU2685
	leaq	200(%rbx), %r15
	.loc 1 4611 46 view .LVU2686
	movq	%rdx, -72(%rbp)
.LBE1758:
.LBE1757:
.LBE1756:
	.loc 1 28314 42 view .LVU2687
	movq	48(%rax), %rax
	.loc 1 28314 9 view .LVU2688
	testq	%rax, %rax
	je	.L684
	.loc 1 28315 13 is_stmt 1 view .LVU2689
	.loc 1 28315 69 is_stmt 0 view .LVU2690
	movq	%rbx, %rdi
	call	*%rax
.LVL785:
	.loc 1 28324 9 is_stmt 1 view .LVU2691
	testl	%eax, %eax
	jne	.L719
.LVL786:
.L684:
	.loc 1 28331 9 view .LVU2692
.LBB1761:
.LBI1761:
	.loc 1 7221 23 view .LVU2693
.LBB1762:
	.loc 1 7223 5 view .LVU2694
	movl	$2, %eax
	xchgl	(%r14), %eax
.LVL787:
	.loc 1 7223 5 is_stmt 0 view .LVU2695
.LBE1762:
.LBE1761:
	.loc 1 28332 9 is_stmt 1 view .LVU2696
.LBB1763:
.LBI1763:
	.loc 1 4915 18 view .LVU2697
.LBE1763:
.LBE1807:
.LBE1818:
	.loc 1 4917 5 view .LVU2698
	.loc 1 4926 5 view .LVU2699
.LBB1819:
.LBB1808:
.LBB1766:
.LBB1764:
.LBI1764:
	.loc 1 4606 18 view .LVU2700
.LBB1765:
	.loc 1 4608 5 view .LVU2701
	.loc 1 4608 23 is_stmt 0 view .LVU2702
	movq	%r15, %rdi
	call	pthread_mutex_lock
.LVL788:
	.loc 1 4609 5 is_stmt 1 view .LVU2703
	.loc 1 4610 9 view .LVU2704
	.loc 1 4611 28 is_stmt 0 view .LVU2705
	leaq	240(%rbx), %rdi
	.loc 1 4610 23 view .LVU2706
	movl	$1, 192(%rbx)
	.loc 1 4611 9 is_stmt 1 view .LVU2707
	.loc 1 4611 28 is_stmt 0 view .LVU2708
	call	pthread_cond_signal
.LVL789:
	.loc 1 4613 5 is_stmt 1 view .LVU2709
	.loc 1 4613 25 is_stmt 0 view .LVU2710
	movq	%r15, %rdi
	call	pthread_mutex_unlock
.LVL790:
	.loc 1 4615 5 is_stmt 1 view .LVU2711
	.loc 1 4615 5 is_stmt 0 view .LVU2712
.LBE1765:
.LBE1764:
.LBE1766:
	.loc 1 28334 9 is_stmt 1 view .LVU2713
.LBB1767:
.LBI1767:
	.loc 1 6750 6 view .LVU2714
.LBB1768:
	.loc 1 6752 5 view .LVU2715
.LBB1769:
.LBI1769:
	.loc 1 6725 31 view .LVU2716
.LBB1770:
	.loc 1 6727 5 view .LVU2717
	.loc 1 6729 5 view .LVU2718
.LBB1771:
.LBI1771:
	.loc 1 776 23 view .LVU2719
.LBB1772:
	.loc 1 781 5 view .LVU2720
	.loc 1 782 9 view .LVU2721
.LBE1772:
.LBE1771:
.LBE1770:
.LBE1769:
.LBB1776:
.LBB1777:
	.loc 1 6740 31 is_stmt 0 view .LVU2722
	movq	32(%rbx), %rax
.LBE1777:
.LBE1776:
.LBB1779:
.LBB1775:
	.loc 1 6730 26 view .LVU2723
	movq	%rbx, -64(%rbp)
.LBB1774:
.LBB1773:
	.loc 1 782 15 view .LVU2724
	movl	$0, -52(%rbp)
.LVL791:
	.loc 1 782 15 view .LVU2725
.LBE1773:
.LBE1774:
	.loc 1 6730 5 is_stmt 1 view .LVU2726
	.loc 1 6731 5 view .LVU2727
	.loc 1 6731 26 is_stmt 0 view .LVU2728
	movl	$0, -56(%rbp)
	.loc 1 6733 5 is_stmt 1 view .LVU2729
.LVL792:
	.loc 1 6733 5 is_stmt 0 view .LVU2730
.LBE1775:
.LBE1779:
.LBB1780:
.LBI1776:
	.loc 1 6736 13 is_stmt 1 view .LVU2731
.LBB1778:
	.loc 1 6738 5 view .LVU2732
	.loc 1 6740 5 view .LVU2733
	testq	%rax, %rax
	je	.L686
	.loc 1 6741 9 view .LVU2734
	.loc 1 6741 45 is_stmt 0 view .LVU2735
	leaq	-64(%rbp), %rdi
	call	*%rax
.LVL793:
.L686:
	.loc 1 6745 5 is_stmt 1 view .LVU2736
	.loc 1 6745 22 is_stmt 0 view .LVU2737
	movq	-64(%rbp), %rdi
	.loc 1 6745 31 view .LVU2738
	movq	40(%rdi), %rax
	.loc 1 6745 5 view .LVU2739
	testq	%rax, %rax
	je	.L687
	.loc 1 6745 46 view .LVU2740
	cmpl	$1, -56(%rbp)
	jne	.L687
	.loc 1 6746 9 is_stmt 1 view .LVU2741
	.loc 1 6746 37 is_stmt 0 view .LVU2742
	call	*%rax
.LVL794:
.L687:
	.loc 1 6746 37 view .LVU2743
.LBE1778:
.LBE1780:
.LBE1768:
.LBE1767:
	.loc 1 28336 9 is_stmt 1 view .LVU2744
	.loc 1 28336 42 is_stmt 0 view .LVU2745
	movq	(%rbx), %rax
	.loc 1 28337 58 view .LVU2746
	movq	%rbx, %rdi
	.loc 1 28336 42 view .LVU2747
	movq	80(%rax), %rax
	.loc 1 28336 9 view .LVU2748
	testq	%rax, %rax
	je	.L688
	.loc 1 28337 13 is_stmt 1 view .LVU2749
	.loc 1 28337 58 is_stmt 0 view .LVU2750
	call	*%rax
.LVL795:
.L689:
	.loc 1 28344 9 is_stmt 1 view .LVU2751
	.loc 1 28344 42 is_stmt 0 view .LVU2752
	movq	(%rbx), %rax
	movq	56(%rax), %rax
	.loc 1 28344 9 view .LVU2753
	testq	%rax, %rax
	je	.L693
	.loc 1 28345 13 is_stmt 1 view .LVU2754
	.loc 1 28345 67 is_stmt 0 view .LVU2755
	movq	%rbx, %rdi
	call	*%rax
.LVL796:
	.loc 1 28355 9 is_stmt 1 view .LVU2756
	testl	%eax, %eax
	jne	.L694
.LVL797:
.L693:
	.loc 1 28356 13 view .LVU2757
.LBB1781:
.LBI1781:
	.loc 1 6755 6 view .LVU2758
.LBB1782:
	.loc 1 6757 5 view .LVU2759
.LBB1783:
.LBI1783:
	.loc 1 6725 31 view .LVU2760
.LBB1784:
	.loc 1 6727 5 view .LVU2761
	.loc 1 6729 5 view .LVU2762
.LBB1785:
.LBI1785:
	.loc 1 776 23 view .LVU2763
.LBB1786:
	.loc 1 781 5 view .LVU2764
	.loc 1 782 9 view .LVU2765
.LBE1786:
.LBE1785:
.LBE1784:
.LBE1783:
.LBB1790:
.LBB1791:
	.loc 1 6740 31 is_stmt 0 view .LVU2766
	movq	32(%rbx), %rax
.LBE1791:
.LBE1790:
.LBB1793:
.LBB1789:
.LBB1788:
.LBB1787:
	.loc 1 782 15 view .LVU2767
	movl	$0, -52(%rbp)
.LVL798:
	.loc 1 782 15 view .LVU2768
.LBE1787:
.LBE1788:
	.loc 1 6730 5 is_stmt 1 view .LVU2769
	.loc 1 6730 26 is_stmt 0 view .LVU2770
	movq	%rbx, -64(%rbp)
	.loc 1 6731 5 is_stmt 1 view .LVU2771
	.loc 1 6731 26 is_stmt 0 view .LVU2772
	movl	$1, -56(%rbp)
	.loc 1 6733 5 is_stmt 1 view .LVU2773
.LVL799:
	.loc 1 6733 5 is_stmt 0 view .LVU2774
.LBE1789:
.LBE1793:
.LBB1794:
.LBI1790:
	.loc 1 6736 13 is_stmt 1 view .LVU2775
.LBB1792:
	.loc 1 6738 5 view .LVU2776
	.loc 1 6740 5 view .LVU2777
	testq	%rax, %rax
	je	.L692
	.loc 1 6741 9 view .LVU2778
	.loc 1 6741 45 is_stmt 0 view .LVU2779
	leaq	-64(%rbp), %rdi
	call	*%rax
.LVL800:
.L692:
	.loc 1 6745 5 is_stmt 1 view .LVU2780
	.loc 1 6745 22 is_stmt 0 view .LVU2781
	movq	-64(%rbp), %rdi
	.loc 1 6745 31 view .LVU2782
	movq	40(%rdi), %rax
	.loc 1 6745 5 view .LVU2783
	testq	%rax, %rax
	je	.L694
	.loc 1 6745 46 view .LVU2784
	cmpl	$1, -56(%rbp)
	jne	.L694
	.loc 1 6746 9 is_stmt 1 view .LVU2785
	.loc 1 6746 37 is_stmt 0 view .LVU2786
	call	*%rax
.LVL801:
	.p2align 4,,10
	.p2align 3
.L694:
	.loc 1 6746 37 view .LVU2787
.LBE1792:
.LBE1794:
.LBE1782:
.LBE1781:
	.loc 1 28360 9 is_stmt 1 view .LVU2788
.LBB1795:
.LBI1795:
	.loc 1 7221 23 view .LVU2789
.LBB1796:
	.loc 1 7223 5 view .LVU2790
	movl	$1, %eax
	xchgl	(%r14), %eax
.LVL802:
	.loc 1 7223 5 is_stmt 0 view .LVU2791
.LBE1796:
.LBE1795:
	.loc 1 28361 9 is_stmt 1 view .LVU2792
.LBB1797:
.LBI1797:
	.loc 1 4915 18 view .LVU2793
.LBE1797:
.LBE1808:
.LBE1819:
	.loc 1 4917 5 view .LVU2794
	.loc 1 4926 5 view .LVU2795
.LBB1820:
.LBB1809:
.LBB1800:
.LBB1798:
.LBI1798:
	.loc 1 4606 18 view .LVU2796
.LBB1799:
	.loc 1 4608 5 view .LVU2797
	.loc 1 4608 23 is_stmt 0 view .LVU2798
	movq	-80(%rbp), %r15
	movq	%r15, %rdi
	call	pthread_mutex_lock
.LVL803:
	.loc 1 4609 5 is_stmt 1 view .LVU2799
	.loc 1 4610 9 view .LVU2800
	.loc 1 4611 28 is_stmt 0 view .LVU2801
	movq	-88(%rbp), %rdi
	.loc 1 4610 23 view .LVU2802
	movl	$1, 288(%rbx)
	.loc 1 4611 9 is_stmt 1 view .LVU2803
	.loc 1 4611 28 is_stmt 0 view .LVU2804
	call	pthread_cond_signal
.LVL804:
	.loc 1 4613 5 is_stmt 1 view .LVU2805
	.loc 1 4613 25 is_stmt 0 view .LVU2806
	movq	%r15, %rdi
	call	pthread_mutex_unlock
.LVL805:
	.loc 1 4615 5 is_stmt 1 view .LVU2807
	.loc 1 4615 12 is_stmt 0 view .LVU2808
	jmp	.L677
.LVL806:
	.p2align 4,,10
	.p2align 3
.L719:
	.loc 1 4615 12 view .LVU2809
.LBE1799:
.LBE1798:
.LBE1800:
	.loc 1 28325 13 is_stmt 1 discriminator 1 view .LVU2810
	.loc 1 28325 33 is_stmt 0 discriminator 1 view .LVU2811
	movl	%eax, 392(%rbx)
	.loc 1 28326 13 is_stmt 1 discriminator 1 view .LVU2812
.LVL807:
.LBB1801:
.LBI1756:
	.loc 1 4915 18 discriminator 1 view .LVU2813
.LBE1801:
.LBE1809:
.LBE1820:
	.loc 1 4917 5 discriminator 1 view .LVU2814
	.loc 1 4926 5 discriminator 1 view .LVU2815
.LBB1821:
.LBB1810:
.LBB1802:
.LBB1760:
.LBI1757:
	.loc 1 4606 18 discriminator 1 view .LVU2816
.LBB1759:
	.loc 1 4608 5 discriminator 1 view .LVU2817
	.loc 1 4608 23 is_stmt 0 discriminator 1 view .LVU2818
	movq	%r15, %rdi
	call	pthread_mutex_lock
.LVL808:
	.loc 1 4609 5 is_stmt 1 discriminator 1 view .LVU2819
	.loc 1 4610 9 discriminator 1 view .LVU2820
	.loc 1 4611 28 is_stmt 0 discriminator 1 view .LVU2821
	leaq	240(%rbx), %rdi
	.loc 1 4610 23 discriminator 1 view .LVU2822
	movl	$1, 192(%rbx)
	.loc 1 4611 9 is_stmt 1 discriminator 1 view .LVU2823
	.loc 1 4611 28 is_stmt 0 discriminator 1 view .LVU2824
	call	pthread_cond_signal
.LVL809:
	.loc 1 4613 5 is_stmt 1 discriminator 1 view .LVU2825
	.loc 1 4613 25 is_stmt 0 discriminator 1 view .LVU2826
	movq	%r15, %rdi
	call	pthread_mutex_unlock
.LVL810:
	.loc 1 4615 5 is_stmt 1 discriminator 1 view .LVU2827
	.loc 1 4615 5 is_stmt 0 discriminator 1 view .LVU2828
.LBE1759:
.LBE1760:
.LBE1802:
	.loc 1 28327 13 is_stmt 1 discriminator 1 view .LVU2829
	jmp	.L677
	.p2align 4,,10
	.p2align 3
.L688:
	.loc 1 28340 13 view .LVU2830
	.loc 1 28340 55 is_stmt 0 view .LVU2831
	call	_ZL42ma_device_audio_thread__default_read_writeP9ma_device.isra.0
.LVL811:
	jmp	.L689
.L717:
	.loc 1 28340 55 view .LVU2832
.LBE1810:
.LBE1821:
	.loc 1 28368 5 is_stmt 1 view .LVU2833
	.loc 1 28369 1 is_stmt 0 view .LVU2834
	addq	$56, %rsp
	xorl	%eax, %eax
	popq	%rbx
.LVL812:
	.loc 1 28369 1 view .LVU2835
	popq	%r12
	popq	%r13
.LVL813:
	.loc 1 28369 1 view .LVU2836
	popq	%r14
.LVL814:
	.loc 1 28369 1 view .LVU2837
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL815:
.L716:
	.cfi_restore_state
	.loc 1 28276 5 discriminator 1 view .LVU2838
	movl	$.LC70, %ecx
	movl	$28276, %edx
	movl	$.LC8, %esi
	movl	$.LC19, %edi
	call	__assert_fail
.LVL816:
	.p2align 4,,10
	.p2align 3
.L718:
.LBB1822:
.LBB1811:
	.loc 1 28311 9 discriminator 1 view .LVU2839
	movl	$.LC70, %ecx
	movl	$28311, %edx
	movl	$.LC8, %esi
	movl	$.LC71, %edi
	call	__assert_fail
.LVL817:
.LBE1811:
.LBE1822:
	.cfi_endproc
.LFE104:
	.size	_ZL16ma_worker_threadPv, .-_ZL16ma_worker_threadPv
	.p2align 4
	.type	ma_context_get_device_info, @function
ma_context_get_device_info:
.LVL818:
.LFB109:
	.loc 1 29065 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 29065 1 is_stmt 0 view .LVU2841
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$1576, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
1:	call	mcount
	.loc 1 29065 1 view .LVU2842
	.loc 1 29066 5 is_stmt 1 view .LVU2843
	.loc 1 29067 5 view .LVU2844
	.loc 1 29070 5 view .LVU2845
	.loc 1 29065 1 is_stmt 0 view .LVU2846
	movq	%rdi, %rbx
	movq	%rdx, %r12
	movq	%rcx, %r14
	.loc 1 29070 5 view .LVU2847
	testq	%rdi, %rdi
	je	.L723
	.loc 1 29074 5 is_stmt 1 view .LVU2848
.LVL819:
.LBB1823:
.LBI1823:
	.loc 1 776 23 view .LVU2849
.LBB1824:
	.loc 1 781 5 view .LVU2850
	.loc 1 782 9 view .LVU2851
	.loc 1 782 15 is_stmt 0 view .LVU2852
	leaq	-1600(%rbp), %r13
.LVL820:
	.loc 1 782 15 view .LVU2853
	movl	$193, %ecx
.LVL821:
	.loc 1 782 15 view .LVU2854
	xorl	%eax, %eax
	movq	%r13, %rdi
.LVL822:
	.loc 1 782 15 view .LVU2855
	rep stosq
.LVL823:
	.loc 1 782 15 view .LVU2856
.LBE1824:
.LBE1823:
	.loc 1 29077 5 is_stmt 1 view .LVU2857
	testq	%rdx, %rdx
	je	.L722
	.loc 1 29078 9 view .LVU2858
	movdqu	(%rdx), %xmm0
	movdqu	16(%rdx), %xmm1
	movdqu	32(%rdx), %xmm2
	movdqu	48(%rdx), %xmm3
	movdqu	64(%rdx), %xmm4
	movdqu	80(%rdx), %xmm5
	movups	%xmm0, -1600(%rbp)
	movdqu	96(%rdx), %xmm6
	movdqu	112(%rdx), %xmm7
	movups	%xmm1, -1584(%rbp)
	movdqu	128(%rdx), %xmm0
	movdqu	144(%rdx), %xmm1
	movups	%xmm2, -1568(%rbp)
	movups	%xmm3, -1552(%rbp)
	movdqu	160(%rdx), %xmm2
	movdqu	176(%rdx), %xmm3
	movups	%xmm4, -1536(%rbp)
	movdqu	192(%rdx), %xmm4
	movups	%xmm5, -1520(%rbp)
	movdqu	208(%rdx), %xmm5
	movups	%xmm6, -1504(%rbp)
	movdqu	224(%rdx), %xmm6
	movups	%xmm7, -1488(%rbp)
	movdqu	240(%rdx), %xmm7
	movups	%xmm0, -1472(%rbp)
	movups	%xmm1, -1456(%rbp)
	movups	%xmm2, -1440(%rbp)
	movups	%xmm3, -1424(%rbp)
	movups	%xmm4, -1408(%rbp)
	movups	%xmm5, -1392(%rbp)
	movups	%xmm6, -1376(%rbp)
	movups	%xmm7, -1360(%rbp)
.L722:
	.loc 1 29081 5 is_stmt 0 view .LVU2859
	cmpq	$0, 24(%rbx)
	movl	%esi, -1604(%rbp)
	.loc 1 29081 5 is_stmt 1 view .LVU2860
	je	.L724
	.loc 1 29085 5 view .LVU2861
	.loc 1 29085 18 is_stmt 0 view .LVU2862
	leaq	360(%rbx), %r15
.LVL824:
.LBB1825:
.LBI1825:
	.loc 1 4800 13 is_stmt 1 view .LVU2863
.LBE1825:
	.loc 1 4802 5 view .LVU2864
	.loc 1 4811 5 view .LVU2865
.LBB1828:
.LBB1826:
.LBI1826:
	.loc 1 4556 13 view .LVU2866
.LBB1827:
	.loc 1 4558 5 view .LVU2867
	.loc 1 4558 23 is_stmt 0 view .LVU2868
	movq	%r15, %rdi
	call	pthread_mutex_lock
.LVL825:
	.loc 1 4558 23 view .LVU2869
.LBE1827:
.LBE1826:
.LBE1828:
	.loc 1 29086 5 is_stmt 1 view .LVU2870
	.loc 1 29087 9 view .LVU2871
	.loc 1 29087 60 is_stmt 0 view .LVU2872
	movq	%r13, %rcx
	movq	%r12, %rdx
	movq	%rbx, %rdi
	movl	-1604(%rbp), %esi
	call	*24(%rbx)
.LVL826:
.LBB1829:
.LBB1830:
.LBB1831:
	.loc 1 4563 25 view .LVU2873
	movq	%r15, %rdi
.LBE1831:
.LBE1830:
.LBE1829:
	.loc 1 29087 60 view .LVU2874
	movl	%eax, %r12d
.LVL827:
	.loc 1 29089 5 is_stmt 1 view .LVU2875
.LBB1834:
.LBI1829:
	.loc 1 4815 13 view .LVU2876
.LBE1834:
	.loc 1 4817 5 view .LVU2877
	.loc 1 4826 5 view .LVU2878
.LBB1835:
.LBB1833:
.LBI1830:
	.loc 1 4561 13 view .LVU2879
.LBB1832:
	.loc 1 4563 5 view .LVU2880
	.loc 1 4563 25 is_stmt 0 view .LVU2881
	call	pthread_mutex_unlock
.LVL828:
	.loc 1 4563 25 view .LVU2882
.LBE1832:
.LBE1833:
.LBE1835:
	.loc 1 29091 5 is_stmt 1 view .LVU2883
	.loc 1 29091 18 is_stmt 0 view .LVU2884
	movl	$193, %ecx
	movq	%r14, %rdi
	movq	%r13, %rsi
	rep movsq
	.loc 1 29092 5 is_stmt 1 view .LVU2885
.LVL829:
.L720:
	.loc 1 29093 1 is_stmt 0 view .LVU2886
	addq	$1576, %rsp
	movl	%r12d, %eax
	popq	%rbx
.LVL830:
	.loc 1 29093 1 view .LVU2887
	popq	%r12
	popq	%r13
	popq	%r14
.LVL831:
	.loc 1 29093 1 view .LVU2888
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL832:
	.p2align 4,,10
	.p2align 3
.L723:
	.cfi_restore_state
	.loc 1 29071 16 view .LVU2889
	movl	$-2, %r12d
	jmp	.L720
.LVL833:
.L724:
	.loc 1 29082 16 view .LVU2890
	movl	$-3, %r12d
	jmp	.L720
	.cfi_endproc
.LFE109:
	.size	ma_context_get_device_info, .-ma_context_get_device_info
	.section	.rodata.str1.8
	.align 8
.LC72:
	.string	"void ma_linear_resampler_interpolate_frame_s16(ma_linear_resampler*, ma_int16*)"
	.section	.rodata.str1.1
.LC73:
	.string	"pFrameOut != __null"
	.section	.rodata.str1.8
	.align 8
.LC74:
	.string	"ma_int16 ma_linear_resampler_mix_s16(ma_int16, ma_int16, ma_int32, ma_int32)"
	.section	.rodata.str1.1
.LC75:
	.string	"a <= (1<<shift)"
	.text
	.p2align 4
	.type	_ZL41ma_linear_resampler_interpolate_frame_s16P19ma_linear_resamplerPs, @function
_ZL41ma_linear_resampler_interpolate_frame_s16P19ma_linear_resamplerPs:
.LVL834:
.LFB110:
	.loc 1 38687 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 38687 1 is_stmt 0 view .LVU2892
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$8, %rsp
	.cfi_offset 3, -24
1:	call	mcount
	.loc 1 38687 1 view .LVU2893
	.loc 1 38688 5 is_stmt 1 view .LVU2894
	.loc 1 38689 5 view .LVU2895
	.loc 1 38690 5 view .LVU2896
	.loc 1 38690 21 is_stmt 0 view .LVU2897
	movl	4(%rdi), %r9d
.LVL835:
	.loc 1 38691 5 is_stmt 1 view .LVU2898
	.loc 1 38693 5 view .LVU2899
	.loc 1 38694 5 view .LVU2900
	.loc 1 38687 1 is_stmt 0 view .LVU2901
	movq	%rdi, %rcx
	.loc 1 38694 5 view .LVU2902
	testq	%rsi, %rsi
	je	.L736
	.loc 1 38696 5 is_stmt 1 view .LVU2903
.LVL836:
	.loc 1 38698 5 view .LVU2904
	.loc 1 38698 5 view .LVU2905
.LBB1846:
	.loc 1 38699 19 view .LVU2906
.LBE1846:
	.loc 1 38696 33 is_stmt 0 view .LVU2907
	movl	44(%rdi), %eax
	.loc 1 38696 7 view .LVU2908
	xorl	%edx, %edx
.LBB1910:
.LBB1847:
	.loc 1 38700 65 view .LVU2909
	movq	48(%rcx), %rcx
.LBE1847:
.LBE1910:
	.loc 1 38696 33 view .LVU2910
	sall	$12, %eax
	.loc 1 38696 7 view .LVU2911
	divl	12(%rdi)
.LBB1911:
.LBB1900:
	.loc 1 38700 88 view .LVU2912
	movq	56(%rdi), %rdi
.LVL837:
	.loc 1 38700 88 view .LVU2913
	cmpl	$4096, %eax
	jg	.L737
	leal	-1(%r9), %edx
	cmpl	$6, %edx
	jbe	.L734
	movl	$4096, %r10d
	movd	%eax, %xmm5
	movl	%r9d, %r8d
	.loc 1 38700 65 view .LVU2914
	xorl	%edx, %edx
	subl	%eax, %r10d
	pshufd	$0, %xmm5, %xmm3
	shrl	$3, %r8d
	.loc 1 38700 49 view .LVU2915
	pxor	%xmm5, %xmm5
.LBB1848:
.LBB1849:
	.loc 1 38679 25 view .LVU2916
	movd	%r10d, %xmm2
	movdqa	%xmm3, %xmm6
	salq	$4, %r8
	pshufd	$0, %xmm2, %xmm2
	psrlq	$32, %xmm6
	.loc 1 38679 7 view .LVU2917
	movdqa	%xmm2, %xmm4
	psrlq	$32, %xmm4
.LVL838:
	.p2align 4,,10
	.p2align 3
.L732:
	.loc 1 38679 7 view .LVU2918
.LBE1849:
.LBE1848:
	.loc 1 38700 9 is_stmt 1 discriminator 2 view .LVU2919
	.loc 1 38700 70 is_stmt 0 discriminator 2 view .LVU2920
	movdqu	(%rcx,%rdx), %xmm1
	.loc 1 38700 49 discriminator 2 view .LVU2921
	movdqa	%xmm5, %xmm10
	.loc 1 38700 93 discriminator 2 view .LVU2922
	movdqu	(%rdi,%rdx), %xmm0
.LVL839:
.LBB1875:
.LBI1848:
	.loc 1 38671 27 is_stmt 1 discriminator 2 view .LVU2923
.LBB1850:
	.loc 1 38673 5 discriminator 2 view .LVU2924
	.loc 1 38674 5 discriminator 2 view .LVU2925
	.loc 1 38675 5 discriminator 2 view .LVU2926
	.loc 1 38677 5 discriminator 2 view .LVU2927
	.loc 1 38679 5 discriminator 2 view .LVU2928
	.loc 1 38680 5 discriminator 2 view .LVU2929
	.loc 1 38681 5 discriminator 2 view .LVU2930
	.loc 1 38683 5 discriminator 2 view .LVU2931
	.loc 1 38683 5 is_stmt 0 discriminator 2 view .LVU2932
.LBE1850:
.LBE1875:
	.loc 1 38701 9 is_stmt 1 discriminator 2 view .LVU2933
	.loc 1 38700 49 is_stmt 0 discriminator 2 view .LVU2934
	movdqa	%xmm5, %xmm9
	pcmpgtw	%xmm1, %xmm10
	pcmpgtw	%xmm0, %xmm9
	movdqa	%xmm1, %xmm8
	punpcklwd	%xmm10, %xmm8
	punpckhwd	%xmm10, %xmm1
.LBB1876:
.LBB1851:
	.loc 1 38679 7 discriminator 2 view .LVU2935
	movdqa	%xmm8, %xmm7
	psrlq	$32, %xmm8
	pmuludq	%xmm2, %xmm7
	pmuludq	%xmm4, %xmm8
	pshufd	$8, %xmm7, %xmm7
	pshufd	$8, %xmm8, %xmm8
	punpckldq	%xmm8, %xmm7
.LBE1851:
.LBE1876:
	.loc 1 38700 49 discriminator 2 view .LVU2936
	movdqa	%xmm0, %xmm8
	punpckhwd	%xmm9, %xmm0
	punpcklwd	%xmm9, %xmm8
.LBB1877:
.LBB1852:
	.loc 1 38680 7 discriminator 2 view .LVU2937
	movdqa	%xmm8, %xmm11
	psrlq	$32, %xmm8
	pmuludq	%xmm3, %xmm11
	pmuludq	%xmm6, %xmm8
	pshufd	$8, %xmm11, %xmm11
	pshufd	$8, %xmm8, %xmm8
	punpckldq	%xmm8, %xmm11
	.loc 1 38679 7 discriminator 2 view .LVU2938
	movdqa	%xmm1, %xmm8
	psrlq	$32, %xmm1
	pmuludq	%xmm2, %xmm8
	.loc 1 38681 7 discriminator 2 view .LVU2939
	paddd	%xmm11, %xmm7
	.loc 1 38679 7 discriminator 2 view .LVU2940
	pmuludq	%xmm4, %xmm1
	.loc 1 38683 25 discriminator 2 view .LVU2941
	psrad	$12, %xmm7
	.loc 1 38679 7 discriminator 2 view .LVU2942
	pshufd	$8, %xmm8, %xmm8
	pshufd	$8, %xmm1, %xmm1
	punpckldq	%xmm1, %xmm8
	.loc 1 38680 7 discriminator 2 view .LVU2943
	movdqa	%xmm0, %xmm1
	psrlq	$32, %xmm0
	pmuludq	%xmm3, %xmm1
	pmuludq	%xmm6, %xmm0
	pshufd	$8, %xmm1, %xmm1
	pshufd	$8, %xmm0, %xmm0
	punpckldq	%xmm0, %xmm1
	.loc 1 38683 33 discriminator 2 view .LVU2944
	movdqa	%xmm7, %xmm0
	.loc 1 38681 7 discriminator 2 view .LVU2945
	paddd	%xmm8, %xmm1
	.loc 1 38683 33 discriminator 2 view .LVU2946
	movdqa	%xmm7, %xmm8
	.loc 1 38683 25 discriminator 2 view .LVU2947
	psrad	$12, %xmm1
	.loc 1 38683 33 discriminator 2 view .LVU2948
	punpcklwd	%xmm1, %xmm0
	punpckhwd	%xmm1, %xmm8
	movdqa	%xmm0, %xmm1
	punpcklwd	%xmm8, %xmm0
	punpckhwd	%xmm8, %xmm1
	punpcklwd	%xmm1, %xmm0
.LBE1852:
.LBE1877:
	.loc 1 38701 22 discriminator 2 view .LVU2949
	movups	%xmm0, (%rsi,%rdx)
	.loc 1 38701 22 discriminator 2 view .LVU2950
.LBE1900:
	.loc 1 38699 5 is_stmt 1 discriminator 2 view .LVU2951
	.loc 1 38699 19 discriminator 2 view .LVU2952
	addq	$16, %rdx
	cmpq	%r8, %rdx
	jne	.L732
	movl	%r9d, %edx
	andl	$-8, %edx
	testb	$7, %r9b
	je	.L728
.L731:
.LVL840:
.LBB1901:
	.loc 1 38700 9 view .LVU2953
	.loc 1 38700 92 is_stmt 0 view .LVU2954
	movl	%edx, %ebx
.LVL841:
.LBB1878:
	.loc 1 38671 27 is_stmt 1 view .LVU2955
.LBB1853:
	.loc 1 38673 5 view .LVU2956
	.loc 1 38674 5 view .LVU2957
	.loc 1 38675 5 view .LVU2958
	.loc 1 38677 5 view .LVU2959
	.loc 1 38679 5 view .LVU2960
	.loc 1 38679 25 is_stmt 0 view .LVU2961
	movl	$4096, %r8d
.LBE1853:
.LBE1878:
	.loc 1 38700 49 view .LVU2962
	movswl	(%rcx,%rbx,2), %r10d
.LBB1879:
.LBB1854:
	.loc 1 38679 25 view .LVU2963
	subl	%eax, %r8d
	.loc 1 38680 5 is_stmt 1 view .LVU2964
	.loc 1 38681 5 view .LVU2965
	.loc 1 38683 5 view .LVU2966
.LVL842:
	.loc 1 38683 5 is_stmt 0 view .LVU2967
.LBE1854:
.LBE1879:
	.loc 1 38701 9 is_stmt 1 view .LVU2968
.LBB1880:
.LBB1855:
	.loc 1 38679 7 is_stmt 0 view .LVU2969
	movl	%r10d, %r11d
.LBE1855:
.LBE1880:
	.loc 1 38700 49 view .LVU2970
	movswl	(%rdi,%rbx,2), %r10d
.LBB1881:
.LBB1856:
	.loc 1 38679 7 view .LVU2971
	imull	%r8d, %r11d
	.loc 1 38680 7 view .LVU2972
	imull	%eax, %r10d
	.loc 1 38681 7 view .LVU2973
	addl	%r11d, %r10d
	.loc 1 38683 25 view .LVU2974
	sarl	$12, %r10d
	.loc 1 38683 33 view .LVU2975
	movw	%r10w, (%rsi,%rbx,2)
.LBE1856:
.LBE1881:
.LBE1901:
	.loc 1 38699 5 is_stmt 1 view .LVU2976
	.loc 1 38699 33 is_stmt 0 view .LVU2977
	leal	1(%rdx), %ebx
.LVL843:
	.loc 1 38699 19 is_stmt 1 view .LVU2978
	cmpl	%ebx, %r9d
	jbe	.L728
.LBB1902:
	.loc 1 38700 9 view .LVU2979
.LVL844:
.LBB1882:
	.loc 1 38671 27 view .LVU2980
.LBB1857:
	.loc 1 38673 5 view .LVU2981
	.loc 1 38674 5 view .LVU2982
	.loc 1 38675 5 view .LVU2983
	.loc 1 38677 5 view .LVU2984
	.loc 1 38679 5 view .LVU2985
	.loc 1 38680 5 view .LVU2986
	.loc 1 38681 5 view .LVU2987
	.loc 1 38683 5 view .LVU2988
	.loc 1 38683 5 is_stmt 0 view .LVU2989
.LBE1857:
.LBE1882:
	.loc 1 38701 9 is_stmt 1 view .LVU2990
	.loc 1 38700 49 is_stmt 0 view .LVU2991
	movswl	(%rcx,%rbx,2), %r10d
.LBB1883:
.LBB1858:
	.loc 1 38679 7 view .LVU2992
	movl	%r10d, %r11d
.LBE1858:
.LBE1883:
	.loc 1 38700 49 view .LVU2993
	movswl	(%rdi,%rbx,2), %r10d
.LBB1884:
.LBB1859:
	.loc 1 38679 7 view .LVU2994
	imull	%r8d, %r11d
	.loc 1 38680 7 view .LVU2995
	imull	%eax, %r10d
	.loc 1 38681 7 view .LVU2996
	addl	%r11d, %r10d
	.loc 1 38683 25 view .LVU2997
	sarl	$12, %r10d
	.loc 1 38683 33 view .LVU2998
	movw	%r10w, (%rsi,%rbx,2)
.LBE1859:
.LBE1884:
.LBE1902:
	.loc 1 38699 5 is_stmt 1 view .LVU2999
	.loc 1 38699 33 is_stmt 0 view .LVU3000
	leal	2(%rdx), %ebx
.LVL845:
	.loc 1 38699 19 is_stmt 1 view .LVU3001
	cmpl	%ebx, %r9d
	jbe	.L728
.LBB1903:
	.loc 1 38700 9 view .LVU3002
.LVL846:
.LBB1885:
	.loc 1 38671 27 view .LVU3003
.LBB1860:
	.loc 1 38673 5 view .LVU3004
	.loc 1 38674 5 view .LVU3005
	.loc 1 38675 5 view .LVU3006
	.loc 1 38677 5 view .LVU3007
	.loc 1 38679 5 view .LVU3008
	.loc 1 38680 5 view .LVU3009
	.loc 1 38681 5 view .LVU3010
	.loc 1 38683 5 view .LVU3011
	.loc 1 38683 5 is_stmt 0 view .LVU3012
.LBE1860:
.LBE1885:
	.loc 1 38701 9 is_stmt 1 view .LVU3013
	.loc 1 38700 49 is_stmt 0 view .LVU3014
	movswl	(%rcx,%rbx,2), %r10d
.LBB1886:
.LBB1861:
	.loc 1 38679 7 view .LVU3015
	movl	%r10d, %r11d
.LBE1861:
.LBE1886:
	.loc 1 38700 49 view .LVU3016
	movswl	(%rdi,%rbx,2), %r10d
.LBB1887:
.LBB1862:
	.loc 1 38679 7 view .LVU3017
	imull	%r8d, %r11d
	.loc 1 38680 7 view .LVU3018
	imull	%eax, %r10d
	.loc 1 38681 7 view .LVU3019
	addl	%r11d, %r10d
	.loc 1 38683 25 view .LVU3020
	sarl	$12, %r10d
	.loc 1 38683 33 view .LVU3021
	movw	%r10w, (%rsi,%rbx,2)
.LBE1862:
.LBE1887:
.LBE1903:
	.loc 1 38699 5 is_stmt 1 view .LVU3022
	.loc 1 38699 33 is_stmt 0 view .LVU3023
	leal	3(%rdx), %ebx
.LVL847:
	.loc 1 38699 19 is_stmt 1 view .LVU3024
	cmpl	%ebx, %r9d
	jbe	.L728
.LBB1904:
	.loc 1 38700 9 view .LVU3025
.LVL848:
.LBB1888:
	.loc 1 38671 27 view .LVU3026
.LBB1863:
	.loc 1 38673 5 view .LVU3027
	.loc 1 38674 5 view .LVU3028
	.loc 1 38675 5 view .LVU3029
	.loc 1 38677 5 view .LVU3030
	.loc 1 38679 5 view .LVU3031
	.loc 1 38680 5 view .LVU3032
	.loc 1 38681 5 view .LVU3033
	.loc 1 38683 5 view .LVU3034
	.loc 1 38683 5 is_stmt 0 view .LVU3035
.LBE1863:
.LBE1888:
	.loc 1 38701 9 is_stmt 1 view .LVU3036
	.loc 1 38700 49 is_stmt 0 view .LVU3037
	movswl	(%rcx,%rbx,2), %r10d
.LBB1889:
.LBB1864:
	.loc 1 38679 7 view .LVU3038
	movl	%r10d, %r11d
.LBE1864:
.LBE1889:
	.loc 1 38700 49 view .LVU3039
	movswl	(%rdi,%rbx,2), %r10d
.LBB1890:
.LBB1865:
	.loc 1 38679 7 view .LVU3040
	imull	%r8d, %r11d
	.loc 1 38680 7 view .LVU3041
	imull	%eax, %r10d
	.loc 1 38681 7 view .LVU3042
	addl	%r11d, %r10d
	.loc 1 38683 25 view .LVU3043
	sarl	$12, %r10d
	.loc 1 38683 33 view .LVU3044
	movw	%r10w, (%rsi,%rbx,2)
.LBE1865:
.LBE1890:
.LBE1904:
	.loc 1 38699 5 is_stmt 1 view .LVU3045
	.loc 1 38699 33 is_stmt 0 view .LVU3046
	leal	4(%rdx), %ebx
.LVL849:
	.loc 1 38699 19 is_stmt 1 view .LVU3047
	cmpl	%ebx, %r9d
	jbe	.L728
.LBB1905:
	.loc 1 38700 9 view .LVU3048
.LVL850:
.LBB1891:
	.loc 1 38671 27 view .LVU3049
.LBB1866:
	.loc 1 38673 5 view .LVU3050
	.loc 1 38674 5 view .LVU3051
	.loc 1 38675 5 view .LVU3052
	.loc 1 38677 5 view .LVU3053
	.loc 1 38679 5 view .LVU3054
	.loc 1 38680 5 view .LVU3055
	.loc 1 38681 5 view .LVU3056
	.loc 1 38683 5 view .LVU3057
	.loc 1 38683 5 is_stmt 0 view .LVU3058
.LBE1866:
.LBE1891:
	.loc 1 38701 9 is_stmt 1 view .LVU3059
	.loc 1 38700 49 is_stmt 0 view .LVU3060
	movswl	(%rcx,%rbx,2), %r10d
.LBB1892:
.LBB1867:
	.loc 1 38679 7 view .LVU3061
	movl	%r10d, %r11d
.LBE1867:
.LBE1892:
	.loc 1 38700 49 view .LVU3062
	movswl	(%rdi,%rbx,2), %r10d
.LBB1893:
.LBB1868:
	.loc 1 38679 7 view .LVU3063
	imull	%r8d, %r11d
	.loc 1 38680 7 view .LVU3064
	imull	%eax, %r10d
	.loc 1 38681 7 view .LVU3065
	addl	%r11d, %r10d
	.loc 1 38683 25 view .LVU3066
	sarl	$12, %r10d
	.loc 1 38683 33 view .LVU3067
	movw	%r10w, (%rsi,%rbx,2)
.LBE1868:
.LBE1893:
.LBE1905:
	.loc 1 38699 5 is_stmt 1 view .LVU3068
	.loc 1 38699 33 is_stmt 0 view .LVU3069
	leal	5(%rdx), %ebx
.LVL851:
	.loc 1 38699 19 is_stmt 1 view .LVU3070
	cmpl	%ebx, %r9d
	jbe	.L728
.LBB1906:
	.loc 1 38700 9 view .LVU3071
.LVL852:
.LBB1894:
	.loc 1 38671 27 view .LVU3072
.LBB1869:
	.loc 1 38673 5 view .LVU3073
	.loc 1 38674 5 view .LVU3074
	.loc 1 38675 5 view .LVU3075
	.loc 1 38677 5 view .LVU3076
	.loc 1 38679 5 view .LVU3077
	.loc 1 38680 5 view .LVU3078
	.loc 1 38681 5 view .LVU3079
	.loc 1 38683 5 view .LVU3080
	.loc 1 38683 5 is_stmt 0 view .LVU3081
.LBE1869:
.LBE1894:
	.loc 1 38701 9 is_stmt 1 view .LVU3082
	.loc 1 38700 49 is_stmt 0 view .LVU3083
	movswl	(%rcx,%rbx,2), %r10d
.LBE1906:
	.loc 1 38699 33 view .LVU3084
	addl	$6, %edx
.LBB1907:
.LBB1895:
.LBB1870:
	.loc 1 38679 7 view .LVU3085
	movl	%r10d, %r11d
.LBE1870:
.LBE1895:
	.loc 1 38700 49 view .LVU3086
	movswl	(%rdi,%rbx,2), %r10d
.LBB1896:
.LBB1871:
	.loc 1 38679 7 view .LVU3087
	imull	%r8d, %r11d
	.loc 1 38680 7 view .LVU3088
	imull	%eax, %r10d
	.loc 1 38681 7 view .LVU3089
	addl	%r11d, %r10d
	.loc 1 38683 25 view .LVU3090
	sarl	$12, %r10d
	.loc 1 38683 33 view .LVU3091
	movw	%r10w, (%rsi,%rbx,2)
.LBE1871:
.LBE1896:
.LBE1907:
	.loc 1 38699 5 is_stmt 1 view .LVU3092
.LVL853:
	.loc 1 38699 19 view .LVU3093
	cmpl	%edx, %r9d
	jbe	.L728
.LBB1908:
	.loc 1 38700 9 view .LVU3094
.LVL854:
.LBB1897:
	.loc 1 38671 27 view .LVU3095
.LBB1872:
	.loc 1 38673 5 view .LVU3096
	.loc 1 38674 5 view .LVU3097
	.loc 1 38675 5 view .LVU3098
	.loc 1 38677 5 view .LVU3099
	.loc 1 38679 5 view .LVU3100
	.loc 1 38680 5 view .LVU3101
	.loc 1 38681 5 view .LVU3102
	.loc 1 38683 5 view .LVU3103
	.loc 1 38683 5 is_stmt 0 view .LVU3104
.LBE1872:
.LBE1897:
	.loc 1 38701 9 is_stmt 1 view .LVU3105
	.loc 1 38700 49 is_stmt 0 view .LVU3106
	movswl	(%rdi,%rdx,2), %edi
	movswl	(%rcx,%rdx,2), %ecx
.LBB1898:
.LBB1873:
	.loc 1 38680 7 view .LVU3107
	imull	%edi, %eax
.LVL855:
	.loc 1 38679 7 view .LVU3108
	imull	%ecx, %r8d
.LVL856:
	.loc 1 38681 7 view .LVU3109
	addl	%r8d, %eax
	.loc 1 38683 25 view .LVU3110
	sarl	$12, %eax
	.loc 1 38683 33 view .LVU3111
	movw	%ax, (%rsi,%rdx,2)
.LBE1873:
.LBE1898:
.LBE1908:
	.loc 1 38699 5 is_stmt 1 view .LVU3112
	.loc 1 38699 19 view .LVU3113
.LVL857:
.L728:
	.loc 1 38699 19 is_stmt 0 view .LVU3114
.LBE1911:
	.loc 1 38703 1 view .LVU3115
	movq	-8(%rbp), %rbx
	leave
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL858:
.L734:
	.cfi_restore_state
.LBB1912:
	.loc 1 38699 12 view .LVU3116
	xorl	%edx, %edx
	jmp	.L731
.L737:
.LBB1909:
	.loc 1 38700 9 is_stmt 1 view .LVU3117
.LVL859:
.LBB1899:
	.loc 1 38671 27 view .LVU3118
.LBB1874:
	.loc 1 38673 5 view .LVU3119
	.loc 1 38674 5 view .LVU3120
	.loc 1 38675 5 view .LVU3121
	.loc 1 38677 5 view .LVU3122
	movl	$.LC74, %ecx
	movl	$38677, %edx
	movl	$.LC8, %esi
.LVL860:
	.loc 1 38677 5 is_stmt 0 view .LVU3123
	movl	$.LC75, %edi
	call	__assert_fail
.LVL861:
.L736:
	.loc 1 38677 5 view .LVU3124
.LBE1874:
.LBE1899:
.LBE1909:
.LBE1912:
.LBB1913:
.LBI1913:
	.loc 1 38686 13 is_stmt 1 view .LVU3125
.LBB1914:
	.loc 1 38694 5 is_stmt 0 view .LVU3126
	movl	$.LC72, %ecx
.LVL862:
	.loc 1 38694 5 view .LVU3127
	movl	$38694, %edx
	movl	$.LC8, %esi
.LVL863:
	.loc 1 38694 5 view .LVU3128
	movl	$.LC73, %edi
.LVL864:
	.loc 1 38694 5 view .LVU3129
	call	__assert_fail
.LVL865:
	.loc 1 38694 5 view .LVU3130
.LBE1914:
.LBE1913:
	.cfi_endproc
.LFE110:
	.size	_ZL41ma_linear_resampler_interpolate_frame_s16P19ma_linear_resamplerPs, .-_ZL41ma_linear_resampler_interpolate_frame_s16P19ma_linear_resamplerPs
	.p2align 4
	.type	_ZL36ma_resampling_backend_uninit__linearPvS_PK23ma_allocation_callbacks, @function
_ZL36ma_resampling_backend_uninit__linearPvS_PK23ma_allocation_callbacks:
.LVL866:
.LFB112:
	.loc 1 39262 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 39262 1 is_stmt 0 view .LVU3132
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
1:	call	mcount
	.loc 1 39262 1 view .LVU3133
	.loc 1 39263 5 is_stmt 1 view .LVU3134
	.loc 1 39265 5 view .LVU3135
	.loc 1 39262 1 is_stmt 0 view .LVU3136
	movq	%rsi, %rdi
.LVL867:
	.loc 1 39262 1 view .LVU3137
	movq	%rdx, %rsi
.LVL868:
.LBB1915:
.LBI1915:
	.loc 1 38658 13 is_stmt 1 view .LVU3138
.LBB1916:
	.loc 1 38660 5 view .LVU3139
	testq	%rdi, %rdi
	je	.L738
.LBE1916:
.LBE1915:
	.loc 1 39266 1 is_stmt 0 view .LVU3140
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
.LBB1918:
.LBB1917:
	jmp	ma_linear_resampler_uninit.part.0
.LVL869:
	.p2align 4,,10
	.p2align 3
.L738:
	.cfi_restore_state
	.loc 1 39266 1 view .LVU3141
.LBE1917:
.LBE1918:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE112:
	.size	_ZL36ma_resampling_backend_uninit__linearPvS_PK23ma_allocation_callbacks, .-_ZL36ma_resampling_backend_uninit__linearPvS_PK23ma_allocation_callbacks
	.p2align 4
	.type	_ZL51ma_resampler_config_init_from_data_converter_configPK24ma_data_converter_config, @function
_ZL51ma_resampler_config_init_from_data_converter_configPK24ma_data_converter_config:
.LVL870:
.LFB113:
	.loc 1 41169 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 41169 1 is_stmt 0 view .LVU3143
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
1:	call	mcount
	.loc 1 41169 1 view .LVU3144
	.loc 1 41170 5 is_stmt 1 view .LVU3145
	.loc 1 41171 5 view .LVU3146
	.loc 1 41173 5 view .LVU3147
	.loc 1 41176 5 view .LVU3148
	movl	12(%rsi), %eax
	cmpl	%eax, 8(%rsi)
	cmovbe	8(%rsi), %eax
	.loc 1 41182 149 is_stmt 0 view .LVU3149
	movl	20(%rsi), %r9d
	.loc 1 41182 126 view .LVU3150
	movl	16(%rsi), %ecx
	movl	%eax, %edx
.LVL871:
	.loc 1 41182 5 is_stmt 1 view .LVU3151
.LBB1933:
.LBI1933:
	.loc 1 41129 18 view .LVU3152
.LBB1934:
	.loc 1 41131 5 view .LVU3153
	.loc 1 41142 5 view .LVU3154
.LBB1935:
.LBI1935:
	.loc 1 41122 18 view .LVU3155
.LBB1936:
	.loc 1 41124 5 view .LVU3156
	.loc 1 41126 5 view .LVU3157
	.loc 1 41126 44 is_stmt 0 view .LVU3158
	movl	64(%rsi), %eax
.LVL872:
	.loc 1 41126 44 view .LVU3159
.LBE1936:
.LBE1935:
.LBE1934:
.LBE1933:
	.loc 1 41169 1 view .LVU3160
	movq	%rdi, %r8
	.loc 1 41182 184 view .LVU3161
	movl	88(%rsi), %edi
.LVL873:
.LBB1940:
.LBB1939:
.LBB1938:
.LBB1937:
	.loc 1 41126 44 view .LVU3162
	testl	%eax, %eax
	jne	.L746
	cmpl	%ecx, %r9d
	je	.L741
.L746:
.LVL874:
	.loc 1 41126 44 view .LVU3163
.LBE1937:
.LBE1938:
	.loc 1 41150 20 view .LVU3164
	movl	$5, %eax
	.loc 1 41142 65 view .LVU3165
	testl	%edi, %edi
	jne	.L743
.L741:
	.loc 1 41145 16 is_stmt 1 view .LVU3166
	.loc 1 41145 29 is_stmt 0 view .LVU3167
	movl	4(%rsi), %eax
	.loc 1 41145 16 view .LVU3168
	cmpl	$2, %eax
	je	.L743
	.loc 1 41145 56 view .LVU3169
	cmpl	$5, %eax
	je	.L743
	.loc 1 41147 16 is_stmt 1 view .LVU3170
	.loc 1 41147 29 is_stmt 0 view .LVU3171
	movl	(%rsi), %eax
	.loc 1 41150 20 view .LVU3172
	movl	$5, %r10d
	cmpl	$2, %eax
	cmovne	%r10d, %eax
.L743:
.LVL875:
	.loc 1 41150 20 view .LVU3173
.LBE1939:
.LBE1940:
.LBB1941:
.LBI1941:
	.loc 1 39333 28 is_stmt 1 view .LVU3174
.LBB1942:
	.loc 1 39335 5 view .LVU3175
	.loc 1 39337 5 view .LVU3176
.LBB1943:
.LBI1943:
	.loc 1 776 23 view .LVU3177
.LBB1944:
	.loc 1 781 5 view .LVU3178
	.loc 1 782 9 view .LVU3179
	.loc 1 782 15 is_stmt 0 view .LVU3180
	pxor	%xmm0, %xmm0
.LBE1944:
.LBE1943:
	.loc 1 39338 19 view .LVU3181
	movd	%ecx, %xmm1
.LBE1942:
.LBE1941:
	.loc 1 41184 60 view .LVU3182
	movdqu	96(%rsi), %xmm6
.LBB1953:
.LBB1949:
.LBB1947:
.LBB1945:
	.loc 1 782 15 view .LVU3183
	movaps	%xmm0, -32(%rbp)
.LBE1945:
.LBE1947:
	.loc 1 39338 19 view .LVU3184
	movd	%r9d, %xmm2
	movd	%edx, %xmm3
.LBB1948:
.LBB1946:
	.loc 1 782 15 view .LVU3185
	movaps	%xmm0, -16(%rbp)
.LVL876:
	.loc 1 782 15 view .LVU3186
.LBE1946:
.LBE1948:
	.loc 1 39338 5 is_stmt 1 view .LVU3187
	.loc 1 39339 5 view .LVU3188
	.loc 1 39340 5 view .LVU3189
	.loc 1 39341 5 view .LVU3190
	.loc 1 39338 19 is_stmt 0 view .LVU3191
	movd	%eax, %xmm0
	punpckldq	%xmm2, %xmm1
.LBE1949:
.LBE1953:
	.loc 1 41183 38 view .LVU3192
	movl	112(%rsi), %eax
.LVL877:
.LBB1954:
.LBB1950:
	.loc 1 39342 22 view .LVU3193
	movl	%edi, -32(%rbp)
	.loc 1 39338 19 view .LVU3194
	punpckldq	%xmm3, %xmm0
.LVL878:
	.loc 1 39338 19 view .LVU3195
.LBE1950:
.LBE1954:
	.loc 1 41182 193 view .LVU3196
	movdqa	-32(%rbp), %xmm4
.LBB1955:
.LBB1951:
	.loc 1 39345 28 view .LVU3197
	movl	$4, -8(%rbp)
.LBE1951:
.LBE1955:
	.loc 1 41182 193 view .LVU3198
	movdqa	-16(%rbp), %xmm5
.LBB1956:
.LBB1952:
	.loc 1 39338 19 view .LVU3199
	punpcklqdq	%xmm1, %xmm0
	.loc 1 39342 5 is_stmt 1 view .LVU3200
	.loc 1 39345 5 view .LVU3201
	.loc 1 39347 5 view .LVU3202
.LVL879:
	.loc 1 39347 5 is_stmt 0 view .LVU3203
.LBE1952:
.LBE1956:
	.loc 1 41182 193 view .LVU3204
	movups	%xmm4, 16(%r8)
	movups	%xmm5, 32(%r8)
	.loc 1 41183 5 is_stmt 1 view .LVU3205
	.loc 1 41182 193 is_stmt 0 view .LVU3206
	movups	%xmm0, (%r8)
	.loc 1 41183 38 view .LVU3207
	movl	%eax, 40(%r8)
	.loc 1 41184 5 is_stmt 1 view .LVU3208
	.loc 1 41185 5 view .LVU3209
	.loc 1 41187 5 view .LVU3210
	.loc 1 41188 1 is_stmt 0 view .LVU3211
	movq	%r8, %rax
	.loc 1 41184 60 view .LVU3212
	movups	%xmm6, 24(%r8)
	.loc 1 41188 1 view .LVU3213
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE113:
	.size	_ZL51ma_resampler_config_init_from_data_converter_configPK24ma_data_converter_config, .-_ZL51ma_resampler_config_init_from_data_converter_configPK24ma_data_converter_config
	.p2align 4
	.globl	ma_copy_and_apply_volume_factor_pcm_frames
	.hidden	ma_copy_and_apply_volume_factor_pcm_frames
	.type	ma_copy_and_apply_volume_factor_pcm_frames, @function
ma_copy_and_apply_volume_factor_pcm_frames:
.LVL880:
.LFB116:
	.loc 1 30316 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 30316 1 is_stmt 0 view .LVU3215
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
1:	call	mcount
	.loc 1 30316 1 view .LVU3216
	.loc 1 30317 5 is_stmt 1 view .LVU3217
	.loc 1 30316 1 is_stmt 0 view .LVU3218
	movaps	%xmm0, %xmm2
	cmpl	$5, %ecx
	ja	.L756
	movl	%ecx, %ecx
	.loc 1 30316 1 view .LVU3219
	jmp	*.L759(,%rcx,8)
	.section	.rodata
	.align 8
	.align 4
.L759:
	.quad	.L756
	.quad	.L763
	.quad	.L762
	.quad	.L761
	.quad	.L760
	.quad	.L758
	.text
	.p2align 4,,10
	.p2align 3
.L761:
	.loc 1 30321 5 is_stmt 1 view .LVU3220
	.loc 1 30321 25 view .LVU3221
.LVL881:
.LBB1989:
.LBI1989:
	.loc 1 30300 13 view .LVU3222
.LBB1990:
	.loc 1 30302 5 view .LVU3223
.LBB1991:
.LBI1991:
	.loc 1 30203 13 view .LVU3224
.LBB1992:
	.loc 1 30205 5 view .LVU3225
	.loc 1 30206 5 view .LVU3226
	.loc 1 30207 5 view .LVU3227
	.loc 1 30209 5 view .LVU3228
	testq	%rdi, %rdi
	je	.L756
	testq	%rsi, %rsi
	je	.L756
.LBE1992:
.LBE1991:
	.loc 1 30302 75 is_stmt 0 view .LVU3229
	movl	%r8d, %r8d
.LVL882:
	.loc 1 30302 40 view .LVU3230
	imulq	%rdx, %r8
.LVL883:
.LBB1999:
.LBB1998:
.LBB1993:
.LBB1994:
.LBB1995:
	.loc 1 30216 31 is_stmt 1 view .LVU3231
	testq	%r8, %r8
	je	.L756
	leaq	(%r8,%r8,2), %rcx
.LVL884:
	.loc 1 30216 31 is_stmt 0 view .LVU3232
	addq	%rsi, %rcx
.LVL885:
	.p2align 4,,10
	.p2align 3
.L777:
.LBB1996:
	.loc 1 30217 9 is_stmt 1 view .LVU3233
	.loc 1 30219 9 view .LVU3234
	.loc 1 30220 9 view .LVU3235
	.loc 1 30219 33 is_stmt 0 view .LVU3236
	movzbl	(%rsi), %eax
	.loc 1 30219 80 view .LVU3237
	movzbl	1(%rsi), %edx
	.loc 1 30220 42 view .LVU3238
	pxor	%xmm0, %xmm0
.LBE1996:
	.loc 1 30216 31 view .LVU3239
	addq	$3, %rsi
.LVL886:
	.loc 1 30216 31 view .LVU3240
	addq	$3, %rdi
.LBB1997:
	.loc 1 30219 118 view .LVU3241
	sall	$16, %edx
	.loc 1 30219 71 view .LVU3242
	sall	$8, %eax
	.loc 1 30219 125 view .LVU3243
	orl	%edx, %eax
	.loc 1 30219 128 view .LVU3244
	movzbl	-1(%rsi), %edx
	.loc 1 30219 167 view .LVU3245
	sall	$24, %edx
	.loc 1 30219 125 view .LVU3246
	orl	%edx, %eax
	.loc 1 30220 42 view .LVU3247
	cvtsi2ssl	%eax, %xmm0
	mulss	%xmm2, %xmm0
.LVL887:
	.loc 1 30222 9 is_stmt 1 view .LVU3248
	.loc 1 30220 19 is_stmt 0 view .LVU3249
	cvttss2sil	%xmm0, %eax
.LVL888:
	.loc 1 30223 84 view .LVU3250
	movl	%eax, %edx
	.loc 1 30222 35 view .LVU3251
	movb	%ah, -3(%rdi)
	.loc 1 30223 9 is_stmt 1 view .LVU3252
	.loc 1 30224 84 is_stmt 0 view .LVU3253
	shrl	$24, %eax
.LVL889:
	.loc 1 30223 84 view .LVU3254
	shrl	$16, %edx
.LVL890:
	.loc 1 30224 35 view .LVU3255
	movb	%al, -1(%rdi)
	.loc 1 30223 35 view .LVU3256
	movb	%dl, -2(%rdi)
	.loc 1 30224 9 is_stmt 1 view .LVU3257
.LBE1997:
	.loc 1 30216 5 view .LVU3258
	.loc 1 30216 31 view .LVU3259
	cmpq	%rcx, %rsi
	jne	.L777
.LVL891:
.L756:
	.loc 1 30216 31 is_stmt 0 view .LVU3260
.LBE1995:
.LBE1994:
.LBE1993:
.LBE1998:
.LBE1999:
.LBE1990:
.LBE1989:
	.loc 1 30326 1 view .LVU3261
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL892:
	.p2align 4,,10
	.p2align 3
.L758:
	.cfi_restore_state
	.loc 1 30323 5 is_stmt 1 view .LVU3262
	.loc 1 30323 25 view .LVU3263
.LBB2000:
.LBI2000:
	.loc 1 30310 13 view .LVU3264
.LBB2001:
	.loc 1 30312 5 view .LVU3265
.LBB2002:
.LBI2002:
	.loc 1 30241 13 view .LVU3266
.LBB2003:
	.loc 1 30243 5 view .LVU3267
	.loc 1 30245 5 view .LVU3268
	testq	%rdi, %rdi
	je	.L756
	testq	%rsi, %rsi
	je	.L756
.LBE2003:
.LBE2002:
	.loc 1 30312 75 is_stmt 0 view .LVU3269
	movl	%r8d, %r8d
.LVL893:
	.loc 1 30312 40 view .LVU3270
	imulq	%rdx, %r8
.LVL894:
.LBB2016:
.LBB2010:
	.loc 1 30249 5 is_stmt 1 view .LVU3271
	comiss	.LC77(%rip), %xmm0
	jne	.L849
	.loc 1 30250 9 view .LVU3272
	cmpq	%rsi, %rdi
	je	.L756
.LVL895:
.LBB2004:
.LBB2005:
	.loc 1 30254 39 view .LVU3273
	testq	%r8, %r8
	je	.L756
	leaq	4(%rsi), %rdx
.LVL896:
	.loc 1 30254 39 is_stmt 0 view .LVU3274
	movq	%rdi, %rax
	subq	%rdx, %rax
	cmpq	$8, %rax
	jbe	.L798
	leaq	-1(%r8), %rax
	cmpq	$3, %rax
	jbe	.L798
	movq	%r8, %rdx
	xorl	%eax, %eax
	shrq	$2, %rdx
	salq	$4, %rdx
.LVL897:
	.p2align 4,,10
	.p2align 3
.L787:
	.loc 1 30255 17 is_stmt 1 view .LVU3275
	.loc 1 30255 38 is_stmt 0 view .LVU3276
	movups	(%rsi,%rax), %xmm7
	movups	%xmm7, (%rdi,%rax)
	.loc 1 30254 13 is_stmt 1 view .LVU3277
	.loc 1 30254 39 view .LVU3278
	addq	$16, %rax
	cmpq	%rdx, %rax
	jne	.L787
	movq	%r8, %rax
	andq	$-4, %rax
	testb	$3, %r8b
	je	.L756
.LVL898:
	.loc 1 30255 17 view .LVU3279
	.loc 1 30255 58 is_stmt 0 view .LVU3280
	movss	(%rsi,%rax,4), %xmm0
.LVL899:
	.loc 1 30254 62 view .LVU3281
	leaq	1(%rax), %rdx
	.loc 1 30255 38 view .LVU3282
	movss	%xmm0, (%rdi,%rax,4)
	.loc 1 30254 13 is_stmt 1 view .LVU3283
.LVL900:
	.loc 1 30254 39 view .LVU3284
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30255 17 view .LVU3285
	.loc 1 30255 58 is_stmt 0 view .LVU3286
	movss	(%rsi,%rdx,4), %xmm0
	.loc 1 30254 62 view .LVU3287
	addq	$2, %rax
	.loc 1 30255 38 view .LVU3288
	movss	%xmm0, (%rdi,%rdx,4)
	.loc 1 30254 13 is_stmt 1 view .LVU3289
.LVL901:
	.loc 1 30254 39 view .LVU3290
	cmpq	%rax, %r8
	jbe	.L756
	.loc 1 30255 17 view .LVU3291
	.loc 1 30255 58 is_stmt 0 view .LVU3292
	movss	(%rsi,%rax,4), %xmm0
.LBE2005:
.LBE2004:
.LBE2010:
.LBE2016:
.LBE2001:
.LBE2000:
	.loc 1 30326 1 view .LVU3293
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
.LBB2027:
.LBB2022:
.LBB2017:
.LBB2011:
.LBB2008:
.LBB2006:
	.loc 1 30255 38 view .LVU3294
	movss	%xmm0, (%rdi,%rax,4)
	.loc 1 30254 13 is_stmt 1 view .LVU3295
	.loc 1 30254 39 view .LVU3296
.LBE2006:
.LBE2008:
.LBE2011:
.LBE2017:
.LBE2022:
.LBE2027:
	.loc 1 30326 1 is_stmt 0 view .LVU3297
	ret
.LVL902:
	.p2align 4,,10
	.p2align 3
.L763:
	.cfi_restore_state
	.loc 1 30319 5 is_stmt 1 view .LVU3298
	.loc 1 30319 25 view .LVU3299
.LBB2028:
.LBI2028:
	.loc 1 30290 13 view .LVU3300
.LBB2029:
	.loc 1 30292 5 view .LVU3301
.LBB2030:
.LBI2030:
	.loc 1 30177 13 view .LVU3302
.LBB2031:
	.loc 1 30179 5 view .LVU3303
	.loc 1 30181 5 view .LVU3304
	testq	%rdi, %rdi
	je	.L756
	testq	%rsi, %rsi
	je	.L756
.LBE2031:
.LBE2030:
	.loc 1 30292 74 is_stmt 0 view .LVU3305
	movl	%r8d, %r8d
.LVL903:
	.loc 1 30292 39 view .LVU3306
	imulq	%rdx, %r8
.LVL904:
.LBB2038:
.LBB2036:
.LBB2032:
.LBB2033:
	.loc 1 30185 31 is_stmt 1 view .LVU3307
	testq	%r8, %r8
	je	.L756
	leaq	1(%rsi), %rdx
.LVL905:
	.loc 1 30185 31 is_stmt 0 view .LVU3308
	movq	%rdi, %rax
	subq	%rdx, %rax
	cmpq	$14, %rax
	jbe	.L795
	leaq	-1(%r8), %rax
	cmpq	$14, %rax
	jbe	.L795
	movq	%r8, %rdx
	movdqa	.LC76(%rip), %xmm7
	movaps	%xmm0, %xmm5
	xorl	%eax, %eax
	andq	$-16, %rdx
	.loc 1 30186 61 view .LVU3309
	pxor	%xmm6, %xmm6
	pxor	%xmm4, %xmm4
	shufps	$0, %xmm5, %xmm5
.LVL906:
	.p2align 4,,10
	.p2align 3
.L769:
	.loc 1 30186 9 is_stmt 1 view .LVU3310
	.loc 1 30186 61 is_stmt 0 view .LVU3311
	movdqu	(%rsi,%rax), %xmm3
	movdqa	%xmm3, %xmm1
	punpckhbw	%xmm6, %xmm3
	punpcklbw	%xmm6, %xmm1
	movdqa	%xmm1, %xmm0
	punpckhwd	%xmm4, %xmm1
	punpcklwd	%xmm4, %xmm0
	.loc 1 30186 63 view .LVU3312
	cvtdq2ps	%xmm1, %xmm1
	cvtdq2ps	%xmm0, %xmm0
	mulps	%xmm5, %xmm1
	mulps	%xmm5, %xmm0
	.loc 1 30186 32 view .LVU3313
	cvttps2dq	%xmm1, %xmm1
	cvttps2dq	%xmm0, %xmm0
	movdqa	%xmm0, %xmm8
	punpcklwd	%xmm1, %xmm0
	punpckhwd	%xmm1, %xmm8
	movdqa	%xmm0, %xmm1
	punpckhwd	%xmm8, %xmm1
	punpcklwd	%xmm8, %xmm0
	punpcklwd	%xmm1, %xmm0
	.loc 1 30186 61 view .LVU3314
	movdqa	%xmm3, %xmm1
	punpckhwd	%xmm4, %xmm3
	punpcklwd	%xmm4, %xmm1
	.loc 1 30186 63 view .LVU3315
	cvtdq2ps	%xmm3, %xmm3
	.loc 1 30186 32 view .LVU3316
	pand	%xmm7, %xmm0
	.loc 1 30186 63 view .LVU3317
	mulps	%xmm5, %xmm3
	cvtdq2ps	%xmm1, %xmm1
	mulps	%xmm5, %xmm1
	.loc 1 30186 32 view .LVU3318
	cvttps2dq	%xmm3, %xmm3
	cvttps2dq	%xmm1, %xmm1
	movdqa	%xmm1, %xmm8
	punpcklwd	%xmm3, %xmm1
	punpckhwd	%xmm3, %xmm8
	movdqa	%xmm1, %xmm3
	punpckhwd	%xmm8, %xmm3
	punpcklwd	%xmm8, %xmm1
	punpcklwd	%xmm3, %xmm1
	pand	%xmm7, %xmm1
	packuswb	%xmm1, %xmm0
	.loc 1 30186 30 view .LVU3319
	movups	%xmm0, (%rdi,%rax)
	.loc 1 30185 5 is_stmt 1 view .LVU3320
	.loc 1 30185 31 view .LVU3321
	addq	$16, %rax
	cmpq	%rax, %rdx
	jne	.L769
	movq	%r8, %rax
	andq	$-16, %rax
	testb	$15, %r8b
	je	.L756
.LVL907:
	.loc 1 30186 9 view .LVU3322
	.loc 1 30186 61 is_stmt 0 view .LVU3323
	movzbl	(%rsi,%rax), %edx
	.loc 1 30186 63 view .LVU3324
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30186 32 view .LVU3325
	cvttss2sil	%xmm0, %edx
	movb	%dl, (%rdi,%rax)
	.loc 1 30185 5 is_stmt 1 view .LVU3326
	.loc 1 30185 54 is_stmt 0 view .LVU3327
	leaq	1(%rax), %rdx
.LVL908:
	.loc 1 30185 31 is_stmt 1 view .LVU3328
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30186 9 view .LVU3329
	.loc 1 30186 61 is_stmt 0 view .LVU3330
	movzbl	1(%rsi,%rax), %edx
.LVL909:
	.loc 1 30186 63 view .LVU3331
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30186 32 view .LVU3332
	cvttss2sil	%xmm0, %edx
	movb	%dl, 1(%rdi,%rax)
	.loc 1 30185 5 is_stmt 1 view .LVU3333
	.loc 1 30185 54 is_stmt 0 view .LVU3334
	leaq	2(%rax), %rdx
.LVL910:
	.loc 1 30185 31 is_stmt 1 view .LVU3335
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30186 9 view .LVU3336
	.loc 1 30186 61 is_stmt 0 view .LVU3337
	movzbl	2(%rsi,%rax), %edx
.LVL911:
	.loc 1 30186 63 view .LVU3338
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30186 32 view .LVU3339
	cvttss2sil	%xmm0, %edx
	movb	%dl, 2(%rdi,%rax)
	.loc 1 30185 5 is_stmt 1 view .LVU3340
	.loc 1 30185 54 is_stmt 0 view .LVU3341
	leaq	3(%rax), %rdx
.LVL912:
	.loc 1 30185 31 is_stmt 1 view .LVU3342
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30186 9 view .LVU3343
	.loc 1 30186 61 is_stmt 0 view .LVU3344
	movzbl	3(%rsi,%rax), %edx
.LVL913:
	.loc 1 30186 63 view .LVU3345
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30186 32 view .LVU3346
	cvttss2sil	%xmm0, %edx
	movb	%dl, 3(%rdi,%rax)
	.loc 1 30185 5 is_stmt 1 view .LVU3347
	.loc 1 30185 54 is_stmt 0 view .LVU3348
	leaq	4(%rax), %rdx
.LVL914:
	.loc 1 30185 31 is_stmt 1 view .LVU3349
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30186 9 view .LVU3350
	.loc 1 30186 61 is_stmt 0 view .LVU3351
	movzbl	4(%rsi,%rax), %edx
.LVL915:
	.loc 1 30186 63 view .LVU3352
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30186 32 view .LVU3353
	cvttss2sil	%xmm0, %edx
	movb	%dl, 4(%rdi,%rax)
	.loc 1 30185 5 is_stmt 1 view .LVU3354
	.loc 1 30185 54 is_stmt 0 view .LVU3355
	leaq	5(%rax), %rdx
.LVL916:
	.loc 1 30185 31 is_stmt 1 view .LVU3356
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30186 9 view .LVU3357
	.loc 1 30186 61 is_stmt 0 view .LVU3358
	movzbl	5(%rsi,%rax), %edx
.LVL917:
	.loc 1 30186 63 view .LVU3359
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30186 32 view .LVU3360
	cvttss2sil	%xmm0, %edx
	movb	%dl, 5(%rdi,%rax)
	.loc 1 30185 5 is_stmt 1 view .LVU3361
	.loc 1 30185 54 is_stmt 0 view .LVU3362
	leaq	6(%rax), %rdx
.LVL918:
	.loc 1 30185 31 is_stmt 1 view .LVU3363
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30186 9 view .LVU3364
	.loc 1 30186 61 is_stmt 0 view .LVU3365
	movzbl	6(%rsi,%rax), %edx
.LVL919:
	.loc 1 30186 63 view .LVU3366
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30186 32 view .LVU3367
	cvttss2sil	%xmm0, %edx
	movb	%dl, 6(%rdi,%rax)
	.loc 1 30185 5 is_stmt 1 view .LVU3368
	.loc 1 30185 54 is_stmt 0 view .LVU3369
	leaq	7(%rax), %rdx
.LVL920:
	.loc 1 30185 31 is_stmt 1 view .LVU3370
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30186 9 view .LVU3371
	.loc 1 30186 61 is_stmt 0 view .LVU3372
	movzbl	7(%rsi,%rax), %edx
.LVL921:
	.loc 1 30186 63 view .LVU3373
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30186 32 view .LVU3374
	cvttss2sil	%xmm0, %edx
	movb	%dl, 7(%rdi,%rax)
	.loc 1 30185 5 is_stmt 1 view .LVU3375
	.loc 1 30185 54 is_stmt 0 view .LVU3376
	leaq	8(%rax), %rdx
.LVL922:
	.loc 1 30185 31 is_stmt 1 view .LVU3377
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30186 9 view .LVU3378
	.loc 1 30186 61 is_stmt 0 view .LVU3379
	movzbl	8(%rsi,%rax), %edx
.LVL923:
	.loc 1 30186 63 view .LVU3380
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30186 32 view .LVU3381
	cvttss2sil	%xmm0, %edx
	movb	%dl, 8(%rdi,%rax)
	.loc 1 30185 5 is_stmt 1 view .LVU3382
	.loc 1 30185 54 is_stmt 0 view .LVU3383
	leaq	9(%rax), %rdx
.LVL924:
	.loc 1 30185 31 is_stmt 1 view .LVU3384
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30186 9 view .LVU3385
	.loc 1 30186 61 is_stmt 0 view .LVU3386
	movzbl	9(%rsi,%rax), %edx
.LVL925:
	.loc 1 30186 63 view .LVU3387
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30186 32 view .LVU3388
	cvttss2sil	%xmm0, %edx
	movb	%dl, 9(%rdi,%rax)
	.loc 1 30185 5 is_stmt 1 view .LVU3389
	.loc 1 30185 54 is_stmt 0 view .LVU3390
	leaq	10(%rax), %rdx
.LVL926:
	.loc 1 30185 31 is_stmt 1 view .LVU3391
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30186 9 view .LVU3392
	.loc 1 30186 61 is_stmt 0 view .LVU3393
	movzbl	10(%rsi,%rax), %edx
.LVL927:
	.loc 1 30186 63 view .LVU3394
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30186 32 view .LVU3395
	cvttss2sil	%xmm0, %edx
	movb	%dl, 10(%rdi,%rax)
	.loc 1 30185 5 is_stmt 1 view .LVU3396
	.loc 1 30185 54 is_stmt 0 view .LVU3397
	leaq	11(%rax), %rdx
.LVL928:
	.loc 1 30185 31 is_stmt 1 view .LVU3398
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30186 9 view .LVU3399
	.loc 1 30186 61 is_stmt 0 view .LVU3400
	movzbl	11(%rsi,%rax), %edx
.LVL929:
	.loc 1 30186 63 view .LVU3401
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30186 32 view .LVU3402
	cvttss2sil	%xmm0, %edx
	movb	%dl, 11(%rdi,%rax)
	.loc 1 30185 5 is_stmt 1 view .LVU3403
	.loc 1 30185 54 is_stmt 0 view .LVU3404
	leaq	12(%rax), %rdx
.LVL930:
	.loc 1 30185 31 is_stmt 1 view .LVU3405
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30186 9 view .LVU3406
	.loc 1 30186 61 is_stmt 0 view .LVU3407
	movzbl	12(%rsi,%rax), %edx
.LVL931:
	.loc 1 30186 63 view .LVU3408
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30186 32 view .LVU3409
	cvttss2sil	%xmm0, %edx
	movb	%dl, 12(%rdi,%rax)
	.loc 1 30185 5 is_stmt 1 view .LVU3410
	.loc 1 30185 54 is_stmt 0 view .LVU3411
	leaq	13(%rax), %rdx
.LVL932:
	.loc 1 30185 31 is_stmt 1 view .LVU3412
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30186 9 view .LVU3413
	.loc 1 30186 61 is_stmt 0 view .LVU3414
	movzbl	13(%rsi,%rax), %edx
.LVL933:
	.loc 1 30186 63 view .LVU3415
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30186 32 view .LVU3416
	cvttss2sil	%xmm0, %edx
	movb	%dl, 13(%rdi,%rax)
	.loc 1 30185 5 is_stmt 1 view .LVU3417
	.loc 1 30185 54 is_stmt 0 view .LVU3418
	leaq	14(%rax), %rdx
.LVL934:
	.loc 1 30185 31 is_stmt 1 view .LVU3419
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30186 9 view .LVU3420
	.loc 1 30186 61 is_stmt 0 view .LVU3421
	movzbl	14(%rsi,%rax), %edx
.LVL935:
	.loc 1 30186 63 view .LVU3422
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30186 32 view .LVU3423
	cvttss2sil	%xmm0, %edx
	movb	%dl, 14(%rdi,%rax)
	.loc 1 30185 5 is_stmt 1 view .LVU3424
.LVL936:
	.loc 1 30185 31 view .LVU3425
.LBE2033:
.LBE2032:
.LBE2036:
.LBE2038:
.LBE2029:
.LBE2028:
	.loc 1 30326 1 is_stmt 0 view .LVU3426
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL937:
	.p2align 4,,10
	.p2align 3
.L762:
	.cfi_restore_state
	.loc 1 30320 5 is_stmt 1 view .LVU3427
	.loc 1 30320 25 view .LVU3428
.LBB2041:
.LBI2041:
	.loc 1 30295 13 view .LVU3429
.LBB2042:
	.loc 1 30297 5 view .LVU3430
.LBB2043:
.LBI2043:
	.loc 1 30190 13 view .LVU3431
.LBB2044:
	.loc 1 30192 5 view .LVU3432
	.loc 1 30194 5 view .LVU3433
	testq	%rdi, %rdi
	je	.L756
	testq	%rsi, %rsi
	je	.L756
.LBE2044:
.LBE2043:
	.loc 1 30297 75 is_stmt 0 view .LVU3434
	movl	%r8d, %r8d
.LVL938:
	.loc 1 30297 40 view .LVU3435
	imulq	%rdx, %r8
.LVL939:
.LBB2054:
.LBB2051:
.LBB2045:
.LBB2046:
	.loc 1 30198 31 is_stmt 1 view .LVU3436
	testq	%r8, %r8
	je	.L756
	leaq	2(%rsi), %rdx
.LVL940:
	.loc 1 30198 31 is_stmt 0 view .LVU3437
	movq	%rdi, %rax
	subq	%rdx, %rax
	cmpq	$12, %rax
	jbe	.L796
	leaq	-1(%r8), %rax
	cmpq	$6, %rax
	jbe	.L796
	movq	%r8, %rdx
	movaps	%xmm0, %xmm4
	.loc 1 30199 63 view .LVU3438
	pxor	%xmm5, %xmm5
	.loc 1 30198 31 view .LVU3439
	xorl	%eax, %eax
	shrq	$3, %rdx
	shufps	$0, %xmm4, %xmm4
	salq	$4, %rdx
.LVL941:
	.p2align 4,,10
	.p2align 3
.L774:
	.loc 1 30199 9 is_stmt 1 view .LVU3440
	.loc 1 30199 61 is_stmt 0 view .LVU3441
	movdqu	(%rsi,%rax), %xmm1
	.loc 1 30199 63 view .LVU3442
	movdqa	%xmm5, %xmm3
	pcmpgtw	%xmm1, %xmm3
	movdqa	%xmm1, %xmm0
	punpcklwd	%xmm3, %xmm0
	punpckhwd	%xmm3, %xmm1
	cvtdq2ps	%xmm0, %xmm0
	cvtdq2ps	%xmm1, %xmm1
	mulps	%xmm4, %xmm0
	mulps	%xmm4, %xmm1
	.loc 1 30199 32 view .LVU3443
	cvttps2dq	%xmm0, %xmm0
	movdqa	%xmm0, %xmm3
	cvttps2dq	%xmm1, %xmm1
	punpcklwd	%xmm1, %xmm0
	punpckhwd	%xmm1, %xmm3
	movdqa	%xmm0, %xmm1
	punpcklwd	%xmm3, %xmm0
	punpckhwd	%xmm3, %xmm1
	punpcklwd	%xmm1, %xmm0
	.loc 1 30199 30 view .LVU3444
	movups	%xmm0, (%rdi,%rax)
	.loc 1 30198 5 is_stmt 1 view .LVU3445
	.loc 1 30198 31 view .LVU3446
	addq	$16, %rax
	cmpq	%rax, %rdx
	jne	.L774
	movq	%r8, %rax
	andq	$-8, %rax
	testb	$7, %r8b
	je	.L756
.LVL942:
	.loc 1 30199 9 view .LVU3447
	.loc 1 30199 63 is_stmt 0 view .LVU3448
	movswl	(%rsi,%rax,2), %edx
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30199 32 view .LVU3449
	cvttss2sil	%xmm0, %edx
	movw	%dx, (%rdi,%rax,2)
	.loc 1 30198 5 is_stmt 1 view .LVU3450
	.loc 1 30198 54 is_stmt 0 view .LVU3451
	leaq	1(%rax), %rdx
.LVL943:
	.loc 1 30198 31 is_stmt 1 view .LVU3452
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30199 9 view .LVU3453
	.loc 1 30199 63 is_stmt 0 view .LVU3454
	movswl	(%rsi,%rdx,2), %ecx
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%ecx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30199 32 view .LVU3455
	cvttss2sil	%xmm0, %ecx
	movw	%cx, (%rdi,%rdx,2)
	.loc 1 30198 5 is_stmt 1 view .LVU3456
	.loc 1 30198 54 is_stmt 0 view .LVU3457
	leaq	2(%rax), %rdx
.LVL944:
	.loc 1 30198 31 is_stmt 1 view .LVU3458
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30199 9 view .LVU3459
	.loc 1 30199 63 is_stmt 0 view .LVU3460
	movswl	(%rsi,%rdx,2), %ecx
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%ecx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30199 32 view .LVU3461
	cvttss2sil	%xmm0, %ecx
	movw	%cx, (%rdi,%rdx,2)
	.loc 1 30198 5 is_stmt 1 view .LVU3462
	.loc 1 30198 54 is_stmt 0 view .LVU3463
	leaq	3(%rax), %rdx
.LVL945:
	.loc 1 30198 31 is_stmt 1 view .LVU3464
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30199 9 view .LVU3465
	.loc 1 30199 63 is_stmt 0 view .LVU3466
	movswl	(%rsi,%rdx,2), %ecx
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%ecx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30199 32 view .LVU3467
	cvttss2sil	%xmm0, %ecx
	movw	%cx, (%rdi,%rdx,2)
	.loc 1 30198 5 is_stmt 1 view .LVU3468
	.loc 1 30198 54 is_stmt 0 view .LVU3469
	leaq	4(%rax), %rdx
.LVL946:
	.loc 1 30198 31 is_stmt 1 view .LVU3470
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30199 9 view .LVU3471
	.loc 1 30199 63 is_stmt 0 view .LVU3472
	movswl	(%rsi,%rdx,2), %ecx
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%ecx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30199 32 view .LVU3473
	cvttss2sil	%xmm0, %ecx
	movw	%cx, (%rdi,%rdx,2)
	.loc 1 30198 5 is_stmt 1 view .LVU3474
	.loc 1 30198 54 is_stmt 0 view .LVU3475
	leaq	5(%rax), %rdx
.LVL947:
	.loc 1 30198 31 is_stmt 1 view .LVU3476
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30199 9 view .LVU3477
	.loc 1 30199 63 is_stmt 0 view .LVU3478
	movswl	(%rsi,%rdx,2), %ecx
	pxor	%xmm0, %xmm0
	.loc 1 30198 54 view .LVU3479
	addq	$6, %rax
	.loc 1 30199 63 view .LVU3480
	cvtsi2ssl	%ecx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30199 32 view .LVU3481
	cvttss2sil	%xmm0, %ecx
	movw	%cx, (%rdi,%rdx,2)
	.loc 1 30198 5 is_stmt 1 view .LVU3482
.LVL948:
	.loc 1 30198 31 view .LVU3483
	cmpq	%rax, %r8
	jbe	.L756
	.loc 1 30199 9 view .LVU3484
	.loc 1 30199 63 is_stmt 0 view .LVU3485
	movswl	(%rsi,%rax,2), %edx
	pxor	%xmm0, %xmm0
.LBE2046:
.LBE2045:
.LBE2051:
.LBE2054:
.LBE2042:
.LBE2041:
	.loc 1 30326 1 view .LVU3486
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
.LBB2059:
.LBB2057:
.LBB2055:
.LBB2052:
.LBB2049:
.LBB2047:
	.loc 1 30199 63 view .LVU3487
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30199 32 view .LVU3488
	cvttss2sil	%xmm0, %edx
	movw	%dx, (%rdi,%rax,2)
	.loc 1 30198 5 is_stmt 1 view .LVU3489
	.loc 1 30198 31 view .LVU3490
.LBE2047:
.LBE2049:
.LBE2052:
.LBE2055:
.LBE2057:
.LBE2059:
	.loc 1 30326 1 is_stmt 0 view .LVU3491
	ret
.LVL949:
	.p2align 4,,10
	.p2align 3
.L760:
	.cfi_restore_state
	.loc 1 30322 5 is_stmt 1 view .LVU3492
	.loc 1 30322 25 view .LVU3493
.LBB2060:
.LBI2060:
	.loc 1 30305 13 view .LVU3494
.LBB2061:
	.loc 1 30307 5 view .LVU3495
.LBB2062:
.LBI2062:
	.loc 1 30228 13 view .LVU3496
.LBB2063:
	.loc 1 30230 5 view .LVU3497
	.loc 1 30232 5 view .LVU3498
	testq	%rdi, %rdi
	je	.L756
	testq	%rsi, %rsi
	je	.L756
.LBE2063:
.LBE2062:
	.loc 1 30307 75 is_stmt 0 view .LVU3499
	movl	%r8d, %r8d
.LVL950:
	.loc 1 30307 40 view .LVU3500
	imulq	%rdx, %r8
.LVL951:
.LBB2073:
.LBB2070:
.LBB2064:
.LBB2065:
	.loc 1 30236 31 is_stmt 1 view .LVU3501
	testq	%r8, %r8
	je	.L756
	leaq	4(%rsi), %rdx
.LVL952:
	.loc 1 30236 31 is_stmt 0 view .LVU3502
	movq	%rdi, %rax
	subq	%rdx, %rax
	cmpq	$8, %rax
	jbe	.L797
	leaq	-1(%r8), %rax
	cmpq	$2, %rax
	jbe	.L797
	movq	%r8, %rdx
	movaps	%xmm0, %xmm1
	xorl	%eax, %eax
	shrq	$2, %rdx
	shufps	$0, %xmm1, %xmm1
	salq	$4, %rdx
.LVL953:
	.p2align 4,,10
	.p2align 3
.L780:
	.loc 1 30237 9 is_stmt 1 view .LVU3503
	.loc 1 30237 63 is_stmt 0 view .LVU3504
	movdqu	(%rsi,%rax), %xmm6
	cvtdq2ps	%xmm6, %xmm0
	mulps	%xmm1, %xmm0
	.loc 1 30237 32 view .LVU3505
	cvttps2dq	%xmm0, %xmm0
	.loc 1 30237 30 view .LVU3506
	movups	%xmm0, (%rdi,%rax)
	.loc 1 30236 5 is_stmt 1 view .LVU3507
	.loc 1 30236 31 view .LVU3508
	addq	$16, %rax
	cmpq	%rdx, %rax
	jne	.L780
	movq	%r8, %rax
	andq	$-4, %rax
	testb	$3, %r8b
	je	.L756
.LVL954:
	.loc 1 30237 9 view .LVU3509
	.loc 1 30237 63 is_stmt 0 view .LVU3510
	pxor	%xmm0, %xmm0
	cvtsi2ssl	(%rsi,%rax,4), %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30237 32 view .LVU3511
	cvttss2sil	%xmm0, %edx
	movl	%edx, (%rdi,%rax,4)
	.loc 1 30236 5 is_stmt 1 view .LVU3512
	.loc 1 30236 54 is_stmt 0 view .LVU3513
	leaq	1(%rax), %rdx
.LVL955:
	.loc 1 30236 31 is_stmt 1 view .LVU3514
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30237 9 view .LVU3515
	.loc 1 30237 63 is_stmt 0 view .LVU3516
	pxor	%xmm0, %xmm0
	.loc 1 30236 54 view .LVU3517
	addq	$2, %rax
	.loc 1 30237 63 view .LVU3518
	cvtsi2ssl	(%rsi,%rdx,4), %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30237 32 view .LVU3519
	cvttss2sil	%xmm0, %ecx
	movl	%ecx, (%rdi,%rdx,4)
	.loc 1 30236 5 is_stmt 1 view .LVU3520
.LVL956:
	.loc 1 30236 31 view .LVU3521
	cmpq	%rax, %r8
	jbe	.L756
	.loc 1 30237 9 view .LVU3522
	.loc 1 30237 63 is_stmt 0 view .LVU3523
	pxor	%xmm0, %xmm0
.LBE2065:
.LBE2064:
.LBE2070:
.LBE2073:
.LBE2061:
.LBE2060:
	.loc 1 30326 1 view .LVU3524
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
.LBB2078:
.LBB2076:
.LBB2074:
.LBB2071:
.LBB2068:
.LBB2066:
	.loc 1 30237 63 view .LVU3525
	cvtsi2ssl	(%rsi,%rax,4), %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30237 32 view .LVU3526
	cvttss2sil	%xmm0, %edx
	movl	%edx, (%rdi,%rax,4)
	.loc 1 30236 5 is_stmt 1 view .LVU3527
	.loc 1 30236 31 view .LVU3528
.LBE2066:
.LBE2068:
.LBE2071:
.LBE2074:
.LBE2076:
.LBE2078:
	.loc 1 30326 1 is_stmt 0 view .LVU3529
	ret
.LVL957:
	.p2align 4,,10
	.p2align 3
.L849:
	.cfi_restore_state
.LBB2079:
.LBB2023:
.LBB2018:
.LBB2012:
	.loc 1 30259 35 is_stmt 1 view .LVU3530
	testq	%r8, %r8
	je	.L756
	leaq	4(%rsi), %rdx
.LVL958:
	.loc 1 30259 35 is_stmt 0 view .LVU3531
	movq	%rdi, %rax
	subq	%rdx, %rax
	cmpq	$8, %rax
	jbe	.L799
	leaq	-1(%r8), %rax
	cmpq	$2, %rax
	jbe	.L799
	movq	%r8, %rdx
	movaps	%xmm0, %xmm1
	xorl	%eax, %eax
	shrq	$2, %rdx
	shufps	$0, %xmm1, %xmm1
	salq	$4, %rdx
.LVL959:
	.p2align 4,,10
	.p2align 3
.L792:
	.loc 1 30260 13 is_stmt 1 view .LVU3532
	.loc 1 30260 56 is_stmt 0 view .LVU3533
	movups	(%rsi,%rax), %xmm0
	mulps	%xmm1, %xmm0
	.loc 1 30260 34 view .LVU3534
	movups	%xmm0, (%rdi,%rax)
	.loc 1 30259 9 is_stmt 1 view .LVU3535
	.loc 1 30259 35 view .LVU3536
	addq	$16, %rax
	cmpq	%rdx, %rax
	jne	.L792
	movq	%r8, %rax
	andq	$-4, %rax
	testb	$3, %r8b
	je	.L756
.LVL960:
	.loc 1 30260 13 view .LVU3537
	.loc 1 30260 56 is_stmt 0 view .LVU3538
	movss	(%rsi,%rax,4), %xmm0
	.loc 1 30259 58 view .LVU3539
	leaq	1(%rax), %rdx
	.loc 1 30260 56 view .LVU3540
	mulss	%xmm2, %xmm0
	.loc 1 30260 34 view .LVU3541
	movss	%xmm0, (%rdi,%rax,4)
	.loc 1 30259 9 is_stmt 1 view .LVU3542
.LVL961:
	.loc 1 30259 35 view .LVU3543
	cmpq	%rdx, %r8
	jbe	.L756
	.loc 1 30260 13 view .LVU3544
	.loc 1 30260 56 is_stmt 0 view .LVU3545
	movss	(%rsi,%rdx,4), %xmm0
	.loc 1 30259 58 view .LVU3546
	addq	$2, %rax
	.loc 1 30260 56 view .LVU3547
	mulss	%xmm2, %xmm0
	.loc 1 30260 34 view .LVU3548
	movss	%xmm0, (%rdi,%rdx,4)
	.loc 1 30259 9 is_stmt 1 view .LVU3549
.LVL962:
	.loc 1 30259 35 view .LVU3550
	cmpq	%rax, %r8
	jbe	.L756
	.loc 1 30260 13 view .LVU3551
	.loc 1 30260 56 is_stmt 0 view .LVU3552
	mulss	(%rsi,%rax,4), %xmm2
.LVL963:
	.loc 1 30260 56 view .LVU3553
.LBE2012:
.LBE2018:
.LBE2023:
.LBE2079:
	.loc 1 30326 1 view .LVU3554
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
.LBB2080:
.LBB2024:
.LBB2019:
.LBB2013:
	.loc 1 30260 34 view .LVU3555
	movss	%xmm2, (%rdi,%rax,4)
	.loc 1 30259 9 is_stmt 1 view .LVU3556
	.loc 1 30259 35 view .LVU3557
.LBE2013:
.LBE2019:
.LBE2024:
.LBE2080:
	.loc 1 30326 1 is_stmt 0 view .LVU3558
	ret
.LVL964:
	.p2align 4,,10
	.p2align 3
.L795:
	.cfi_restore_state
.LBB2081:
.LBB2040:
.LBB2039:
.LBB2037:
.LBB2035:
.LBB2034:
	.loc 1 30185 18 view .LVU3559
	xorl	%eax, %eax
.LVL965:
	.p2align 4,,10
	.p2align 3
.L767:
	.loc 1 30186 9 is_stmt 1 view .LVU3560
	.loc 1 30186 61 is_stmt 0 view .LVU3561
	movzbl	(%rsi,%rax), %edx
	.loc 1 30186 63 view .LVU3562
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30186 32 view .LVU3563
	cvttss2sil	%xmm0, %edx
	movb	%dl, (%rdi,%rax)
	.loc 1 30185 5 is_stmt 1 view .LVU3564
	.loc 1 30185 54 is_stmt 0 view .LVU3565
	addq	$1, %rax
.LVL966:
	.loc 1 30185 31 is_stmt 1 view .LVU3566
	cmpq	%rax, %r8
	jne	.L767
.LBE2034:
.LBE2035:
.LBE2037:
.LBE2039:
.LBE2040:
.LBE2081:
	.loc 1 30326 1 is_stmt 0 view .LVU3567
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL967:
	.p2align 4,,10
	.p2align 3
.L797:
	.cfi_restore_state
.LBB2082:
.LBB2077:
.LBB2075:
.LBB2072:
.LBB2069:
.LBB2067:
	.loc 1 30236 18 view .LVU3568
	xorl	%eax, %eax
.LVL968:
	.p2align 4,,10
	.p2align 3
.L778:
	.loc 1 30237 9 is_stmt 1 view .LVU3569
	.loc 1 30237 63 is_stmt 0 view .LVU3570
	pxor	%xmm0, %xmm0
	cvtsi2ssl	(%rsi,%rax,4), %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30237 32 view .LVU3571
	cvttss2sil	%xmm0, %edx
	movl	%edx, (%rdi,%rax,4)
	.loc 1 30236 5 is_stmt 1 view .LVU3572
	.loc 1 30236 54 is_stmt 0 view .LVU3573
	addq	$1, %rax
.LVL969:
	.loc 1 30236 31 is_stmt 1 view .LVU3574
	cmpq	%rax, %r8
	jne	.L778
.LBE2067:
.LBE2069:
.LBE2072:
.LBE2075:
.LBE2077:
.LBE2082:
	.loc 1 30326 1 is_stmt 0 view .LVU3575
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL970:
	.p2align 4,,10
	.p2align 3
.L796:
	.cfi_restore_state
.LBB2083:
.LBB2058:
.LBB2056:
.LBB2053:
.LBB2050:
.LBB2048:
	.loc 1 30198 18 view .LVU3576
	xorl	%eax, %eax
.LVL971:
	.p2align 4,,10
	.p2align 3
.L772:
	.loc 1 30199 9 is_stmt 1 view .LVU3577
	.loc 1 30199 63 is_stmt 0 view .LVU3578
	movswl	(%rsi,%rax,2), %edx
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edx, %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30199 32 view .LVU3579
	cvttss2sil	%xmm0, %edx
	movw	%dx, (%rdi,%rax,2)
	.loc 1 30198 5 is_stmt 1 view .LVU3580
	.loc 1 30198 54 is_stmt 0 view .LVU3581
	addq	$1, %rax
.LVL972:
	.loc 1 30198 31 is_stmt 1 view .LVU3582
	cmpq	%rax, %r8
	jne	.L772
.LBE2048:
.LBE2050:
.LBE2053:
.LBE2056:
.LBE2058:
.LBE2083:
	.loc 1 30326 1 is_stmt 0 view .LVU3583
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL973:
.L799:
	.cfi_restore_state
.LBB2084:
.LBB2025:
.LBB2020:
.LBB2014:
	.loc 1 30259 22 view .LVU3584
	xorl	%eax, %eax
.LVL974:
	.p2align 4,,10
	.p2align 3
.L790:
	.loc 1 30260 13 is_stmt 1 view .LVU3585
	.loc 1 30260 56 is_stmt 0 view .LVU3586
	movss	(%rsi,%rax,4), %xmm0
	mulss	%xmm2, %xmm0
	.loc 1 30260 34 view .LVU3587
	movss	%xmm0, (%rdi,%rax,4)
	.loc 1 30259 9 is_stmt 1 view .LVU3588
	.loc 1 30259 58 is_stmt 0 view .LVU3589
	addq	$1, %rax
.LVL975:
	.loc 1 30259 35 is_stmt 1 view .LVU3590
	cmpq	%rax, %r8
	jne	.L790
.LBE2014:
.LBE2020:
.LBE2025:
.LBE2084:
	.loc 1 30326 1 is_stmt 0 view .LVU3591
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL976:
.L798:
	.cfi_restore_state
.LBB2085:
.LBB2026:
.LBB2021:
.LBB2015:
.LBB2009:
.LBB2007:
	.loc 1 30254 26 view .LVU3592
	xorl	%eax, %eax
.LVL977:
	.p2align 4,,10
	.p2align 3
.L785:
	.loc 1 30255 17 is_stmt 1 view .LVU3593
	.loc 1 30255 58 is_stmt 0 view .LVU3594
	movss	(%rsi,%rax,4), %xmm0
	.loc 1 30255 38 view .LVU3595
	movss	%xmm0, (%rdi,%rax,4)
	.loc 1 30254 13 is_stmt 1 view .LVU3596
	.loc 1 30254 62 is_stmt 0 view .LVU3597
	addq	$1, %rax
.LVL978:
	.loc 1 30254 39 is_stmt 1 view .LVU3598
	cmpq	%rax, %r8
	jne	.L785
.LBE2007:
.LBE2009:
.LBE2015:
.LBE2021:
.LBE2026:
.LBE2085:
	.loc 1 30326 1 is_stmt 0 view .LVU3599
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE116:
	.size	ma_copy_and_apply_volume_factor_pcm_frames, .-ma_copy_and_apply_volume_factor_pcm_frames
	.section	.rodata.str1.8
	.align 8
.LC78:
	.string	"void ma_copy_and_apply_volume_and_clip_pcm_frames(void*, const void*, ma_uint64, ma_format, ma_uint32, float)"
	.section	.rodata.str1.1
.LC79:
	.string	"pDst != __null"
.LC80:
	.string	"pSrc != __null"
	.text
	.p2align 4
	.globl	ma_copy_and_apply_volume_and_clip_pcm_frames
	.hidden	ma_copy_and_apply_volume_and_clip_pcm_frames
	.type	ma_copy_and_apply_volume_and_clip_pcm_frames, @function
ma_copy_and_apply_volume_and_clip_pcm_frames:
.LVL979:
.LFB123:
	.loc 1 30481 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 30481 1 is_stmt 0 view .LVU3601
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	.cfi_offset 3, -40
1:	call	mcount
	.loc 1 30481 1 view .LVU3602
	.loc 1 30482 5 is_stmt 1 view .LVU3603
	testq	%rdi, %rdi
	je	.L1045
	.loc 1 30483 5 view .LVU3604
	testq	%rsi, %rsi
	je	.L1046
	.loc 1 30485 5 view .LVU3605
.LBB2229:
	movss	.LC77(%rip), %xmm2
	comiss	%xmm2, %xmm0
	je	.L1047
.LBE2229:
	.loc 1 30487 12 view .LVU3606
.LBB2401:
.LBB2230:
	comiss	.LC5(%rip), %xmm0
	je	.L1048
.LVL980:
	.loc 1 30487 12 is_stmt 0 view .LVU3607
.LBE2230:
.LBE2401:
.LBB2402:
.LBI2402:
	.loc 1 30480 13 is_stmt 1 view .LVU3608
.LBB2403:
	.loc 1 30490 9 view .LVU3609
	.loc 1 30490 46 is_stmt 0 view .LVU3610
	movl	%r8d, %ebx
	.loc 1 30490 19 view .LVU3611
	imulq	%rdx, %rbx
.LVL981:
	.loc 1 30492 9 is_stmt 1 view .LVU3612
	cmpl	$5, %ecx
	ja	.L850
	movl	%ecx, %ecx
	.loc 1 30492 9 is_stmt 0 view .LVU3613
	jmp	*.L903(,%rcx,8)
	.section	.rodata
	.align 8
	.align 4
.L903:
	.quad	.L850
	.quad	.L907
	.quad	.L906
	.quad	.L905
	.quad	.L904
	.quad	.L902
	.text
.LVL982:
	.p2align 4,,10
	.p2align 3
.L1048:
	.loc 1 30492 9 view .LVU3614
.LBE2403:
.LBE2402:
.LBB2740:
.LBB2252:
	.loc 1 30488 9 is_stmt 1 view .LVU3615
.LBB2231:
.LBI2231:
	.loc 1 30066 13 view .LVU3616
.LBE2231:
.LBE2252:
.LBE2740:
	.loc 1 30068 5 view .LVU3617
.LBB2741:
.LBB2253:
.LBB2249:
.LBB2232:
	cmpl	$1, %ecx
	jne	.L900
.LBB2233:
	.loc 1 30069 9 view .LVU3618
	.loc 1 30069 46 is_stmt 0 view .LVU3619
	movl	%r8d, %r8d
.LVL983:
	.loc 1 30069 19 view .LVU3620
	imulq	%r8, %rdx
.LVL984:
	.loc 1 30070 9 is_stmt 1 view .LVU3621
	.loc 1 30071 9 view .LVU3622
	.loc 1 30071 35 view .LVU3623
	testq	%rdx, %rdx
	je	.L850
.LBE2233:
.LBE2232:
.LBE2249:
.LBE2253:
.LBE2741:
	.loc 1 30505 1 is_stmt 0 view .LVU3624
	addq	$40, %rsp
.LBB2742:
.LBB2254:
.LBB2250:
.LBB2236:
.LBB2234:
	.loc 1 30072 37 view .LVU3625
	movl	$128, %esi
.LVL985:
	.loc 1 30072 37 view .LVU3626
.LBE2234:
.LBE2236:
.LBE2250:
.LBE2254:
.LBE2742:
	.loc 1 30505 1 view .LVU3627
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
.LBB2743:
.LBB2255:
.LBB2251:
.LBB2237:
.LBB2235:
	.loc 1 30072 37 view .LVU3628
	jmp	memset
.LVL986:
	.p2align 4,,10
	.p2align 3
.L900:
	.cfi_restore_state
	.loc 1 30072 37 view .LVU3629
.LBE2235:
.LBE2237:
.LBB2238:
.LBI2238:
	.loc 1 30066 13 is_stmt 1 view .LVU3630
.LBB2239:
	.loc 1 30075 9 view .LVU3631
.LBB2240:
.LBI2240:
	.loc 2 2066 28 view .LVU3632
.LBB2241:
	.loc 2 2066 91 view .LVU3633
.LBB2242:
.LBI2242:
	.loc 1 44154 18 view .LVU3634
.LBB2243:
	.loc 1 44156 5 view .LVU3635
	.loc 1 44156 15 is_stmt 0 view .LVU3636
	movdqa	.LC22(%rip), %xmm0
.LVL987:
	.loc 1 44164 24 view .LVU3637
	movslq	%ecx, %rcx
.LVL988:
	.loc 1 44156 15 view .LVU3638
	movabsq	$17179869188, %rax
	movq	%rax, -48(%rbp)
	.loc 1 44164 5 is_stmt 1 view .LVU3639
.LVL989:
	.loc 1 44156 15 is_stmt 0 view .LVU3640
	movaps	%xmm0, -64(%rbp)
.LBE2243:
.LBE2242:
.LBE2241:
.LBE2240:
	.loc 1 30075 65 view .LVU3641
	imull	-64(%rbp,%rcx,4), %r8d
.LVL990:
	.loc 1 30075 26 view .LVU3642
	movq	%r8, %rbx
	imulq	%rdx, %rbx
.LVL991:
.LBB2244:
.LBI2244:
	.loc 1 1810 23 is_stmt 1 view .LVU3643
.LBB2245:
	.loc 1 1815 5 view .LVU3644
	.loc 1 1815 24 view .LVU3645
	testq	%rbx, %rbx
	je	.L850
	movl	$4294967295, %r13d
.LVL992:
	.p2align 4,,10
	.p2align 3
.L901:
.LBB2246:
	.loc 1 1816 9 view .LVU3646
	.loc 1 1817 9 view .LVU3647
	cmpq	%r13, %rbx
	movq	%r13, %r12
	cmovbe	%rbx, %r12
.LVL993:
.LBB2247:
.LBB2248:
	.loc 1 782 9 view .LVU3648
	.loc 1 782 15 is_stmt 0 view .LVU3649
	xorl	%esi, %esi
	movq	%r12, %rdx
	call	memset
.LVL994:
	.loc 1 782 15 view .LVU3650
	movq	%rax, %rdi
.LBE2248:
.LBE2247:
	.loc 1 1823 9 is_stmt 1 view .LVU3651
.LVL995:
	.loc 1 1824 9 view .LVU3652
	.loc 1 1824 13 is_stmt 0 view .LVU3653
	addq	%r12, %rdi
.LVL996:
	.loc 1 1824 13 view .LVU3654
.LBE2246:
	.loc 1 1815 5 is_stmt 1 view .LVU3655
	.loc 1 1815 24 view .LVU3656
	subq	%r12, %rbx
.LVL997:
	.loc 1 1815 24 is_stmt 0 view .LVU3657
	jne	.L901
.LVL998:
.L850:
	.loc 1 1815 24 view .LVU3658
.LBE2245:
.LBE2244:
.LBE2239:
.LBE2238:
.LBE2251:
.LBE2255:
.LBE2743:
	.loc 1 30505 1 view .LVU3659
	addq	$40, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL999:
	.p2align 4,,10
	.p2align 3
.L1047:
	.cfi_restore_state
.LBB2744:
	.loc 1 30486 9 is_stmt 1 view .LVU3660
.LBB2256:
.LBI2256:
	.loc 1 30153 13 view .LVU3661
.LBB2257:
	.loc 1 30155 5 view .LVU3662
	.loc 1 30157 5 view .LVU3663
	.loc 1 30158 5 view .LVU3664
	.loc 1 30160 5 view .LVU3665
	.loc 1 30160 32 is_stmt 0 view .LVU3666
	movl	%r8d, %ebx
	.loc 1 30160 17 view .LVU3667
	imulq	%rdx, %rbx
.LVL1000:
	.loc 1 30162 5 is_stmt 1 view .LVU3668
	cmpl	$5, %ecx
	ja	.L850
	movl	%ecx, %ecx
.LVL1001:
	.loc 1 30162 5 is_stmt 0 view .LVU3669
	jmp	*.L857(,%rcx,8)
	.section	.rodata
	.align 8
	.align 4
.L857:
	.quad	.L850
	.quad	.L861
	.quad	.L860
	.quad	.L859
	.quad	.L858
	.quad	.L856
	.text
.LVL1002:
	.p2align 4,,10
	.p2align 3
.L904:
	.loc 1 30162 5 view .LVU3670
.LBE2257:
.LBE2256:
.LBE2744:
.LBB2745:
.LBB2731:
	.loc 1 30496 13 is_stmt 1 view .LVU3671
	.loc 1 30496 33 view .LVU3672
.LBB2404:
.LBI2404:
	.loc 1 30451 13 view .LVU3673
.LBB2405:
	.loc 1 30453 5 view .LVU3674
	.loc 1 30454 5 view .LVU3675
	.loc 1 30456 5 view .LVU3676
	.loc 1 30457 5 view .LVU3677
	.loc 1 30459 5 view .LVU3678
.LBB2406:
.LBI2406:
	.loc 1 2406 27 view .LVU3679
.LBB2407:
	.loc 1 2408 5 view .LVU3680
	.loc 1 2408 25 is_stmt 0 view .LVU3681
	mulss	.LC89(%rip), %xmm0
.LVL1003:
	.loc 1 2408 35 view .LVU3682
	cvttss2sil	%xmm0, %r8d
.LVL1004:
	.loc 1 2408 35 view .LVU3683
.LBE2407:
.LBE2406:
	.loc 1 30461 5 is_stmt 1 view .LVU3684
	.loc 1 30461 31 view .LVU3685
	testq	%rbx, %rbx
	je	.L850
.LBE2405:
.LBE2404:
.LBB2419:
.LBB2420:
.LBB2421:
.LBB2422:
.LBB2423:
.LBB2424:
	.loc 1 30389 28 is_stmt 0 view .LVU3686
	movswq	%r8w, %r8
	.loc 1 30389 28 view .LVU3687
.LBE2424:
.LBE2423:
.LBE2422:
.LBE2421:
.LBE2420:
.LBE2419:
.LBB2443:
.LBB2418:
	.loc 1 30461 18 view .LVU3688
	xorl	%eax, %eax
.LBB2408:
.LBB2409:
	.loc 1 2315 22 view .LVU3689
	movl	$-2147483648, %r9d
	movabsq	$-2147483649, %r10
.LVL1005:
	.p2align 4,,10
	.p2align 3
.L936:
	.loc 1 2315 22 view .LVU3690
.LBE2409:
.LBE2408:
	.loc 1 30462 9 is_stmt 1 view .LVU3691
.LBB2412:
.LBI2412:
	.loc 1 30392 27 view .LVU3692
.LBB2413:
	.loc 1 30394 5 view .LVU3693
	.loc 1 30394 26 is_stmt 0 view .LVU3694
	movq	(%rsi,%rax,8), %rdx
.LBE2413:
.LBE2412:
.LBB2415:
.LBB2410:
	.loc 1 2315 22 view .LVU3695
	movl	$2147483647, %ecx
.LBE2410:
.LBE2415:
.LBB2416:
.LBB2414:
	.loc 1 30394 26 view .LVU3696
	imulq	%r8, %rdx
	.loc 1 30394 40 view .LVU3697
	sarq	$8, %rdx
.LVL1006:
	.loc 1 30394 40 view .LVU3698
.LBE2414:
.LBE2416:
.LBB2417:
.LBI2408:
	.loc 1 2307 27 is_stmt 1 view .LVU3699
.LBB2411:
	.loc 1 2310 5 view .LVU3700
	.loc 1 2311 5 view .LVU3701
	.loc 1 2312 5 view .LVU3702
	.loc 1 2313 5 view .LVU3703
	.loc 1 2315 5 view .LVU3704
	.loc 1 2315 22 is_stmt 0 view .LVU3705
	cmpq	$2147483646, %rdx
	jg	.L935
	cmpq	%r10, %rdx
	movl	%edx, %ecx
	cmovle	%r9d, %ecx
.L935:
.LVL1007:
	.loc 1 2315 22 view .LVU3706
.LBE2411:
.LBE2417:
	.loc 1 30462 23 view .LVU3707
	movl	%ecx, (%rdi,%rax,4)
	.loc 1 30461 5 is_stmt 1 view .LVU3708
	.loc 1 30461 48 is_stmt 0 view .LVU3709
	addq	$1, %rax
.LVL1008:
	.loc 1 30461 31 is_stmt 1 view .LVU3710
	cmpq	%rax, %rbx
	jne	.L936
	jmp	.L850
.LVL1009:
	.p2align 4,,10
	.p2align 3
.L905:
	.loc 1 30461 31 is_stmt 0 view .LVU3711
.LBE2418:
.LBE2443:
	.loc 1 30495 13 is_stmt 1 view .LVU3712
	.loc 1 30495 33 view .LVU3713
.LBB2444:
.LBI2419:
	.loc 1 30433 13 view .LVU3714
.LBB2442:
	.loc 1 30435 5 view .LVU3715
	.loc 1 30436 5 view .LVU3716
	.loc 1 30438 5 view .LVU3717
	.loc 1 30439 5 view .LVU3718
	.loc 1 30441 5 view .LVU3719
.LBB2439:
.LBI2439:
	.loc 1 2406 27 view .LVU3720
.LBB2440:
	.loc 1 2408 5 view .LVU3721
	.loc 1 2408 25 is_stmt 0 view .LVU3722
	mulss	.LC89(%rip), %xmm0
.LVL1010:
	.loc 1 2408 35 view .LVU3723
	cvttss2sil	%xmm0, %ecx
.LVL1011:
	.loc 1 2408 35 view .LVU3724
.LBE2440:
.LBE2439:
	.loc 1 30443 5 is_stmt 1 view .LVU3725
.LBB2441:
	.loc 1 30443 31 view .LVU3726
	testq	%rbx, %rbx
	je	.L850
	leaq	(%rbx,%rbx,2), %r8
.LVL1012:
.LBB2437:
.LBB2428:
.LBB2425:
	.loc 1 30389 28 is_stmt 0 view .LVU3727
	movswq	%cx, %rcx
	.loc 1 30389 28 view .LVU3728
.LBE2425:
.LBE2428:
.LBB2429:
.LBB2430:
	.loc 1 2304 12 view .LVU3729
	movl	$8388607, %r10d
	movq	$-8388608, %r9
	addq	%rdi, %r8
.LVL1013:
	.p2align 4,,10
	.p2align 3
.L934:
	.loc 1 2304 12 view .LVU3730
.LBE2430:
.LBE2429:
	.loc 1 30444 9 is_stmt 1 view .LVU3731
.LBB2433:
.LBI2423:
	.loc 1 30387 27 view .LVU3732
.LBB2426:
	.loc 1 30389 5 view .LVU3733
	.loc 1 30389 5 is_stmt 0 view .LVU3734
.LBE2426:
.LBE2433:
.LBB2434:
.LBI2429:
	.loc 1 2302 27 is_stmt 1 view .LVU3735
.LBB2431:
	.loc 1 2304 5 view .LVU3736
.LBE2431:
.LBE2434:
.LBB2435:
.LBB2427:
	.loc 1 30389 26 is_stmt 0 view .LVU3737
	movq	(%rsi), %rdx
	imulq	%rcx, %rdx
	.loc 1 30389 40 view .LVU3738
	movq	%rdx, %rax
	sarq	$8, %rax
.LVL1014:
	.loc 1 30389 40 view .LVU3739
.LBE2427:
.LBE2435:
.LBB2436:
.LBB2432:
	.loc 1 2304 12 view .LVU3740
	cmpq	$2147483647, %rdx
	cmovg	%r10, %rax
.LVL1015:
	.loc 1 2304 12 view .LVU3741
	cmpq	$-8388608, %rax
	cmovl	%r9, %rax
.LVL1016:
	.loc 1 2304 12 view .LVU3742
.LBE2432:
.LBE2436:
	.loc 1 30445 9 is_stmt 1 view .LVU3743
.LBE2437:
	.loc 1 30443 31 is_stmt 0 view .LVU3744
	addq	$3, %rdi
	addq	$8, %rsi
.LBB2438:
	.loc 1 30446 59 view .LVU3745
	movq	%rax, %rdx
	.loc 1 30445 29 view .LVU3746
	movb	%al, -3(%rdi)
	.loc 1 30446 9 is_stmt 1 view .LVU3747
	.loc 1 30447 59 is_stmt 0 view .LVU3748
	sarq	$16, %rax
.LVL1017:
	.loc 1 30446 59 view .LVU3749
	sarq	$8, %rdx
.LVL1018:
	.loc 1 30447 29 view .LVU3750
	movb	%al, -1(%rdi)
	.loc 1 30446 29 view .LVU3751
	movb	%dl, -2(%rdi)
	.loc 1 30447 9 is_stmt 1 view .LVU3752
.LBE2438:
	.loc 1 30443 5 view .LVU3753
	.loc 1 30443 31 view .LVU3754
	cmpq	%r8, %rdi
	jne	.L934
	jmp	.L850
.LVL1019:
	.p2align 4,,10
	.p2align 3
.L906:
	.loc 1 30443 31 is_stmt 0 view .LVU3755
.LBE2441:
.LBE2442:
.LBE2444:
	.loc 1 30494 13 is_stmt 1 view .LVU3756
	.loc 1 30494 33 view .LVU3757
.LBB2445:
.LBI2445:
	.loc 1 30418 13 view .LVU3758
.LBB2446:
	.loc 1 30420 5 view .LVU3759
	.loc 1 30421 5 view .LVU3760
	.loc 1 30423 5 view .LVU3761
	.loc 1 30424 5 view .LVU3762
	.loc 1 30426 5 view .LVU3763
.LBB2447:
.LBI2447:
	.loc 1 2406 27 view .LVU3764
.LBB2448:
	.loc 1 2408 5 view .LVU3765
	.loc 1 2408 25 is_stmt 0 view .LVU3766
	mulss	.LC89(%rip), %xmm0
.LVL1020:
	.loc 1 2408 35 view .LVU3767
	cvttss2sil	%xmm0, %edx
.LVL1021:
	.loc 1 2408 35 view .LVU3768
.LBE2448:
.LBE2447:
	.loc 1 30428 5 is_stmt 1 view .LVU3769
	.loc 1 30428 31 view .LVU3770
	testq	%rbx, %rbx
	je	.L850
	leaq	-1(%rbx), %rax
.LBE2446:
.LBE2445:
.LBB2537:
.LBB2538:
	.loc 1 30414 64 is_stmt 0 view .LVU3771
	movswl	%dx, %edx
	.loc 1 30414 64 view .LVU3772
	cmpq	$6, %rax
	jbe	.L976
	movd	%edx, %xmm5
	movq	%rbx, %rcx
	xorl	%eax, %eax
	movdqa	.LC84(%rip), %xmm4
	pshufd	$0, %xmm5, %xmm5
	shrq	$3, %rcx
	movdqa	.LC85(%rip), %xmm3
	movdqa	%xmm5, %xmm6
	salq	$4, %rcx
	psrlq	$32, %xmm6
.LVL1022:
	.p2align 4,,10
	.p2align 3
.L932:
	.loc 1 30414 64 view .LVU3773
.LBE2538:
.LBE2537:
.LBB2687:
.LBB2535:
	.loc 1 30429 9 is_stmt 1 view .LVU3774
.LBB2449:
.LBI2449:
	.loc 1 30382 27 view .LVU3775
.LBB2450:
	.loc 1 30384 5 view .LVU3776
	.loc 1 30384 5 is_stmt 0 view .LVU3777
.LBE2450:
.LBE2449:
.LBB2471:
.LBI2471:
	.loc 1 2297 27 is_stmt 1 view .LVU3778
.LBB2472:
	.loc 1 2299 5 view .LVU3779
	.loc 1 2299 5 is_stmt 0 view .LVU3780
.LBE2472:
.LBE2471:
.LBB2494:
.LBB2451:
	.loc 1 30384 26 view .LVU3781
	movdqu	(%rsi,%rax,2), %xmm0
	movdqu	(%rsi,%rax,2), %xmm1
.LBE2451:
.LBE2494:
.LBB2495:
.LBB2473:
	.loc 1 2299 22 view .LVU3782
	movdqa	%xmm4, %xmm7
.LBE2473:
.LBE2495:
.LBB2496:
.LBB2452:
	.loc 1 30384 26 view .LVU3783
	psrlq	$32, %xmm0
	pmuludq	%xmm5, %xmm1
	pmuludq	%xmm6, %xmm0
	pshufd	$8, %xmm1, %xmm1
	pshufd	$8, %xmm0, %xmm0
	punpckldq	%xmm0, %xmm1
	.loc 1 30384 40 view .LVU3784
	movdqa	%xmm1, %xmm2
.LBE2452:
.LBE2496:
.LBB2497:
.LBB2474:
	.loc 1 2299 22 view .LVU3785
	movdqa	%xmm4, %xmm1
.LBE2474:
.LBE2497:
.LBB2498:
.LBB2453:
	.loc 1 30384 40 view .LVU3786
	psrad	$8, %xmm2
.LBE2453:
.LBE2498:
.LBB2499:
.LBB2475:
	.loc 1 2299 22 view .LVU3787
	movdqa	%xmm2, %xmm0
	pcmpgtd	%xmm4, %xmm0
	pand	%xmm0, %xmm1
	pandn	%xmm2, %xmm0
	por	%xmm1, %xmm0
.LBE2475:
.LBE2499:
	.loc 1 30429 23 view .LVU3788
	movdqa	%xmm0, %xmm1
	pcmpgtd	%xmm3, %xmm1
	pand	%xmm1, %xmm0
	pandn	%xmm3, %xmm1
	movdqa	%xmm1, %xmm2
.LBB2500:
.LBB2454:
	.loc 1 30384 26 view .LVU3789
	movdqu	16(%rsi,%rax,2), %xmm1
.LBE2454:
.LBE2500:
	.loc 1 30429 23 view .LVU3790
	por	%xmm0, %xmm2
.LBB2501:
.LBB2455:
	.loc 1 30384 26 view .LVU3791
	movdqu	16(%rsi,%rax,2), %xmm0
	psrlq	$32, %xmm1
	pmuludq	%xmm5, %xmm0
	pmuludq	%xmm6, %xmm1
	pshufd	$8, %xmm0, %xmm0
	pshufd	$8, %xmm1, %xmm1
	punpckldq	%xmm1, %xmm0
	.loc 1 30384 40 view .LVU3792
	psrad	$8, %xmm0
.LBE2455:
.LBE2501:
.LBB2502:
.LBB2476:
	.loc 1 2299 22 view .LVU3793
	movdqa	%xmm0, %xmm1
	pcmpgtd	%xmm4, %xmm1
	pand	%xmm1, %xmm7
	pandn	%xmm0, %xmm1
	por	%xmm7, %xmm1
.LBE2476:
.LBE2502:
	.loc 1 30429 23 view .LVU3794
	movdqa	%xmm2, %xmm7
.LBB2503:
.LBB2477:
	.loc 1 2299 22 view .LVU3795
	movdqa	%xmm1, %xmm0
.LBE2477:
.LBE2503:
	.loc 1 30429 23 view .LVU3796
	pcmpgtd	%xmm3, %xmm1
	pand	%xmm1, %xmm0
	pandn	%xmm3, %xmm1
	por	%xmm1, %xmm0
	movdqa	%xmm2, %xmm1
	punpcklwd	%xmm0, %xmm1
	punpckhwd	%xmm0, %xmm7
	movdqa	%xmm1, %xmm0
	punpcklwd	%xmm7, %xmm1
	punpckhwd	%xmm7, %xmm0
	punpcklwd	%xmm0, %xmm1
	movups	%xmm1, (%rdi,%rax)
	.loc 1 30428 5 is_stmt 1 view .LVU3797
	.loc 1 30428 31 view .LVU3798
	addq	$16, %rax
	cmpq	%rax, %rcx
	jne	.L932
	movq	%rbx, %rax
	andq	$-8, %rax
	testb	$7, %bl
	je	.L850
.L930:
.LVL1023:
	.loc 1 30429 9 view .LVU3799
.LBB2504:
	.loc 1 30382 27 view .LVU3800
.LBB2456:
	.loc 1 30384 5 view .LVU3801
	.loc 1 30384 5 is_stmt 0 view .LVU3802
.LBE2456:
.LBE2504:
.LBB2505:
	.loc 1 2297 27 is_stmt 1 view .LVU3803
.LBB2478:
	.loc 1 2299 5 view .LVU3804
	.loc 1 2299 5 is_stmt 0 view .LVU3805
.LBE2478:
.LBE2505:
.LBB2506:
.LBB2457:
	.loc 1 30384 26 view .LVU3806
	movl	(%rsi,%rax,4), %r8d
.LVL1024:
	.loc 1 30384 26 view .LVU3807
.LBE2457:
.LBE2506:
.LBB2507:
.LBB2479:
	.loc 1 2299 22 view .LVU3808
	movl	$32767, %r9d
.LBE2479:
.LBE2507:
	.loc 1 30428 48 view .LVU3809
	leaq	1(%rax), %r10
.LBB2508:
.LBB2458:
	.loc 1 30384 26 view .LVU3810
	imull	%edx, %r8d
	.loc 1 30384 40 view .LVU3811
	movl	%r8d, %ecx
	sarl	$8, %ecx
.LBE2458:
.LBE2508:
.LBB2509:
.LBB2480:
	.loc 1 2299 22 view .LVU3812
	cmpl	$8388607, %r8d
.LBE2480:
.LBE2509:
	.loc 1 30429 23 view .LVU3813
	movl	$-32768, %r8d
.LBB2510:
.LBB2481:
	.loc 1 2299 22 view .LVU3814
	cmovg	%r9d, %ecx
.LBE2481:
.LBE2510:
	.loc 1 30429 23 view .LVU3815
	cmpl	$-32768, %ecx
	cmovl	%r8d, %ecx
	movw	%cx, (%rdi,%rax,2)
	.loc 1 30428 5 is_stmt 1 view .LVU3816
.LVL1025:
	.loc 1 30428 31 view .LVU3817
	cmpq	%r10, %rbx
	jbe	.L850
	.loc 1 30429 9 view .LVU3818
.LVL1026:
.LBB2511:
	.loc 1 30382 27 view .LVU3819
.LBB2459:
	.loc 1 30384 5 view .LVU3820
	.loc 1 30384 5 is_stmt 0 view .LVU3821
.LBE2459:
.LBE2511:
.LBB2512:
	.loc 1 2297 27 is_stmt 1 view .LVU3822
.LBB2482:
	.loc 1 2299 5 view .LVU3823
	.loc 1 2299 5 is_stmt 0 view .LVU3824
.LBE2482:
.LBE2512:
.LBB2513:
.LBB2460:
	.loc 1 30384 26 view .LVU3825
	movl	(%rsi,%r10,4), %r11d
	imull	%edx, %r11d
	.loc 1 30384 40 view .LVU3826
	movl	%r11d, %ecx
	sarl	$8, %ecx
.LBE2460:
.LBE2513:
.LBB2514:
.LBB2483:
	.loc 1 2299 22 view .LVU3827
	cmpl	$8388607, %r11d
	cmovg	%r9d, %ecx
.LBE2483:
.LBE2514:
	.loc 1 30429 23 view .LVU3828
	cmpl	$-32768, %ecx
	cmovl	%r8d, %ecx
	movw	%cx, (%rdi,%r10,2)
	.loc 1 30428 5 is_stmt 1 view .LVU3829
	.loc 1 30428 48 is_stmt 0 view .LVU3830
	leaq	2(%rax), %r10
.LVL1027:
	.loc 1 30428 31 is_stmt 1 view .LVU3831
	cmpq	%r10, %rbx
	jbe	.L850
	.loc 1 30429 9 view .LVU3832
.LVL1028:
.LBB2515:
	.loc 1 30382 27 view .LVU3833
.LBB2461:
	.loc 1 30384 5 view .LVU3834
	.loc 1 30384 5 is_stmt 0 view .LVU3835
.LBE2461:
.LBE2515:
.LBB2516:
	.loc 1 2297 27 is_stmt 1 view .LVU3836
.LBB2484:
	.loc 1 2299 5 view .LVU3837
	.loc 1 2299 5 is_stmt 0 view .LVU3838
.LBE2484:
.LBE2516:
.LBB2517:
.LBB2462:
	.loc 1 30384 26 view .LVU3839
	movl	(%rsi,%r10,4), %r11d
	imull	%edx, %r11d
	.loc 1 30384 40 view .LVU3840
	movl	%r11d, %ecx
	sarl	$8, %ecx
.LBE2462:
.LBE2517:
.LBB2518:
.LBB2485:
	.loc 1 2299 22 view .LVU3841
	cmpl	$8388607, %r11d
	cmovg	%r9d, %ecx
.LBE2485:
.LBE2518:
	.loc 1 30429 23 view .LVU3842
	cmpl	$-32768, %ecx
	cmovl	%r8d, %ecx
	movw	%cx, (%rdi,%r10,2)
	.loc 1 30428 5 is_stmt 1 view .LVU3843
	.loc 1 30428 48 is_stmt 0 view .LVU3844
	leaq	3(%rax), %r10
.LVL1029:
	.loc 1 30428 31 is_stmt 1 view .LVU3845
	cmpq	%r10, %rbx
	jbe	.L850
	.loc 1 30429 9 view .LVU3846
.LVL1030:
.LBB2519:
	.loc 1 30382 27 view .LVU3847
.LBB2463:
	.loc 1 30384 5 view .LVU3848
	.loc 1 30384 5 is_stmt 0 view .LVU3849
.LBE2463:
.LBE2519:
.LBB2520:
	.loc 1 2297 27 is_stmt 1 view .LVU3850
.LBB2486:
	.loc 1 2299 5 view .LVU3851
	.loc 1 2299 5 is_stmt 0 view .LVU3852
.LBE2486:
.LBE2520:
.LBB2521:
.LBB2464:
	.loc 1 30384 26 view .LVU3853
	movl	(%rsi,%r10,4), %r11d
	imull	%edx, %r11d
	.loc 1 30384 40 view .LVU3854
	movl	%r11d, %ecx
	sarl	$8, %ecx
.LBE2464:
.LBE2521:
.LBB2522:
.LBB2487:
	.loc 1 2299 22 view .LVU3855
	cmpl	$8388607, %r11d
	cmovg	%r9d, %ecx
.LBE2487:
.LBE2522:
	.loc 1 30429 23 view .LVU3856
	cmpl	$-32768, %ecx
	cmovl	%r8d, %ecx
	movw	%cx, (%rdi,%r10,2)
	.loc 1 30428 5 is_stmt 1 view .LVU3857
	.loc 1 30428 48 is_stmt 0 view .LVU3858
	leaq	4(%rax), %r10
.LVL1031:
	.loc 1 30428 31 is_stmt 1 view .LVU3859
	cmpq	%r10, %rbx
	jbe	.L850
	.loc 1 30429 9 view .LVU3860
.LVL1032:
.LBB2523:
	.loc 1 30382 27 view .LVU3861
.LBB2465:
	.loc 1 30384 5 view .LVU3862
	.loc 1 30384 5 is_stmt 0 view .LVU3863
.LBE2465:
.LBE2523:
.LBB2524:
	.loc 1 2297 27 is_stmt 1 view .LVU3864
.LBB2488:
	.loc 1 2299 5 view .LVU3865
	.loc 1 2299 5 is_stmt 0 view .LVU3866
.LBE2488:
.LBE2524:
.LBB2525:
.LBB2466:
	.loc 1 30384 26 view .LVU3867
	movl	(%rsi,%r10,4), %r11d
	imull	%edx, %r11d
	.loc 1 30384 40 view .LVU3868
	movl	%r11d, %ecx
	sarl	$8, %ecx
.LBE2466:
.LBE2525:
.LBB2526:
.LBB2489:
	.loc 1 2299 22 view .LVU3869
	cmpl	$8388607, %r11d
	cmovg	%r9d, %ecx
.LBE2489:
.LBE2526:
	.loc 1 30429 23 view .LVU3870
	cmpl	$-32768, %ecx
	cmovl	%r8d, %ecx
	movw	%cx, (%rdi,%r10,2)
	.loc 1 30428 5 is_stmt 1 view .LVU3871
	.loc 1 30428 48 is_stmt 0 view .LVU3872
	leaq	5(%rax), %r10
.LVL1033:
	.loc 1 30428 31 is_stmt 1 view .LVU3873
	cmpq	%r10, %rbx
	jbe	.L850
	.loc 1 30429 9 view .LVU3874
.LVL1034:
.LBB2527:
	.loc 1 30382 27 view .LVU3875
.LBB2467:
	.loc 1 30384 5 view .LVU3876
	.loc 1 30384 5 is_stmt 0 view .LVU3877
.LBE2467:
.LBE2527:
.LBB2528:
	.loc 1 2297 27 is_stmt 1 view .LVU3878
.LBB2490:
	.loc 1 2299 5 view .LVU3879
	.loc 1 2299 5 is_stmt 0 view .LVU3880
.LBE2490:
.LBE2528:
.LBB2529:
.LBB2468:
	.loc 1 30384 26 view .LVU3881
	movl	(%rsi,%r10,4), %r11d
	imull	%edx, %r11d
	.loc 1 30384 40 view .LVU3882
	movl	%r11d, %ecx
	sarl	$8, %ecx
.LBE2468:
.LBE2529:
.LBB2530:
.LBB2491:
	.loc 1 2299 22 view .LVU3883
	cmpl	$8388607, %r11d
	cmovg	%r9d, %ecx
.LBE2491:
.LBE2530:
	.loc 1 30429 23 view .LVU3884
	cmpl	$-32768, %ecx
	cmovl	%r8d, %ecx
	.loc 1 30428 48 view .LVU3885
	addq	$6, %rax
	.loc 1 30429 23 view .LVU3886
	movw	%cx, (%rdi,%r10,2)
	.loc 1 30428 5 is_stmt 1 view .LVU3887
.LVL1035:
	.loc 1 30428 31 view .LVU3888
	cmpq	%rax, %rbx
	jbe	.L850
	.loc 1 30429 9 view .LVU3889
.LVL1036:
.LBB2531:
	.loc 1 30382 27 view .LVU3890
.LBB2469:
	.loc 1 30384 5 view .LVU3891
	.loc 1 30384 5 is_stmt 0 view .LVU3892
.LBE2469:
.LBE2531:
.LBB2532:
	.loc 1 2297 27 is_stmt 1 view .LVU3893
.LBB2492:
	.loc 1 2299 5 view .LVU3894
	.loc 1 2299 5 is_stmt 0 view .LVU3895
.LBE2492:
.LBE2532:
.LBB2533:
.LBB2470:
	.loc 1 30384 26 view .LVU3896
	imull	(%rsi,%rax,4), %edx
.LVL1037:
	.loc 1 30384 40 view .LVU3897
	movl	%edx, %ecx
	sarl	$8, %ecx
.LBE2470:
.LBE2533:
.LBB2534:
.LBB2493:
	.loc 1 2299 22 view .LVU3898
	cmpl	$8388607, %edx
	cmovg	%r9d, %ecx
.LBE2493:
.LBE2534:
	.loc 1 30429 23 view .LVU3899
	cmpl	$-32768, %ecx
	cmovl	%r8d, %ecx
	movw	%cx, (%rdi,%rax,2)
	.loc 1 30428 5 is_stmt 1 view .LVU3900
	.loc 1 30428 31 view .LVU3901
	jmp	.L850
.LVL1038:
	.p2align 4,,10
	.p2align 3
.L907:
	.loc 1 30428 31 is_stmt 0 view .LVU3902
.LBE2535:
.LBE2687:
	.loc 1 30493 13 is_stmt 1 view .LVU3903
	.loc 1 30493 33 view .LVU3904
.LBB2688:
.LBI2537:
	.loc 1 30403 13 view .LVU3905
.LBB2683:
	.loc 1 30405 5 view .LVU3906
	.loc 1 30406 5 view .LVU3907
	.loc 1 30408 5 view .LVU3908
	.loc 1 30409 5 view .LVU3909
	.loc 1 30411 5 view .LVU3910
.LBB2539:
.LBI2539:
	.loc 1 2406 27 view .LVU3911
.LBB2540:
	.loc 1 2408 5 view .LVU3912
	.loc 1 2408 25 is_stmt 0 view .LVU3913
	mulss	.LC89(%rip), %xmm0
.LVL1039:
	.loc 1 2408 35 view .LVU3914
	cvttss2sil	%xmm0, %eax
.LVL1040:
	.loc 1 2408 35 view .LVU3915
.LBE2540:
.LBE2539:
	.loc 1 30413 5 is_stmt 1 view .LVU3916
	.loc 1 30413 31 view .LVU3917
	testq	%rbx, %rbx
	je	.L850
	leaq	(%rsi,%rbx,2), %rdx
.LVL1041:
	.loc 1 30414 64 is_stmt 0 view .LVU3918
	movswl	%ax, %ecx
	cmpq	%rdx, %rdi
	leaq	(%rdi,%rbx), %rdx
	setnb	%r8b
.LVL1042:
	.loc 1 30414 64 view .LVU3919
	cmpq	%rdx, %rsi
	setnb	%dl
	orb	%dl, %r8b
	je	.L961
	leaq	-1(%rbx), %rdx
	cmpq	$14, %rdx
	jbe	.L961
	movd	%eax, %xmm6
	movq	%rbx, %rdx
	movdqa	.LC81(%rip), %xmm5
	movdqa	.LC76(%rip), %xmm4
	punpcklwd	%xmm6, %xmm6
	andq	$-16, %rdx
	.loc 1 30414 35 view .LVU3920
	pxor	%xmm9, %xmm9
	.loc 1 30414 64 view .LVU3921
	xorl	%eax, %eax
.LVL1043:
	.loc 1 30414 64 view .LVU3922
	movdqa	.LC82(%rip), %xmm3
	pshufd	$0, %xmm6, %xmm6
	.loc 1 30414 23 view .LVU3923
	pxor	%xmm7, %xmm7
	movdqa	.LC83(%rip), %xmm8
.LVL1044:
	.p2align 4,,10
	.p2align 3
.L910:
	.loc 1 30414 9 is_stmt 1 view .LVU3924
.LBB2541:
.LBI2541:
	.loc 1 30377 27 view .LVU3925
.LBB2542:
	.loc 1 30379 5 view .LVU3926
	.loc 1 30379 56 is_stmt 0 view .LVU3927
	movdqu	(%rsi,%rax,2), %xmm0
	movdqu	(%rsi,%rax,2), %xmm2
	pmullw	%xmm6, %xmm0
	pmulhw	%xmm6, %xmm2
	movdqa	%xmm0, %xmm1
	punpckhwd	%xmm2, %xmm0
	punpcklwd	%xmm2, %xmm1
	psrad	$8, %xmm0
	psrad	$8, %xmm1
	.loc 1 30379 60 view .LVU3928
	movdqa	%xmm1, %xmm2
	punpcklwd	%xmm0, %xmm1
	punpckhwd	%xmm0, %xmm2
	movdqa	%xmm1, %xmm0
	punpckhwd	%xmm2, %xmm0
	punpcklwd	%xmm2, %xmm1
	.loc 1 30379 56 view .LVU3929
	movdqu	16(%rsi,%rax,2), %xmm2
	.loc 1 30379 60 view .LVU3930
	punpcklwd	%xmm0, %xmm1
	.loc 1 30379 56 view .LVU3931
	movdqu	16(%rsi,%rax,2), %xmm0
	pmulhw	%xmm6, %xmm2
.LBE2542:
.LBE2541:
	.loc 1 30414 35 view .LVU3932
	movdqa	%xmm1, %xmm12
.LBB2577:
.LBB2543:
	.loc 1 30379 56 view .LVU3933
	pmullw	%xmm6, %xmm0
	movdqa	%xmm0, %xmm10
	punpckhwd	%xmm2, %xmm0
	punpcklwd	%xmm2, %xmm10
	psrad	$8, %xmm0
	psrad	$8, %xmm10
	.loc 1 30379 60 view .LVU3934
	movdqa	%xmm10, %xmm2
	punpcklwd	%xmm0, %xmm10
	punpckhwd	%xmm0, %xmm2
	movdqa	%xmm10, %xmm0
	punpckhwd	%xmm2, %xmm0
	punpcklwd	%xmm2, %xmm10
.LBE2543:
.LBE2577:
	.loc 1 30414 23 view .LVU3935
	movdqa	%xmm5, %xmm2
.LBB2578:
.LBB2544:
	.loc 1 30379 60 view .LVU3936
	punpcklwd	%xmm0, %xmm10
.LBE2544:
.LBE2578:
	.loc 1 30414 35 view .LVU3937
	movdqa	%xmm9, %xmm0
	pcmpgtw	%xmm1, %xmm0
	movdqa	%xmm10, %xmm11
	punpcklwd	%xmm0, %xmm12
	punpckhwd	%xmm0, %xmm1
	movdqa	%xmm9, %xmm0
	pcmpgtw	%xmm10, %xmm0
	.loc 1 30414 23 view .LVU3938
	pcmpgtd	%xmm12, %xmm2
	.loc 1 30414 35 view .LVU3939
	punpcklwd	%xmm0, %xmm11
	.loc 1 30414 23 view .LVU3940
	pcmpeqd	%xmm7, %xmm2
	.loc 1 30414 35 view .LVU3941
	punpckhwd	%xmm0, %xmm10
.LBB2579:
.LBI2579:
	.loc 1 2292 27 is_stmt 1 view .LVU3942
.LBB2580:
	.loc 1 2294 5 view .LVU3943
.LBE2580:
.LBE2579:
	.loc 1 30414 23 is_stmt 0 view .LVU3944
	movdqa	%xmm5, %xmm0
	pcmpgtd	%xmm1, %xmm0
	movdqa	%xmm2, %xmm13
	pcmpeqd	%xmm7, %xmm0
	punpcklwd	%xmm0, %xmm2
	punpckhwd	%xmm0, %xmm13
	movdqa	%xmm2, %xmm0
	punpcklwd	%xmm13, %xmm2
	punpckhwd	%xmm13, %xmm0
	movdqa	%xmm5, %xmm13
	punpcklwd	%xmm0, %xmm2
	pcmpgtd	%xmm10, %xmm13
	movdqa	%xmm5, %xmm0
	pcmpgtd	%xmm11, %xmm0
	pand	%xmm4, %xmm2
	pcmpeqd	%xmm7, %xmm13
	pcmpeqd	%xmm7, %xmm0
	movdqa	%xmm0, %xmm14
	punpcklwd	%xmm13, %xmm0
	punpckhwd	%xmm13, %xmm14
	movdqa	%xmm0, %xmm13
	punpckhwd	%xmm14, %xmm13
	punpcklwd	%xmm14, %xmm0
	punpcklwd	%xmm13, %xmm0
.LBB2616:
.LBB2581:
	.loc 1 2294 23 view .LVU3945
	movdqa	%xmm12, %xmm13
	pcmpgtd	%xmm3, %xmm13
.LBE2581:
.LBE2616:
	.loc 1 30414 23 view .LVU3946
	pand	%xmm4, %xmm0
	packuswb	%xmm0, %xmm2
.LBB2617:
.LBB2582:
	.loc 1 2294 23 view .LVU3947
	movdqa	%xmm3, %xmm0
	pand	%xmm13, %xmm0
	pandn	%xmm12, %xmm13
	movdqa	%xmm1, %xmm12
	pcmpgtd	%xmm3, %xmm12
	por	%xmm0, %xmm13
	movdqa	%xmm3, %xmm0
	pand	%xmm12, %xmm0
	pandn	%xmm1, %xmm12
	movdqa	%xmm12, %xmm1
	.loc 1 2294 46 view .LVU3948
	movdqa	%xmm13, %xmm12
	.loc 1 2294 23 view .LVU3949
	por	%xmm0, %xmm1
	.loc 1 2294 46 view .LVU3950
	movdqa	%xmm13, %xmm0
	punpcklwd	%xmm1, %xmm0
	punpckhwd	%xmm1, %xmm12
	movdqa	%xmm0, %xmm1
	punpcklwd	%xmm12, %xmm0
	punpckhwd	%xmm12, %xmm1
	.loc 1 2294 23 view .LVU3951
	movdqa	%xmm3, %xmm12
	.loc 1 2294 46 view .LVU3952
	punpcklwd	%xmm1, %xmm0
	.loc 1 2294 23 view .LVU3953
	movdqa	%xmm11, %xmm1
	pcmpgtd	%xmm3, %xmm1
	.loc 1 2294 46 view .LVU3954
	pand	%xmm4, %xmm0
	.loc 1 2294 23 view .LVU3955
	pand	%xmm1, %xmm12
	pandn	%xmm11, %xmm1
	movdqa	%xmm10, %xmm11
	pcmpgtd	%xmm3, %xmm11
	por	%xmm12, %xmm1
	movdqa	%xmm3, %xmm12
	pand	%xmm11, %xmm12
	pandn	%xmm10, %xmm11
	por	%xmm12, %xmm11
	movdqa	%xmm11, %xmm10
	.loc 1 2294 46 view .LVU3956
	movdqa	%xmm1, %xmm11
	punpcklwd	%xmm10, %xmm1
	punpckhwd	%xmm10, %xmm11
	movdqa	%xmm1, %xmm10
	punpcklwd	%xmm11, %xmm1
	punpckhwd	%xmm11, %xmm10
	punpcklwd	%xmm10, %xmm1
	pand	%xmm4, %xmm1
	packuswb	%xmm1, %xmm0
	.loc 1 2294 51 view .LVU3957
	paddb	%xmm8, %xmm0
.LBE2582:
.LBE2617:
	.loc 1 30414 23 view .LVU3958
	pand	%xmm2, %xmm0
	movups	%xmm0, (%rdi,%rax)
	.loc 1 30413 5 is_stmt 1 view .LVU3959
	.loc 1 30413 31 view .LVU3960
	addq	$16, %rax
	cmpq	%rax, %rdx
	jne	.L910
	movq	%rbx, %rax
	andq	$-16, %rax
	testb	$15, %bl
	je	.L850
.LVL1045:
	.loc 1 30414 9 view .LVU3961
.LBB2618:
	.loc 1 30377 27 view .LVU3962
.LBB2545:
	.loc 1 30379 5 view .LVU3963
	.loc 1 30379 5 is_stmt 0 view .LVU3964
.LBE2545:
.LBE2618:
	.loc 1 30414 64 view .LVU3965
	movswl	(%rsi,%rax,2), %edx
	.loc 1 30414 21 view .LVU3966
	leaq	(%rdi,%rax), %r10
.LBB2619:
.LBB2583:
	.loc 1 2294 51 view .LVU3967
	xorl	%r9d, %r9d
.LBE2583:
.LBE2619:
.LBB2620:
.LBB2546:
	.loc 1 30379 36 view .LVU3968
	imull	%ecx, %edx
	.loc 1 30379 56 view .LVU3969
	sarl	$8, %edx
.LBE2546:
.LBE2620:
	.loc 1 30414 35 view .LVU3970
	movswl	%dx, %r8d
.LVL1046:
.LBB2621:
	.loc 1 2292 27 is_stmt 1 view .LVU3971
.LBB2584:
	.loc 1 2294 5 view .LVU3972
	.loc 1 2294 51 is_stmt 0 view .LVU3973
	cmpw	$-128, %dx
	jge	.L1049
.LVL1047:
.L912:
	.loc 1 2294 51 view .LVU3974
.LBE2584:
.LBE2621:
	.loc 1 30413 48 view .LVU3975
	leaq	1(%rax), %r8
	.loc 1 30414 23 view .LVU3976
	movb	%r9b, (%r10)
	.loc 1 30413 5 is_stmt 1 view .LVU3977
.LVL1048:
	.loc 1 30413 31 view .LVU3978
	cmpq	%r8, %rbx
	jbe	.L850
	.loc 1 30414 9 view .LVU3979
.LVL1049:
.LBB2622:
	.loc 1 30377 27 view .LVU3980
.LBB2547:
	.loc 1 30379 5 view .LVU3981
	.loc 1 30379 5 is_stmt 0 view .LVU3982
.LBE2547:
.LBE2622:
	.loc 1 30414 64 view .LVU3983
	movswl	(%rsi,%r8,2), %edx
.LBB2623:
.LBB2585:
	.loc 1 2294 51 view .LVU3984
	xorl	%r10d, %r10d
.LBE2585:
.LBE2623:
	.loc 1 30414 21 view .LVU3985
	addq	%rdi, %r8
.LVL1050:
.LBB2624:
.LBB2548:
	.loc 1 30379 36 view .LVU3986
	imull	%ecx, %edx
	.loc 1 30379 56 view .LVU3987
	sarl	$8, %edx
.LBE2548:
.LBE2624:
	.loc 1 30414 35 view .LVU3988
	movswl	%dx, %r9d
.LVL1051:
.LBB2625:
	.loc 1 2292 27 is_stmt 1 view .LVU3989
.LBB2586:
	.loc 1 2294 5 view .LVU3990
	.loc 1 2294 51 is_stmt 0 view .LVU3991
	cmpw	$-128, %dx
	jl	.L913
	.loc 1 2294 23 view .LVU3992
	cmpl	$127, %r9d
	movl	$127, %edx
	cmovg	%edx, %r9d
.LVL1052:
	.loc 1 2294 51 view .LVU3993
	leal	-128(%r9), %r10d
.L913:
.LVL1053:
	.loc 1 2294 51 view .LVU3994
.LBE2586:
.LBE2625:
	.loc 1 30414 23 view .LVU3995
	movb	%r10b, (%r8)
	.loc 1 30413 5 is_stmt 1 view .LVU3996
	.loc 1 30413 48 is_stmt 0 view .LVU3997
	leaq	2(%rax), %r8
.LVL1054:
	.loc 1 30413 31 is_stmt 1 view .LVU3998
	cmpq	%r8, %rbx
	jbe	.L850
	.loc 1 30414 9 view .LVU3999
.LVL1055:
.LBB2626:
	.loc 1 30377 27 view .LVU4000
.LBB2549:
	.loc 1 30379 5 view .LVU4001
	.loc 1 30379 5 is_stmt 0 view .LVU4002
.LBE2549:
.LBE2626:
	.loc 1 30414 64 view .LVU4003
	movswl	(%rsi,%r8,2), %edx
.LBB2627:
.LBB2587:
	.loc 1 2294 51 view .LVU4004
	xorl	%r10d, %r10d
.LBE2587:
.LBE2627:
	.loc 1 30414 21 view .LVU4005
	addq	%rdi, %r8
.LVL1056:
.LBB2628:
.LBB2550:
	.loc 1 30379 36 view .LVU4006
	imull	%ecx, %edx
	.loc 1 30379 56 view .LVU4007
	sarl	$8, %edx
.LBE2550:
.LBE2628:
	.loc 1 30414 35 view .LVU4008
	movswl	%dx, %r9d
.LVL1057:
.LBB2629:
	.loc 1 2292 27 is_stmt 1 view .LVU4009
.LBB2588:
	.loc 1 2294 5 view .LVU4010
	.loc 1 2294 51 is_stmt 0 view .LVU4011
	cmpw	$-128, %dx
	jl	.L914
	.loc 1 2294 23 view .LVU4012
	cmpl	$127, %r9d
	movl	$127, %edx
	cmovg	%edx, %r9d
.LVL1058:
	.loc 1 2294 51 view .LVU4013
	leal	-128(%r9), %r10d
.L914:
.LVL1059:
	.loc 1 2294 51 view .LVU4014
.LBE2588:
.LBE2629:
	.loc 1 30414 23 view .LVU4015
	movb	%r10b, (%r8)
	.loc 1 30413 5 is_stmt 1 view .LVU4016
	.loc 1 30413 48 is_stmt 0 view .LVU4017
	leaq	3(%rax), %r8
.LVL1060:
	.loc 1 30413 31 is_stmt 1 view .LVU4018
	cmpq	%r8, %rbx
	jbe	.L850
	.loc 1 30414 9 view .LVU4019
.LVL1061:
.LBB2630:
	.loc 1 30377 27 view .LVU4020
.LBB2551:
	.loc 1 30379 5 view .LVU4021
	.loc 1 30379 5 is_stmt 0 view .LVU4022
.LBE2551:
.LBE2630:
	.loc 1 30414 64 view .LVU4023
	movswl	(%rsi,%r8,2), %edx
.LBB2631:
.LBB2589:
	.loc 1 2294 51 view .LVU4024
	xorl	%r10d, %r10d
.LBE2589:
.LBE2631:
	.loc 1 30414 21 view .LVU4025
	addq	%rdi, %r8
.LVL1062:
.LBB2632:
.LBB2552:
	.loc 1 30379 36 view .LVU4026
	imull	%ecx, %edx
	.loc 1 30379 56 view .LVU4027
	sarl	$8, %edx
.LBE2552:
.LBE2632:
	.loc 1 30414 35 view .LVU4028
	movswl	%dx, %r9d
.LVL1063:
.LBB2633:
	.loc 1 2292 27 is_stmt 1 view .LVU4029
.LBB2590:
	.loc 1 2294 5 view .LVU4030
	.loc 1 2294 51 is_stmt 0 view .LVU4031
	cmpw	$-128, %dx
	jl	.L915
	.loc 1 2294 23 view .LVU4032
	cmpl	$127, %r9d
	movl	$127, %edx
	cmovg	%edx, %r9d
.LVL1064:
	.loc 1 2294 51 view .LVU4033
	leal	-128(%r9), %r10d
.L915:
.LVL1065:
	.loc 1 2294 51 view .LVU4034
.LBE2590:
.LBE2633:
	.loc 1 30414 23 view .LVU4035
	movb	%r10b, (%r8)
	.loc 1 30413 5 is_stmt 1 view .LVU4036
	.loc 1 30413 48 is_stmt 0 view .LVU4037
	leaq	4(%rax), %r8
.LVL1066:
	.loc 1 30413 31 is_stmt 1 view .LVU4038
	cmpq	%r8, %rbx
	jbe	.L850
	.loc 1 30414 9 view .LVU4039
.LVL1067:
.LBB2634:
	.loc 1 30377 27 view .LVU4040
.LBB2553:
	.loc 1 30379 5 view .LVU4041
	.loc 1 30379 5 is_stmt 0 view .LVU4042
.LBE2553:
.LBE2634:
	.loc 1 30414 64 view .LVU4043
	movswl	(%rsi,%r8,2), %edx
.LBB2635:
.LBB2591:
	.loc 1 2294 51 view .LVU4044
	xorl	%r10d, %r10d
.LBE2591:
.LBE2635:
	.loc 1 30414 21 view .LVU4045
	addq	%rdi, %r8
.LVL1068:
.LBB2636:
.LBB2554:
	.loc 1 30379 36 view .LVU4046
	imull	%ecx, %edx
	.loc 1 30379 56 view .LVU4047
	sarl	$8, %edx
.LBE2554:
.LBE2636:
	.loc 1 30414 35 view .LVU4048
	movswl	%dx, %r9d
.LVL1069:
.LBB2637:
	.loc 1 2292 27 is_stmt 1 view .LVU4049
.LBB2592:
	.loc 1 2294 5 view .LVU4050
	.loc 1 2294 51 is_stmt 0 view .LVU4051
	cmpw	$-128, %dx
	jl	.L916
	.loc 1 2294 23 view .LVU4052
	cmpl	$127, %r9d
	movl	$127, %edx
	cmovg	%edx, %r9d
.LVL1070:
	.loc 1 2294 51 view .LVU4053
	leal	-128(%r9), %r10d
.L916:
.LVL1071:
	.loc 1 2294 51 view .LVU4054
.LBE2592:
.LBE2637:
	.loc 1 30414 23 view .LVU4055
	movb	%r10b, (%r8)
	.loc 1 30413 5 is_stmt 1 view .LVU4056
	.loc 1 30413 48 is_stmt 0 view .LVU4057
	leaq	5(%rax), %r8
.LVL1072:
	.loc 1 30413 31 is_stmt 1 view .LVU4058
	cmpq	%r8, %rbx
	jbe	.L850
	.loc 1 30414 9 view .LVU4059
.LVL1073:
.LBB2638:
	.loc 1 30377 27 view .LVU4060
.LBB2555:
	.loc 1 30379 5 view .LVU4061
	.loc 1 30379 5 is_stmt 0 view .LVU4062
.LBE2555:
.LBE2638:
	.loc 1 30414 64 view .LVU4063
	movswl	(%rsi,%r8,2), %edx
.LBB2639:
.LBB2593:
	.loc 1 2294 51 view .LVU4064
	xorl	%r10d, %r10d
.LBE2593:
.LBE2639:
	.loc 1 30414 21 view .LVU4065
	addq	%rdi, %r8
.LVL1074:
.LBB2640:
.LBB2556:
	.loc 1 30379 36 view .LVU4066
	imull	%ecx, %edx
	.loc 1 30379 56 view .LVU4067
	sarl	$8, %edx
.LBE2556:
.LBE2640:
	.loc 1 30414 35 view .LVU4068
	movswl	%dx, %r9d
.LVL1075:
.LBB2641:
	.loc 1 2292 27 is_stmt 1 view .LVU4069
.LBB2594:
	.loc 1 2294 5 view .LVU4070
	.loc 1 2294 51 is_stmt 0 view .LVU4071
	cmpw	$-128, %dx
	jl	.L917
	.loc 1 2294 23 view .LVU4072
	cmpl	$127, %r9d
	movl	$127, %edx
	cmovg	%edx, %r9d
.LVL1076:
	.loc 1 2294 51 view .LVU4073
	leal	-128(%r9), %r10d
.L917:
.LVL1077:
	.loc 1 2294 51 view .LVU4074
.LBE2594:
.LBE2641:
	.loc 1 30414 23 view .LVU4075
	movb	%r10b, (%r8)
	.loc 1 30413 5 is_stmt 1 view .LVU4076
	.loc 1 30413 48 is_stmt 0 view .LVU4077
	leaq	6(%rax), %r8
.LVL1078:
	.loc 1 30413 31 is_stmt 1 view .LVU4078
	cmpq	%r8, %rbx
	jbe	.L850
	.loc 1 30414 9 view .LVU4079
.LVL1079:
.LBB2642:
	.loc 1 30377 27 view .LVU4080
.LBB2557:
	.loc 1 30379 5 view .LVU4081
	.loc 1 30379 5 is_stmt 0 view .LVU4082
.LBE2557:
.LBE2642:
	.loc 1 30414 64 view .LVU4083
	movswl	(%rsi,%r8,2), %edx
.LBB2643:
.LBB2595:
	.loc 1 2294 51 view .LVU4084
	xorl	%r10d, %r10d
.LBE2595:
.LBE2643:
	.loc 1 30414 21 view .LVU4085
	addq	%rdi, %r8
.LVL1080:
.LBB2644:
.LBB2558:
	.loc 1 30379 36 view .LVU4086
	imull	%ecx, %edx
	.loc 1 30379 56 view .LVU4087
	sarl	$8, %edx
.LBE2558:
.LBE2644:
	.loc 1 30414 35 view .LVU4088
	movswl	%dx, %r9d
.LVL1081:
.LBB2645:
	.loc 1 2292 27 is_stmt 1 view .LVU4089
.LBB2596:
	.loc 1 2294 5 view .LVU4090
	.loc 1 2294 51 is_stmt 0 view .LVU4091
	cmpw	$-128, %dx
	jl	.L918
	.loc 1 2294 23 view .LVU4092
	cmpl	$127, %r9d
	movl	$127, %edx
	cmovg	%edx, %r9d
.LVL1082:
	.loc 1 2294 51 view .LVU4093
	leal	-128(%r9), %r10d
.L918:
.LVL1083:
	.loc 1 2294 51 view .LVU4094
.LBE2596:
.LBE2645:
	.loc 1 30414 23 view .LVU4095
	movb	%r10b, (%r8)
	.loc 1 30413 5 is_stmt 1 view .LVU4096
	.loc 1 30413 48 is_stmt 0 view .LVU4097
	leaq	7(%rax), %r8
.LVL1084:
	.loc 1 30413 31 is_stmt 1 view .LVU4098
	cmpq	%r8, %rbx
	jbe	.L850
	.loc 1 30414 9 view .LVU4099
.LVL1085:
.LBB2646:
	.loc 1 30377 27 view .LVU4100
.LBB2559:
	.loc 1 30379 5 view .LVU4101
	.loc 1 30379 5 is_stmt 0 view .LVU4102
.LBE2559:
.LBE2646:
	.loc 1 30414 64 view .LVU4103
	movswl	(%rsi,%r8,2), %edx
.LBB2647:
.LBB2597:
	.loc 1 2294 51 view .LVU4104
	xorl	%r10d, %r10d
.LBE2597:
.LBE2647:
	.loc 1 30414 21 view .LVU4105
	addq	%rdi, %r8
.LVL1086:
.LBB2648:
.LBB2560:
	.loc 1 30379 36 view .LVU4106
	imull	%ecx, %edx
	.loc 1 30379 56 view .LVU4107
	sarl	$8, %edx
.LBE2560:
.LBE2648:
	.loc 1 30414 35 view .LVU4108
	movswl	%dx, %r9d
.LVL1087:
.LBB2649:
	.loc 1 2292 27 is_stmt 1 view .LVU4109
.LBB2598:
	.loc 1 2294 5 view .LVU4110
	.loc 1 2294 51 is_stmt 0 view .LVU4111
	cmpw	$-128, %dx
	jl	.L919
	.loc 1 2294 23 view .LVU4112
	cmpl	$127, %r9d
	movl	$127, %edx
	cmovg	%edx, %r9d
.LVL1088:
	.loc 1 2294 51 view .LVU4113
	leal	-128(%r9), %r10d
.L919:
.LVL1089:
	.loc 1 2294 51 view .LVU4114
.LBE2598:
.LBE2649:
	.loc 1 30414 23 view .LVU4115
	movb	%r10b, (%r8)
	.loc 1 30413 5 is_stmt 1 view .LVU4116
	.loc 1 30413 48 is_stmt 0 view .LVU4117
	leaq	8(%rax), %r8
.LVL1090:
	.loc 1 30413 31 is_stmt 1 view .LVU4118
	cmpq	%r8, %rbx
	jbe	.L850
	.loc 1 30414 9 view .LVU4119
.LVL1091:
.LBB2650:
	.loc 1 30377 27 view .LVU4120
.LBB2561:
	.loc 1 30379 5 view .LVU4121
	.loc 1 30379 5 is_stmt 0 view .LVU4122
.LBE2561:
.LBE2650:
	.loc 1 30414 64 view .LVU4123
	movswl	(%rsi,%r8,2), %edx
.LBB2651:
.LBB2599:
	.loc 1 2294 51 view .LVU4124
	xorl	%r10d, %r10d
.LBE2599:
.LBE2651:
	.loc 1 30414 21 view .LVU4125
	addq	%rdi, %r8
.LVL1092:
.LBB2652:
.LBB2562:
	.loc 1 30379 36 view .LVU4126
	imull	%ecx, %edx
	.loc 1 30379 56 view .LVU4127
	sarl	$8, %edx
.LBE2562:
.LBE2652:
	.loc 1 30414 35 view .LVU4128
	movswl	%dx, %r9d
.LVL1093:
.LBB2653:
	.loc 1 2292 27 is_stmt 1 view .LVU4129
.LBB2600:
	.loc 1 2294 5 view .LVU4130
	.loc 1 2294 51 is_stmt 0 view .LVU4131
	cmpw	$-128, %dx
	jl	.L920
	.loc 1 2294 23 view .LVU4132
	cmpl	$127, %r9d
	movl	$127, %edx
	cmovg	%edx, %r9d
.LVL1094:
	.loc 1 2294 51 view .LVU4133
	leal	-128(%r9), %r10d
.L920:
.LVL1095:
	.loc 1 2294 51 view .LVU4134
.LBE2600:
.LBE2653:
	.loc 1 30414 23 view .LVU4135
	movb	%r10b, (%r8)
	.loc 1 30413 5 is_stmt 1 view .LVU4136
	.loc 1 30413 48 is_stmt 0 view .LVU4137
	leaq	9(%rax), %r8
.LVL1096:
	.loc 1 30413 31 is_stmt 1 view .LVU4138
	cmpq	%r8, %rbx
	jbe	.L850
	.loc 1 30414 9 view .LVU4139
.LVL1097:
.LBB2654:
	.loc 1 30377 27 view .LVU4140
.LBB2563:
	.loc 1 30379 5 view .LVU4141
	.loc 1 30379 5 is_stmt 0 view .LVU4142
.LBE2563:
.LBE2654:
	.loc 1 30414 64 view .LVU4143
	movswl	(%rsi,%r8,2), %edx
.LBB2655:
.LBB2601:
	.loc 1 2294 51 view .LVU4144
	xorl	%r10d, %r10d
.LBE2601:
.LBE2655:
	.loc 1 30414 21 view .LVU4145
	addq	%rdi, %r8
.LVL1098:
.LBB2656:
.LBB2564:
	.loc 1 30379 36 view .LVU4146
	imull	%ecx, %edx
	.loc 1 30379 56 view .LVU4147
	sarl	$8, %edx
.LBE2564:
.LBE2656:
	.loc 1 30414 35 view .LVU4148
	movswl	%dx, %r9d
.LVL1099:
.LBB2657:
	.loc 1 2292 27 is_stmt 1 view .LVU4149
.LBB2602:
	.loc 1 2294 5 view .LVU4150
	.loc 1 2294 51 is_stmt 0 view .LVU4151
	cmpw	$-128, %dx
	jl	.L921
	.loc 1 2294 23 view .LVU4152
	cmpl	$127, %r9d
	movl	$127, %edx
	cmovg	%edx, %r9d
.LVL1100:
	.loc 1 2294 51 view .LVU4153
	leal	-128(%r9), %r10d
.L921:
.LVL1101:
	.loc 1 2294 51 view .LVU4154
.LBE2602:
.LBE2657:
	.loc 1 30414 23 view .LVU4155
	movb	%r10b, (%r8)
	.loc 1 30413 5 is_stmt 1 view .LVU4156
	.loc 1 30413 48 is_stmt 0 view .LVU4157
	leaq	10(%rax), %r8
.LVL1102:
	.loc 1 30413 31 is_stmt 1 view .LVU4158
	cmpq	%r8, %rbx
	jbe	.L850
	.loc 1 30414 9 view .LVU4159
.LVL1103:
.LBB2658:
	.loc 1 30377 27 view .LVU4160
.LBB2565:
	.loc 1 30379 5 view .LVU4161
	.loc 1 30379 5 is_stmt 0 view .LVU4162
.LBE2565:
.LBE2658:
	.loc 1 30414 64 view .LVU4163
	movswl	(%rsi,%r8,2), %edx
.LBB2659:
.LBB2603:
	.loc 1 2294 51 view .LVU4164
	xorl	%r10d, %r10d
.LBE2603:
.LBE2659:
	.loc 1 30414 21 view .LVU4165
	addq	%rdi, %r8
.LVL1104:
.LBB2660:
.LBB2566:
	.loc 1 30379 36 view .LVU4166
	imull	%ecx, %edx
	.loc 1 30379 56 view .LVU4167
	sarl	$8, %edx
.LBE2566:
.LBE2660:
	.loc 1 30414 35 view .LVU4168
	movswl	%dx, %r9d
.LVL1105:
.LBB2661:
	.loc 1 2292 27 is_stmt 1 view .LVU4169
.LBB2604:
	.loc 1 2294 5 view .LVU4170
	.loc 1 2294 51 is_stmt 0 view .LVU4171
	cmpw	$-128, %dx
	jl	.L922
	.loc 1 2294 23 view .LVU4172
	cmpl	$127, %r9d
	movl	$127, %edx
	cmovg	%edx, %r9d
.LVL1106:
	.loc 1 2294 51 view .LVU4173
	leal	-128(%r9), %r10d
.L922:
.LVL1107:
	.loc 1 2294 51 view .LVU4174
.LBE2604:
.LBE2661:
	.loc 1 30414 23 view .LVU4175
	movb	%r10b, (%r8)
	.loc 1 30413 5 is_stmt 1 view .LVU4176
	.loc 1 30413 48 is_stmt 0 view .LVU4177
	leaq	11(%rax), %r8
.LVL1108:
	.loc 1 30413 31 is_stmt 1 view .LVU4178
	cmpq	%r8, %rbx
	jbe	.L850
	.loc 1 30414 9 view .LVU4179
.LVL1109:
.LBB2662:
	.loc 1 30377 27 view .LVU4180
.LBB2567:
	.loc 1 30379 5 view .LVU4181
	.loc 1 30379 5 is_stmt 0 view .LVU4182
.LBE2567:
.LBE2662:
	.loc 1 30414 64 view .LVU4183
	movswl	(%rsi,%r8,2), %edx
.LBB2663:
.LBB2605:
	.loc 1 2294 51 view .LVU4184
	xorl	%r10d, %r10d
.LBE2605:
.LBE2663:
	.loc 1 30414 21 view .LVU4185
	addq	%rdi, %r8
.LVL1110:
.LBB2664:
.LBB2568:
	.loc 1 30379 36 view .LVU4186
	imull	%ecx, %edx
	.loc 1 30379 56 view .LVU4187
	sarl	$8, %edx
.LBE2568:
.LBE2664:
	.loc 1 30414 35 view .LVU4188
	movswl	%dx, %r9d
.LVL1111:
.LBB2665:
	.loc 1 2292 27 is_stmt 1 view .LVU4189
.LBB2606:
	.loc 1 2294 5 view .LVU4190
	.loc 1 2294 51 is_stmt 0 view .LVU4191
	cmpw	$-128, %dx
	jl	.L923
	.loc 1 2294 23 view .LVU4192
	cmpl	$127, %r9d
	movl	$127, %edx
	cmovg	%edx, %r9d
.LVL1112:
	.loc 1 2294 51 view .LVU4193
	leal	-128(%r9), %r10d
.L923:
.LVL1113:
	.loc 1 2294 51 view .LVU4194
.LBE2606:
.LBE2665:
	.loc 1 30414 23 view .LVU4195
	movb	%r10b, (%r8)
	.loc 1 30413 5 is_stmt 1 view .LVU4196
	.loc 1 30413 48 is_stmt 0 view .LVU4197
	leaq	12(%rax), %r8
.LVL1114:
	.loc 1 30413 31 is_stmt 1 view .LVU4198
	cmpq	%r8, %rbx
	jbe	.L850
	.loc 1 30414 9 view .LVU4199
.LVL1115:
.LBB2666:
	.loc 1 30377 27 view .LVU4200
.LBB2569:
	.loc 1 30379 5 view .LVU4201
	.loc 1 30379 5 is_stmt 0 view .LVU4202
.LBE2569:
.LBE2666:
	.loc 1 30414 64 view .LVU4203
	movswl	(%rsi,%r8,2), %edx
.LBB2667:
.LBB2607:
	.loc 1 2294 51 view .LVU4204
	xorl	%r10d, %r10d
.LBE2607:
.LBE2667:
	.loc 1 30414 21 view .LVU4205
	addq	%rdi, %r8
.LVL1116:
.LBB2668:
.LBB2570:
	.loc 1 30379 36 view .LVU4206
	imull	%ecx, %edx
	.loc 1 30379 56 view .LVU4207
	sarl	$8, %edx
.LBE2570:
.LBE2668:
	.loc 1 30414 35 view .LVU4208
	movswl	%dx, %r9d
.LVL1117:
.LBB2669:
	.loc 1 2292 27 is_stmt 1 view .LVU4209
.LBB2608:
	.loc 1 2294 5 view .LVU4210
	.loc 1 2294 51 is_stmt 0 view .LVU4211
	cmpw	$-128, %dx
	jl	.L924
	.loc 1 2294 23 view .LVU4212
	cmpl	$127, %r9d
	movl	$127, %edx
	cmovg	%edx, %r9d
.LVL1118:
	.loc 1 2294 51 view .LVU4213
	leal	-128(%r9), %r10d
.L924:
.LVL1119:
	.loc 1 2294 51 view .LVU4214
.LBE2608:
.LBE2669:
	.loc 1 30414 23 view .LVU4215
	movb	%r10b, (%r8)
	.loc 1 30413 5 is_stmt 1 view .LVU4216
	.loc 1 30413 48 is_stmt 0 view .LVU4217
	leaq	13(%rax), %r8
.LVL1120:
	.loc 1 30413 31 is_stmt 1 view .LVU4218
	cmpq	%r8, %rbx
	jbe	.L850
	.loc 1 30414 9 view .LVU4219
.LVL1121:
.LBB2670:
	.loc 1 30377 27 view .LVU4220
.LBB2571:
	.loc 1 30379 5 view .LVU4221
	.loc 1 30379 5 is_stmt 0 view .LVU4222
.LBE2571:
.LBE2670:
	.loc 1 30414 64 view .LVU4223
	movswl	(%rsi,%r8,2), %edx
.LBB2671:
.LBB2609:
	.loc 1 2294 51 view .LVU4224
	xorl	%r10d, %r10d
.LBE2609:
.LBE2671:
	.loc 1 30414 21 view .LVU4225
	addq	%rdi, %r8
.LVL1122:
.LBB2672:
.LBB2572:
	.loc 1 30379 36 view .LVU4226
	imull	%ecx, %edx
	.loc 1 30379 56 view .LVU4227
	sarl	$8, %edx
.LBE2572:
.LBE2672:
	.loc 1 30414 35 view .LVU4228
	movswl	%dx, %r9d
.LVL1123:
.LBB2673:
	.loc 1 2292 27 is_stmt 1 view .LVU4229
.LBB2610:
	.loc 1 2294 5 view .LVU4230
	.loc 1 2294 51 is_stmt 0 view .LVU4231
	cmpw	$-128, %dx
	jl	.L925
	.loc 1 2294 23 view .LVU4232
	cmpl	$127, %r9d
	movl	$127, %edx
	cmovg	%edx, %r9d
.LVL1124:
	.loc 1 2294 51 view .LVU4233
	leal	-128(%r9), %r10d
.L925:
.LVL1125:
	.loc 1 2294 51 view .LVU4234
.LBE2610:
.LBE2673:
	.loc 1 30413 48 view .LVU4235
	addq	$14, %rax
.LVL1126:
	.loc 1 30414 23 view .LVU4236
	movb	%r10b, (%r8)
	.loc 1 30413 5 is_stmt 1 view .LVU4237
.LVL1127:
	.loc 1 30413 31 view .LVU4238
	cmpq	%rax, %rbx
	jbe	.L850
	.loc 1 30414 9 view .LVU4239
.LVL1128:
.LBB2674:
	.loc 1 30377 27 view .LVU4240
.LBB2573:
	.loc 1 30379 5 view .LVU4241
	.loc 1 30379 5 is_stmt 0 view .LVU4242
.LBE2573:
.LBE2674:
	.loc 1 30414 64 view .LVU4243
	movswl	(%rsi,%rax,2), %edx
	.loc 1 30414 21 view .LVU4244
	addq	%rdi, %rax
.LBB2675:
.LBB2574:
	.loc 1 30379 36 view .LVU4245
	imull	%edx, %ecx
.LVL1129:
	.loc 1 30379 56 view .LVU4246
	sarl	$8, %ecx
.LBE2574:
.LBE2675:
	.loc 1 30414 35 view .LVU4247
	movswl	%cx, %edx
.LVL1130:
.LBB2676:
	.loc 1 2292 27 is_stmt 1 view .LVU4248
.LBB2611:
	.loc 1 2294 5 view .LVU4249
	.loc 1 2294 51 is_stmt 0 view .LVU4250
	cmpw	$-128, %cx
	jge	.L926
.LVL1131:
.L1044:
	.loc 1 2294 51 view .LVU4251
	xorl	%edx, %edx
.LBE2611:
.LBE2676:
	.loc 1 30414 23 view .LVU4252
	movb	%dl, (%rax)
	.loc 1 30413 5 is_stmt 1 view .LVU4253
	.loc 1 30413 31 view .LVU4254
	jmp	.L850
.LVL1132:
	.p2align 4,,10
	.p2align 3
.L902:
	.loc 1 30413 31 is_stmt 0 view .LVU4255
.LBE2683:
.LBE2688:
.LBB2689:
.LBB2690:
	.loc 1 30475 31 is_stmt 1 view .LVU4256
	testq	%rbx, %rbx
	je	.L850
	leaq	4(%rsi), %rdx
.LVL1133:
	.loc 1 30475 31 is_stmt 0 view .LVU4257
	movq	%rdi, %rax
	subq	%rdx, %rax
	cmpq	$8, %rax
	jbe	.L979
	leaq	-1(%rbx), %rax
	cmpq	$2, %rax
	jbe	.L979
	movq	%rbx, %rdx
	movaps	.LC86(%rip), %xmm4
	movaps	%xmm0, %xmm5
	xorl	%eax, %eax
	shrq	$2, %rdx
	movaps	.LC87(%rip), %xmm3
	shufps	$0, %xmm5, %xmm5
	salq	$4, %rdx
.LVL1134:
	.p2align 4,,10
	.p2align 3
.L939:
	.loc 1 30476 9 is_stmt 1 view .LVU4258
.LBB2691:
.LBI2691:
	.loc 1 30397 24 view .LVU4259
.LBB2692:
	.loc 1 30399 5 view .LVU4260
	.loc 1 30399 5 is_stmt 0 view .LVU4261
.LBE2692:
.LBE2691:
.LBE2690:
.LBE2689:
.LBE2731:
.LBE2745:
	.loc 1 2320 5 is_stmt 1 view .LVU4262
.LBB2746:
.LBB2732:
.LBB2721:
.LBB2715:
.LBB2704:
.LBB2693:
	.loc 1 30399 16 is_stmt 0 view .LVU4263
	movups	(%rsi,%rax), %xmm1
	mulps	%xmm5, %xmm1
.LBE2693:
.LBE2704:
	.loc 1 30476 23 view .LVU4264
	minps	%xmm4, %xmm1
	maxps	%xmm3, %xmm1
	movups	%xmm1, (%rdi,%rax)
	.loc 1 30475 5 is_stmt 1 view .LVU4265
	.loc 1 30475 31 view .LVU4266
	addq	$16, %rax
	cmpq	%rax, %rdx
	jne	.L939
	movq	%rbx, %rax
	andq	$-4, %rax
	testb	$3, %bl
	je	.L850
.LVL1135:
	.loc 1 30476 9 view .LVU4267
.LBB2705:
	.loc 1 30397 24 view .LVU4268
.LBB2694:
	.loc 1 30399 5 view .LVU4269
	.loc 1 30399 5 is_stmt 0 view .LVU4270
.LBE2694:
.LBE2705:
.LBE2715:
.LBE2721:
.LBE2732:
.LBE2746:
	.loc 1 2320 5 is_stmt 1 view .LVU4271
.LBB2747:
.LBB2733:
.LBB2722:
.LBB2716:
.LBB2706:
.LBB2695:
	.loc 1 30399 16 is_stmt 0 view .LVU4272
	movss	(%rsi,%rax,4), %xmm1
.LBE2695:
.LBE2706:
	.loc 1 30476 23 view .LVU4273
	movss	.LC88(%rip), %xmm3
	.loc 1 30475 48 view .LVU4274
	leaq	1(%rax), %rdx
.LBB2707:
.LBB2696:
	.loc 1 30399 16 view .LVU4275
	mulss	%xmm0, %xmm1
.LBE2696:
.LBE2707:
	.loc 1 30476 23 view .LVU4276
	minss	%xmm2, %xmm1
	maxss	%xmm3, %xmm1
	movss	%xmm1, (%rdi,%rax,4)
	.loc 1 30475 5 is_stmt 1 view .LVU4277
.LVL1136:
	.loc 1 30475 31 view .LVU4278
	cmpq	%rdx, %rbx
	jbe	.L850
	.loc 1 30476 9 view .LVU4279
.LVL1137:
.LBB2708:
	.loc 1 30397 24 view .LVU4280
.LBB2697:
	.loc 1 30399 5 view .LVU4281
	.loc 1 30399 5 is_stmt 0 view .LVU4282
.LBE2697:
.LBE2708:
.LBE2716:
.LBE2722:
.LBE2733:
.LBE2747:
	.loc 1 2320 5 is_stmt 1 view .LVU4283
.LBB2748:
.LBB2734:
.LBB2723:
.LBB2717:
.LBB2709:
.LBB2698:
	.loc 1 30399 16 is_stmt 0 view .LVU4284
	movss	(%rsi,%rdx,4), %xmm1
.LBE2698:
.LBE2709:
	.loc 1 30475 48 view .LVU4285
	addq	$2, %rax
.LBB2710:
.LBB2699:
	.loc 1 30399 16 view .LVU4286
	mulss	%xmm0, %xmm1
.LBE2699:
.LBE2710:
	.loc 1 30476 23 view .LVU4287
	minss	%xmm2, %xmm1
	maxss	%xmm3, %xmm1
	movss	%xmm1, (%rdi,%rdx,4)
	.loc 1 30475 5 is_stmt 1 view .LVU4288
.LVL1138:
	.loc 1 30475 31 view .LVU4289
	cmpq	%rax, %rbx
	jbe	.L850
	.loc 1 30476 9 view .LVU4290
.LVL1139:
.LBB2711:
	.loc 1 30397 24 view .LVU4291
.LBB2700:
	.loc 1 30399 5 view .LVU4292
	.loc 1 30399 5 is_stmt 0 view .LVU4293
.LBE2700:
.LBE2711:
.LBE2717:
.LBE2723:
.LBE2734:
.LBE2748:
	.loc 1 2320 5 is_stmt 1 view .LVU4294
.LBB2749:
.LBB2735:
.LBB2724:
.LBB2718:
.LBB2712:
.LBB2701:
	.loc 1 30399 16 is_stmt 0 view .LVU4295
	mulss	(%rsi,%rax,4), %xmm0
.LVL1140:
	.loc 1 30399 16 view .LVU4296
.LBE2701:
.LBE2712:
	.loc 1 30476 23 view .LVU4297
	minss	%xmm0, %xmm2
	maxss	%xmm3, %xmm2
	movss	%xmm2, (%rdi,%rax,4)
	.loc 1 30475 5 is_stmt 1 view .LVU4298
	.loc 1 30475 31 view .LVU4299
	jmp	.L850
.LVL1141:
	.p2align 4,,10
	.p2align 3
.L856:
	.loc 1 30475 31 is_stmt 0 view .LVU4300
.LBE2718:
.LBE2724:
.LBE2735:
.LBE2749:
.LBB2750:
.LBB2392:
.LBB2383:
.LBB2258:
.LBB2259:
	.loc 1 30148 31 is_stmt 1 view .LVU4301
	testq	%rbx, %rbx
	je	.L850
	leaq	4(%rsi), %rdx
.LVL1142:
	.loc 1 30148 31 is_stmt 0 view .LVU4302
	movq	%rdi, %rax
	subq	%rdx, %rax
	cmpq	$8, %rax
	jbe	.L960
	leaq	-1(%rbx), %rax
	cmpq	$3, %rax
	jbe	.L960
	movq	%rbx, %rdx
	movaps	.LC86(%rip), %xmm4
	movaps	.LC87(%rip), %xmm3
	xorl	%eax, %eax
	shrq	$2, %rdx
	salq	$4, %rdx
.LVL1143:
	.p2align 4,,10
	.p2align 3
.L895:
	.loc 1 30149 9 is_stmt 1 view .LVU4303
	.loc 1 30149 9 is_stmt 0 view .LVU4304
.LBE2259:
.LBE2258:
.LBE2383:
.LBE2392:
.LBE2750:
	.loc 1 2320 5 is_stmt 1 view .LVU4305
.LBB2751:
.LBB2393:
.LBB2384:
.LBB2266:
.LBB2260:
	.loc 1 30149 23 is_stmt 0 view .LVU4306
	movups	(%rsi,%rax), %xmm0
	minps	%xmm4, %xmm0
	maxps	%xmm3, %xmm0
	movups	%xmm0, (%rdi,%rax)
	.loc 1 30148 5 is_stmt 1 view .LVU4307
	.loc 1 30148 31 view .LVU4308
	addq	$16, %rax
	cmpq	%rax, %rdx
	jne	.L895
	movq	%rbx, %rax
	andq	$-4, %rax
	testb	$3, %bl
	je	.L850
.LVL1144:
	.loc 1 30149 9 view .LVU4309
	.loc 1 30149 9 is_stmt 0 view .LVU4310
.LBE2260:
.LBE2266:
.LBE2384:
.LBE2393:
.LBE2751:
	.loc 1 2320 5 is_stmt 1 view .LVU4311
.LBB2752:
.LBB2394:
.LBB2385:
.LBB2267:
.LBB2261:
	.loc 1 30149 23 is_stmt 0 view .LVU4312
	movss	(%rsi,%rax,4), %xmm0
	movss	.LC88(%rip), %xmm1
	.loc 1 30148 48 view .LVU4313
	leaq	1(%rax), %rdx
	.loc 1 30149 23 view .LVU4314
	minss	%xmm2, %xmm0
	maxss	%xmm1, %xmm0
	movss	%xmm0, (%rdi,%rax,4)
	.loc 1 30148 5 is_stmt 1 view .LVU4315
.LVL1145:
	.loc 1 30148 31 view .LVU4316
	cmpq	%rdx, %rbx
	jbe	.L850
	.loc 1 30149 9 view .LVU4317
.LVL1146:
	.loc 1 30149 9 is_stmt 0 view .LVU4318
.LBE2261:
.LBE2267:
.LBE2385:
.LBE2394:
.LBE2752:
	.loc 1 2320 5 is_stmt 1 view .LVU4319
.LBB2753:
.LBB2395:
.LBB2386:
.LBB2268:
.LBB2262:
	.loc 1 30149 23 is_stmt 0 view .LVU4320
	movss	(%rsi,%rdx,4), %xmm0
	.loc 1 30148 48 view .LVU4321
	addq	$2, %rax
	.loc 1 30149 23 view .LVU4322
	minss	%xmm2, %xmm0
	maxss	%xmm1, %xmm0
	movss	%xmm0, (%rdi,%rdx,4)
	.loc 1 30148 5 is_stmt 1 view .LVU4323
.LVL1147:
	.loc 1 30148 31 view .LVU4324
	cmpq	%rax, %rbx
	jbe	.L850
	.loc 1 30149 9 view .LVU4325
.LVL1148:
	.loc 1 30149 9 is_stmt 0 view .LVU4326
.LBE2262:
.LBE2268:
.LBE2386:
.LBE2395:
.LBE2753:
	.loc 1 2320 5 is_stmt 1 view .LVU4327
.LBB2754:
.LBB2396:
.LBB2387:
.LBB2269:
.LBB2263:
	.loc 1 30149 23 is_stmt 0 view .LVU4328
	minss	(%rsi,%rax,4), %xmm2
	maxss	%xmm1, %xmm2
	movss	%xmm2, (%rdi,%rax,4)
	.loc 1 30148 5 is_stmt 1 view .LVU4329
	.loc 1 30148 31 view .LVU4330
	jmp	.L850
.LVL1149:
	.p2align 4,,10
	.p2align 3
.L859:
	.loc 1 30148 31 is_stmt 0 view .LVU4331
.LBE2263:
.LBE2269:
.LBB2270:
.LBB2271:
.LBB2272:
	.loc 1 30121 31 is_stmt 1 view .LVU4332
	testq	%rbx, %rbx
	je	.L850
	leaq	(%rbx,%rbx,2), %rcx
.LVL1150:
.LBB2273:
.LBB2274:
.LBB2275:
	.loc 1 2304 12 is_stmt 0 view .LVU4333
	movl	$8388607, %r9d
	movq	$-8388608, %r8
.LVL1151:
	.loc 1 2304 12 view .LVU4334
	addq	%rdi, %rcx
.LVL1152:
	.p2align 4,,10
	.p2align 3
.L890:
	.loc 1 2304 12 view .LVU4335
.LBE2275:
.LBE2274:
	.loc 1 30122 9 is_stmt 1 view .LVU4336
.LBB2277:
.LBI2274:
	.loc 1 2302 27 view .LVU4337
.LBB2276:
	.loc 1 2304 5 view .LVU4338
	.loc 1 2304 12 is_stmt 0 view .LVU4339
	cmpq	$8388607, (%rsi)
	movq	%r9, %rax
	cmovle	(%rsi), %rax
	cmpq	$-8388608, %rax
	cmovl	%r8, %rax
.LVL1153:
	.loc 1 2304 12 view .LVU4340
.LBE2276:
.LBE2277:
	.loc 1 30123 9 is_stmt 1 view .LVU4341
.LBE2273:
	.loc 1 30121 31 is_stmt 0 view .LVU4342
	addq	$3, %rdi
	addq	$8, %rsi
.LBB2278:
	.loc 1 30124 59 view .LVU4343
	movq	%rax, %rdx
	.loc 1 30123 29 view .LVU4344
	movb	%al, -3(%rdi)
	.loc 1 30124 9 is_stmt 1 view .LVU4345
	.loc 1 30125 59 is_stmt 0 view .LVU4346
	sarq	$16, %rax
.LVL1154:
	.loc 1 30124 59 view .LVU4347
	sarq	$8, %rdx
.LVL1155:
	.loc 1 30125 29 view .LVU4348
	movb	%al, -1(%rdi)
	.loc 1 30124 29 view .LVU4349
	movb	%dl, -2(%rdi)
	.loc 1 30125 9 is_stmt 1 view .LVU4350
.LBE2278:
	.loc 1 30121 5 view .LVU4351
	.loc 1 30121 31 view .LVU4352
	cmpq	%rdi, %rcx
	jne	.L890
	jmp	.L850
.LVL1156:
	.p2align 4,,10
	.p2align 3
.L860:
	.loc 1 30121 31 is_stmt 0 view .LVU4353
.LBE2272:
.LBE2271:
.LBE2270:
.LBB2279:
.LBB2280:
	.loc 1 30109 31 is_stmt 1 view .LVU4354
	testq	%rbx, %rbx
	je	.L850
	leaq	-1(%rbx), %rax
	cmpq	$6, %rax
	jbe	.L957
	movq	%rbx, %rdx
.LVL1157:
	.loc 1 30109 31 is_stmt 0 view .LVU4355
	movdqa	.LC84(%rip), %xmm4
	movdqa	.LC85(%rip), %xmm3
	xorl	%eax, %eax
	shrq	$3, %rdx
	salq	$4, %rdx
.LVL1158:
	.p2align 4,,10
	.p2align 3
.L888:
	.loc 1 30110 9 is_stmt 1 view .LVU4356
.LBB2281:
.LBI2281:
	.loc 1 2297 27 view .LVU4357
.LBB2282:
	.loc 1 2299 5 view .LVU4358
	.loc 1 2299 22 is_stmt 0 view .LVU4359
	movdqu	(%rsi,%rax,2), %xmm0
	movdqu	(%rsi,%rax,2), %xmm6
	movdqa	%xmm4, %xmm1
	pcmpgtd	%xmm4, %xmm0
	pand	%xmm0, %xmm1
	pandn	%xmm6, %xmm0
	movdqu	16(%rsi,%rax,2), %xmm6
	por	%xmm1, %xmm0
.LBE2282:
.LBE2281:
	.loc 1 30110 23 view .LVU4360
	movdqa	%xmm0, %xmm1
	movdqa	%xmm0, %xmm2
	pcmpgtd	%xmm3, %xmm1
	pand	%xmm1, %xmm2
	pandn	%xmm3, %xmm1
	movdqa	%xmm1, %xmm0
.LBB2293:
.LBB2283:
	.loc 1 2299 22 view .LVU4361
	movdqu	16(%rsi,%rax,2), %xmm1
.LBE2283:
.LBE2293:
	.loc 1 30110 23 view .LVU4362
	por	%xmm2, %xmm0
.LBB2294:
.LBB2284:
	.loc 1 2299 22 view .LVU4363
	movdqa	%xmm4, %xmm2
	pcmpgtd	%xmm4, %xmm1
	pand	%xmm1, %xmm2
	pandn	%xmm6, %xmm1
	por	%xmm2, %xmm1
.LBE2284:
.LBE2294:
	.loc 1 30110 23 view .LVU4364
	movdqa	%xmm1, %xmm2
	pcmpgtd	%xmm3, %xmm2
	pand	%xmm2, %xmm1
	pandn	%xmm3, %xmm2
	por	%xmm2, %xmm1
	movdqa	%xmm0, %xmm2
	punpcklwd	%xmm1, %xmm0
	punpckhwd	%xmm1, %xmm2
	movdqa	%xmm0, %xmm1
	punpcklwd	%xmm2, %xmm0
	punpckhwd	%xmm2, %xmm1
	punpcklwd	%xmm1, %xmm0
	movups	%xmm0, (%rdi,%rax)
	.loc 1 30109 5 is_stmt 1 view .LVU4365
	.loc 1 30109 31 view .LVU4366
	addq	$16, %rax
	cmpq	%rax, %rdx
	jne	.L888
	movq	%rbx, %rax
	andq	$-8, %rax
	testb	$7, %bl
	je	.L850
.L886:
.LVL1159:
	.loc 1 30110 9 view .LVU4367
.LBB2295:
	.loc 1 2297 27 view .LVU4368
.LBB2285:
	.loc 1 2299 5 view .LVU4369
	.loc 1 2299 22 is_stmt 0 view .LVU4370
	movl	$32767, %edx
	cmpl	$32767, (%rsi,%rax,4)
.LBE2285:
.LBE2295:
	.loc 1 30110 23 view .LVU4371
	movl	$-32768, %r9d
.LBB2296:
.LBB2286:
	.loc 1 2299 22 view .LVU4372
	movl	%edx, %ecx
	cmovle	(%rsi,%rax,4), %ecx
.LBE2286:
.LBE2296:
	.loc 1 30110 23 view .LVU4373
	cmpl	$-32768, %ecx
	cmovl	%r9d, %ecx
	movw	%cx, (%rdi,%rax,2)
	.loc 1 30109 5 is_stmt 1 view .LVU4374
	.loc 1 30109 48 is_stmt 0 view .LVU4375
	leaq	1(%rax), %rcx
.LVL1160:
	.loc 1 30109 31 is_stmt 1 view .LVU4376
	cmpq	%rcx, %rbx
	jbe	.L850
	.loc 1 30110 9 view .LVU4377
.LVL1161:
.LBB2297:
	.loc 1 2297 27 view .LVU4378
.LBB2287:
	.loc 1 2299 5 view .LVU4379
	.loc 1 2299 22 is_stmt 0 view .LVU4380
	cmpl	$32767, (%rsi,%rcx,4)
	movl	%edx, %r8d
.LVL1162:
	.loc 1 2299 22 view .LVU4381
	cmovle	(%rsi,%rcx,4), %r8d
.LBE2287:
.LBE2297:
	.loc 1 30110 23 view .LVU4382
	cmpl	$-32768, %r8d
	cmovl	%r9d, %r8d
	movw	%r8w, (%rdi,%rcx,2)
	.loc 1 30109 5 is_stmt 1 view .LVU4383
	.loc 1 30109 48 is_stmt 0 view .LVU4384
	leaq	2(%rax), %rcx
.LVL1163:
	.loc 1 30109 31 is_stmt 1 view .LVU4385
	cmpq	%rcx, %rbx
	jbe	.L850
	.loc 1 30110 9 view .LVU4386
.LVL1164:
.LBB2298:
	.loc 1 2297 27 view .LVU4387
.LBB2288:
	.loc 1 2299 5 view .LVU4388
	.loc 1 2299 22 is_stmt 0 view .LVU4389
	cmpl	$32767, (%rsi,%rcx,4)
	movl	%edx, %r8d
	cmovle	(%rsi,%rcx,4), %r8d
.LBE2288:
.LBE2298:
	.loc 1 30110 23 view .LVU4390
	cmpl	$-32768, %r8d
	cmovl	%r9d, %r8d
	movw	%r8w, (%rdi,%rcx,2)
	.loc 1 30109 5 is_stmt 1 view .LVU4391
	.loc 1 30109 48 is_stmt 0 view .LVU4392
	leaq	3(%rax), %rcx
.LVL1165:
	.loc 1 30109 31 is_stmt 1 view .LVU4393
	cmpq	%rcx, %rbx
	jbe	.L850
	.loc 1 30110 9 view .LVU4394
.LVL1166:
.LBB2299:
	.loc 1 2297 27 view .LVU4395
.LBB2289:
	.loc 1 2299 5 view .LVU4396
	.loc 1 2299 22 is_stmt 0 view .LVU4397
	cmpl	$32767, (%rsi,%rcx,4)
	movl	%edx, %r8d
	cmovle	(%rsi,%rcx,4), %r8d
.LBE2289:
.LBE2299:
	.loc 1 30110 23 view .LVU4398
	cmpl	$-32768, %r8d
	cmovl	%r9d, %r8d
	movw	%r8w, (%rdi,%rcx,2)
	.loc 1 30109 5 is_stmt 1 view .LVU4399
	.loc 1 30109 48 is_stmt 0 view .LVU4400
	leaq	4(%rax), %rcx
.LVL1167:
	.loc 1 30109 31 is_stmt 1 view .LVU4401
	cmpq	%rcx, %rbx
	jbe	.L850
	.loc 1 30110 9 view .LVU4402
.LVL1168:
.LBB2300:
	.loc 1 2297 27 view .LVU4403
.LBB2290:
	.loc 1 2299 5 view .LVU4404
	.loc 1 2299 22 is_stmt 0 view .LVU4405
	cmpl	$32767, (%rsi,%rcx,4)
	movl	%edx, %r8d
	cmovle	(%rsi,%rcx,4), %r8d
.LBE2290:
.LBE2300:
	.loc 1 30110 23 view .LVU4406
	cmpl	$-32768, %r8d
	cmovl	%r9d, %r8d
	movw	%r8w, (%rdi,%rcx,2)
	.loc 1 30109 5 is_stmt 1 view .LVU4407
	.loc 1 30109 48 is_stmt 0 view .LVU4408
	leaq	5(%rax), %rcx
.LVL1169:
	.loc 1 30109 31 is_stmt 1 view .LVU4409
	cmpq	%rcx, %rbx
	jbe	.L850
	.loc 1 30110 9 view .LVU4410
.LVL1170:
.LBB2301:
	.loc 1 2297 27 view .LVU4411
.LBB2291:
	.loc 1 2299 5 view .LVU4412
	.loc 1 2299 22 is_stmt 0 view .LVU4413
	cmpl	$32767, (%rsi,%rcx,4)
	movl	%edx, %r8d
	cmovle	(%rsi,%rcx,4), %r8d
.LBE2291:
.LBE2301:
	.loc 1 30110 23 view .LVU4414
	cmpl	$-32768, %r8d
	cmovl	%r9d, %r8d
	.loc 1 30109 48 view .LVU4415
	addq	$6, %rax
	.loc 1 30110 23 view .LVU4416
	movw	%r8w, (%rdi,%rcx,2)
	.loc 1 30109 5 is_stmt 1 view .LVU4417
.LVL1171:
	.loc 1 30109 31 view .LVU4418
	cmpq	%rax, %rbx
	jbe	.L850
	.loc 1 30110 9 view .LVU4419
.LBB2302:
	.loc 1 2297 27 view .LVU4420
.LBB2292:
	.loc 1 2299 5 view .LVU4421
	.loc 1 2299 22 is_stmt 0 view .LVU4422
	cmpl	$32767, (%rsi,%rax,4)
	cmovle	(%rsi,%rax,4), %edx
.LBE2292:
.LBE2302:
	.loc 1 30110 23 view .LVU4423
	cmpl	$-32768, %edx
	cmovl	%r9d, %edx
	movw	%dx, (%rdi,%rax,2)
	.loc 1 30109 5 is_stmt 1 view .LVU4424
	.loc 1 30109 31 view .LVU4425
	jmp	.L850
.LVL1172:
	.p2align 4,,10
	.p2align 3
.L861:
	.loc 1 30109 31 is_stmt 0 view .LVU4426
.LBE2280:
.LBE2279:
.LBB2304:
.LBB2305:
	.loc 1 30097 31 is_stmt 1 view .LVU4427
	testq	%rbx, %rbx
	je	.L850
	leaq	(%rsi,%rbx,2), %rax
	cmpq	%rax, %rdi
	leaq	(%rdi,%rbx), %rax
	setnb	%dl
.LVL1173:
	.loc 1 30097 31 is_stmt 0 view .LVU4428
	cmpq	%rax, %rsi
	setnb	%al
	orb	%al, %dl
	je	.L942
	leaq	-1(%rbx), %rax
	cmpq	$14, %rax
	jbe	.L942
	movq	%rbx, %rdx
	xorl	%eax, %eax
	.loc 1 30098 35 view .LVU4429
	pxor	%xmm6, %xmm6
	movdqa	.LC81(%rip), %xmm5
	movdqa	.LC76(%rip), %xmm4
	movdqa	.LC82(%rip), %xmm3
	andq	$-16, %rdx
	.loc 1 30098 23 view .LVU4430
	pxor	%xmm2, %xmm2
	movdqa	.LC83(%rip), %xmm8
.LVL1174:
	.p2align 4,,10
	.p2align 3
.L865:
	.loc 1 30098 9 is_stmt 1 view .LVU4431
	.loc 1 30098 48 is_stmt 0 view .LVU4432
	movdqu	(%rsi,%rax,2), %xmm11
	.loc 1 30098 35 view .LVU4433
	movdqa	%xmm6, %xmm0
	.loc 1 30098 48 view .LVU4434
	movdqu	16(%rsi,%rax,2), %xmm9
	.loc 1 30098 23 view .LVU4435
	movdqa	%xmm5, %xmm7
	.loc 1 30098 35 view .LVU4436
	pcmpgtw	%xmm11, %xmm0
	movdqa	%xmm11, %xmm1
	movdqa	%xmm9, %xmm10
	punpcklwd	%xmm0, %xmm1
	punpckhwd	%xmm0, %xmm11
	movdqa	%xmm6, %xmm0
	pcmpgtw	%xmm9, %xmm0
	.loc 1 30098 23 view .LVU4437
	pcmpgtd	%xmm1, %xmm7
	.loc 1 30098 35 view .LVU4438
	punpcklwd	%xmm0, %xmm10
	.loc 1 30098 23 view .LVU4439
	pcmpeqd	%xmm2, %xmm7
	.loc 1 30098 35 view .LVU4440
	punpckhwd	%xmm0, %xmm9
.LBB2306:
.LBI2306:
	.loc 1 2292 27 is_stmt 1 view .LVU4441
.LBB2307:
	.loc 1 2294 5 view .LVU4442
.LBE2307:
.LBE2306:
	.loc 1 30098 23 is_stmt 0 view .LVU4443
	movdqa	%xmm5, %xmm0
	pcmpgtd	%xmm11, %xmm0
	movdqa	%xmm7, %xmm12
	pcmpeqd	%xmm2, %xmm0
	punpcklwd	%xmm0, %xmm7
	punpckhwd	%xmm0, %xmm12
	movdqa	%xmm7, %xmm0
	punpcklwd	%xmm12, %xmm7
	punpckhwd	%xmm12, %xmm0
	movdqa	%xmm5, %xmm12
	punpcklwd	%xmm0, %xmm7
	pcmpgtd	%xmm9, %xmm12
	movdqa	%xmm5, %xmm0
	pcmpgtd	%xmm10, %xmm0
	pand	%xmm4, %xmm7
	pcmpeqd	%xmm2, %xmm12
	pcmpeqd	%xmm2, %xmm0
	movdqa	%xmm0, %xmm13
	punpcklwd	%xmm12, %xmm0
	punpckhwd	%xmm12, %xmm13
	movdqa	%xmm0, %xmm12
	punpckhwd	%xmm13, %xmm12
	punpcklwd	%xmm13, %xmm0
	punpcklwd	%xmm12, %xmm0
.LBB2340:
.LBB2308:
	.loc 1 2294 23 view .LVU4444
	movdqa	%xmm3, %xmm12
.LBE2308:
.LBE2340:
	.loc 1 30098 23 view .LVU4445
	pand	%xmm4, %xmm0
	packuswb	%xmm0, %xmm7
.LBB2341:
.LBB2309:
	.loc 1 2294 23 view .LVU4446
	movdqa	%xmm1, %xmm0
	pcmpgtd	%xmm3, %xmm0
	pand	%xmm0, %xmm12
	pandn	%xmm1, %xmm0
	movdqa	%xmm11, %xmm1
	pcmpgtd	%xmm3, %xmm1
	por	%xmm12, %xmm0
	movdqa	%xmm3, %xmm12
	pand	%xmm1, %xmm12
	pandn	%xmm11, %xmm1
	.loc 1 2294 46 view .LVU4447
	movdqa	%xmm0, %xmm11
	.loc 1 2294 23 view .LVU4448
	por	%xmm12, %xmm1
	.loc 1 2294 46 view .LVU4449
	punpcklwd	%xmm1, %xmm0
	punpckhwd	%xmm1, %xmm11
	movdqa	%xmm0, %xmm1
	punpcklwd	%xmm11, %xmm0
	punpckhwd	%xmm11, %xmm1
	.loc 1 2294 23 view .LVU4450
	movdqa	%xmm3, %xmm11
	.loc 1 2294 46 view .LVU4451
	punpcklwd	%xmm1, %xmm0
	.loc 1 2294 23 view .LVU4452
	movdqa	%xmm10, %xmm1
	pcmpgtd	%xmm3, %xmm1
	.loc 1 2294 46 view .LVU4453
	pand	%xmm4, %xmm0
	.loc 1 2294 23 view .LVU4454
	pand	%xmm1, %xmm11
	pandn	%xmm10, %xmm1
	movdqa	%xmm9, %xmm10
	pcmpgtd	%xmm3, %xmm10
	por	%xmm11, %xmm1
	movdqa	%xmm3, %xmm11
	pand	%xmm10, %xmm11
	pandn	%xmm9, %xmm10
	movdqa	%xmm10, %xmm9
	.loc 1 2294 46 view .LVU4455
	movdqa	%xmm1, %xmm10
	.loc 1 2294 23 view .LVU4456
	por	%xmm11, %xmm9
	.loc 1 2294 46 view .LVU4457
	punpcklwd	%xmm9, %xmm1
	punpckhwd	%xmm9, %xmm10
	movdqa	%xmm1, %xmm9
	punpcklwd	%xmm10, %xmm1
	punpckhwd	%xmm10, %xmm9
	punpcklwd	%xmm9, %xmm1
	pand	%xmm4, %xmm1
	packuswb	%xmm1, %xmm0
	.loc 1 2294 51 view .LVU4458
	paddb	%xmm8, %xmm0
.LBE2309:
.LBE2341:
	.loc 1 30098 23 view .LVU4459
	pand	%xmm7, %xmm0
	movups	%xmm0, (%rdi,%rax)
	.loc 1 30097 5 is_stmt 1 view .LVU4460
	.loc 1 30097 31 view .LVU4461
	addq	$16, %rax
	cmpq	%rax, %rdx
	jne	.L865
	movq	%rbx, %rax
	andq	$-16, %rax
	testb	$15, %bl
	je	.L850
.LVL1175:
	.loc 1 30098 9 view .LVU4462
	.loc 1 30098 35 is_stmt 0 view .LVU4463
	movswl	(%rsi,%rax,2), %edx
	.loc 1 30098 21 view .LVU4464
	leaq	(%rdi,%rax), %r8
.LVL1176:
.LBB2342:
	.loc 1 2292 27 is_stmt 1 view .LVU4465
.LBB2310:
	.loc 1 2294 5 view .LVU4466
	.loc 1 2294 51 is_stmt 0 view .LVU4467
	xorl	%ecx, %ecx
	cmpl	$-128, %edx
	jl	.L868
	.loc 1 2294 23 view .LVU4468
	movl	$127, %ecx
	cmpl	$127, %edx
	cmovg	%ecx, %edx
.LVL1177:
	.loc 1 2294 51 view .LVU4469
	leal	-128(%rdx), %ecx
.L868:
.LVL1178:
	.loc 1 2294 51 view .LVU4470
.LBE2310:
.LBE2342:
	.loc 1 30097 48 view .LVU4471
	leaq	1(%rax), %rdx
	.loc 1 30098 23 view .LVU4472
	movb	%cl, (%r8)
	.loc 1 30097 5 is_stmt 1 view .LVU4473
.LVL1179:
	.loc 1 30097 31 view .LVU4474
	cmpq	%rdx, %rbx
	jbe	.L850
	.loc 1 30098 9 view .LVU4475
	.loc 1 30098 35 is_stmt 0 view .LVU4476
	movswl	(%rsi,%rdx,2), %ecx
.LBB2343:
.LBB2311:
	.loc 1 2294 51 view .LVU4477
	xorl	%r8d, %r8d
.LBE2311:
.LBE2343:
	.loc 1 30098 21 view .LVU4478
	addq	%rdi, %rdx
.LVL1180:
.LBB2344:
	.loc 1 2292 27 is_stmt 1 view .LVU4479
.LBB2312:
	.loc 1 2294 5 view .LVU4480
	.loc 1 2294 51 is_stmt 0 view .LVU4481
	cmpl	$-128, %ecx
	jl	.L869
	.loc 1 2294 23 view .LVU4482
	movl	$127, %r8d
	cmpl	$127, %ecx
	cmovg	%r8d, %ecx
.LVL1181:
	.loc 1 2294 51 view .LVU4483
	leal	-128(%rcx), %r8d
.L869:
.LVL1182:
	.loc 1 2294 51 view .LVU4484
.LBE2312:
.LBE2344:
	.loc 1 30098 23 view .LVU4485
	movb	%r8b, (%rdx)
	.loc 1 30097 5 is_stmt 1 view .LVU4486
	.loc 1 30097 48 is_stmt 0 view .LVU4487
	leaq	2(%rax), %rdx
.LVL1183:
	.loc 1 30097 31 is_stmt 1 view .LVU4488
	cmpq	%rdx, %rbx
	jbe	.L850
	.loc 1 30098 9 view .LVU4489
	.loc 1 30098 35 is_stmt 0 view .LVU4490
	movswl	(%rsi,%rdx,2), %ecx
.LBB2345:
.LBB2313:
	.loc 1 2294 51 view .LVU4491
	xorl	%r8d, %r8d
.LBE2313:
.LBE2345:
	.loc 1 30098 21 view .LVU4492
	addq	%rdi, %rdx
.LVL1184:
.LBB2346:
	.loc 1 2292 27 is_stmt 1 view .LVU4493
.LBB2314:
	.loc 1 2294 5 view .LVU4494
	.loc 1 2294 51 is_stmt 0 view .LVU4495
	cmpl	$-128, %ecx
	jl	.L870
	.loc 1 2294 23 view .LVU4496
	movl	$127, %r8d
	cmpl	$127, %ecx
	cmovg	%r8d, %ecx
.LVL1185:
	.loc 1 2294 51 view .LVU4497
	leal	-128(%rcx), %r8d
.L870:
.LVL1186:
	.loc 1 2294 51 view .LVU4498
.LBE2314:
.LBE2346:
	.loc 1 30098 23 view .LVU4499
	movb	%r8b, (%rdx)
	.loc 1 30097 5 is_stmt 1 view .LVU4500
	.loc 1 30097 48 is_stmt 0 view .LVU4501
	leaq	3(%rax), %rdx
.LVL1187:
	.loc 1 30097 31 is_stmt 1 view .LVU4502
	cmpq	%rdx, %rbx
	jbe	.L850
	.loc 1 30098 9 view .LVU4503
	.loc 1 30098 35 is_stmt 0 view .LVU4504
	movswl	(%rsi,%rdx,2), %ecx
.LBB2347:
.LBB2315:
	.loc 1 2294 51 view .LVU4505
	xorl	%r8d, %r8d
.LBE2315:
.LBE2347:
	.loc 1 30098 21 view .LVU4506
	addq	%rdi, %rdx
.LVL1188:
.LBB2348:
	.loc 1 2292 27 is_stmt 1 view .LVU4507
.LBB2316:
	.loc 1 2294 5 view .LVU4508
	.loc 1 2294 51 is_stmt 0 view .LVU4509
	cmpl	$-128, %ecx
	jl	.L871
	.loc 1 2294 23 view .LVU4510
	movl	$127, %r8d
	cmpl	$127, %ecx
	cmovg	%r8d, %ecx
.LVL1189:
	.loc 1 2294 51 view .LVU4511
	leal	-128(%rcx), %r8d
.L871:
.LVL1190:
	.loc 1 2294 51 view .LVU4512
.LBE2316:
.LBE2348:
	.loc 1 30098 23 view .LVU4513
	movb	%r8b, (%rdx)
	.loc 1 30097 5 is_stmt 1 view .LVU4514
	.loc 1 30097 48 is_stmt 0 view .LVU4515
	leaq	4(%rax), %rdx
.LVL1191:
	.loc 1 30097 31 is_stmt 1 view .LVU4516
	cmpq	%rdx, %rbx
	jbe	.L850
	.loc 1 30098 9 view .LVU4517
	.loc 1 30098 35 is_stmt 0 view .LVU4518
	movswl	(%rsi,%rdx,2), %ecx
.LBB2349:
.LBB2317:
	.loc 1 2294 51 view .LVU4519
	xorl	%r8d, %r8d
.LBE2317:
.LBE2349:
	.loc 1 30098 21 view .LVU4520
	addq	%rdi, %rdx
.LVL1192:
.LBB2350:
	.loc 1 2292 27 is_stmt 1 view .LVU4521
.LBB2318:
	.loc 1 2294 5 view .LVU4522
	.loc 1 2294 51 is_stmt 0 view .LVU4523
	cmpl	$-128, %ecx
	jl	.L872
	.loc 1 2294 23 view .LVU4524
	movl	$127, %r8d
	cmpl	$127, %ecx
	cmovg	%r8d, %ecx
.LVL1193:
	.loc 1 2294 51 view .LVU4525
	leal	-128(%rcx), %r8d
.L872:
.LVL1194:
	.loc 1 2294 51 view .LVU4526
.LBE2318:
.LBE2350:
	.loc 1 30098 23 view .LVU4527
	movb	%r8b, (%rdx)
	.loc 1 30097 5 is_stmt 1 view .LVU4528
	.loc 1 30097 48 is_stmt 0 view .LVU4529
	leaq	5(%rax), %rdx
.LVL1195:
	.loc 1 30097 31 is_stmt 1 view .LVU4530
	cmpq	%rdx, %rbx
	jbe	.L850
	.loc 1 30098 9 view .LVU4531
	.loc 1 30098 35 is_stmt 0 view .LVU4532
	movswl	(%rsi,%rdx,2), %ecx
.LBB2351:
.LBB2319:
	.loc 1 2294 51 view .LVU4533
	xorl	%r8d, %r8d
.LBE2319:
.LBE2351:
	.loc 1 30098 21 view .LVU4534
	addq	%rdi, %rdx
.LVL1196:
.LBB2352:
	.loc 1 2292 27 is_stmt 1 view .LVU4535
.LBB2320:
	.loc 1 2294 5 view .LVU4536
	.loc 1 2294 51 is_stmt 0 view .LVU4537
	cmpl	$-128, %ecx
	jl	.L873
	.loc 1 2294 23 view .LVU4538
	movl	$127, %r8d
	cmpl	$127, %ecx
	cmovg	%r8d, %ecx
.LVL1197:
	.loc 1 2294 51 view .LVU4539
	leal	-128(%rcx), %r8d
.L873:
.LVL1198:
	.loc 1 2294 51 view .LVU4540
.LBE2320:
.LBE2352:
	.loc 1 30098 23 view .LVU4541
	movb	%r8b, (%rdx)
	.loc 1 30097 5 is_stmt 1 view .LVU4542
	.loc 1 30097 48 is_stmt 0 view .LVU4543
	leaq	6(%rax), %rdx
.LVL1199:
	.loc 1 30097 31 is_stmt 1 view .LVU4544
	cmpq	%rdx, %rbx
	jbe	.L850
	.loc 1 30098 9 view .LVU4545
	.loc 1 30098 35 is_stmt 0 view .LVU4546
	movswl	(%rsi,%rdx,2), %ecx
.LBB2353:
.LBB2321:
	.loc 1 2294 51 view .LVU4547
	xorl	%r8d, %r8d
.LBE2321:
.LBE2353:
	.loc 1 30098 21 view .LVU4548
	addq	%rdi, %rdx
.LVL1200:
.LBB2354:
	.loc 1 2292 27 is_stmt 1 view .LVU4549
.LBB2322:
	.loc 1 2294 5 view .LVU4550
	.loc 1 2294 51 is_stmt 0 view .LVU4551
	cmpl	$-128, %ecx
	jl	.L874
	.loc 1 2294 23 view .LVU4552
	movl	$127, %r8d
	cmpl	$127, %ecx
	cmovg	%r8d, %ecx
.LVL1201:
	.loc 1 2294 51 view .LVU4553
	leal	-128(%rcx), %r8d
.L874:
.LVL1202:
	.loc 1 2294 51 view .LVU4554
.LBE2322:
.LBE2354:
	.loc 1 30098 23 view .LVU4555
	movb	%r8b, (%rdx)
	.loc 1 30097 5 is_stmt 1 view .LVU4556
	.loc 1 30097 48 is_stmt 0 view .LVU4557
	leaq	7(%rax), %rdx
.LVL1203:
	.loc 1 30097 31 is_stmt 1 view .LVU4558
	cmpq	%rdx, %rbx
	jbe	.L850
	.loc 1 30098 9 view .LVU4559
	.loc 1 30098 35 is_stmt 0 view .LVU4560
	movswl	(%rsi,%rdx,2), %ecx
.LBB2355:
.LBB2323:
	.loc 1 2294 51 view .LVU4561
	xorl	%r8d, %r8d
.LBE2323:
.LBE2355:
	.loc 1 30098 21 view .LVU4562
	addq	%rdi, %rdx
.LVL1204:
.LBB2356:
	.loc 1 2292 27 is_stmt 1 view .LVU4563
.LBB2324:
	.loc 1 2294 5 view .LVU4564
	.loc 1 2294 51 is_stmt 0 view .LVU4565
	cmpl	$-128, %ecx
	jl	.L875
	.loc 1 2294 23 view .LVU4566
	movl	$127, %r8d
	cmpl	$127, %ecx
	cmovg	%r8d, %ecx
.LVL1205:
	.loc 1 2294 51 view .LVU4567
	leal	-128(%rcx), %r8d
.L875:
.LVL1206:
	.loc 1 2294 51 view .LVU4568
.LBE2324:
.LBE2356:
	.loc 1 30098 23 view .LVU4569
	movb	%r8b, (%rdx)
	.loc 1 30097 5 is_stmt 1 view .LVU4570
	.loc 1 30097 48 is_stmt 0 view .LVU4571
	leaq	8(%rax), %rdx
.LVL1207:
	.loc 1 30097 31 is_stmt 1 view .LVU4572
	cmpq	%rdx, %rbx
	jbe	.L850
	.loc 1 30098 9 view .LVU4573
	.loc 1 30098 35 is_stmt 0 view .LVU4574
	movswl	(%rsi,%rdx,2), %ecx
.LBB2357:
.LBB2325:
	.loc 1 2294 51 view .LVU4575
	xorl	%r8d, %r8d
.LBE2325:
.LBE2357:
	.loc 1 30098 21 view .LVU4576
	addq	%rdi, %rdx
.LVL1208:
.LBB2358:
	.loc 1 2292 27 is_stmt 1 view .LVU4577
.LBB2326:
	.loc 1 2294 5 view .LVU4578
	.loc 1 2294 51 is_stmt 0 view .LVU4579
	cmpl	$-128, %ecx
	jl	.L876
	.loc 1 2294 23 view .LVU4580
	movl	$127, %r8d
	cmpl	$127, %ecx
	cmovg	%r8d, %ecx
.LVL1209:
	.loc 1 2294 51 view .LVU4581
	leal	-128(%rcx), %r8d
.L876:
.LVL1210:
	.loc 1 2294 51 view .LVU4582
.LBE2326:
.LBE2358:
	.loc 1 30098 23 view .LVU4583
	movb	%r8b, (%rdx)
	.loc 1 30097 5 is_stmt 1 view .LVU4584
	.loc 1 30097 48 is_stmt 0 view .LVU4585
	leaq	9(%rax), %rdx
.LVL1211:
	.loc 1 30097 31 is_stmt 1 view .LVU4586
	cmpq	%rdx, %rbx
	jbe	.L850
	.loc 1 30098 9 view .LVU4587
	.loc 1 30098 35 is_stmt 0 view .LVU4588
	movswl	(%rsi,%rdx,2), %ecx
.LBB2359:
.LBB2327:
	.loc 1 2294 51 view .LVU4589
	xorl	%r8d, %r8d
.LBE2327:
.LBE2359:
	.loc 1 30098 21 view .LVU4590
	addq	%rdi, %rdx
.LVL1212:
.LBB2360:
	.loc 1 2292 27 is_stmt 1 view .LVU4591
.LBB2328:
	.loc 1 2294 5 view .LVU4592
	.loc 1 2294 51 is_stmt 0 view .LVU4593
	cmpl	$-128, %ecx
	jl	.L877
	.loc 1 2294 23 view .LVU4594
	movl	$127, %r8d
	cmpl	$127, %ecx
	cmovg	%r8d, %ecx
.LVL1213:
	.loc 1 2294 51 view .LVU4595
	leal	-128(%rcx), %r8d
.L877:
.LVL1214:
	.loc 1 2294 51 view .LVU4596
.LBE2328:
.LBE2360:
	.loc 1 30098 23 view .LVU4597
	movb	%r8b, (%rdx)
	.loc 1 30097 5 is_stmt 1 view .LVU4598
	.loc 1 30097 48 is_stmt 0 view .LVU4599
	leaq	10(%rax), %rdx
.LVL1215:
	.loc 1 30097 31 is_stmt 1 view .LVU4600
	cmpq	%rdx, %rbx
	jbe	.L850
	.loc 1 30098 9 view .LVU4601
	.loc 1 30098 35 is_stmt 0 view .LVU4602
	movswl	(%rsi,%rdx,2), %ecx
.LBB2361:
.LBB2329:
	.loc 1 2294 51 view .LVU4603
	xorl	%r8d, %r8d
.LBE2329:
.LBE2361:
	.loc 1 30098 21 view .LVU4604
	addq	%rdi, %rdx
.LVL1216:
.LBB2362:
	.loc 1 2292 27 is_stmt 1 view .LVU4605
.LBB2330:
	.loc 1 2294 5 view .LVU4606
	.loc 1 2294 51 is_stmt 0 view .LVU4607
	cmpl	$-128, %ecx
	jl	.L878
	.loc 1 2294 23 view .LVU4608
	movl	$127, %r8d
	cmpl	$127, %ecx
	cmovg	%r8d, %ecx
.LVL1217:
	.loc 1 2294 51 view .LVU4609
	leal	-128(%rcx), %r8d
.L878:
.LVL1218:
	.loc 1 2294 51 view .LVU4610
.LBE2330:
.LBE2362:
	.loc 1 30098 23 view .LVU4611
	movb	%r8b, (%rdx)
	.loc 1 30097 5 is_stmt 1 view .LVU4612
	.loc 1 30097 48 is_stmt 0 view .LVU4613
	leaq	11(%rax), %rdx
.LVL1219:
	.loc 1 30097 31 is_stmt 1 view .LVU4614
	cmpq	%rdx, %rbx
	jbe	.L850
	.loc 1 30098 9 view .LVU4615
	.loc 1 30098 35 is_stmt 0 view .LVU4616
	movswl	(%rsi,%rdx,2), %ecx
.LBB2363:
.LBB2331:
	.loc 1 2294 51 view .LVU4617
	xorl	%r8d, %r8d
.LBE2331:
.LBE2363:
	.loc 1 30098 21 view .LVU4618
	addq	%rdi, %rdx
.LVL1220:
.LBB2364:
	.loc 1 2292 27 is_stmt 1 view .LVU4619
.LBB2332:
	.loc 1 2294 5 view .LVU4620
	.loc 1 2294 51 is_stmt 0 view .LVU4621
	cmpl	$-128, %ecx
	jl	.L879
	.loc 1 2294 23 view .LVU4622
	movl	$127, %r8d
	cmpl	$127, %ecx
	cmovg	%r8d, %ecx
.LVL1221:
	.loc 1 2294 51 view .LVU4623
	leal	-128(%rcx), %r8d
.L879:
.LVL1222:
	.loc 1 2294 51 view .LVU4624
.LBE2332:
.LBE2364:
	.loc 1 30098 23 view .LVU4625
	movb	%r8b, (%rdx)
	.loc 1 30097 5 is_stmt 1 view .LVU4626
	.loc 1 30097 48 is_stmt 0 view .LVU4627
	leaq	12(%rax), %rdx
.LVL1223:
	.loc 1 30097 31 is_stmt 1 view .LVU4628
	cmpq	%rdx, %rbx
	jbe	.L850
	.loc 1 30098 9 view .LVU4629
	.loc 1 30098 35 is_stmt 0 view .LVU4630
	movswl	(%rsi,%rdx,2), %ecx
.LBB2365:
.LBB2333:
	.loc 1 2294 51 view .LVU4631
	xorl	%r8d, %r8d
.LBE2333:
.LBE2365:
	.loc 1 30098 21 view .LVU4632
	addq	%rdi, %rdx
.LVL1224:
.LBB2366:
	.loc 1 2292 27 is_stmt 1 view .LVU4633
.LBB2334:
	.loc 1 2294 5 view .LVU4634
	.loc 1 2294 51 is_stmt 0 view .LVU4635
	cmpl	$-128, %ecx
	jl	.L880
	.loc 1 2294 23 view .LVU4636
	movl	$127, %r8d
	cmpl	$127, %ecx
	cmovg	%r8d, %ecx
.LVL1225:
	.loc 1 2294 51 view .LVU4637
	leal	-128(%rcx), %r8d
.L880:
.LVL1226:
	.loc 1 2294 51 view .LVU4638
.LBE2334:
.LBE2366:
	.loc 1 30098 23 view .LVU4639
	movb	%r8b, (%rdx)
	.loc 1 30097 5 is_stmt 1 view .LVU4640
	.loc 1 30097 48 is_stmt 0 view .LVU4641
	leaq	13(%rax), %rdx
.LVL1227:
	.loc 1 30097 31 is_stmt 1 view .LVU4642
	cmpq	%rdx, %rbx
	jbe	.L850
	.loc 1 30098 9 view .LVU4643
	.loc 1 30098 35 is_stmt 0 view .LVU4644
	movswl	(%rsi,%rdx,2), %ecx
.LBB2367:
.LBB2335:
	.loc 1 2294 51 view .LVU4645
	xorl	%r8d, %r8d
.LBE2335:
.LBE2367:
	.loc 1 30098 21 view .LVU4646
	addq	%rdi, %rdx
.LVL1228:
.LBB2368:
	.loc 1 2292 27 is_stmt 1 view .LVU4647
.LBB2336:
	.loc 1 2294 5 view .LVU4648
	.loc 1 2294 51 is_stmt 0 view .LVU4649
	cmpl	$-128, %ecx
	jl	.L881
	.loc 1 2294 23 view .LVU4650
	movl	$127, %r8d
	cmpl	$127, %ecx
	cmovg	%r8d, %ecx
.LVL1229:
	.loc 1 2294 51 view .LVU4651
	leal	-128(%rcx), %r8d
.L881:
.LVL1230:
	.loc 1 2294 51 view .LVU4652
.LBE2336:
.LBE2368:
	.loc 1 30097 48 view .LVU4653
	addq	$14, %rax
.LVL1231:
	.loc 1 30098 23 view .LVU4654
	movb	%r8b, (%rdx)
	.loc 1 30097 5 is_stmt 1 view .LVU4655
.LVL1232:
	.loc 1 30097 31 view .LVU4656
	cmpq	%rax, %rbx
	jbe	.L850
	.loc 1 30098 9 view .LVU4657
	.loc 1 30098 35 is_stmt 0 view .LVU4658
	movswl	(%rsi,%rax,2), %edx
	.loc 1 30098 21 view .LVU4659
	addq	%rdi, %rax
.LVL1233:
.LBB2369:
	.loc 1 2292 27 is_stmt 1 view .LVU4660
.LBB2337:
	.loc 1 2294 5 view .LVU4661
	.loc 1 2294 51 is_stmt 0 view .LVU4662
	cmpl	$-128, %edx
	jl	.L1044
.LVL1234:
.L926:
	.loc 1 2294 51 view .LVU4663
.LBE2337:
.LBE2369:
.LBE2305:
.LBE2304:
.LBE2387:
.LBE2396:
.LBE2754:
.LBB2755:
.LBB2736:
.LBB2725:
.LBB2684:
.LBB2677:
.LBB2612:
	.loc 1 2294 23 view .LVU4664
	cmpl	$127, %edx
	movl	$127, %ecx
	cmovg	%ecx, %edx
	.loc 1 2294 51 view .LVU4665
	addl	$-128, %edx
.LBE2612:
.LBE2677:
	.loc 1 30414 23 view .LVU4666
	movb	%dl, (%rax)
	.loc 1 30413 5 is_stmt 1 view .LVU4667
	.loc 1 30413 31 view .LVU4668
	jmp	.L850
.LVL1235:
	.p2align 4,,10
	.p2align 3
.L858:
	.loc 1 30413 31 is_stmt 0 view .LVU4669
.LBE2684:
.LBE2725:
.LBE2736:
.LBE2755:
.LBB2756:
.LBB2397:
.LBB2388:
.LBB2373:
.LBB2374:
	.loc 1 30136 31 is_stmt 1 view .LVU4670
	testq	%rbx, %rbx
	je	.L850
	.loc 1 30136 18 is_stmt 0 view .LVU4671
	xorl	%eax, %eax
.LBB2375:
.LBB2376:
	.loc 1 2315 22 view .LVU4672
	movl	$-2147483648, %r8d
.LVL1236:
	.loc 1 2315 22 view .LVU4673
	movabsq	$-2147483649, %r9
.LVL1237:
	.p2align 4,,10
	.p2align 3
.L892:
	.loc 1 2315 22 view .LVU4674
.LBE2376:
.LBE2375:
	.loc 1 30137 9 is_stmt 1 view .LVU4675
	.loc 1 30137 36 is_stmt 0 view .LVU4676
	movq	(%rsi,%rax,8), %rdx
.LVL1238:
.LBB2378:
.LBI2375:
	.loc 1 2307 27 is_stmt 1 view .LVU4677
.LBB2377:
	.loc 1 2310 5 view .LVU4678
	.loc 1 2311 5 view .LVU4679
	.loc 1 2312 5 view .LVU4680
	.loc 1 2313 5 view .LVU4681
	.loc 1 2315 5 view .LVU4682
	.loc 1 2315 22 is_stmt 0 view .LVU4683
	movl	$2147483647, %ecx
	cmpq	$2147483646, %rdx
	jg	.L891
	cmpq	%r9, %rdx
	movl	%edx, %ecx
	cmovle	%r8d, %ecx
.L891:
.LVL1239:
	.loc 1 2315 22 view .LVU4684
.LBE2377:
.LBE2378:
	.loc 1 30137 23 view .LVU4685
	movl	%ecx, (%rdi,%rax,4)
	.loc 1 30136 5 is_stmt 1 view .LVU4686
	.loc 1 30136 48 is_stmt 0 view .LVU4687
	addq	$1, %rax
.LVL1240:
	.loc 1 30136 31 is_stmt 1 view .LVU4688
	cmpq	%rax, %rbx
	jne	.L892
	jmp	.L850
.LVL1241:
	.p2align 4,,10
	.p2align 3
.L1049:
	.loc 1 30136 31 is_stmt 0 view .LVU4689
.LBE2374:
.LBE2373:
.LBE2388:
.LBE2397:
.LBE2756:
.LBB2757:
.LBB2737:
.LBB2726:
.LBB2685:
.LBB2678:
.LBB2613:
	.loc 1 2294 23 view .LVU4690
	cmpl	$127, %r8d
	movl	$127, %edx
	cmovg	%edx, %r8d
.LVL1242:
	.loc 1 2294 51 view .LVU4691
	leal	-128(%r8), %r9d
	jmp	.L912
.LVL1243:
	.p2align 4,,10
	.p2align 3
.L979:
	.loc 1 2294 51 view .LVU4692
	movss	.LC88(%rip), %xmm3
.LBE2613:
.LBE2678:
.LBE2685:
.LBE2726:
.LBB2727:
.LBB2719:
	.loc 1 30475 18 view .LVU4693
	xorl	%eax, %eax
.LVL1244:
	.p2align 4,,10
	.p2align 3
.L937:
	.loc 1 30476 9 is_stmt 1 view .LVU4694
.LBB2713:
	.loc 1 30397 24 view .LVU4695
.LBB2702:
	.loc 1 30399 5 view .LVU4696
	.loc 1 30399 5 is_stmt 0 view .LVU4697
.LBE2702:
.LBE2713:
.LBE2719:
.LBE2727:
.LBE2737:
.LBE2757:
	.loc 1 2320 5 is_stmt 1 view .LVU4698
.LBB2758:
.LBB2738:
.LBB2728:
.LBB2720:
.LBB2714:
.LBB2703:
	.loc 1 30399 16 is_stmt 0 view .LVU4699
	movss	(%rsi,%rax,4), %xmm1
	mulss	%xmm0, %xmm1
.LBE2703:
.LBE2714:
	.loc 1 30476 23 view .LVU4700
	minss	%xmm2, %xmm1
	maxss	%xmm3, %xmm1
	movss	%xmm1, (%rdi,%rax,4)
	.loc 1 30475 5 is_stmt 1 view .LVU4701
	.loc 1 30475 48 is_stmt 0 view .LVU4702
	addq	$1, %rax
.LVL1245:
	.loc 1 30475 31 is_stmt 1 view .LVU4703
	cmpq	%rax, %rbx
	jne	.L937
	jmp	.L850
.LVL1246:
	.p2align 4,,10
	.p2align 3
.L961:
	.loc 1 30475 31 is_stmt 0 view .LVU4704
.LBE2720:
.LBE2728:
.LBB2729:
.LBB2686:
	.loc 1 30413 18 view .LVU4705
	xorl	%edx, %edx
.LBB2679:
.LBB2614:
	.loc 1 2294 23 view .LVU4706
	movl	$127, %r9d
.LVL1247:
	.p2align 4,,10
	.p2align 3
.L908:
	.loc 1 2294 23 view .LVU4707
.LBE2614:
.LBE2679:
	.loc 1 30414 9 is_stmt 1 view .LVU4708
.LBB2680:
	.loc 1 30377 27 view .LVU4709
.LBB2575:
	.loc 1 30379 5 view .LVU4710
	.loc 1 30379 5 is_stmt 0 view .LVU4711
.LBE2575:
.LBE2680:
	.loc 1 30414 64 view .LVU4712
	movswl	(%rsi,%rdx,2), %eax
.LBB2681:
.LBB2576:
	.loc 1 30379 36 view .LVU4713
	imull	%ecx, %eax
	.loc 1 30379 56 view .LVU4714
	sarl	$8, %eax
.LBE2576:
.LBE2681:
	.loc 1 30414 35 view .LVU4715
	movswl	%ax, %r8d
.LVL1248:
.LBB2682:
	.loc 1 2292 27 is_stmt 1 view .LVU4716
.LBB2615:
	.loc 1 2294 5 view .LVU4717
	.loc 1 2294 51 is_stmt 0 view .LVU4718
	cmpw	$-128, %ax
	jl	.L928
.LVL1249:
	.loc 1 2294 23 view .LVU4719
	cmpl	$127, %r8d
	cmovg	%r9d, %r8d
	.loc 1 2294 51 view .LVU4720
	addl	$-128, %r8d
	movb	%r8b, (%rdi,%rdx)
.LBE2615:
.LBE2682:
	.loc 1 30413 5 is_stmt 1 view .LVU4721
	.loc 1 30413 48 is_stmt 0 view .LVU4722
	addq	$1, %rdx
.LVL1250:
	.loc 1 30413 31 is_stmt 1 view .LVU4723
	cmpq	%rdx, %rbx
	jne	.L908
	jmp	.L850
.LVL1251:
	.p2align 4,,10
	.p2align 3
.L928:
	.loc 1 30414 23 is_stmt 0 view .LVU4724
	movb	$0, (%rdi,%rdx)
	.loc 1 30413 5 is_stmt 1 view .LVU4725
	.loc 1 30413 48 is_stmt 0 view .LVU4726
	addq	$1, %rdx
.LVL1252:
	.loc 1 30413 31 is_stmt 1 view .LVU4727
	cmpq	%rdx, %rbx
	jne	.L908
	jmp	.L850
.LVL1253:
.L942:
	.loc 1 30413 31 is_stmt 0 view .LVU4728
.LBE2686:
.LBE2729:
.LBE2738:
.LBE2758:
.LBB2759:
.LBB2398:
.LBB2389:
.LBB2379:
.LBB2372:
	.loc 1 30097 18 view .LVU4729
	xorl	%eax, %eax
.LBB2370:
.LBB2338:
	.loc 1 2294 23 view .LVU4730
	movl	$127, %ecx
.LVL1254:
	.p2align 4,,10
	.p2align 3
.L863:
	.loc 1 2294 23 view .LVU4731
.LBE2338:
.LBE2370:
	.loc 1 30098 9 is_stmt 1 view .LVU4732
	.loc 1 30098 35 is_stmt 0 view .LVU4733
	movswl	(%rsi,%rax,2), %edx
.LVL1255:
.LBB2371:
	.loc 1 2292 27 is_stmt 1 view .LVU4734
.LBB2339:
	.loc 1 2294 5 view .LVU4735
	.loc 1 2294 51 is_stmt 0 view .LVU4736
	cmpl	$-128, %edx
	jl	.L884
.LVL1256:
	.loc 1 2294 23 view .LVU4737
	cmpl	$127, %edx
	cmovg	%ecx, %edx
	.loc 1 2294 51 view .LVU4738
	addl	$-128, %edx
	movb	%dl, (%rdi,%rax)
.LBE2339:
.LBE2371:
	.loc 1 30097 5 is_stmt 1 view .LVU4739
	.loc 1 30097 48 is_stmt 0 view .LVU4740
	addq	$1, %rax
.LVL1257:
	.loc 1 30097 31 is_stmt 1 view .LVU4741
	cmpq	%rax, %rbx
	jne	.L863
	jmp	.L850
.LVL1258:
	.p2align 4,,10
	.p2align 3
.L884:
	.loc 1 30098 23 is_stmt 0 view .LVU4742
	movb	$0, (%rdi,%rax)
	.loc 1 30097 5 is_stmt 1 view .LVU4743
	.loc 1 30097 48 is_stmt 0 view .LVU4744
	addq	$1, %rax
.LVL1259:
	.loc 1 30097 31 is_stmt 1 view .LVU4745
	cmpq	%rax, %rbx
	jne	.L863
	jmp	.L850
.LVL1260:
.L960:
	.loc 1 30097 31 is_stmt 0 view .LVU4746
	movss	.LC88(%rip), %xmm3
.LBE2372:
.LBE2379:
.LBB2380:
.LBB2264:
	.loc 1 30148 18 view .LVU4747
	xorl	%eax, %eax
.LVL1261:
	.p2align 4,,10
	.p2align 3
.L893:
	.loc 1 30149 9 is_stmt 1 view .LVU4748
	.loc 1 30149 9 is_stmt 0 view .LVU4749
.LBE2264:
.LBE2380:
.LBE2389:
.LBE2398:
.LBE2759:
	.loc 1 2320 5 is_stmt 1 view .LVU4750
.LBB2760:
.LBB2399:
.LBB2390:
.LBB2381:
.LBB2265:
	.loc 1 30149 23 is_stmt 0 view .LVU4751
	movss	(%rsi,%rax,4), %xmm0
	minss	%xmm2, %xmm0
	maxss	%xmm3, %xmm0
	movss	%xmm0, (%rdi,%rax,4)
	.loc 1 30148 5 is_stmt 1 view .LVU4752
	.loc 1 30148 48 is_stmt 0 view .LVU4753
	addq	$1, %rax
.LVL1262:
	.loc 1 30148 31 is_stmt 1 view .LVU4754
	cmpq	%rax, %rbx
	jne	.L893
	jmp	.L850
.LVL1263:
.L976:
	.loc 1 30148 31 is_stmt 0 view .LVU4755
.LBE2265:
.LBE2381:
.LBE2390:
.LBE2399:
.LBE2760:
.LBB2761:
.LBB2739:
.LBB2730:
.LBB2536:
	.loc 1 30428 18 view .LVU4756
	xorl	%eax, %eax
	jmp	.L930
.LVL1264:
.L957:
	.loc 1 30428 18 view .LVU4757
.LBE2536:
.LBE2730:
.LBE2739:
.LBE2761:
.LBB2762:
.LBB2400:
.LBB2391:
.LBB2382:
.LBB2303:
	.loc 1 30109 18 view .LVU4758
	xorl	%eax, %eax
	jmp	.L886
.LVL1265:
.L1046:
	.loc 1 30109 18 view .LVU4759
.LBE2303:
.LBE2382:
.LBE2391:
.LBE2400:
.LBE2762:
	.loc 1 30483 5 discriminator 1 view .LVU4760
	movl	$.LC78, %ecx
.LVL1266:
	.loc 1 30483 5 discriminator 1 view .LVU4761
	movl	$30483, %edx
.LVL1267:
	.loc 1 30483 5 discriminator 1 view .LVU4762
	movl	$.LC8, %esi
.LVL1268:
	.loc 1 30483 5 discriminator 1 view .LVU4763
	movl	$.LC80, %edi
.LVL1269:
	.loc 1 30483 5 discriminator 1 view .LVU4764
	call	__assert_fail
.LVL1270:
.L1045:
	.loc 1 30482 5 discriminator 1 view .LVU4765
	movl	$.LC78, %ecx
.LVL1271:
	.loc 1 30482 5 discriminator 1 view .LVU4766
	movl	$30482, %edx
.LVL1272:
	.loc 1 30482 5 discriminator 1 view .LVU4767
	movl	$.LC8, %esi
.LVL1273:
	.loc 1 30482 5 discriminator 1 view .LVU4768
	movl	$.LC79, %edi
.LVL1274:
	.loc 1 30482 5 discriminator 1 view .LVU4769
	call	__assert_fail
.LVL1275:
	.loc 1 30482 5 discriminator 1 view .LVU4770
	.cfi_endproc
.LFE123:
	.size	ma_copy_and_apply_volume_and_clip_pcm_frames, .-ma_copy_and_apply_volume_and_clip_pcm_frames
	.p2align 4
	.globl	ma_pcm_convert
	.hidden	ma_pcm_convert
	.type	ma_pcm_convert, @function
ma_pcm_convert:
.LVL1276:
.LFB146:
	.loc 1 32723 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 32723 1 is_stmt 0 view .LVU4772
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
1:	call	mcount
	.loc 1 32723 1 view .LVU4773
	movq	%rdx, %rbx
	.loc 1 32724 5 is_stmt 1 view .LVU4774
	cmpl	%ecx, %esi
	je	.L1461
	.loc 1 32729 5 view .LVU4775
	cmpl	$5, %ecx
	ja	.L1050
	movl	%ecx, %ecx
	.loc 1 32729 5 is_stmt 0 view .LVU4776
	jmp	*.L1056(,%rcx,8)
	.section	.rodata
	.align 8
	.align 4
.L1056:
	.quad	.L1050
	.quad	.L1060
	.quad	.L1059
	.quad	.L1058
	.quad	.L1057
	.quad	.L1055
	.text
	.p2align 4,,10
	.p2align 3
.L1461:
	.loc 1 32725 9 is_stmt 1 view .LVU4777
.LVL1277:
.LBB3314:
.LBI3314:
	.loc 1 44154 18 view .LVU4778
.LBB3315:
	.loc 1 44156 5 view .LVU4779
	.loc 1 44156 15 is_stmt 0 view .LVU4780
	movdqa	.LC22(%rip), %xmm0
	.loc 1 44164 24 view .LVU4781
	movslq	%esi, %rsi
	.loc 1 44164 24 view .LVU4782
	movl	$4294967295, %r14d
	.loc 1 44156 15 view .LVU4783
	movabsq	$17179869188, %rax
	movq	%rax, -64(%rbp)
	.loc 1 44164 5 is_stmt 1 view .LVU4784
.LVL1278:
	.loc 1 44156 15 is_stmt 0 view .LVU4785
	movaps	%xmm0, -80(%rbp)
.LBE3315:
.LBE3314:
	.loc 1 32725 75 view .LVU4786
	movl	-80(%rbp,%rsi,4), %r13d
	.loc 1 32725 26 view .LVU4787
	imulq	%r8, %r13
.LVL1279:
.LBB3316:
.LBI3316:
	.loc 1 1790 23 is_stmt 1 view .LVU4788
.LBB3317:
	.loc 1 1795 5 view .LVU4789
	.loc 1 1795 24 view .LVU4790
	testq	%r13, %r13
	je	.L1050
.LVL1280:
	.p2align 4,,10
	.p2align 3
.L1052:
.LBB3318:
	.loc 1 1796 9 view .LVU4791
	.loc 1 1797 9 view .LVU4792
	cmpq	%r14, %r13
	movq	%r14, %r12
	.loc 1 1801 9 is_stmt 0 view .LVU4793
	movq	%rbx, %rsi
	cmovbe	%r13, %r12
.LVL1281:
	.loc 1 1801 9 is_stmt 1 view .LVU4794
	movq	%r12, %rdx
	.loc 1 1805 13 is_stmt 0 view .LVU4795
	addq	%r12, %rbx
	.loc 1 1801 9 view .LVU4796
	call	memcpy
.LVL1282:
	.loc 1 1801 9 view .LVU4797
	movq	%rax, %rdi
	.loc 1 1803 9 is_stmt 1 view .LVU4798
.LVL1283:
	.loc 1 1804 9 view .LVU4799
	.loc 1 1804 13 is_stmt 0 view .LVU4800
	addq	%r12, %rdi
.LVL1284:
	.loc 1 1805 9 is_stmt 1 view .LVU4801
	.loc 1 1805 9 is_stmt 0 view .LVU4802
.LBE3318:
	.loc 1 1795 5 is_stmt 1 view .LVU4803
	.loc 1 1795 24 view .LVU4804
	subq	%r12, %r13
.LVL1285:
	.loc 1 1795 24 is_stmt 0 view .LVU4805
	jne	.L1052
.LVL1286:
.L1050:
	.loc 1 1795 24 view .LVU4806
.LBE3317:
.LBE3316:
	.loc 1 32793 1 view .LVU4807
	addq	$72, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL1287:
	.p2align 4,,10
	.p2align 3
.L1055:
	.cfi_restore_state
	.loc 1 32779 9 is_stmt 1 view .LVU4808
	.loc 1 32780 9 view .LVU4809
	.loc 1 32781 13 view .LVU4810
	cmpl	$3, %esi
	je	.L1204
	ja	.L1205
	cmpl	$1, %esi
	je	.L1206
	cmpl	$2, %esi
	jne	.L1050
	.loc 1 32784 17 view .LVU4811
	.loc 1 32784 37 view .LVU4812
.LVL1288:
.LBB3319:
.LBI3319:
	.loc 1 32477 13 view .LVU4813
.LBE3319:
	.loc 1 32495 9 view .LVU4814
	.loc 1 32496 13 view .LVU4815
.LBB4426:
.LBB3320:
.LBI3320:
	.loc 1 32089 23 view .LVU4816
.LBB3321:
	.loc 1 32091 5 view .LVU4817
	.loc 1 32092 5 view .LVU4818
	.loc 1 32093 5 view .LVU4819
	.loc 1 32095 5 view .LVU4820
	.loc 1 32096 5 view .LVU4821
	.loc 1 32098 5 view .LVU4822
	.loc 1 32099 5 view .LVU4823
	.loc 1 32100 5 view .LVU4824
	testl	%r9d, %r9d
	jne	.L1462
	pxor	%xmm7, %xmm7
	movaps	%xmm7, %xmm8
	movss	%xmm7, -104(%rbp)
	.loc 1 32099 11 is_stmt 0 view .LVU4825
	movaps	%xmm7, %xmm10
.L1217:
.LVL1289:
	.loc 1 32106 5 is_stmt 1 view .LVU4826
	.loc 1 32107 5 view .LVU4827
	.loc 1 32108 5 view .LVU4828
.LBB3322:
	.loc 1 32108 21 view .LVU4829
	movq	%r8, %r12
	shrq	$2, %r12
.LVL1290:
	.loc 1 32108 21 is_stmt 0 view .LVU4830
	je	.L1274
	salq	$2, %r12
.LVL1291:
	.loc 1 32108 21 view .LVU4831
	movl	_ZL7g_maLCG(%rip), %r11d
	xorl	%r13d, %r13d
.LBE3322:
	.loc 1 32106 7 view .LVU4832
	xorl	%esi, %esi
.LVL1292:
	.loc 1 32106 7 view .LVU4833
	movq	%r8, -112(%rbp)
	leal	-1(%r9), %r15d
.LBB4026:
.LBB3323:
	.loc 1 32119 12 view .LVU4834
	pxor	%xmm11, %xmm11
	movq	%r12, %r10
	movss	.LC77(%rip), %xmm0
	movss	.LC88(%rip), %xmm3
	movsd	.LC104(%rip), %xmm2
	movss	.LC109(%rip), %xmm9
	jmp	.L1272
.LVL1293:
	.p2align 4,,10
	.p2align 3
.L1459:
	.loc 1 32120 12 view .LVU4835
	movss	-100(%rbp), %xmm7
.L1241:
	.loc 1 32120 12 view .LVU4836
	addss	%xmm15, %xmm7
	.loc 1 32121 12 view .LVU4837
	movaps	%xmm11, %xmm6
	.loc 1 32125 25 view .LVU4838
	minss	%xmm0, %xmm7
	maxss	%xmm3, %xmm7
.LVL1294:
	.loc 1 32126 9 is_stmt 1 view .LVU4839
	.loc 1 32121 12 is_stmt 0 view .LVU4840
	cmpl	$1, %r15d
	ja	.L1253
	movd	%r8d, %xmm6
	cmpl	$2, %r9d
	je	.L1253
	.loc 1 32121 12 view .LVU4841
	cmpl	$1, %r9d
	jne	.L1253
.LBB3324:
.LBB3325:
.LBB3326:
.LBB3327:
.LBB3328:
.LBB3329:
	.loc 1 2369 18 view .LVU4842
	mulss	-104(%rbp), %xmm5
	.loc 1 2369 18 view .LVU4843
	movaps	%xmm5, %xmm6
	.loc 1 2369 25 view .LVU4844
	addss	%xmm8, %xmm6
	.p2align 4,,10
	.p2align 3
.L1253:
	.loc 1 2369 25 view .LVU4845
.LBE3329:
.LBE3328:
.LBE3327:
.LBE3326:
.LBE3325:
.LBE3324:
	.loc 1 32121 12 view .LVU4846
	addss	%xmm14, %xmm6
	.loc 1 32122 12 view .LVU4847
	movaps	%xmm11, %xmm5
	.loc 1 32126 25 view .LVU4848
	minss	%xmm0, %xmm6
	maxss	%xmm3, %xmm6
.LVL1295:
	.loc 1 32127 9 is_stmt 1 view .LVU4849
	.loc 1 32122 12 is_stmt 0 view .LVU4850
	cmpl	$1, %r15d
	ja	.L1265
	cmpl	$2, %r9d
	je	.L1460
	cmpl	$1, %r9d
	je	.L1270
.L1460:
	movd	%ecx, %xmm5
.L1265:
	.loc 1 32122 12 view .LVU4851
	addss	%xmm5, %xmm13
	.loc 1 32131 12 view .LVU4852
	mulss	%xmm9, %xmm6
.LVL1296:
	.loc 1 32130 12 view .LVU4853
	mulss	%xmm9, %xmm7
.LVL1297:
	.loc 1 32129 12 view .LVU4854
	mulss	%xmm9, %xmm1
.LVL1298:
	.loc 1 32127 25 view .LVU4855
	minss	%xmm0, %xmm13
	.loc 1 32136 24 view .LVU4856
	cvttss2sil	%xmm6, %r8d
	.loc 1 32135 24 view .LVU4857
	cvttss2sil	%xmm7, %ecx
	.loc 1 32135 24 view .LVU4858
	maxss	%xmm3, %xmm13
.LVL1299:
	.loc 1 32129 9 is_stmt 1 view .LVU4859
	.loc 1 32130 9 view .LVU4860
	.loc 1 32131 9 view .LVU4861
	.loc 1 32132 9 view .LVU4862
	.loc 1 32134 9 view .LVU4863
	.loc 1 32135 9 view .LVU4864
	.loc 1 32136 9 view .LVU4865
	.loc 1 32137 9 view .LVU4866
	.loc 1 32134 24 is_stmt 0 view .LVU4867
	cvttss2sil	%xmm1, %edx
	.loc 1 32132 12 view .LVU4868
	mulss	%xmm9, %xmm13
.LVL1300:
	.loc 1 32134 22 view .LVU4869
	movzwl	%r8w, %r8d
	movzwl	%cx, %ecx
	movzwl	%dx, %edx
	.loc 1 32137 24 view .LVU4870
	cvttss2sil	%xmm13, %eax
	.loc 1 32134 22 view .LVU4871
	movzwl	%ax, %eax
	salq	$16, %rax
	orq	%r8, %rax
	salq	$16, %rax
	orq	%rcx, %rax
	salq	$16, %rax
	orq	%rdx, %rax
	movq	%rax, (%rdi,%rsi,2)
	.loc 1 32139 9 is_stmt 1 view .LVU4872
	.loc 1 32139 11 is_stmt 0 view .LVU4873
	addq	$4, %rsi
.LVL1301:
	.loc 1 32139 11 view .LVU4874
.LBE3323:
	.loc 1 32108 5 is_stmt 1 view .LVU4875
	.loc 1 32108 21 view .LVU4876
	cmpq	%r10, %rsi
	je	.L1463
.LVL1302:
.L1272:
.LBB3990:
	.loc 1 32109 9 view .LVU4877
.LBB3543:
.LBI3543:
	.loc 1 2528 24 view .LVU4878
.LBB3544:
	.loc 1 2530 5 view .LVU4879
	.loc 1 2531 9 view .LVU4880
.LBB3545:
.LBI3545:
	.loc 1 2516 24 view .LVU4881
.LBE3545:
.LBE3544:
.LBE3543:
.LBE3990:
.LBE4026:
.LBE3321:
.LBE3320:
.LBE4426:
	.loc 1 2518 5 view .LVU4882
.LBB4427:
.LBB4369:
.LBB4312:
.LBB4027:
.LBB3991:
.LBB3636:
.LBB3622:
.LBB3587:
.LBB3546:
.LBI3546:
	.loc 1 2505 24 view .LVU4883
.LBE3546:
.LBE3587:
.LBE3622:
.LBE3636:
.LBE3991:
.LBE4027:
.LBE4312:
.LBE4369:
.LBE4427:
	.loc 1 2507 5 view .LVU4884
.LBB4428:
.LBB4370:
.LBB4313:
.LBB4028:
.LBB3992:
.LBB3637:
.LBB3623:
.LBB3588:
.LBB3580:
.LBB3547:
.LBI3547:
	.loc 1 2464 24 view .LVU4885
.LBE3547:
.LBE3580:
.LBE3588:
.LBE3623:
.LBE3637:
.LBE3992:
.LBE4028:
.LBE4313:
.LBE4370:
.LBE4428:
	.loc 1 2466 5 view .LVU4886
.LBB4429:
.LBB4371:
.LBB4314:
.LBB4029:
.LBB3993:
.LBB3638:
.LBB3624:
.LBB3589:
.LBB3581:
.LBB3574:
.LBB3548:
.LBI3548:
	.loc 1 2459 24 view .LVU4887
.LBB3549:
	.loc 1 2461 5 view .LVU4888
.LBB3550:
.LBI3550:
	.loc 1 2454 25 view .LVU4889
.LBB3551:
	.loc 1 2456 5 view .LVU4890
.LBB3552:
.LBI3552:
	.loc 1 2438 27 view .LVU4891
.LBB3553:
	.loc 1 2440 5 view .LVU4892
	.loc 1 2440 29 is_stmt 0 view .LVU4893
	imull	$48271, %r11d, %edx
.LBE3553:
.LBE3552:
	.loc 1 2456 34 view .LVU4894
	pxor	%xmm7, %xmm7
.LBE3551:
.LBE3550:
.LBE3549:
.LBE3548:
.LBE3574:
.LBE3581:
.LBE3589:
.LBE3624:
.LBE3638:
.LBB3639:
.LBB3640:
.LBB3641:
.LBB3642:
.LBB3643:
.LBB3644:
.LBB3645:
.LBB3646:
	pxor	%xmm6, %xmm6
.LBE3646:
.LBE3645:
.LBE3644:
.LBE3643:
.LBE3642:
.LBE3641:
.LBE3640:
.LBE3639:
.LBB3733:
.LBB3383:
.LBB3374:
.LBB3366:
.LBB3331:
.LBB3332:
.LBB3333:
.LBB3334:
	pxor	%xmm5, %xmm5
	movaps	%xmm0, %xmm1
.LBE3334:
.LBE3333:
.LBE3332:
.LBE3331:
.LBE3366:
.LBE3374:
.LBE3383:
.LBE3733:
.LBB3734:
.LBB3625:
.LBB3590:
.LBB3591:
.LBB3592:
.LBB3593:
.LBB3594:
.LBB3595:
	.loc 1 2369 18 view .LVU4895
	movaps	%xmm10, %xmm12
.LBE3595:
.LBE3594:
.LBE3593:
.LBE3592:
.LBE3591:
.LBE3590:
.LBE3625:
.LBE3734:
.LBB3735:
.LBB3736:
.LBB3737:
.LBB3738:
.LBB3739:
.LBB3740:
.LBB3741:
.LBB3742:
	.loc 1 2456 34 view .LVU4896
	pxor	%xmm4, %xmm4
.LBE3742:
.LBE3741:
.LBE3740:
.LBE3739:
.LBE3738:
.LBE3737:
.LBE3736:
.LBE3735:
.LBB3921:
.LBB3626:
.LBB3612:
.LBB3582:
.LBB3575:
.LBB3566:
.LBB3562:
.LBB3559:
.LBB3556:
.LBB3555:
.LBB3554:
	.loc 1 2440 55 view .LVU4897
	movslq	%edx, %rcx
	movq	%rcx, %rax
	salq	$30, %rax
	addq	%rcx, %rax
	movl	%edx, %ecx
	sarl	$31, %ecx
	sarq	$61, %rax
	subl	%ecx, %eax
	movl	%eax, %ecx
	sall	$31, %ecx
	subl	%eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	.loc 1 2441 5 is_stmt 1 view .LVU4898
.LBE3554:
.LBE3555:
.LBE3556:
.LBE3559:
.LBE3562:
.LBE3566:
.LBE3575:
.LBE3582:
.LBE3612:
.LBE3626:
.LBE3921:
.LBB3922:
.LBB3698:
.LBB3689:
.LBB3681:
.LBB3671:
.LBB3665:
.LBB3660:
.LBB3655:
.LBB3647:
.LBB3648:
	.loc 1 2440 29 is_stmt 0 view .LVU4899
	imull	$48271, %eax, %edx
.LBE3648:
.LBE3647:
.LBE3655:
.LBE3660:
.LBE3665:
.LBE3671:
.LBE3681:
.LBE3689:
.LBE3698:
.LBE3922:
.LBB3923:
.LBB3627:
.LBB3613:
.LBB3583:
.LBB3576:
.LBB3567:
.LBB3563:
.LBB3560:
.LBB3557:
	.loc 1 2456 34 view .LVU4900
	cvtsi2sdl	%eax, %xmm7
.LBE3557:
.LBE3560:
.LBE3563:
.LBE3567:
.LBE3576:
.LBE3583:
.LBE3613:
.LBE3627:
.LBE3923:
.LBB3924:
.LBB3699:
.LBB3690:
.LBB3682:
.LBB3672:
.LBB3666:
.LBB3661:
.LBB3656:
.LBB3652:
.LBB3649:
	.loc 1 2440 55 view .LVU4901
	movslq	%edx, %rcx
	movq	%rcx, %rax
.LBE3649:
.LBE3652:
.LBE3656:
.LBE3661:
.LBE3666:
.LBE3672:
.LBE3682:
.LBE3690:
.LBE3699:
.LBE3924:
.LBB3925:
.LBB3628:
.LBB3614:
.LBB3584:
.LBB3577:
.LBB3568:
.LBB3564:
.LBB3561:
.LBB3558:
	.loc 1 2456 44 view .LVU4902
	mulsd	%xmm2, %xmm7
.LBE3558:
.LBE3561:
.LBE3564:
.LBE3568:
.LBE3577:
.LBE3584:
.LBE3614:
.LBE3628:
.LBE3925:
.LBB3926:
.LBB3700:
.LBB3691:
.LBB3683:
.LBB3673:
.LBB3667:
.LBB3662:
.LBB3657:
.LBB3653:
.LBB3650:
	.loc 1 2440 55 view .LVU4903
	salq	$30, %rax
	addq	%rcx, %rax
	movl	%edx, %ecx
	sarl	$31, %ecx
	sarq	$61, %rax
	subl	%ecx, %eax
	movl	%eax, %ecx
	sall	$31, %ecx
.LBE3650:
.LBE3653:
.LBE3657:
.LBE3662:
.LBE3667:
.LBE3673:
.LBE3683:
.LBE3691:
.LBE3700:
.LBE3926:
.LBB3927:
.LBB3629:
.LBB3615:
.LBB3585:
.LBB3578:
.LBB3569:
.LBB3565:
	.loc 1 2461 39 view .LVU4904
	cvtsd2ss	%xmm7, %xmm7
.LBE3565:
.LBE3569:
.LBB3570:
.LBI3570:
	.loc 1 2367 24 is_stmt 1 view .LVU4905
.LBB3571:
	.loc 1 2369 5 view .LVU4906
.LBE3571:
.LBE3570:
.LBE3578:
.LBE3585:
.LBE3615:
.LBE3629:
.LBE3927:
	.loc 1 32110 9 view .LVU4907
.LBB3928:
.LBI3639:
	.loc 1 2528 24 view .LVU4908
.LBE3928:
.LBE3993:
.LBE4029:
.LBE4314:
.LBE4371:
.LBE4429:
	.loc 1 2530 5 view .LVU4909
	.loc 1 2531 9 view .LVU4910
.LBB4430:
.LBB4372:
.LBB4315:
.LBB4030:
.LBB3994:
.LBB3929:
.LBB3701:
.LBI3640:
	.loc 1 2516 24 view .LVU4911
.LBE3701:
.LBE3929:
.LBE3994:
.LBE4030:
.LBE4315:
.LBE4372:
.LBE4430:
	.loc 1 2518 5 view .LVU4912
.LBB4431:
.LBB4373:
.LBB4316:
.LBB4031:
.LBB3995:
.LBB3930:
.LBB3702:
.LBB3692:
.LBI3641:
	.loc 1 2505 24 view .LVU4913
.LBE3692:
.LBE3702:
.LBE3930:
.LBE3995:
.LBE4031:
.LBE4316:
.LBE4373:
.LBE4431:
	.loc 1 2507 5 view .LVU4914
.LBB4432:
.LBB4374:
.LBB4317:
.LBB4032:
.LBB3996:
.LBB3931:
.LBB3703:
.LBB3693:
.LBB3684:
.LBI3642:
	.loc 1 2464 24 view .LVU4915
.LBE3684:
.LBE3693:
.LBE3703:
.LBE3931:
.LBE3996:
.LBE4032:
.LBE4317:
.LBE4374:
.LBE4432:
	.loc 1 2466 5 view .LVU4916
.LBB4433:
.LBB4375:
.LBB4318:
.LBB4033:
.LBB3997:
.LBB3932:
.LBB3704:
.LBB3694:
.LBB3685:
.LBB3674:
.LBI3643:
	.loc 1 2459 24 view .LVU4917
.LBB3668:
	.loc 1 2461 5 view .LVU4918
.LBB3663:
.LBI3645:
	.loc 1 2454 25 view .LVU4919
.LBB3658:
	.loc 1 2456 5 view .LVU4920
.LBB3654:
.LBI3647:
	.loc 1 2438 27 view .LVU4921
.LBB3651:
	.loc 1 2440 5 view .LVU4922
	subss	%xmm7, %xmm1
	.loc 1 2440 55 is_stmt 0 view .LVU4923
	subl	%eax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	.loc 1 2441 5 is_stmt 1 view .LVU4924
.LBE3651:
.LBE3654:
	.loc 1 2456 34 is_stmt 0 view .LVU4925
	cvtsi2sdl	%eax, %xmm6
	mulss	%xmm8, %xmm1
.LBE3658:
.LBE3663:
.LBE3668:
.LBE3674:
.LBE3685:
.LBE3694:
.LBE3704:
.LBE3932:
.LBB3933:
.LBB3384:
.LBB3375:
.LBB3367:
.LBB3359:
.LBB3353:
.LBB3348:
.LBB3343:
.LBB3335:
.LBB3336:
	.loc 1 2440 29 view .LVU4926
	imull	$48271, %eax, %eax
.LBE3336:
.LBE3335:
.LBE3343:
.LBE3348:
.LBE3353:
.LBE3359:
.LBE3367:
.LBE3375:
.LBE3384:
.LBE3933:
.LBB3934:
.LBB3705:
.LBB3695:
.LBB3686:
.LBB3675:
.LBB3669:
.LBB3664:
.LBB3659:
	.loc 1 2456 44 view .LVU4927
	mulsd	%xmm2, %xmm6
.LBE3659:
.LBE3664:
.LBE3669:
.LBE3675:
.LBE3686:
.LBE3695:
.LBE3705:
.LBE3934:
.LBB3935:
.LBB3385:
.LBB3376:
.LBB3368:
.LBB3360:
.LBB3354:
.LBB3349:
.LBB3344:
.LBB3340:
.LBB3337:
	.loc 1 2440 55 view .LVU4928
	movslq	%eax, %rcx
	movq	%rcx, %rdx
	salq	$30, %rdx
	addq	%rcx, %rdx
	movl	%eax, %ecx
	sarl	$31, %ecx
	sarq	$61, %rdx
	subl	%ecx, %edx
.LBE3337:
.LBE3340:
.LBE3344:
.LBE3349:
.LBE3354:
.LBE3360:
.LBE3368:
.LBE3376:
.LBE3385:
.LBE3935:
.LBB3936:
.LBB3706:
.LBB3696:
.LBB3687:
.LBB3676:
.LBB3670:
	.loc 1 2461 39 view .LVU4929
	cvtsd2ss	%xmm6, %xmm6
.LBE3670:
.LBE3676:
.LBB3677:
.LBI3677:
	.loc 1 2367 24 is_stmt 1 view .LVU4930
.LBB3678:
	.loc 1 2369 5 view .LVU4931
.LBE3678:
.LBE3677:
.LBE3687:
.LBE3696:
.LBE3706:
.LBE3936:
	.loc 1 32111 9 view .LVU4932
.LBB3937:
.LBI3324:
	.loc 1 2528 24 view .LVU4933
.LBE3937:
.LBE3997:
.LBE4033:
.LBE4318:
.LBE4375:
.LBE4433:
	.loc 1 2530 5 view .LVU4934
	.loc 1 2531 9 view .LVU4935
.LBB4434:
.LBB4376:
.LBB4319:
.LBB4034:
.LBB3998:
.LBB3938:
.LBB3386:
.LBI3325:
	.loc 1 2516 24 view .LVU4936
.LBE3386:
.LBE3938:
.LBE3998:
.LBE4034:
.LBE4319:
.LBE4376:
.LBE4434:
	.loc 1 2518 5 view .LVU4937
.LBB4435:
.LBB4377:
.LBB4320:
.LBB4035:
.LBB3999:
.LBB3939:
.LBB3387:
.LBB3377:
.LBI3326:
	.loc 1 2505 24 view .LVU4938
.LBE3377:
.LBE3387:
.LBE3939:
.LBE3999:
.LBE4035:
.LBE4320:
.LBE4377:
.LBE4435:
	.loc 1 2507 5 view .LVU4939
.LBB4436:
.LBB4378:
.LBB4321:
.LBB4036:
.LBB4000:
.LBB3940:
.LBB3388:
.LBB3378:
.LBB3369:
.LBI3327:
	.loc 1 2464 24 view .LVU4940
.LBE3369:
.LBE3378:
.LBE3388:
.LBE3940:
.LBE4000:
.LBE4036:
.LBE4321:
.LBE4378:
.LBE4436:
	.loc 1 2466 5 view .LVU4941
.LBB4437:
.LBB4379:
.LBB4322:
.LBB4037:
.LBB4001:
.LBB3941:
.LBB3389:
.LBB3379:
.LBB3370:
.LBB3361:
.LBI3331:
	.loc 1 2459 24 view .LVU4942
.LBB3355:
	.loc 1 2461 5 view .LVU4943
.LBB3350:
.LBI3333:
	.loc 1 2454 25 view .LVU4944
.LBB3345:
	.loc 1 2456 5 view .LVU4945
.LBB3341:
.LBI3335:
	.loc 1 2438 27 view .LVU4946
.LBB3338:
	.loc 1 2440 5 view .LVU4947
.LBE3338:
.LBE3341:
.LBE3345:
.LBE3350:
.LBE3355:
.LBE3361:
.LBE3370:
.LBE3379:
.LBE3389:
.LBE3941:
.LBB3942:
.LBB3630:
.LBB3616:
.LBB3607:
.LBB3603:
.LBB3600:
.LBB3598:
.LBB3596:
	.loc 1 2369 18 is_stmt 0 view .LVU4948
	mulss	%xmm6, %xmm12
.LBE3596:
.LBE3598:
.LBE3600:
.LBE3603:
.LBE3607:
.LBE3616:
.LBE3630:
.LBE3942:
.LBB3943:
.LBB3390:
.LBB3380:
.LBB3371:
.LBB3362:
.LBB3356:
.LBB3351:
.LBB3346:
.LBB3342:
.LBB3339:
	.loc 1 2440 55 view .LVU4949
	movl	%edx, %ecx
	sall	$31, %ecx
	subl	%edx, %ecx
	subl	%ecx, %eax
	.loc 1 2441 5 is_stmt 1 view .LVU4950
.LBE3339:
.LBE3342:
	.loc 1 2456 34 is_stmt 0 view .LVU4951
	cvtsi2sdl	%eax, %xmm5
.LBE3346:
.LBE3351:
.LBE3356:
.LBE3362:
.LBE3371:
.LBE3380:
.LBE3390:
.LBE3943:
.LBB3944:
.LBB3788:
.LBB3780:
.LBB3773:
.LBB3764:
.LBB3759:
.LBB3755:
.LBB3751:
.LBB3743:
.LBB3744:
	.loc 1 2440 29 view .LVU4952
	imull	$48271, %eax, %eax
	addss	%xmm12, %xmm1
.LBE3744:
.LBE3743:
.LBE3751:
.LBE3755:
.LBE3759:
.LBE3764:
.LBE3773:
.LBE3780:
.LBE3788:
.LBE3944:
.LBB3945:
.LBB3707:
.LBB3708:
.LBB3709:
.LBB3710:
.LBB3711:
.LBB3712:
	.loc 1 2369 18 view .LVU4953
	movaps	%xmm10, %xmm12
.LBE3712:
.LBE3711:
.LBE3710:
.LBE3709:
.LBE3708:
.LBE3707:
.LBE3945:
.LBB3946:
.LBB3391:
.LBB3381:
.LBB3372:
.LBB3363:
.LBB3357:
.LBB3352:
.LBB3347:
	.loc 1 2456 44 view .LVU4954
	mulsd	%xmm2, %xmm5
.LBE3347:
.LBE3352:
.LBE3357:
.LBE3363:
.LBE3372:
.LBE3381:
.LBE3391:
.LBE3946:
.LBB3947:
.LBB3789:
.LBB3781:
.LBB3774:
.LBB3765:
.LBB3760:
.LBB3756:
.LBB3752:
.LBB3748:
.LBB3745:
	.loc 1 2440 55 view .LVU4955
	movslq	%eax, %rcx
	movss	%xmm1, -96(%rbp)
	movaps	%xmm0, %xmm1
	movq	%rcx, %rdx
	salq	$30, %rdx
	addq	%rcx, %rdx
	movl	%eax, %ecx
	sarl	$31, %ecx
	sarq	$61, %rdx
	subl	%ecx, %edx
.LBE3745:
.LBE3748:
.LBE3752:
.LBE3756:
.LBE3760:
.LBE3765:
.LBE3774:
.LBE3781:
.LBE3789:
.LBE3947:
.LBB3948:
.LBB3392:
.LBB3382:
.LBB3373:
.LBB3364:
.LBB3358:
	.loc 1 2461 39 view .LVU4956
	cvtsd2ss	%xmm5, %xmm5
.LBE3358:
.LBE3364:
.LBB3365:
.LBI3328:
	.loc 1 2367 24 is_stmt 1 view .LVU4957
.LBB3330:
	.loc 1 2369 5 view .LVU4958
.LBE3330:
.LBE3365:
.LBE3373:
.LBE3382:
.LBE3392:
.LBE3948:
	.loc 1 32112 9 view .LVU4959
.LBB3949:
.LBI3735:
	.loc 1 2528 24 view .LVU4960
.LBE3949:
.LBE4001:
.LBE4037:
.LBE4322:
.LBE4379:
.LBE4437:
	.loc 1 2530 5 view .LVU4961
	.loc 1 2531 9 view .LVU4962
.LBB4438:
.LBB4380:
.LBB4323:
.LBB4038:
.LBB4002:
.LBB3950:
.LBB3790:
.LBI3736:
	.loc 1 2516 24 view .LVU4963
.LBE3790:
.LBE3950:
.LBE4002:
.LBE4038:
.LBE4323:
.LBE4380:
.LBE4438:
	.loc 1 2518 5 view .LVU4964
.LBB4439:
.LBB4381:
.LBB4324:
.LBB4039:
.LBB4003:
.LBB3951:
.LBB3791:
.LBB3782:
.LBI3737:
	.loc 1 2505 24 view .LVU4965
.LBE3782:
.LBE3791:
.LBE3951:
.LBE4003:
.LBE4039:
.LBE4324:
.LBE4381:
.LBE4439:
	.loc 1 2507 5 view .LVU4966
.LBB4440:
.LBB4382:
.LBB4325:
.LBB4040:
.LBB4004:
.LBB3952:
.LBB3792:
.LBB3783:
.LBB3775:
.LBI3738:
	.loc 1 2464 24 view .LVU4967
.LBE3775:
.LBE3783:
.LBE3792:
.LBE3952:
.LBE4004:
.LBE4040:
.LBE4325:
.LBE4382:
.LBE4440:
	.loc 1 2466 5 view .LVU4968
.LBB4441:
.LBB4383:
.LBB4326:
.LBB4041:
.LBB4005:
.LBB3953:
.LBB3793:
.LBB3784:
.LBB3776:
.LBB3766:
.LBI3739:
	.loc 1 2459 24 view .LVU4969
.LBB3761:
	.loc 1 2461 5 view .LVU4970
.LBB3757:
.LBI3741:
	.loc 1 2454 25 view .LVU4971
.LBB3753:
	.loc 1 2456 5 view .LVU4972
.LBB3749:
.LBI3743:
	.loc 1 2438 27 view .LVU4973
.LBB3746:
	.loc 1 2440 5 view .LVU4974
	subss	%xmm5, %xmm1
	.loc 1 2440 55 is_stmt 0 view .LVU4975
	movl	%edx, %ecx
	sall	$31, %ecx
	mulss	%xmm8, %xmm1
	subl	%edx, %ecx
	subl	%ecx, %eax
.LBE3746:
.LBE3749:
	.loc 1 2456 34 view .LVU4976
	cvtsi2sdl	%eax, %xmm4
.LBB3750:
.LBB3747:
	.loc 1 2440 55 view .LVU4977
	movl	%eax, %edx
	.loc 1 2441 5 is_stmt 1 view .LVU4978
.LBE3747:
.LBE3750:
.LBE3753:
.LBE3757:
.LBE3761:
.LBE3766:
.LBE3776:
.LBE3784:
.LBE3793:
.LBE3953:
.LBB3954:
.LBB3393:
.LBB3394:
.LBB3395:
.LBB3396:
.LBB3397:
.LBB3398:
.LBB3399:
.LBB3400:
.LBB3401:
.LBB3402:
	.loc 1 2440 29 is_stmt 0 view .LVU4979
	imull	$48271, %eax, %eax
.LBE3402:
.LBE3401:
.LBE3400:
.LBE3399:
.LBE3398:
.LBE3397:
.LBE3396:
.LBE3395:
.LBE3394:
.LBE3393:
.LBE3954:
.LBB3955:
.LBB3794:
.LBB3785:
.LBB3777:
.LBB3767:
.LBB3762:
.LBB3758:
.LBB3754:
	.loc 1 2456 44 view .LVU4980
	mulsd	%xmm2, %xmm4
.LBE3754:
.LBE3758:
.LBE3762:
.LBE3767:
.LBE3777:
.LBE3785:
.LBE3794:
.LBE3955:
.LBB3956:
.LBB3533:
.LBB3523:
.LBB3450:
.LBB3441:
.LBB3433:
.LBB3425:
.LBB3418:
.LBB3411:
.LBB3407:
.LBB3403:
	.loc 1 2440 55 view .LVU4981
	movslq	%eax, %r8
	movq	%r8, %rcx
	salq	$30, %rcx
	addq	%r8, %rcx
	movl	%eax, %r8d
	sarl	$31, %r8d
	sarq	$61, %rcx
.LBE3403:
.LBE3407:
.LBE3411:
.LBE3418:
.LBE3425:
.LBE3433:
.LBE3441:
.LBE3450:
.LBE3523:
.LBE3533:
.LBE3956:
.LBB3957:
.LBB3795:
.LBB3786:
.LBB3778:
.LBB3768:
.LBB3763:
	.loc 1 2461 39 view .LVU4982
	cvtsd2ss	%xmm4, %xmm4
.LBE3763:
.LBE3768:
.LBB3769:
.LBI3769:
	.loc 1 2367 24 is_stmt 1 view .LVU4983
.LBB3770:
	.loc 1 2369 5 view .LVU4984
.LBE3770:
.LBE3769:
.LBE3778:
.LBE3786:
.LBE3795:
.LBE3957:
.LBB3958:
.LBB3631:
	.loc 1 2533 5 view .LVU4985
	.loc 1 2534 9 view .LVU4986
.LBB3617:
.LBI3590:
	.loc 1 2521 24 view .LVU4987
.LBB3608:
	.loc 1 2523 5 view .LVU4988
.LBE3608:
.LBE3617:
.LBE3631:
.LBE3958:
.LBE4005:
.LBE4041:
.LBE4326:
.LBE4383:
.LBE4441:
	.loc 1 2507 5 view .LVU4989
	.loc 1 2466 5 view .LVU4990
	.loc 1 2461 5 view .LVU4991
	.loc 1 2456 5 view .LVU4992
	.loc 1 2440 5 view .LVU4993
	.loc 1 2441 5 view .LVU4994
	.loc 1 2369 5 view .LVU4995
.LBB4442:
.LBB4384:
.LBB4327:
.LBB4042:
.LBB4006:
.LBB3959:
.LBB3632:
.LBB3618:
.LBB3609:
	.loc 1 2524 5 view .LVU4996
.LBB3604:
.LBI3592:
	.loc 1 2505 24 view .LVU4997
.LBE3604:
.LBE3609:
.LBE3618:
.LBE3632:
.LBE3959:
.LBE4006:
.LBE4042:
.LBE4327:
.LBE4384:
.LBE4442:
	.loc 1 2507 5 view .LVU4998
.LBB4443:
.LBB4385:
.LBB4328:
.LBB4043:
.LBB4007:
.LBB3960:
.LBB3633:
.LBB3619:
.LBB3610:
.LBB3605:
.LBB3601:
.LBI3593:
	.loc 1 2464 24 view .LVU4999
.LBE3601:
.LBE3605:
.LBE3610:
.LBE3619:
.LBE3633:
.LBE3960:
.LBE4007:
.LBE4043:
.LBE4328:
.LBE4385:
.LBE4443:
	.loc 1 2466 5 view .LVU5000
	.loc 1 2461 5 view .LVU5001
	.loc 1 2456 5 view .LVU5002
	.loc 1 2440 5 view .LVU5003
	.loc 1 2441 5 view .LVU5004
.LBB4444:
.LBB4386:
.LBB4329:
.LBB4044:
.LBB4008:
.LBB3961:
.LBB3634:
.LBB3620:
.LBB3611:
.LBB3606:
.LBB3602:
.LBB3599:
.LBI3594:
	.loc 1 2367 24 view .LVU5005
.LBB3597:
	.loc 1 2369 5 view .LVU5006
.LBE3597:
.LBE3599:
.LBE3602:
.LBE3606:
	.loc 1 2525 5 view .LVU5007
.LBE3611:
.LBE3620:
.LBE3634:
.LBE3961:
	.loc 1 32110 9 view .LVU5008
.LBB3962:
	.loc 1 2528 24 view .LVU5009
.LBE3962:
.LBE4008:
.LBE4044:
.LBE4329:
.LBE4386:
.LBE4444:
	.loc 1 2530 5 view .LVU5010
	.loc 1 2533 5 view .LVU5011
	.loc 1 2534 9 view .LVU5012
.LBB4445:
.LBB4387:
.LBB4330:
.LBB4045:
.LBB4009:
.LBB3963:
.LBB3728:
.LBI3707:
	.loc 1 2521 24 view .LVU5013
.LBB3724:
	.loc 1 2523 5 view .LVU5014
.LBE3724:
.LBE3728:
.LBE3963:
.LBE4009:
.LBE4045:
.LBE4330:
.LBE4387:
.LBE4445:
	.loc 1 2507 5 view .LVU5015
	.loc 1 2466 5 view .LVU5016
	.loc 1 2461 5 view .LVU5017
	.loc 1 2456 5 view .LVU5018
	.loc 1 2440 5 view .LVU5019
	.loc 1 2441 5 view .LVU5020
	.loc 1 2369 5 view .LVU5021
.LBB4446:
.LBB4388:
.LBB4331:
.LBB4046:
.LBB4010:
.LBB3964:
.LBB3729:
.LBB3725:
	.loc 1 2524 5 view .LVU5022
.LBB3720:
.LBI3709:
	.loc 1 2505 24 view .LVU5023
.LBE3720:
.LBE3725:
.LBE3729:
.LBE3964:
.LBE4010:
.LBE4046:
.LBE4331:
.LBE4388:
.LBE4446:
	.loc 1 2507 5 view .LVU5024
.LBB4447:
.LBB4389:
.LBB4332:
.LBB4047:
.LBB4011:
.LBB3965:
.LBB3730:
.LBB3726:
.LBB3721:
.LBB3717:
.LBI3710:
	.loc 1 2464 24 view .LVU5025
.LBE3717:
.LBE3721:
.LBE3726:
.LBE3730:
.LBE3965:
.LBE4011:
.LBE4047:
.LBE4332:
.LBE4389:
.LBE4447:
	.loc 1 2466 5 view .LVU5026
	.loc 1 2461 5 view .LVU5027
	.loc 1 2456 5 view .LVU5028
	.loc 1 2440 5 view .LVU5029
	.loc 1 2441 5 view .LVU5030
.LBB4448:
.LBB4390:
.LBB4333:
.LBB4048:
.LBB4012:
.LBB3966:
.LBB3731:
.LBB3727:
.LBB3722:
.LBB3718:
.LBB3715:
.LBI3711:
	.loc 1 2367 24 view .LVU5031
.LBB3713:
	.loc 1 2369 5 view .LVU5032
.LBE3713:
.LBE3715:
.LBE3718:
.LBE3722:
	.loc 1 2525 5 view .LVU5033
.LBB3723:
.LBB3719:
.LBB3716:
.LBB3714:
	.loc 1 2369 18 is_stmt 0 view .LVU5034
	mulss	%xmm4, %xmm12
.LBE3714:
.LBE3716:
.LBE3719:
.LBE3723:
.LBE3727:
.LBE3731:
.LBE3966:
.LBB3967:
.LBB3534:
.LBB3524:
.LBB3451:
.LBB3442:
.LBB3434:
.LBB3426:
.LBB3419:
.LBB3412:
.LBB3408:
.LBB3404:
	.loc 1 2440 55 view .LVU5035
	subl	%r8d, %ecx
	movl	%ecx, %r8d
	sall	$31, %r8d
	subl	%ecx, %r8d
	subl	%r8d, %eax
.LBE3404:
.LBE3408:
.LBE3412:
.LBE3419:
.LBE3426:
.LBE3434:
.LBE3442:
.LBE3451:
.LBB3452:
.LBB3453:
.LBB3454:
.LBB3455:
.LBB3456:
.LBB3457:
.LBB3458:
.LBB3459:
	.loc 1 2440 29 view .LVU5036
	imull	$48271, %eax, %r8d
	addss	%xmm12, %xmm1
.LBE3459:
.LBE3458:
.LBE3457:
.LBE3456:
.LBE3455:
.LBE3454:
.LBE3453:
.LBE3452:
.LBB3506:
.LBB3443:
.LBB3435:
.LBB3427:
.LBB3420:
.LBB3413:
.LBB3409:
.LBB3405:
	.loc 1 2440 55 view .LVU5037
	movl	%eax, %ecx
	movaps	%xmm0, %xmm12
	movss	%xmm1, -100(%rbp)
.LBE3405:
.LBE3409:
.LBE3413:
.LBE3420:
.LBE3427:
.LBE3435:
.LBE3443:
.LBE3506:
.LBE3524:
.LBE3534:
.LBE3967:
	.loc 1 32111 9 is_stmt 1 view .LVU5038
.LBB3968:
	.loc 1 2528 24 view .LVU5039
.LBE3968:
.LBE4012:
.LBE4048:
.LBE4333:
.LBE4390:
.LBE4448:
	.loc 1 2530 5 view .LVU5040
	.loc 1 2533 5 view .LVU5041
	.loc 1 2534 9 view .LVU5042
.LBB4449:
.LBB4391:
.LBB4334:
.LBB4049:
.LBB4013:
.LBB3969:
.LBB3535:
.LBI3393:
	.loc 1 2521 24 view .LVU5043
.LBB3525:
	.loc 1 2523 5 view .LVU5044
.LBB3507:
.LBI3395:
	.loc 1 2505 24 view .LVU5045
.LBE3507:
.LBE3525:
.LBE3535:
.LBE3969:
.LBE4013:
.LBE4049:
.LBE4334:
.LBE4391:
.LBE4449:
	.loc 1 2507 5 view .LVU5046
.LBB4450:
.LBB4392:
.LBB4335:
.LBB4050:
.LBB4014:
.LBB3970:
.LBB3536:
.LBB3526:
.LBB3508:
.LBB3444:
.LBI3396:
	.loc 1 2464 24 view .LVU5047
.LBE3444:
.LBE3508:
.LBE3526:
.LBE3536:
.LBE3970:
.LBE4014:
.LBE4050:
.LBE4335:
.LBE4392:
.LBE4450:
	.loc 1 2466 5 view .LVU5048
.LBB4451:
.LBB4393:
.LBB4336:
.LBB4051:
.LBB4015:
.LBB3971:
.LBB3537:
.LBB3527:
.LBB3509:
.LBB3445:
.LBB3436:
.LBI3397:
	.loc 1 2459 24 view .LVU5049
.LBB3428:
	.loc 1 2461 5 view .LVU5050
.LBB3421:
.LBI3399:
	.loc 1 2454 25 view .LVU5051
.LBB3414:
	.loc 1 2456 5 view .LVU5052
.LBB3410:
.LBI3401:
	.loc 1 2438 27 view .LVU5053
.LBB3406:
	.loc 1 2440 5 view .LVU5054
	.loc 1 2441 5 view .LVU5055
.LBE3406:
.LBE3410:
.LBE3414:
.LBE3421:
.LBE3428:
.LBE3436:
.LBE3445:
.LBE3509:
.LBE3527:
.LBE3537:
.LBE3971:
.LBE4015:
.LBE4051:
.LBE4336:
.LBE4393:
.LBE4451:
	.loc 1 2369 5 view .LVU5056
.LBB4452:
.LBB4394:
.LBB4337:
.LBB4052:
.LBB4016:
.LBB3972:
.LBB3538:
.LBB3528:
	.loc 1 2524 5 view .LVU5057
.LBB3510:
.LBI3452:
	.loc 1 2505 24 view .LVU5058
.LBE3510:
.LBE3528:
.LBE3538:
.LBE3972:
.LBE4016:
.LBE4052:
.LBE4337:
.LBE4394:
.LBE4452:
	.loc 1 2507 5 view .LVU5059
.LBB4453:
.LBB4395:
.LBB4338:
.LBB4053:
.LBB4017:
.LBB3973:
.LBB3539:
.LBB3529:
.LBB3511:
.LBB3498:
.LBI3453:
	.loc 1 2464 24 view .LVU5060
.LBE3498:
.LBE3511:
.LBE3529:
.LBE3539:
.LBE3973:
.LBE4017:
.LBE4053:
.LBE4338:
.LBE4395:
.LBE4453:
	.loc 1 2466 5 view .LVU5061
.LBB4454:
.LBB4396:
.LBB4339:
.LBB4054:
.LBB4018:
.LBB3974:
.LBB3540:
.LBB3530:
.LBB3512:
.LBB3499:
.LBB3487:
.LBI3454:
	.loc 1 2459 24 view .LVU5062
.LBB3480:
	.loc 1 2461 5 view .LVU5063
.LBB3474:
.LBI3456:
	.loc 1 2454 25 view .LVU5064
.LBB3468:
	.loc 1 2456 5 view .LVU5065
.LBB3464:
.LBI3458:
	.loc 1 2438 27 view .LVU5066
.LBB3460:
	.loc 1 2440 5 view .LVU5067
.LBE3460:
.LBE3464:
.LBE3468:
.LBE3474:
.LBE3480:
.LBE3487:
.LBE3499:
.LBE3512:
.LBB3513:
.LBB3446:
.LBB3437:
.LBB3429:
.LBB3422:
.LBB3415:
	.loc 1 2456 34 is_stmt 0 view .LVU5068
	pxor	%xmm1, %xmm1
.LBE3415:
.LBE3422:
.LBE3429:
.LBE3437:
.LBE3446:
.LBE3513:
.LBB3514:
.LBB3500:
.LBB3488:
.LBB3481:
.LBB3475:
.LBB3469:
.LBB3465:
.LBB3461:
	.loc 1 2440 55 view .LVU5069
	movslq	%r8d, %r12
.LBE3461:
.LBE3465:
.LBE3469:
.LBE3475:
.LBE3481:
.LBE3488:
.LBE3500:
.LBE3514:
.LBB3515:
.LBB3447:
.LBB3438:
.LBB3430:
.LBB3423:
.LBB3416:
	.loc 1 2456 34 view .LVU5070
	cvtsi2sdl	%ecx, %xmm1
.LBE3416:
.LBE3423:
.LBE3430:
.LBE3438:
.LBE3447:
.LBE3515:
.LBB3516:
.LBB3501:
.LBB3489:
.LBB3482:
.LBB3476:
.LBB3470:
.LBB3466:
.LBB3462:
	.loc 1 2440 55 view .LVU5071
	movq	%r12, %rax
	salq	$30, %rax
	addq	%r12, %rax
	movl	%r8d, %r12d
	sarl	$31, %r12d
	sarq	$61, %rax
.LBE3462:
.LBE3466:
.LBE3470:
.LBE3476:
.LBE3482:
.LBE3489:
.LBE3501:
.LBE3516:
.LBB3517:
.LBB3448:
.LBB3439:
.LBB3431:
.LBB3424:
.LBB3417:
	.loc 1 2456 44 view .LVU5072
	mulsd	%xmm2, %xmm1
.LBE3417:
.LBE3424:
.LBE3431:
.LBE3439:
.LBE3448:
.LBE3517:
.LBB3518:
.LBB3502:
.LBB3490:
.LBB3483:
.LBB3477:
.LBB3471:
.LBB3467:
.LBB3463:
	.loc 1 2440 55 view .LVU5073
	subl	%r12d, %eax
	movl	%eax, %r12d
	sall	$31, %r12d
	subl	%eax, %r12d
	movl	%r8d, %eax
	subl	%r12d, %eax
	.loc 1 2441 5 is_stmt 1 view .LVU5074
.LBE3463:
.LBE3467:
.LBE3471:
.LBE3477:
.LBE3483:
.LBE3490:
.LBB3491:
.LBI3491:
	.loc 1 2367 24 view .LVU5075
.LBB3492:
	.loc 1 2369 5 view .LVU5076
.LBE3492:
.LBE3491:
.LBE3502:
.LBE3518:
	.loc 1 2525 5 view .LVU5077
.LBB3519:
.LBB3449:
.LBB3440:
.LBB3432:
	.loc 1 2461 39 is_stmt 0 view .LVU5078
	cvtsd2ss	%xmm1, %xmm1
	subss	%xmm1, %xmm12
.LBE3432:
.LBE3440:
.LBE3449:
.LBE3519:
.LBB3520:
.LBB3503:
.LBB3494:
.LBB3484:
.LBB3478:
.LBB3472:
	.loc 1 2456 34 view .LVU5079
	pxor	%xmm1, %xmm1
	cvtsi2sdl	%eax, %xmm1
.LBE3472:
.LBE3478:
.LBE3484:
.LBE3494:
.LBE3503:
.LBE3520:
.LBE3530:
.LBE3540:
.LBE3974:
.LBB3975:
.LBB3796:
.LBB3797:
.LBB3798:
.LBB3799:
.LBB3800:
.LBB3801:
.LBB3802:
.LBB3803:
.LBB3804:
.LBB3805:
	.loc 1 2440 29 view .LVU5080
	imull	$48271, %eax, %eax
	mulss	%xmm8, %xmm12
.LBE3805:
.LBE3804:
.LBE3803:
.LBE3802:
.LBE3801:
.LBE3800:
.LBE3799:
.LBE3798:
.LBE3797:
.LBE3796:
.LBE3975:
.LBB3976:
.LBB3541:
.LBB3531:
.LBB3521:
.LBB3504:
.LBB3495:
.LBB3485:
.LBB3479:
.LBB3473:
	.loc 1 2456 44 view .LVU5081
	mulsd	%xmm2, %xmm1
.LBE3473:
.LBE3479:
.LBE3485:
.LBE3495:
.LBE3504:
.LBE3521:
.LBE3531:
.LBE3541:
.LBE3976:
.LBB3977:
.LBB3912:
.LBB3904:
.LBB3843:
.LBB3836:
.LBB3830:
.LBB3824:
.LBB3819:
.LBB3814:
.LBB3810:
.LBB3806:
	.loc 1 2440 55 view .LVU5082
	movslq	%eax, %r12
	movq	%r12, %rcx
	salq	$30, %rcx
	addq	%r12, %rcx
	movl	%eax, %r12d
	sarl	$31, %r12d
	sarq	$61, %rcx
	subl	%r12d, %ecx
.LBE3806:
.LBE3810:
.LBE3814:
.LBE3819:
.LBE3824:
.LBE3830:
.LBE3836:
.LBE3843:
.LBE3904:
.LBE3912:
.LBE3977:
.LBB3978:
.LBB3542:
.LBB3532:
.LBB3522:
.LBB3505:
.LBB3496:
.LBB3486:
	.loc 1 2461 39 view .LVU5083
	cvtsd2ss	%xmm1, %xmm1
.LBE3486:
.LBE3496:
.LBB3497:
.LBB3493:
	.loc 1 2369 18 view .LVU5084
	mulss	%xmm10, %xmm1
.LBE3493:
.LBE3497:
.LBE3505:
.LBE3522:
.LBE3532:
.LBE3542:
.LBE3978:
.LBB3979:
.LBB3913:
.LBB3905:
.LBB3844:
.LBB3837:
.LBB3831:
.LBB3825:
.LBB3820:
.LBB3815:
.LBB3811:
.LBB3807:
	.loc 1 2440 55 view .LVU5085
	movl	%ecx, %r12d
	sall	$31, %r12d
	subl	%ecx, %r12d
	subl	%r12d, %eax
.LBE3807:
.LBE3811:
.LBE3815:
.LBE3820:
.LBE3825:
.LBE3831:
.LBE3837:
.LBE3844:
.LBB3845:
.LBB3846:
.LBB3847:
.LBB3848:
.LBB3849:
.LBB3850:
.LBB3851:
.LBB3852:
	.loc 1 2440 29 view .LVU5086
	imull	$48271, %eax, %r12d
.LBE3852:
.LBE3851:
.LBE3850:
.LBE3849:
.LBE3848:
.LBE3847:
.LBE3846:
.LBE3845:
.LBB3891:
.LBB3838:
.LBB3832:
.LBB3826:
.LBB3821:
.LBB3816:
.LBB3812:
.LBB3808:
	.loc 1 2440 55 view .LVU5087
	movl	%eax, %ecx
	addss	%xmm1, %xmm12
.LBE3808:
.LBE3812:
	.loc 1 2456 34 view .LVU5088
	pxor	%xmm1, %xmm1
	cvtsi2sdl	%ecx, %xmm1
.LBE3816:
.LBE3821:
.LBE3826:
.LBE3832:
.LBE3838:
.LBE3891:
.LBB3892:
.LBB3885:
.LBB3876:
.LBB3871:
.LBB3866:
.LBB3861:
.LBB3857:
.LBB3853:
	.loc 1 2440 55 view .LVU5089
	movslq	%r12d, %r14
	movq	%r14, %rax
	movd	%xmm12, %r8d
.LBE3853:
.LBE3857:
.LBE3861:
.LBE3866:
.LBE3871:
.LBE3876:
.LBE3885:
.LBE3892:
.LBE3905:
.LBE3913:
.LBE3979:
	.loc 1 32112 9 is_stmt 1 view .LVU5090
.LBB3980:
	.loc 1 2528 24 view .LVU5091
.LBE3980:
.LBE4018:
.LBE4054:
.LBE4339:
.LBE4396:
.LBE4454:
	.loc 1 2530 5 view .LVU5092
	.loc 1 2533 5 view .LVU5093
	.loc 1 2534 9 view .LVU5094
.LBB4455:
.LBB4397:
.LBB4340:
.LBB4055:
.LBB4019:
.LBB3981:
.LBB3914:
.LBI3796:
	.loc 1 2521 24 view .LVU5095
.LBB3906:
	.loc 1 2523 5 view .LVU5096
.LBB3893:
.LBI3798:
	.loc 1 2505 24 view .LVU5097
.LBE3893:
.LBE3906:
.LBE3914:
.LBE3981:
.LBE4019:
.LBE4055:
.LBE4340:
.LBE4397:
.LBE4455:
	.loc 1 2507 5 view .LVU5098
.LBB4456:
.LBB4398:
.LBB4341:
.LBB4056:
.LBB4020:
.LBB3982:
.LBB3915:
.LBB3907:
.LBB3894:
.LBB3839:
.LBI3799:
	.loc 1 2464 24 view .LVU5099
.LBE3839:
.LBE3894:
.LBE3907:
.LBE3915:
.LBE3982:
.LBE4020:
.LBE4056:
.LBE4341:
.LBE4398:
.LBE4456:
	.loc 1 2466 5 view .LVU5100
.LBB4457:
.LBB4399:
.LBB4342:
.LBB4057:
.LBB4021:
.LBB3983:
.LBB3916:
.LBB3908:
.LBB3895:
.LBB3840:
.LBB3833:
.LBI3800:
	.loc 1 2459 24 view .LVU5101
.LBB3827:
	.loc 1 2461 5 view .LVU5102
.LBB3822:
.LBI3802:
	.loc 1 2454 25 view .LVU5103
.LBB3817:
	.loc 1 2456 5 view .LVU5104
.LBB3813:
.LBI3804:
	.loc 1 2438 27 view .LVU5105
.LBB3809:
	.loc 1 2440 5 view .LVU5106
	.loc 1 2441 5 view .LVU5107
.LBE3809:
.LBE3813:
.LBE3817:
.LBE3822:
.LBE3827:
.LBE3833:
.LBE3840:
.LBE3895:
.LBE3908:
.LBE3916:
.LBE3983:
.LBE4021:
.LBE4057:
.LBE4342:
.LBE4399:
.LBE4457:
	.loc 1 2369 5 view .LVU5108
.LBB4458:
.LBB4400:
.LBB4343:
.LBB4058:
.LBB4022:
.LBB3984:
.LBB3917:
.LBB3909:
	.loc 1 2524 5 view .LVU5109
.LBB3896:
.LBI3845:
	.loc 1 2505 24 view .LVU5110
.LBE3896:
.LBE3909:
.LBE3917:
.LBE3984:
.LBE4022:
.LBE4058:
.LBE4343:
.LBE4400:
.LBE4458:
	.loc 1 2507 5 view .LVU5111
.LBB4459:
.LBB4401:
.LBB4344:
.LBB4059:
.LBB4023:
.LBB3985:
.LBB3918:
.LBB3910:
.LBB3897:
.LBB3886:
.LBI3846:
	.loc 1 2464 24 view .LVU5112
.LBE3886:
.LBE3897:
.LBE3910:
.LBE3918:
.LBE3985:
.LBE4023:
.LBE4059:
.LBE4344:
.LBE4401:
.LBE4459:
	.loc 1 2466 5 view .LVU5113
.LBB4460:
.LBB4402:
.LBB4345:
.LBB4060:
.LBB4024:
.LBB3986:
.LBB3919:
.LBB3911:
.LBB3898:
.LBB3887:
.LBB3877:
.LBI3847:
	.loc 1 2459 24 view .LVU5114
.LBB3872:
	.loc 1 2461 5 view .LVU5115
.LBB3867:
.LBI3849:
	.loc 1 2454 25 view .LVU5116
.LBB3862:
	.loc 1 2456 5 view .LVU5117
.LBB3858:
.LBI3851:
	.loc 1 2438 27 view .LVU5118
.LBB3854:
	.loc 1 2440 5 view .LVU5119
	movaps	%xmm0, %xmm12
	.loc 1 2440 55 is_stmt 0 view .LVU5120
	salq	$30, %rax
.LBE3854:
.LBE3858:
.LBE3862:
.LBE3867:
.LBE3872:
.LBE3877:
.LBE3887:
.LBE3898:
.LBB3899:
.LBB3841:
.LBB3834:
.LBB3828:
.LBB3823:
.LBB3818:
	.loc 1 2456 44 view .LVU5121
	mulsd	%xmm2, %xmm1
.LBE3818:
.LBE3823:
.LBE3828:
.LBE3834:
.LBE3841:
.LBE3899:
.LBB3900:
.LBB3888:
.LBB3878:
.LBB3873:
.LBB3868:
.LBB3863:
.LBB3859:
.LBB3855:
	.loc 1 2440 55 view .LVU5122
	addq	%r14, %rax
	movl	%r12d, %r14d
	sarl	$31, %r14d
	sarq	$61, %rax
	subl	%r14d, %eax
	movl	%eax, %r14d
	sall	$31, %r14d
	subl	%eax, %r14d
	movl	%r12d, %eax
.LBE3855:
.LBE3859:
.LBE3863:
.LBE3868:
.LBE3873:
.LBE3878:
.LBE3888:
.LBE3900:
.LBB3901:
.LBB3842:
.LBB3835:
.LBB3829:
	.loc 1 2461 39 view .LVU5123
	cvtsd2ss	%xmm1, %xmm1
	subss	%xmm1, %xmm12
.LBE3829:
.LBE3835:
.LBE3842:
.LBE3901:
.LBB3902:
.LBB3889:
.LBB3879:
.LBB3874:
.LBB3869:
.LBB3864:
.LBB3860:
.LBB3856:
	.loc 1 2440 55 view .LVU5124
	subl	%r14d, %eax
	.loc 1 2441 5 is_stmt 1 view .LVU5125
.LBE3856:
.LBE3860:
.LBE3864:
.LBE3869:
.LBE3874:
.LBE3879:
.LBB3880:
.LBI3880:
	.loc 1 2367 24 view .LVU5126
.LBB3881:
	.loc 1 2369 5 view .LVU5127
.LBE3881:
.LBE3880:
.LBE3889:
.LBE3902:
	.loc 1 2525 5 view .LVU5128
.LBB3903:
.LBB3890:
.LBB3883:
.LBB3875:
.LBB3870:
.LBB3865:
	.loc 1 2456 34 is_stmt 0 view .LVU5129
	pxor	%xmm1, %xmm1
	cvtsi2sdl	%eax, %xmm1
	mulss	%xmm8, %xmm12
	.loc 1 2456 44 view .LVU5130
	mulsd	%xmm2, %xmm1
.LBE3865:
.LBE3870:
	.loc 1 2461 39 view .LVU5131
	cvtsd2ss	%xmm1, %xmm1
.LBE3875:
.LBE3883:
.LBB3884:
.LBB3882:
	.loc 1 2369 18 view .LVU5132
	mulss	%xmm10, %xmm1
	addss	%xmm1, %xmm12
	movd	%xmm12, %ecx
	cmpl	$2, %r9d
	je	.L1221
	cmpl	$1, %r9d
	cmove	%edx, %eax
.L1221:
	cmpl	$1, %r15d
.LBE3882:
.LBE3884:
.LBE3890:
.LBE3903:
.LBE3911:
.LBE3919:
.LBE3986:
	.loc 1 32114 15 view .LVU5133
	movss	(%rbx,%rsi,4), %xmm1
	.loc 1 32115 15 view .LVU5134
	movss	4(%rbx,%rsi,4), %xmm15
	.loc 1 32119 12 view .LVU5135
	movaps	%xmm11, %xmm12
	cmovbe	%eax, %r11d
	movl	$1, %eax
	.loc 1 32116 15 view .LVU5136
	movss	8(%rbx,%rsi,4), %xmm14
	.loc 1 32117 15 view .LVU5137
	movss	12(%rbx,%rsi,4), %xmm13
	cmovbe	%eax, %r13d
	.loc 1 32114 9 is_stmt 1 view .LVU5138
.LVL1303:
	.loc 1 32115 9 view .LVU5139
	.loc 1 32116 9 view .LVU5140
	.loc 1 32117 9 view .LVU5141
	.loc 1 32119 9 view .LVU5142
	.loc 1 32120 9 view .LVU5143
	.loc 1 32121 9 view .LVU5144
	.loc 1 32122 9 view .LVU5145
	.loc 1 32124 9 view .LVU5146
	.loc 1 32119 12 is_stmt 0 view .LVU5147
	ja	.L1229
	movss	-96(%rbp), %xmm12
	cmpl	$2, %r9d
	je	.L1229
	cmpl	$1, %r9d
	jne	.L1229
.LBB3987:
.LBB3635:
.LBB3621:
.LBB3586:
.LBB3579:
.LBB3573:
.LBB3572:
	.loc 1 2369 18 view .LVU5148
	mulss	-104(%rbp), %xmm7
	.loc 1 2369 18 view .LVU5149
	movaps	%xmm7, %xmm12
	.loc 1 2369 25 view .LVU5150
	addss	%xmm8, %xmm12
	.p2align 4,,10
	.p2align 3
.L1229:
	.loc 1 2369 25 view .LVU5151
.LBE3572:
.LBE3573:
.LBE3579:
.LBE3586:
.LBE3621:
.LBE3635:
.LBE3987:
	.loc 1 32119 12 view .LVU5152
	addss	%xmm12, %xmm1
	.loc 1 32120 12 view .LVU5153
	movaps	%xmm11, %xmm7
	.loc 1 32124 25 view .LVU5154
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL1304:
	.loc 1 32125 9 is_stmt 1 view .LVU5155
	.loc 1 32120 12 is_stmt 0 view .LVU5156
	cmpl	$1, %r15d
	ja	.L1241
	cmpl	$2, %r9d
	je	.L1459
	cmpl	$1, %r9d
	jne	.L1459
.LBB3988:
.LBB3732:
.LBB3697:
.LBB3688:
.LBB3680:
.LBB3679:
	.loc 1 2369 18 view .LVU5157
	movss	-104(%rbp), %xmm7
	mulss	%xmm6, %xmm7
	.loc 1 2369 25 view .LVU5158
	addss	%xmm8, %xmm7
	jmp	.L1241
.LVL1305:
	.p2align 4,,10
	.p2align 3
.L1060:
	.loc 1 2369 25 view .LVU5159
.LBE3679:
.LBE3680:
.LBE3688:
.LBE3697:
.LBE3732:
.LBE3988:
.LBE4024:
.LBE4060:
.LBE4345:
.LBE4402:
.LBE4460:
	.loc 1 32731 9 is_stmt 1 view .LVU5160
	.loc 1 32732 9 view .LVU5161
	.loc 1 32733 13 view .LVU5162
	cmpl	$4, %esi
	je	.L1061
	ja	.L1062
	cmpl	$2, %esi
	je	.L1063
	cmpl	$3, %esi
	jne	.L1050
.LVL1306:
.LBB4461:
.LBB4462:
.LBB4463:
.LBB4464:
.LBB4465:
	.loc 1 30629 19 view .LVU5163
	testq	%r8, %r8
	je	.L1050
	leaq	(%r8,%r8,2), %rdx
.LVL1307:
	.loc 1 30629 19 is_stmt 0 view .LVU5164
	addq	%rdi, %rdx
.LVL1308:
	.p2align 4,,10
	.p2align 3
.L1071:
.LBB4466:
	.loc 1 30630 9 is_stmt 1 view .LVU5165
	.loc 1 30630 30 is_stmt 0 view .LVU5166
	movzbl	(%rbx), %eax
.LVL1309:
	.loc 1 30631 9 is_stmt 1 view .LVU5167
	.loc 1 30633 9 view .LVU5168
.LBE4466:
	.loc 1 30629 19 is_stmt 0 view .LVU5169
	addq	$3, %rdi
.LBB4467:
	.loc 1 30633 24 view .LVU5170
	movb	$0, -3(%rdi)
	.loc 1 30634 9 is_stmt 1 view .LVU5171
.LBE4467:
	.loc 1 30629 19 is_stmt 0 view .LVU5172
	addq	$1, %rbx
.LVL1310:
.LBB4468:
	.loc 1 30634 24 view .LVU5173
	movb	$0, -2(%rdi)
	.loc 1 30635 9 is_stmt 1 view .LVU5174
	.loc 1 30635 26 is_stmt 0 view .LVU5175
	addl	$-128, %eax
.LVL1311:
	.loc 1 30635 26 view .LVU5176
	movb	%al, -1(%rdi)
.LBE4468:
	.loc 1 30629 5 is_stmt 1 view .LVU5177
.LVL1312:
	.loc 1 30629 19 view .LVU5178
	cmpq	%rdi, %rdx
	jne	.L1071
	jmp	.L1050
.LVL1313:
	.p2align 4,,10
	.p2align 3
.L1059:
	.loc 1 30629 19 is_stmt 0 view .LVU5179
.LBE4465:
.LBE4464:
.LBE4463:
.LBE4462:
.LBE4461:
	.loc 1 32743 9 is_stmt 1 view .LVU5180
	.loc 1 32744 9 view .LVU5181
	.loc 1 32745 13 view .LVU5182
	cmpl	$4, %esi
	je	.L1082
	ja	.L1083
	cmpl	$1, %esi
	je	.L1084
	cmpl	$3, %esi
	jne	.L1050
.LVL1314:
.LBB4469:
.LBB4470:
.LBB4471:
.LBB4472:
	.loc 1 30996 19 view .LVU5183
	testq	%r8, %r8
	je	.L1050
	leaq	(%r8,%r8,2), %rdx
.LVL1315:
	.loc 1 30996 19 is_stmt 0 view .LVU5184
	addq	%rdi, %rdx
.LVL1316:
	.p2align 4,,10
	.p2align 3
.L1106:
	.loc 1 30997 9 is_stmt 1 view .LVU5185
	.loc 1 30997 24 is_stmt 0 view .LVU5186
	movb	$0, (%rdi)
	.loc 1 30998 9 is_stmt 1 view .LVU5187
	.loc 1 30998 24 is_stmt 0 view .LVU5188
	movzwl	(%rbx), %eax
	.loc 1 30996 19 view .LVU5189
	addq	$3, %rdi
	addq	$2, %rbx
	.loc 1 30998 24 view .LVU5190
	movb	%al, -2(%rdi)
	.loc 1 30999 9 is_stmt 1 view .LVU5191
	.loc 1 30999 48 is_stmt 0 view .LVU5192
	movzwl	-2(%rbx), %eax
	sarw	$8, %ax
	.loc 1 30999 24 view .LVU5193
	movb	%al, -1(%rdi)
	.loc 1 30996 5 is_stmt 1 view .LVU5194
	.loc 1 30996 19 view .LVU5195
	cmpq	%rdi, %rdx
	jne	.L1106
	jmp	.L1050
.LVL1317:
	.p2align 4,,10
	.p2align 3
.L1058:
	.loc 1 30996 19 is_stmt 0 view .LVU5196
.LBE4472:
.LBE4471:
.LBE4470:
.LBE4469:
	.loc 1 32755 9 is_stmt 1 view .LVU5197
	.loc 1 32756 9 view .LVU5198
	.loc 1 32757 13 view .LVU5199
	cmpl	$4, %esi
	je	.L1115
	ja	.L1116
	cmpl	$1, %esi
	je	.L1117
	cmpl	$2, %esi
	jne	.L1050
	.loc 1 32760 17 view .LVU5200
	.loc 1 32760 37 view .LVU5201
.LVL1318:
.LBB4473:
.LBI4473:
	.loc 1 31383 13 view .LVU5202
.LBE4473:
	.loc 1 31401 9 view .LVU5203
	.loc 1 31402 13 view .LVU5204
.LBB4647:
.LBB4474:
.LBI4474:
	.loc 1 31359 23 view .LVU5205
.LBE4474:
.LBE4647:
	.loc 1 31361 5 view .LVU5206
.LBB4648:
.LBB4485:
.LBB4475:
.LBI4475:
	.loc 1 31328 23 view .LVU5207
.LBB4476:
	.loc 1 31330 5 view .LVU5208
	.loc 1 31331 5 view .LVU5209
	.loc 1 31333 5 view .LVU5210
.LBB4477:
	testl	%r9d, %r9d
	je	.L1464
.LVL1319:
	.loc 1 31333 5 is_stmt 0 view .LVU5211
.LBE4477:
.LBE4476:
.LBE4475:
.LBE4485:
.LBB4486:
.LBB4487:
.LBB4488:
.LBB4489:
.LBB4490:
.LBB4491:
	.loc 1 31342 23 is_stmt 1 view .LVU5212
	testq	%r8, %r8
	je	.L1050
	movl	_ZL7g_maLCG(%rip), %ecx
	cmpl	$1, %r9d
	je	.L1144
	cmpl	$2, %r9d
	je	.L1145
	leaq	(%r8,%r8,2), %rcx
	addq	%rdx, %rcx
.LVL1320:
	.p2align 4,,10
	.p2align 3
.L1146:
.LBB4492:
	.loc 1 31343 13 view .LVU5213
	.loc 1 31346 13 view .LVU5214
.LBB4493:
.LBI4493:
	.loc 1 2540 27 view .LVU5215
.LBE4493:
.LBE4492:
.LBE4491:
.LBE4490:
.LBE4489:
.LBE4488:
.LBE4487:
.LBE4486:
.LBE4648:
	.loc 1 2542 5 view .LVU5216
	.loc 1 2546 5 view .LVU5217
.LBB4649:
.LBB4638:
.LBB4630:
.LBB4622:
.LBB4614:
.LBB4606:
.LBB4598:
.LBB4583:
	.loc 1 31348 17 view .LVU5218
	.loc 1 31353 13 view .LVU5219
	.loc 1 31354 13 view .LVU5220
	.loc 1 31343 75 is_stmt 0 view .LVU5221
	movzbl	1(%rbx), %eax
	.loc 1 31343 38 view .LVU5222
	movzbl	(%rbx), %edx
.LBE4583:
	.loc 1 31342 23 view .LVU5223
	addq	$3, %rbx
	addq	$2, %rdi
.LBB4584:
	.loc 1 31343 66 view .LVU5224
	sall	$8, %edx
	.loc 1 31343 103 view .LVU5225
	sall	$16, %eax
	.loc 1 31343 110 view .LVU5226
	orl	%edx, %eax
	.loc 1 31343 113 view .LVU5227
	movzbl	-1(%rbx), %edx
	.loc 1 31343 142 view .LVU5228
	sall	$24, %edx
	.loc 1 31343 110 view .LVU5229
	orl	%edx, %eax
	.loc 1 31353 15 view .LVU5230
	sarl	$16, %eax
	.loc 1 31354 24 view .LVU5231
	movw	%ax, -2(%rdi)
.LBE4584:
	.loc 1 31342 9 is_stmt 1 view .LVU5232
	.loc 1 31342 23 view .LVU5233
	cmpq	%rcx, %rbx
	jne	.L1146
	jmp	.L1050
.LVL1321:
	.p2align 4,,10
	.p2align 3
.L1057:
	.loc 1 31342 23 is_stmt 0 view .LVU5234
.LBE4598:
.LBE4606:
.LBE4614:
.LBE4622:
.LBE4630:
.LBE4638:
.LBE4649:
	.loc 1 32767 9 is_stmt 1 view .LVU5235
	.loc 1 32768 9 view .LVU5236
	.loc 1 32769 13 view .LVU5237
	cmpl	$3, %esi
	je	.L1158
	ja	.L1159
	cmpl	$1, %esi
	je	.L1160
	cmpl	$2, %esi
	jne	.L1050
	.loc 1 32772 17 view .LVU5238
	.loc 1 32772 37 view .LVU5239
.LVL1322:
.LBB4650:
.LBI4650:
	.loc 1 31753 13 view .LVU5240
.LBE4650:
	.loc 1 31771 9 view .LVU5241
	.loc 1 31772 13 view .LVU5242
.LBB4898:
.LBB4651:
.LBI4651:
	.loc 1 31729 23 view .LVU5243
.LBE4651:
.LBE4898:
	.loc 1 31731 5 view .LVU5244
.LBB4899:
.LBB4674:
.LBB4652:
.LBI4652:
	.loc 1 31698 23 view .LVU5245
.LBB4653:
	.loc 1 31700 5 view .LVU5246
	.loc 1 31701 5 view .LVU5247
	.loc 1 31703 5 view .LVU5248
.LBB4654:
	testl	%r9d, %r9d
	je	.L1465
.LVL1323:
	.loc 1 31703 5 is_stmt 0 view .LVU5249
.LBE4654:
.LBE4653:
.LBE4652:
.LBE4674:
.LBB4675:
.LBB4676:
.LBB4677:
.LBB4678:
.LBB4679:
.LBB4680:
	.loc 1 31712 23 is_stmt 1 view .LVU5250
	testq	%r8, %r8
	je	.L1050
	movl	_ZL7g_maLCG(%rip), %eax
	cmpl	$1, %r9d
	je	.L1302
	cmpl	$2, %r9d
	je	.L1303
	leaq	-1(%r8), %rax
	cmpq	$6, %rax
	jbe	.L1304
	movq	%r8, %rdx
.LVL1324:
	.loc 1 31712 23 is_stmt 0 view .LVU5251
	xorl	%eax, %eax
	shrq	$3, %rdx
	salq	$4, %rdx
.LVL1325:
	.p2align 4,,10
	.p2align 3
.L1190:
.LBB4681:
	.loc 1 31713 13 is_stmt 1 view .LVU5252
	.loc 1 31716 13 view .LVU5253
.LBB4682:
.LBI4682:
	.loc 1 2540 27 view .LVU5254
.LBE4682:
.LBE4681:
.LBE4680:
.LBE4679:
.LBE4678:
.LBE4677:
.LBE4676:
.LBE4675:
.LBE4899:
	.loc 1 2542 5 view .LVU5255
	.loc 1 2546 5 view .LVU5256
.LBB4900:
.LBB4880:
.LBB4864:
.LBB4848:
.LBB4832:
.LBB4816:
.LBB4800:
.LBB4775:
	.loc 1 31718 17 view .LVU5257
	.loc 1 31723 13 view .LVU5258
	.loc 1 31724 13 view .LVU5259
	.loc 1 31723 15 is_stmt 0 view .LVU5260
	movdqu	(%rbx,%rax,2), %xmm0
	movdqu	16(%rbx,%rax,2), %xmm1
	psrad	$16, %xmm0
	psrad	$16, %xmm1
	.loc 1 31724 24 view .LVU5261
	movdqa	%xmm0, %xmm2
	punpcklwd	%xmm1, %xmm0
	punpckhwd	%xmm1, %xmm2
	movdqa	%xmm0, %xmm1
	punpckhwd	%xmm2, %xmm1
	punpcklwd	%xmm2, %xmm0
	punpcklwd	%xmm1, %xmm0
	movups	%xmm0, (%rdi,%rax)
.LBE4775:
	.loc 1 31712 9 is_stmt 1 view .LVU5262
	.loc 1 31712 23 view .LVU5263
	addq	$16, %rax
	cmpq	%rdx, %rax
	jne	.L1190
	movq	%r8, %rax
	andq	$-8, %rax
	testb	$7, %r8b
	je	.L1050
.L1189:
.LVL1326:
.LBB4776:
	.loc 1 31713 13 view .LVU5264
	.loc 1 31716 13 view .LVU5265
.LBB4758:
	.loc 1 2540 27 view .LVU5266
.LBE4758:
.LBE4776:
.LBE4800:
.LBE4816:
.LBE4832:
.LBE4848:
.LBE4864:
.LBE4880:
.LBE4900:
	.loc 1 2542 5 view .LVU5267
	.loc 1 2546 5 view .LVU5268
.LBB4901:
.LBB4881:
.LBB4865:
.LBB4849:
.LBB4833:
.LBB4817:
.LBB4801:
.LBB4777:
	.loc 1 31718 17 view .LVU5269
	.loc 1 31723 13 view .LVU5270
	.loc 1 31724 13 view .LVU5271
	.loc 1 31723 15 is_stmt 0 view .LVU5272
	movswl	2(%rbx,%rax,4), %edx
	.loc 1 31724 24 view .LVU5273
	movw	%dx, (%rdi,%rax,2)
.LBE4777:
	.loc 1 31712 9 is_stmt 1 view .LVU5274
	.loc 1 31712 34 is_stmt 0 view .LVU5275
	leaq	1(%rax), %rdx
.LVL1327:
	.loc 1 31712 23 is_stmt 1 view .LVU5276
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4778:
	.loc 1 31713 13 view .LVU5277
.LVL1328:
	.loc 1 31716 13 view .LVU5278
.LBB4759:
	.loc 1 2540 27 view .LVU5279
.LBE4759:
.LBE4778:
.LBE4801:
.LBE4817:
.LBE4833:
.LBE4849:
.LBE4865:
.LBE4881:
.LBE4901:
	.loc 1 2542 5 view .LVU5280
	.loc 1 2546 5 view .LVU5281
.LBB4902:
.LBB4882:
.LBB4866:
.LBB4850:
.LBB4834:
.LBB4818:
.LBB4802:
.LBB4779:
	.loc 1 31718 17 view .LVU5282
	.loc 1 31723 13 view .LVU5283
	.loc 1 31724 13 view .LVU5284
	.loc 1 31723 15 is_stmt 0 view .LVU5285
	movswl	2(%rbx,%rdx,4), %ecx
	.loc 1 31724 24 view .LVU5286
	movw	%cx, (%rdi,%rdx,2)
.LBE4779:
	.loc 1 31712 9 is_stmt 1 view .LVU5287
	.loc 1 31712 34 is_stmt 0 view .LVU5288
	leaq	2(%rax), %rdx
.LVL1329:
	.loc 1 31712 23 is_stmt 1 view .LVU5289
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4780:
	.loc 1 31713 13 view .LVU5290
.LVL1330:
	.loc 1 31716 13 view .LVU5291
.LBB4760:
	.loc 1 2540 27 view .LVU5292
.LBE4760:
.LBE4780:
.LBE4802:
.LBE4818:
.LBE4834:
.LBE4850:
.LBE4866:
.LBE4882:
.LBE4902:
	.loc 1 2542 5 view .LVU5293
	.loc 1 2546 5 view .LVU5294
.LBB4903:
.LBB4883:
.LBB4867:
.LBB4851:
.LBB4835:
.LBB4819:
.LBB4803:
.LBB4781:
	.loc 1 31718 17 view .LVU5295
	.loc 1 31723 13 view .LVU5296
	.loc 1 31724 13 view .LVU5297
	.loc 1 31723 15 is_stmt 0 view .LVU5298
	movswl	2(%rbx,%rdx,4), %ecx
	.loc 1 31724 24 view .LVU5299
	movw	%cx, (%rdi,%rdx,2)
.LBE4781:
	.loc 1 31712 9 is_stmt 1 view .LVU5300
	.loc 1 31712 34 is_stmt 0 view .LVU5301
	leaq	3(%rax), %rdx
.LVL1331:
	.loc 1 31712 23 is_stmt 1 view .LVU5302
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4782:
	.loc 1 31713 13 view .LVU5303
.LVL1332:
	.loc 1 31716 13 view .LVU5304
.LBB4761:
	.loc 1 2540 27 view .LVU5305
.LBE4761:
.LBE4782:
.LBE4803:
.LBE4819:
.LBE4835:
.LBE4851:
.LBE4867:
.LBE4883:
.LBE4903:
	.loc 1 2542 5 view .LVU5306
	.loc 1 2546 5 view .LVU5307
.LBB4904:
.LBB4884:
.LBB4868:
.LBB4852:
.LBB4836:
.LBB4820:
.LBB4804:
.LBB4783:
	.loc 1 31718 17 view .LVU5308
	.loc 1 31723 13 view .LVU5309
	.loc 1 31724 13 view .LVU5310
	.loc 1 31723 15 is_stmt 0 view .LVU5311
	movswl	2(%rbx,%rdx,4), %ecx
	.loc 1 31724 24 view .LVU5312
	movw	%cx, (%rdi,%rdx,2)
.LBE4783:
	.loc 1 31712 9 is_stmt 1 view .LVU5313
	.loc 1 31712 34 is_stmt 0 view .LVU5314
	leaq	4(%rax), %rdx
.LVL1333:
	.loc 1 31712 23 is_stmt 1 view .LVU5315
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4784:
	.loc 1 31713 13 view .LVU5316
.LVL1334:
	.loc 1 31716 13 view .LVU5317
.LBB4762:
	.loc 1 2540 27 view .LVU5318
.LBE4762:
.LBE4784:
.LBE4804:
.LBE4820:
.LBE4836:
.LBE4852:
.LBE4868:
.LBE4884:
.LBE4904:
	.loc 1 2542 5 view .LVU5319
	.loc 1 2546 5 view .LVU5320
.LBB4905:
.LBB4885:
.LBB4869:
.LBB4853:
.LBB4837:
.LBB4821:
.LBB4805:
.LBB4785:
	.loc 1 31718 17 view .LVU5321
	.loc 1 31723 13 view .LVU5322
	.loc 1 31724 13 view .LVU5323
	.loc 1 31723 15 is_stmt 0 view .LVU5324
	movswl	2(%rbx,%rdx,4), %ecx
	.loc 1 31724 24 view .LVU5325
	movw	%cx, (%rdi,%rdx,2)
.LBE4785:
	.loc 1 31712 9 is_stmt 1 view .LVU5326
	.loc 1 31712 34 is_stmt 0 view .LVU5327
	leaq	5(%rax), %rdx
.LVL1335:
	.loc 1 31712 23 is_stmt 1 view .LVU5328
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4786:
	.loc 1 31713 13 view .LVU5329
.LVL1336:
	.loc 1 31716 13 view .LVU5330
.LBB4763:
	.loc 1 2540 27 view .LVU5331
.LBE4763:
.LBE4786:
.LBE4805:
.LBE4821:
.LBE4837:
.LBE4853:
.LBE4869:
.LBE4885:
.LBE4905:
	.loc 1 2542 5 view .LVU5332
	.loc 1 2546 5 view .LVU5333
.LBB4906:
.LBB4886:
.LBB4870:
.LBB4854:
.LBB4838:
.LBB4822:
.LBB4806:
.LBB4787:
	.loc 1 31718 17 view .LVU5334
	.loc 1 31723 13 view .LVU5335
	.loc 1 31724 13 view .LVU5336
	.loc 1 31723 15 is_stmt 0 view .LVU5337
	movswl	2(%rbx,%rdx,4), %ecx
.LBE4787:
	.loc 1 31712 34 view .LVU5338
	addq	$6, %rax
.LBB4788:
	.loc 1 31724 24 view .LVU5339
	movw	%cx, (%rdi,%rdx,2)
.LBE4788:
	.loc 1 31712 9 is_stmt 1 view .LVU5340
.LVL1337:
	.loc 1 31712 23 view .LVU5341
	cmpq	%rax, %r8
	jbe	.L1050
.LBB4789:
	.loc 1 31713 13 view .LVU5342
	.loc 1 31716 13 view .LVU5343
.LVL1338:
.LBB4764:
	.loc 1 2540 27 view .LVU5344
.LBE4764:
.LBE4789:
.LBE4806:
.LBE4822:
.LBE4838:
.LBE4854:
.LBE4870:
.LBE4886:
.LBE4906:
	.loc 1 2542 5 view .LVU5345
	.loc 1 2546 5 view .LVU5346
.LBB4907:
.LBB4887:
.LBB4871:
.LBB4855:
.LBB4839:
.LBB4823:
.LBB4807:
.LBB4790:
	.loc 1 31718 17 view .LVU5347
	.loc 1 31723 13 view .LVU5348
	.loc 1 31724 13 view .LVU5349
	.loc 1 31723 15 is_stmt 0 view .LVU5350
	movswl	2(%rbx,%rax,4), %edx
	.loc 1 31724 24 view .LVU5351
	movw	%dx, (%rdi,%rax,2)
.LBE4790:
	.loc 1 31712 9 is_stmt 1 view .LVU5352
	.loc 1 31712 23 view .LVU5353
	jmp	.L1050
.LVL1339:
	.p2align 4,,10
	.p2align 3
.L1116:
	.loc 1 31712 23 is_stmt 0 view .LVU5354
.LBE4807:
.LBE4823:
.LBE4839:
.LBE4855:
.LBE4871:
.LBE4887:
.LBE4907:
	cmpl	$5, %esi
	jne	.L1050
.LVL1340:
.LBB4908:
.LBB4909:
.LBB4910:
.LBB4911:
.LBB4912:
	.loc 1 31484 19 view .LVU5355
	testq	%r8, %r8
	je	.L1050
	leaq	(%r8,%r8,2), %rcx
	movss	.LC99(%rip), %xmm1
	addq	%rdx, %rcx
.LVL1341:
	.p2align 4,,10
	.p2align 3
.L1157:
.LBB4913:
	.loc 1 31485 40 view .LVU5356
	movzbl	(%rbx), %eax
	.loc 1 31485 77 view .LVU5357
	movzbl	1(%rbx), %edx
	.loc 1 31485 15 view .LVU5358
	pxor	%xmm0, %xmm0
.LBE4913:
	.loc 1 31484 19 view .LVU5359
	addq	$3, %rbx
	addq	$4, %rdi
.LBB4914:
	.loc 1 31485 105 view .LVU5360
	sall	$16, %edx
	.loc 1 31485 68 view .LVU5361
	sall	$8, %eax
	.loc 1 31485 112 view .LVU5362
	orl	%edx, %eax
	.loc 1 31485 115 view .LVU5363
	movzbl	-1(%rbx), %edx
	.loc 1 31485 144 view .LVU5364
	sall	$24, %edx
	.loc 1 31485 112 view .LVU5365
	orl	%edx, %eax
	.loc 1 31485 152 view .LVU5366
	sarl	$8, %eax
	.loc 1 31485 15 view .LVU5367
	cvtsi2ssl	%eax, %xmm0
.LVL1342:
	.loc 1 31494 11 view .LVU5368
	mulss	%xmm1, %xmm0
.LVL1343:
	.loc 1 31497 20 view .LVU5369
	movss	%xmm0, -4(%rdi)
.LBE4914:
	.loc 1 31484 19 view .LVU5370
	cmpq	%rcx, %rbx
	jne	.L1157
	jmp	.L1050
.LVL1344:
	.p2align 4,,10
	.p2align 3
.L1205:
	.loc 1 31484 19 view .LVU5371
.LBE4912:
.LBE4911:
.LBE4910:
.LBE4909:
.LBE4908:
	cmpl	$4, %esi
	jne	.L1050
.LVL1345:
.LBB4915:
.LBB4916:
.LBB4917:
.LBB4918:
.LBB4919:
	.loc 1 32587 19 is_stmt 1 view .LVU5372
	testq	%r8, %r8
	je	.L1050
	movss	.LC88(%rip), %xmm3
.LBB4920:
	.loc 1 32589 23 is_stmt 0 view .LVU5373
	movsd	.LC1(%rip), %xmm2
.LBE4920:
	.loc 1 32587 17 view .LVU5374
	xorl	%eax, %eax
	.loc 1 32587 12 view .LVU5375
	xorl	%edx, %edx
.LVL1346:
.LBB4921:
	.loc 1 32598 11 view .LVU5376
	movsd	.LC112(%rip), %xmm1
.LVL1347:
	.p2align 4,,10
	.p2align 3
.L1285:
	.loc 1 32588 9 is_stmt 1 view .LVU5377
	.loc 1 32588 29 is_stmt 0 view .LVU5378
	movss	(%rbx,%rax,4), %xmm0
.LVL1348:
	.loc 1 32589 9 is_stmt 1 view .LVU5379
	.loc 1 32589 23 is_stmt 0 view .LVU5380
	comiss	%xmm3, %xmm0
	jb	.L1458
.LVL1349:
	.loc 1 32598 9 is_stmt 1 view .LVU5381
	.loc 1 32601 9 view .LVU5382
	.loc 1 32588 16 is_stmt 0 view .LVU5383
	cvtss2sd	%xmm0, %xmm0
	.loc 1 32589 23 view .LVU5384
	minsd	%xmm2, %xmm0
	.loc 1 32598 11 view .LVU5385
	mulsd	%xmm1, %xmm0
	.loc 1 32601 22 view .LVU5386
	cvttsd2sil	%xmm0, %ecx
	movl	%ecx, (%rdi,%rax,4)
.LBE4921:
	.loc 1 32587 5 is_stmt 1 view .LVU5387
	.loc 1 32587 30 is_stmt 0 view .LVU5388
	leal	1(%rdx), %eax
	movq	%rax, %rdx
.LVL1350:
	.loc 1 32587 19 is_stmt 1 view .LVU5389
	cmpq	%rax, %r8
	ja	.L1285
	jmp	.L1050
.LVL1351:
	.p2align 4,,10
	.p2align 3
.L1083:
	.loc 1 32587 19 is_stmt 0 view .LVU5390
.LBE4919:
.LBE4918:
.LBE4917:
.LBE4916:
.LBE4915:
	cmpl	$5, %esi
	jne	.L1050
.LVL1352:
.LBB4927:
.LBB4928:
.LBB4929:
.LBB4930:
.LBB4931:
	.loc 1 31122 19 is_stmt 1 view .LVU5391
	testq	%r8, %r8
	je	.L1050
	leaq	-1(%r8), %rax
	cmpq	$6, %rax
	jbe	.L1295
	movq	%r8, %rdx
.LVL1353:
	.loc 1 31122 19 is_stmt 0 view .LVU5392
	movaps	.LC96(%rip), %xmm3
	xorl	%eax, %eax
.LBB4932:
	.loc 1 31123 15 view .LVU5393
	pxor	%xmm4, %xmm4
	shrq	$3, %rdx
	salq	$4, %rdx
.LVL1354:
	.p2align 4,,10
	.p2align 3
.L1113:
	.loc 1 31123 9 is_stmt 1 view .LVU5394
	.loc 1 31123 35 is_stmt 0 view .LVU5395
	movdqu	(%rbx,%rax), %xmm0
.LVL1355:
	.loc 1 31132 9 is_stmt 1 view .LVU5396
	.loc 1 31135 9 view .LVU5397
	.loc 1 31123 15 is_stmt 0 view .LVU5398
	movdqa	%xmm4, %xmm2
	pcmpgtw	%xmm0, %xmm2
	movdqa	%xmm0, %xmm1
	punpcklwd	%xmm2, %xmm1
	punpckhwd	%xmm2, %xmm0
	cvtdq2ps	%xmm1, %xmm1
	cvtdq2ps	%xmm0, %xmm0
	.loc 1 31132 11 view .LVU5399
	mulps	%xmm3, %xmm1
	mulps	%xmm3, %xmm0
	.loc 1 31135 20 view .LVU5400
	movups	%xmm1, (%rdi,%rax,2)
	movups	%xmm0, 16(%rdi,%rax,2)
.LBE4932:
	.loc 1 31122 5 is_stmt 1 view .LVU5401
	.loc 1 31122 19 view .LVU5402
	addq	$16, %rax
	cmpq	%rdx, %rax
	jne	.L1113
	movq	%r8, %rax
	andq	$-8, %rax
	testb	$7, %r8b
	je	.L1050
.L1111:
.LVL1356:
.LBB4933:
	.loc 1 31123 9 view .LVU5403
	.loc 1 31123 15 is_stmt 0 view .LVU5404
	movswl	(%rbx,%rax,2), %edx
	pxor	%xmm1, %xmm1
	.loc 1 31132 11 view .LVU5405
	movss	.LC97(%rip), %xmm0
	.loc 1 31123 15 view .LVU5406
	cvtsi2ssl	%edx, %xmm1
.LVL1357:
	.loc 1 31132 9 is_stmt 1 view .LVU5407
	.loc 1 31135 9 view .LVU5408
.LBE4933:
	.loc 1 31122 30 is_stmt 0 view .LVU5409
	leaq	1(%rax), %rdx
.LBB4934:
	.loc 1 31132 11 view .LVU5410
	mulss	%xmm0, %xmm1
.LVL1358:
	.loc 1 31135 20 view .LVU5411
	movss	%xmm1, (%rdi,%rax,4)
.LBE4934:
	.loc 1 31122 5 is_stmt 1 view .LVU5412
.LVL1359:
	.loc 1 31122 19 view .LVU5413
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4935:
	.loc 1 31123 9 view .LVU5414
	.loc 1 31123 15 is_stmt 0 view .LVU5415
	movswl	(%rbx,%rdx,2), %ecx
	pxor	%xmm1, %xmm1
.LVL1360:
	.loc 1 31123 15 view .LVU5416
	cvtsi2ssl	%ecx, %xmm1
.LVL1361:
	.loc 1 31132 9 is_stmt 1 view .LVU5417
	.loc 1 31135 9 view .LVU5418
	.loc 1 31132 11 is_stmt 0 view .LVU5419
	mulss	%xmm0, %xmm1
.LVL1362:
	.loc 1 31135 20 view .LVU5420
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4935:
	.loc 1 31122 5 is_stmt 1 view .LVU5421
	.loc 1 31122 30 is_stmt 0 view .LVU5422
	leaq	2(%rax), %rdx
.LVL1363:
	.loc 1 31122 19 is_stmt 1 view .LVU5423
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4936:
	.loc 1 31123 9 view .LVU5424
	.loc 1 31123 15 is_stmt 0 view .LVU5425
	movswl	(%rbx,%rdx,2), %ecx
	pxor	%xmm1, %xmm1
.LVL1364:
	.loc 1 31123 15 view .LVU5426
	cvtsi2ssl	%ecx, %xmm1
.LVL1365:
	.loc 1 31132 9 is_stmt 1 view .LVU5427
	.loc 1 31135 9 view .LVU5428
	.loc 1 31132 11 is_stmt 0 view .LVU5429
	mulss	%xmm0, %xmm1
.LVL1366:
	.loc 1 31135 20 view .LVU5430
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4936:
	.loc 1 31122 5 is_stmt 1 view .LVU5431
	.loc 1 31122 30 is_stmt 0 view .LVU5432
	leaq	3(%rax), %rdx
.LVL1367:
	.loc 1 31122 19 is_stmt 1 view .LVU5433
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4937:
	.loc 1 31123 9 view .LVU5434
	.loc 1 31123 15 is_stmt 0 view .LVU5435
	movswl	(%rbx,%rdx,2), %ecx
	pxor	%xmm1, %xmm1
.LVL1368:
	.loc 1 31123 15 view .LVU5436
	cvtsi2ssl	%ecx, %xmm1
.LVL1369:
	.loc 1 31132 9 is_stmt 1 view .LVU5437
	.loc 1 31135 9 view .LVU5438
	.loc 1 31132 11 is_stmt 0 view .LVU5439
	mulss	%xmm0, %xmm1
.LVL1370:
	.loc 1 31135 20 view .LVU5440
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4937:
	.loc 1 31122 5 is_stmt 1 view .LVU5441
	.loc 1 31122 30 is_stmt 0 view .LVU5442
	leaq	4(%rax), %rdx
.LVL1371:
	.loc 1 31122 19 is_stmt 1 view .LVU5443
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4938:
	.loc 1 31123 9 view .LVU5444
	.loc 1 31123 15 is_stmt 0 view .LVU5445
	movswl	(%rbx,%rdx,2), %ecx
	pxor	%xmm1, %xmm1
.LVL1372:
	.loc 1 31123 15 view .LVU5446
	cvtsi2ssl	%ecx, %xmm1
.LVL1373:
	.loc 1 31132 9 is_stmt 1 view .LVU5447
	.loc 1 31135 9 view .LVU5448
	.loc 1 31132 11 is_stmt 0 view .LVU5449
	mulss	%xmm0, %xmm1
.LVL1374:
	.loc 1 31135 20 view .LVU5450
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4938:
	.loc 1 31122 5 is_stmt 1 view .LVU5451
	.loc 1 31122 30 is_stmt 0 view .LVU5452
	leaq	5(%rax), %rdx
.LVL1375:
	.loc 1 31122 19 is_stmt 1 view .LVU5453
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4939:
	.loc 1 31123 9 view .LVU5454
	.loc 1 31123 15 is_stmt 0 view .LVU5455
	movswl	(%rbx,%rdx,2), %ecx
	pxor	%xmm1, %xmm1
.LVL1376:
	.loc 1 31123 15 view .LVU5456
.LBE4939:
	.loc 1 31122 30 view .LVU5457
	addq	$6, %rax
.LVL1377:
.LBB4940:
	.loc 1 31123 15 view .LVU5458
	cvtsi2ssl	%ecx, %xmm1
.LVL1378:
	.loc 1 31132 9 is_stmt 1 view .LVU5459
	.loc 1 31135 9 view .LVU5460
	.loc 1 31132 11 is_stmt 0 view .LVU5461
	mulss	%xmm0, %xmm1
.LVL1379:
	.loc 1 31135 20 view .LVU5462
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4940:
	.loc 1 31122 5 is_stmt 1 view .LVU5463
.LVL1380:
	.loc 1 31122 19 view .LVU5464
	cmpq	%rax, %r8
	jbe	.L1050
.LBB4941:
	.loc 1 31123 9 view .LVU5465
	.loc 1 31123 15 is_stmt 0 view .LVU5466
	movswl	(%rbx,%rax,2), %edx
	pxor	%xmm1, %xmm1
.LVL1381:
	.loc 1 31123 15 view .LVU5467
	cvtsi2ssl	%edx, %xmm1
.LVL1382:
	.loc 1 31132 9 is_stmt 1 view .LVU5468
	.loc 1 31135 9 view .LVU5469
	.loc 1 31132 11 is_stmt 0 view .LVU5470
	mulss	%xmm1, %xmm0
.LVL1383:
	.loc 1 31135 20 view .LVU5471
	movss	%xmm0, (%rdi,%rax,4)
.LBE4941:
	.loc 1 31122 5 is_stmt 1 view .LVU5472
	.loc 1 31122 19 view .LVU5473
	jmp	.L1050
.LVL1384:
	.p2align 4,,10
	.p2align 3
.L1062:
	.loc 1 31122 19 is_stmt 0 view .LVU5474
.LBE4931:
.LBE4930:
.LBE4929:
.LBE4928:
.LBE4927:
	cmpl	$5, %esi
	jne	.L1050
.LVL1385:
.LBB4946:
.LBB4947:
.LBB4948:
.LBB4949:
.LBB4950:
	.loc 1 30761 19 is_stmt 1 view .LVU5475
	testq	%r8, %r8
	je	.L1050
	leaq	(%rdi,%r8,4), %rax
	cmpq	%rax, %rdx
	leaq	(%rbx,%r8), %rax
	setnb	%dl
.LVL1386:
	.loc 1 30761 19 is_stmt 0 view .LVU5476
	cmpq	%rax, %rdi
	setnb	%al
	orb	%al, %dl
	je	.L1289
	leaq	-1(%r8), %rax
	cmpq	$14, %rax
	jbe	.L1289
	movq	%r8, %rcx
	movaps	.LC94(%rip), %xmm3
	movq	%rbx, %rdx
	movq	%rdi, %rax
	andq	$-16, %rcx
	movaps	.LC87(%rip), %xmm2
.LBB4951:
	.loc 1 30762 15 view .LVU5477
	pxor	%xmm5, %xmm5
	pxor	%xmm4, %xmm4
	addq	%rbx, %rcx
.LVL1387:
	.p2align 4,,10
	.p2align 3
.L1079:
	.loc 1 30762 9 is_stmt 1 view .LVU5478
	.loc 1 30762 34 is_stmt 0 view .LVU5479
	movdqu	(%rdx), %xmm0
	.loc 1 30762 15 view .LVU5480
	movdqa	%xmm4, %xmm7
	addq	$16, %rdx
	addq	$64, %rax
	movdqa	%xmm0, %xmm1
	punpckhbw	%xmm5, %xmm0
.LVL1388:
	.loc 1 30763 9 is_stmt 1 view .LVU5481
	.loc 1 30764 9 view .LVU5482
	.loc 1 30766 9 view .LVU5483
	.loc 1 30762 15 is_stmt 0 view .LVU5484
	punpcklbw	%xmm5, %xmm1
	pcmpgtw	%xmm1, %xmm7
	movdqa	%xmm1, %xmm6
	punpcklwd	%xmm7, %xmm6
	punpckhwd	%xmm7, %xmm1
	cvtdq2ps	%xmm6, %xmm6
	.loc 1 30763 11 view .LVU5485
	mulps	%xmm3, %xmm6
	.loc 1 30762 15 view .LVU5486
	cvtdq2ps	%xmm1, %xmm1
	.loc 1 30763 11 view .LVU5487
	mulps	%xmm3, %xmm1
	.loc 1 30764 11 view .LVU5488
	addps	%xmm2, %xmm6
	addps	%xmm2, %xmm1
	.loc 1 30766 20 view .LVU5489
	movups	%xmm6, -64(%rax)
	.loc 1 30762 15 view .LVU5490
	movdqa	%xmm4, %xmm6
	pcmpgtw	%xmm0, %xmm6
	.loc 1 30766 20 view .LVU5491
	movups	%xmm1, -48(%rax)
	.loc 1 30762 15 view .LVU5492
	movdqa	%xmm0, %xmm1
	punpcklwd	%xmm6, %xmm1
	punpckhwd	%xmm6, %xmm0
	cvtdq2ps	%xmm1, %xmm1
	cvtdq2ps	%xmm0, %xmm0
	.loc 1 30763 11 view .LVU5493
	mulps	%xmm3, %xmm1
	mulps	%xmm3, %xmm0
	.loc 1 30764 11 view .LVU5494
	addps	%xmm2, %xmm1
	addps	%xmm2, %xmm0
	.loc 1 30766 20 view .LVU5495
	movups	%xmm1, -32(%rax)
	movups	%xmm0, -16(%rax)
.LBE4951:
	.loc 1 30761 5 is_stmt 1 view .LVU5496
	.loc 1 30761 19 view .LVU5497
	cmpq	%rdx, %rcx
	jne	.L1079
	movq	%r8, %rax
	andq	$-16, %rax
	testb	$15, %r8b
	je	.L1050
.LVL1389:
.LBB4952:
	.loc 1 30762 9 view .LVU5498
	.loc 1 30762 15 is_stmt 0 view .LVU5499
	movzbl	(%rbx,%rax), %edx
	pxor	%xmm1, %xmm1
	.loc 1 30763 11 view .LVU5500
	movss	.LC95(%rip), %xmm2
	.loc 1 30764 11 view .LVU5501
	movss	.LC77(%rip), %xmm0
	.loc 1 30762 15 view .LVU5502
	cvtsi2ssl	%edx, %xmm1
.LVL1390:
	.loc 1 30763 9 is_stmt 1 view .LVU5503
.LBE4952:
	.loc 1 30761 30 is_stmt 0 view .LVU5504
	leaq	1(%rax), %rdx
.LBB4953:
	.loc 1 30763 11 view .LVU5505
	mulss	%xmm2, %xmm1
.LVL1391:
	.loc 1 30764 9 is_stmt 1 view .LVU5506
	.loc 1 30766 9 view .LVU5507
	.loc 1 30764 11 is_stmt 0 view .LVU5508
	subss	%xmm0, %xmm1
.LVL1392:
	.loc 1 30766 20 view .LVU5509
	movss	%xmm1, (%rdi,%rax,4)
.LBE4953:
	.loc 1 30761 5 is_stmt 1 view .LVU5510
.LVL1393:
	.loc 1 30761 19 view .LVU5511
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4954:
	.loc 1 30762 9 view .LVU5512
	.loc 1 30762 15 is_stmt 0 view .LVU5513
	movzbl	1(%rbx,%rax), %ecx
	pxor	%xmm1, %xmm1
.LVL1394:
	.loc 1 30762 15 view .LVU5514
	cvtsi2ssl	%ecx, %xmm1
.LVL1395:
	.loc 1 30763 9 is_stmt 1 view .LVU5515
	.loc 1 30763 11 is_stmt 0 view .LVU5516
	mulss	%xmm2, %xmm1
.LVL1396:
	.loc 1 30764 9 is_stmt 1 view .LVU5517
	.loc 1 30766 9 view .LVU5518
	.loc 1 30764 11 is_stmt 0 view .LVU5519
	subss	%xmm0, %xmm1
.LVL1397:
	.loc 1 30766 20 view .LVU5520
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4954:
	.loc 1 30761 5 is_stmt 1 view .LVU5521
	.loc 1 30761 30 is_stmt 0 view .LVU5522
	leaq	2(%rax), %rdx
.LVL1398:
	.loc 1 30761 19 is_stmt 1 view .LVU5523
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4955:
	.loc 1 30762 9 view .LVU5524
	.loc 1 30762 15 is_stmt 0 view .LVU5525
	movzbl	2(%rbx,%rax), %ecx
	pxor	%xmm1, %xmm1
.LVL1399:
	.loc 1 30762 15 view .LVU5526
	cvtsi2ssl	%ecx, %xmm1
.LVL1400:
	.loc 1 30763 9 is_stmt 1 view .LVU5527
	.loc 1 30763 11 is_stmt 0 view .LVU5528
	mulss	%xmm2, %xmm1
.LVL1401:
	.loc 1 30764 9 is_stmt 1 view .LVU5529
	.loc 1 30766 9 view .LVU5530
	.loc 1 30764 11 is_stmt 0 view .LVU5531
	subss	%xmm0, %xmm1
.LVL1402:
	.loc 1 30766 20 view .LVU5532
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4955:
	.loc 1 30761 5 is_stmt 1 view .LVU5533
	.loc 1 30761 30 is_stmt 0 view .LVU5534
	leaq	3(%rax), %rdx
.LVL1403:
	.loc 1 30761 19 is_stmt 1 view .LVU5535
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4956:
	.loc 1 30762 9 view .LVU5536
	.loc 1 30762 15 is_stmt 0 view .LVU5537
	movzbl	3(%rbx,%rax), %ecx
	pxor	%xmm1, %xmm1
.LVL1404:
	.loc 1 30762 15 view .LVU5538
	cvtsi2ssl	%ecx, %xmm1
.LVL1405:
	.loc 1 30763 9 is_stmt 1 view .LVU5539
	.loc 1 30763 11 is_stmt 0 view .LVU5540
	mulss	%xmm2, %xmm1
.LVL1406:
	.loc 1 30764 9 is_stmt 1 view .LVU5541
	.loc 1 30766 9 view .LVU5542
	.loc 1 30764 11 is_stmt 0 view .LVU5543
	subss	%xmm0, %xmm1
.LVL1407:
	.loc 1 30766 20 view .LVU5544
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4956:
	.loc 1 30761 5 is_stmt 1 view .LVU5545
	.loc 1 30761 30 is_stmt 0 view .LVU5546
	leaq	4(%rax), %rdx
.LVL1408:
	.loc 1 30761 19 is_stmt 1 view .LVU5547
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4957:
	.loc 1 30762 9 view .LVU5548
	.loc 1 30762 15 is_stmt 0 view .LVU5549
	movzbl	4(%rbx,%rax), %ecx
	pxor	%xmm1, %xmm1
.LVL1409:
	.loc 1 30762 15 view .LVU5550
	cvtsi2ssl	%ecx, %xmm1
.LVL1410:
	.loc 1 30763 9 is_stmt 1 view .LVU5551
	.loc 1 30763 11 is_stmt 0 view .LVU5552
	mulss	%xmm2, %xmm1
.LVL1411:
	.loc 1 30764 9 is_stmt 1 view .LVU5553
	.loc 1 30766 9 view .LVU5554
	.loc 1 30764 11 is_stmt 0 view .LVU5555
	subss	%xmm0, %xmm1
.LVL1412:
	.loc 1 30766 20 view .LVU5556
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4957:
	.loc 1 30761 5 is_stmt 1 view .LVU5557
	.loc 1 30761 30 is_stmt 0 view .LVU5558
	leaq	5(%rax), %rdx
.LVL1413:
	.loc 1 30761 19 is_stmt 1 view .LVU5559
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4958:
	.loc 1 30762 9 view .LVU5560
	.loc 1 30762 15 is_stmt 0 view .LVU5561
	movzbl	5(%rbx,%rax), %ecx
	pxor	%xmm1, %xmm1
.LVL1414:
	.loc 1 30762 15 view .LVU5562
	cvtsi2ssl	%ecx, %xmm1
.LVL1415:
	.loc 1 30763 9 is_stmt 1 view .LVU5563
	.loc 1 30763 11 is_stmt 0 view .LVU5564
	mulss	%xmm2, %xmm1
.LVL1416:
	.loc 1 30764 9 is_stmt 1 view .LVU5565
	.loc 1 30766 9 view .LVU5566
	.loc 1 30764 11 is_stmt 0 view .LVU5567
	subss	%xmm0, %xmm1
.LVL1417:
	.loc 1 30766 20 view .LVU5568
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4958:
	.loc 1 30761 5 is_stmt 1 view .LVU5569
	.loc 1 30761 30 is_stmt 0 view .LVU5570
	leaq	6(%rax), %rdx
.LVL1418:
	.loc 1 30761 19 is_stmt 1 view .LVU5571
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4959:
	.loc 1 30762 9 view .LVU5572
	.loc 1 30762 15 is_stmt 0 view .LVU5573
	movzbl	6(%rbx,%rax), %ecx
	pxor	%xmm1, %xmm1
.LVL1419:
	.loc 1 30762 15 view .LVU5574
	cvtsi2ssl	%ecx, %xmm1
.LVL1420:
	.loc 1 30763 9 is_stmt 1 view .LVU5575
	.loc 1 30763 11 is_stmt 0 view .LVU5576
	mulss	%xmm2, %xmm1
.LVL1421:
	.loc 1 30764 9 is_stmt 1 view .LVU5577
	.loc 1 30766 9 view .LVU5578
	.loc 1 30764 11 is_stmt 0 view .LVU5579
	subss	%xmm0, %xmm1
.LVL1422:
	.loc 1 30766 20 view .LVU5580
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4959:
	.loc 1 30761 5 is_stmt 1 view .LVU5581
	.loc 1 30761 30 is_stmt 0 view .LVU5582
	leaq	7(%rax), %rdx
.LVL1423:
	.loc 1 30761 19 is_stmt 1 view .LVU5583
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4960:
	.loc 1 30762 9 view .LVU5584
	.loc 1 30762 15 is_stmt 0 view .LVU5585
	movzbl	7(%rbx,%rax), %ecx
	pxor	%xmm1, %xmm1
.LVL1424:
	.loc 1 30762 15 view .LVU5586
	cvtsi2ssl	%ecx, %xmm1
.LVL1425:
	.loc 1 30763 9 is_stmt 1 view .LVU5587
	.loc 1 30763 11 is_stmt 0 view .LVU5588
	mulss	%xmm2, %xmm1
.LVL1426:
	.loc 1 30764 9 is_stmt 1 view .LVU5589
	.loc 1 30766 9 view .LVU5590
	.loc 1 30764 11 is_stmt 0 view .LVU5591
	subss	%xmm0, %xmm1
.LVL1427:
	.loc 1 30766 20 view .LVU5592
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4960:
	.loc 1 30761 5 is_stmt 1 view .LVU5593
	.loc 1 30761 30 is_stmt 0 view .LVU5594
	leaq	8(%rax), %rdx
.LVL1428:
	.loc 1 30761 19 is_stmt 1 view .LVU5595
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4961:
	.loc 1 30762 9 view .LVU5596
	.loc 1 30762 15 is_stmt 0 view .LVU5597
	movzbl	8(%rbx,%rax), %ecx
	pxor	%xmm1, %xmm1
.LVL1429:
	.loc 1 30762 15 view .LVU5598
	cvtsi2ssl	%ecx, %xmm1
.LVL1430:
	.loc 1 30763 9 is_stmt 1 view .LVU5599
	.loc 1 30763 11 is_stmt 0 view .LVU5600
	mulss	%xmm2, %xmm1
.LVL1431:
	.loc 1 30764 9 is_stmt 1 view .LVU5601
	.loc 1 30766 9 view .LVU5602
	.loc 1 30764 11 is_stmt 0 view .LVU5603
	subss	%xmm0, %xmm1
.LVL1432:
	.loc 1 30766 20 view .LVU5604
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4961:
	.loc 1 30761 5 is_stmt 1 view .LVU5605
	.loc 1 30761 30 is_stmt 0 view .LVU5606
	leaq	9(%rax), %rdx
.LVL1433:
	.loc 1 30761 19 is_stmt 1 view .LVU5607
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4962:
	.loc 1 30762 9 view .LVU5608
	.loc 1 30762 15 is_stmt 0 view .LVU5609
	movzbl	9(%rbx,%rax), %ecx
	pxor	%xmm1, %xmm1
.LVL1434:
	.loc 1 30762 15 view .LVU5610
	cvtsi2ssl	%ecx, %xmm1
.LVL1435:
	.loc 1 30763 9 is_stmt 1 view .LVU5611
	.loc 1 30763 11 is_stmt 0 view .LVU5612
	mulss	%xmm2, %xmm1
.LVL1436:
	.loc 1 30764 9 is_stmt 1 view .LVU5613
	.loc 1 30766 9 view .LVU5614
	.loc 1 30764 11 is_stmt 0 view .LVU5615
	subss	%xmm0, %xmm1
.LVL1437:
	.loc 1 30766 20 view .LVU5616
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4962:
	.loc 1 30761 5 is_stmt 1 view .LVU5617
	.loc 1 30761 30 is_stmt 0 view .LVU5618
	leaq	10(%rax), %rdx
.LVL1438:
	.loc 1 30761 19 is_stmt 1 view .LVU5619
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4963:
	.loc 1 30762 9 view .LVU5620
	.loc 1 30762 15 is_stmt 0 view .LVU5621
	movzbl	10(%rbx,%rax), %ecx
	pxor	%xmm1, %xmm1
.LVL1439:
	.loc 1 30762 15 view .LVU5622
	cvtsi2ssl	%ecx, %xmm1
.LVL1440:
	.loc 1 30763 9 is_stmt 1 view .LVU5623
	.loc 1 30763 11 is_stmt 0 view .LVU5624
	mulss	%xmm2, %xmm1
.LVL1441:
	.loc 1 30764 9 is_stmt 1 view .LVU5625
	.loc 1 30766 9 view .LVU5626
	.loc 1 30764 11 is_stmt 0 view .LVU5627
	subss	%xmm0, %xmm1
.LVL1442:
	.loc 1 30766 20 view .LVU5628
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4963:
	.loc 1 30761 5 is_stmt 1 view .LVU5629
	.loc 1 30761 30 is_stmt 0 view .LVU5630
	leaq	11(%rax), %rdx
.LVL1443:
	.loc 1 30761 19 is_stmt 1 view .LVU5631
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4964:
	.loc 1 30762 9 view .LVU5632
	.loc 1 30762 15 is_stmt 0 view .LVU5633
	movzbl	11(%rbx,%rax), %ecx
	pxor	%xmm1, %xmm1
.LVL1444:
	.loc 1 30762 15 view .LVU5634
	cvtsi2ssl	%ecx, %xmm1
.LVL1445:
	.loc 1 30763 9 is_stmt 1 view .LVU5635
	.loc 1 30763 11 is_stmt 0 view .LVU5636
	mulss	%xmm2, %xmm1
.LVL1446:
	.loc 1 30764 9 is_stmt 1 view .LVU5637
	.loc 1 30766 9 view .LVU5638
	.loc 1 30764 11 is_stmt 0 view .LVU5639
	subss	%xmm0, %xmm1
.LVL1447:
	.loc 1 30766 20 view .LVU5640
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4964:
	.loc 1 30761 5 is_stmt 1 view .LVU5641
	.loc 1 30761 30 is_stmt 0 view .LVU5642
	leaq	12(%rax), %rdx
.LVL1448:
	.loc 1 30761 19 is_stmt 1 view .LVU5643
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4965:
	.loc 1 30762 9 view .LVU5644
	.loc 1 30762 15 is_stmt 0 view .LVU5645
	movzbl	12(%rbx,%rax), %ecx
	pxor	%xmm1, %xmm1
.LVL1449:
	.loc 1 30762 15 view .LVU5646
	cvtsi2ssl	%ecx, %xmm1
.LVL1450:
	.loc 1 30763 9 is_stmt 1 view .LVU5647
	.loc 1 30763 11 is_stmt 0 view .LVU5648
	mulss	%xmm2, %xmm1
.LVL1451:
	.loc 1 30764 9 is_stmt 1 view .LVU5649
	.loc 1 30766 9 view .LVU5650
	.loc 1 30764 11 is_stmt 0 view .LVU5651
	subss	%xmm0, %xmm1
.LVL1452:
	.loc 1 30766 20 view .LVU5652
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4965:
	.loc 1 30761 5 is_stmt 1 view .LVU5653
	.loc 1 30761 30 is_stmt 0 view .LVU5654
	leaq	13(%rax), %rdx
.LVL1453:
	.loc 1 30761 19 is_stmt 1 view .LVU5655
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4966:
	.loc 1 30762 9 view .LVU5656
	.loc 1 30762 15 is_stmt 0 view .LVU5657
	movzbl	13(%rbx,%rax), %ecx
	pxor	%xmm1, %xmm1
.LVL1454:
	.loc 1 30762 15 view .LVU5658
	cvtsi2ssl	%ecx, %xmm1
.LVL1455:
	.loc 1 30763 9 is_stmt 1 view .LVU5659
	.loc 1 30763 11 is_stmt 0 view .LVU5660
	mulss	%xmm2, %xmm1
.LVL1456:
	.loc 1 30764 9 is_stmt 1 view .LVU5661
	.loc 1 30766 9 view .LVU5662
	.loc 1 30764 11 is_stmt 0 view .LVU5663
	subss	%xmm0, %xmm1
.LVL1457:
	.loc 1 30766 20 view .LVU5664
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4966:
	.loc 1 30761 5 is_stmt 1 view .LVU5665
	.loc 1 30761 30 is_stmt 0 view .LVU5666
	leaq	14(%rax), %rdx
.LVL1458:
	.loc 1 30761 19 is_stmt 1 view .LVU5667
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4967:
	.loc 1 30762 9 view .LVU5668
	.loc 1 30762 15 is_stmt 0 view .LVU5669
	movzbl	14(%rbx,%rax), %eax
	pxor	%xmm1, %xmm1
.LVL1459:
	.loc 1 30762 15 view .LVU5670
	cvtsi2ssl	%eax, %xmm1
.LVL1460:
	.loc 1 30763 9 is_stmt 1 view .LVU5671
	.loc 1 30763 11 is_stmt 0 view .LVU5672
	mulss	%xmm2, %xmm1
.LVL1461:
	.loc 1 30764 9 is_stmt 1 view .LVU5673
	.loc 1 30766 9 view .LVU5674
	.loc 1 30764 11 is_stmt 0 view .LVU5675
	subss	%xmm0, %xmm1
.LVL1462:
	.loc 1 30766 20 view .LVU5676
	movss	%xmm1, (%rdi,%rdx,4)
.LBE4967:
	.loc 1 30761 5 is_stmt 1 view .LVU5677
.LVL1463:
	.loc 1 30761 19 view .LVU5678
	jmp	.L1050
.LVL1464:
	.p2align 4,,10
	.p2align 3
.L1159:
	.loc 1 30761 19 is_stmt 0 view .LVU5679
.LBE4950:
.LBE4949:
.LBE4948:
.LBE4947:
.LBE4946:
	cmpl	$5, %esi
	jne	.L1050
.LVL1465:
.LBB4973:
.LBB4974:
.LBB4975:
.LBB4976:
.LBB4977:
	.loc 1 31857 19 is_stmt 1 view .LVU5680
	testq	%r8, %r8
	je	.L1050
	leaq	-1(%r8), %rax
	cmpq	$2, %rax
	jbe	.L1305
	movq	%r8, %rdx
.LVL1466:
	.loc 1 31857 19 is_stmt 0 view .LVU5681
	movapd	.LC100(%rip), %xmm2
	xorl	%eax, %eax
	shrq	$2, %rdx
	salq	$4, %rdx
.LVL1467:
	.p2align 4,,10
	.p2align 3
.L1202:
.LBB4978:
	.loc 1 31858 9 is_stmt 1 view .LVU5682
	.loc 1 31865 9 view .LVU5683
	.loc 1 31868 9 view .LVU5684
	.loc 1 31858 16 is_stmt 0 view .LVU5685
	movdqu	(%rbx,%rax), %xmm5
	cvtdq2pd	(%rbx,%rax), %xmm1
	.loc 1 31865 11 view .LVU5686
	mulpd	%xmm2, %xmm1
	.loc 1 31858 16 view .LVU5687
	pshufd	$238, %xmm5, %xmm0
	cvtdq2pd	%xmm0, %xmm0
	.loc 1 31865 11 view .LVU5688
	mulpd	%xmm2, %xmm0
	.loc 1 31868 22 view .LVU5689
	cvtpd2ps	%xmm1, %xmm1
	cvtpd2ps	%xmm0, %xmm0
	movlhps	%xmm0, %xmm1
	.loc 1 31868 20 view .LVU5690
	movups	%xmm1, (%rdi,%rax)
.LBE4978:
	.loc 1 31857 5 is_stmt 1 view .LVU5691
	.loc 1 31857 19 view .LVU5692
	addq	$16, %rax
	cmpq	%rdx, %rax
	jne	.L1202
	movq	%r8, %rax
	andq	$-4, %rax
	testb	$3, %r8b
	je	.L1050
.L1200:
.LVL1468:
.LBB4979:
	.loc 1 31858 9 view .LVU5693
	.loc 1 31858 16 is_stmt 0 view .LVU5694
	pxor	%xmm0, %xmm0
	.loc 1 31865 11 view .LVU5695
	movsd	.LC101(%rip), %xmm1
.LBE4979:
	.loc 1 31857 30 view .LVU5696
	leaq	1(%rax), %rdx
.LBB4980:
	.loc 1 31858 16 view .LVU5697
	cvtsi2sdl	(%rbx,%rax,4), %xmm0
.LVL1469:
	.loc 1 31865 9 is_stmt 1 view .LVU5698
	.loc 1 31868 9 view .LVU5699
	.loc 1 31865 11 is_stmt 0 view .LVU5700
	mulsd	%xmm1, %xmm0
.LVL1470:
	.loc 1 31868 22 view .LVU5701
	cvtsd2ss	%xmm0, %xmm0
.LVL1471:
	.loc 1 31868 22 view .LVU5702
	movss	%xmm0, (%rdi,%rax,4)
.LBE4980:
	.loc 1 31857 5 is_stmt 1 view .LVU5703
.LVL1472:
	.loc 1 31857 19 view .LVU5704
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4981:
	.loc 1 31858 9 view .LVU5705
	.loc 1 31858 16 is_stmt 0 view .LVU5706
	pxor	%xmm0, %xmm0
.LBE4981:
	.loc 1 31857 30 view .LVU5707
	addq	$2, %rax
.LBB4982:
	.loc 1 31858 16 view .LVU5708
	cvtsi2sdl	(%rbx,%rdx,4), %xmm0
.LVL1473:
	.loc 1 31865 9 is_stmt 1 view .LVU5709
	.loc 1 31868 9 view .LVU5710
	.loc 1 31865 11 is_stmt 0 view .LVU5711
	mulsd	%xmm1, %xmm0
.LVL1474:
	.loc 1 31868 22 view .LVU5712
	cvtsd2ss	%xmm0, %xmm0
.LVL1475:
	.loc 1 31868 22 view .LVU5713
	movss	%xmm0, (%rdi,%rdx,4)
.LBE4982:
	.loc 1 31857 5 is_stmt 1 view .LVU5714
.LVL1476:
	.loc 1 31857 19 view .LVU5715
	cmpq	%rax, %r8
	jbe	.L1050
.LBB4983:
	.loc 1 31858 9 view .LVU5716
	.loc 1 31858 16 is_stmt 0 view .LVU5717
	pxor	%xmm0, %xmm0
	cvtsi2sdl	(%rbx,%rax,4), %xmm0
.LVL1477:
	.loc 1 31865 9 is_stmt 1 view .LVU5718
	.loc 1 31868 9 view .LVU5719
	.loc 1 31865 11 is_stmt 0 view .LVU5720
	mulsd	%xmm1, %xmm0
.LVL1478:
	.loc 1 31868 22 view .LVU5721
	cvtsd2ss	%xmm0, %xmm0
.LVL1479:
	.loc 1 31868 22 view .LVU5722
	movss	%xmm0, (%rdi,%rax,4)
.LBE4983:
	.loc 1 31857 5 is_stmt 1 view .LVU5723
	.loc 1 31857 19 view .LVU5724
	jmp	.L1050
.LVL1480:
.L1464:
	.loc 1 31857 19 is_stmt 0 view .LVU5725
.LBE4977:
.LBE4976:
.LBE4975:
.LBE4974:
.LBE4973:
.LBB4988:
.LBB4639:
.LBB4484:
.LBB4483:
.LBB4482:
.LBB4478:
.LBB4479:
	.loc 1 31335 23 is_stmt 1 view .LVU5726
	testq	%r8, %r8
	je	.L1050
	addq	$2, %rbx
	leaq	(%rdi,%r8,2), %rcx
.LVL1481:
	.p2align 4,,10
	.p2align 3
.L1143:
.LBB4480:
	.loc 1 31336 13 view .LVU5727
	.loc 1 31337 13 view .LVU5728
	.loc 1 31338 13 view .LVU5729
	.loc 1 31337 70 is_stmt 0 view .LVU5730
	movzbl	(%rbx), %eax
	.loc 1 31336 23 view .LVU5731
	movzbl	-1(%rbx), %edx
.LVL1482:
	.loc 1 31336 23 view .LVU5732
.LBE4480:
	.loc 1 31335 23 view .LVU5733
	addq	$2, %rdi
	addq	$3, %rbx
.LVL1483:
.LBB4481:
	.loc 1 31337 23 view .LVU5734
	sall	$8, %eax
	.loc 1 31338 44 view .LVU5735
	orl	%edx, %eax
	movw	%ax, -2(%rdi)
.LVL1484:
	.loc 1 31338 44 view .LVU5736
.LBE4481:
	.loc 1 31335 9 is_stmt 1 view .LVU5737
	.loc 1 31335 23 view .LVU5738
	cmpq	%rdi, %rcx
	jne	.L1143
	jmp	.L1050
.LVL1485:
.L1465:
	.loc 1 31335 23 is_stmt 0 view .LVU5739
.LBE4479:
.LBE4478:
.LBE4482:
.LBE4483:
.LBE4484:
.LBE4639:
.LBE4988:
.LBB4989:
.LBB4888:
.LBB4672:
.LBB4670:
.LBB4668:
.LBB4655:
.LBB4656:
	.loc 1 31705 23 is_stmt 1 view .LVU5740
	testq	%r8, %r8
	je	.L1050
	leaq	-1(%r8), %rax
	cmpq	$6, %rax
	jbe	.L1301
	movq	%r8, %rdx
.LVL1486:
	.loc 1 31705 23 is_stmt 0 view .LVU5741
	xorl	%eax, %eax
	shrq	$3, %rdx
	salq	$4, %rdx
.LVL1487:
	.p2align 4,,10
	.p2align 3
.L1185:
.LBB4657:
	.loc 1 31706 13 is_stmt 1 view .LVU5742
	.loc 1 31707 13 view .LVU5743
	.loc 1 31708 13 view .LVU5744
	.loc 1 31707 15 is_stmt 0 view .LVU5745
	movdqu	(%rbx,%rax,2), %xmm0
	movdqu	16(%rbx,%rax,2), %xmm1
	psrad	$16, %xmm0
	psrad	$16, %xmm1
	.loc 1 31708 24 view .LVU5746
	movdqa	%xmm0, %xmm2
	punpcklwd	%xmm1, %xmm0
	punpckhwd	%xmm1, %xmm2
	movdqa	%xmm0, %xmm1
	punpckhwd	%xmm2, %xmm1
	punpcklwd	%xmm2, %xmm0
	punpcklwd	%xmm1, %xmm0
	movups	%xmm0, (%rdi,%rax)
.LBE4657:
	.loc 1 31705 9 is_stmt 1 view .LVU5747
	.loc 1 31705 23 view .LVU5748
	addq	$16, %rax
	cmpq	%rdx, %rax
	jne	.L1185
	movq	%r8, %rax
	andq	$-8, %rax
	testb	$7, %r8b
	je	.L1050
.L1183:
.LVL1488:
.LBB4658:
	.loc 1 31706 13 view .LVU5749
	.loc 1 31707 13 view .LVU5750
	.loc 1 31708 13 view .LVU5751
	.loc 1 31707 15 is_stmt 0 view .LVU5752
	movswl	2(%rbx,%rax,4), %edx
	.loc 1 31708 24 view .LVU5753
	movw	%dx, (%rdi,%rax,2)
.LBE4658:
	.loc 1 31705 9 is_stmt 1 view .LVU5754
	.loc 1 31705 34 is_stmt 0 view .LVU5755
	leaq	1(%rax), %rdx
.LVL1489:
	.loc 1 31705 23 is_stmt 1 view .LVU5756
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4659:
	.loc 1 31706 13 view .LVU5757
.LVL1490:
	.loc 1 31707 13 view .LVU5758
	.loc 1 31708 13 view .LVU5759
	.loc 1 31707 15 is_stmt 0 view .LVU5760
	movswl	2(%rbx,%rdx,4), %ecx
	.loc 1 31708 24 view .LVU5761
	movw	%cx, (%rdi,%rdx,2)
.LBE4659:
	.loc 1 31705 9 is_stmt 1 view .LVU5762
	.loc 1 31705 34 is_stmt 0 view .LVU5763
	leaq	2(%rax), %rdx
.LVL1491:
	.loc 1 31705 23 is_stmt 1 view .LVU5764
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4660:
	.loc 1 31706 13 view .LVU5765
.LVL1492:
	.loc 1 31707 13 view .LVU5766
	.loc 1 31708 13 view .LVU5767
	.loc 1 31707 15 is_stmt 0 view .LVU5768
	movswl	2(%rbx,%rdx,4), %ecx
	.loc 1 31708 24 view .LVU5769
	movw	%cx, (%rdi,%rdx,2)
.LBE4660:
	.loc 1 31705 9 is_stmt 1 view .LVU5770
	.loc 1 31705 34 is_stmt 0 view .LVU5771
	leaq	3(%rax), %rdx
.LVL1493:
	.loc 1 31705 23 is_stmt 1 view .LVU5772
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4661:
	.loc 1 31706 13 view .LVU5773
.LVL1494:
	.loc 1 31707 13 view .LVU5774
	.loc 1 31708 13 view .LVU5775
	.loc 1 31707 15 is_stmt 0 view .LVU5776
	movswl	2(%rbx,%rdx,4), %ecx
	.loc 1 31708 24 view .LVU5777
	movw	%cx, (%rdi,%rdx,2)
.LBE4661:
	.loc 1 31705 9 is_stmt 1 view .LVU5778
	.loc 1 31705 34 is_stmt 0 view .LVU5779
	leaq	4(%rax), %rdx
.LVL1495:
	.loc 1 31705 23 is_stmt 1 view .LVU5780
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4662:
	.loc 1 31706 13 view .LVU5781
.LVL1496:
	.loc 1 31707 13 view .LVU5782
	.loc 1 31708 13 view .LVU5783
	.loc 1 31707 15 is_stmt 0 view .LVU5784
	movswl	2(%rbx,%rdx,4), %ecx
	.loc 1 31708 24 view .LVU5785
	movw	%cx, (%rdi,%rdx,2)
.LBE4662:
	.loc 1 31705 9 is_stmt 1 view .LVU5786
	.loc 1 31705 34 is_stmt 0 view .LVU5787
	leaq	5(%rax), %rdx
.LVL1497:
	.loc 1 31705 23 is_stmt 1 view .LVU5788
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB4663:
	.loc 1 31706 13 view .LVU5789
.LVL1498:
	.loc 1 31707 13 view .LVU5790
	.loc 1 31708 13 view .LVU5791
	.loc 1 31707 15 is_stmt 0 view .LVU5792
	movswl	2(%rbx,%rdx,4), %ecx
.LBE4663:
	.loc 1 31705 34 view .LVU5793
	addq	$6, %rax
.LBB4664:
	.loc 1 31708 24 view .LVU5794
	movw	%cx, (%rdi,%rdx,2)
.LBE4664:
	.loc 1 31705 9 is_stmt 1 view .LVU5795
.LVL1499:
	.loc 1 31705 23 view .LVU5796
	cmpq	%rax, %r8
	jbe	.L1050
.LBB4665:
	.loc 1 31706 13 view .LVU5797
.LVL1500:
	.loc 1 31707 13 view .LVU5798
	.loc 1 31708 13 view .LVU5799
	.loc 1 31707 15 is_stmt 0 view .LVU5800
	movswl	2(%rbx,%rax,4), %edx
	.loc 1 31708 24 view .LVU5801
	movw	%dx, (%rdi,%rax,2)
.LBE4665:
	.loc 1 31705 9 is_stmt 1 view .LVU5802
	.loc 1 31705 23 view .LVU5803
	jmp	.L1050
.LVL1501:
.L1462:
	.loc 1 31705 23 is_stmt 0 view .LVU5804
.LBE4656:
.LBE4655:
.LBE4668:
.LBE4670:
.LBE4672:
.LBE4888:
.LBE4989:
.LBB4990:
.LBB4403:
.LBB4346:
	.loc 1 32100 5 view .LVU5805
	movss	.LC90(%rip), %xmm7
	.loc 1 32102 19 view .LVU5806
	movss	.LC91(%rip), %xmm10
	.loc 1 32101 19 view .LVU5807
	movss	.LC92(%rip), %xmm8
	.loc 1 32100 5 view .LVU5808
	movss	%xmm7, -104(%rbp)
	jmp	.L1217
.LVL1502:
	.p2align 4,,10
	.p2align 3
.L1458:
	.loc 1 32100 5 view .LVU5809
.LBE4346:
.LBE4403:
.LBE4990:
.LBB4991:
.LBB4926:
.LBB4925:
.LBB4924:
.LBB4923:
.LBB4922:
	.loc 1 32598 9 is_stmt 1 view .LVU5810
	.loc 1 32601 9 view .LVU5811
	.loc 1 32601 20 is_stmt 0 view .LVU5812
	movl	$-2147483647, (%rdi,%rax,4)
.LBE4922:
	.loc 1 32587 5 is_stmt 1 view .LVU5813
	.loc 1 32587 30 is_stmt 0 view .LVU5814
	leal	1(%rdx), %eax
	movq	%rax, %rdx
.LVL1503:
	.loc 1 32587 19 is_stmt 1 view .LVU5815
	cmpq	%rax, %r8
	ja	.L1285
	jmp	.L1050
.LVL1504:
	.p2align 4,,10
	.p2align 3
.L1082:
	.loc 1 32587 19 is_stmt 0 view .LVU5816
.LBE4923:
.LBE4924:
.LBE4925:
.LBE4926:
.LBE4991:
.LBB4992:
.LBB4993:
.LBB4994:
.LBB4995:
	.loc 1 31060 19 is_stmt 1 view .LVU5817
	testq	%r8, %r8
	je	.L1050
	leaq	-1(%r8), %rax
	cmpq	$6, %rax
	jbe	.L1294
	movq	%r8, %rdx
.LVL1505:
	.loc 1 31060 19 is_stmt 0 view .LVU5818
	xorl	%eax, %eax
	.loc 1 31061 31 view .LVU5819
	pxor	%xmm3, %xmm3
	shrq	$3, %rdx
	salq	$4, %rdx
.LVL1506:
	.p2align 4,,10
	.p2align 3
.L1109:
	.loc 1 31061 9 is_stmt 1 view .LVU5820
	.loc 1 31061 31 is_stmt 0 view .LVU5821
	movdqu	(%rbx,%rax), %xmm0
	movdqa	%xmm3, %xmm2
	pcmpgtw	%xmm0, %xmm2
	movdqa	%xmm0, %xmm1
	punpcklwd	%xmm2, %xmm1
	punpckhwd	%xmm2, %xmm0
	.loc 1 31061 33 view .LVU5822
	pslld	$16, %xmm1
	pslld	$16, %xmm0
	.loc 1 31061 20 view .LVU5823
	movups	%xmm1, (%rdi,%rax,2)
	movups	%xmm0, 16(%rdi,%rax,2)
	.loc 1 31060 5 is_stmt 1 view .LVU5824
	.loc 1 31060 19 view .LVU5825
	addq	$16, %rax
	cmpq	%rax, %rdx
	jne	.L1109
	movq	%r8, %rax
	andq	$-8, %rax
	testb	$7, %r8b
	je	.L1050
.L1107:
.LVL1507:
	.loc 1 31061 9 view .LVU5826
	.loc 1 31061 31 is_stmt 0 view .LVU5827
	movswl	(%rbx,%rax,2), %edx
	.loc 1 31061 33 view .LVU5828
	sall	$16, %edx
	movl	%edx, (%rdi,%rax,4)
	.loc 1 31060 5 is_stmt 1 view .LVU5829
	.loc 1 31060 30 is_stmt 0 view .LVU5830
	leaq	1(%rax), %rdx
.LVL1508:
	.loc 1 31060 19 is_stmt 1 view .LVU5831
	cmpq	%rdx, %r8
	jbe	.L1050
	.loc 1 31061 9 view .LVU5832
	.loc 1 31061 31 is_stmt 0 view .LVU5833
	movswl	(%rbx,%rdx,2), %ecx
	.loc 1 31061 33 view .LVU5834
	sall	$16, %ecx
	movl	%ecx, (%rdi,%rdx,4)
	.loc 1 31060 5 is_stmt 1 view .LVU5835
	.loc 1 31060 30 is_stmt 0 view .LVU5836
	leaq	2(%rax), %rdx
.LVL1509:
	.loc 1 31060 19 is_stmt 1 view .LVU5837
	cmpq	%rdx, %r8
	jbe	.L1050
	.loc 1 31061 9 view .LVU5838
	.loc 1 31061 31 is_stmt 0 view .LVU5839
	movswl	(%rbx,%rdx,2), %ecx
	.loc 1 31061 33 view .LVU5840
	sall	$16, %ecx
	movl	%ecx, (%rdi,%rdx,4)
	.loc 1 31060 5 is_stmt 1 view .LVU5841
	.loc 1 31060 30 is_stmt 0 view .LVU5842
	leaq	3(%rax), %rdx
.LVL1510:
	.loc 1 31060 19 is_stmt 1 view .LVU5843
	cmpq	%rdx, %r8
	jbe	.L1050
	.loc 1 31061 9 view .LVU5844
	.loc 1 31061 31 is_stmt 0 view .LVU5845
	movswl	(%rbx,%rdx,2), %ecx
	.loc 1 31061 33 view .LVU5846
	sall	$16, %ecx
	movl	%ecx, (%rdi,%rdx,4)
	.loc 1 31060 5 is_stmt 1 view .LVU5847
	.loc 1 31060 30 is_stmt 0 view .LVU5848
	leaq	4(%rax), %rdx
.LVL1511:
	.loc 1 31060 19 is_stmt 1 view .LVU5849
	cmpq	%rdx, %r8
	jbe	.L1050
	.loc 1 31061 9 view .LVU5850
	.loc 1 31061 31 is_stmt 0 view .LVU5851
	movswl	(%rbx,%rdx,2), %ecx
	.loc 1 31061 33 view .LVU5852
	sall	$16, %ecx
	movl	%ecx, (%rdi,%rdx,4)
	.loc 1 31060 5 is_stmt 1 view .LVU5853
	.loc 1 31060 30 is_stmt 0 view .LVU5854
	leaq	5(%rax), %rdx
.LVL1512:
	.loc 1 31060 19 is_stmt 1 view .LVU5855
	cmpq	%rdx, %r8
	jbe	.L1050
	.loc 1 31061 9 view .LVU5856
	.loc 1 31061 31 is_stmt 0 view .LVU5857
	movswl	(%rbx,%rdx,2), %ecx
	.loc 1 31060 30 view .LVU5858
	addq	$6, %rax
	.loc 1 31061 33 view .LVU5859
	sall	$16, %ecx
	movl	%ecx, (%rdi,%rdx,4)
	.loc 1 31060 5 is_stmt 1 view .LVU5860
.LVL1513:
	.loc 1 31060 19 view .LVU5861
	cmpq	%rax, %r8
	jbe	.L1050
	.loc 1 31061 9 view .LVU5862
	.loc 1 31061 31 is_stmt 0 view .LVU5863
	movswl	(%rbx,%rax,2), %edx
	.loc 1 31061 33 view .LVU5864
	sall	$16, %edx
	movl	%edx, (%rdi,%rax,4)
	.loc 1 31060 5 is_stmt 1 view .LVU5865
	.loc 1 31060 19 view .LVU5866
	jmp	.L1050
.LVL1514:
	.p2align 4,,10
	.p2align 3
.L1463:
	.loc 1 31060 19 is_stmt 0 view .LVU5867
	movq	-112(%rbp), %r8
	movq	%r10, %r12
	testb	%r13b, %r13b
	je	.L1274
	movl	%r11d, _ZL7g_maLCG(%rip)
.LVL1515:
.L1274:
	.loc 1 31060 19 view .LVU5868
.LBE4995:
.LBE4994:
.LBE4993:
.LBE4992:
.LBB4999:
.LBB4404:
.LBB4347:
	.loc 1 32143 5 is_stmt 1 view .LVU5869
.LBB4061:
	.loc 1 32143 14 view .LVU5870
	cmpq	%r12, %r8
	jbe	.L1050
	movl	_ZL7g_maLCG(%rip), %eax
	cmpl	$1, %r9d
	je	.L1466
	cmpl	$2, %r9d
	je	.L1467
	leaq	-1(%r8), %rax
	movq	%r8, %r9
.LVL1516:
	.loc 1 32143 14 is_stmt 0 view .LVU5871
	subq	%r12, %rax
	subq	%r12, %r9
	cmpq	$6, %rax
	jbe	.L1277
	movq	%r9, %rcx
	movaps	.LC87(%rip), %xmm2
	leaq	(%rbx,%r12,4), %rdx
	xorl	%eax, %eax
	shrq	$3, %rcx
	movaps	.LC86(%rip), %xmm5
	movaps	.LC110(%rip), %xmm4
	leaq	(%rdi,%r12,2), %rsi
	salq	$4, %rcx
.LVL1517:
	.p2align 4,,10
	.p2align 3
.L1278:
.LBB4062:
	.loc 1 32144 9 is_stmt 1 view .LVU5872
	.loc 1 32145 9 view .LVU5873
.LBB4063:
.LBI4063:
	.loc 1 2528 24 view .LVU5874
.LBE4063:
.LBE4062:
.LBE4061:
.LBE4347:
.LBE4404:
.LBE4999:
	.loc 1 2530 5 view .LVU5875
	.loc 1 2533 5 view .LVU5876
.LBB5000:
.LBB4405:
.LBB4348:
.LBB4281:
.LBB4253:
	.loc 1 32146 9 view .LVU5877
	.loc 1 32147 9 view .LVU5878
	.loc 1 32149 9 view .LVU5879
	.loc 1 32146 23 is_stmt 0 view .LVU5880
	movups	(%rdx,%rax,2), %xmm0
	movups	16(%rdx,%rax,2), %xmm1
	minps	%xmm5, %xmm0
	minps	%xmm5, %xmm1
	.loc 1 32147 11 view .LVU5881
	maxps	%xmm2, %xmm0
	maxps	%xmm2, %xmm1
	mulps	%xmm4, %xmm0
	mulps	%xmm4, %xmm1
	.loc 1 32149 22 view .LVU5882
	cvttps2dq	%xmm0, %xmm0
	movdqa	%xmm0, %xmm3
	cvttps2dq	%xmm1, %xmm1
	punpcklwd	%xmm1, %xmm0
	punpckhwd	%xmm1, %xmm3
	movdqa	%xmm0, %xmm1
	punpcklwd	%xmm3, %xmm0
	punpckhwd	%xmm3, %xmm1
	punpcklwd	%xmm1, %xmm0
	.loc 1 32149 20 view .LVU5883
	movups	%xmm0, (%rsi,%rax)
.LBE4253:
	.loc 1 32143 5 is_stmt 1 view .LVU5884
.LBE4281:
	.loc 1 32143 5 view .LVU5885
.LBB4282:
	.loc 1 32143 14 view .LVU5886
	addq	$16, %rax
	cmpq	%rcx, %rax
	jne	.L1278
	movq	%r9, %rax
	andq	$-8, %rax
	addq	%rax, %r12
	cmpq	%rax, %r9
	je	.L1050
.L1277:
.LVL1518:
.LBB4254:
	.loc 1 32144 9 view .LVU5887
	.loc 1 32145 9 view .LVU5888
.LBB4228:
	.loc 1 2528 24 view .LVU5889
.LBE4228:
.LBE4254:
.LBE4282:
.LBE4348:
.LBE4405:
.LBE5000:
	.loc 1 2530 5 view .LVU5890
	.loc 1 2533 5 view .LVU5891
.LBB5001:
.LBB4406:
.LBB4349:
.LBB4283:
.LBB4255:
	.loc 1 32146 9 view .LVU5892
	.loc 1 32146 23 is_stmt 0 view .LVU5893
	movss	(%rbx,%r12,4), %xmm3
	movss	.LC77(%rip), %xmm0
	movss	.LC88(%rip), %xmm2
	.loc 1 32147 11 view .LVU5894
	movss	.LC109(%rip), %xmm1
	.loc 1 32146 23 view .LVU5895
	minss	%xmm0, %xmm3
	maxss	%xmm2, %xmm3
.LVL1519:
	.loc 1 32147 9 is_stmt 1 view .LVU5896
	.loc 1 32149 9 view .LVU5897
	.loc 1 32147 11 is_stmt 0 view .LVU5898
	mulss	%xmm1, %xmm3
.LVL1520:
	.loc 1 32149 22 view .LVU5899
	cvttss2sil	%xmm3, %eax
	movw	%ax, (%rdi,%r12,2)
.LBE4255:
	.loc 1 32143 5 is_stmt 1 view .LVU5900
	.loc 1 32143 25 is_stmt 0 view .LVU5901
	leaq	1(%r12), %rax
.LVL1521:
	.loc 1 32143 25 view .LVU5902
.LBE4283:
	.loc 1 32143 5 is_stmt 1 view .LVU5903
.LBB4284:
	.loc 1 32143 14 view .LVU5904
	cmpq	%rax, %r8
	jbe	.L1050
.LBB4256:
	.loc 1 32144 9 view .LVU5905
.LVL1522:
	.loc 1 32145 9 view .LVU5906
.LBB4229:
	.loc 1 2528 24 view .LVU5907
.LBE4229:
.LBE4256:
.LBE4284:
.LBE4349:
.LBE4406:
.LBE5001:
	.loc 1 2530 5 view .LVU5908
	.loc 1 2533 5 view .LVU5909
.LBB5002:
.LBB4407:
.LBB4350:
.LBB4285:
.LBB4257:
	.loc 1 32146 9 view .LVU5910
	.loc 1 32146 23 is_stmt 0 view .LVU5911
	movss	(%rbx,%rax,4), %xmm3
	minss	%xmm0, %xmm3
	maxss	%xmm2, %xmm3
.LVL1523:
	.loc 1 32147 9 is_stmt 1 view .LVU5912
	.loc 1 32149 9 view .LVU5913
	.loc 1 32147 11 is_stmt 0 view .LVU5914
	mulss	%xmm1, %xmm3
.LVL1524:
	.loc 1 32149 22 view .LVU5915
	cvttss2sil	%xmm3, %edx
	movw	%dx, (%rdi,%rax,2)
.LBE4257:
	.loc 1 32143 5 is_stmt 1 view .LVU5916
	.loc 1 32143 25 is_stmt 0 view .LVU5917
	leaq	2(%r12), %rax
.LVL1525:
	.loc 1 32143 25 view .LVU5918
.LBE4285:
	.loc 1 32143 5 is_stmt 1 view .LVU5919
.LBB4286:
	.loc 1 32143 14 view .LVU5920
	cmpq	%rax, %r8
	jbe	.L1050
.LBB4258:
	.loc 1 32144 9 view .LVU5921
.LVL1526:
	.loc 1 32145 9 view .LVU5922
.LBB4230:
	.loc 1 2528 24 view .LVU5923
.LBE4230:
.LBE4258:
.LBE4286:
.LBE4350:
.LBE4407:
.LBE5002:
	.loc 1 2530 5 view .LVU5924
	.loc 1 2533 5 view .LVU5925
.LBB5003:
.LBB4408:
.LBB4351:
.LBB4287:
.LBB4259:
	.loc 1 32146 9 view .LVU5926
	.loc 1 32146 23 is_stmt 0 view .LVU5927
	movss	(%rbx,%rax,4), %xmm3
	minss	%xmm0, %xmm3
	maxss	%xmm2, %xmm3
.LVL1527:
	.loc 1 32147 9 is_stmt 1 view .LVU5928
	.loc 1 32149 9 view .LVU5929
	.loc 1 32147 11 is_stmt 0 view .LVU5930
	mulss	%xmm1, %xmm3
.LVL1528:
	.loc 1 32149 22 view .LVU5931
	cvttss2sil	%xmm3, %edx
	movw	%dx, (%rdi,%rax,2)
.LBE4259:
	.loc 1 32143 5 is_stmt 1 view .LVU5932
	.loc 1 32143 25 is_stmt 0 view .LVU5933
	leaq	3(%r12), %rax
.LVL1529:
	.loc 1 32143 25 view .LVU5934
.LBE4287:
	.loc 1 32143 5 is_stmt 1 view .LVU5935
.LBB4288:
	.loc 1 32143 14 view .LVU5936
	cmpq	%rax, %r8
	jbe	.L1050
.LBB4260:
	.loc 1 32144 9 view .LVU5937
.LVL1530:
	.loc 1 32145 9 view .LVU5938
.LBB4231:
	.loc 1 2528 24 view .LVU5939
.LBE4231:
.LBE4260:
.LBE4288:
.LBE4351:
.LBE4408:
.LBE5003:
	.loc 1 2530 5 view .LVU5940
	.loc 1 2533 5 view .LVU5941
.LBB5004:
.LBB4409:
.LBB4352:
.LBB4289:
.LBB4261:
	.loc 1 32146 9 view .LVU5942
	.loc 1 32146 23 is_stmt 0 view .LVU5943
	movss	(%rbx,%rax,4), %xmm3
	minss	%xmm0, %xmm3
	maxss	%xmm2, %xmm3
.LVL1531:
	.loc 1 32147 9 is_stmt 1 view .LVU5944
	.loc 1 32149 9 view .LVU5945
	.loc 1 32147 11 is_stmt 0 view .LVU5946
	mulss	%xmm1, %xmm3
.LVL1532:
	.loc 1 32149 22 view .LVU5947
	cvttss2sil	%xmm3, %edx
	movw	%dx, (%rdi,%rax,2)
.LBE4261:
	.loc 1 32143 5 is_stmt 1 view .LVU5948
	.loc 1 32143 25 is_stmt 0 view .LVU5949
	leaq	4(%r12), %rax
.LVL1533:
	.loc 1 32143 25 view .LVU5950
.LBE4289:
	.loc 1 32143 5 is_stmt 1 view .LVU5951
.LBB4290:
	.loc 1 32143 14 view .LVU5952
	cmpq	%rax, %r8
	jbe	.L1050
.LBB4262:
	.loc 1 32144 9 view .LVU5953
.LVL1534:
	.loc 1 32145 9 view .LVU5954
.LBB4232:
	.loc 1 2528 24 view .LVU5955
.LBE4232:
.LBE4262:
.LBE4290:
.LBE4352:
.LBE4409:
.LBE5004:
	.loc 1 2530 5 view .LVU5956
	.loc 1 2533 5 view .LVU5957
.LBB5005:
.LBB4410:
.LBB4353:
.LBB4291:
.LBB4263:
	.loc 1 32146 9 view .LVU5958
	.loc 1 32146 23 is_stmt 0 view .LVU5959
	movss	(%rbx,%rax,4), %xmm3
	minss	%xmm0, %xmm3
	maxss	%xmm2, %xmm3
.LVL1535:
	.loc 1 32147 9 is_stmt 1 view .LVU5960
	.loc 1 32149 9 view .LVU5961
	.loc 1 32147 11 is_stmt 0 view .LVU5962
	mulss	%xmm1, %xmm3
.LVL1536:
	.loc 1 32149 22 view .LVU5963
	cvttss2sil	%xmm3, %edx
	movw	%dx, (%rdi,%rax,2)
.LBE4263:
	.loc 1 32143 5 is_stmt 1 view .LVU5964
	.loc 1 32143 25 is_stmt 0 view .LVU5965
	leaq	5(%r12), %rax
.LVL1537:
	.loc 1 32143 25 view .LVU5966
.LBE4291:
	.loc 1 32143 5 is_stmt 1 view .LVU5967
.LBB4292:
	.loc 1 32143 14 view .LVU5968
	cmpq	%rax, %r8
	jbe	.L1050
.LBB4264:
	.loc 1 32144 9 view .LVU5969
.LVL1538:
	.loc 1 32145 9 view .LVU5970
.LBB4233:
	.loc 1 2528 24 view .LVU5971
.LBE4233:
.LBE4264:
.LBE4292:
.LBE4353:
.LBE4410:
.LBE5005:
	.loc 1 2530 5 view .LVU5972
	.loc 1 2533 5 view .LVU5973
.LBB5006:
.LBB4411:
.LBB4354:
.LBB4293:
.LBB4265:
	.loc 1 32146 9 view .LVU5974
	.loc 1 32146 23 is_stmt 0 view .LVU5975
	movss	(%rbx,%rax,4), %xmm3
.LBE4265:
	.loc 1 32143 25 view .LVU5976
	addq	$6, %r12
.LBB4266:
	.loc 1 32146 23 view .LVU5977
	minss	%xmm0, %xmm3
	maxss	%xmm2, %xmm3
.LVL1539:
	.loc 1 32147 9 is_stmt 1 view .LVU5978
	.loc 1 32149 9 view .LVU5979
	.loc 1 32147 11 is_stmt 0 view .LVU5980
	mulss	%xmm1, %xmm3
.LVL1540:
	.loc 1 32149 22 view .LVU5981
	cvttss2sil	%xmm3, %edx
	movw	%dx, (%rdi,%rax,2)
.LBE4266:
	.loc 1 32143 5 is_stmt 1 view .LVU5982
.LVL1541:
	.loc 1 32143 5 is_stmt 0 view .LVU5983
.LBE4293:
	.loc 1 32143 5 is_stmt 1 view .LVU5984
.LBB4294:
	.loc 1 32143 14 view .LVU5985
	cmpq	%r12, %r8
	jbe	.L1050
.LBB4267:
	.loc 1 32144 9 view .LVU5986
.LVL1542:
	.loc 1 32145 9 view .LVU5987
.LBB4234:
	.loc 1 2528 24 view .LVU5988
.LBE4234:
.LBE4267:
.LBE4294:
.LBE4354:
.LBE4411:
.LBE5006:
	.loc 1 2530 5 view .LVU5989
	.loc 1 2533 5 view .LVU5990
.LBB5007:
.LBB4412:
.LBB4355:
.LBB4295:
.LBB4268:
	.loc 1 32146 9 view .LVU5991
	.loc 1 32146 23 is_stmt 0 view .LVU5992
	minss	(%rbx,%r12,4), %xmm0
	maxss	%xmm2, %xmm0
.LVL1543:
	.loc 1 32147 9 is_stmt 1 view .LVU5993
	.loc 1 32149 9 view .LVU5994
	.loc 1 32147 11 is_stmt 0 view .LVU5995
	mulss	%xmm1, %xmm0
.LVL1544:
	.loc 1 32149 22 view .LVU5996
	cvttss2sil	%xmm0, %eax
	movw	%ax, (%rdi,%r12,2)
.LBE4268:
	.loc 1 32143 5 is_stmt 1 view .LVU5997
	.loc 1 32143 5 is_stmt 0 view .LVU5998
.LBE4295:
	.loc 1 32143 5 is_stmt 1 view .LVU5999
.LBB4296:
	.loc 1 32143 14 view .LVU6000
	jmp	.L1050
.LVL1545:
	.p2align 4,,10
	.p2align 3
.L1204:
	.loc 1 32143 14 is_stmt 0 view .LVU6001
.LBE4296:
.LBE4355:
.LBE4412:
.LBE5007:
.LBB5008:
.LBB5009:
.LBB5010:
.LBB5011:
.LBB5012:
	.loc 1 32508 19 view .LVU6002
	testq	%r8, %r8
	je	.L1050
	leaq	(%r8,%r8,2), %rdx
.LVL1546:
	.loc 1 32508 19 view .LVU6003
	movss	.LC77(%rip), %xmm0
	movss	.LC88(%rip), %xmm3
	movss	.LC111(%rip), %xmm2
	addq	%rdi, %rdx
.LVL1547:
	.p2align 4,,10
	.p2align 3
.L1281:
.LBB5013:
	.loc 1 32511 23 view .LVU6004
	movss	(%rbx), %xmm1
.LBE5013:
	.loc 1 32508 19 view .LVU6005
	addq	$3, %rdi
	addq	$4, %rbx
.LVL1548:
.LBB5014:
	.loc 1 32511 23 view .LVU6006
	minss	%xmm0, %xmm1
.LVL1549:
	.loc 1 32511 23 view .LVU6007
	maxss	%xmm3, %xmm1
.LVL1550:
	.loc 1 32520 11 view .LVU6008
	mulss	%xmm2, %xmm1
.LVL1551:
	.loc 1 32523 11 view .LVU6009
	cvttss2sil	%xmm1, %eax
.LVL1552:
	.loc 1 32524 26 view .LVU6010
	movb	%al, -3(%rdi)
.LVL1553:
	.loc 1 32525 26 view .LVU6011
	movb	%ah, -2(%rdi)
	.loc 1 32526 54 view .LVU6012
	sarl	$16, %eax
.LVL1554:
	.loc 1 32526 26 view .LVU6013
	movb	%al, -1(%rdi)
.LBE5014:
	.loc 1 32508 19 view .LVU6014
	cmpq	%rdx, %rdi
	jne	.L1281
	jmp	.L1050
.LVL1555:
	.p2align 4,,10
	.p2align 3
.L1063:
	.loc 1 32508 19 view .LVU6015
.LBE5012:
.LBE5011:
.LBE5010:
.LBE5009:
.LBE5008:
.LBB5015:
.LBB5016:
.LBB5017:
.LBB5018:
.LBB5019:
	.loc 1 30564 19 is_stmt 1 view .LVU6016
	testq	%r8, %r8
	je	.L1050
	leaq	(%rdi,%r8,2), %rax
	cmpq	%rax, %rdx
	leaq	(%rbx,%r8), %rax
	setnb	%dl
.LVL1556:
	.loc 1 30564 19 is_stmt 0 view .LVU6017
	cmpq	%rax, %rdi
	setnb	%al
	orb	%al, %dl
	je	.L1287
	leaq	-1(%r8), %rax
	cmpq	$14, %rax
	jbe	.L1287
	movq	%r8, %rdx
	movdqa	.LC93(%rip), %xmm3
	xorl	%eax, %eax
.LBB5020:
	.loc 1 30566 26 view .LVU6018
	pxor	%xmm2, %xmm2
	andq	$-16, %rdx
.LVL1557:
	.p2align 4,,10
	.p2align 3
.L1068:
	.loc 1 30565 9 is_stmt 1 view .LVU6019
	.loc 1 30565 30 is_stmt 0 view .LVU6020
	movdqu	(%rbx,%rax), %xmm0
.LVL1558:
	.loc 1 30566 9 is_stmt 1 view .LVU6021
	.loc 1 30567 9 view .LVU6022
	.loc 1 30568 9 view .LVU6023
	.loc 1 30566 26 is_stmt 0 view .LVU6024
	movdqa	%xmm0, %xmm1
	punpckhbw	%xmm2, %xmm0
	punpcklbw	%xmm2, %xmm1
	paddw	%xmm3, %xmm0
	paddw	%xmm3, %xmm1
	.loc 1 30567 26 view .LVU6025
	psllw	$8, %xmm0
	psllw	$8, %xmm1
	.loc 1 30568 20 view .LVU6026
	movups	%xmm0, 16(%rdi,%rax,2)
	.loc 1 30568 20 view .LVU6027
.LBE5020:
	.loc 1 30564 5 is_stmt 1 view .LVU6028
	.loc 1 30564 19 view .LVU6029
.LBB5021:
	.loc 1 30568 20 is_stmt 0 view .LVU6030
	movups	%xmm1, (%rdi,%rax,2)
	addq	$16, %rax
	cmpq	%rax, %rdx
	jne	.L1068
	movq	%r8, %rdx
	andq	$-16, %rdx
	testb	$15, %r8b
	je	.L1050
.LVL1559:
	.loc 1 30565 9 is_stmt 1 view .LVU6031
	.loc 1 30566 9 view .LVU6032
	.loc 1 30567 9 view .LVU6033
	.loc 1 30566 26 is_stmt 0 view .LVU6034
	movzbl	(%rbx,%rdx), %eax
.LBE5021:
	.loc 1 30564 30 view .LVU6035
	leaq	1(%rdx), %rcx
.LBB5022:
	.loc 1 30566 26 view .LVU6036
	addl	$-128, %eax
	.loc 1 30567 24 view .LVU6037
	cwtl
	.loc 1 30567 26 view .LVU6038
	sall	$8, %eax
.LVL1560:
	.loc 1 30568 9 is_stmt 1 view .LVU6039
	.loc 1 30567 11 is_stmt 0 view .LVU6040
	movw	%ax, (%rdi,%rdx,2)
.LBE5022:
	.loc 1 30564 5 is_stmt 1 view .LVU6041
.LVL1561:
	.loc 1 30564 19 view .LVU6042
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB5023:
	.loc 1 30565 9 view .LVU6043
.LVL1562:
	.loc 1 30566 9 view .LVU6044
	.loc 1 30567 9 view .LVU6045
	.loc 1 30566 26 is_stmt 0 view .LVU6046
	movzbl	1(%rbx,%rdx), %eax
	addl	$-128, %eax
	.loc 1 30567 24 view .LVU6047
	cwtl
	.loc 1 30567 26 view .LVU6048
	sall	$8, %eax
.LVL1563:
	.loc 1 30568 9 is_stmt 1 view .LVU6049
	.loc 1 30567 11 is_stmt 0 view .LVU6050
	movw	%ax, (%rdi,%rcx,2)
.LBE5023:
	.loc 1 30564 5 is_stmt 1 view .LVU6051
	.loc 1 30564 30 is_stmt 0 view .LVU6052
	leaq	2(%rdx), %rcx
.LVL1564:
	.loc 1 30564 19 is_stmt 1 view .LVU6053
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB5024:
	.loc 1 30565 9 view .LVU6054
.LVL1565:
	.loc 1 30566 9 view .LVU6055
	.loc 1 30567 9 view .LVU6056
	.loc 1 30566 26 is_stmt 0 view .LVU6057
	movzbl	2(%rbx,%rdx), %eax
	addl	$-128, %eax
	.loc 1 30567 24 view .LVU6058
	cwtl
	.loc 1 30567 26 view .LVU6059
	sall	$8, %eax
.LVL1566:
	.loc 1 30568 9 is_stmt 1 view .LVU6060
	.loc 1 30567 11 is_stmt 0 view .LVU6061
	movw	%ax, (%rdi,%rcx,2)
.LBE5024:
	.loc 1 30564 5 is_stmt 1 view .LVU6062
	.loc 1 30564 30 is_stmt 0 view .LVU6063
	leaq	3(%rdx), %rcx
.LVL1567:
	.loc 1 30564 19 is_stmt 1 view .LVU6064
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB5025:
	.loc 1 30565 9 view .LVU6065
.LVL1568:
	.loc 1 30566 9 view .LVU6066
	.loc 1 30567 9 view .LVU6067
	.loc 1 30566 26 is_stmt 0 view .LVU6068
	movzbl	3(%rbx,%rdx), %eax
	addl	$-128, %eax
	.loc 1 30567 24 view .LVU6069
	cwtl
	.loc 1 30567 26 view .LVU6070
	sall	$8, %eax
.LVL1569:
	.loc 1 30568 9 is_stmt 1 view .LVU6071
	.loc 1 30567 11 is_stmt 0 view .LVU6072
	movw	%ax, (%rdi,%rcx,2)
.LBE5025:
	.loc 1 30564 5 is_stmt 1 view .LVU6073
	.loc 1 30564 30 is_stmt 0 view .LVU6074
	leaq	4(%rdx), %rcx
.LVL1570:
	.loc 1 30564 19 is_stmt 1 view .LVU6075
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB5026:
	.loc 1 30565 9 view .LVU6076
.LVL1571:
	.loc 1 30566 9 view .LVU6077
	.loc 1 30567 9 view .LVU6078
	.loc 1 30566 26 is_stmt 0 view .LVU6079
	movzbl	4(%rbx,%rdx), %eax
	addl	$-128, %eax
	.loc 1 30567 24 view .LVU6080
	cwtl
	.loc 1 30567 26 view .LVU6081
	sall	$8, %eax
.LVL1572:
	.loc 1 30568 9 is_stmt 1 view .LVU6082
	.loc 1 30567 11 is_stmt 0 view .LVU6083
	movw	%ax, (%rdi,%rcx,2)
.LBE5026:
	.loc 1 30564 5 is_stmt 1 view .LVU6084
	.loc 1 30564 30 is_stmt 0 view .LVU6085
	leaq	5(%rdx), %rcx
.LVL1573:
	.loc 1 30564 19 is_stmt 1 view .LVU6086
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB5027:
	.loc 1 30565 9 view .LVU6087
.LVL1574:
	.loc 1 30566 9 view .LVU6088
	.loc 1 30567 9 view .LVU6089
	.loc 1 30566 26 is_stmt 0 view .LVU6090
	movzbl	5(%rbx,%rdx), %eax
	addl	$-128, %eax
	.loc 1 30567 24 view .LVU6091
	cwtl
	.loc 1 30567 26 view .LVU6092
	sall	$8, %eax
.LVL1575:
	.loc 1 30568 9 is_stmt 1 view .LVU6093
	.loc 1 30567 11 is_stmt 0 view .LVU6094
	movw	%ax, (%rdi,%rcx,2)
.LBE5027:
	.loc 1 30564 5 is_stmt 1 view .LVU6095
	.loc 1 30564 30 is_stmt 0 view .LVU6096
	leaq	6(%rdx), %rcx
.LVL1576:
	.loc 1 30564 19 is_stmt 1 view .LVU6097
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB5028:
	.loc 1 30565 9 view .LVU6098
.LVL1577:
	.loc 1 30566 9 view .LVU6099
	.loc 1 30567 9 view .LVU6100
	.loc 1 30566 26 is_stmt 0 view .LVU6101
	movzbl	6(%rbx,%rdx), %eax
	addl	$-128, %eax
	.loc 1 30567 24 view .LVU6102
	cwtl
	.loc 1 30567 26 view .LVU6103
	sall	$8, %eax
.LVL1578:
	.loc 1 30568 9 is_stmt 1 view .LVU6104
	.loc 1 30567 11 is_stmt 0 view .LVU6105
	movw	%ax, (%rdi,%rcx,2)
.LBE5028:
	.loc 1 30564 5 is_stmt 1 view .LVU6106
	.loc 1 30564 30 is_stmt 0 view .LVU6107
	leaq	7(%rdx), %rcx
.LVL1579:
	.loc 1 30564 19 is_stmt 1 view .LVU6108
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB5029:
	.loc 1 30565 9 view .LVU6109
.LVL1580:
	.loc 1 30566 9 view .LVU6110
	.loc 1 30567 9 view .LVU6111
	.loc 1 30566 26 is_stmt 0 view .LVU6112
	movzbl	7(%rbx,%rdx), %eax
	addl	$-128, %eax
	.loc 1 30567 24 view .LVU6113
	cwtl
	.loc 1 30567 26 view .LVU6114
	sall	$8, %eax
.LVL1581:
	.loc 1 30568 9 is_stmt 1 view .LVU6115
	.loc 1 30567 11 is_stmt 0 view .LVU6116
	movw	%ax, (%rdi,%rcx,2)
.LBE5029:
	.loc 1 30564 5 is_stmt 1 view .LVU6117
	.loc 1 30564 30 is_stmt 0 view .LVU6118
	leaq	8(%rdx), %rcx
.LVL1582:
	.loc 1 30564 19 is_stmt 1 view .LVU6119
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB5030:
	.loc 1 30565 9 view .LVU6120
.LVL1583:
	.loc 1 30566 9 view .LVU6121
	.loc 1 30567 9 view .LVU6122
	.loc 1 30566 26 is_stmt 0 view .LVU6123
	movzbl	8(%rbx,%rdx), %eax
	addl	$-128, %eax
	.loc 1 30567 24 view .LVU6124
	cwtl
	.loc 1 30567 26 view .LVU6125
	sall	$8, %eax
.LVL1584:
	.loc 1 30568 9 is_stmt 1 view .LVU6126
	.loc 1 30567 11 is_stmt 0 view .LVU6127
	movw	%ax, (%rdi,%rcx,2)
.LBE5030:
	.loc 1 30564 5 is_stmt 1 view .LVU6128
	.loc 1 30564 30 is_stmt 0 view .LVU6129
	leaq	9(%rdx), %rcx
.LVL1585:
	.loc 1 30564 19 is_stmt 1 view .LVU6130
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB5031:
	.loc 1 30565 9 view .LVU6131
.LVL1586:
	.loc 1 30566 9 view .LVU6132
	.loc 1 30567 9 view .LVU6133
	.loc 1 30566 26 is_stmt 0 view .LVU6134
	movzbl	9(%rbx,%rdx), %eax
	addl	$-128, %eax
	.loc 1 30567 24 view .LVU6135
	cwtl
	.loc 1 30567 26 view .LVU6136
	sall	$8, %eax
.LVL1587:
	.loc 1 30568 9 is_stmt 1 view .LVU6137
	.loc 1 30567 11 is_stmt 0 view .LVU6138
	movw	%ax, (%rdi,%rcx,2)
.LBE5031:
	.loc 1 30564 5 is_stmt 1 view .LVU6139
	.loc 1 30564 30 is_stmt 0 view .LVU6140
	leaq	10(%rdx), %rcx
.LVL1588:
	.loc 1 30564 19 is_stmt 1 view .LVU6141
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB5032:
	.loc 1 30565 9 view .LVU6142
.LVL1589:
	.loc 1 30566 9 view .LVU6143
	.loc 1 30567 9 view .LVU6144
	.loc 1 30566 26 is_stmt 0 view .LVU6145
	movzbl	10(%rbx,%rdx), %eax
	addl	$-128, %eax
	.loc 1 30567 24 view .LVU6146
	cwtl
	.loc 1 30567 26 view .LVU6147
	sall	$8, %eax
.LVL1590:
	.loc 1 30568 9 is_stmt 1 view .LVU6148
	.loc 1 30567 11 is_stmt 0 view .LVU6149
	movw	%ax, (%rdi,%rcx,2)
.LBE5032:
	.loc 1 30564 5 is_stmt 1 view .LVU6150
	.loc 1 30564 30 is_stmt 0 view .LVU6151
	leaq	11(%rdx), %rcx
.LVL1591:
	.loc 1 30564 19 is_stmt 1 view .LVU6152
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB5033:
	.loc 1 30565 9 view .LVU6153
.LVL1592:
	.loc 1 30566 9 view .LVU6154
	.loc 1 30567 9 view .LVU6155
	.loc 1 30566 26 is_stmt 0 view .LVU6156
	movzbl	11(%rbx,%rdx), %eax
	addl	$-128, %eax
	.loc 1 30567 24 view .LVU6157
	cwtl
	.loc 1 30567 26 view .LVU6158
	sall	$8, %eax
.LVL1593:
	.loc 1 30568 9 is_stmt 1 view .LVU6159
	.loc 1 30567 11 is_stmt 0 view .LVU6160
	movw	%ax, (%rdi,%rcx,2)
.LBE5033:
	.loc 1 30564 5 is_stmt 1 view .LVU6161
	.loc 1 30564 30 is_stmt 0 view .LVU6162
	leaq	12(%rdx), %rcx
.LVL1594:
	.loc 1 30564 19 is_stmt 1 view .LVU6163
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB5034:
	.loc 1 30565 9 view .LVU6164
.LVL1595:
	.loc 1 30566 9 view .LVU6165
	.loc 1 30567 9 view .LVU6166
	.loc 1 30566 26 is_stmt 0 view .LVU6167
	movzbl	12(%rbx,%rdx), %eax
	addl	$-128, %eax
	.loc 1 30567 24 view .LVU6168
	cwtl
	.loc 1 30567 26 view .LVU6169
	sall	$8, %eax
.LVL1596:
	.loc 1 30568 9 is_stmt 1 view .LVU6170
	.loc 1 30567 11 is_stmt 0 view .LVU6171
	movw	%ax, (%rdi,%rcx,2)
.LBE5034:
	.loc 1 30564 5 is_stmt 1 view .LVU6172
	.loc 1 30564 30 is_stmt 0 view .LVU6173
	leaq	13(%rdx), %rcx
.LVL1597:
	.loc 1 30564 19 is_stmt 1 view .LVU6174
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB5035:
	.loc 1 30565 9 view .LVU6175
.LVL1598:
	.loc 1 30566 9 view .LVU6176
	.loc 1 30567 9 view .LVU6177
	.loc 1 30566 26 is_stmt 0 view .LVU6178
	movzbl	13(%rbx,%rdx), %eax
	addl	$-128, %eax
	.loc 1 30567 24 view .LVU6179
	cwtl
	.loc 1 30567 26 view .LVU6180
	sall	$8, %eax
.LVL1599:
	.loc 1 30568 9 is_stmt 1 view .LVU6181
	.loc 1 30567 11 is_stmt 0 view .LVU6182
	movw	%ax, (%rdi,%rcx,2)
.LBE5035:
	.loc 1 30564 5 is_stmt 1 view .LVU6183
	.loc 1 30564 30 is_stmt 0 view .LVU6184
	leaq	14(%rdx), %rcx
.LVL1600:
	.loc 1 30564 19 is_stmt 1 view .LVU6185
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB5036:
	.loc 1 30565 9 view .LVU6186
.LVL1601:
	.loc 1 30566 9 view .LVU6187
	.loc 1 30567 9 view .LVU6188
	.loc 1 30566 26 is_stmt 0 view .LVU6189
	movzbl	14(%rbx,%rdx), %eax
	addl	$-128, %eax
	.loc 1 30567 24 view .LVU6190
	cwtl
	.loc 1 30567 26 view .LVU6191
	sall	$8, %eax
.LVL1602:
	.loc 1 30568 9 is_stmt 1 view .LVU6192
	.loc 1 30567 11 is_stmt 0 view .LVU6193
	movw	%ax, (%rdi,%rcx,2)
.LBE5036:
	.loc 1 30564 5 is_stmt 1 view .LVU6194
.LVL1603:
	.loc 1 30564 19 view .LVU6195
	jmp	.L1050
.LVL1604:
	.p2align 4,,10
	.p2align 3
.L1084:
	.loc 1 30564 19 is_stmt 0 view .LVU6196
.LBE5019:
.LBE5018:
.LBE5017:
.LBE5016:
.LBE5015:
	.loc 1 32747 17 is_stmt 1 view .LVU6197
	.loc 1 32747 37 view .LVU6198
.LBB5042:
.LBI5042:
	.loc 1 30958 13 view .LVU6199
.LBE5042:
	.loc 1 30976 9 view .LVU6200
	.loc 1 30977 13 view .LVU6201
.LBB5378:
.LBB5043:
.LBI5043:
	.loc 1 30934 23 view .LVU6202
.LBE5043:
.LBE5378:
	.loc 1 30936 5 view .LVU6203
.LBB5379:
.LBB5071:
.LBB5044:
.LBI5044:
	.loc 1 30901 23 view .LVU6204
.LBB5045:
	.loc 1 30903 5 view .LVU6205
	.loc 1 30904 5 view .LVU6206
	.loc 1 30906 5 view .LVU6207
.LBB5046:
	testl	%r9d, %r9d
	jne	.L1087
.LVL1605:
.LBB5047:
.LBB5048:
	.loc 1 30908 23 view .LVU6208
	testq	%r8, %r8
	je	.L1050
	leaq	(%rdx,%r8,2), %rax
	cmpq	%rax, %rdi
	leaq	(%rdi,%r8), %rax
	setnb	%dl
.LVL1606:
	.loc 1 30908 23 is_stmt 0 view .LVU6209
	cmpq	%rax, %rbx
	setnb	%al
	orb	%al, %dl
	je	.L1290
	leaq	-1(%r8), %rax
	cmpq	$14, %rax
	jbe	.L1290
	movq	%r8, %rdx
	movdqa	.LC83(%rip), %xmm2
	movdqa	.LC76(%rip), %xmm3
	xorl	%eax, %eax
	andq	$-16, %rdx
.LVL1607:
	.p2align 4,,10
	.p2align 3
.L1090:
.LBB5049:
	.loc 1 30909 13 is_stmt 1 view .LVU6210
	.loc 1 30910 13 view .LVU6211
	.loc 1 30911 13 view .LVU6212
	.loc 1 30912 13 view .LVU6213
	.loc 1 30910 15 is_stmt 0 view .LVU6214
	movdqu	(%rbx,%rax,2), %xmm0
	movdqu	16(%rbx,%rax,2), %xmm1
	psraw	$8, %xmm0
	psraw	$8, %xmm1
	.loc 1 30911 30 view .LVU6215
	pand	%xmm3, %xmm0
	pand	%xmm3, %xmm1
	packuswb	%xmm1, %xmm0
	paddb	%xmm2, %xmm0
	.loc 1 30912 23 view .LVU6216
	movups	%xmm0, (%rdi,%rax)
	.loc 1 30912 23 view .LVU6217
.LBE5049:
	.loc 1 30908 9 is_stmt 1 view .LVU6218
	.loc 1 30908 23 view .LVU6219
	addq	$16, %rax
	cmpq	%rax, %rdx
	jne	.L1090
	movq	%r8, %rax
	andq	$-16, %rax
	testb	$15, %r8b
	je	.L1050
.LVL1608:
.LBB5050:
	.loc 1 30909 13 view .LVU6220
	.loc 1 30910 13 view .LVU6221
	.loc 1 30911 13 view .LVU6222
	.loc 1 30912 13 view .LVU6223
	.loc 1 30910 15 is_stmt 0 view .LVU6224
	movsbw	1(%rbx,%rax,2), %dx
	.loc 1 30911 30 view .LVU6225
	subw	$-128, %dx
	.loc 1 30912 23 view .LVU6226
	movb	%dl, (%rdi,%rax)
.LVL1609:
	.loc 1 30912 23 view .LVU6227
.LBE5050:
	.loc 1 30908 9 is_stmt 1 view .LVU6228
	.loc 1 30908 34 is_stmt 0 view .LVU6229
	leaq	1(%rax), %rdx
.LVL1610:
	.loc 1 30908 23 is_stmt 1 view .LVU6230
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5051:
	.loc 1 30909 13 view .LVU6231
.LVL1611:
	.loc 1 30910 13 view .LVU6232
	.loc 1 30911 13 view .LVU6233
	.loc 1 30912 13 view .LVU6234
	.loc 1 30910 15 is_stmt 0 view .LVU6235
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1612:
	.loc 1 30911 30 view .LVU6236
	subw	$-128, %dx
	.loc 1 30912 23 view .LVU6237
	movb	%dl, 1(%rdi,%rax)
.LVL1613:
	.loc 1 30912 23 view .LVU6238
.LBE5051:
	.loc 1 30908 9 is_stmt 1 view .LVU6239
	.loc 1 30908 34 is_stmt 0 view .LVU6240
	leaq	2(%rax), %rdx
.LVL1614:
	.loc 1 30908 23 is_stmt 1 view .LVU6241
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5052:
	.loc 1 30909 13 view .LVU6242
.LVL1615:
	.loc 1 30910 13 view .LVU6243
	.loc 1 30911 13 view .LVU6244
	.loc 1 30912 13 view .LVU6245
	.loc 1 30910 15 is_stmt 0 view .LVU6246
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1616:
	.loc 1 30911 30 view .LVU6247
	subw	$-128, %dx
	.loc 1 30912 23 view .LVU6248
	movb	%dl, 2(%rdi,%rax)
.LVL1617:
	.loc 1 30912 23 view .LVU6249
.LBE5052:
	.loc 1 30908 9 is_stmt 1 view .LVU6250
	.loc 1 30908 34 is_stmt 0 view .LVU6251
	leaq	3(%rax), %rdx
.LVL1618:
	.loc 1 30908 23 is_stmt 1 view .LVU6252
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5053:
	.loc 1 30909 13 view .LVU6253
.LVL1619:
	.loc 1 30910 13 view .LVU6254
	.loc 1 30911 13 view .LVU6255
	.loc 1 30912 13 view .LVU6256
	.loc 1 30910 15 is_stmt 0 view .LVU6257
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1620:
	.loc 1 30911 30 view .LVU6258
	subw	$-128, %dx
	.loc 1 30912 23 view .LVU6259
	movb	%dl, 3(%rdi,%rax)
.LVL1621:
	.loc 1 30912 23 view .LVU6260
.LBE5053:
	.loc 1 30908 9 is_stmt 1 view .LVU6261
	.loc 1 30908 34 is_stmt 0 view .LVU6262
	leaq	4(%rax), %rdx
.LVL1622:
	.loc 1 30908 23 is_stmt 1 view .LVU6263
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5054:
	.loc 1 30909 13 view .LVU6264
.LVL1623:
	.loc 1 30910 13 view .LVU6265
	.loc 1 30911 13 view .LVU6266
	.loc 1 30912 13 view .LVU6267
	.loc 1 30910 15 is_stmt 0 view .LVU6268
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1624:
	.loc 1 30911 30 view .LVU6269
	subw	$-128, %dx
	.loc 1 30912 23 view .LVU6270
	movb	%dl, 4(%rdi,%rax)
.LVL1625:
	.loc 1 30912 23 view .LVU6271
.LBE5054:
	.loc 1 30908 9 is_stmt 1 view .LVU6272
	.loc 1 30908 34 is_stmt 0 view .LVU6273
	leaq	5(%rax), %rdx
.LVL1626:
	.loc 1 30908 23 is_stmt 1 view .LVU6274
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5055:
	.loc 1 30909 13 view .LVU6275
.LVL1627:
	.loc 1 30910 13 view .LVU6276
	.loc 1 30911 13 view .LVU6277
	.loc 1 30912 13 view .LVU6278
	.loc 1 30910 15 is_stmt 0 view .LVU6279
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1628:
	.loc 1 30911 30 view .LVU6280
	subw	$-128, %dx
	.loc 1 30912 23 view .LVU6281
	movb	%dl, 5(%rdi,%rax)
.LVL1629:
	.loc 1 30912 23 view .LVU6282
.LBE5055:
	.loc 1 30908 9 is_stmt 1 view .LVU6283
	.loc 1 30908 34 is_stmt 0 view .LVU6284
	leaq	6(%rax), %rdx
.LVL1630:
	.loc 1 30908 23 is_stmt 1 view .LVU6285
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5056:
	.loc 1 30909 13 view .LVU6286
.LVL1631:
	.loc 1 30910 13 view .LVU6287
	.loc 1 30911 13 view .LVU6288
	.loc 1 30912 13 view .LVU6289
	.loc 1 30910 15 is_stmt 0 view .LVU6290
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1632:
	.loc 1 30911 30 view .LVU6291
	subw	$-128, %dx
	.loc 1 30912 23 view .LVU6292
	movb	%dl, 6(%rdi,%rax)
.LVL1633:
	.loc 1 30912 23 view .LVU6293
.LBE5056:
	.loc 1 30908 9 is_stmt 1 view .LVU6294
	.loc 1 30908 34 is_stmt 0 view .LVU6295
	leaq	7(%rax), %rdx
.LVL1634:
	.loc 1 30908 23 is_stmt 1 view .LVU6296
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5057:
	.loc 1 30909 13 view .LVU6297
.LVL1635:
	.loc 1 30910 13 view .LVU6298
	.loc 1 30911 13 view .LVU6299
	.loc 1 30912 13 view .LVU6300
	.loc 1 30910 15 is_stmt 0 view .LVU6301
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1636:
	.loc 1 30911 30 view .LVU6302
	subw	$-128, %dx
	.loc 1 30912 23 view .LVU6303
	movb	%dl, 7(%rdi,%rax)
.LVL1637:
	.loc 1 30912 23 view .LVU6304
.LBE5057:
	.loc 1 30908 9 is_stmt 1 view .LVU6305
	.loc 1 30908 34 is_stmt 0 view .LVU6306
	leaq	8(%rax), %rdx
.LVL1638:
	.loc 1 30908 23 is_stmt 1 view .LVU6307
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5058:
	.loc 1 30909 13 view .LVU6308
.LVL1639:
	.loc 1 30910 13 view .LVU6309
	.loc 1 30911 13 view .LVU6310
	.loc 1 30912 13 view .LVU6311
	.loc 1 30910 15 is_stmt 0 view .LVU6312
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1640:
	.loc 1 30911 30 view .LVU6313
	subw	$-128, %dx
	.loc 1 30912 23 view .LVU6314
	movb	%dl, 8(%rdi,%rax)
.LVL1641:
	.loc 1 30912 23 view .LVU6315
.LBE5058:
	.loc 1 30908 9 is_stmt 1 view .LVU6316
	.loc 1 30908 34 is_stmt 0 view .LVU6317
	leaq	9(%rax), %rdx
.LVL1642:
	.loc 1 30908 23 is_stmt 1 view .LVU6318
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5059:
	.loc 1 30909 13 view .LVU6319
.LVL1643:
	.loc 1 30910 13 view .LVU6320
	.loc 1 30911 13 view .LVU6321
	.loc 1 30912 13 view .LVU6322
	.loc 1 30910 15 is_stmt 0 view .LVU6323
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1644:
	.loc 1 30911 30 view .LVU6324
	subw	$-128, %dx
	.loc 1 30912 23 view .LVU6325
	movb	%dl, 9(%rdi,%rax)
.LVL1645:
	.loc 1 30912 23 view .LVU6326
.LBE5059:
	.loc 1 30908 9 is_stmt 1 view .LVU6327
	.loc 1 30908 34 is_stmt 0 view .LVU6328
	leaq	10(%rax), %rdx
.LVL1646:
	.loc 1 30908 23 is_stmt 1 view .LVU6329
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5060:
	.loc 1 30909 13 view .LVU6330
.LVL1647:
	.loc 1 30910 13 view .LVU6331
	.loc 1 30911 13 view .LVU6332
	.loc 1 30912 13 view .LVU6333
	.loc 1 30910 15 is_stmt 0 view .LVU6334
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1648:
	.loc 1 30911 30 view .LVU6335
	subw	$-128, %dx
	.loc 1 30912 23 view .LVU6336
	movb	%dl, 10(%rdi,%rax)
.LVL1649:
	.loc 1 30912 23 view .LVU6337
.LBE5060:
	.loc 1 30908 9 is_stmt 1 view .LVU6338
	.loc 1 30908 34 is_stmt 0 view .LVU6339
	leaq	11(%rax), %rdx
.LVL1650:
	.loc 1 30908 23 is_stmt 1 view .LVU6340
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5061:
	.loc 1 30909 13 view .LVU6341
.LVL1651:
	.loc 1 30910 13 view .LVU6342
	.loc 1 30911 13 view .LVU6343
	.loc 1 30912 13 view .LVU6344
	.loc 1 30910 15 is_stmt 0 view .LVU6345
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1652:
	.loc 1 30911 30 view .LVU6346
	subw	$-128, %dx
	.loc 1 30912 23 view .LVU6347
	movb	%dl, 11(%rdi,%rax)
.LVL1653:
	.loc 1 30912 23 view .LVU6348
.LBE5061:
	.loc 1 30908 9 is_stmt 1 view .LVU6349
	.loc 1 30908 34 is_stmt 0 view .LVU6350
	leaq	12(%rax), %rdx
.LVL1654:
	.loc 1 30908 23 is_stmt 1 view .LVU6351
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5062:
	.loc 1 30909 13 view .LVU6352
.LVL1655:
	.loc 1 30910 13 view .LVU6353
	.loc 1 30911 13 view .LVU6354
	.loc 1 30912 13 view .LVU6355
	.loc 1 30910 15 is_stmt 0 view .LVU6356
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1656:
	.loc 1 30911 30 view .LVU6357
	subw	$-128, %dx
	.loc 1 30912 23 view .LVU6358
	movb	%dl, 12(%rdi,%rax)
.LVL1657:
	.loc 1 30912 23 view .LVU6359
.LBE5062:
	.loc 1 30908 9 is_stmt 1 view .LVU6360
	.loc 1 30908 34 is_stmt 0 view .LVU6361
	leaq	13(%rax), %rdx
.LVL1658:
	.loc 1 30908 23 is_stmt 1 view .LVU6362
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5063:
	.loc 1 30909 13 view .LVU6363
.LVL1659:
	.loc 1 30910 13 view .LVU6364
	.loc 1 30911 13 view .LVU6365
	.loc 1 30912 13 view .LVU6366
	.loc 1 30910 15 is_stmt 0 view .LVU6367
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1660:
	.loc 1 30911 30 view .LVU6368
	subw	$-128, %dx
	.loc 1 30912 23 view .LVU6369
	movb	%dl, 13(%rdi,%rax)
.LVL1661:
	.loc 1 30912 23 view .LVU6370
.LBE5063:
	.loc 1 30908 9 is_stmt 1 view .LVU6371
	.loc 1 30908 34 is_stmt 0 view .LVU6372
	leaq	14(%rax), %rdx
.LVL1662:
	.loc 1 30908 23 is_stmt 1 view .LVU6373
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5064:
	.loc 1 30909 13 view .LVU6374
.LVL1663:
	.loc 1 30910 13 view .LVU6375
	.loc 1 30911 13 view .LVU6376
	.loc 1 30912 13 view .LVU6377
	.loc 1 30910 15 is_stmt 0 view .LVU6378
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1664:
	.loc 1 30911 30 view .LVU6379
	subw	$-128, %dx
	.loc 1 30912 23 view .LVU6380
	movb	%dl, 14(%rdi,%rax)
.LVL1665:
	.loc 1 30912 23 view .LVU6381
.LBE5064:
	.loc 1 30908 9 is_stmt 1 view .LVU6382
	.loc 1 30908 23 view .LVU6383
	jmp	.L1050
.LVL1666:
	.p2align 4,,10
	.p2align 3
.L1206:
	.loc 1 30908 23 is_stmt 0 view .LVU6384
.LBE5048:
.LBE5047:
.LBE5046:
.LBE5045:
.LBE5044:
.LBE5071:
.LBE5379:
	.loc 1 32783 17 is_stmt 1 view .LVU6385
	.loc 1 32783 37 view .LVU6386
.LBB5380:
.LBI5380:
	.loc 1 32031 13 view .LVU6387
.LBE5380:
	.loc 1 32049 9 view .LVU6388
	.loc 1 32050 13 view .LVU6389
.LBB5751:
.LBB5381:
.LBI5381:
	.loc 1 32007 23 view .LVU6390
.LBE5381:
.LBE5751:
	.loc 1 32009 5 view .LVU6391
.LBB5752:
.LBB5720:
.LBB5382:
.LBI5382:
	.loc 1 31982 23 view .LVU6392
.LBB5383:
	.loc 1 31984 5 view .LVU6393
	.loc 1 31986 5 view .LVU6394
	.loc 1 31987 5 view .LVU6395
	.loc 1 31989 5 view .LVU6396
	.loc 1 31990 5 view .LVU6397
	.loc 1 31991 5 view .LVU6398
	testl	%r9d, %r9d
	je	.L1209
.LVL1667:
	.loc 1 31996 5 view .LVU6399
.LBB5384:
	.loc 1 31996 19 view .LVU6400
	testq	%r8, %r8
	je	.L1050
	movl	_ZL7g_maLCG(%rip), %eax
	cmpl	$1, %r9d
	jne	.L1468
	movss	.LC77(%rip), %xmm0
	movss	.LC88(%rip), %xmm3
	.loc 1 31996 12 is_stmt 0 view .LVU6401
	xorl	%edx, %edx
.LVL1668:
	.loc 1 31996 12 view .LVU6402
	movss	.LC103(%rip), %xmm5
	movsd	.LC104(%rip), %xmm2
	movss	.LC107(%rip), %xmm6
	movss	.LC108(%rip), %xmm4
.LVL1669:
	.p2align 4,,10
	.p2align 3
.L1210:
.LBB5385:
	.loc 1 31997 9 is_stmt 1 view .LVU6403
	.loc 1 31998 9 view .LVU6404
.LBB5386:
.LBI5386:
	.loc 1 2528 24 view .LVU6405
.LBE5386:
.LBE5385:
.LBE5384:
.LBE5383:
.LBE5382:
.LBE5720:
.LBE5752:
	.loc 1 2530 5 view .LVU6406
	.loc 1 2531 9 view .LVU6407
.LBB5753:
.LBB5721:
.LBB5690:
.LBB5660:
.LBB5630:
.LBB5585:
.LBB5551:
.LBB5387:
.LBI5387:
	.loc 1 2516 24 view .LVU6408
.LBE5387:
.LBE5551:
.LBE5585:
.LBE5630:
.LBE5660:
.LBE5690:
.LBE5721:
.LBE5753:
	.loc 1 2518 5 view .LVU6409
.LBB5754:
.LBB5722:
.LBB5691:
.LBB5661:
.LBB5631:
.LBB5586:
.LBB5552:
.LBB5411:
.LBB5388:
.LBI5388:
	.loc 1 2505 24 view .LVU6410
.LBE5388:
.LBE5411:
.LBE5552:
.LBE5586:
.LBE5631:
.LBE5661:
.LBE5691:
.LBE5722:
.LBE5754:
	.loc 1 2507 5 view .LVU6411
.LBB5755:
.LBB5723:
.LBB5692:
.LBB5662:
.LBB5632:
.LBB5587:
.LBB5553:
.LBB5412:
.LBB5408:
.LBB5389:
.LBI5389:
	.loc 1 2464 24 view .LVU6412
.LBE5389:
.LBE5408:
.LBE5412:
.LBE5553:
.LBE5587:
.LBE5632:
.LBE5662:
.LBE5692:
.LBE5723:
.LBE5755:
	.loc 1 2466 5 view .LVU6413
.LBB5756:
.LBB5724:
.LBB5693:
.LBB5663:
.LBB5633:
.LBB5588:
.LBB5554:
.LBB5413:
.LBB5409:
.LBB5406:
.LBB5390:
.LBI5390:
	.loc 1 2459 24 view .LVU6414
.LBB5391:
	.loc 1 2461 5 view .LVU6415
.LBB5392:
.LBI5392:
	.loc 1 2454 25 view .LVU6416
.LBB5393:
	.loc 1 2456 5 view .LVU6417
.LBB5394:
.LBI5394:
	.loc 1 2438 27 view .LVU6418
.LBB5395:
	.loc 1 2440 5 view .LVU6419
	.loc 1 2440 29 is_stmt 0 view .LVU6420
	imull	$48271, %eax, %esi
.LBE5395:
.LBE5394:
	.loc 1 2456 34 view .LVU6421
	pxor	%xmm1, %xmm1
.LBB5397:
.LBB5396:
	.loc 1 2440 55 view .LVU6422
	movslq	%esi, %rcx
	movq	%rcx, %rax
	salq	$30, %rax
	addq	%rcx, %rax
	movl	%esi, %ecx
	sarl	$31, %ecx
	sarq	$61, %rax
	subl	%ecx, %eax
	movl	%eax, %ecx
	sall	$31, %ecx
	subl	%eax, %ecx
	movl	%esi, %eax
	subl	%ecx, %eax
	.loc 1 2441 5 is_stmt 1 view .LVU6423
.LVL1670:
	.loc 1 2441 5 is_stmt 0 view .LVU6424
.LBE5396:
.LBE5397:
.LBE5393:
.LBE5392:
.LBE5391:
.LBE5390:
.LBB5401:
.LBI5401:
	.loc 1 2367 24 is_stmt 1 view .LVU6425
.LBB5402:
	.loc 1 2369 5 view .LVU6426
	.loc 1 2369 5 is_stmt 0 view .LVU6427
.LBE5402:
.LBE5401:
.LBE5406:
.LBE5409:
.LBE5413:
.LBE5554:
	.loc 1 31999 9 is_stmt 1 view .LVU6428
.LBB5555:
.LBB5414:
.LBB5410:
.LBB5407:
.LBB5404:
.LBB5400:
.LBB5399:
.LBB5398:
	.loc 1 2456 34 is_stmt 0 view .LVU6429
	cvtsi2sdl	%eax, %xmm1
	.loc 1 2456 44 view .LVU6430
	mulsd	%xmm2, %xmm1
.LBE5398:
.LBE5399:
	.loc 1 2461 39 view .LVU6431
	cvtsd2ss	%xmm1, %xmm1
.LBE5400:
.LBE5404:
.LBB5405:
.LBB5403:
	.loc 1 2369 18 view .LVU6432
	mulss	%xmm4, %xmm1
	.loc 1 2369 25 view .LVU6433
	subss	%xmm6, %xmm1
.LBE5403:
.LBE5405:
.LBE5407:
.LBE5410:
.LBE5414:
.LBE5555:
	.loc 1 31998 11 view .LVU6434
	addss	(%rbx,%rdx,4), %xmm1
	.loc 1 31999 23 view .LVU6435
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL1671:
	.loc 1 32000 9 is_stmt 1 view .LVU6436
	.loc 1 32000 11 is_stmt 0 view .LVU6437
	addss	%xmm0, %xmm1
.LVL1672:
	.loc 1 32001 9 is_stmt 1 view .LVU6438
	.loc 1 32003 9 view .LVU6439
	.loc 1 32001 11 is_stmt 0 view .LVU6440
	mulss	%xmm5, %xmm1
.LVL1673:
	.loc 1 32003 21 view .LVU6441
	cvttss2sil	%xmm1, %ecx
	movb	%cl, (%rdi,%rdx)
.LBE5588:
	.loc 1 31996 5 is_stmt 1 view .LVU6442
	.loc 1 31996 30 is_stmt 0 view .LVU6443
	addq	$1, %rdx
.LVL1674:
	.loc 1 31996 19 is_stmt 1 view .LVU6444
	cmpq	%rdx, %r8
	jne	.L1210
.LVL1675:
.L1216:
	.loc 1 31996 19 is_stmt 0 view .LVU6445
	movl	%eax, _ZL7g_maLCG(%rip)
	jmp	.L1050
.LVL1676:
	.p2align 4,,10
	.p2align 3
.L1117:
	.loc 1 31996 19 view .LVU6446
.LBE5633:
.LBE5663:
.LBE5693:
.LBE5724:
.LBE5756:
	.loc 1 32759 17 is_stmt 1 view .LVU6447
	.loc 1 32759 37 view .LVU6448
.LBB5757:
.LBI5757:
	.loc 1 31303 13 view .LVU6449
.LBE5757:
	.loc 1 31321 9 view .LVU6450
	.loc 1 31322 13 view .LVU6451
.LBB5930:
.LBB5758:
.LBI5758:
	.loc 1 31279 23 view .LVU6452
.LBE5758:
.LBE5930:
	.loc 1 31281 5 view .LVU6453
.LBB5931:
.LBB5771:
.LBB5759:
.LBI5759:
	.loc 1 31249 23 view .LVU6454
.LBB5760:
	.loc 1 31251 5 view .LVU6455
	.loc 1 31252 5 view .LVU6456
	.loc 1 31254 5 view .LVU6457
.LBB5761:
	testl	%r9d, %r9d
	jne	.L1120
.LVL1677:
.LBB5762:
	.loc 1 31256 23 view .LVU6458
	testq	%r8, %r8
	je	.L1050
	leaq	(%r8,%r8,2), %rax
	leaq	2(%rdx), %rcx
	addq	%rdx, %rax
	leaq	(%rdi,%r8), %rsi
.LVL1678:
	.loc 1 31256 23 is_stmt 0 view .LVU6459
	leaq	-1(%r8), %r11
	cmpq	%rax, %rdi
	setnb	%dl
.LVL1679:
	.loc 1 31256 23 view .LVU6460
	cmpq	%rsi, %rcx
	setnb	%al
	orb	%al, %dl
	je	.L1121
	cmpq	$6, %r11
	jbe	.L1121
	cmpq	$14, %r11
	jbe	.L1296
	movq	%r8, %r12
	movdqa	.LC83(%rip), %xmm2
	movq	%rdi, %rsi
	andq	$-16, %r12
	addq	%rdi, %r12
.LVL1680:
	.p2align 4,,10
	.p2align 3
.L1124:
	.loc 1 31257 13 is_stmt 1 view .LVU6461
	.loc 1 31257 36 is_stmt 0 view .LVU6462
	movzbl	21(%rcx), %edx
	movzbl	18(%rcx), %eax
	addq	$16, %rsi
	addq	$48, %rcx
	movzbl	-6(%rcx), %r9d
	movzbl	-48(%rcx), %r10d
	salq	$8, %rdx
	orq	%rax, %rdx
	movzbl	-33(%rcx), %eax
	salq	$8, %rdx
	orq	%rax, %rdx
	movzbl	-36(%rcx), %eax
	salq	$8, %rdx
	orq	%rax, %rdx
	movzbl	-39(%rcx), %eax
	salq	$8, %rdx
	orq	%rax, %rdx
	movzbl	-42(%rcx), %eax
	salq	$8, %rdx
	orq	%rax, %rdx
	movzbl	-45(%rcx), %eax
	salq	$8, %rdx
	orq	%rax, %rdx
	movzbl	-3(%rcx), %eax
	salq	$8, %rdx
	salq	$8, %rax
	orq	%r10, %rdx
	orq	%r9, %rax
	movzbl	-9(%rcx), %r9d
	movq	%rdx, -96(%rbp)
	salq	$8, %rax
	orq	%r9, %rax
	movzbl	-12(%rcx), %r9d
	salq	$8, %rax
	orq	%r9, %rax
	movzbl	-15(%rcx), %r9d
	salq	$8, %rax
	orq	%r9, %rax
	movzbl	-18(%rcx), %r9d
	salq	$8, %rax
	orq	%r9, %rax
	movzbl	-21(%rcx), %r9d
	salq	$8, %rax
	orq	%r9, %rax
	movzbl	-24(%rcx), %r9d
	salq	$8, %rax
	orq	%r9, %rax
	movq	%rax, -88(%rbp)
	.loc 1 31257 62 view .LVU6463
	movdqa	-96(%rbp), %xmm0
	paddb	%xmm2, %xmm0
	.loc 1 31257 23 view .LVU6464
	movups	%xmm0, -16(%rsi)
	.loc 1 31256 9 is_stmt 1 view .LVU6465
	.loc 1 31256 23 view .LVU6466
	cmpq	%rsi, %r12
	jne	.L1124
	movq	%r8, %rdx
	andq	$-16, %rdx
	testb	$15, %r8b
	je	.L1050
	movq	%r8, %rsi
	subq	%rdx, %r11
	subq	%rdx, %rsi
	cmpq	$6, %r11
	jbe	.L1126
.L1122:
	.loc 1 31257 62 is_stmt 0 view .LVU6467
	movq	.LC98(%rip), %xmm0
	leaq	2(%rdx,%rdx,2), %rcx
	addq	%rbx, %rcx
	.loc 1 31257 13 is_stmt 1 view .LVU6468
	.loc 1 31257 36 is_stmt 0 view .LVU6469
	movzbl	21(%rcx), %eax
	movzbl	18(%rcx), %r9d
	salq	$8, %rax
	orq	%r9, %rax
	movzbl	15(%rcx), %r9d
	salq	$8, %rax
	orq	%r9, %rax
	movzbl	12(%rcx), %r9d
	salq	$8, %rax
	orq	%r9, %rax
	movzbl	9(%rcx), %r9d
	salq	$8, %rax
	orq	%r9, %rax
	movzbl	6(%rcx), %r9d
	salq	$8, %rax
	orq	%r9, %rax
	movzbl	3(%rcx), %r9d
	movzbl	(%rcx), %ecx
	salq	$8, %rax
	orq	%r9, %rax
	salq	$8, %rax
	orq	%rcx, %rax
	.loc 1 31257 62 view .LVU6470
	movq	%rax, %xmm7
	movq	%rsi, %rax
	paddb	%xmm7, %xmm0
	andq	$-8, %rax
	.loc 1 31257 23 view .LVU6471
	movq	%xmm0, (%rdi,%rdx)
	.loc 1 31256 9 is_stmt 1 view .LVU6472
	.loc 1 31256 23 view .LVU6473
	addq	%rax, %rdx
	cmpq	%rsi, %rax
	je	.L1050
.L1126:
.LVL1681:
	.loc 1 31257 13 view .LVU6474
	.loc 1 31257 36 is_stmt 0 view .LVU6475
	leaq	(%rdx,%rdx,2), %rax
	.loc 1 31257 62 view .LVU6476
	movzbl	2(%rbx,%rax), %eax
	addl	$-128, %eax
	.loc 1 31257 23 view .LVU6477
	movb	%al, (%rdi,%rdx)
	.loc 1 31256 9 is_stmt 1 view .LVU6478
	.loc 1 31256 34 is_stmt 0 view .LVU6479
	leaq	1(%rdx), %rax
.LVL1682:
	.loc 1 31256 23 is_stmt 1 view .LVU6480
	cmpq	%rax, %r8
	jbe	.L1050
	.loc 1 31257 13 view .LVU6481
	.loc 1 31257 36 is_stmt 0 view .LVU6482
	leaq	(%rax,%rax,2), %rax
.LVL1683:
	.loc 1 31257 62 view .LVU6483
	movzbl	2(%rbx,%rax), %eax
	addl	$-128, %eax
	.loc 1 31257 23 view .LVU6484
	movb	%al, 1(%rdi,%rdx)
	.loc 1 31256 9 is_stmt 1 view .LVU6485
	.loc 1 31256 34 is_stmt 0 view .LVU6486
	leaq	2(%rdx), %rax
.LVL1684:
	.loc 1 31256 23 is_stmt 1 view .LVU6487
	cmpq	%rax, %r8
	jbe	.L1050
	.loc 1 31257 13 view .LVU6488
	.loc 1 31257 36 is_stmt 0 view .LVU6489
	leaq	(%rax,%rax,2), %rax
.LVL1685:
	.loc 1 31257 62 view .LVU6490
	movzbl	2(%rbx,%rax), %eax
	addl	$-128, %eax
	.loc 1 31257 23 view .LVU6491
	movb	%al, 2(%rdi,%rdx)
	.loc 1 31256 9 is_stmt 1 view .LVU6492
	.loc 1 31256 34 is_stmt 0 view .LVU6493
	leaq	3(%rdx), %rax
.LVL1686:
	.loc 1 31256 23 is_stmt 1 view .LVU6494
	cmpq	%rax, %r8
	jbe	.L1050
	.loc 1 31257 13 view .LVU6495
	.loc 1 31257 36 is_stmt 0 view .LVU6496
	leaq	(%rax,%rax,2), %rax
.LVL1687:
	.loc 1 31257 62 view .LVU6497
	movzbl	2(%rbx,%rax), %eax
	addl	$-128, %eax
	.loc 1 31257 23 view .LVU6498
	movb	%al, 3(%rdi,%rdx)
	.loc 1 31256 9 is_stmt 1 view .LVU6499
	.loc 1 31256 34 is_stmt 0 view .LVU6500
	leaq	4(%rdx), %rax
.LVL1688:
	.loc 1 31256 23 is_stmt 1 view .LVU6501
	cmpq	%rax, %r8
	jbe	.L1050
	.loc 1 31257 13 view .LVU6502
	.loc 1 31257 36 is_stmt 0 view .LVU6503
	leaq	(%rax,%rax,2), %rax
.LVL1689:
	.loc 1 31257 62 view .LVU6504
	movzbl	2(%rbx,%rax), %eax
	addl	$-128, %eax
	.loc 1 31257 23 view .LVU6505
	movb	%al, 4(%rdi,%rdx)
	.loc 1 31256 9 is_stmt 1 view .LVU6506
	.loc 1 31256 34 is_stmt 0 view .LVU6507
	leaq	5(%rdx), %rax
.LVL1690:
	.loc 1 31256 23 is_stmt 1 view .LVU6508
	cmpq	%rax, %r8
	jbe	.L1050
	.loc 1 31257 13 view .LVU6509
	.loc 1 31257 36 is_stmt 0 view .LVU6510
	leaq	(%rax,%rax,2), %rax
.LVL1691:
	.loc 1 31257 62 view .LVU6511
	movzbl	2(%rbx,%rax), %eax
	addl	$-128, %eax
	.loc 1 31257 23 view .LVU6512
	movb	%al, 5(%rdi,%rdx)
	.loc 1 31256 9 is_stmt 1 view .LVU6513
	.loc 1 31256 34 is_stmt 0 view .LVU6514
	leaq	6(%rdx), %rax
.LVL1692:
	.loc 1 31256 23 is_stmt 1 view .LVU6515
	cmpq	%rax, %r8
	jbe	.L1050
	.loc 1 31257 13 view .LVU6516
	.loc 1 31257 36 is_stmt 0 view .LVU6517
	leaq	(%rax,%rax,2), %rax
.LVL1693:
	.loc 1 31257 62 view .LVU6518
	movzbl	2(%rbx,%rax), %eax
	addl	$-128, %eax
	.loc 1 31257 23 view .LVU6519
	movb	%al, 6(%rdi,%rdx)
	.loc 1 31256 9 is_stmt 1 view .LVU6520
.LVL1694:
	.loc 1 31256 23 view .LVU6521
	jmp	.L1050
.LVL1695:
	.p2align 4,,10
	.p2align 3
.L1160:
	.loc 1 31256 23 is_stmt 0 view .LVU6522
.LBE5762:
.LBE5761:
.LBE5760:
.LBE5759:
.LBE5771:
.LBE5931:
	.loc 1 32771 17 is_stmt 1 view .LVU6523
	.loc 1 32771 37 view .LVU6524
.LBB5932:
.LBI5932:
	.loc 1 31673 13 view .LVU6525
.LBE5932:
	.loc 1 31691 9 view .LVU6526
	.loc 1 31692 13 view .LVU6527
.LBB6278:
.LBB5933:
.LBI5933:
	.loc 1 31649 23 view .LVU6528
.LBE5933:
.LBE6278:
	.loc 1 31651 5 view .LVU6529
.LBB6279:
.LBB5961:
.LBB5934:
.LBI5934:
	.loc 1 31616 23 view .LVU6530
.LBB5935:
	.loc 1 31618 5 view .LVU6531
	.loc 1 31619 5 view .LVU6532
	.loc 1 31621 5 view .LVU6533
.LBB5936:
	testl	%r9d, %r9d
	jne	.L1163
.LVL1696:
.LBB5937:
.LBB5938:
	.loc 1 31623 23 view .LVU6534
	testq	%r8, %r8
	je	.L1050
	leaq	(%rdx,%r8,4), %rax
	cmpq	%rax, %rdi
	leaq	(%rdi,%r8), %rax
	setnb	%dl
.LVL1697:
	.loc 1 31623 23 is_stmt 0 view .LVU6535
	cmpq	%rax, %rbx
	setnb	%al
	orb	%al, %dl
	je	.L1297
	leaq	-1(%r8), %rax
	cmpq	$14, %rax
	jbe	.L1297
	movq	%r8, %rcx
	movdqa	.LC83(%rip), %xmm2
	movq	%rbx, %rax
	movq	%rdi, %rdx
	shrq	$4, %rcx
	movdqa	.LC76(%rip), %xmm3
	salq	$6, %rcx
	addq	%rbx, %rcx
.LVL1698:
	.p2align 4,,10
	.p2align 3
.L1166:
.LBB5939:
	.loc 1 31624 13 is_stmt 1 view .LVU6536
	.loc 1 31625 13 view .LVU6537
	.loc 1 31626 13 view .LVU6538
	.loc 1 31627 13 view .LVU6539
	.loc 1 31625 15 is_stmt 0 view .LVU6540
	movdqu	(%rax), %xmm0
	movdqu	16(%rax), %xmm1
	addq	$64, %rax
	addq	$16, %rdx
	psrad	$24, %xmm1
	psrad	$24, %xmm0
	.loc 1 31626 15 view .LVU6541
	movdqa	%xmm0, %xmm4
	punpcklwd	%xmm1, %xmm0
	punpckhwd	%xmm1, %xmm4
	movdqa	%xmm0, %xmm1
	punpckhwd	%xmm4, %xmm1
	punpcklwd	%xmm4, %xmm0
	.loc 1 31625 15 view .LVU6542
	movdqu	-16(%rax), %xmm4
	.loc 1 31626 15 view .LVU6543
	punpcklwd	%xmm1, %xmm0
	.loc 1 31625 15 view .LVU6544
	movdqu	-32(%rax), %xmm1
	psrad	$24, %xmm4
	.loc 1 31626 15 view .LVU6545
	pand	%xmm3, %xmm0
	.loc 1 31625 15 view .LVU6546
	psrad	$24, %xmm1
	.loc 1 31626 15 view .LVU6547
	movdqa	%xmm1, %xmm5
	punpcklwd	%xmm4, %xmm1
	punpckhwd	%xmm4, %xmm5
	movdqa	%xmm1, %xmm4
	punpckhwd	%xmm5, %xmm4
	punpcklwd	%xmm5, %xmm1
	punpcklwd	%xmm4, %xmm1
	pand	%xmm3, %xmm1
	packuswb	%xmm1, %xmm0
	paddb	%xmm2, %xmm0
	.loc 1 31627 23 view .LVU6548
	movups	%xmm0, -16(%rdx)
	.loc 1 31627 23 view .LVU6549
.LBE5939:
	.loc 1 31623 9 is_stmt 1 view .LVU6550
	.loc 1 31623 23 view .LVU6551
	cmpq	%rcx, %rax
	jne	.L1166
	movq	%r8, %rax
	andq	$-16, %rax
	testb	$15, %r8b
	je	.L1050
.LVL1699:
.LBB5940:
	.loc 1 31624 13 view .LVU6552
	.loc 1 31625 13 view .LVU6553
	.loc 1 31625 15 is_stmt 0 view .LVU6554
	movsbl	3(%rbx,%rax,4), %edx
.LVL1700:
	.loc 1 31626 13 is_stmt 1 view .LVU6555
	.loc 1 31627 13 view .LVU6556
	.loc 1 31626 15 is_stmt 0 view .LVU6557
	subl	$-128, %edx
.LVL1701:
	.loc 1 31627 23 view .LVU6558
	movb	%dl, (%rdi,%rax)
.LBE5940:
	.loc 1 31623 9 is_stmt 1 view .LVU6559
	.loc 1 31623 34 is_stmt 0 view .LVU6560
	leaq	1(%rax), %rdx
.LVL1702:
	.loc 1 31623 23 is_stmt 1 view .LVU6561
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5941:
	.loc 1 31624 13 view .LVU6562
.LVL1703:
	.loc 1 31625 13 view .LVU6563
	.loc 1 31625 15 is_stmt 0 view .LVU6564
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1704:
	.loc 1 31626 13 is_stmt 1 view .LVU6565
	.loc 1 31627 13 view .LVU6566
	.loc 1 31626 15 is_stmt 0 view .LVU6567
	subl	$-128, %edx
.LVL1705:
	.loc 1 31627 23 view .LVU6568
	movb	%dl, 1(%rdi,%rax)
.LBE5941:
	.loc 1 31623 9 is_stmt 1 view .LVU6569
	.loc 1 31623 34 is_stmt 0 view .LVU6570
	leaq	2(%rax), %rdx
.LVL1706:
	.loc 1 31623 23 is_stmt 1 view .LVU6571
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5942:
	.loc 1 31624 13 view .LVU6572
.LVL1707:
	.loc 1 31625 13 view .LVU6573
	.loc 1 31625 15 is_stmt 0 view .LVU6574
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1708:
	.loc 1 31626 13 is_stmt 1 view .LVU6575
	.loc 1 31627 13 view .LVU6576
	.loc 1 31626 15 is_stmt 0 view .LVU6577
	subl	$-128, %edx
.LVL1709:
	.loc 1 31627 23 view .LVU6578
	movb	%dl, 2(%rdi,%rax)
.LBE5942:
	.loc 1 31623 9 is_stmt 1 view .LVU6579
	.loc 1 31623 34 is_stmt 0 view .LVU6580
	leaq	3(%rax), %rdx
.LVL1710:
	.loc 1 31623 23 is_stmt 1 view .LVU6581
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5943:
	.loc 1 31624 13 view .LVU6582
.LVL1711:
	.loc 1 31625 13 view .LVU6583
	.loc 1 31625 15 is_stmt 0 view .LVU6584
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1712:
	.loc 1 31626 13 is_stmt 1 view .LVU6585
	.loc 1 31627 13 view .LVU6586
	.loc 1 31626 15 is_stmt 0 view .LVU6587
	subl	$-128, %edx
.LVL1713:
	.loc 1 31627 23 view .LVU6588
	movb	%dl, 3(%rdi,%rax)
.LBE5943:
	.loc 1 31623 9 is_stmt 1 view .LVU6589
	.loc 1 31623 34 is_stmt 0 view .LVU6590
	leaq	4(%rax), %rdx
.LVL1714:
	.loc 1 31623 23 is_stmt 1 view .LVU6591
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5944:
	.loc 1 31624 13 view .LVU6592
.LVL1715:
	.loc 1 31625 13 view .LVU6593
	.loc 1 31625 15 is_stmt 0 view .LVU6594
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1716:
	.loc 1 31626 13 is_stmt 1 view .LVU6595
	.loc 1 31627 13 view .LVU6596
	.loc 1 31626 15 is_stmt 0 view .LVU6597
	subl	$-128, %edx
.LVL1717:
	.loc 1 31627 23 view .LVU6598
	movb	%dl, 4(%rdi,%rax)
.LBE5944:
	.loc 1 31623 9 is_stmt 1 view .LVU6599
	.loc 1 31623 34 is_stmt 0 view .LVU6600
	leaq	5(%rax), %rdx
.LVL1718:
	.loc 1 31623 23 is_stmt 1 view .LVU6601
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5945:
	.loc 1 31624 13 view .LVU6602
.LVL1719:
	.loc 1 31625 13 view .LVU6603
	.loc 1 31625 15 is_stmt 0 view .LVU6604
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1720:
	.loc 1 31626 13 is_stmt 1 view .LVU6605
	.loc 1 31627 13 view .LVU6606
	.loc 1 31626 15 is_stmt 0 view .LVU6607
	subl	$-128, %edx
.LVL1721:
	.loc 1 31627 23 view .LVU6608
	movb	%dl, 5(%rdi,%rax)
.LBE5945:
	.loc 1 31623 9 is_stmt 1 view .LVU6609
	.loc 1 31623 34 is_stmt 0 view .LVU6610
	leaq	6(%rax), %rdx
.LVL1722:
	.loc 1 31623 23 is_stmt 1 view .LVU6611
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5946:
	.loc 1 31624 13 view .LVU6612
.LVL1723:
	.loc 1 31625 13 view .LVU6613
	.loc 1 31625 15 is_stmt 0 view .LVU6614
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1724:
	.loc 1 31626 13 is_stmt 1 view .LVU6615
	.loc 1 31627 13 view .LVU6616
	.loc 1 31626 15 is_stmt 0 view .LVU6617
	subl	$-128, %edx
.LVL1725:
	.loc 1 31627 23 view .LVU6618
	movb	%dl, 6(%rdi,%rax)
.LBE5946:
	.loc 1 31623 9 is_stmt 1 view .LVU6619
	.loc 1 31623 34 is_stmt 0 view .LVU6620
	leaq	7(%rax), %rdx
.LVL1726:
	.loc 1 31623 23 is_stmt 1 view .LVU6621
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5947:
	.loc 1 31624 13 view .LVU6622
.LVL1727:
	.loc 1 31625 13 view .LVU6623
	.loc 1 31625 15 is_stmt 0 view .LVU6624
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1728:
	.loc 1 31626 13 is_stmt 1 view .LVU6625
	.loc 1 31627 13 view .LVU6626
	.loc 1 31626 15 is_stmt 0 view .LVU6627
	subl	$-128, %edx
.LVL1729:
	.loc 1 31627 23 view .LVU6628
	movb	%dl, 7(%rdi,%rax)
.LBE5947:
	.loc 1 31623 9 is_stmt 1 view .LVU6629
	.loc 1 31623 34 is_stmt 0 view .LVU6630
	leaq	8(%rax), %rdx
.LVL1730:
	.loc 1 31623 23 is_stmt 1 view .LVU6631
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5948:
	.loc 1 31624 13 view .LVU6632
.LVL1731:
	.loc 1 31625 13 view .LVU6633
	.loc 1 31625 15 is_stmt 0 view .LVU6634
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1732:
	.loc 1 31626 13 is_stmt 1 view .LVU6635
	.loc 1 31627 13 view .LVU6636
	.loc 1 31626 15 is_stmt 0 view .LVU6637
	subl	$-128, %edx
.LVL1733:
	.loc 1 31627 23 view .LVU6638
	movb	%dl, 8(%rdi,%rax)
.LBE5948:
	.loc 1 31623 9 is_stmt 1 view .LVU6639
	.loc 1 31623 34 is_stmt 0 view .LVU6640
	leaq	9(%rax), %rdx
.LVL1734:
	.loc 1 31623 23 is_stmt 1 view .LVU6641
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5949:
	.loc 1 31624 13 view .LVU6642
.LVL1735:
	.loc 1 31625 13 view .LVU6643
	.loc 1 31625 15 is_stmt 0 view .LVU6644
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1736:
	.loc 1 31626 13 is_stmt 1 view .LVU6645
	.loc 1 31627 13 view .LVU6646
	.loc 1 31626 15 is_stmt 0 view .LVU6647
	subl	$-128, %edx
.LVL1737:
	.loc 1 31627 23 view .LVU6648
	movb	%dl, 9(%rdi,%rax)
.LBE5949:
	.loc 1 31623 9 is_stmt 1 view .LVU6649
	.loc 1 31623 34 is_stmt 0 view .LVU6650
	leaq	10(%rax), %rdx
.LVL1738:
	.loc 1 31623 23 is_stmt 1 view .LVU6651
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5950:
	.loc 1 31624 13 view .LVU6652
.LVL1739:
	.loc 1 31625 13 view .LVU6653
	.loc 1 31625 15 is_stmt 0 view .LVU6654
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1740:
	.loc 1 31626 13 is_stmt 1 view .LVU6655
	.loc 1 31627 13 view .LVU6656
	.loc 1 31626 15 is_stmt 0 view .LVU6657
	subl	$-128, %edx
.LVL1741:
	.loc 1 31627 23 view .LVU6658
	movb	%dl, 10(%rdi,%rax)
.LBE5950:
	.loc 1 31623 9 is_stmt 1 view .LVU6659
	.loc 1 31623 34 is_stmt 0 view .LVU6660
	leaq	11(%rax), %rdx
.LVL1742:
	.loc 1 31623 23 is_stmt 1 view .LVU6661
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5951:
	.loc 1 31624 13 view .LVU6662
.LVL1743:
	.loc 1 31625 13 view .LVU6663
	.loc 1 31625 15 is_stmt 0 view .LVU6664
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1744:
	.loc 1 31626 13 is_stmt 1 view .LVU6665
	.loc 1 31627 13 view .LVU6666
	.loc 1 31626 15 is_stmt 0 view .LVU6667
	subl	$-128, %edx
.LVL1745:
	.loc 1 31627 23 view .LVU6668
	movb	%dl, 11(%rdi,%rax)
.LBE5951:
	.loc 1 31623 9 is_stmt 1 view .LVU6669
	.loc 1 31623 34 is_stmt 0 view .LVU6670
	leaq	12(%rax), %rdx
.LVL1746:
	.loc 1 31623 23 is_stmt 1 view .LVU6671
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5952:
	.loc 1 31624 13 view .LVU6672
.LVL1747:
	.loc 1 31625 13 view .LVU6673
	.loc 1 31625 15 is_stmt 0 view .LVU6674
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1748:
	.loc 1 31626 13 is_stmt 1 view .LVU6675
	.loc 1 31627 13 view .LVU6676
	.loc 1 31626 15 is_stmt 0 view .LVU6677
	subl	$-128, %edx
.LVL1749:
	.loc 1 31627 23 view .LVU6678
	movb	%dl, 12(%rdi,%rax)
.LBE5952:
	.loc 1 31623 9 is_stmt 1 view .LVU6679
	.loc 1 31623 34 is_stmt 0 view .LVU6680
	leaq	13(%rax), %rdx
.LVL1750:
	.loc 1 31623 23 is_stmt 1 view .LVU6681
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5953:
	.loc 1 31624 13 view .LVU6682
.LVL1751:
	.loc 1 31625 13 view .LVU6683
	.loc 1 31625 15 is_stmt 0 view .LVU6684
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1752:
	.loc 1 31626 13 is_stmt 1 view .LVU6685
	.loc 1 31627 13 view .LVU6686
	.loc 1 31626 15 is_stmt 0 view .LVU6687
	subl	$-128, %edx
.LVL1753:
	.loc 1 31627 23 view .LVU6688
	movb	%dl, 13(%rdi,%rax)
.LBE5953:
	.loc 1 31623 9 is_stmt 1 view .LVU6689
	.loc 1 31623 34 is_stmt 0 view .LVU6690
	leaq	14(%rax), %rdx
.LVL1754:
	.loc 1 31623 23 is_stmt 1 view .LVU6691
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5954:
	.loc 1 31624 13 view .LVU6692
.LVL1755:
	.loc 1 31625 13 view .LVU6693
	.loc 1 31625 15 is_stmt 0 view .LVU6694
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1756:
	.loc 1 31626 13 is_stmt 1 view .LVU6695
	.loc 1 31627 13 view .LVU6696
	.loc 1 31626 15 is_stmt 0 view .LVU6697
	subl	$-128, %edx
.LVL1757:
	.loc 1 31627 23 view .LVU6698
	movb	%dl, 14(%rdi,%rax)
.LBE5954:
	.loc 1 31623 9 is_stmt 1 view .LVU6699
.LVL1758:
	.loc 1 31623 23 view .LVU6700
	jmp	.L1050
.LVL1759:
	.p2align 4,,10
	.p2align 3
.L1158:
	.loc 1 31623 23 is_stmt 0 view .LVU6701
.LBE5938:
.LBE5937:
.LBE5936:
.LBE5935:
.LBE5934:
.LBE5961:
.LBE6279:
.LBB6280:
.LBB6281:
.LBB6282:
.LBB6283:
.LBB6284:
	.loc 1 31784 19 is_stmt 1 view .LVU6702
	testq	%r8, %r8
	je	.L1050
	leaq	(%r8,%r8,2), %rcx
	addq	%rdi, %rcx
.LVL1760:
	.p2align 4,,10
	.p2align 3
.L1199:
.LBB6285:
	.loc 1 31785 9 view .LVU6703
	.loc 1 31785 19 is_stmt 0 view .LVU6704
	movl	(%rbx), %eax
.LVL1761:
	.loc 1 31786 9 is_stmt 1 view .LVU6705
.LBE6285:
	.loc 1 31784 19 is_stmt 0 view .LVU6706
	addq	$3, %rdi
	addq	$4, %rbx
.LBB6286:
	.loc 1 31787 54 view .LVU6707
	movl	%eax, %edx
	.loc 1 31786 24 view .LVU6708
	movb	%ah, -3(%rdi)
	.loc 1 31787 9 is_stmt 1 view .LVU6709
	.loc 1 31788 54 is_stmt 0 view .LVU6710
	shrl	$24, %eax
.LVL1762:
	.loc 1 31787 54 view .LVU6711
	shrl	$16, %edx
.LVL1763:
	.loc 1 31788 24 view .LVU6712
	movb	%al, -1(%rdi)
	.loc 1 31787 24 view .LVU6713
	movb	%dl, -2(%rdi)
	.loc 1 31788 9 is_stmt 1 view .LVU6714
.LBE6286:
	.loc 1 31784 5 view .LVU6715
	.loc 1 31784 19 view .LVU6716
	cmpq	%rcx, %rdi
	jne	.L1199
	jmp	.L1050
.LVL1764:
	.p2align 4,,10
	.p2align 3
.L1115:
	.loc 1 31784 19 is_stmt 0 view .LVU6717
.LBE6284:
.LBE6283:
.LBE6282:
.LBE6281:
.LBE6280:
.LBB6287:
.LBB6288:
.LBB6289:
.LBB6290:
	.loc 1 31422 19 view .LVU6718
	testq	%r8, %r8
	je	.L1050
	leaq	(%r8,%r8,2), %rcx
	addq	%rdx, %rcx
.LVL1765:
	.p2align 4,,10
	.p2align 3
.L1156:
	.loc 1 31423 34 view .LVU6719
	movzbl	(%rbx), %eax
	.loc 1 31423 71 view .LVU6720
	movzbl	1(%rbx), %edx
	.loc 1 31422 19 view .LVU6721
	addq	$3, %rbx
	addq	$4, %rdi
	.loc 1 31423 99 view .LVU6722
	sall	$16, %edx
	.loc 1 31423 62 view .LVU6723
	sall	$8, %eax
	.loc 1 31423 106 view .LVU6724
	orl	%edx, %eax
	.loc 1 31423 109 view .LVU6725
	movzbl	-1(%rbx), %edx
	.loc 1 31423 138 view .LVU6726
	sall	$24, %edx
	.loc 1 31423 106 view .LVU6727
	orl	%edx, %eax
	movl	%eax, -4(%rdi)
	.loc 1 31422 19 view .LVU6728
	cmpq	%rcx, %rbx
	jne	.L1156
	jmp	.L1050
.LVL1766:
	.p2align 4,,10
	.p2align 3
.L1061:
	.loc 1 31422 19 view .LVU6729
.LBE6290:
.LBE6289:
.LBE6288:
.LBE6287:
.LBB6291:
.LBB6292:
.LBB6293:
.LBB6294:
.LBB6295:
	.loc 1 30696 19 is_stmt 1 view .LVU6730
	testq	%r8, %r8
	je	.L1050
	leaq	(%rdi,%r8,4), %rax
	cmpq	%rax, %rdx
	leaq	(%rbx,%r8), %rax
	setnb	%dl
.LVL1767:
	.loc 1 30696 19 is_stmt 0 view .LVU6731
	cmpq	%rax, %rdi
	setnb	%al
	orb	%al, %dl
	je	.L1288
	leaq	-1(%r8), %rax
	cmpq	$14, %rax
	jbe	.L1288
	movq	%r8, %rcx
	movq	%rdi, %rax
	pxor	%xmm6, %xmm6
	movq	%rbx, %rdx
	shrq	$4, %rcx
	movdqa	.LC83(%rip), %xmm2
.LBB6296:
	.loc 1 30699 11 view .LVU6732
	pxor	%xmm5, %xmm5
	salq	$6, %rcx
	addq	%rdi, %rcx
.LVL1768:
	.p2align 4,,10
	.p2align 3
.L1074:
	.loc 1 30697 9 is_stmt 1 view .LVU6733
	.loc 1 30698 9 view .LVU6734
	.loc 1 30698 11 is_stmt 0 view .LVU6735
	movdqu	(%rdx), %xmm0
	movdqa	%xmm6, %xmm3
	.loc 1 30699 11 view .LVU6736
	movdqa	%xmm5, %xmm4
	addq	$64, %rax
	addq	$16, %rdx
	.loc 1 30698 11 view .LVU6737
	paddb	%xmm2, %xmm0
	pcmpgtb	%xmm0, %xmm3
	movdqa	%xmm0, %xmm1
	punpcklbw	%xmm3, %xmm1
	punpckhbw	%xmm3, %xmm0
	.loc 1 30699 9 is_stmt 1 view .LVU6738
	.loc 1 30700 9 view .LVU6739
	.loc 1 30699 11 is_stmt 0 view .LVU6740
	pcmpgtw	%xmm1, %xmm4
	movdqa	%xmm1, %xmm3
	punpcklwd	%xmm4, %xmm3
	punpckhwd	%xmm4, %xmm1
	pslld	$24, %xmm3
	pslld	$24, %xmm1
	.loc 1 30700 20 view .LVU6741
	movups	%xmm3, -64(%rax)
	.loc 1 30699 11 view .LVU6742
	movdqa	%xmm5, %xmm3
	pcmpgtw	%xmm0, %xmm3
	.loc 1 30700 20 view .LVU6743
	movups	%xmm1, -48(%rax)
	.loc 1 30699 11 view .LVU6744
	movdqa	%xmm0, %xmm1
	punpcklwd	%xmm3, %xmm1
	punpckhwd	%xmm3, %xmm0
	pslld	$24, %xmm1
	pslld	$24, %xmm0
	.loc 1 30700 20 view .LVU6745
	movups	%xmm1, -32(%rax)
	movups	%xmm0, -16(%rax)
.LBE6296:
	.loc 1 30696 5 is_stmt 1 view .LVU6746
	.loc 1 30696 19 view .LVU6747
	cmpq	%rax, %rcx
	jne	.L1074
	movq	%r8, %rdx
	andq	$-16, %rdx
	testb	$15, %r8b
	je	.L1050
.LVL1769:
.LBB6297:
	.loc 1 30697 9 view .LVU6748
	.loc 1 30697 18 is_stmt 0 view .LVU6749
	movzbl	(%rbx,%rdx), %eax
.LVL1770:
	.loc 1 30698 9 is_stmt 1 view .LVU6750
.LBE6297:
	.loc 1 30696 30 is_stmt 0 view .LVU6751
	leaq	1(%rdx), %rcx
.LBB6298:
	.loc 1 30698 11 view .LVU6752
	addl	$-128, %eax
.LVL1771:
	.loc 1 30699 9 is_stmt 1 view .LVU6753
	.loc 1 30700 9 view .LVU6754
	.loc 1 30699 11 is_stmt 0 view .LVU6755
	sall	$24, %eax
.LVL1772:
	.loc 1 30699 11 view .LVU6756
	movl	%eax, (%rdi,%rdx,4)
.LBE6298:
	.loc 1 30696 5 is_stmt 1 view .LVU6757
.LVL1773:
	.loc 1 30696 19 view .LVU6758
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB6299:
	.loc 1 30697 9 view .LVU6759
	.loc 1 30697 18 is_stmt 0 view .LVU6760
	movzbl	1(%rbx,%rdx), %eax
.LVL1774:
	.loc 1 30698 9 is_stmt 1 view .LVU6761
	.loc 1 30698 11 is_stmt 0 view .LVU6762
	addl	$-128, %eax
.LVL1775:
	.loc 1 30699 9 is_stmt 1 view .LVU6763
	.loc 1 30700 9 view .LVU6764
	.loc 1 30699 11 is_stmt 0 view .LVU6765
	sall	$24, %eax
.LVL1776:
	.loc 1 30699 11 view .LVU6766
	movl	%eax, (%rdi,%rcx,4)
.LBE6299:
	.loc 1 30696 5 is_stmt 1 view .LVU6767
	.loc 1 30696 30 is_stmt 0 view .LVU6768
	leaq	2(%rdx), %rcx
.LVL1777:
	.loc 1 30696 19 is_stmt 1 view .LVU6769
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB6300:
	.loc 1 30697 9 view .LVU6770
	.loc 1 30697 18 is_stmt 0 view .LVU6771
	movzbl	2(%rbx,%rdx), %eax
.LVL1778:
	.loc 1 30698 9 is_stmt 1 view .LVU6772
	.loc 1 30698 11 is_stmt 0 view .LVU6773
	addl	$-128, %eax
.LVL1779:
	.loc 1 30699 9 is_stmt 1 view .LVU6774
	.loc 1 30700 9 view .LVU6775
	.loc 1 30699 11 is_stmt 0 view .LVU6776
	sall	$24, %eax
.LVL1780:
	.loc 1 30699 11 view .LVU6777
	movl	%eax, (%rdi,%rcx,4)
.LBE6300:
	.loc 1 30696 5 is_stmt 1 view .LVU6778
	.loc 1 30696 30 is_stmt 0 view .LVU6779
	leaq	3(%rdx), %rcx
.LVL1781:
	.loc 1 30696 19 is_stmt 1 view .LVU6780
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB6301:
	.loc 1 30697 9 view .LVU6781
	.loc 1 30697 18 is_stmt 0 view .LVU6782
	movzbl	3(%rbx,%rdx), %eax
.LVL1782:
	.loc 1 30698 9 is_stmt 1 view .LVU6783
	.loc 1 30698 11 is_stmt 0 view .LVU6784
	addl	$-128, %eax
.LVL1783:
	.loc 1 30699 9 is_stmt 1 view .LVU6785
	.loc 1 30700 9 view .LVU6786
	.loc 1 30699 11 is_stmt 0 view .LVU6787
	sall	$24, %eax
.LVL1784:
	.loc 1 30699 11 view .LVU6788
	movl	%eax, (%rdi,%rcx,4)
.LBE6301:
	.loc 1 30696 5 is_stmt 1 view .LVU6789
	.loc 1 30696 30 is_stmt 0 view .LVU6790
	leaq	4(%rdx), %rcx
.LVL1785:
	.loc 1 30696 19 is_stmt 1 view .LVU6791
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB6302:
	.loc 1 30697 9 view .LVU6792
	.loc 1 30697 18 is_stmt 0 view .LVU6793
	movzbl	4(%rbx,%rdx), %eax
.LVL1786:
	.loc 1 30698 9 is_stmt 1 view .LVU6794
	.loc 1 30698 11 is_stmt 0 view .LVU6795
	addl	$-128, %eax
.LVL1787:
	.loc 1 30699 9 is_stmt 1 view .LVU6796
	.loc 1 30700 9 view .LVU6797
	.loc 1 30699 11 is_stmt 0 view .LVU6798
	sall	$24, %eax
.LVL1788:
	.loc 1 30699 11 view .LVU6799
	movl	%eax, (%rdi,%rcx,4)
.LBE6302:
	.loc 1 30696 5 is_stmt 1 view .LVU6800
	.loc 1 30696 30 is_stmt 0 view .LVU6801
	leaq	5(%rdx), %rcx
.LVL1789:
	.loc 1 30696 19 is_stmt 1 view .LVU6802
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB6303:
	.loc 1 30697 9 view .LVU6803
	.loc 1 30697 18 is_stmt 0 view .LVU6804
	movzbl	5(%rbx,%rdx), %eax
.LVL1790:
	.loc 1 30698 9 is_stmt 1 view .LVU6805
	.loc 1 30698 11 is_stmt 0 view .LVU6806
	addl	$-128, %eax
.LVL1791:
	.loc 1 30699 9 is_stmt 1 view .LVU6807
	.loc 1 30700 9 view .LVU6808
	.loc 1 30699 11 is_stmt 0 view .LVU6809
	sall	$24, %eax
.LVL1792:
	.loc 1 30699 11 view .LVU6810
	movl	%eax, (%rdi,%rcx,4)
.LBE6303:
	.loc 1 30696 5 is_stmt 1 view .LVU6811
	.loc 1 30696 30 is_stmt 0 view .LVU6812
	leaq	6(%rdx), %rcx
.LVL1793:
	.loc 1 30696 19 is_stmt 1 view .LVU6813
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB6304:
	.loc 1 30697 9 view .LVU6814
	.loc 1 30697 18 is_stmt 0 view .LVU6815
	movzbl	6(%rbx,%rdx), %eax
.LVL1794:
	.loc 1 30698 9 is_stmt 1 view .LVU6816
	.loc 1 30698 11 is_stmt 0 view .LVU6817
	addl	$-128, %eax
.LVL1795:
	.loc 1 30699 9 is_stmt 1 view .LVU6818
	.loc 1 30700 9 view .LVU6819
	.loc 1 30699 11 is_stmt 0 view .LVU6820
	sall	$24, %eax
.LVL1796:
	.loc 1 30699 11 view .LVU6821
	movl	%eax, (%rdi,%rcx,4)
.LBE6304:
	.loc 1 30696 5 is_stmt 1 view .LVU6822
	.loc 1 30696 30 is_stmt 0 view .LVU6823
	leaq	7(%rdx), %rcx
.LVL1797:
	.loc 1 30696 19 is_stmt 1 view .LVU6824
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB6305:
	.loc 1 30697 9 view .LVU6825
	.loc 1 30697 18 is_stmt 0 view .LVU6826
	movzbl	7(%rbx,%rdx), %eax
.LVL1798:
	.loc 1 30698 9 is_stmt 1 view .LVU6827
	.loc 1 30698 11 is_stmt 0 view .LVU6828
	addl	$-128, %eax
.LVL1799:
	.loc 1 30699 9 is_stmt 1 view .LVU6829
	.loc 1 30700 9 view .LVU6830
	.loc 1 30699 11 is_stmt 0 view .LVU6831
	sall	$24, %eax
.LVL1800:
	.loc 1 30699 11 view .LVU6832
	movl	%eax, (%rdi,%rcx,4)
.LBE6305:
	.loc 1 30696 5 is_stmt 1 view .LVU6833
	.loc 1 30696 30 is_stmt 0 view .LVU6834
	leaq	8(%rdx), %rcx
.LVL1801:
	.loc 1 30696 19 is_stmt 1 view .LVU6835
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB6306:
	.loc 1 30697 9 view .LVU6836
	.loc 1 30697 18 is_stmt 0 view .LVU6837
	movzbl	8(%rbx,%rdx), %eax
.LVL1802:
	.loc 1 30698 9 is_stmt 1 view .LVU6838
	.loc 1 30698 11 is_stmt 0 view .LVU6839
	addl	$-128, %eax
.LVL1803:
	.loc 1 30699 9 is_stmt 1 view .LVU6840
	.loc 1 30700 9 view .LVU6841
	.loc 1 30699 11 is_stmt 0 view .LVU6842
	sall	$24, %eax
.LVL1804:
	.loc 1 30699 11 view .LVU6843
	movl	%eax, (%rdi,%rcx,4)
.LBE6306:
	.loc 1 30696 5 is_stmt 1 view .LVU6844
	.loc 1 30696 30 is_stmt 0 view .LVU6845
	leaq	9(%rdx), %rcx
.LVL1805:
	.loc 1 30696 19 is_stmt 1 view .LVU6846
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB6307:
	.loc 1 30697 9 view .LVU6847
	.loc 1 30697 18 is_stmt 0 view .LVU6848
	movzbl	9(%rbx,%rdx), %eax
.LVL1806:
	.loc 1 30698 9 is_stmt 1 view .LVU6849
	.loc 1 30698 11 is_stmt 0 view .LVU6850
	addl	$-128, %eax
.LVL1807:
	.loc 1 30699 9 is_stmt 1 view .LVU6851
	.loc 1 30700 9 view .LVU6852
	.loc 1 30699 11 is_stmt 0 view .LVU6853
	sall	$24, %eax
.LVL1808:
	.loc 1 30699 11 view .LVU6854
	movl	%eax, (%rdi,%rcx,4)
.LBE6307:
	.loc 1 30696 5 is_stmt 1 view .LVU6855
	.loc 1 30696 30 is_stmt 0 view .LVU6856
	leaq	10(%rdx), %rcx
.LVL1809:
	.loc 1 30696 19 is_stmt 1 view .LVU6857
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB6308:
	.loc 1 30697 9 view .LVU6858
	.loc 1 30697 18 is_stmt 0 view .LVU6859
	movzbl	10(%rbx,%rdx), %eax
.LVL1810:
	.loc 1 30698 9 is_stmt 1 view .LVU6860
	.loc 1 30698 11 is_stmt 0 view .LVU6861
	addl	$-128, %eax
.LVL1811:
	.loc 1 30699 9 is_stmt 1 view .LVU6862
	.loc 1 30700 9 view .LVU6863
	.loc 1 30699 11 is_stmt 0 view .LVU6864
	sall	$24, %eax
.LVL1812:
	.loc 1 30699 11 view .LVU6865
	movl	%eax, (%rdi,%rcx,4)
.LBE6308:
	.loc 1 30696 5 is_stmt 1 view .LVU6866
	.loc 1 30696 30 is_stmt 0 view .LVU6867
	leaq	11(%rdx), %rcx
.LVL1813:
	.loc 1 30696 19 is_stmt 1 view .LVU6868
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB6309:
	.loc 1 30697 9 view .LVU6869
	.loc 1 30697 18 is_stmt 0 view .LVU6870
	movzbl	11(%rbx,%rdx), %eax
.LVL1814:
	.loc 1 30698 9 is_stmt 1 view .LVU6871
	.loc 1 30698 11 is_stmt 0 view .LVU6872
	addl	$-128, %eax
.LVL1815:
	.loc 1 30699 9 is_stmt 1 view .LVU6873
	.loc 1 30700 9 view .LVU6874
	.loc 1 30699 11 is_stmt 0 view .LVU6875
	sall	$24, %eax
.LVL1816:
	.loc 1 30699 11 view .LVU6876
	movl	%eax, (%rdi,%rcx,4)
.LBE6309:
	.loc 1 30696 5 is_stmt 1 view .LVU6877
	.loc 1 30696 30 is_stmt 0 view .LVU6878
	leaq	12(%rdx), %rcx
.LVL1817:
	.loc 1 30696 19 is_stmt 1 view .LVU6879
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB6310:
	.loc 1 30697 9 view .LVU6880
	.loc 1 30697 18 is_stmt 0 view .LVU6881
	movzbl	12(%rbx,%rdx), %eax
.LVL1818:
	.loc 1 30698 9 is_stmt 1 view .LVU6882
	.loc 1 30698 11 is_stmt 0 view .LVU6883
	addl	$-128, %eax
.LVL1819:
	.loc 1 30699 9 is_stmt 1 view .LVU6884
	.loc 1 30700 9 view .LVU6885
	.loc 1 30699 11 is_stmt 0 view .LVU6886
	sall	$24, %eax
.LVL1820:
	.loc 1 30699 11 view .LVU6887
	movl	%eax, (%rdi,%rcx,4)
.LBE6310:
	.loc 1 30696 5 is_stmt 1 view .LVU6888
	.loc 1 30696 30 is_stmt 0 view .LVU6889
	leaq	13(%rdx), %rcx
.LVL1821:
	.loc 1 30696 19 is_stmt 1 view .LVU6890
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB6311:
	.loc 1 30697 9 view .LVU6891
	.loc 1 30697 18 is_stmt 0 view .LVU6892
	movzbl	13(%rbx,%rdx), %eax
.LVL1822:
	.loc 1 30698 9 is_stmt 1 view .LVU6893
	.loc 1 30698 11 is_stmt 0 view .LVU6894
	addl	$-128, %eax
.LVL1823:
	.loc 1 30699 9 is_stmt 1 view .LVU6895
	.loc 1 30700 9 view .LVU6896
	.loc 1 30699 11 is_stmt 0 view .LVU6897
	sall	$24, %eax
.LVL1824:
	.loc 1 30699 11 view .LVU6898
	movl	%eax, (%rdi,%rcx,4)
.LBE6311:
	.loc 1 30696 5 is_stmt 1 view .LVU6899
	.loc 1 30696 30 is_stmt 0 view .LVU6900
	leaq	14(%rdx), %rcx
.LVL1825:
	.loc 1 30696 19 is_stmt 1 view .LVU6901
	cmpq	%rcx, %r8
	jbe	.L1050
.LBB6312:
	.loc 1 30697 9 view .LVU6902
	.loc 1 30697 18 is_stmt 0 view .LVU6903
	movzbl	14(%rbx,%rdx), %eax
.LVL1826:
	.loc 1 30698 9 is_stmt 1 view .LVU6904
	.loc 1 30698 11 is_stmt 0 view .LVU6905
	addl	$-128, %eax
.LVL1827:
	.loc 1 30699 9 is_stmt 1 view .LVU6906
	.loc 1 30700 9 view .LVU6907
	.loc 1 30699 11 is_stmt 0 view .LVU6908
	sall	$24, %eax
.LVL1828:
	.loc 1 30699 11 view .LVU6909
	movl	%eax, (%rdi,%rcx,4)
.LBE6312:
	.loc 1 30696 5 is_stmt 1 view .LVU6910
.LVL1829:
	.loc 1 30696 19 view .LVU6911
	jmp	.L1050
.LVL1830:
	.p2align 4,,10
	.p2align 3
.L1270:
	.loc 1 30696 19 is_stmt 0 view .LVU6912
.LBE6295:
.LBE6294:
.LBE6293:
.LBE6292:
.LBE6291:
.LBB6318:
.LBB4413:
.LBB4356:
.LBB4297:
.LBB4025:
.LBB3989:
.LBB3920:
.LBB3787:
.LBB3779:
.LBB3772:
.LBB3771:
	.loc 1 2369 18 view .LVU6913
	movss	-104(%rbp), %xmm5
	mulss	%xmm4, %xmm5
	.loc 1 2369 25 view .LVU6914
	addss	%xmm8, %xmm5
	jmp	.L1265
.LVL1831:
.L1209:
	.loc 1 2369 25 view .LVU6915
.LBE3771:
.LBE3772:
.LBE3779:
.LBE3787:
.LBE3920:
.LBE3989:
.LBE4025:
.LBE4297:
.LBE4356:
.LBE4413:
.LBE6318:
.LBB6319:
.LBB5725:
.LBB5694:
.LBB5664:
	.loc 1 31996 5 is_stmt 1 view .LVU6916
.LBB5634:
	.loc 1 31996 19 view .LVU6917
	testq	%r8, %r8
	je	.L1050
.LVL1832:
.L1286:
	.loc 1 31996 19 is_stmt 0 view .LVU6918
	leaq	(%rbx,%r8,4), %rax
	cmpq	%rax, %rdi
	leaq	(%rdi,%r8), %rax
	setnb	%dl
.LVL1833:
	.loc 1 31996 19 view .LVU6919
	cmpq	%rax, %rbx
	setnb	%al
	orb	%al, %dl
	je	.L1308
	leaq	-1(%r8), %rax
	cmpq	$14, %rax
	jbe	.L1308
	movq	%r8, %rcx
	movaps	.LC87(%rip), %xmm2
	movq	%rbx, %rax
	movq	%rdi, %rdx
	shrq	$4, %rcx
	movdqa	.LC76(%rip), %xmm3
	movaps	.LC86(%rip), %xmm5
	salq	$6, %rcx
	movaps	.LC102(%rip), %xmm6
	addq	%rbx, %rcx
.LVL1834:
	.p2align 4,,10
	.p2align 3
.L1213:
.LBB5589:
	.loc 1 31997 9 is_stmt 1 view .LVU6920
	.loc 1 31998 9 view .LVU6921
.LBB5556:
	.loc 1 2528 24 view .LVU6922
.LBE5556:
.LBE5589:
.LBE5634:
.LBE5664:
.LBE5694:
.LBE5725:
.LBE6319:
	.loc 1 2530 5 view .LVU6923
	.loc 1 2533 5 view .LVU6924
.LBB6320:
.LBB5726:
.LBB5695:
.LBB5665:
.LBB5635:
.LBB5590:
	.loc 1 31999 9 view .LVU6925
	.loc 1 32000 9 view .LVU6926
	.loc 1 32001 9 view .LVU6927
	.loc 1 32003 9 view .LVU6928
	.loc 1 31999 23 is_stmt 0 view .LVU6929
	movups	(%rax), %xmm0
	movups	16(%rax), %xmm1
	addq	$64, %rax
	addq	$16, %rdx
	minps	%xmm5, %xmm0
	minps	%xmm5, %xmm1
	.loc 1 32000 11 view .LVU6930
	maxps	%xmm2, %xmm0
	maxps	%xmm2, %xmm1
	addps	%xmm5, %xmm0
	addps	%xmm5, %xmm1
	.loc 1 32001 11 view .LVU6931
	mulps	%xmm6, %xmm0
	mulps	%xmm6, %xmm1
	.loc 1 32003 21 view .LVU6932
	cvttps2dq	%xmm0, %xmm0
	movdqa	%xmm0, %xmm4
	cvttps2dq	%xmm1, %xmm1
	punpcklwd	%xmm1, %xmm0
	punpckhwd	%xmm1, %xmm4
	movdqa	%xmm0, %xmm1
	punpcklwd	%xmm4, %xmm0
	punpckhwd	%xmm4, %xmm1
	.loc 1 31999 23 view .LVU6933
	movups	-16(%rax), %xmm4
	.loc 1 32003 21 view .LVU6934
	punpcklwd	%xmm1, %xmm0
	.loc 1 31999 23 view .LVU6935
	movups	-32(%rax), %xmm1
	minps	%xmm5, %xmm4
	.loc 1 32003 21 view .LVU6936
	pand	%xmm3, %xmm0
	.loc 1 31999 23 view .LVU6937
	minps	%xmm5, %xmm1
	.loc 1 32000 11 view .LVU6938
	maxps	%xmm2, %xmm4
	maxps	%xmm2, %xmm1
	addps	%xmm5, %xmm4
	addps	%xmm5, %xmm1
	.loc 1 32001 11 view .LVU6939
	mulps	%xmm6, %xmm4
	mulps	%xmm6, %xmm1
	.loc 1 32003 21 view .LVU6940
	cvttps2dq	%xmm4, %xmm4
	cvttps2dq	%xmm1, %xmm1
	movdqa	%xmm1, %xmm7
	punpcklwd	%xmm4, %xmm1
	punpckhwd	%xmm4, %xmm7
	movdqa	%xmm1, %xmm4
	punpckhwd	%xmm7, %xmm4
	punpcklwd	%xmm7, %xmm1
	punpcklwd	%xmm4, %xmm1
	pand	%xmm3, %xmm1
	packuswb	%xmm1, %xmm0
	.loc 1 32003 19 view .LVU6941
	movups	%xmm0, -16(%rdx)
	.loc 1 32003 19 view .LVU6942
.LBE5590:
	.loc 1 31996 5 is_stmt 1 view .LVU6943
	.loc 1 31996 19 view .LVU6944
	cmpq	%rcx, %rax
	jne	.L1213
	movq	%r8, %rax
	andq	$-16, %rax
	testb	$15, %r8b
	je	.L1050
.LVL1835:
.LBB5591:
	.loc 1 31997 9 view .LVU6945
	.loc 1 31998 9 view .LVU6946
.LBB5557:
	.loc 1 2528 24 view .LVU6947
.LBE5557:
.LBE5591:
.LBE5635:
.LBE5665:
.LBE5695:
.LBE5726:
.LBE6320:
	.loc 1 2530 5 view .LVU6948
	.loc 1 2533 5 view .LVU6949
.LBB6321:
.LBB5727:
.LBB5696:
.LBB5666:
.LBB5636:
.LBB5592:
	.loc 1 31999 9 view .LVU6950
	.loc 1 31999 23 is_stmt 0 view .LVU6951
	movss	.LC77(%rip), %xmm0
	movss	(%rbx,%rax,4), %xmm1
	movss	.LC88(%rip), %xmm3
	.loc 1 32001 11 view .LVU6952
	movss	.LC103(%rip), %xmm5
	.loc 1 31999 23 view .LVU6953
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL1836:
	.loc 1 32000 9 is_stmt 1 view .LVU6954
	.loc 1 32000 11 is_stmt 0 view .LVU6955
	addss	%xmm0, %xmm1
.LVL1837:
	.loc 1 32001 9 is_stmt 1 view .LVU6956
	.loc 1 32003 9 view .LVU6957
	.loc 1 32001 11 is_stmt 0 view .LVU6958
	mulss	%xmm5, %xmm1
.LVL1838:
	.loc 1 32003 21 view .LVU6959
	cvttss2sil	%xmm1, %edx
	movb	%dl, (%rdi,%rax)
.LBE5592:
	.loc 1 31996 5 is_stmt 1 view .LVU6960
	.loc 1 31996 30 is_stmt 0 view .LVU6961
	leaq	1(%rax), %rdx
.LVL1839:
	.loc 1 31996 19 is_stmt 1 view .LVU6962
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5593:
	.loc 1 31997 9 view .LVU6963
.LVL1840:
	.loc 1 31998 9 view .LVU6964
.LBB5558:
	.loc 1 2528 24 view .LVU6965
.LBE5558:
.LBE5593:
.LBE5636:
.LBE5666:
.LBE5696:
.LBE5727:
.LBE6321:
	.loc 1 2530 5 view .LVU6966
	.loc 1 2533 5 view .LVU6967
.LBB6322:
.LBB5728:
.LBB5697:
.LBB5667:
.LBB5637:
.LBB5594:
	.loc 1 31999 9 view .LVU6968
	.loc 1 31999 23 is_stmt 0 view .LVU6969
	movss	(%rbx,%rdx,4), %xmm1
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL1841:
	.loc 1 32000 9 is_stmt 1 view .LVU6970
	.loc 1 32000 11 is_stmt 0 view .LVU6971
	addss	%xmm0, %xmm1
.LVL1842:
	.loc 1 32001 9 is_stmt 1 view .LVU6972
	.loc 1 32003 9 view .LVU6973
	.loc 1 32001 11 is_stmt 0 view .LVU6974
	mulss	%xmm5, %xmm1
.LVL1843:
	.loc 1 32003 21 view .LVU6975
	cvttss2sil	%xmm1, %edx
.LVL1844:
	.loc 1 32003 21 view .LVU6976
	movb	%dl, 1(%rdi,%rax)
.LBE5594:
	.loc 1 31996 5 is_stmt 1 view .LVU6977
	.loc 1 31996 30 is_stmt 0 view .LVU6978
	leaq	2(%rax), %rdx
.LVL1845:
	.loc 1 31996 19 is_stmt 1 view .LVU6979
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5595:
	.loc 1 31997 9 view .LVU6980
.LVL1846:
	.loc 1 31998 9 view .LVU6981
.LBB5559:
	.loc 1 2528 24 view .LVU6982
.LBE5559:
.LBE5595:
.LBE5637:
.LBE5667:
.LBE5697:
.LBE5728:
.LBE6322:
	.loc 1 2530 5 view .LVU6983
	.loc 1 2533 5 view .LVU6984
.LBB6323:
.LBB5729:
.LBB5698:
.LBB5668:
.LBB5638:
.LBB5596:
	.loc 1 31999 9 view .LVU6985
	.loc 1 31999 23 is_stmt 0 view .LVU6986
	movss	(%rbx,%rdx,4), %xmm1
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL1847:
	.loc 1 32000 9 is_stmt 1 view .LVU6987
	.loc 1 32000 11 is_stmt 0 view .LVU6988
	addss	%xmm0, %xmm1
.LVL1848:
	.loc 1 32001 9 is_stmt 1 view .LVU6989
	.loc 1 32003 9 view .LVU6990
	.loc 1 32001 11 is_stmt 0 view .LVU6991
	mulss	%xmm5, %xmm1
.LVL1849:
	.loc 1 32003 21 view .LVU6992
	cvttss2sil	%xmm1, %edx
.LVL1850:
	.loc 1 32003 21 view .LVU6993
	movb	%dl, 2(%rdi,%rax)
.LBE5596:
	.loc 1 31996 5 is_stmt 1 view .LVU6994
	.loc 1 31996 30 is_stmt 0 view .LVU6995
	leaq	3(%rax), %rdx
.LVL1851:
	.loc 1 31996 19 is_stmt 1 view .LVU6996
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5597:
	.loc 1 31997 9 view .LVU6997
.LVL1852:
	.loc 1 31998 9 view .LVU6998
.LBB5560:
	.loc 1 2528 24 view .LVU6999
.LBE5560:
.LBE5597:
.LBE5638:
.LBE5668:
.LBE5698:
.LBE5729:
.LBE6323:
	.loc 1 2530 5 view .LVU7000
	.loc 1 2533 5 view .LVU7001
.LBB6324:
.LBB5730:
.LBB5699:
.LBB5669:
.LBB5639:
.LBB5598:
	.loc 1 31999 9 view .LVU7002
	.loc 1 31999 23 is_stmt 0 view .LVU7003
	movss	(%rbx,%rdx,4), %xmm1
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL1853:
	.loc 1 32000 9 is_stmt 1 view .LVU7004
	.loc 1 32000 11 is_stmt 0 view .LVU7005
	addss	%xmm0, %xmm1
.LVL1854:
	.loc 1 32001 9 is_stmt 1 view .LVU7006
	.loc 1 32003 9 view .LVU7007
	.loc 1 32001 11 is_stmt 0 view .LVU7008
	mulss	%xmm5, %xmm1
.LVL1855:
	.loc 1 32003 21 view .LVU7009
	cvttss2sil	%xmm1, %edx
.LVL1856:
	.loc 1 32003 21 view .LVU7010
	movb	%dl, 3(%rdi,%rax)
.LBE5598:
	.loc 1 31996 5 is_stmt 1 view .LVU7011
	.loc 1 31996 30 is_stmt 0 view .LVU7012
	leaq	4(%rax), %rdx
.LVL1857:
	.loc 1 31996 19 is_stmt 1 view .LVU7013
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5599:
	.loc 1 31997 9 view .LVU7014
.LVL1858:
	.loc 1 31998 9 view .LVU7015
.LBB5561:
	.loc 1 2528 24 view .LVU7016
.LBE5561:
.LBE5599:
.LBE5639:
.LBE5669:
.LBE5699:
.LBE5730:
.LBE6324:
	.loc 1 2530 5 view .LVU7017
	.loc 1 2533 5 view .LVU7018
.LBB6325:
.LBB5731:
.LBB5700:
.LBB5670:
.LBB5640:
.LBB5600:
	.loc 1 31999 9 view .LVU7019
	.loc 1 31999 23 is_stmt 0 view .LVU7020
	movss	(%rbx,%rdx,4), %xmm1
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL1859:
	.loc 1 32000 9 is_stmt 1 view .LVU7021
	.loc 1 32000 11 is_stmt 0 view .LVU7022
	addss	%xmm0, %xmm1
.LVL1860:
	.loc 1 32001 9 is_stmt 1 view .LVU7023
	.loc 1 32003 9 view .LVU7024
	.loc 1 32001 11 is_stmt 0 view .LVU7025
	mulss	%xmm5, %xmm1
.LVL1861:
	.loc 1 32003 21 view .LVU7026
	cvttss2sil	%xmm1, %edx
.LVL1862:
	.loc 1 32003 21 view .LVU7027
	movb	%dl, 4(%rdi,%rax)
.LBE5600:
	.loc 1 31996 5 is_stmt 1 view .LVU7028
	.loc 1 31996 30 is_stmt 0 view .LVU7029
	leaq	5(%rax), %rdx
.LVL1863:
	.loc 1 31996 19 is_stmt 1 view .LVU7030
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5601:
	.loc 1 31997 9 view .LVU7031
.LVL1864:
	.loc 1 31998 9 view .LVU7032
.LBB5562:
	.loc 1 2528 24 view .LVU7033
.LBE5562:
.LBE5601:
.LBE5640:
.LBE5670:
.LBE5700:
.LBE5731:
.LBE6325:
	.loc 1 2530 5 view .LVU7034
	.loc 1 2533 5 view .LVU7035
.LBB6326:
.LBB5732:
.LBB5701:
.LBB5671:
.LBB5641:
.LBB5602:
	.loc 1 31999 9 view .LVU7036
	.loc 1 31999 23 is_stmt 0 view .LVU7037
	movss	(%rbx,%rdx,4), %xmm1
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL1865:
	.loc 1 32000 9 is_stmt 1 view .LVU7038
	.loc 1 32000 11 is_stmt 0 view .LVU7039
	addss	%xmm0, %xmm1
.LVL1866:
	.loc 1 32001 9 is_stmt 1 view .LVU7040
	.loc 1 32003 9 view .LVU7041
	.loc 1 32001 11 is_stmt 0 view .LVU7042
	mulss	%xmm5, %xmm1
.LVL1867:
	.loc 1 32003 21 view .LVU7043
	cvttss2sil	%xmm1, %edx
.LVL1868:
	.loc 1 32003 21 view .LVU7044
	movb	%dl, 5(%rdi,%rax)
.LBE5602:
	.loc 1 31996 5 is_stmt 1 view .LVU7045
	.loc 1 31996 30 is_stmt 0 view .LVU7046
	leaq	6(%rax), %rdx
.LVL1869:
	.loc 1 31996 19 is_stmt 1 view .LVU7047
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5603:
	.loc 1 31997 9 view .LVU7048
.LVL1870:
	.loc 1 31998 9 view .LVU7049
.LBB5563:
	.loc 1 2528 24 view .LVU7050
.LBE5563:
.LBE5603:
.LBE5641:
.LBE5671:
.LBE5701:
.LBE5732:
.LBE6326:
	.loc 1 2530 5 view .LVU7051
	.loc 1 2533 5 view .LVU7052
.LBB6327:
.LBB5733:
.LBB5702:
.LBB5672:
.LBB5642:
.LBB5604:
	.loc 1 31999 9 view .LVU7053
	.loc 1 31999 23 is_stmt 0 view .LVU7054
	movss	(%rbx,%rdx,4), %xmm1
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL1871:
	.loc 1 32000 9 is_stmt 1 view .LVU7055
	.loc 1 32000 11 is_stmt 0 view .LVU7056
	addss	%xmm0, %xmm1
.LVL1872:
	.loc 1 32001 9 is_stmt 1 view .LVU7057
	.loc 1 32003 9 view .LVU7058
	.loc 1 32001 11 is_stmt 0 view .LVU7059
	mulss	%xmm5, %xmm1
.LVL1873:
	.loc 1 32003 21 view .LVU7060
	cvttss2sil	%xmm1, %edx
.LVL1874:
	.loc 1 32003 21 view .LVU7061
	movb	%dl, 6(%rdi,%rax)
.LBE5604:
	.loc 1 31996 5 is_stmt 1 view .LVU7062
	.loc 1 31996 30 is_stmt 0 view .LVU7063
	leaq	7(%rax), %rdx
.LVL1875:
	.loc 1 31996 19 is_stmt 1 view .LVU7064
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5605:
	.loc 1 31997 9 view .LVU7065
.LVL1876:
	.loc 1 31998 9 view .LVU7066
.LBB5564:
	.loc 1 2528 24 view .LVU7067
.LBE5564:
.LBE5605:
.LBE5642:
.LBE5672:
.LBE5702:
.LBE5733:
.LBE6327:
	.loc 1 2530 5 view .LVU7068
	.loc 1 2533 5 view .LVU7069
.LBB6328:
.LBB5734:
.LBB5703:
.LBB5673:
.LBB5643:
.LBB5606:
	.loc 1 31999 9 view .LVU7070
	.loc 1 31999 23 is_stmt 0 view .LVU7071
	movss	(%rbx,%rdx,4), %xmm1
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL1877:
	.loc 1 32000 9 is_stmt 1 view .LVU7072
	.loc 1 32000 11 is_stmt 0 view .LVU7073
	addss	%xmm0, %xmm1
.LVL1878:
	.loc 1 32001 9 is_stmt 1 view .LVU7074
	.loc 1 32003 9 view .LVU7075
	.loc 1 32001 11 is_stmt 0 view .LVU7076
	mulss	%xmm5, %xmm1
.LVL1879:
	.loc 1 32003 21 view .LVU7077
	cvttss2sil	%xmm1, %edx
.LVL1880:
	.loc 1 32003 21 view .LVU7078
	movb	%dl, 7(%rdi,%rax)
.LBE5606:
	.loc 1 31996 5 is_stmt 1 view .LVU7079
	.loc 1 31996 30 is_stmt 0 view .LVU7080
	leaq	8(%rax), %rdx
.LVL1881:
	.loc 1 31996 19 is_stmt 1 view .LVU7081
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5607:
	.loc 1 31997 9 view .LVU7082
.LVL1882:
	.loc 1 31998 9 view .LVU7083
.LBB5565:
	.loc 1 2528 24 view .LVU7084
.LBE5565:
.LBE5607:
.LBE5643:
.LBE5673:
.LBE5703:
.LBE5734:
.LBE6328:
	.loc 1 2530 5 view .LVU7085
	.loc 1 2533 5 view .LVU7086
.LBB6329:
.LBB5735:
.LBB5704:
.LBB5674:
.LBB5644:
.LBB5608:
	.loc 1 31999 9 view .LVU7087
	.loc 1 31999 23 is_stmt 0 view .LVU7088
	movss	(%rbx,%rdx,4), %xmm1
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL1883:
	.loc 1 32000 9 is_stmt 1 view .LVU7089
	.loc 1 32000 11 is_stmt 0 view .LVU7090
	addss	%xmm0, %xmm1
.LVL1884:
	.loc 1 32001 9 is_stmt 1 view .LVU7091
	.loc 1 32003 9 view .LVU7092
	.loc 1 32001 11 is_stmt 0 view .LVU7093
	mulss	%xmm5, %xmm1
.LVL1885:
	.loc 1 32003 21 view .LVU7094
	cvttss2sil	%xmm1, %edx
.LVL1886:
	.loc 1 32003 21 view .LVU7095
	movb	%dl, 8(%rdi,%rax)
.LBE5608:
	.loc 1 31996 5 is_stmt 1 view .LVU7096
	.loc 1 31996 30 is_stmt 0 view .LVU7097
	leaq	9(%rax), %rdx
.LVL1887:
	.loc 1 31996 19 is_stmt 1 view .LVU7098
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5609:
	.loc 1 31997 9 view .LVU7099
.LVL1888:
	.loc 1 31998 9 view .LVU7100
.LBB5566:
	.loc 1 2528 24 view .LVU7101
.LBE5566:
.LBE5609:
.LBE5644:
.LBE5674:
.LBE5704:
.LBE5735:
.LBE6329:
	.loc 1 2530 5 view .LVU7102
	.loc 1 2533 5 view .LVU7103
.LBB6330:
.LBB5736:
.LBB5705:
.LBB5675:
.LBB5645:
.LBB5610:
	.loc 1 31999 9 view .LVU7104
	.loc 1 31999 23 is_stmt 0 view .LVU7105
	movss	(%rbx,%rdx,4), %xmm1
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL1889:
	.loc 1 32000 9 is_stmt 1 view .LVU7106
	.loc 1 32000 11 is_stmt 0 view .LVU7107
	addss	%xmm0, %xmm1
.LVL1890:
	.loc 1 32001 9 is_stmt 1 view .LVU7108
	.loc 1 32003 9 view .LVU7109
	.loc 1 32001 11 is_stmt 0 view .LVU7110
	mulss	%xmm5, %xmm1
.LVL1891:
	.loc 1 32003 21 view .LVU7111
	cvttss2sil	%xmm1, %edx
.LVL1892:
	.loc 1 32003 21 view .LVU7112
	movb	%dl, 9(%rdi,%rax)
.LBE5610:
	.loc 1 31996 5 is_stmt 1 view .LVU7113
	.loc 1 31996 30 is_stmt 0 view .LVU7114
	leaq	10(%rax), %rdx
.LVL1893:
	.loc 1 31996 19 is_stmt 1 view .LVU7115
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5611:
	.loc 1 31997 9 view .LVU7116
.LVL1894:
	.loc 1 31998 9 view .LVU7117
.LBB5567:
	.loc 1 2528 24 view .LVU7118
.LBE5567:
.LBE5611:
.LBE5645:
.LBE5675:
.LBE5705:
.LBE5736:
.LBE6330:
	.loc 1 2530 5 view .LVU7119
	.loc 1 2533 5 view .LVU7120
.LBB6331:
.LBB5737:
.LBB5706:
.LBB5676:
.LBB5646:
.LBB5612:
	.loc 1 31999 9 view .LVU7121
	.loc 1 31999 23 is_stmt 0 view .LVU7122
	movss	(%rbx,%rdx,4), %xmm1
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL1895:
	.loc 1 32000 9 is_stmt 1 view .LVU7123
	.loc 1 32000 11 is_stmt 0 view .LVU7124
	addss	%xmm0, %xmm1
.LVL1896:
	.loc 1 32001 9 is_stmt 1 view .LVU7125
	.loc 1 32003 9 view .LVU7126
	.loc 1 32001 11 is_stmt 0 view .LVU7127
	mulss	%xmm5, %xmm1
.LVL1897:
	.loc 1 32003 21 view .LVU7128
	cvttss2sil	%xmm1, %edx
.LVL1898:
	.loc 1 32003 21 view .LVU7129
	movb	%dl, 10(%rdi,%rax)
.LBE5612:
	.loc 1 31996 5 is_stmt 1 view .LVU7130
	.loc 1 31996 30 is_stmt 0 view .LVU7131
	leaq	11(%rax), %rdx
.LVL1899:
	.loc 1 31996 19 is_stmt 1 view .LVU7132
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5613:
	.loc 1 31997 9 view .LVU7133
.LVL1900:
	.loc 1 31998 9 view .LVU7134
.LBB5568:
	.loc 1 2528 24 view .LVU7135
.LBE5568:
.LBE5613:
.LBE5646:
.LBE5676:
.LBE5706:
.LBE5737:
.LBE6331:
	.loc 1 2530 5 view .LVU7136
	.loc 1 2533 5 view .LVU7137
.LBB6332:
.LBB5738:
.LBB5707:
.LBB5677:
.LBB5647:
.LBB5614:
	.loc 1 31999 9 view .LVU7138
	.loc 1 31999 23 is_stmt 0 view .LVU7139
	movss	(%rbx,%rdx,4), %xmm1
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL1901:
	.loc 1 32000 9 is_stmt 1 view .LVU7140
	.loc 1 32000 11 is_stmt 0 view .LVU7141
	addss	%xmm0, %xmm1
.LVL1902:
	.loc 1 32001 9 is_stmt 1 view .LVU7142
	.loc 1 32003 9 view .LVU7143
	.loc 1 32001 11 is_stmt 0 view .LVU7144
	mulss	%xmm5, %xmm1
.LVL1903:
	.loc 1 32003 21 view .LVU7145
	cvttss2sil	%xmm1, %edx
.LVL1904:
	.loc 1 32003 21 view .LVU7146
	movb	%dl, 11(%rdi,%rax)
.LBE5614:
	.loc 1 31996 5 is_stmt 1 view .LVU7147
	.loc 1 31996 30 is_stmt 0 view .LVU7148
	leaq	12(%rax), %rdx
.LVL1905:
	.loc 1 31996 19 is_stmt 1 view .LVU7149
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5615:
	.loc 1 31997 9 view .LVU7150
.LVL1906:
	.loc 1 31998 9 view .LVU7151
.LBB5569:
	.loc 1 2528 24 view .LVU7152
.LBE5569:
.LBE5615:
.LBE5647:
.LBE5677:
.LBE5707:
.LBE5738:
.LBE6332:
	.loc 1 2530 5 view .LVU7153
	.loc 1 2533 5 view .LVU7154
.LBB6333:
.LBB5739:
.LBB5708:
.LBB5678:
.LBB5648:
.LBB5616:
	.loc 1 31999 9 view .LVU7155
	.loc 1 31999 23 is_stmt 0 view .LVU7156
	movss	(%rbx,%rdx,4), %xmm1
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL1907:
	.loc 1 32000 9 is_stmt 1 view .LVU7157
	.loc 1 32000 11 is_stmt 0 view .LVU7158
	addss	%xmm0, %xmm1
.LVL1908:
	.loc 1 32001 9 is_stmt 1 view .LVU7159
	.loc 1 32003 9 view .LVU7160
	.loc 1 32001 11 is_stmt 0 view .LVU7161
	mulss	%xmm5, %xmm1
.LVL1909:
	.loc 1 32003 21 view .LVU7162
	cvttss2sil	%xmm1, %edx
.LVL1910:
	.loc 1 32003 21 view .LVU7163
	movb	%dl, 12(%rdi,%rax)
.LBE5616:
	.loc 1 31996 5 is_stmt 1 view .LVU7164
	.loc 1 31996 30 is_stmt 0 view .LVU7165
	leaq	13(%rax), %rdx
.LVL1911:
	.loc 1 31996 19 is_stmt 1 view .LVU7166
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5617:
	.loc 1 31997 9 view .LVU7167
.LVL1912:
	.loc 1 31998 9 view .LVU7168
.LBB5570:
	.loc 1 2528 24 view .LVU7169
.LBE5570:
.LBE5617:
.LBE5648:
.LBE5678:
.LBE5708:
.LBE5739:
.LBE6333:
	.loc 1 2530 5 view .LVU7170
	.loc 1 2533 5 view .LVU7171
.LBB6334:
.LBB5740:
.LBB5709:
.LBB5679:
.LBB5649:
.LBB5618:
	.loc 1 31999 9 view .LVU7172
	.loc 1 31999 23 is_stmt 0 view .LVU7173
	movss	(%rbx,%rdx,4), %xmm1
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL1913:
	.loc 1 32000 9 is_stmt 1 view .LVU7174
	.loc 1 32000 11 is_stmt 0 view .LVU7175
	addss	%xmm0, %xmm1
.LVL1914:
	.loc 1 32001 9 is_stmt 1 view .LVU7176
	.loc 1 32003 9 view .LVU7177
	.loc 1 32001 11 is_stmt 0 view .LVU7178
	mulss	%xmm5, %xmm1
.LVL1915:
	.loc 1 32003 21 view .LVU7179
	cvttss2sil	%xmm1, %edx
.LVL1916:
	.loc 1 32003 21 view .LVU7180
	movb	%dl, 13(%rdi,%rax)
.LBE5618:
	.loc 1 31996 5 is_stmt 1 view .LVU7181
	.loc 1 31996 30 is_stmt 0 view .LVU7182
	leaq	14(%rax), %rdx
.LVL1917:
	.loc 1 31996 19 is_stmt 1 view .LVU7183
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5619:
	.loc 1 31997 9 view .LVU7184
.LVL1918:
	.loc 1 31998 9 view .LVU7185
.LBB5571:
	.loc 1 2528 24 view .LVU7186
.LBE5571:
.LBE5619:
.LBE5649:
.LBE5679:
.LBE5709:
.LBE5740:
.LBE6334:
	.loc 1 2530 5 view .LVU7187
	.loc 1 2533 5 view .LVU7188
.LBB6335:
.LBB5741:
.LBB5710:
.LBB5680:
.LBB5650:
.LBB5620:
	.loc 1 31999 9 view .LVU7189
	.loc 1 31999 23 is_stmt 0 view .LVU7190
	movss	(%rbx,%rdx,4), %xmm1
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL1919:
	.loc 1 32000 9 is_stmt 1 view .LVU7191
	.loc 1 32000 11 is_stmt 0 view .LVU7192
	addss	%xmm1, %xmm0
.LVL1920:
	.loc 1 32001 9 is_stmt 1 view .LVU7193
	.loc 1 32003 9 view .LVU7194
	.loc 1 32001 11 is_stmt 0 view .LVU7195
	mulss	%xmm5, %xmm0
.LVL1921:
	.loc 1 32003 21 view .LVU7196
	cvttss2sil	%xmm0, %edx
.LVL1922:
	.loc 1 32003 21 view .LVU7197
	movb	%dl, 14(%rdi,%rax)
.LBE5620:
	.loc 1 31996 5 is_stmt 1 view .LVU7198
.LVL1923:
	.loc 1 31996 19 view .LVU7199
	jmp	.L1050
.LVL1924:
.L1087:
	.loc 1 31996 19 is_stmt 0 view .LVU7200
.LBE5650:
.LBE5680:
.LBE5710:
.LBE5741:
.LBE6335:
.LBB6336:
.LBB5072:
.LBB5073:
.LBB5074:
.LBB5075:
.LBB5076:
.LBB5077:
	.loc 1 30916 23 is_stmt 1 view .LVU7201
	testq	%r8, %r8
	je	.L1050
	movl	_ZL7g_maLCG(%rip), %eax
	cmpl	$1, %r9d
	je	.L1291
	cmpl	$2, %r9d
	je	.L1292
	leaq	(%rdx,%r8,2), %rax
	cmpq	%rax, %rdi
	leaq	(%rdi,%r8), %rax
	setnb	%dl
.LVL1925:
	.loc 1 30916 23 is_stmt 0 view .LVU7202
	cmpq	%rax, %rbx
	setnb	%al
	orb	%al, %dl
	je	.L1293
	leaq	-1(%r8), %rax
	cmpq	$14, %rax
	jbe	.L1293
	movq	%r8, %rdx
	movdqa	.LC83(%rip), %xmm2
	movdqa	.LC76(%rip), %xmm3
	xorl	%eax, %eax
	andq	$-16, %rdx
.LVL1926:
	.p2align 4,,10
	.p2align 3
.L1096:
.LBB5078:
	.loc 1 30917 13 is_stmt 1 view .LVU7203
	.loc 1 30920 13 view .LVU7204
.LBB5079:
.LBI5079:
	.loc 1 2540 27 view .LVU7205
.LBE5079:
.LBE5078:
.LBE5077:
.LBE5076:
.LBE5075:
.LBE5074:
.LBE5073:
.LBE5072:
.LBE6336:
	.loc 1 2542 5 view .LVU7206
	.loc 1 2546 5 view .LVU7207
.LBB6337:
.LBB5352:
.LBB5327:
.LBB5302:
.LBB5277:
.LBB5252:
.LBB5227:
.LBB5185:
	.loc 1 30922 17 view .LVU7208
	.loc 1 30927 13 view .LVU7209
	.loc 1 30928 13 view .LVU7210
	.loc 1 30929 13 view .LVU7211
	.loc 1 30927 15 is_stmt 0 view .LVU7212
	movdqu	(%rbx,%rax,2), %xmm0
	movdqu	16(%rbx,%rax,2), %xmm1
	psraw	$8, %xmm0
	psraw	$8, %xmm1
	.loc 1 30928 30 view .LVU7213
	pand	%xmm3, %xmm0
	pand	%xmm3, %xmm1
	packuswb	%xmm1, %xmm0
	paddb	%xmm2, %xmm0
	.loc 1 30929 23 view .LVU7214
	movups	%xmm0, (%rdi,%rax)
.LBE5185:
	.loc 1 30916 9 is_stmt 1 view .LVU7215
	.loc 1 30916 23 view .LVU7216
	addq	$16, %rax
	cmpq	%rax, %rdx
	jne	.L1096
	movq	%r8, %rax
	andq	$-16, %rax
	testb	$15, %r8b
	je	.L1050
.LVL1927:
.LBB5186:
	.loc 1 30917 13 view .LVU7217
	.loc 1 30920 13 view .LVU7218
.LBB5159:
	.loc 1 2540 27 view .LVU7219
.LBE5159:
.LBE5186:
.LBE5227:
.LBE5252:
.LBE5277:
.LBE5302:
.LBE5327:
.LBE5352:
.LBE6337:
	.loc 1 2542 5 view .LVU7220
	.loc 1 2546 5 view .LVU7221
.LBB6338:
.LBB5353:
.LBB5328:
.LBB5303:
.LBB5278:
.LBB5253:
.LBB5228:
.LBB5187:
	.loc 1 30922 17 view .LVU7222
	.loc 1 30927 13 view .LVU7223
	.loc 1 30928 13 view .LVU7224
	.loc 1 30929 13 view .LVU7225
	.loc 1 30927 15 is_stmt 0 view .LVU7226
	movsbw	1(%rbx,%rax,2), %dx
	.loc 1 30928 30 view .LVU7227
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU7228
	movb	%dl, (%rdi,%rax)
.LBE5187:
	.loc 1 30916 9 is_stmt 1 view .LVU7229
	.loc 1 30916 34 is_stmt 0 view .LVU7230
	leaq	1(%rax), %rdx
.LVL1928:
	.loc 1 30916 23 is_stmt 1 view .LVU7231
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5188:
	.loc 1 30917 13 view .LVU7232
.LVL1929:
	.loc 1 30920 13 view .LVU7233
.LBB5160:
	.loc 1 2540 27 view .LVU7234
.LBE5160:
.LBE5188:
.LBE5228:
.LBE5253:
.LBE5278:
.LBE5303:
.LBE5328:
.LBE5353:
.LBE6338:
	.loc 1 2542 5 view .LVU7235
	.loc 1 2546 5 view .LVU7236
.LBB6339:
.LBB5354:
.LBB5329:
.LBB5304:
.LBB5279:
.LBB5254:
.LBB5229:
.LBB5189:
	.loc 1 30922 17 view .LVU7237
	.loc 1 30927 13 view .LVU7238
	.loc 1 30928 13 view .LVU7239
	.loc 1 30929 13 view .LVU7240
	.loc 1 30927 15 is_stmt 0 view .LVU7241
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1930:
	.loc 1 30928 30 view .LVU7242
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU7243
	movb	%dl, 1(%rdi,%rax)
.LBE5189:
	.loc 1 30916 9 is_stmt 1 view .LVU7244
	.loc 1 30916 34 is_stmt 0 view .LVU7245
	leaq	2(%rax), %rdx
.LVL1931:
	.loc 1 30916 23 is_stmt 1 view .LVU7246
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5190:
	.loc 1 30917 13 view .LVU7247
.LVL1932:
	.loc 1 30920 13 view .LVU7248
.LBB5161:
	.loc 1 2540 27 view .LVU7249
.LBE5161:
.LBE5190:
.LBE5229:
.LBE5254:
.LBE5279:
.LBE5304:
.LBE5329:
.LBE5354:
.LBE6339:
	.loc 1 2542 5 view .LVU7250
	.loc 1 2546 5 view .LVU7251
.LBB6340:
.LBB5355:
.LBB5330:
.LBB5305:
.LBB5280:
.LBB5255:
.LBB5230:
.LBB5191:
	.loc 1 30922 17 view .LVU7252
	.loc 1 30927 13 view .LVU7253
	.loc 1 30928 13 view .LVU7254
	.loc 1 30929 13 view .LVU7255
	.loc 1 30927 15 is_stmt 0 view .LVU7256
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1933:
	.loc 1 30928 30 view .LVU7257
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU7258
	movb	%dl, 2(%rdi,%rax)
.LBE5191:
	.loc 1 30916 9 is_stmt 1 view .LVU7259
	.loc 1 30916 34 is_stmt 0 view .LVU7260
	leaq	3(%rax), %rdx
.LVL1934:
	.loc 1 30916 23 is_stmt 1 view .LVU7261
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5192:
	.loc 1 30917 13 view .LVU7262
.LVL1935:
	.loc 1 30920 13 view .LVU7263
.LBB5162:
	.loc 1 2540 27 view .LVU7264
.LBE5162:
.LBE5192:
.LBE5230:
.LBE5255:
.LBE5280:
.LBE5305:
.LBE5330:
.LBE5355:
.LBE6340:
	.loc 1 2542 5 view .LVU7265
	.loc 1 2546 5 view .LVU7266
.LBB6341:
.LBB5356:
.LBB5331:
.LBB5306:
.LBB5281:
.LBB5256:
.LBB5231:
.LBB5193:
	.loc 1 30922 17 view .LVU7267
	.loc 1 30927 13 view .LVU7268
	.loc 1 30928 13 view .LVU7269
	.loc 1 30929 13 view .LVU7270
	.loc 1 30927 15 is_stmt 0 view .LVU7271
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1936:
	.loc 1 30928 30 view .LVU7272
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU7273
	movb	%dl, 3(%rdi,%rax)
.LBE5193:
	.loc 1 30916 9 is_stmt 1 view .LVU7274
	.loc 1 30916 34 is_stmt 0 view .LVU7275
	leaq	4(%rax), %rdx
.LVL1937:
	.loc 1 30916 23 is_stmt 1 view .LVU7276
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5194:
	.loc 1 30917 13 view .LVU7277
.LVL1938:
	.loc 1 30920 13 view .LVU7278
.LBB5163:
	.loc 1 2540 27 view .LVU7279
.LBE5163:
.LBE5194:
.LBE5231:
.LBE5256:
.LBE5281:
.LBE5306:
.LBE5331:
.LBE5356:
.LBE6341:
	.loc 1 2542 5 view .LVU7280
	.loc 1 2546 5 view .LVU7281
.LBB6342:
.LBB5357:
.LBB5332:
.LBB5307:
.LBB5282:
.LBB5257:
.LBB5232:
.LBB5195:
	.loc 1 30922 17 view .LVU7282
	.loc 1 30927 13 view .LVU7283
	.loc 1 30928 13 view .LVU7284
	.loc 1 30929 13 view .LVU7285
	.loc 1 30927 15 is_stmt 0 view .LVU7286
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1939:
	.loc 1 30928 30 view .LVU7287
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU7288
	movb	%dl, 4(%rdi,%rax)
.LBE5195:
	.loc 1 30916 9 is_stmt 1 view .LVU7289
	.loc 1 30916 34 is_stmt 0 view .LVU7290
	leaq	5(%rax), %rdx
.LVL1940:
	.loc 1 30916 23 is_stmt 1 view .LVU7291
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5196:
	.loc 1 30917 13 view .LVU7292
.LVL1941:
	.loc 1 30920 13 view .LVU7293
.LBB5164:
	.loc 1 2540 27 view .LVU7294
.LBE5164:
.LBE5196:
.LBE5232:
.LBE5257:
.LBE5282:
.LBE5307:
.LBE5332:
.LBE5357:
.LBE6342:
	.loc 1 2542 5 view .LVU7295
	.loc 1 2546 5 view .LVU7296
.LBB6343:
.LBB5358:
.LBB5333:
.LBB5308:
.LBB5283:
.LBB5258:
.LBB5233:
.LBB5197:
	.loc 1 30922 17 view .LVU7297
	.loc 1 30927 13 view .LVU7298
	.loc 1 30928 13 view .LVU7299
	.loc 1 30929 13 view .LVU7300
	.loc 1 30927 15 is_stmt 0 view .LVU7301
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1942:
	.loc 1 30928 30 view .LVU7302
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU7303
	movb	%dl, 5(%rdi,%rax)
.LBE5197:
	.loc 1 30916 9 is_stmt 1 view .LVU7304
	.loc 1 30916 34 is_stmt 0 view .LVU7305
	leaq	6(%rax), %rdx
.LVL1943:
	.loc 1 30916 23 is_stmt 1 view .LVU7306
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5198:
	.loc 1 30917 13 view .LVU7307
.LVL1944:
	.loc 1 30920 13 view .LVU7308
.LBB5165:
	.loc 1 2540 27 view .LVU7309
.LBE5165:
.LBE5198:
.LBE5233:
.LBE5258:
.LBE5283:
.LBE5308:
.LBE5333:
.LBE5358:
.LBE6343:
	.loc 1 2542 5 view .LVU7310
	.loc 1 2546 5 view .LVU7311
.LBB6344:
.LBB5359:
.LBB5334:
.LBB5309:
.LBB5284:
.LBB5259:
.LBB5234:
.LBB5199:
	.loc 1 30922 17 view .LVU7312
	.loc 1 30927 13 view .LVU7313
	.loc 1 30928 13 view .LVU7314
	.loc 1 30929 13 view .LVU7315
	.loc 1 30927 15 is_stmt 0 view .LVU7316
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1945:
	.loc 1 30928 30 view .LVU7317
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU7318
	movb	%dl, 6(%rdi,%rax)
.LBE5199:
	.loc 1 30916 9 is_stmt 1 view .LVU7319
	.loc 1 30916 34 is_stmt 0 view .LVU7320
	leaq	7(%rax), %rdx
.LVL1946:
	.loc 1 30916 23 is_stmt 1 view .LVU7321
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5200:
	.loc 1 30917 13 view .LVU7322
.LVL1947:
	.loc 1 30920 13 view .LVU7323
.LBB5166:
	.loc 1 2540 27 view .LVU7324
.LBE5166:
.LBE5200:
.LBE5234:
.LBE5259:
.LBE5284:
.LBE5309:
.LBE5334:
.LBE5359:
.LBE6344:
	.loc 1 2542 5 view .LVU7325
	.loc 1 2546 5 view .LVU7326
.LBB6345:
.LBB5360:
.LBB5335:
.LBB5310:
.LBB5285:
.LBB5260:
.LBB5235:
.LBB5201:
	.loc 1 30922 17 view .LVU7327
	.loc 1 30927 13 view .LVU7328
	.loc 1 30928 13 view .LVU7329
	.loc 1 30929 13 view .LVU7330
	.loc 1 30927 15 is_stmt 0 view .LVU7331
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1948:
	.loc 1 30928 30 view .LVU7332
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU7333
	movb	%dl, 7(%rdi,%rax)
.LBE5201:
	.loc 1 30916 9 is_stmt 1 view .LVU7334
	.loc 1 30916 34 is_stmt 0 view .LVU7335
	leaq	8(%rax), %rdx
.LVL1949:
	.loc 1 30916 23 is_stmt 1 view .LVU7336
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5202:
	.loc 1 30917 13 view .LVU7337
.LVL1950:
	.loc 1 30920 13 view .LVU7338
.LBB5167:
	.loc 1 2540 27 view .LVU7339
.LBE5167:
.LBE5202:
.LBE5235:
.LBE5260:
.LBE5285:
.LBE5310:
.LBE5335:
.LBE5360:
.LBE6345:
	.loc 1 2542 5 view .LVU7340
	.loc 1 2546 5 view .LVU7341
.LBB6346:
.LBB5361:
.LBB5336:
.LBB5311:
.LBB5286:
.LBB5261:
.LBB5236:
.LBB5203:
	.loc 1 30922 17 view .LVU7342
	.loc 1 30927 13 view .LVU7343
	.loc 1 30928 13 view .LVU7344
	.loc 1 30929 13 view .LVU7345
	.loc 1 30927 15 is_stmt 0 view .LVU7346
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1951:
	.loc 1 30928 30 view .LVU7347
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU7348
	movb	%dl, 8(%rdi,%rax)
.LBE5203:
	.loc 1 30916 9 is_stmt 1 view .LVU7349
	.loc 1 30916 34 is_stmt 0 view .LVU7350
	leaq	9(%rax), %rdx
.LVL1952:
	.loc 1 30916 23 is_stmt 1 view .LVU7351
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5204:
	.loc 1 30917 13 view .LVU7352
.LVL1953:
	.loc 1 30920 13 view .LVU7353
.LBB5168:
	.loc 1 2540 27 view .LVU7354
.LBE5168:
.LBE5204:
.LBE5236:
.LBE5261:
.LBE5286:
.LBE5311:
.LBE5336:
.LBE5361:
.LBE6346:
	.loc 1 2542 5 view .LVU7355
	.loc 1 2546 5 view .LVU7356
.LBB6347:
.LBB5362:
.LBB5337:
.LBB5312:
.LBB5287:
.LBB5262:
.LBB5237:
.LBB5205:
	.loc 1 30922 17 view .LVU7357
	.loc 1 30927 13 view .LVU7358
	.loc 1 30928 13 view .LVU7359
	.loc 1 30929 13 view .LVU7360
	.loc 1 30927 15 is_stmt 0 view .LVU7361
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1954:
	.loc 1 30928 30 view .LVU7362
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU7363
	movb	%dl, 9(%rdi,%rax)
.LBE5205:
	.loc 1 30916 9 is_stmt 1 view .LVU7364
	.loc 1 30916 34 is_stmt 0 view .LVU7365
	leaq	10(%rax), %rdx
.LVL1955:
	.loc 1 30916 23 is_stmt 1 view .LVU7366
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5206:
	.loc 1 30917 13 view .LVU7367
.LVL1956:
	.loc 1 30920 13 view .LVU7368
.LBB5169:
	.loc 1 2540 27 view .LVU7369
.LBE5169:
.LBE5206:
.LBE5237:
.LBE5262:
.LBE5287:
.LBE5312:
.LBE5337:
.LBE5362:
.LBE6347:
	.loc 1 2542 5 view .LVU7370
	.loc 1 2546 5 view .LVU7371
.LBB6348:
.LBB5363:
.LBB5338:
.LBB5313:
.LBB5288:
.LBB5263:
.LBB5238:
.LBB5207:
	.loc 1 30922 17 view .LVU7372
	.loc 1 30927 13 view .LVU7373
	.loc 1 30928 13 view .LVU7374
	.loc 1 30929 13 view .LVU7375
	.loc 1 30927 15 is_stmt 0 view .LVU7376
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1957:
	.loc 1 30928 30 view .LVU7377
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU7378
	movb	%dl, 10(%rdi,%rax)
.LBE5207:
	.loc 1 30916 9 is_stmt 1 view .LVU7379
	.loc 1 30916 34 is_stmt 0 view .LVU7380
	leaq	11(%rax), %rdx
.LVL1958:
	.loc 1 30916 23 is_stmt 1 view .LVU7381
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5208:
	.loc 1 30917 13 view .LVU7382
.LVL1959:
	.loc 1 30920 13 view .LVU7383
.LBB5170:
	.loc 1 2540 27 view .LVU7384
.LBE5170:
.LBE5208:
.LBE5238:
.LBE5263:
.LBE5288:
.LBE5313:
.LBE5338:
.LBE5363:
.LBE6348:
	.loc 1 2542 5 view .LVU7385
	.loc 1 2546 5 view .LVU7386
.LBB6349:
.LBB5364:
.LBB5339:
.LBB5314:
.LBB5289:
.LBB5264:
.LBB5239:
.LBB5209:
	.loc 1 30922 17 view .LVU7387
	.loc 1 30927 13 view .LVU7388
	.loc 1 30928 13 view .LVU7389
	.loc 1 30929 13 view .LVU7390
	.loc 1 30927 15 is_stmt 0 view .LVU7391
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1960:
	.loc 1 30928 30 view .LVU7392
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU7393
	movb	%dl, 11(%rdi,%rax)
.LBE5209:
	.loc 1 30916 9 is_stmt 1 view .LVU7394
	.loc 1 30916 34 is_stmt 0 view .LVU7395
	leaq	12(%rax), %rdx
.LVL1961:
	.loc 1 30916 23 is_stmt 1 view .LVU7396
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5210:
	.loc 1 30917 13 view .LVU7397
.LVL1962:
	.loc 1 30920 13 view .LVU7398
.LBB5171:
	.loc 1 2540 27 view .LVU7399
.LBE5171:
.LBE5210:
.LBE5239:
.LBE5264:
.LBE5289:
.LBE5314:
.LBE5339:
.LBE5364:
.LBE6349:
	.loc 1 2542 5 view .LVU7400
	.loc 1 2546 5 view .LVU7401
.LBB6350:
.LBB5365:
.LBB5340:
.LBB5315:
.LBB5290:
.LBB5265:
.LBB5240:
.LBB5211:
	.loc 1 30922 17 view .LVU7402
	.loc 1 30927 13 view .LVU7403
	.loc 1 30928 13 view .LVU7404
	.loc 1 30929 13 view .LVU7405
	.loc 1 30927 15 is_stmt 0 view .LVU7406
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1963:
	.loc 1 30928 30 view .LVU7407
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU7408
	movb	%dl, 12(%rdi,%rax)
.LBE5211:
	.loc 1 30916 9 is_stmt 1 view .LVU7409
	.loc 1 30916 34 is_stmt 0 view .LVU7410
	leaq	13(%rax), %rdx
.LVL1964:
	.loc 1 30916 23 is_stmt 1 view .LVU7411
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5212:
	.loc 1 30917 13 view .LVU7412
.LVL1965:
	.loc 1 30920 13 view .LVU7413
.LBB5172:
	.loc 1 2540 27 view .LVU7414
.LBE5172:
.LBE5212:
.LBE5240:
.LBE5265:
.LBE5290:
.LBE5315:
.LBE5340:
.LBE5365:
.LBE6350:
	.loc 1 2542 5 view .LVU7415
	.loc 1 2546 5 view .LVU7416
.LBB6351:
.LBB5366:
.LBB5341:
.LBB5316:
.LBB5291:
.LBB5266:
.LBB5241:
.LBB5213:
	.loc 1 30922 17 view .LVU7417
	.loc 1 30927 13 view .LVU7418
	.loc 1 30928 13 view .LVU7419
	.loc 1 30929 13 view .LVU7420
	.loc 1 30927 15 is_stmt 0 view .LVU7421
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1966:
	.loc 1 30928 30 view .LVU7422
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU7423
	movb	%dl, 13(%rdi,%rax)
.LBE5213:
	.loc 1 30916 9 is_stmt 1 view .LVU7424
	.loc 1 30916 34 is_stmt 0 view .LVU7425
	leaq	14(%rax), %rdx
.LVL1967:
	.loc 1 30916 23 is_stmt 1 view .LVU7426
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB5214:
	.loc 1 30917 13 view .LVU7427
.LVL1968:
	.loc 1 30920 13 view .LVU7428
.LBB5173:
	.loc 1 2540 27 view .LVU7429
.LBE5173:
.LBE5214:
.LBE5241:
.LBE5266:
.LBE5291:
.LBE5316:
.LBE5341:
.LBE5366:
.LBE6351:
	.loc 1 2542 5 view .LVU7430
	.loc 1 2546 5 view .LVU7431
.LBB6352:
.LBB5367:
.LBB5342:
.LBB5317:
.LBB5292:
.LBB5267:
.LBB5242:
.LBB5215:
	.loc 1 30922 17 view .LVU7432
	.loc 1 30927 13 view .LVU7433
	.loc 1 30928 13 view .LVU7434
	.loc 1 30929 13 view .LVU7435
	.loc 1 30927 15 is_stmt 0 view .LVU7436
	movsbw	1(%rbx,%rdx,2), %dx
.LVL1969:
	.loc 1 30928 30 view .LVU7437
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU7438
	movb	%dl, 14(%rdi,%rax)
.LBE5215:
	.loc 1 30916 9 is_stmt 1 view .LVU7439
.LVL1970:
	.loc 1 30916 23 view .LVU7440
	jmp	.L1050
.LVL1971:
	.p2align 4,,10
	.p2align 3
.L1163:
	.loc 1 30916 23 is_stmt 0 view .LVU7441
.LBE5242:
.LBE5267:
.LBE5292:
.LBE5317:
.LBE5342:
.LBE5367:
.LBE6352:
.LBB6353:
.LBB5962:
.LBB5963:
.LBB5964:
.LBB5965:
.LBB5966:
.LBB5967:
	.loc 1 31631 23 is_stmt 1 view .LVU7442
	testq	%r8, %r8
	je	.L1050
	movl	_ZL7g_maLCG(%rip), %eax
	cmpl	$1, %r9d
	je	.L1298
	cmpl	$2, %r9d
	je	.L1299
	leaq	(%rdx,%r8,4), %rax
	cmpq	%rax, %rdi
	leaq	(%rdi,%r8), %rax
	setnb	%dl
.LVL1972:
	.loc 1 31631 23 is_stmt 0 view .LVU7443
	cmpq	%rax, %rbx
	setnb	%al
	orb	%al, %dl
	je	.L1300
	leaq	-1(%r8), %rax
	cmpq	$14, %rax
	jbe	.L1300
	movq	%r8, %rcx
	movdqa	.LC83(%rip), %xmm2
	movq	%rbx, %rax
	movq	%rdi, %rdx
	shrq	$4, %rcx
	movdqa	.LC76(%rip), %xmm3
	salq	$6, %rcx
	addq	%rbx, %rcx
.LVL1973:
	.p2align 4,,10
	.p2align 3
.L1172:
.LBB5968:
	.loc 1 31632 13 is_stmt 1 view .LVU7444
	.loc 1 31635 13 view .LVU7445
.LBB5969:
.LBI5969:
	.loc 1 2540 27 view .LVU7446
.LBE5969:
.LBE5968:
.LBE5967:
.LBE5966:
.LBE5965:
.LBE5964:
.LBE5963:
.LBE5962:
.LBE6353:
	.loc 1 2542 5 view .LVU7447
	.loc 1 2546 5 view .LVU7448
.LBB6354:
.LBB6252:
.LBB6227:
.LBB6202:
.LBB6177:
.LBB6152:
.LBB6127:
.LBB6085:
	.loc 1 31637 17 view .LVU7449
	.loc 1 31642 13 view .LVU7450
	.loc 1 31643 13 view .LVU7451
	.loc 1 31644 13 view .LVU7452
	.loc 1 31642 15 is_stmt 0 view .LVU7453
	movdqu	(%rax), %xmm0
	movdqu	16(%rax), %xmm1
	addq	$64, %rax
	addq	$16, %rdx
	psrad	$24, %xmm1
	psrad	$24, %xmm0
	.loc 1 31643 15 view .LVU7454
	movdqa	%xmm0, %xmm4
	punpcklwd	%xmm1, %xmm0
	punpckhwd	%xmm1, %xmm4
	movdqa	%xmm0, %xmm1
	punpckhwd	%xmm4, %xmm1
	punpcklwd	%xmm4, %xmm0
	.loc 1 31642 15 view .LVU7455
	movdqu	-16(%rax), %xmm4
	.loc 1 31643 15 view .LVU7456
	punpcklwd	%xmm1, %xmm0
	.loc 1 31642 15 view .LVU7457
	movdqu	-32(%rax), %xmm1
	psrad	$24, %xmm4
	.loc 1 31643 15 view .LVU7458
	pand	%xmm3, %xmm0
	.loc 1 31642 15 view .LVU7459
	psrad	$24, %xmm1
	.loc 1 31643 15 view .LVU7460
	movdqa	%xmm1, %xmm5
	punpcklwd	%xmm4, %xmm1
	punpckhwd	%xmm4, %xmm5
	movdqa	%xmm1, %xmm4
	punpckhwd	%xmm5, %xmm4
	punpcklwd	%xmm5, %xmm1
	punpcklwd	%xmm4, %xmm1
	pand	%xmm3, %xmm1
	packuswb	%xmm1, %xmm0
	paddb	%xmm2, %xmm0
	.loc 1 31644 23 view .LVU7461
	movups	%xmm0, -16(%rdx)
.LBE6085:
	.loc 1 31631 9 is_stmt 1 view .LVU7462
	.loc 1 31631 23 view .LVU7463
	cmpq	%rcx, %rax
	jne	.L1172
	movq	%r8, %rax
	andq	$-16, %rax
	testb	$15, %r8b
	je	.L1050
.LVL1974:
.LBB6086:
	.loc 1 31632 13 view .LVU7464
	.loc 1 31635 13 view .LVU7465
.LBB6058:
	.loc 1 2540 27 view .LVU7466
.LBE6058:
.LBE6086:
.LBE6127:
.LBE6152:
.LBE6177:
.LBE6202:
.LBE6227:
.LBE6252:
.LBE6354:
	.loc 1 2542 5 view .LVU7467
	.loc 1 2546 5 view .LVU7468
.LBB6355:
.LBB6253:
.LBB6228:
.LBB6203:
.LBB6178:
.LBB6153:
.LBB6128:
.LBB6087:
	.loc 1 31637 17 view .LVU7469
	.loc 1 31642 13 view .LVU7470
	.loc 1 31643 13 view .LVU7471
	.loc 1 31644 13 view .LVU7472
	.loc 1 31642 15 is_stmt 0 view .LVU7473
	movsbl	3(%rbx,%rax,4), %edx
	.loc 1 31643 15 view .LVU7474
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU7475
	movb	%dl, (%rdi,%rax)
.LBE6087:
	.loc 1 31631 9 is_stmt 1 view .LVU7476
	.loc 1 31631 34 is_stmt 0 view .LVU7477
	leaq	1(%rax), %rdx
.LVL1975:
	.loc 1 31631 23 is_stmt 1 view .LVU7478
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB6088:
	.loc 1 31632 13 view .LVU7479
.LVL1976:
	.loc 1 31635 13 view .LVU7480
.LBB6059:
	.loc 1 2540 27 view .LVU7481
.LBE6059:
.LBE6088:
.LBE6128:
.LBE6153:
.LBE6178:
.LBE6203:
.LBE6228:
.LBE6253:
.LBE6355:
	.loc 1 2542 5 view .LVU7482
	.loc 1 2546 5 view .LVU7483
.LBB6356:
.LBB6254:
.LBB6229:
.LBB6204:
.LBB6179:
.LBB6154:
.LBB6129:
.LBB6089:
	.loc 1 31637 17 view .LVU7484
	.loc 1 31642 13 view .LVU7485
	.loc 1 31643 13 view .LVU7486
	.loc 1 31644 13 view .LVU7487
	.loc 1 31642 15 is_stmt 0 view .LVU7488
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1977:
	.loc 1 31643 15 view .LVU7489
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU7490
	movb	%dl, 1(%rdi,%rax)
.LBE6089:
	.loc 1 31631 9 is_stmt 1 view .LVU7491
	.loc 1 31631 34 is_stmt 0 view .LVU7492
	leaq	2(%rax), %rdx
.LVL1978:
	.loc 1 31631 23 is_stmt 1 view .LVU7493
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB6090:
	.loc 1 31632 13 view .LVU7494
.LVL1979:
	.loc 1 31635 13 view .LVU7495
.LBB6060:
	.loc 1 2540 27 view .LVU7496
.LBE6060:
.LBE6090:
.LBE6129:
.LBE6154:
.LBE6179:
.LBE6204:
.LBE6229:
.LBE6254:
.LBE6356:
	.loc 1 2542 5 view .LVU7497
	.loc 1 2546 5 view .LVU7498
.LBB6357:
.LBB6255:
.LBB6230:
.LBB6205:
.LBB6180:
.LBB6155:
.LBB6130:
.LBB6091:
	.loc 1 31637 17 view .LVU7499
	.loc 1 31642 13 view .LVU7500
	.loc 1 31643 13 view .LVU7501
	.loc 1 31644 13 view .LVU7502
	.loc 1 31642 15 is_stmt 0 view .LVU7503
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1980:
	.loc 1 31643 15 view .LVU7504
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU7505
	movb	%dl, 2(%rdi,%rax)
.LBE6091:
	.loc 1 31631 9 is_stmt 1 view .LVU7506
	.loc 1 31631 34 is_stmt 0 view .LVU7507
	leaq	3(%rax), %rdx
.LVL1981:
	.loc 1 31631 23 is_stmt 1 view .LVU7508
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB6092:
	.loc 1 31632 13 view .LVU7509
.LVL1982:
	.loc 1 31635 13 view .LVU7510
.LBB6061:
	.loc 1 2540 27 view .LVU7511
.LBE6061:
.LBE6092:
.LBE6130:
.LBE6155:
.LBE6180:
.LBE6205:
.LBE6230:
.LBE6255:
.LBE6357:
	.loc 1 2542 5 view .LVU7512
	.loc 1 2546 5 view .LVU7513
.LBB6358:
.LBB6256:
.LBB6231:
.LBB6206:
.LBB6181:
.LBB6156:
.LBB6131:
.LBB6093:
	.loc 1 31637 17 view .LVU7514
	.loc 1 31642 13 view .LVU7515
	.loc 1 31643 13 view .LVU7516
	.loc 1 31644 13 view .LVU7517
	.loc 1 31642 15 is_stmt 0 view .LVU7518
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1983:
	.loc 1 31643 15 view .LVU7519
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU7520
	movb	%dl, 3(%rdi,%rax)
.LBE6093:
	.loc 1 31631 9 is_stmt 1 view .LVU7521
	.loc 1 31631 34 is_stmt 0 view .LVU7522
	leaq	4(%rax), %rdx
.LVL1984:
	.loc 1 31631 23 is_stmt 1 view .LVU7523
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB6094:
	.loc 1 31632 13 view .LVU7524
.LVL1985:
	.loc 1 31635 13 view .LVU7525
.LBB6062:
	.loc 1 2540 27 view .LVU7526
.LBE6062:
.LBE6094:
.LBE6131:
.LBE6156:
.LBE6181:
.LBE6206:
.LBE6231:
.LBE6256:
.LBE6358:
	.loc 1 2542 5 view .LVU7527
	.loc 1 2546 5 view .LVU7528
.LBB6359:
.LBB6257:
.LBB6232:
.LBB6207:
.LBB6182:
.LBB6157:
.LBB6132:
.LBB6095:
	.loc 1 31637 17 view .LVU7529
	.loc 1 31642 13 view .LVU7530
	.loc 1 31643 13 view .LVU7531
	.loc 1 31644 13 view .LVU7532
	.loc 1 31642 15 is_stmt 0 view .LVU7533
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1986:
	.loc 1 31643 15 view .LVU7534
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU7535
	movb	%dl, 4(%rdi,%rax)
.LBE6095:
	.loc 1 31631 9 is_stmt 1 view .LVU7536
	.loc 1 31631 34 is_stmt 0 view .LVU7537
	leaq	5(%rax), %rdx
.LVL1987:
	.loc 1 31631 23 is_stmt 1 view .LVU7538
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB6096:
	.loc 1 31632 13 view .LVU7539
.LVL1988:
	.loc 1 31635 13 view .LVU7540
.LBB6063:
	.loc 1 2540 27 view .LVU7541
.LBE6063:
.LBE6096:
.LBE6132:
.LBE6157:
.LBE6182:
.LBE6207:
.LBE6232:
.LBE6257:
.LBE6359:
	.loc 1 2542 5 view .LVU7542
	.loc 1 2546 5 view .LVU7543
.LBB6360:
.LBB6258:
.LBB6233:
.LBB6208:
.LBB6183:
.LBB6158:
.LBB6133:
.LBB6097:
	.loc 1 31637 17 view .LVU7544
	.loc 1 31642 13 view .LVU7545
	.loc 1 31643 13 view .LVU7546
	.loc 1 31644 13 view .LVU7547
	.loc 1 31642 15 is_stmt 0 view .LVU7548
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1989:
	.loc 1 31643 15 view .LVU7549
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU7550
	movb	%dl, 5(%rdi,%rax)
.LBE6097:
	.loc 1 31631 9 is_stmt 1 view .LVU7551
	.loc 1 31631 34 is_stmt 0 view .LVU7552
	leaq	6(%rax), %rdx
.LVL1990:
	.loc 1 31631 23 is_stmt 1 view .LVU7553
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB6098:
	.loc 1 31632 13 view .LVU7554
.LVL1991:
	.loc 1 31635 13 view .LVU7555
.LBB6064:
	.loc 1 2540 27 view .LVU7556
.LBE6064:
.LBE6098:
.LBE6133:
.LBE6158:
.LBE6183:
.LBE6208:
.LBE6233:
.LBE6258:
.LBE6360:
	.loc 1 2542 5 view .LVU7557
	.loc 1 2546 5 view .LVU7558
.LBB6361:
.LBB6259:
.LBB6234:
.LBB6209:
.LBB6184:
.LBB6159:
.LBB6134:
.LBB6099:
	.loc 1 31637 17 view .LVU7559
	.loc 1 31642 13 view .LVU7560
	.loc 1 31643 13 view .LVU7561
	.loc 1 31644 13 view .LVU7562
	.loc 1 31642 15 is_stmt 0 view .LVU7563
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1992:
	.loc 1 31643 15 view .LVU7564
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU7565
	movb	%dl, 6(%rdi,%rax)
.LBE6099:
	.loc 1 31631 9 is_stmt 1 view .LVU7566
	.loc 1 31631 34 is_stmt 0 view .LVU7567
	leaq	7(%rax), %rdx
.LVL1993:
	.loc 1 31631 23 is_stmt 1 view .LVU7568
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB6100:
	.loc 1 31632 13 view .LVU7569
.LVL1994:
	.loc 1 31635 13 view .LVU7570
.LBB6065:
	.loc 1 2540 27 view .LVU7571
.LBE6065:
.LBE6100:
.LBE6134:
.LBE6159:
.LBE6184:
.LBE6209:
.LBE6234:
.LBE6259:
.LBE6361:
	.loc 1 2542 5 view .LVU7572
	.loc 1 2546 5 view .LVU7573
.LBB6362:
.LBB6260:
.LBB6235:
.LBB6210:
.LBB6185:
.LBB6160:
.LBB6135:
.LBB6101:
	.loc 1 31637 17 view .LVU7574
	.loc 1 31642 13 view .LVU7575
	.loc 1 31643 13 view .LVU7576
	.loc 1 31644 13 view .LVU7577
	.loc 1 31642 15 is_stmt 0 view .LVU7578
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1995:
	.loc 1 31643 15 view .LVU7579
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU7580
	movb	%dl, 7(%rdi,%rax)
.LBE6101:
	.loc 1 31631 9 is_stmt 1 view .LVU7581
	.loc 1 31631 34 is_stmt 0 view .LVU7582
	leaq	8(%rax), %rdx
.LVL1996:
	.loc 1 31631 23 is_stmt 1 view .LVU7583
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB6102:
	.loc 1 31632 13 view .LVU7584
.LVL1997:
	.loc 1 31635 13 view .LVU7585
.LBB6066:
	.loc 1 2540 27 view .LVU7586
.LBE6066:
.LBE6102:
.LBE6135:
.LBE6160:
.LBE6185:
.LBE6210:
.LBE6235:
.LBE6260:
.LBE6362:
	.loc 1 2542 5 view .LVU7587
	.loc 1 2546 5 view .LVU7588
.LBB6363:
.LBB6261:
.LBB6236:
.LBB6211:
.LBB6186:
.LBB6161:
.LBB6136:
.LBB6103:
	.loc 1 31637 17 view .LVU7589
	.loc 1 31642 13 view .LVU7590
	.loc 1 31643 13 view .LVU7591
	.loc 1 31644 13 view .LVU7592
	.loc 1 31642 15 is_stmt 0 view .LVU7593
	movsbl	3(%rbx,%rdx,4), %edx
.LVL1998:
	.loc 1 31643 15 view .LVU7594
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU7595
	movb	%dl, 8(%rdi,%rax)
.LBE6103:
	.loc 1 31631 9 is_stmt 1 view .LVU7596
	.loc 1 31631 34 is_stmt 0 view .LVU7597
	leaq	9(%rax), %rdx
.LVL1999:
	.loc 1 31631 23 is_stmt 1 view .LVU7598
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB6104:
	.loc 1 31632 13 view .LVU7599
.LVL2000:
	.loc 1 31635 13 view .LVU7600
.LBB6067:
	.loc 1 2540 27 view .LVU7601
.LBE6067:
.LBE6104:
.LBE6136:
.LBE6161:
.LBE6186:
.LBE6211:
.LBE6236:
.LBE6261:
.LBE6363:
	.loc 1 2542 5 view .LVU7602
	.loc 1 2546 5 view .LVU7603
.LBB6364:
.LBB6262:
.LBB6237:
.LBB6212:
.LBB6187:
.LBB6162:
.LBB6137:
.LBB6105:
	.loc 1 31637 17 view .LVU7604
	.loc 1 31642 13 view .LVU7605
	.loc 1 31643 13 view .LVU7606
	.loc 1 31644 13 view .LVU7607
	.loc 1 31642 15 is_stmt 0 view .LVU7608
	movsbl	3(%rbx,%rdx,4), %edx
.LVL2001:
	.loc 1 31643 15 view .LVU7609
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU7610
	movb	%dl, 9(%rdi,%rax)
.LBE6105:
	.loc 1 31631 9 is_stmt 1 view .LVU7611
	.loc 1 31631 34 is_stmt 0 view .LVU7612
	leaq	10(%rax), %rdx
.LVL2002:
	.loc 1 31631 23 is_stmt 1 view .LVU7613
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB6106:
	.loc 1 31632 13 view .LVU7614
.LVL2003:
	.loc 1 31635 13 view .LVU7615
.LBB6068:
	.loc 1 2540 27 view .LVU7616
.LBE6068:
.LBE6106:
.LBE6137:
.LBE6162:
.LBE6187:
.LBE6212:
.LBE6237:
.LBE6262:
.LBE6364:
	.loc 1 2542 5 view .LVU7617
	.loc 1 2546 5 view .LVU7618
.LBB6365:
.LBB6263:
.LBB6238:
.LBB6213:
.LBB6188:
.LBB6163:
.LBB6138:
.LBB6107:
	.loc 1 31637 17 view .LVU7619
	.loc 1 31642 13 view .LVU7620
	.loc 1 31643 13 view .LVU7621
	.loc 1 31644 13 view .LVU7622
	.loc 1 31642 15 is_stmt 0 view .LVU7623
	movsbl	3(%rbx,%rdx,4), %edx
.LVL2004:
	.loc 1 31643 15 view .LVU7624
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU7625
	movb	%dl, 10(%rdi,%rax)
.LBE6107:
	.loc 1 31631 9 is_stmt 1 view .LVU7626
	.loc 1 31631 34 is_stmt 0 view .LVU7627
	leaq	11(%rax), %rdx
.LVL2005:
	.loc 1 31631 23 is_stmt 1 view .LVU7628
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB6108:
	.loc 1 31632 13 view .LVU7629
.LVL2006:
	.loc 1 31635 13 view .LVU7630
.LBB6069:
	.loc 1 2540 27 view .LVU7631
.LBE6069:
.LBE6108:
.LBE6138:
.LBE6163:
.LBE6188:
.LBE6213:
.LBE6238:
.LBE6263:
.LBE6365:
	.loc 1 2542 5 view .LVU7632
	.loc 1 2546 5 view .LVU7633
.LBB6366:
.LBB6264:
.LBB6239:
.LBB6214:
.LBB6189:
.LBB6164:
.LBB6139:
.LBB6109:
	.loc 1 31637 17 view .LVU7634
	.loc 1 31642 13 view .LVU7635
	.loc 1 31643 13 view .LVU7636
	.loc 1 31644 13 view .LVU7637
	.loc 1 31642 15 is_stmt 0 view .LVU7638
	movsbl	3(%rbx,%rdx,4), %edx
.LVL2007:
	.loc 1 31643 15 view .LVU7639
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU7640
	movb	%dl, 11(%rdi,%rax)
.LBE6109:
	.loc 1 31631 9 is_stmt 1 view .LVU7641
	.loc 1 31631 34 is_stmt 0 view .LVU7642
	leaq	12(%rax), %rdx
.LVL2008:
	.loc 1 31631 23 is_stmt 1 view .LVU7643
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB6110:
	.loc 1 31632 13 view .LVU7644
.LVL2009:
	.loc 1 31635 13 view .LVU7645
.LBB6070:
	.loc 1 2540 27 view .LVU7646
.LBE6070:
.LBE6110:
.LBE6139:
.LBE6164:
.LBE6189:
.LBE6214:
.LBE6239:
.LBE6264:
.LBE6366:
	.loc 1 2542 5 view .LVU7647
	.loc 1 2546 5 view .LVU7648
.LBB6367:
.LBB6265:
.LBB6240:
.LBB6215:
.LBB6190:
.LBB6165:
.LBB6140:
.LBB6111:
	.loc 1 31637 17 view .LVU7649
	.loc 1 31642 13 view .LVU7650
	.loc 1 31643 13 view .LVU7651
	.loc 1 31644 13 view .LVU7652
	.loc 1 31642 15 is_stmt 0 view .LVU7653
	movsbl	3(%rbx,%rdx,4), %edx
.LVL2010:
	.loc 1 31643 15 view .LVU7654
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU7655
	movb	%dl, 12(%rdi,%rax)
.LBE6111:
	.loc 1 31631 9 is_stmt 1 view .LVU7656
	.loc 1 31631 34 is_stmt 0 view .LVU7657
	leaq	13(%rax), %rdx
.LVL2011:
	.loc 1 31631 23 is_stmt 1 view .LVU7658
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB6112:
	.loc 1 31632 13 view .LVU7659
.LVL2012:
	.loc 1 31635 13 view .LVU7660
.LBB6071:
	.loc 1 2540 27 view .LVU7661
.LBE6071:
.LBE6112:
.LBE6140:
.LBE6165:
.LBE6190:
.LBE6215:
.LBE6240:
.LBE6265:
.LBE6367:
	.loc 1 2542 5 view .LVU7662
	.loc 1 2546 5 view .LVU7663
.LBB6368:
.LBB6266:
.LBB6241:
.LBB6216:
.LBB6191:
.LBB6166:
.LBB6141:
.LBB6113:
	.loc 1 31637 17 view .LVU7664
	.loc 1 31642 13 view .LVU7665
	.loc 1 31643 13 view .LVU7666
	.loc 1 31644 13 view .LVU7667
	.loc 1 31642 15 is_stmt 0 view .LVU7668
	movsbl	3(%rbx,%rdx,4), %edx
.LVL2013:
	.loc 1 31643 15 view .LVU7669
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU7670
	movb	%dl, 13(%rdi,%rax)
.LBE6113:
	.loc 1 31631 9 is_stmt 1 view .LVU7671
	.loc 1 31631 34 is_stmt 0 view .LVU7672
	leaq	14(%rax), %rdx
.LVL2014:
	.loc 1 31631 23 is_stmt 1 view .LVU7673
	cmpq	%rdx, %r8
	jbe	.L1050
.LBB6114:
	.loc 1 31632 13 view .LVU7674
.LVL2015:
	.loc 1 31635 13 view .LVU7675
.LBB6072:
	.loc 1 2540 27 view .LVU7676
.LBE6072:
.LBE6114:
.LBE6141:
.LBE6166:
.LBE6191:
.LBE6216:
.LBE6241:
.LBE6266:
.LBE6368:
	.loc 1 2542 5 view .LVU7677
	.loc 1 2546 5 view .LVU7678
.LBB6369:
.LBB6267:
.LBB6242:
.LBB6217:
.LBB6192:
.LBB6167:
.LBB6142:
.LBB6115:
	.loc 1 31637 17 view .LVU7679
	.loc 1 31642 13 view .LVU7680
	.loc 1 31643 13 view .LVU7681
	.loc 1 31644 13 view .LVU7682
	.loc 1 31642 15 is_stmt 0 view .LVU7683
	movsbl	3(%rbx,%rdx,4), %edx
.LVL2016:
	.loc 1 31643 15 view .LVU7684
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU7685
	movb	%dl, 14(%rdi,%rax)
.LBE6115:
	.loc 1 31631 9 is_stmt 1 view .LVU7686
.LVL2017:
	.loc 1 31631 23 view .LVU7687
	jmp	.L1050
.LVL2018:
	.p2align 4,,10
	.p2align 3
.L1120:
	.loc 1 31631 23 is_stmt 0 view .LVU7688
.LBE6142:
.LBE6167:
.LBE6192:
.LBE6217:
.LBE6242:
.LBE6267:
.LBE6369:
.LBB6370:
.LBB5772:
.LBB5773:
.LBB5774:
.LBB5775:
.LBB5776:
.LBB5777:
	.loc 1 31261 23 is_stmt 1 view .LVU7689
	testq	%r8, %r8
	je	.L1050
	movl	_ZL7g_maLCG(%rip), %ecx
	cmpl	$1, %r9d
	je	.L1130
	cmpl	$2, %r9d
	je	.L1131
	leaq	(%r8,%r8,2), %rcx
	addq	%rdx, %rcx
.LVL2019:
	.p2align 4,,10
	.p2align 3
.L1132:
.LBB5778:
	.loc 1 31262 13 view .LVU7690
	.loc 1 31265 13 view .LVU7691
.LBB5779:
.LBI5779:
	.loc 1 2540 27 view .LVU7692
.LBE5779:
.LBE5778:
.LBE5777:
.LBE5776:
.LBE5775:
.LBE5774:
.LBE5773:
.LBE5772:
.LBE6370:
	.loc 1 2542 5 view .LVU7693
	.loc 1 2546 5 view .LVU7694
.LBB6371:
.LBB5920:
.LBB5912:
.LBB5904:
.LBB5896:
.LBB5888:
.LBB5880:
.LBB5865:
	.loc 1 31267 17 view .LVU7695
	.loc 1 31272 13 view .LVU7696
	.loc 1 31273 13 view .LVU7697
	.loc 1 31274 13 view .LVU7698
	.loc 1 31262 75 is_stmt 0 view .LVU7699
	movzbl	1(%rbx), %eax
	.loc 1 31262 38 view .LVU7700
	movzbl	(%rbx), %edx
.LBE5865:
	.loc 1 31261 23 view .LVU7701
	addq	$3, %rbx
	addq	$1, %rdi
.LVL2020:
.LBB5866:
	.loc 1 31262 66 view .LVU7702
	sall	$8, %edx
	.loc 1 31262 103 view .LVU7703
	sall	$16, %eax
	.loc 1 31262 110 view .LVU7704
	orl	%edx, %eax
	.loc 1 31262 113 view .LVU7705
	movzbl	-1(%rbx), %edx
	.loc 1 31262 142 view .LVU7706
	sall	$24, %edx
	.loc 1 31262 110 view .LVU7707
	orl	%edx, %eax
	.loc 1 31272 15 view .LVU7708
	sarl	$24, %eax
	.loc 1 31273 15 view .LVU7709
	subl	$-128, %eax
	.loc 1 31274 23 view .LVU7710
	movb	%al, -1(%rdi)
.LBE5866:
	.loc 1 31261 9 is_stmt 1 view .LVU7711
.LVL2021:
	.loc 1 31261 23 view .LVU7712
	cmpq	%rbx, %rcx
	jne	.L1132
	jmp	.L1050
.LVL2022:
.L1466:
	.loc 1 31261 23 is_stmt 0 view .LVU7713
	movss	.LC77(%rip), %xmm0
	movss	-104(%rbp), %xmm4
	movss	.LC88(%rip), %xmm3
	movsd	.LC104(%rip), %xmm2
	movss	.LC109(%rip), %xmm9
	.p2align 4,,10
	.p2align 3
.L1275:
	.loc 1 31261 23 view .LVU7714
.LBE5880:
.LBE5888:
.LBE5896:
.LBE5904:
.LBE5912:
.LBE5920:
.LBE6371:
.LBB6372:
.LBB4414:
.LBB4357:
.LBB4298:
.LBB4269:
	.loc 1 32144 9 is_stmt 1 view .LVU7715
.LVL2023:
	.loc 1 32145 9 view .LVU7716
.LBB4235:
	.loc 1 2528 24 view .LVU7717
.LBE4235:
.LBE4269:
.LBE4298:
.LBE4357:
.LBE4414:
.LBE6372:
	.loc 1 2530 5 view .LVU7718
	.loc 1 2531 9 view .LVU7719
.LBB6373:
.LBB4415:
.LBB4358:
.LBB4299:
.LBB4270:
.LBB4236:
.LBB4064:
.LBI4064:
	.loc 1 2516 24 view .LVU7720
.LBE4064:
.LBE4236:
.LBE4270:
.LBE4299:
.LBE4358:
.LBE4415:
.LBE6373:
	.loc 1 2518 5 view .LVU7721
.LBB6374:
.LBB4416:
.LBB4359:
.LBB4300:
.LBB4271:
.LBB4237:
.LBB4088:
.LBB4065:
.LBI4065:
	.loc 1 2505 24 view .LVU7722
.LBE4065:
.LBE4088:
.LBE4237:
.LBE4271:
.LBE4300:
.LBE4359:
.LBE4416:
.LBE6374:
	.loc 1 2507 5 view .LVU7723
.LBB6375:
.LBB4417:
.LBB4360:
.LBB4301:
.LBB4272:
.LBB4238:
.LBB4089:
.LBB4085:
.LBB4066:
.LBI4066:
	.loc 1 2464 24 view .LVU7724
.LBE4066:
.LBE4085:
.LBE4089:
.LBE4238:
.LBE4272:
.LBE4301:
.LBE4360:
.LBE4417:
.LBE6375:
	.loc 1 2466 5 view .LVU7725
.LBB6376:
.LBB4418:
.LBB4361:
.LBB4302:
.LBB4273:
.LBB4239:
.LBB4090:
.LBB4086:
.LBB4083:
.LBB4067:
.LBI4067:
	.loc 1 2459 24 view .LVU7726
.LBB4068:
	.loc 1 2461 5 view .LVU7727
.LBB4069:
.LBI4069:
	.loc 1 2454 25 view .LVU7728
.LBB4070:
	.loc 1 2456 5 view .LVU7729
.LBB4071:
.LBI4071:
	.loc 1 2438 27 view .LVU7730
.LBB4072:
	.loc 1 2440 5 view .LVU7731
	.loc 1 2440 29 is_stmt 0 view .LVU7732
	imull	$48271, %eax, %ecx
.LBE4072:
.LBE4071:
	.loc 1 2456 34 view .LVU7733
	pxor	%xmm1, %xmm1
.LBB4074:
.LBB4073:
	.loc 1 2440 55 view .LVU7734
	movslq	%ecx, %rdx
	movq	%rdx, %rax
	salq	$30, %rax
	addq	%rdx, %rax
	movl	%ecx, %edx
	sarl	$31, %edx
	sarq	$61, %rax
	subl	%edx, %eax
	movl	%eax, %edx
	sall	$31, %edx
	subl	%eax, %edx
	movl	%ecx, %eax
	subl	%edx, %eax
	.loc 1 2441 5 is_stmt 1 view .LVU7735
.LVL2024:
	.loc 1 2441 5 is_stmt 0 view .LVU7736
.LBE4073:
.LBE4074:
.LBE4070:
.LBE4069:
.LBE4068:
.LBE4067:
.LBB4078:
.LBI4078:
	.loc 1 2367 24 is_stmt 1 view .LVU7737
.LBB4079:
	.loc 1 2369 5 view .LVU7738
	.loc 1 2369 5 is_stmt 0 view .LVU7739
.LBE4079:
.LBE4078:
.LBE4083:
.LBE4086:
.LBE4090:
.LBE4239:
	.loc 1 32146 9 is_stmt 1 view .LVU7740
.LBB4240:
.LBB4091:
.LBB4087:
.LBB4084:
.LBB4081:
.LBB4077:
.LBB4076:
.LBB4075:
	.loc 1 2456 34 is_stmt 0 view .LVU7741
	cvtsi2sdl	%eax, %xmm1
	.loc 1 2456 44 view .LVU7742
	mulsd	%xmm2, %xmm1
.LBE4075:
.LBE4076:
	.loc 1 2461 39 view .LVU7743
	cvtsd2ss	%xmm1, %xmm1
.LBE4077:
.LBE4081:
.LBB4082:
.LBB4080:
	.loc 1 2369 18 view .LVU7744
	mulss	%xmm4, %xmm1
	.loc 1 2369 25 view .LVU7745
	addss	%xmm8, %xmm1
.LBE4080:
.LBE4082:
.LBE4084:
.LBE4087:
.LBE4091:
.LBE4240:
	.loc 1 32145 11 view .LVU7746
	addss	(%rbx,%r12,4), %xmm1
	.loc 1 32146 23 view .LVU7747
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL2025:
	.loc 1 32147 9 is_stmt 1 view .LVU7748
	.loc 1 32149 9 view .LVU7749
	.loc 1 32147 11 is_stmt 0 view .LVU7750
	mulss	%xmm9, %xmm1
.LVL2026:
	.loc 1 32149 22 view .LVU7751
	cvttss2sil	%xmm1, %edx
	movw	%dx, (%rdi,%r12,2)
.LBE4273:
	.loc 1 32143 5 is_stmt 1 view .LVU7752
	.loc 1 32143 25 is_stmt 0 view .LVU7753
	addq	$1, %r12
.LVL2027:
	.loc 1 32143 25 view .LVU7754
.LBE4302:
	.loc 1 32143 5 is_stmt 1 view .LVU7755
.LBB4303:
	.loc 1 32143 14 view .LVU7756
	cmpq	%r12, %r8
	jne	.L1275
.L1280:
	.loc 1 32143 14 is_stmt 0 view .LVU7757
	movl	%eax, _ZL7g_maLCG(%rip)
	jmp	.L1050
.LVL2028:
.L1468:
	.loc 1 32143 14 view .LVU7758
	cmpl	$2, %r9d
	jne	.L1286
	movss	.LC77(%rip), %xmm0
	movss	.LC88(%rip), %xmm3
.LBE4303:
.LBE4361:
.LBE4418:
.LBE6376:
.LBB6377:
.LBB5742:
.LBB5711:
.LBB5681:
.LBB5651:
	.loc 1 31996 12 view .LVU7759
	xorl	%ecx, %ecx
	movss	.LC103(%rip), %xmm5
	movsd	.LC104(%rip), %xmm2
	movss	.LC106(%rip), %xmm7
	movss	.LC107(%rip), %xmm6
	movss	.LC105(%rip), %xmm8
.LVL2029:
	.p2align 4,,10
	.p2align 3
.L1211:
.LBB5621:
	.loc 1 31997 9 is_stmt 1 view .LVU7760
	.loc 1 31998 9 view .LVU7761
.LBB5572:
	.loc 1 2528 24 view .LVU7762
.LBE5572:
.LBE5621:
.LBE5651:
.LBE5681:
.LBE5711:
.LBE5742:
.LBE6377:
	.loc 1 2530 5 view .LVU7763
	.loc 1 2533 5 view .LVU7764
	.loc 1 2534 9 view .LVU7765
.LBB6378:
.LBB5743:
.LBB5712:
.LBB5682:
.LBB5652:
.LBB5622:
.LBB5573:
.LBB5415:
.LBI5415:
	.loc 1 2521 24 view .LVU7766
.LBB5416:
	.loc 1 2523 5 view .LVU7767
.LBB5417:
.LBI5417:
	.loc 1 2505 24 view .LVU7768
.LBE5417:
.LBE5416:
.LBE5415:
.LBE5573:
.LBE5622:
.LBE5652:
.LBE5682:
.LBE5712:
.LBE5743:
.LBE6378:
	.loc 1 2507 5 view .LVU7769
.LBB6379:
.LBB5744:
.LBB5713:
.LBB5683:
.LBB5653:
.LBB5623:
.LBB5574:
.LBB5541:
.LBB5531:
.LBB5458:
.LBB5418:
.LBI5418:
	.loc 1 2464 24 view .LVU7770
.LBE5418:
.LBE5458:
.LBE5531:
.LBE5541:
.LBE5574:
.LBE5623:
.LBE5653:
.LBE5683:
.LBE5713:
.LBE5744:
.LBE6379:
	.loc 1 2466 5 view .LVU7771
.LBB6380:
.LBB5745:
.LBB5714:
.LBB5684:
.LBB5654:
.LBB5624:
.LBB5575:
.LBB5542:
.LBB5532:
.LBB5459:
.LBB5451:
.LBB5419:
.LBI5419:
	.loc 1 2459 24 view .LVU7772
.LBB5420:
	.loc 1 2461 5 view .LVU7773
.LBB5421:
.LBI5421:
	.loc 1 2454 25 view .LVU7774
.LBB5422:
	.loc 1 2456 5 view .LVU7775
.LBB5423:
.LBI5423:
	.loc 1 2438 27 view .LVU7776
.LBB5424:
	.loc 1 2440 5 view .LVU7777
	.loc 1 2440 29 is_stmt 0 view .LVU7778
	imull	$48271, %eax, %eax
.LBE5424:
.LBE5423:
.LBE5422:
.LBE5421:
.LBE5420:
.LBE5419:
.LBE5451:
.LBE5459:
.LBE5532:
.LBE5542:
.LBE5575:
	.loc 1 31998 11 view .LVU7779
	movss	(%rbx,%rcx,4), %xmm1
.LBB5576:
.LBB5543:
.LBB5533:
.LBB5460:
.LBB5452:
.LBB5445:
.LBB5439:
.LBB5434:
.LBB5429:
	.loc 1 2456 34 view .LVU7780
	pxor	%xmm9, %xmm9
.LBE5429:
.LBE5434:
.LBE5439:
.LBE5445:
.LBE5452:
.LBE5460:
.LBE5533:
.LBE5543:
.LBE5576:
	.loc 1 31998 11 view .LVU7781
	movaps	%xmm1, %xmm4
.LBB5577:
.LBB5544:
.LBB5534:
.LBB5461:
.LBB5462:
.LBB5463:
.LBB5464:
.LBB5465:
.LBB5466:
	.loc 1 2456 34 view .LVU7782
	pxor	%xmm1, %xmm1
.LBE5466:
.LBE5465:
.LBE5464:
.LBE5463:
.LBE5462:
.LBE5461:
.LBB5517:
.LBB5453:
.LBB5446:
.LBB5440:
.LBB5435:
.LBB5430:
.LBB5427:
.LBB5425:
	.loc 1 2440 55 view .LVU7783
	movslq	%eax, %rsi
	movq	%rsi, %rdx
	salq	$30, %rdx
	addq	%rsi, %rdx
	movl	%eax, %esi
	sarl	$31, %esi
	sarq	$61, %rdx
	subl	%esi, %edx
	movl	%edx, %esi
	sall	$31, %esi
	subl	%edx, %esi
	subl	%esi, %eax
.LBE5425:
.LBE5427:
.LBE5430:
.LBE5435:
.LBE5440:
.LBE5446:
.LBE5453:
.LBE5517:
.LBB5518:
.LBB5509:
.LBB5498:
.LBB5491:
.LBB5484:
.LBB5477:
.LBB5467:
.LBB5468:
	.loc 1 2440 29 view .LVU7784
	imull	$48271, %eax, %r9d
.LBE5468:
.LBE5467:
.LBE5477:
.LBE5484:
.LBE5491:
.LBE5498:
.LBE5509:
.LBE5518:
.LBB5519:
.LBB5454:
.LBB5447:
.LBB5441:
.LBB5436:
.LBB5431:
.LBB5428:
.LBB5426:
	.loc 1 2440 55 view .LVU7785
	movl	%eax, %edx
	.loc 1 2441 5 is_stmt 1 view .LVU7786
.LVL2030:
	.loc 1 2441 5 is_stmt 0 view .LVU7787
.LBE5426:
.LBE5428:
.LBE5431:
.LBE5436:
.LBE5441:
.LBE5447:
.LBE5454:
.LBE5519:
.LBE5534:
.LBE5544:
.LBE5577:
.LBE5624:
.LBE5654:
.LBE5684:
.LBE5714:
.LBE5745:
.LBE6380:
	.loc 1 2369 5 is_stmt 1 view .LVU7788
.LBB6381:
.LBB5746:
.LBB5715:
.LBB5685:
.LBB5655:
.LBB5625:
.LBB5578:
.LBB5545:
.LBB5535:
	.loc 1 2524 5 view .LVU7789
.LBB5520:
.LBI5461:
	.loc 1 2505 24 view .LVU7790
.LBE5520:
.LBE5535:
.LBE5545:
.LBE5578:
.LBE5625:
.LBE5655:
.LBE5685:
.LBE5715:
.LBE5746:
.LBE6381:
	.loc 1 2507 5 view .LVU7791
.LBB6382:
.LBB5747:
.LBB5716:
.LBB5686:
.LBB5656:
.LBB5626:
.LBB5579:
.LBB5546:
.LBB5536:
.LBB5521:
.LBB5510:
.LBI5462:
	.loc 1 2464 24 view .LVU7792
.LBE5510:
.LBE5521:
.LBE5536:
.LBE5546:
.LBE5579:
.LBE5626:
.LBE5656:
.LBE5686:
.LBE5716:
.LBE5747:
.LBE6382:
	.loc 1 2466 5 view .LVU7793
.LBB6383:
.LBB5748:
.LBB5717:
.LBB5687:
.LBB5657:
.LBB5627:
.LBB5580:
.LBB5547:
.LBB5537:
.LBB5522:
.LBB5511:
.LBB5499:
.LBI5463:
	.loc 1 2459 24 view .LVU7794
.LBB5492:
	.loc 1 2461 5 view .LVU7795
.LBB5485:
.LBI5465:
	.loc 1 2454 25 view .LVU7796
.LBB5478:
	.loc 1 2456 5 view .LVU7797
.LBB5473:
.LBI5467:
	.loc 1 2438 27 view .LVU7798
.LBB5469:
	.loc 1 2440 5 view .LVU7799
.LBE5469:
.LBE5473:
.LBE5478:
.LBE5485:
.LBE5492:
.LBE5499:
.LBE5511:
.LBE5522:
.LBB5523:
.LBB5455:
.LBB5448:
.LBB5442:
.LBB5437:
.LBB5432:
	.loc 1 2456 34 is_stmt 0 view .LVU7800
	cvtsi2sdl	%edx, %xmm9
.LBE5432:
.LBE5437:
.LBE5442:
.LBE5448:
.LBE5455:
.LBE5523:
.LBB5524:
.LBB5512:
.LBB5500:
.LBB5493:
.LBB5486:
.LBB5479:
.LBB5474:
.LBB5470:
	.loc 1 2440 55 view .LVU7801
	movslq	%r9d, %rsi
	movq	%rsi, %rax
.LVL2031:
	.loc 1 2440 55 view .LVU7802
.LBE5470:
.LBE5474:
.LBE5479:
.LBE5486:
.LBE5493:
.LBE5500:
.LBE5512:
.LBE5524:
.LBB5525:
.LBB5456:
.LBB5449:
.LBB5443:
.LBB5438:
.LBB5433:
	.loc 1 2456 44 view .LVU7803
	mulsd	%xmm2, %xmm9
.LBE5433:
.LBE5438:
.LBE5443:
.LBE5449:
.LBE5456:
.LBE5525:
.LBB5526:
.LBB5513:
.LBB5501:
.LBB5494:
.LBB5487:
.LBB5480:
.LBB5475:
.LBB5471:
	.loc 1 2440 55 view .LVU7804
	salq	$30, %rax
	addq	%rsi, %rax
	movl	%r9d, %esi
	sarl	$31, %esi
	sarq	$61, %rax
	subl	%esi, %eax
	movl	%eax, %esi
	sall	$31, %esi
.LBE5471:
.LBE5475:
.LBE5480:
.LBE5487:
.LBE5494:
.LBE5501:
.LBE5513:
.LBE5526:
.LBB5527:
.LBB5457:
.LBB5450:
.LBB5444:
	.loc 1 2461 39 view .LVU7805
	cvtsd2ss	%xmm9, %xmm9
.LBE5444:
.LBE5450:
.LBE5457:
.LBE5527:
.LBE5537:
.LBE5547:
.LBE5580:
	.loc 1 31998 11 view .LVU7806
	mulss	%xmm8, %xmm9
.LBB5581:
.LBB5548:
.LBB5538:
.LBB5528:
.LBB5514:
.LBB5502:
.LBB5495:
.LBB5488:
.LBB5481:
.LBB5476:
.LBB5472:
	.loc 1 2440 55 view .LVU7807
	subl	%eax, %esi
	movl	%r9d, %eax
	subl	%esi, %eax
	.loc 1 2441 5 is_stmt 1 view .LVU7808
.LVL2032:
	.loc 1 2441 5 is_stmt 0 view .LVU7809
.LBE5472:
.LBE5476:
.LBE5481:
.LBE5488:
.LBE5495:
.LBE5502:
.LBB5503:
.LBI5503:
	.loc 1 2367 24 is_stmt 1 view .LVU7810
.LBB5504:
	.loc 1 2369 5 view .LVU7811
	.loc 1 2369 5 is_stmt 0 view .LVU7812
.LBE5504:
.LBE5503:
.LBE5514:
.LBE5528:
	.loc 1 2525 5 is_stmt 1 view .LVU7813
	.loc 1 2525 5 is_stmt 0 view .LVU7814
.LBE5538:
.LBE5548:
.LBE5581:
	.loc 1 31999 9 is_stmt 1 view .LVU7815
.LBB5582:
.LBB5549:
.LBB5539:
.LBB5529:
.LBB5515:
.LBB5506:
.LBB5496:
.LBB5489:
.LBB5482:
	.loc 1 2456 34 is_stmt 0 view .LVU7816
	cvtsi2sdl	%eax, %xmm1
.LBE5482:
.LBE5489:
.LBE5496:
.LBE5506:
.LBE5515:
.LBE5529:
.LBE5539:
.LBE5549:
.LBE5582:
	.loc 1 31998 11 view .LVU7817
	subss	%xmm9, %xmm4
.LBB5583:
.LBB5550:
.LBB5540:
.LBB5530:
.LBB5516:
.LBB5507:
.LBB5497:
.LBB5490:
.LBB5483:
	.loc 1 2456 44 view .LVU7818
	mulsd	%xmm2, %xmm1
.LBE5483:
.LBE5490:
	.loc 1 2461 39 view .LVU7819
	cvtsd2ss	%xmm1, %xmm1
.LBE5497:
.LBE5507:
.LBB5508:
.LBB5505:
	.loc 1 2369 18 view .LVU7820
	mulss	%xmm7, %xmm1
.LBE5505:
.LBE5508:
.LBE5516:
.LBE5530:
.LBE5540:
.LBE5550:
.LBE5583:
	.loc 1 31998 11 view .LVU7821
	subss	%xmm6, %xmm1
	addss	%xmm4, %xmm1
	.loc 1 31999 23 view .LVU7822
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL2033:
	.loc 1 32000 9 is_stmt 1 view .LVU7823
	.loc 1 32000 11 is_stmt 0 view .LVU7824
	addss	%xmm0, %xmm1
.LVL2034:
	.loc 1 32001 9 is_stmt 1 view .LVU7825
	.loc 1 32003 9 view .LVU7826
	.loc 1 32001 11 is_stmt 0 view .LVU7827
	mulss	%xmm5, %xmm1
.LVL2035:
	.loc 1 32003 21 view .LVU7828
	cvttss2sil	%xmm1, %edx
.LVL2036:
	.loc 1 32003 21 view .LVU7829
	movb	%dl, (%rdi,%rcx)
.LBE5627:
	.loc 1 31996 5 is_stmt 1 view .LVU7830
	.loc 1 31996 30 is_stmt 0 view .LVU7831
	addq	$1, %rcx
.LVL2037:
	.loc 1 31996 19 is_stmt 1 view .LVU7832
	cmpq	%rcx, %r8
	jne	.L1211
	jmp	.L1216
.LVL2038:
.L1467:
	.loc 1 31996 19 is_stmt 0 view .LVU7833
	movss	.LC77(%rip), %xmm0
	movss	.LC88(%rip), %xmm3
	movsd	.LC104(%rip), %xmm2
	movss	.LC109(%rip), %xmm9
	.p2align 4,,10
	.p2align 3
.L1276:
	.loc 1 31996 19 view .LVU7834
.LBE5657:
.LBE5687:
.LBE5717:
.LBE5748:
.LBE6383:
.LBB6384:
.LBB4419:
.LBB4362:
.LBB4304:
.LBB4274:
	.loc 1 32144 9 is_stmt 1 view .LVU7835
.LVL2039:
	.loc 1 32145 9 view .LVU7836
.LBB4241:
	.loc 1 2528 24 view .LVU7837
.LBE4241:
.LBE4274:
.LBE4304:
.LBE4362:
.LBE4419:
.LBE6384:
	.loc 1 2530 5 view .LVU7838
	.loc 1 2533 5 view .LVU7839
	.loc 1 2534 9 view .LVU7840
.LBB6385:
.LBB4420:
.LBB4363:
.LBB4305:
.LBB4275:
.LBB4242:
.LBB4092:
.LBI4092:
	.loc 1 2521 24 view .LVU7841
.LBB4093:
	.loc 1 2523 5 view .LVU7842
.LBB4094:
.LBI4094:
	.loc 1 2505 24 view .LVU7843
.LBE4094:
.LBE4093:
.LBE4092:
.LBE4242:
.LBE4275:
.LBE4305:
.LBE4363:
.LBE4420:
.LBE6385:
	.loc 1 2507 5 view .LVU7844
.LBB6386:
.LBB4421:
.LBB4364:
.LBB4306:
.LBB4276:
.LBB4243:
.LBB4218:
.LBB4208:
.LBB4135:
.LBB4095:
.LBI4095:
	.loc 1 2464 24 view .LVU7845
.LBE4095:
.LBE4135:
.LBE4208:
.LBE4218:
.LBE4243:
.LBE4276:
.LBE4306:
.LBE4364:
.LBE4421:
.LBE6386:
	.loc 1 2466 5 view .LVU7846
.LBB6387:
.LBB4422:
.LBB4365:
.LBB4307:
.LBB4277:
.LBB4244:
.LBB4219:
.LBB4209:
.LBB4136:
.LBB4128:
.LBB4096:
.LBI4096:
	.loc 1 2459 24 view .LVU7847
.LBB4097:
	.loc 1 2461 5 view .LVU7848
.LBB4098:
.LBI4098:
	.loc 1 2454 25 view .LVU7849
.LBB4099:
	.loc 1 2456 5 view .LVU7850
.LBB4100:
.LBI4100:
	.loc 1 2438 27 view .LVU7851
.LBB4101:
	.loc 1 2440 5 view .LVU7852
	.loc 1 2440 29 is_stmt 0 view .LVU7853
	imull	$48271, %eax, %eax
.LBE4101:
.LBE4100:
.LBE4099:
.LBE4098:
.LBE4097:
.LBE4096:
.LBE4128:
.LBE4136:
.LBE4209:
.LBE4219:
.LBE4244:
	.loc 1 32145 11 view .LVU7854
	movss	(%rbx,%r12,4), %xmm1
.LBB4245:
.LBB4220:
.LBB4210:
.LBB4137:
.LBB4129:
.LBB4122:
.LBB4116:
.LBB4111:
.LBB4106:
	.loc 1 2456 34 view .LVU7855
	pxor	%xmm5, %xmm5
.LBE4106:
.LBE4111:
.LBE4116:
.LBE4122:
.LBE4129:
.LBE4137:
.LBE4210:
.LBE4220:
.LBE4245:
	.loc 1 32145 11 view .LVU7856
	movaps	%xmm1, %xmm4
.LBB4246:
.LBB4221:
.LBB4211:
.LBB4138:
.LBB4139:
.LBB4140:
.LBB4141:
.LBB4142:
.LBB4143:
	.loc 1 2456 34 view .LVU7857
	pxor	%xmm1, %xmm1
.LBE4143:
.LBE4142:
.LBE4141:
.LBE4140:
.LBE4139:
.LBE4138:
.LBB4194:
.LBB4130:
.LBB4123:
.LBB4117:
.LBB4112:
.LBB4107:
.LBB4104:
.LBB4102:
	.loc 1 2440 55 view .LVU7858
	movslq	%eax, %rcx
	movq	%rcx, %rdx
	salq	$30, %rdx
	addq	%rcx, %rdx
	movl	%eax, %ecx
	sarl	$31, %ecx
	sarq	$61, %rdx
	subl	%ecx, %edx
	movl	%edx, %ecx
	sall	$31, %ecx
	subl	%edx, %ecx
	subl	%ecx, %eax
.LBE4102:
.LBE4104:
.LBE4107:
.LBE4112:
.LBE4117:
.LBE4123:
.LBE4130:
.LBE4194:
.LBB4195:
.LBB4186:
.LBB4175:
.LBB4168:
.LBB4161:
.LBB4154:
.LBB4144:
.LBB4145:
	.loc 1 2440 29 view .LVU7859
	imull	$48271, %eax, %esi
.LBE4145:
.LBE4144:
.LBE4154:
.LBE4161:
.LBE4168:
.LBE4175:
.LBE4186:
.LBE4195:
.LBB4196:
.LBB4131:
.LBB4124:
.LBB4118:
.LBB4113:
.LBB4108:
.LBB4105:
.LBB4103:
	.loc 1 2440 55 view .LVU7860
	movl	%eax, %edx
	.loc 1 2441 5 is_stmt 1 view .LVU7861
.LVL2040:
	.loc 1 2441 5 is_stmt 0 view .LVU7862
.LBE4103:
.LBE4105:
.LBE4108:
.LBE4113:
.LBE4118:
.LBE4124:
.LBE4131:
.LBE4196:
.LBE4211:
.LBE4221:
.LBE4246:
.LBE4277:
.LBE4307:
.LBE4365:
.LBE4422:
.LBE6387:
	.loc 1 2369 5 is_stmt 1 view .LVU7863
.LBB6388:
.LBB4423:
.LBB4366:
.LBB4308:
.LBB4278:
.LBB4247:
.LBB4222:
.LBB4212:
	.loc 1 2524 5 view .LVU7864
.LBB4197:
.LBI4138:
	.loc 1 2505 24 view .LVU7865
.LBE4197:
.LBE4212:
.LBE4222:
.LBE4247:
.LBE4278:
.LBE4308:
.LBE4366:
.LBE4423:
.LBE6388:
	.loc 1 2507 5 view .LVU7866
.LBB6389:
.LBB4424:
.LBB4367:
.LBB4309:
.LBB4279:
.LBB4248:
.LBB4223:
.LBB4213:
.LBB4198:
.LBB4187:
.LBI4139:
	.loc 1 2464 24 view .LVU7867
.LBE4187:
.LBE4198:
.LBE4213:
.LBE4223:
.LBE4248:
.LBE4279:
.LBE4309:
.LBE4367:
.LBE4424:
.LBE6389:
	.loc 1 2466 5 view .LVU7868
.LBB6390:
.LBB4425:
.LBB4368:
.LBB4310:
.LBB4280:
.LBB4249:
.LBB4224:
.LBB4214:
.LBB4199:
.LBB4188:
.LBB4176:
.LBI4140:
	.loc 1 2459 24 view .LVU7869
.LBB4169:
	.loc 1 2461 5 view .LVU7870
.LBB4162:
.LBI4142:
	.loc 1 2454 25 view .LVU7871
.LBB4155:
	.loc 1 2456 5 view .LVU7872
.LBB4150:
.LBI4144:
	.loc 1 2438 27 view .LVU7873
.LBB4146:
	.loc 1 2440 5 view .LVU7874
.LBE4146:
.LBE4150:
.LBE4155:
.LBE4162:
.LBE4169:
.LBE4176:
.LBE4188:
.LBE4199:
.LBB4200:
.LBB4132:
.LBB4125:
.LBB4119:
.LBB4114:
.LBB4109:
	.loc 1 2456 34 is_stmt 0 view .LVU7875
	cvtsi2sdl	%edx, %xmm5
.LBE4109:
.LBE4114:
.LBE4119:
.LBE4125:
.LBE4132:
.LBE4200:
.LBB4201:
.LBB4189:
.LBB4177:
.LBB4170:
.LBB4163:
.LBB4156:
.LBB4151:
.LBB4147:
	.loc 1 2440 55 view .LVU7876
	movslq	%esi, %rcx
	movq	%rcx, %rax
.LBE4147:
.LBE4151:
.LBE4156:
.LBE4163:
.LBE4170:
.LBE4177:
.LBE4189:
.LBE4201:
.LBB4202:
.LBB4133:
.LBB4126:
.LBB4120:
.LBB4115:
.LBB4110:
	.loc 1 2456 44 view .LVU7877
	mulsd	%xmm2, %xmm5
.LBE4110:
.LBE4115:
.LBE4120:
.LBE4126:
.LBE4133:
.LBE4202:
.LBB4203:
.LBB4190:
.LBB4178:
.LBB4171:
.LBB4164:
.LBB4157:
.LBB4152:
.LBB4148:
	.loc 1 2440 55 view .LVU7878
	salq	$30, %rax
	addq	%rcx, %rax
	movl	%esi, %ecx
	sarl	$31, %ecx
	sarq	$61, %rax
	subl	%ecx, %eax
	movl	%eax, %ecx
	sall	$31, %ecx
.LBE4148:
.LBE4152:
.LBE4157:
.LBE4164:
.LBE4171:
.LBE4178:
.LBE4190:
.LBE4203:
.LBB4204:
.LBB4134:
.LBB4127:
.LBB4121:
	.loc 1 2461 39 view .LVU7879
	cvtsd2ss	%xmm5, %xmm5
.LBE4121:
.LBE4127:
.LBE4134:
.LBE4204:
.LBE4214:
.LBE4224:
.LBE4249:
	.loc 1 32145 11 view .LVU7880
	mulss	%xmm8, %xmm5
.LBB4250:
.LBB4225:
.LBB4215:
.LBB4205:
.LBB4191:
.LBB4179:
.LBB4172:
.LBB4165:
.LBB4158:
.LBB4153:
.LBB4149:
	.loc 1 2440 55 view .LVU7881
	subl	%eax, %ecx
	movl	%esi, %eax
	subl	%ecx, %eax
	.loc 1 2441 5 is_stmt 1 view .LVU7882
.LVL2041:
	.loc 1 2441 5 is_stmt 0 view .LVU7883
.LBE4149:
.LBE4153:
.LBE4158:
.LBE4165:
.LBE4172:
.LBE4179:
.LBB4180:
.LBI4180:
	.loc 1 2367 24 is_stmt 1 view .LVU7884
.LBB4181:
	.loc 1 2369 5 view .LVU7885
	.loc 1 2369 5 is_stmt 0 view .LVU7886
.LBE4181:
.LBE4180:
.LBE4191:
.LBE4205:
	.loc 1 2525 5 is_stmt 1 view .LVU7887
	.loc 1 2525 5 is_stmt 0 view .LVU7888
.LBE4215:
.LBE4225:
.LBE4250:
	.loc 1 32146 9 is_stmt 1 view .LVU7889
.LBB4251:
.LBB4226:
.LBB4216:
.LBB4206:
.LBB4192:
.LBB4183:
.LBB4173:
.LBB4166:
.LBB4159:
	.loc 1 2456 34 is_stmt 0 view .LVU7890
	cvtsi2sdl	%eax, %xmm1
.LBE4159:
.LBE4166:
.LBE4173:
.LBE4183:
.LBE4192:
.LBE4206:
.LBE4216:
.LBE4226:
.LBE4251:
	.loc 1 32145 11 view .LVU7891
	subss	%xmm5, %xmm4
.LBB4252:
.LBB4227:
.LBB4217:
.LBB4207:
.LBB4193:
.LBB4184:
.LBB4174:
.LBB4167:
.LBB4160:
	.loc 1 2456 44 view .LVU7892
	mulsd	%xmm2, %xmm1
.LBE4160:
.LBE4167:
	.loc 1 2461 39 view .LVU7893
	cvtsd2ss	%xmm1, %xmm1
.LBE4174:
.LBE4184:
.LBB4185:
.LBB4182:
	.loc 1 2369 18 view .LVU7894
	mulss	%xmm10, %xmm1
.LBE4182:
.LBE4185:
.LBE4193:
.LBE4207:
.LBE4217:
.LBE4227:
.LBE4252:
	.loc 1 32145 11 view .LVU7895
	addss	%xmm8, %xmm1
	addss	%xmm4, %xmm1
	.loc 1 32146 23 view .LVU7896
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL2042:
	.loc 1 32147 9 is_stmt 1 view .LVU7897
	.loc 1 32149 9 view .LVU7898
	.loc 1 32147 11 is_stmt 0 view .LVU7899
	mulss	%xmm9, %xmm1
.LVL2043:
	.loc 1 32149 22 view .LVU7900
	cvttss2sil	%xmm1, %edx
	movw	%dx, (%rdi,%r12,2)
.LBE4280:
	.loc 1 32143 5 is_stmt 1 view .LVU7901
	.loc 1 32143 25 is_stmt 0 view .LVU7902
	addq	$1, %r12
.LVL2044:
	.loc 1 32143 25 view .LVU7903
.LBE4310:
	.loc 1 32143 5 is_stmt 1 view .LVU7904
.LBB4311:
	.loc 1 32143 14 view .LVU7905
	cmpq	%r12, %r8
	jne	.L1276
	jmp	.L1280
.LVL2045:
.L1287:
	.loc 1 32143 14 is_stmt 0 view .LVU7906
.LBE4311:
.LBE4368:
.LBE4425:
.LBE6390:
.LBB6391:
.LBB5041:
.LBB5040:
.LBB5039:
.LBB5038:
	.loc 1 30564 12 view .LVU7907
	xorl	%edx, %edx
.LVL2046:
	.p2align 4,,10
	.p2align 3
.L1066:
.LBB5037:
	.loc 1 30565 9 is_stmt 1 view .LVU7908
	.loc 1 30566 9 view .LVU7909
	.loc 1 30567 9 view .LVU7910
	.loc 1 30566 26 is_stmt 0 view .LVU7911
	movzbl	(%rbx,%rdx), %eax
	addl	$-128, %eax
	.loc 1 30567 24 view .LVU7912
	cwtl
	.loc 1 30567 26 view .LVU7913
	sall	$8, %eax
.LVL2047:
	.loc 1 30568 9 is_stmt 1 view .LVU7914
	.loc 1 30567 11 is_stmt 0 view .LVU7915
	movw	%ax, (%rdi,%rdx,2)
.LBE5037:
	.loc 1 30564 5 is_stmt 1 view .LVU7916
	.loc 1 30564 30 is_stmt 0 view .LVU7917
	addq	$1, %rdx
.LVL2048:
	.loc 1 30564 19 is_stmt 1 view .LVU7918
	cmpq	%rdx, %r8
	jne	.L1066
	jmp	.L1050
.LVL2049:
.L1288:
	.loc 1 30564 19 is_stmt 0 view .LVU7919
.LBE5038:
.LBE5039:
.LBE5040:
.LBE5041:
.LBE6391:
.LBB6392:
.LBB6317:
.LBB6316:
.LBB6315:
.LBB6314:
	.loc 1 30696 12 view .LVU7920
	xorl	%edx, %edx
.LVL2050:
	.p2align 4,,10
	.p2align 3
.L1072:
.LBB6313:
	.loc 1 30697 9 is_stmt 1 view .LVU7921
	.loc 1 30697 18 is_stmt 0 view .LVU7922
	movzbl	(%rbx,%rdx), %eax
.LVL2051:
	.loc 1 30698 9 is_stmt 1 view .LVU7923
	.loc 1 30698 11 is_stmt 0 view .LVU7924
	addl	$-128, %eax
.LVL2052:
	.loc 1 30699 9 is_stmt 1 view .LVU7925
	.loc 1 30700 9 view .LVU7926
	.loc 1 30699 11 is_stmt 0 view .LVU7927
	sall	$24, %eax
.LVL2053:
	.loc 1 30699 11 view .LVU7928
	movl	%eax, (%rdi,%rdx,4)
.LBE6313:
	.loc 1 30696 5 is_stmt 1 view .LVU7929
	.loc 1 30696 30 is_stmt 0 view .LVU7930
	addq	$1, %rdx
.LVL2054:
	.loc 1 30696 19 is_stmt 1 view .LVU7931
	cmpq	%rdx, %r8
	jne	.L1072
	jmp	.L1050
.LVL2055:
.L1289:
	.loc 1 30696 19 is_stmt 0 view .LVU7932
	movss	.LC95(%rip), %xmm2
	movss	.LC77(%rip), %xmm0
.LBE6314:
.LBE6315:
.LBE6316:
.LBE6317:
.LBE6392:
.LBB6393:
.LBB4972:
.LBB4971:
.LBB4970:
.LBB4969:
	.loc 1 30761 12 view .LVU7933
	xorl	%eax, %eax
.LVL2056:
	.p2align 4,,10
	.p2align 3
.L1077:
.LBB4968:
	.loc 1 30762 9 is_stmt 1 view .LVU7934
	.loc 1 30762 15 is_stmt 0 view .LVU7935
	movzbl	(%rbx,%rax), %edx
	pxor	%xmm1, %xmm1
	cvtsi2ssl	%edx, %xmm1
.LVL2057:
	.loc 1 30763 9 is_stmt 1 view .LVU7936
	.loc 1 30763 11 is_stmt 0 view .LVU7937
	mulss	%xmm2, %xmm1
.LVL2058:
	.loc 1 30764 9 is_stmt 1 view .LVU7938
	.loc 1 30766 9 view .LVU7939
	.loc 1 30764 11 is_stmt 0 view .LVU7940
	subss	%xmm0, %xmm1
.LVL2059:
	.loc 1 30766 20 view .LVU7941
	movss	%xmm1, (%rdi,%rax,4)
.LBE4968:
	.loc 1 30761 5 is_stmt 1 view .LVU7942
	.loc 1 30761 30 is_stmt 0 view .LVU7943
	addq	$1, %rax
.LVL2060:
	.loc 1 30761 19 is_stmt 1 view .LVU7944
	cmpq	%rax, %r8
	jne	.L1077
	jmp	.L1050
.LVL2061:
.L1291:
	.loc 1 30761 19 is_stmt 0 view .LVU7945
.LBE4969:
.LBE4970:
.LBE4971:
.LBE4972:
.LBE6393:
.LBB6394:
.LBB5368:
.LBB5343:
.LBB5318:
.LBB5293:
.LBB5268:
.LBB5243:
	.loc 1 30916 16 view .LVU7946
	xorl	%esi, %esi
.LVL2062:
	.p2align 4,,10
	.p2align 3
.L1093:
.LBB5216:
	.loc 1 30917 13 is_stmt 1 view .LVU7947
.LBB5174:
.LBB5080:
.LBB5081:
.LBB5082:
.LBB5083:
.LBB5084:
.LBB5085:
.LBB5086:
.LBB5087:
	.loc 1 2440 29 is_stmt 0 view .LVU7948
	imull	$48271, %eax, %r9d
.LBE5087:
.LBE5086:
.LBE5085:
.LBE5084:
.LBE5083:
.LBE5082:
.LBE5081:
.LBE5080:
.LBE5174:
	.loc 1 30917 22 view .LVU7949
	movzwl	(%rbx,%rsi,2), %edx
.LVL2063:
	.loc 1 30920 13 is_stmt 1 view .LVU7950
.LBB5175:
	.loc 1 2540 27 view .LVU7951
.LBE5175:
.LBE5216:
.LBE5243:
.LBE5268:
.LBE5293:
.LBE5318:
.LBE5343:
.LBE5368:
.LBE6394:
	.loc 1 2542 5 view .LVU7952
.LBB6395:
.LBB5369:
.LBB5344:
.LBB5319:
.LBB5294:
.LBB5269:
.LBB5244:
.LBB5217:
.LBB5176:
.LBB5103:
	.loc 1 2543 9 view .LVU7953
.LBB5100:
.LBI5081:
	.loc 1 2510 27 view .LVU7954
.LBE5100:
.LBE5103:
.LBE5176:
.LBE5217:
.LBE5244:
.LBE5269:
.LBE5294:
.LBE5319:
.LBE5344:
.LBE5369:
.LBE6395:
	.loc 1 2512 5 view .LVU7955
.LBB6396:
.LBB5370:
.LBB5345:
.LBB5320:
.LBB5295:
.LBB5270:
.LBB5245:
.LBB5218:
.LBB5177:
.LBB5104:
.LBB5101:
.LBB5098:
.LBI5082:
	.loc 1 2469 27 view .LVU7956
.LBB5096:
	.loc 1 2471 5 view .LVU7957
	.loc 1 2475 5 view .LVU7958
.LBB5094:
.LBI5084:
	.loc 1 2444 28 view .LVU7959
.LBB5092:
	.loc 1 2446 5 view .LVU7960
.LBB5090:
.LBI5086:
	.loc 1 2438 27 view .LVU7961
.LBB5088:
	.loc 1 2440 5 view .LVU7962
	.loc 1 2440 55 is_stmt 0 view .LVU7963
	movslq	%r9d, %rcx
	movq	%rcx, %rax
	salq	$30, %rax
	addq	%rcx, %rax
	movl	%r9d, %ecx
	sarl	$31, %ecx
	sarq	$61, %rax
	subl	%ecx, %eax
	movl	%eax, %ecx
	sall	$31, %ecx
	subl	%eax, %ecx
	movl	%r9d, %eax
.LBE5088:
.LBE5090:
.LBE5092:
.LBE5094:
.LBE5096:
.LBE5098:
.LBE5101:
.LBE5104:
.LBE5177:
	.loc 1 30921 18 view .LVU7964
	movswl	%dx, %r9d
.LBB5178:
.LBB5105:
.LBB5102:
.LBB5099:
.LBB5097:
.LBB5095:
.LBB5093:
.LBB5091:
.LBB5089:
	.loc 1 2440 55 view .LVU7965
	subl	%ecx, %eax
	.loc 1 2441 5 is_stmt 1 view .LVU7966
.LVL2064:
	.loc 1 2441 5 is_stmt 0 view .LVU7967
.LBE5089:
.LBE5091:
.LBE5093:
.LBE5095:
	.loc 1 2475 39 view .LVU7968
	movl	%eax, %ecx
	shrl	$24, %ecx
	.loc 1 2475 15 view .LVU7969
	addl	$-128, %ecx
.LVL2065:
	.loc 1 2475 15 view .LVU7970
.LBE5097:
.LBE5099:
.LBE5102:
	.loc 1 2544 9 is_stmt 1 view .LVU7971
	.loc 1 2544 9 is_stmt 0 view .LVU7972
.LBE5105:
.LBE5178:
	.loc 1 30921 13 is_stmt 1 view .LVU7973
	.loc 1 30921 20 is_stmt 0 view .LVU7974
	addl	%ecx, %r9d
	.loc 1 30921 13 view .LVU7975
	cmpl	$32767, %r9d
	jle	.L1469
.LVL2066:
	.loc 1 30927 13 is_stmt 1 view .LVU7976
	.loc 1 30928 13 view .LVU7977
	.loc 1 30929 13 view .LVU7978
	.loc 1 30929 23 is_stmt 0 view .LVU7979
	movb	$-1, (%rdi,%rsi)
.LBE5218:
	.loc 1 30916 9 is_stmt 1 view .LVU7980
	.loc 1 30916 34 is_stmt 0 view .LVU7981
	addq	$1, %rsi
.LVL2067:
	.loc 1 30916 23 is_stmt 1 view .LVU7982
	cmpq	%rsi, %r8
	jne	.L1093
.LVL2068:
.L1099:
	.loc 1 30916 23 is_stmt 0 view .LVU7983
	movl	%eax, _ZL7g_maLCG(%rip)
.LVL2069:
	.loc 1 30916 23 view .LVU7984
	jmp	.L1050
.LVL2070:
.L1469:
.LBB5219:
	.loc 1 30922 17 is_stmt 1 view .LVU7985
	.loc 1 30922 34 is_stmt 0 view .LVU7986
	addl	%ecx, %edx
.LVL2071:
	.loc 1 30927 13 is_stmt 1 view .LVU7987
	.loc 1 30928 13 view .LVU7988
	.loc 1 30929 13 view .LVU7989
	.loc 1 30927 15 is_stmt 0 view .LVU7990
	sarw	$8, %dx
	.loc 1 30928 30 view .LVU7991
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU7992
	movb	%dl, (%rdi,%rsi)
.LBE5219:
	.loc 1 30916 9 is_stmt 1 view .LVU7993
	.loc 1 30916 34 is_stmt 0 view .LVU7994
	addq	$1, %rsi
.LVL2072:
	.loc 1 30916 23 is_stmt 1 view .LVU7995
	cmpq	%rsi, %r8
	jne	.L1093
	jmp	.L1099
.LVL2073:
.L1302:
	.loc 1 30916 23 is_stmt 0 view .LVU7996
.LBE5245:
.LBE5270:
.LBE5295:
.LBE5320:
.LBE5345:
.LBE5370:
.LBE6396:
.LBB6397:
.LBB4889:
.LBB4872:
.LBB4856:
.LBB4840:
.LBB4824:
.LBB4808:
	.loc 1 31712 16 view .LVU7997
	xorl	%ecx, %ecx
.LBB4791:
	.loc 1 31717 13 view .LVU7998
	movl	$2147483648, %r9d
.LVL2074:
	.p2align 4,,10
	.p2align 3
.L1187:
	.loc 1 31713 13 is_stmt 1 view .LVU7999
.LBB4765:
.LBB4683:
.LBB4684:
.LBB4685:
.LBB4686:
.LBB4687:
.LBB4688:
.LBB4689:
.LBB4690:
	.loc 1 2440 29 is_stmt 0 view .LVU8000
	imull	$48271, %eax, %r10d
.LBE4690:
.LBE4689:
.LBE4688:
.LBE4687:
.LBE4686:
.LBE4685:
.LBE4684:
.LBE4683:
.LBE4765:
	.loc 1 31713 22 view .LVU8001
	movslq	(%rbx,%rcx,4), %r11
.LVL2075:
	.loc 1 31716 13 is_stmt 1 view .LVU8002
.LBB4766:
	.loc 1 2540 27 view .LVU8003
.LBE4766:
.LBE4791:
.LBE4808:
.LBE4824:
.LBE4840:
.LBE4856:
.LBE4872:
.LBE4889:
.LBE6397:
	.loc 1 2542 5 view .LVU8004
.LBB6398:
.LBB4890:
.LBB4873:
.LBB4857:
.LBB4841:
.LBB4825:
.LBB4809:
.LBB4792:
.LBB4767:
.LBB4699:
	.loc 1 2543 9 view .LVU8005
.LBB4697:
.LBI4684:
	.loc 1 2510 27 view .LVU8006
.LBE4697:
.LBE4699:
.LBE4767:
.LBE4792:
.LBE4809:
.LBE4825:
.LBE4841:
.LBE4857:
.LBE4873:
.LBE4890:
.LBE6398:
	.loc 1 2512 5 view .LVU8007
.LBB6399:
.LBB4891:
.LBB4874:
.LBB4858:
.LBB4842:
.LBB4826:
.LBB4810:
.LBB4793:
.LBB4768:
.LBB4700:
.LBB4698:
.LBB4696:
.LBI4685:
	.loc 1 2469 27 view .LVU8008
.LBB4695:
	.loc 1 2471 5 view .LVU8009
	.loc 1 2475 5 view .LVU8010
.LBB4694:
.LBI4687:
	.loc 1 2444 28 view .LVU8011
.LBB4693:
	.loc 1 2446 5 view .LVU8012
.LBB4692:
.LBI4689:
	.loc 1 2438 27 view .LVU8013
.LBB4691:
	.loc 1 2440 5 view .LVU8014
	.loc 1 2440 55 is_stmt 0 view .LVU8015
	movslq	%r10d, %rdx
	movq	%rdx, %rax
	salq	$30, %rax
	addq	%rdx, %rax
	movl	%r10d, %edx
	sarl	$31, %edx
	sarq	$61, %rax
	subl	%edx, %eax
	movl	%eax, %edx
	sall	$31, %edx
	subl	%eax, %edx
	movl	%r10d, %eax
	subl	%edx, %eax
	.loc 1 2441 5 is_stmt 1 view .LVU8016
.LVL2076:
	.loc 1 2441 5 is_stmt 0 view .LVU8017
.LBE4691:
.LBE4692:
.LBE4693:
.LBE4694:
	.loc 1 2475 39 view .LVU8018
	movl	%eax, %edx
	shrl	$16, %edx
	.loc 1 2475 15 view .LVU8019
	subl	$32768, %edx
.LVL2077:
	.loc 1 2475 15 view .LVU8020
.LBE4695:
.LBE4696:
.LBE4698:
	.loc 1 2544 9 is_stmt 1 view .LVU8021
	.loc 1 2544 9 is_stmt 0 view .LVU8022
.LBE4700:
.LBE4768:
	.loc 1 31717 13 is_stmt 1 view .LVU8023
	.loc 1 31717 31 is_stmt 0 view .LVU8024
	movslq	%edx, %r10
	.loc 1 31717 29 view .LVU8025
	addq	%r11, %r10
	.loc 1 31717 13 view .LVU8026
	cmpq	%r9, %r10
	jl	.L1470
.LVL2078:
	.loc 1 31723 13 is_stmt 1 view .LVU8027
	.loc 1 31724 13 view .LVU8028
	.loc 1 31724 24 is_stmt 0 view .LVU8029
	movl	$32767, %edx
.LVL2079:
	.loc 1 31724 24 view .LVU8030
	movw	%dx, (%rdi,%rcx,2)
.LBE4793:
	.loc 1 31712 9 is_stmt 1 view .LVU8031
	.loc 1 31712 34 is_stmt 0 view .LVU8032
	addq	$1, %rcx
.LVL2080:
	.loc 1 31712 23 is_stmt 1 view .LVU8033
	cmpq	%rcx, %r8
	jne	.L1187
.LVL2081:
.L1192:
	.loc 1 31712 23 is_stmt 0 view .LVU8034
	movl	%eax, _ZL7g_maLCG(%rip)
	jmp	.L1050
.LVL2082:
.L1470:
.LBB4794:
	.loc 1 31718 17 is_stmt 1 view .LVU8035
	.loc 1 31723 13 view .LVU8036
	.loc 1 31724 13 view .LVU8037
	.loc 1 31718 19 is_stmt 0 view .LVU8038
	addl	%r11d, %edx
.LVL2083:
	.loc 1 31723 15 view .LVU8039
	sarl	$16, %edx
	.loc 1 31724 24 view .LVU8040
	movw	%dx, (%rdi,%rcx,2)
.LBE4794:
	.loc 1 31712 9 is_stmt 1 view .LVU8041
	.loc 1 31712 34 is_stmt 0 view .LVU8042
	addq	$1, %rcx
.LVL2084:
	.loc 1 31712 23 is_stmt 1 view .LVU8043
	cmpq	%rcx, %r8
	jne	.L1187
	jmp	.L1192
.LVL2085:
.L1144:
	.loc 1 31712 23 is_stmt 0 view .LVU8044
	leaq	(%r8,%r8,2), %rsi
.LVL2086:
	.loc 1 31712 23 view .LVU8045
.LBE4810:
.LBE4826:
.LBE4842:
.LBE4858:
.LBE4874:
.LBE4891:
.LBE6399:
.LBB6400:
.LBB4640:
.LBB4631:
.LBB4623:
.LBB4615:
.LBB4607:
.LBB4599:
.LBB4585:
	.loc 1 31347 13 view .LVU8046
	movl	$2147483648, %r8d
.LVL2087:
	.loc 1 31347 13 view .LVU8047
	addq	%rdx, %rsi
.LVL2088:
	.p2align 4,,10
	.p2align 3
.L1152:
	.loc 1 31343 13 is_stmt 1 view .LVU8048
	.loc 1 31343 75 is_stmt 0 view .LVU8049
	movzbl	1(%rbx), %eax
	.loc 1 31343 38 view .LVU8050
	movzbl	(%rbx), %edx
.LBB4571:
.LBB4494:
.LBB4495:
.LBB4496:
.LBB4497:
.LBB4498:
.LBB4499:
.LBB4500:
.LBB4501:
	.loc 1 2440 29 view .LVU8051
	imull	$48271, %ecx, %r9d
.LBE4501:
.LBE4500:
.LBE4499:
.LBE4498:
.LBE4497:
.LBE4496:
.LBE4495:
.LBE4494:
.LBE4571:
	.loc 1 31343 66 view .LVU8052
	sall	$8, %edx
	.loc 1 31343 103 view .LVU8053
	sall	$16, %eax
	.loc 1 31343 110 view .LVU8054
	orl	%edx, %eax
	.loc 1 31343 113 view .LVU8055
	movzbl	2(%rbx), %edx
	.loc 1 31343 142 view .LVU8056
	sall	$24, %edx
	.loc 1 31343 110 view .LVU8057
	orl	%edx, %eax
.LVL2089:
	.loc 1 31346 13 is_stmt 1 view .LVU8058
.LBB4572:
	.loc 1 2540 27 view .LVU8059
.LBE4572:
.LBE4585:
.LBE4599:
.LBE4607:
.LBE4615:
.LBE4623:
.LBE4631:
.LBE4640:
.LBE6400:
	.loc 1 2542 5 view .LVU8060
.LBB6401:
.LBB4641:
.LBB4632:
.LBB4624:
.LBB4616:
.LBB4608:
.LBB4600:
.LBB4586:
.LBB4573:
.LBB4517:
	.loc 1 2543 9 view .LVU8061
.LBB4514:
.LBI4495:
	.loc 1 2510 27 view .LVU8062
.LBE4514:
.LBE4517:
.LBE4573:
.LBE4586:
.LBE4600:
.LBE4608:
.LBE4616:
.LBE4624:
.LBE4632:
.LBE4641:
.LBE6401:
	.loc 1 2512 5 view .LVU8063
.LBB6402:
.LBB4642:
.LBB4633:
.LBB4625:
.LBB4617:
.LBB4609:
.LBB4601:
.LBB4587:
.LBB4574:
.LBB4518:
.LBB4515:
.LBB4512:
.LBI4496:
	.loc 1 2469 27 view .LVU8064
.LBB4510:
	.loc 1 2471 5 view .LVU8065
	.loc 1 2475 5 view .LVU8066
.LBB4508:
.LBI4498:
	.loc 1 2444 28 view .LVU8067
.LBB4506:
	.loc 1 2446 5 view .LVU8068
.LBB4504:
.LBI4500:
	.loc 1 2438 27 view .LVU8069
.LBB4502:
	.loc 1 2440 5 view .LVU8070
	.loc 1 2440 55 is_stmt 0 view .LVU8071
	movslq	%r9d, %rdx
	movq	%rdx, %rcx
.LBE4502:
.LBE4504:
.LBE4506:
.LBE4508:
.LBE4510:
.LBE4512:
.LBE4515:
.LBE4518:
.LBE4574:
	.loc 1 31347 17 view .LVU8072
	movslq	%eax, %r10
.LBB4575:
.LBB4519:
.LBB4516:
.LBB4513:
.LBB4511:
.LBB4509:
.LBB4507:
.LBB4505:
.LBB4503:
	.loc 1 2440 55 view .LVU8073
	salq	$30, %rcx
	addq	%rdx, %rcx
	movl	%r9d, %edx
	sarl	$31, %edx
	sarq	$61, %rcx
	subl	%edx, %ecx
	movl	%ecx, %edx
	sall	$31, %edx
	subl	%ecx, %edx
	movl	%r9d, %ecx
	subl	%edx, %ecx
	.loc 1 2441 5 is_stmt 1 view .LVU8074
.LVL2090:
	.loc 1 2441 5 is_stmt 0 view .LVU8075
.LBE4503:
.LBE4505:
.LBE4507:
.LBE4509:
	.loc 1 2475 39 view .LVU8076
	movl	%ecx, %edx
	shrl	$16, %edx
	.loc 1 2475 15 view .LVU8077
	subl	$32768, %edx
.LVL2091:
	.loc 1 2475 15 view .LVU8078
.LBE4511:
.LBE4513:
.LBE4516:
	.loc 1 2544 9 is_stmt 1 view .LVU8079
	.loc 1 2544 9 is_stmt 0 view .LVU8080
.LBE4519:
.LBE4575:
	.loc 1 31347 13 is_stmt 1 view .LVU8081
	.loc 1 31347 31 is_stmt 0 view .LVU8082
	movslq	%edx, %r9
	.loc 1 31347 29 view .LVU8083
	addq	%r10, %r9
	.loc 1 31347 13 view .LVU8084
	cmpq	%r8, %r9
	jl	.L1471
.LVL2092:
	.loc 1 31353 13 is_stmt 1 view .LVU8085
	.loc 1 31354 13 view .LVU8086
	.loc 1 31354 24 is_stmt 0 view .LVU8087
	movl	$32767, %r9d
.LBE4587:
	.loc 1 31342 23 view .LVU8088
	addq	$3, %rbx
	addq	$2, %rdi
.LBB4588:
	.loc 1 31354 24 view .LVU8089
	movw	%r9w, -2(%rdi)
.LBE4588:
	.loc 1 31342 9 is_stmt 1 view .LVU8090
	.loc 1 31342 23 view .LVU8091
	cmpq	%rsi, %rbx
	jne	.L1152
.LVL2093:
.L1148:
	.loc 1 31342 23 is_stmt 0 view .LVU8092
	movl	%ecx, _ZL7g_maLCG(%rip)
	jmp	.L1050
.LVL2094:
.L1471:
.LBB4589:
	.loc 1 31348 17 is_stmt 1 view .LVU8093
	.loc 1 31353 13 view .LVU8094
	.loc 1 31354 13 view .LVU8095
	.loc 1 31348 19 is_stmt 0 view .LVU8096
	addl	%edx, %eax
.LBE4589:
	.loc 1 31342 23 view .LVU8097
	addq	$3, %rbx
	addq	$2, %rdi
.LBB4590:
	.loc 1 31353 15 view .LVU8098
	sarl	$16, %eax
	.loc 1 31354 24 view .LVU8099
	movw	%ax, -2(%rdi)
.LBE4590:
	.loc 1 31342 9 is_stmt 1 view .LVU8100
	.loc 1 31342 23 view .LVU8101
	cmpq	%rsi, %rbx
	jne	.L1152
	jmp	.L1148
.LVL2095:
.L1298:
	.loc 1 31342 23 is_stmt 0 view .LVU8102
.LBE4601:
.LBE4609:
.LBE4617:
.LBE4625:
.LBE4633:
.LBE4642:
.LBE6402:
.LBB6403:
.LBB6268:
.LBB6243:
.LBB6218:
.LBB6193:
.LBB6168:
.LBB6143:
	.loc 1 31631 16 view .LVU8103
	xorl	%ecx, %ecx
.LBB6116:
	.loc 1 31636 13 view .LVU8104
	movl	$2147483648, %esi
.LVL2096:
	.p2align 4,,10
	.p2align 3
.L1169:
	.loc 1 31632 13 is_stmt 1 view .LVU8105
.LBB6073:
.LBB5970:
.LBB5971:
.LBB5972:
.LBB5973:
.LBB5974:
.LBB5975:
.LBB5976:
.LBB5977:
	.loc 1 2440 29 is_stmt 0 view .LVU8106
	imull	$48271, %eax, %r10d
.LBE5977:
.LBE5976:
.LBE5975:
.LBE5974:
.LBE5973:
.LBE5972:
.LBE5971:
.LBE5970:
.LBE6073:
	.loc 1 31632 22 view .LVU8107
	movl	(%rbx,%rcx,4), %edx
.LVL2097:
	.loc 1 31635 13 is_stmt 1 view .LVU8108
.LBB6074:
	.loc 1 2540 27 view .LVU8109
.LBE6074:
.LBE6116:
.LBE6143:
.LBE6168:
.LBE6193:
.LBE6218:
.LBE6243:
.LBE6268:
.LBE6403:
	.loc 1 2542 5 view .LVU8110
.LBB6404:
.LBB6269:
.LBB6244:
.LBB6219:
.LBB6194:
.LBB6169:
.LBB6144:
.LBB6117:
.LBB6075:
.LBB5993:
	.loc 1 2543 9 view .LVU8111
.LBB5990:
.LBI5971:
	.loc 1 2510 27 view .LVU8112
.LBE5990:
.LBE5993:
.LBE6075:
.LBE6117:
.LBE6144:
.LBE6169:
.LBE6194:
.LBE6219:
.LBE6244:
.LBE6269:
.LBE6404:
	.loc 1 2512 5 view .LVU8113
.LBB6405:
.LBB6270:
.LBB6245:
.LBB6220:
.LBB6195:
.LBB6170:
.LBB6145:
.LBB6118:
.LBB6076:
.LBB5994:
.LBB5991:
.LBB5988:
.LBI5972:
	.loc 1 2469 27 view .LVU8114
.LBB5986:
	.loc 1 2471 5 view .LVU8115
	.loc 1 2475 5 view .LVU8116
.LBB5984:
.LBI5974:
	.loc 1 2444 28 view .LVU8117
.LBB5982:
	.loc 1 2446 5 view .LVU8118
.LBB5980:
.LBI5976:
	.loc 1 2438 27 view .LVU8119
.LBB5978:
	.loc 1 2440 5 view .LVU8120
	.loc 1 2440 55 is_stmt 0 view .LVU8121
	movslq	%r10d, %r9
	movq	%r9, %rax
	salq	$30, %rax
	addq	%r9, %rax
	movl	%r10d, %r9d
	sarl	$31, %r9d
	sarq	$61, %rax
	subl	%r9d, %eax
	movl	%eax, %r9d
	sall	$31, %r9d
	subl	%eax, %r9d
	movl	%r10d, %eax
.LBE5978:
.LBE5980:
.LBE5982:
.LBE5984:
.LBE5986:
.LBE5988:
.LBE5991:
.LBE5994:
.LBE6076:
	.loc 1 31636 17 view .LVU8122
	movslq	%edx, %r10
.LBB6077:
.LBB5995:
.LBB5992:
.LBB5989:
.LBB5987:
.LBB5985:
.LBB5983:
.LBB5981:
.LBB5979:
	.loc 1 2440 55 view .LVU8123
	subl	%r9d, %eax
	.loc 1 2441 5 is_stmt 1 view .LVU8124
.LVL2098:
	.loc 1 2441 5 is_stmt 0 view .LVU8125
.LBE5979:
.LBE5981:
.LBE5983:
.LBE5985:
	.loc 1 2475 39 view .LVU8126
	movl	%eax, %r9d
	shrl	$8, %r9d
	.loc 1 2475 15 view .LVU8127
	subl	$8388608, %r9d
.LVL2099:
	.loc 1 2475 15 view .LVU8128
.LBE5987:
.LBE5989:
.LBE5992:
	.loc 1 2544 9 is_stmt 1 view .LVU8129
	.loc 1 2544 9 is_stmt 0 view .LVU8130
.LBE5995:
.LBE6077:
	.loc 1 31636 13 is_stmt 1 view .LVU8131
	.loc 1 31636 31 is_stmt 0 view .LVU8132
	movslq	%r9d, %r11
	.loc 1 31636 29 view .LVU8133
	addq	%r11, %r10
	.loc 1 31636 13 view .LVU8134
	cmpq	%rsi, %r10
	jl	.L1472
.LVL2100:
	.loc 1 31642 13 is_stmt 1 view .LVU8135
	.loc 1 31643 13 view .LVU8136
	.loc 1 31644 13 view .LVU8137
	.loc 1 31644 23 is_stmt 0 view .LVU8138
	movb	$-1, (%rdi,%rcx)
.LBE6118:
	.loc 1 31631 9 is_stmt 1 view .LVU8139
	.loc 1 31631 34 is_stmt 0 view .LVU8140
	addq	$1, %rcx
.LVL2101:
	.loc 1 31631 23 is_stmt 1 view .LVU8141
	cmpq	%rcx, %r8
	jne	.L1169
.LVL2102:
.L1175:
	.loc 1 31631 23 is_stmt 0 view .LVU8142
	movl	%eax, _ZL7g_maLCG(%rip)
	jmp	.L1050
.LVL2103:
.L1472:
.LBB6119:
	.loc 1 31637 17 is_stmt 1 view .LVU8143
	.loc 1 31642 13 view .LVU8144
	.loc 1 31643 13 view .LVU8145
	.loc 1 31644 13 view .LVU8146
	.loc 1 31637 19 is_stmt 0 view .LVU8147
	addl	%r9d, %edx
	.loc 1 31642 15 view .LVU8148
	sarl	$24, %edx
	.loc 1 31643 15 view .LVU8149
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU8150
	movb	%dl, (%rdi,%rcx)
.LBE6119:
	.loc 1 31631 9 is_stmt 1 view .LVU8151
	.loc 1 31631 34 is_stmt 0 view .LVU8152
	addq	$1, %rcx
.LVL2104:
	.loc 1 31631 23 is_stmt 1 view .LVU8153
	cmpq	%rcx, %r8
	jne	.L1169
	jmp	.L1175
.LVL2105:
.L1130:
	.loc 1 31631 23 is_stmt 0 view .LVU8154
	leaq	(%r8,%r8,2), %rsi
.LVL2106:
	.loc 1 31631 23 view .LVU8155
.LBE6145:
.LBE6170:
.LBE6195:
.LBE6220:
.LBE6245:
.LBE6270:
.LBE6405:
.LBB6406:
.LBB5921:
.LBB5913:
.LBB5905:
.LBB5897:
.LBB5889:
.LBB5881:
.LBB5867:
	.loc 1 31266 13 view .LVU8156
	movl	$2147483648, %r8d
.LVL2107:
	.loc 1 31266 13 view .LVU8157
	addq	%rdx, %rsi
.LVL2108:
	.p2align 4,,10
	.p2align 3
.L1138:
	.loc 1 31262 13 is_stmt 1 view .LVU8158
	.loc 1 31262 38 is_stmt 0 view .LVU8159
	movzbl	(%rbx), %eax
	.loc 1 31262 75 view .LVU8160
	movzbl	1(%rbx), %edx
.LBB5854:
.LBB5780:
.LBB5781:
.LBB5782:
.LBB5783:
.LBB5784:
.LBB5785:
.LBB5786:
.LBB5787:
	.loc 1 2440 29 view .LVU8161
	imull	$48271, %ecx, %r9d
.LBE5787:
.LBE5786:
.LBE5785:
.LBE5784:
.LBE5783:
.LBE5782:
.LBE5781:
.LBE5780:
.LBE5854:
	.loc 1 31262 103 view .LVU8162
	sall	$16, %edx
	.loc 1 31262 66 view .LVU8163
	sall	$8, %eax
	.loc 1 31262 110 view .LVU8164
	orl	%edx, %eax
	.loc 1 31262 113 view .LVU8165
	movzbl	2(%rbx), %edx
	.loc 1 31262 142 view .LVU8166
	sall	$24, %edx
	.loc 1 31262 110 view .LVU8167
	orl	%edx, %eax
.LVL2109:
	.loc 1 31265 13 is_stmt 1 view .LVU8168
.LBB5855:
	.loc 1 2540 27 view .LVU8169
.LBE5855:
.LBE5867:
.LBE5881:
.LBE5889:
.LBE5897:
.LBE5905:
.LBE5913:
.LBE5921:
.LBE6406:
	.loc 1 2542 5 view .LVU8170
.LBB6407:
.LBB5922:
.LBB5914:
.LBB5906:
.LBB5898:
.LBB5890:
.LBB5882:
.LBB5868:
.LBB5856:
.LBB5803:
	.loc 1 2543 9 view .LVU8171
.LBB5800:
.LBI5781:
	.loc 1 2510 27 view .LVU8172
.LBE5800:
.LBE5803:
.LBE5856:
.LBE5868:
.LBE5882:
.LBE5890:
.LBE5898:
.LBE5906:
.LBE5914:
.LBE5922:
.LBE6407:
	.loc 1 2512 5 view .LVU8173
.LBB6408:
.LBB5923:
.LBB5915:
.LBB5907:
.LBB5899:
.LBB5891:
.LBB5883:
.LBB5869:
.LBB5857:
.LBB5804:
.LBB5801:
.LBB5798:
.LBI5782:
	.loc 1 2469 27 view .LVU8174
.LBB5796:
	.loc 1 2471 5 view .LVU8175
	.loc 1 2475 5 view .LVU8176
.LBB5794:
.LBI5784:
	.loc 1 2444 28 view .LVU8177
.LBB5792:
	.loc 1 2446 5 view .LVU8178
.LBB5790:
.LBI5786:
	.loc 1 2438 27 view .LVU8179
.LBB5788:
	.loc 1 2440 5 view .LVU8180
	.loc 1 2440 55 is_stmt 0 view .LVU8181
	movslq	%r9d, %rdx
	movq	%rdx, %rcx
.LBE5788:
.LBE5790:
.LBE5792:
.LBE5794:
.LBE5796:
.LBE5798:
.LBE5801:
.LBE5804:
.LBE5857:
	.loc 1 31266 17 view .LVU8182
	movslq	%eax, %r10
.LBB5858:
.LBB5805:
.LBB5802:
.LBB5799:
.LBB5797:
.LBB5795:
.LBB5793:
.LBB5791:
.LBB5789:
	.loc 1 2440 55 view .LVU8183
	salq	$30, %rcx
	addq	%rdx, %rcx
	movl	%r9d, %edx
	sarl	$31, %edx
	sarq	$61, %rcx
	subl	%edx, %ecx
	movl	%ecx, %edx
	sall	$31, %edx
	subl	%ecx, %edx
	movl	%r9d, %ecx
	subl	%edx, %ecx
	.loc 1 2441 5 is_stmt 1 view .LVU8184
.LVL2110:
	.loc 1 2441 5 is_stmt 0 view .LVU8185
.LBE5789:
.LBE5791:
.LBE5793:
.LBE5795:
	.loc 1 2475 39 view .LVU8186
	movl	%ecx, %edx
	shrl	$8, %edx
	.loc 1 2475 15 view .LVU8187
	subl	$8388608, %edx
.LVL2111:
	.loc 1 2475 15 view .LVU8188
.LBE5797:
.LBE5799:
.LBE5802:
	.loc 1 2544 9 is_stmt 1 view .LVU8189
	.loc 1 2544 9 is_stmt 0 view .LVU8190
.LBE5805:
.LBE5858:
	.loc 1 31266 13 is_stmt 1 view .LVU8191
	.loc 1 31266 31 is_stmt 0 view .LVU8192
	movslq	%edx, %r9
	.loc 1 31266 29 view .LVU8193
	addq	%r10, %r9
	.loc 1 31266 13 view .LVU8194
	cmpq	%r8, %r9
	jl	.L1473
.LVL2112:
	.loc 1 31272 13 is_stmt 1 view .LVU8195
	.loc 1 31273 13 view .LVU8196
	.loc 1 31274 13 view .LVU8197
.LBE5869:
	.loc 1 31261 23 is_stmt 0 view .LVU8198
	addq	$3, %rbx
.LBB5870:
	.loc 1 31274 23 view .LVU8199
	movb	$-1, (%rdi)
.LBE5870:
	.loc 1 31261 9 is_stmt 1 view .LVU8200
.LVL2113:
	.loc 1 31261 23 view .LVU8201
	addq	$1, %rdi
.LVL2114:
	.loc 1 31261 23 is_stmt 0 view .LVU8202
	cmpq	%rbx, %rsi
	jne	.L1138
.LVL2115:
.L1134:
	.loc 1 31261 23 view .LVU8203
	movl	%ecx, _ZL7g_maLCG(%rip)
	jmp	.L1050
.LVL2116:
.L1473:
.LBB5871:
	.loc 1 31267 17 is_stmt 1 view .LVU8204
	.loc 1 31272 13 view .LVU8205
	.loc 1 31273 13 view .LVU8206
	.loc 1 31274 13 view .LVU8207
	.loc 1 31267 19 is_stmt 0 view .LVU8208
	addl	%edx, %eax
.LBE5871:
	.loc 1 31261 23 view .LVU8209
	addq	$3, %rbx
	addq	$1, %rdi
.LVL2117:
.LBB5872:
	.loc 1 31272 15 view .LVU8210
	sarl	$24, %eax
	.loc 1 31273 15 view .LVU8211
	subl	$-128, %eax
	.loc 1 31274 23 view .LVU8212
	movb	%al, -1(%rdi)
.LBE5872:
	.loc 1 31261 9 is_stmt 1 view .LVU8213
.LVL2118:
	.loc 1 31261 23 view .LVU8214
	cmpq	%rsi, %rbx
	jne	.L1138
	jmp	.L1134
.LVL2119:
.L1294:
	.loc 1 31261 23 is_stmt 0 view .LVU8215
.LBE5883:
.LBE5891:
.LBE5899:
.LBE5907:
.LBE5915:
.LBE5923:
.LBE6408:
.LBB6409:
.LBB4998:
.LBB4997:
.LBB4996:
	.loc 1 31060 12 view .LVU8216
	xorl	%eax, %eax
	jmp	.L1107
.LVL2120:
.L1121:
	.loc 1 31060 12 view .LVU8217
	movq	%rcx, %rax
.LVL2121:
	.p2align 4,,10
	.p2align 3
.L1129:
	.loc 1 31060 12 view .LVU8218
.LBE4996:
.LBE4997:
.LBE4998:
.LBE6409:
.LBB6410:
.LBB5924:
.LBB5769:
.LBB5767:
.LBB5765:
.LBB5763:
	.loc 1 31257 13 is_stmt 1 view .LVU8219
	.loc 1 31257 62 is_stmt 0 view .LVU8220
	movzbl	(%rax), %ebx
	.loc 1 31256 23 view .LVU8221
	addq	$1, %rdi
.LVL2122:
	.loc 1 31256 23 view .LVU8222
	addq	$3, %rax
	.loc 1 31257 62 view .LVU8223
	leal	-128(%rbx), %edx
	.loc 1 31257 23 view .LVU8224
	movb	%dl, -1(%rdi)
	.loc 1 31256 9 is_stmt 1 view .LVU8225
.LVL2123:
	.loc 1 31256 23 view .LVU8226
	cmpq	%rdi, %rsi
	jne	.L1129
	jmp	.L1050
.LVL2124:
.L1290:
	.loc 1 31256 23 is_stmt 0 view .LVU8227
.LBE5763:
.LBE5765:
.LBE5767:
.LBE5769:
.LBE5924:
.LBE6410:
.LBB6411:
.LBB5371:
.LBB5070:
.LBB5069:
.LBB5068:
.LBB5067:
.LBB5066:
	.loc 1 30908 16 view .LVU8228
	xorl	%eax, %eax
.LVL2125:
	.p2align 4,,10
	.p2align 3
.L1088:
.LBB5065:
	.loc 1 30909 13 is_stmt 1 view .LVU8229
	.loc 1 30910 13 view .LVU8230
	.loc 1 30911 13 view .LVU8231
	.loc 1 30912 13 view .LVU8232
	.loc 1 30910 15 is_stmt 0 view .LVU8233
	movsbw	1(%rbx,%rax,2), %dx
	.loc 1 30911 30 view .LVU8234
	subw	$-128, %dx
	.loc 1 30912 23 view .LVU8235
	movb	%dl, (%rdi,%rax)
.LVL2126:
	.loc 1 30912 23 view .LVU8236
.LBE5065:
	.loc 1 30908 9 is_stmt 1 view .LVU8237
	.loc 1 30908 34 is_stmt 0 view .LVU8238
	addq	$1, %rax
.LVL2127:
	.loc 1 30908 23 is_stmt 1 view .LVU8239
	cmpq	%rax, %r8
	jne	.L1088
	jmp	.L1050
.LVL2128:
.L1295:
	.loc 1 30908 23 is_stmt 0 view .LVU8240
.LBE5066:
.LBE5067:
.LBE5068:
.LBE5069:
.LBE5070:
.LBE5371:
.LBE6411:
.LBB6412:
.LBB4945:
.LBB4944:
.LBB4943:
.LBB4942:
	.loc 1 31122 12 view .LVU8241
	xorl	%eax, %eax
	jmp	.L1111
.LVL2129:
.L1297:
	.loc 1 31122 12 view .LVU8242
.LBE4942:
.LBE4943:
.LBE4944:
.LBE4945:
.LBE6412:
.LBB6413:
.LBB6271:
.LBB5960:
.LBB5959:
.LBB5958:
.LBB5957:
.LBB5956:
	.loc 1 31623 16 view .LVU8243
	xorl	%eax, %eax
.LVL2130:
	.p2align 4,,10
	.p2align 3
.L1164:
.LBB5955:
	.loc 1 31624 13 is_stmt 1 view .LVU8244
	.loc 1 31625 13 view .LVU8245
	.loc 1 31625 15 is_stmt 0 view .LVU8246
	movsbl	3(%rbx,%rax,4), %edx
.LVL2131:
	.loc 1 31626 13 is_stmt 1 view .LVU8247
	.loc 1 31627 13 view .LVU8248
	.loc 1 31626 15 is_stmt 0 view .LVU8249
	subl	$-128, %edx
.LVL2132:
	.loc 1 31627 23 view .LVU8250
	movb	%dl, (%rdi,%rax)
.LBE5955:
	.loc 1 31623 9 is_stmt 1 view .LVU8251
	.loc 1 31623 34 is_stmt 0 view .LVU8252
	addq	$1, %rax
.LVL2133:
	.loc 1 31623 23 is_stmt 1 view .LVU8253
	cmpq	%rax, %r8
	jne	.L1164
	jmp	.L1050
.LVL2134:
.L1305:
	.loc 1 31623 23 is_stmt 0 view .LVU8254
.LBE5956:
.LBE5957:
.LBE5958:
.LBE5959:
.LBE5960:
.LBE6271:
.LBE6413:
.LBB6414:
.LBB4987:
.LBB4986:
.LBB4985:
.LBB4984:
	.loc 1 31857 12 view .LVU8255
	xorl	%eax, %eax
	jmp	.L1200
.LVL2135:
.L1308:
	.loc 1 31857 12 view .LVU8256
	movss	.LC77(%rip), %xmm0
	movss	.LC88(%rip), %xmm3
.LBE4984:
.LBE4985:
.LBE4986:
.LBE4987:
.LBE6414:
.LBB6415:
.LBB5749:
.LBB5718:
.LBB5688:
.LBB5658:
	.loc 1 31996 12 view .LVU8257
	xorl	%eax, %eax
	movss	.LC103(%rip), %xmm5
.LVL2136:
.L1212:
.LBB5628:
	.loc 1 31997 9 is_stmt 1 view .LVU8258
	.loc 1 31998 9 view .LVU8259
.LBB5584:
	.loc 1 2528 24 view .LVU8260
.LBE5584:
.LBE5628:
.LBE5658:
.LBE5688:
.LBE5718:
.LBE5749:
.LBE6415:
	.loc 1 2530 5 view .LVU8261
	.loc 1 2533 5 view .LVU8262
.LBB6416:
.LBB5750:
.LBB5719:
.LBB5689:
.LBB5659:
.LBB5629:
	.loc 1 31999 9 view .LVU8263
	.loc 1 31999 23 is_stmt 0 view .LVU8264
	movss	(%rbx,%rax,4), %xmm1
	minss	%xmm0, %xmm1
	maxss	%xmm3, %xmm1
.LVL2137:
	.loc 1 32000 9 is_stmt 1 view .LVU8265
	.loc 1 32000 11 is_stmt 0 view .LVU8266
	addss	%xmm0, %xmm1
.LVL2138:
	.loc 1 32001 9 is_stmt 1 view .LVU8267
	.loc 1 32003 9 view .LVU8268
	.loc 1 32001 11 is_stmt 0 view .LVU8269
	mulss	%xmm5, %xmm1
.LVL2139:
	.loc 1 32003 21 view .LVU8270
	cvttss2sil	%xmm1, %edx
	movb	%dl, (%rdi,%rax)
.LVL2140:
	.loc 1 32003 21 view .LVU8271
.LBE5629:
	.loc 1 31996 5 is_stmt 1 view .LVU8272
	.loc 1 31996 30 is_stmt 0 view .LVU8273
	addq	$1, %rax
.LVL2141:
	.loc 1 31996 19 is_stmt 1 view .LVU8274
	cmpq	%rax, %r8
	jne	.L1212
	jmp	.L1050
.LVL2142:
.L1145:
	.loc 1 31996 19 is_stmt 0 view .LVU8275
	leaq	(%r8,%r8,2), %r8
.LVL2143:
	.loc 1 31996 19 view .LVU8276
.LBE5659:
.LBE5689:
.LBE5719:
.LBE5750:
.LBE6416:
.LBB6417:
.LBB4643:
.LBB4634:
.LBB4626:
.LBB4618:
.LBB4610:
.LBB4602:
.LBB4591:
	.loc 1 31347 13 view .LVU8277
	movl	$2147483648, %r9d
.LVL2144:
	.loc 1 31347 13 view .LVU8278
	addq	%rdx, %r8
.LVL2145:
.L1147:
	.loc 1 31343 13 is_stmt 1 view .LVU8279
	.loc 1 31343 75 is_stmt 0 view .LVU8280
	movzbl	1(%rbx), %esi
	.loc 1 31343 38 view .LVU8281
	movzbl	(%rbx), %eax
.LBB4576:
.LBB4520:
.LBB4521:
.LBB4522:
.LBB4523:
.LBB4524:
.LBB4525:
.LBB4526:
.LBB4527:
	.loc 1 2440 29 view .LVU8282
	imull	$48271, %ecx, %edx
.LBE4527:
.LBE4526:
.LBE4525:
.LBE4524:
.LBE4523:
.LBE4522:
.LBE4521:
.LBE4520:
.LBE4576:
	.loc 1 31343 66 view .LVU8283
	sall	$8, %eax
	.loc 1 31343 103 view .LVU8284
	sall	$16, %esi
	.loc 1 31343 110 view .LVU8285
	orl	%eax, %esi
	.loc 1 31343 113 view .LVU8286
	movzbl	2(%rbx), %eax
.LBB4577:
.LBB4566:
.LBB4546:
.LBB4541:
.LBB4536:
.LBB4534:
.LBB4532:
.LBB4530:
.LBB4528:
	.loc 1 2440 55 view .LVU8287
	movslq	%edx, %rcx
.LBE4528:
.LBE4530:
.LBE4532:
.LBE4534:
.LBE4536:
.LBE4541:
.LBE4546:
.LBE4566:
.LBE4577:
	.loc 1 31343 142 view .LVU8288
	sall	$24, %eax
	.loc 1 31343 110 view .LVU8289
	orl	%eax, %esi
.LVL2146:
	.loc 1 31346 13 is_stmt 1 view .LVU8290
.LBB4578:
	.loc 1 2540 27 view .LVU8291
.LBE4578:
.LBE4591:
.LBE4602:
.LBE4610:
.LBE4618:
.LBE4626:
.LBE4634:
.LBE4643:
.LBE6417:
	.loc 1 2542 5 view .LVU8292
	.loc 1 2546 5 view .LVU8293
.LBB6418:
.LBB4644:
.LBB4635:
.LBB4627:
.LBB4619:
.LBB4611:
.LBB4603:
.LBB4592:
.LBB4579:
.LBB4567:
	.loc 1 2547 9 view .LVU8294
.LBB4547:
.LBI4521:
	.loc 1 2510 27 view .LVU8295
.LBE4547:
.LBE4567:
.LBE4579:
.LBE4592:
.LBE4603:
.LBE4611:
.LBE4619:
.LBE4627:
.LBE4635:
.LBE4644:
.LBE6418:
	.loc 1 2512 5 view .LVU8296
.LBB6419:
.LBB4645:
.LBB4636:
.LBB4628:
.LBB4620:
.LBB4612:
.LBB4604:
.LBB4593:
.LBB4580:
.LBB4568:
.LBB4548:
.LBB4542:
.LBI4522:
	.loc 1 2469 27 view .LVU8297
.LBB4537:
	.loc 1 2471 5 view .LVU8298
	.loc 1 2475 5 view .LVU8299
.LBB4535:
.LBI4524:
	.loc 1 2444 28 view .LVU8300
.LBB4533:
	.loc 1 2446 5 view .LVU8301
.LBB4531:
.LBI4526:
	.loc 1 2438 27 view .LVU8302
.LBB4529:
	.loc 1 2440 5 view .LVU8303
	.loc 1 2440 55 is_stmt 0 view .LVU8304
	movq	%rcx, %rax
	salq	$30, %rax
	addq	%rcx, %rax
	movl	%edx, %ecx
	sarl	$31, %ecx
	sarq	$61, %rax
	subl	%ecx, %eax
	movl	%eax, %r10d
	sall	$31, %r10d
	subl	%eax, %r10d
	movl	%edx, %eax
	subl	%r10d, %eax
	.loc 1 2441 5 is_stmt 1 view .LVU8305
.LVL2147:
	.loc 1 2441 5 is_stmt 0 view .LVU8306
.LBE4529:
.LBE4531:
.LBE4533:
.LBE4535:
.LBE4537:
.LBE4542:
.LBE4548:
	.loc 1 2548 9 is_stmt 1 view .LVU8307
.LBB4549:
.LBI4549:
	.loc 1 2510 27 view .LVU8308
.LBE4549:
.LBE4568:
.LBE4580:
.LBE4593:
.LBE4604:
.LBE4612:
.LBE4620:
.LBE4628:
.LBE4636:
.LBE4645:
.LBE6419:
	.loc 1 2512 5 view .LVU8309
.LBB6420:
.LBB4646:
.LBB4637:
.LBB4629:
.LBB4621:
.LBB4613:
.LBB4605:
.LBB4594:
.LBB4581:
.LBB4569:
.LBB4560:
.LBB4550:
.LBI4550:
	.loc 1 2469 27 view .LVU8310
.LBB4551:
	.loc 1 2471 5 view .LVU8311
	.loc 1 2475 5 view .LVU8312
.LBB4552:
.LBI4552:
	.loc 1 2444 28 view .LVU8313
.LBB4553:
	.loc 1 2446 5 view .LVU8314
.LBB4554:
.LBI4554:
	.loc 1 2438 27 view .LVU8315
.LBB4555:
	.loc 1 2440 5 view .LVU8316
	.loc 1 2440 29 is_stmt 0 view .LVU8317
	imull	$48271, %eax, %r10d
	.loc 1 2440 55 view .LVU8318
	movslq	%r10d, %rcx
	movl	%r10d, %r11d
	movq	%rcx, %rdx
	sarl	$31, %r11d
	salq	$30, %rdx
	addq	%rcx, %rdx
	sarq	$61, %rdx
	subl	%r11d, %edx
	movl	%edx, %ecx
	sall	$31, %edx
	subl	%ecx, %edx
	movl	%r10d, %ecx
	subl	%edx, %ecx
	.loc 1 2441 5 is_stmt 1 view .LVU8319
.LVL2148:
	.loc 1 2441 5 is_stmt 0 view .LVU8320
.LBE4555:
.LBE4554:
.LBE4553:
.LBE4552:
.LBE4551:
.LBE4550:
.LBE4560:
	.loc 1 2549 9 is_stmt 1 view .LVU8321
.LBB4561:
.LBB4543:
.LBB4538:
	.loc 1 2475 39 is_stmt 0 view .LVU8322
	movl	%eax, %edx
	leaq	(%rdx,%rdx,2), %rdx
	movq	%rdx, %r10
	salq	$15, %r10
	addq	%r10, %rdx
.LBE4538:
.LBE4543:
.LBE4561:
.LBE4569:
.LBE4581:
	.loc 1 31347 17 view .LVU8323
	movslq	%esi, %r10
.LBB4582:
.LBB4570:
.LBB4562:
.LBB4544:
.LBB4539:
	.loc 1 2475 39 view .LVU8324
	shrq	$32, %rdx
	subl	%edx, %eax
.LVL2149:
	.loc 1 2475 39 view .LVU8325
	shrl	%eax
	addl	%edx, %eax
.LBE4539:
.LBE4544:
.LBE4562:
.LBB4563:
.LBB4558:
.LBB4556:
	movl	%ecx, %edx
.LBE4556:
.LBE4558:
.LBE4563:
.LBB4564:
.LBB4545:
.LBB4540:
	shrl	$16, %eax
.LBE4540:
.LBE4545:
.LBE4564:
.LBB4565:
.LBB4559:
.LBB4557:
	shrl	$17, %edx
.LVL2150:
	.loc 1 2475 39 view .LVU8326
.LBE4557:
.LBE4559:
.LBE4565:
	.loc 1 2549 20 view .LVU8327
	leal	-32768(%rax,%rdx), %edx
.LVL2151:
	.loc 1 2549 20 view .LVU8328
.LBE4570:
.LBE4582:
	.loc 1 31347 13 is_stmt 1 view .LVU8329
	.loc 1 31347 31 is_stmt 0 view .LVU8330
	movslq	%edx, %rax
	.loc 1 31347 29 view .LVU8331
	addq	%r10, %rax
	.loc 1 31347 13 view .LVU8332
	cmpq	%r9, %rax
	jl	.L1474
.LVL2152:
	.loc 1 31353 13 is_stmt 1 view .LVU8333
	.loc 1 31354 13 view .LVU8334
	.loc 1 31354 24 is_stmt 0 view .LVU8335
	movl	$32767, %r10d
.LBE4594:
	.loc 1 31342 23 view .LVU8336
	addq	$3, %rbx
	addq	$2, %rdi
.LBB4595:
	.loc 1 31354 24 view .LVU8337
	movw	%r10w, -2(%rdi)
.LBE4595:
	.loc 1 31342 9 is_stmt 1 view .LVU8338
	.loc 1 31342 23 view .LVU8339
	cmpq	%r8, %rbx
	jne	.L1147
	jmp	.L1148
.LVL2153:
.L1474:
.LBB4596:
	.loc 1 31348 17 view .LVU8340
	.loc 1 31353 13 view .LVU8341
	.loc 1 31354 13 view .LVU8342
	.loc 1 31348 19 is_stmt 0 view .LVU8343
	addl	%edx, %esi
.LBE4596:
	.loc 1 31342 23 view .LVU8344
	addq	$3, %rbx
	addq	$2, %rdi
.LBB4597:
	.loc 1 31353 15 view .LVU8345
	sarl	$16, %esi
	.loc 1 31354 24 view .LVU8346
	movw	%si, -2(%rdi)
.LBE4597:
	.loc 1 31342 9 is_stmt 1 view .LVU8347
	.loc 1 31342 23 view .LVU8348
	cmpq	%r8, %rbx
	jne	.L1147
	jmp	.L1148
.LVL2154:
.L1299:
	.loc 1 31342 23 is_stmt 0 view .LVU8349
.LBE4605:
.LBE4613:
.LBE4621:
.LBE4629:
.LBE4637:
.LBE4646:
.LBE6420:
.LBB6421:
.LBB6272:
.LBB6246:
.LBB6221:
.LBB6196:
.LBB6171:
.LBB6146:
	.loc 1 31631 16 view .LVU8350
	xorl	%esi, %esi
.LVL2155:
.LBB6120:
	.loc 1 31636 13 view .LVU8351
	movl	$2147483648, %r9d
.LVL2156:
.L1170:
	.loc 1 31632 13 is_stmt 1 view .LVU8352
.LBB6078:
.LBB5996:
.LBB5997:
.LBB5998:
.LBB5999:
.LBB6000:
.LBB6001:
.LBB6002:
.LBB6003:
	.loc 1 2440 29 is_stmt 0 view .LVU8353
	imull	$48271, %eax, %eax
.LBE6003:
.LBE6002:
.LBE6001:
.LBE6000:
.LBE5999:
.LBE5998:
.LBE5997:
.LBE5996:
.LBE6078:
	.loc 1 31632 22 view .LVU8354
	movl	(%rbx,%rsi,4), %ecx
.LVL2157:
	.loc 1 31635 13 is_stmt 1 view .LVU8355
.LBB6079:
	.loc 1 2540 27 view .LVU8356
.LBE6079:
.LBE6120:
.LBE6146:
.LBE6171:
.LBE6196:
.LBE6221:
.LBE6246:
.LBE6272:
.LBE6421:
	.loc 1 2542 5 view .LVU8357
	.loc 1 2546 5 view .LVU8358
.LBB6422:
.LBB6273:
.LBB6247:
.LBB6222:
.LBB6197:
.LBB6172:
.LBB6147:
.LBB6121:
.LBB6080:
.LBB6054:
	.loc 1 2547 9 view .LVU8359
.LBB6018:
.LBI5997:
	.loc 1 2510 27 view .LVU8360
.LBE6018:
.LBE6054:
.LBE6080:
.LBE6121:
.LBE6147:
.LBE6172:
.LBE6197:
.LBE6222:
.LBE6247:
.LBE6273:
.LBE6422:
	.loc 1 2512 5 view .LVU8361
.LBB6423:
.LBB6274:
.LBB6248:
.LBB6223:
.LBB6198:
.LBB6173:
.LBB6148:
.LBB6122:
.LBB6081:
.LBB6055:
.LBB6019:
.LBB6015:
.LBI5998:
	.loc 1 2469 27 view .LVU8362
.LBB6012:
	.loc 1 2471 5 view .LVU8363
	.loc 1 2475 5 view .LVU8364
.LBB6010:
.LBI6000:
	.loc 1 2444 28 view .LVU8365
.LBB6008:
	.loc 1 2446 5 view .LVU8366
.LBB6006:
.LBI6002:
	.loc 1 2438 27 view .LVU8367
.LBB6004:
	.loc 1 2440 5 view .LVU8368
	.loc 1 2440 55 is_stmt 0 view .LVU8369
	movslq	%eax, %r10
	movq	%r10, %rdx
	salq	$30, %rdx
	addq	%r10, %rdx
	movl	%eax, %r10d
	sarl	$31, %r10d
	sarq	$61, %rdx
	subl	%r10d, %edx
	movl	%edx, %r10d
	sall	$31, %r10d
	subl	%edx, %r10d
	subl	%r10d, %eax
.LBE6004:
.LBE6006:
.LBE6008:
.LBE6010:
.LBE6012:
.LBE6015:
.LBE6019:
.LBB6020:
.LBB6021:
.LBB6022:
.LBB6023:
.LBB6024:
.LBB6025:
.LBB6026:
	.loc 1 2440 29 view .LVU8370
	imull	$48271, %eax, %r11d
.LBE6026:
.LBE6025:
.LBE6024:
.LBE6023:
.LBE6022:
.LBE6021:
.LBE6020:
.LBB6047:
.LBB6016:
.LBB6013:
.LBB6011:
.LBB6009:
.LBB6007:
.LBB6005:
	.loc 1 2440 55 view .LVU8371
	movl	%eax, %edx
	.loc 1 2441 5 is_stmt 1 view .LVU8372
.LVL2158:
	.loc 1 2441 5 is_stmt 0 view .LVU8373
.LBE6005:
.LBE6007:
.LBE6009:
.LBE6011:
.LBE6013:
.LBE6016:
.LBE6047:
	.loc 1 2548 9 is_stmt 1 view .LVU8374
.LBB6048:
.LBI6020:
	.loc 1 2510 27 view .LVU8375
.LBE6048:
.LBE6055:
.LBE6081:
.LBE6122:
.LBE6148:
.LBE6173:
.LBE6198:
.LBE6223:
.LBE6248:
.LBE6274:
.LBE6423:
	.loc 1 2512 5 view .LVU8376
.LBB6424:
.LBB6275:
.LBB6249:
.LBB6224:
.LBB6199:
.LBB6174:
.LBB6149:
.LBB6123:
.LBB6082:
.LBB6056:
.LBB6049:
.LBB6043:
.LBI6021:
	.loc 1 2469 27 view .LVU8377
.LBB6039:
	.loc 1 2471 5 view .LVU8378
	.loc 1 2475 5 view .LVU8379
.LBB6036:
.LBI6023:
	.loc 1 2444 28 view .LVU8380
.LBB6033:
	.loc 1 2446 5 view .LVU8381
.LBB6030:
.LBI6025:
	.loc 1 2438 27 view .LVU8382
.LBB6027:
	.loc 1 2440 5 view .LVU8383
.LBE6027:
.LBE6030:
.LBE6033:
.LBE6036:
.LBE6039:
.LBE6043:
.LBE6049:
.LBB6050:
.LBB6017:
.LBB6014:
	.loc 1 2475 39 is_stmt 0 view .LVU8384
	shrl	$9, %edx
.LBE6014:
.LBE6017:
.LBE6050:
.LBB6051:
.LBB6044:
.LBB6040:
.LBB6037:
.LBB6034:
.LBB6031:
.LBB6028:
	.loc 1 2440 55 view .LVU8385
	movslq	%r11d, %r10
	movq	%r10, %rax
.LVL2159:
	.loc 1 2440 55 view .LVU8386
	salq	$30, %rax
	addq	%r10, %rax
	movl	%r11d, %r10d
	sarl	$31, %r10d
	sarq	$61, %rax
	subl	%r10d, %eax
	movl	%eax, %r10d
	sall	$31, %r10d
	subl	%eax, %r10d
	movl	%r11d, %eax
.LBE6028:
.LBE6031:
.LBE6034:
.LBE6037:
.LBE6040:
.LBE6044:
.LBE6051:
.LBE6056:
.LBE6082:
	.loc 1 31636 17 view .LVU8387
	movslq	%ecx, %r11
.LBB6083:
.LBB6057:
.LBB6052:
.LBB6045:
.LBB6041:
.LBB6038:
.LBB6035:
.LBB6032:
.LBB6029:
	.loc 1 2440 55 view .LVU8388
	subl	%r10d, %eax
	.loc 1 2441 5 is_stmt 1 view .LVU8389
.LVL2160:
	.loc 1 2441 5 is_stmt 0 view .LVU8390
.LBE6029:
.LBE6032:
.LBE6035:
.LBE6038:
.LBE6041:
.LBE6045:
.LBE6052:
	.loc 1 2549 9 is_stmt 1 view .LVU8391
.LBB6053:
.LBB6046:
.LBB6042:
	.loc 1 2475 39 is_stmt 0 view .LVU8392
	movl	%eax, %r10d
	shrl	$9, %r10d
.LVL2161:
	.loc 1 2475 39 view .LVU8393
.LBE6042:
.LBE6046:
.LBE6053:
	.loc 1 2549 20 view .LVU8394
	leal	-8388608(%rdx,%r10), %r10d
.LVL2162:
	.loc 1 2549 20 view .LVU8395
.LBE6057:
.LBE6083:
	.loc 1 31636 13 is_stmt 1 view .LVU8396
	.loc 1 31636 31 is_stmt 0 view .LVU8397
	movslq	%r10d, %rdx
	.loc 1 31636 29 view .LVU8398
	addq	%r11, %rdx
	.loc 1 31636 13 view .LVU8399
	cmpq	%r9, %rdx
	jl	.L1475
.LVL2163:
	.loc 1 31642 13 is_stmt 1 view .LVU8400
	.loc 1 31643 13 view .LVU8401
	.loc 1 31644 13 view .LVU8402
	.loc 1 31644 23 is_stmt 0 view .LVU8403
	movb	$-1, (%rdi,%rsi)
.LBE6123:
	.loc 1 31631 9 is_stmt 1 view .LVU8404
	.loc 1 31631 34 is_stmt 0 view .LVU8405
	addq	$1, %rsi
.LVL2164:
	.loc 1 31631 23 is_stmt 1 view .LVU8406
	cmpq	%rsi, %r8
	jne	.L1170
	jmp	.L1175
.LVL2165:
.L1475:
.LBB6124:
	.loc 1 31637 17 view .LVU8407
	.loc 1 31642 13 view .LVU8408
	.loc 1 31643 13 view .LVU8409
	.loc 1 31644 13 view .LVU8410
	.loc 1 31637 19 is_stmt 0 view .LVU8411
	leal	(%rcx,%r10), %edx
	.loc 1 31642 15 view .LVU8412
	sarl	$24, %edx
	.loc 1 31643 15 view .LVU8413
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU8414
	movb	%dl, (%rdi,%rsi)
.LBE6124:
	.loc 1 31631 9 is_stmt 1 view .LVU8415
	.loc 1 31631 34 is_stmt 0 view .LVU8416
	addq	$1, %rsi
.LVL2166:
	.loc 1 31631 23 is_stmt 1 view .LVU8417
	cmpq	%rsi, %r8
	jne	.L1170
	jmp	.L1175
.LVL2167:
.L1292:
	.loc 1 31631 23 is_stmt 0 view .LVU8418
.LBE6149:
.LBE6174:
.LBE6199:
.LBE6224:
.LBE6249:
.LBE6275:
.LBE6424:
.LBB6425:
.LBB5372:
.LBB5346:
.LBB5321:
.LBB5296:
.LBB5271:
.LBB5246:
	.loc 1 30916 16 view .LVU8419
	xorl	%r9d, %r9d
.LVL2168:
.L1094:
.LBB5220:
	.loc 1 30917 13 is_stmt 1 view .LVU8420
.LBB5179:
.LBB5106:
.LBB5107:
.LBB5108:
.LBB5109:
.LBB5110:
.LBB5111:
.LBB5112:
.LBB5113:
	.loc 1 2440 29 is_stmt 0 view .LVU8421
	imull	$48271, %eax, %eax
.LBE5113:
.LBE5112:
.LBE5111:
.LBE5110:
.LBE5109:
.LBE5108:
.LBE5107:
.LBE5106:
.LBE5179:
	.loc 1 30917 22 view .LVU8422
	movzwl	(%rbx,%r9,2), %esi
.LVL2169:
	.loc 1 30920 13 is_stmt 1 view .LVU8423
.LBB5180:
	.loc 1 2540 27 view .LVU8424
.LBE5180:
.LBE5220:
.LBE5246:
.LBE5271:
.LBE5296:
.LBE5321:
.LBE5346:
.LBE5372:
.LBE6425:
	.loc 1 2542 5 view .LVU8425
	.loc 1 2546 5 view .LVU8426
.LBB6426:
.LBB5373:
.LBB5347:
.LBB5322:
.LBB5297:
.LBB5272:
.LBB5247:
.LBB5221:
.LBB5181:
.LBB5156:
	.loc 1 2547 9 view .LVU8427
.LBB5130:
.LBI5107:
	.loc 1 2510 27 view .LVU8428
.LBE5130:
.LBE5156:
.LBE5181:
.LBE5221:
.LBE5247:
.LBE5272:
.LBE5297:
.LBE5322:
.LBE5347:
.LBE5373:
.LBE6426:
	.loc 1 2512 5 view .LVU8429
.LBB6427:
.LBB5374:
.LBB5348:
.LBB5323:
.LBB5298:
.LBB5273:
.LBB5248:
.LBB5222:
.LBB5182:
.LBB5157:
.LBB5131:
.LBB5126:
.LBI5108:
	.loc 1 2469 27 view .LVU8430
.LBB5122:
	.loc 1 2471 5 view .LVU8431
	.loc 1 2475 5 view .LVU8432
.LBB5120:
.LBI5110:
	.loc 1 2444 28 view .LVU8433
.LBB5118:
	.loc 1 2446 5 view .LVU8434
.LBB5116:
.LBI5112:
	.loc 1 2438 27 view .LVU8435
.LBB5114:
	.loc 1 2440 5 view .LVU8436
	.loc 1 2440 55 is_stmt 0 view .LVU8437
	movslq	%eax, %rcx
	movq	%rcx, %rdx
	salq	$30, %rdx
	addq	%rcx, %rdx
	movl	%eax, %ecx
	sarl	$31, %ecx
	sarq	$61, %rdx
	subl	%ecx, %edx
	movl	%edx, %ecx
	sall	$31, %ecx
	subl	%edx, %ecx
	subl	%ecx, %eax
.LBE5114:
.LBE5116:
.LBE5118:
.LBE5120:
.LBE5122:
.LBE5126:
.LBE5131:
.LBB5132:
.LBB5133:
.LBB5134:
.LBB5135:
.LBB5136:
.LBB5137:
.LBB5138:
	.loc 1 2440 29 view .LVU8438
	imull	$48271, %eax, %r10d
.LBE5138:
.LBE5137:
.LBE5136:
.LBE5135:
.LBE5134:
.LBE5133:
.LBE5132:
.LBB5149:
.LBB5127:
.LBB5123:
.LBB5121:
.LBB5119:
.LBB5117:
.LBB5115:
	.loc 1 2440 55 view .LVU8439
	movl	%eax, %edx
	.loc 1 2441 5 is_stmt 1 view .LVU8440
.LVL2170:
	.loc 1 2441 5 is_stmt 0 view .LVU8441
.LBE5115:
.LBE5117:
.LBE5119:
.LBE5121:
.LBE5123:
.LBE5127:
.LBE5149:
	.loc 1 2548 9 is_stmt 1 view .LVU8442
.LBB5150:
.LBI5132:
	.loc 1 2510 27 view .LVU8443
.LBE5150:
.LBE5157:
.LBE5182:
.LBE5222:
.LBE5248:
.LBE5273:
.LBE5298:
.LBE5323:
.LBE5348:
.LBE5374:
.LBE6427:
	.loc 1 2512 5 view .LVU8444
.LBB6428:
.LBB5375:
.LBB5349:
.LBB5324:
.LBB5299:
.LBB5274:
.LBB5249:
.LBB5223:
.LBB5183:
.LBB5158:
.LBB5151:
.LBB5146:
.LBI5133:
	.loc 1 2469 27 view .LVU8445
.LBB5143:
	.loc 1 2471 5 view .LVU8446
	.loc 1 2475 5 view .LVU8447
.LBB5142:
.LBI5135:
	.loc 1 2444 28 view .LVU8448
.LBB5141:
	.loc 1 2446 5 view .LVU8449
.LBB5140:
.LBI5137:
	.loc 1 2438 27 view .LVU8450
.LBB5139:
	.loc 1 2440 5 view .LVU8451
	.loc 1 2440 55 is_stmt 0 view .LVU8452
	movslq	%r10d, %rcx
	movq	%rcx, %rax
.LVL2171:
	.loc 1 2440 55 view .LVU8453
	salq	$30, %rax
	addq	%rcx, %rax
	movl	%r10d, %ecx
	sarl	$31, %ecx
	sarq	$61, %rax
	subl	%ecx, %eax
	movl	%eax, %ecx
	sall	$31, %ecx
	subl	%eax, %ecx
	movl	%r10d, %eax
	subl	%ecx, %eax
	.loc 1 2441 5 is_stmt 1 view .LVU8454
.LVL2172:
	.loc 1 2441 5 is_stmt 0 view .LVU8455
.LBE5139:
.LBE5140:
.LBE5141:
.LBE5142:
.LBE5143:
.LBE5146:
.LBE5151:
	.loc 1 2549 9 is_stmt 1 view .LVU8456
.LBB5152:
.LBB5128:
.LBB5124:
	.loc 1 2475 39 is_stmt 0 view .LVU8457
	movl	%edx, %ecx
	imulq	$33554319, %rcx, %rcx
	shrq	$32, %rcx
	subl	%ecx, %edx
.LVL2173:
	.loc 1 2475 39 view .LVU8458
	shrl	%edx
	addl	%ecx, %edx
.LBE5124:
.LBE5128:
.LBE5152:
.LBB5153:
.LBB5147:
.LBB5144:
	movl	%eax, %ecx
.LBE5144:
.LBE5147:
.LBE5153:
.LBB5154:
.LBB5129:
.LBB5125:
	shrl	$24, %edx
.LBE5125:
.LBE5129:
.LBE5154:
.LBB5155:
.LBB5148:
.LBB5145:
	shrl	$25, %ecx
.LVL2174:
	.loc 1 2475 39 view .LVU8459
.LBE5145:
.LBE5148:
.LBE5155:
	.loc 1 2549 20 view .LVU8460
	leal	-128(%rdx,%rcx), %ecx
.LVL2175:
	.loc 1 2549 20 view .LVU8461
.LBE5158:
.LBE5183:
	.loc 1 30921 13 is_stmt 1 view .LVU8462
	.loc 1 30921 18 is_stmt 0 view .LVU8463
	movswl	%si, %edx
	.loc 1 30921 20 view .LVU8464
	addl	%ecx, %edx
	.loc 1 30921 13 view .LVU8465
	cmpl	$32767, %edx
	jle	.L1476
.LVL2176:
	.loc 1 30927 13 is_stmt 1 view .LVU8466
	.loc 1 30928 13 view .LVU8467
	.loc 1 30929 13 view .LVU8468
	.loc 1 30929 23 is_stmt 0 view .LVU8469
	movb	$-1, (%rdi,%r9)
.LBE5223:
	.loc 1 30916 9 is_stmt 1 view .LVU8470
	.loc 1 30916 34 is_stmt 0 view .LVU8471
	addq	$1, %r9
.LVL2177:
	.loc 1 30916 23 is_stmt 1 view .LVU8472
	cmpq	%r9, %r8
	jne	.L1094
	jmp	.L1099
.LVL2178:
.L1476:
.LBB5224:
	.loc 1 30922 17 view .LVU8473
	.loc 1 30922 34 is_stmt 0 view .LVU8474
	leal	(%rsi,%rcx), %edx
.LVL2179:
	.loc 1 30927 13 is_stmt 1 view .LVU8475
	.loc 1 30928 13 view .LVU8476
	.loc 1 30929 13 view .LVU8477
	.loc 1 30927 15 is_stmt 0 view .LVU8478
	sarw	$8, %dx
	.loc 1 30928 30 view .LVU8479
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU8480
	movb	%dl, (%rdi,%r9)
.LBE5224:
	.loc 1 30916 9 is_stmt 1 view .LVU8481
	.loc 1 30916 34 is_stmt 0 view .LVU8482
	addq	$1, %r9
.LVL2180:
	.loc 1 30916 23 is_stmt 1 view .LVU8483
	cmpq	%r9, %r8
	jne	.L1094
	jmp	.L1099
.LVL2181:
.L1303:
	.loc 1 30916 23 is_stmt 0 view .LVU8484
.LBE5249:
.LBE5274:
.LBE5299:
.LBE5324:
.LBE5349:
.LBE5375:
.LBE6428:
.LBB6429:
.LBB4892:
.LBB4875:
.LBB4859:
.LBB4843:
.LBB4827:
.LBB4811:
	.loc 1 31712 16 view .LVU8485
	xorl	%esi, %esi
.LVL2182:
.LBB4795:
	.loc 1 31717 13 view .LVU8486
	movl	$2147483648, %r10d
.LVL2183:
.L1188:
	.loc 1 31713 13 is_stmt 1 view .LVU8487
.LBB4769:
.LBB4701:
.LBB4702:
.LBB4703:
.LBB4704:
.LBB4705:
.LBB4706:
.LBB4707:
.LBB4708:
	.loc 1 2440 29 is_stmt 0 view .LVU8488
	imull	$48271, %eax, %eax
.LBE4708:
.LBE4707:
.LBE4706:
.LBE4705:
.LBE4704:
.LBE4703:
.LBE4702:
.LBE4701:
.LBE4769:
	.loc 1 31713 22 view .LVU8489
	movl	(%rbx,%rsi,4), %r9d
.LVL2184:
	.loc 1 31716 13 is_stmt 1 view .LVU8490
.LBB4770:
	.loc 1 2540 27 view .LVU8491
.LBE4770:
.LBE4795:
.LBE4811:
.LBE4827:
.LBE4843:
.LBE4859:
.LBE4875:
.LBE4892:
.LBE6429:
	.loc 1 2542 5 view .LVU8492
	.loc 1 2546 5 view .LVU8493
.LBB6430:
.LBB4893:
.LBB4876:
.LBB4860:
.LBB4844:
.LBB4828:
.LBB4812:
.LBB4796:
.LBB4771:
.LBB4754:
	.loc 1 2547 9 view .LVU8494
.LBB4727:
.LBI4702:
	.loc 1 2510 27 view .LVU8495
.LBE4727:
.LBE4754:
.LBE4771:
.LBE4796:
.LBE4812:
.LBE4828:
.LBE4844:
.LBE4860:
.LBE4876:
.LBE4893:
.LBE6430:
	.loc 1 2512 5 view .LVU8496
.LBB6431:
.LBB4894:
.LBB4877:
.LBB4861:
.LBB4845:
.LBB4829:
.LBB4813:
.LBB4797:
.LBB4772:
.LBB4755:
.LBB4728:
.LBB4722:
.LBI4703:
	.loc 1 2469 27 view .LVU8497
.LBB4717:
	.loc 1 2471 5 view .LVU8498
	.loc 1 2475 5 view .LVU8499
.LBB4715:
.LBI4705:
	.loc 1 2444 28 view .LVU8500
.LBB4713:
	.loc 1 2446 5 view .LVU8501
.LBB4711:
.LBI4707:
	.loc 1 2438 27 view .LVU8502
.LBB4709:
	.loc 1 2440 5 view .LVU8503
	.loc 1 2440 55 is_stmt 0 view .LVU8504
	movslq	%eax, %rcx
	movq	%rcx, %rdx
	salq	$30, %rdx
	addq	%rcx, %rdx
	movl	%eax, %ecx
	sarl	$31, %ecx
	sarq	$61, %rdx
	subl	%ecx, %edx
	movl	%edx, %ecx
	sall	$31, %ecx
	subl	%edx, %ecx
	subl	%ecx, %eax
.LBE4709:
.LBE4711:
.LBE4713:
.LBE4715:
.LBE4717:
.LBE4722:
.LBE4728:
.LBB4729:
.LBB4730:
.LBB4731:
.LBB4732:
.LBB4733:
.LBB4734:
.LBB4735:
	.loc 1 2440 29 view .LVU8505
	imull	$48271, %eax, %r11d
.LBE4735:
.LBE4734:
.LBE4733:
.LBE4732:
.LBE4731:
.LBE4730:
.LBE4729:
.LBB4746:
.LBB4723:
.LBB4718:
.LBB4716:
.LBB4714:
.LBB4712:
.LBB4710:
	.loc 1 2440 55 view .LVU8506
	movl	%eax, %edx
	.loc 1 2441 5 is_stmt 1 view .LVU8507
.LVL2185:
	.loc 1 2441 5 is_stmt 0 view .LVU8508
.LBE4710:
.LBE4712:
.LBE4714:
.LBE4716:
.LBE4718:
.LBE4723:
.LBE4746:
	.loc 1 2548 9 is_stmt 1 view .LVU8509
.LBB4747:
.LBI4729:
	.loc 1 2510 27 view .LVU8510
.LBE4747:
.LBE4755:
.LBE4772:
.LBE4797:
.LBE4813:
.LBE4829:
.LBE4845:
.LBE4861:
.LBE4877:
.LBE4894:
.LBE6431:
	.loc 1 2512 5 view .LVU8511
.LBB6432:
.LBB4895:
.LBB4878:
.LBB4862:
.LBB4846:
.LBB4830:
.LBB4814:
.LBB4798:
.LBB4773:
.LBB4756:
.LBB4748:
.LBB4743:
.LBI4730:
	.loc 1 2469 27 view .LVU8512
.LBB4740:
	.loc 1 2471 5 view .LVU8513
	.loc 1 2475 5 view .LVU8514
.LBB4739:
.LBI4732:
	.loc 1 2444 28 view .LVU8515
.LBB4738:
	.loc 1 2446 5 view .LVU8516
.LBB4737:
.LBI4734:
	.loc 1 2438 27 view .LVU8517
.LBB4736:
	.loc 1 2440 5 view .LVU8518
	.loc 1 2440 55 is_stmt 0 view .LVU8519
	movslq	%r11d, %rcx
	movq	%rcx, %rax
.LVL2186:
	.loc 1 2440 55 view .LVU8520
	salq	$30, %rax
	addq	%rcx, %rax
	movl	%r11d, %ecx
	sarl	$31, %ecx
	sarq	$61, %rax
	subl	%ecx, %eax
	movl	%eax, %ecx
	sall	$31, %ecx
	subl	%eax, %ecx
	movl	%r11d, %eax
	subl	%ecx, %eax
	.loc 1 2441 5 is_stmt 1 view .LVU8521
.LVL2187:
	.loc 1 2441 5 is_stmt 0 view .LVU8522
.LBE4736:
.LBE4737:
.LBE4738:
.LBE4739:
.LBE4740:
.LBE4743:
.LBE4748:
	.loc 1 2549 9 is_stmt 1 view .LVU8523
.LBB4749:
.LBB4724:
.LBB4719:
	.loc 1 2475 39 is_stmt 0 view .LVU8524
	movl	%edx, %ecx
	leaq	(%rcx,%rcx,2), %rcx
	movq	%rcx, %r11
	salq	$15, %r11
	addq	%r11, %rcx
.LBE4719:
.LBE4724:
.LBE4749:
.LBE4756:
.LBE4773:
	.loc 1 31717 17 view .LVU8525
	movslq	%r9d, %r11
.LBB4774:
.LBB4757:
.LBB4750:
.LBB4725:
.LBB4720:
	.loc 1 2475 39 view .LVU8526
	shrq	$32, %rcx
	subl	%ecx, %edx
.LVL2188:
	.loc 1 2475 39 view .LVU8527
	shrl	%edx
	addl	%ecx, %edx
.LBE4720:
.LBE4725:
.LBE4750:
.LBB4751:
.LBB4744:
.LBB4741:
	movl	%eax, %ecx
.LBE4741:
.LBE4744:
.LBE4751:
.LBB4752:
.LBB4726:
.LBB4721:
	shrl	$16, %edx
.LBE4721:
.LBE4726:
.LBE4752:
.LBB4753:
.LBB4745:
.LBB4742:
	shrl	$17, %ecx
.LVL2189:
	.loc 1 2475 39 view .LVU8528
.LBE4742:
.LBE4745:
.LBE4753:
	.loc 1 2549 20 view .LVU8529
	leal	-32768(%rdx,%rcx), %ecx
.LVL2190:
	.loc 1 2549 20 view .LVU8530
.LBE4757:
.LBE4774:
	.loc 1 31717 13 is_stmt 1 view .LVU8531
	.loc 1 31717 31 is_stmt 0 view .LVU8532
	movslq	%ecx, %rdx
	.loc 1 31717 29 view .LVU8533
	addq	%r11, %rdx
	.loc 1 31717 13 view .LVU8534
	cmpq	%r10, %rdx
	jl	.L1477
.LVL2191:
	.loc 1 31723 13 is_stmt 1 view .LVU8535
	.loc 1 31724 13 view .LVU8536
	.loc 1 31724 24 is_stmt 0 view .LVU8537
	movl	$32767, %ecx
.LVL2192:
	.loc 1 31724 24 view .LVU8538
	movw	%cx, (%rdi,%rsi,2)
.LBE4798:
	.loc 1 31712 9 is_stmt 1 view .LVU8539
	.loc 1 31712 34 is_stmt 0 view .LVU8540
	addq	$1, %rsi
.LVL2193:
	.loc 1 31712 23 is_stmt 1 view .LVU8541
	cmpq	%rsi, %r8
	jne	.L1188
	jmp	.L1192
.LVL2194:
.L1477:
.LBB4799:
	.loc 1 31718 17 view .LVU8542
	.loc 1 31723 13 view .LVU8543
	.loc 1 31724 13 view .LVU8544
	.loc 1 31718 19 is_stmt 0 view .LVU8545
	addl	%ecx, %r9d
	.loc 1 31723 15 view .LVU8546
	sarl	$16, %r9d
	.loc 1 31724 24 view .LVU8547
	movw	%r9w, (%rdi,%rsi,2)
.LBE4799:
	.loc 1 31712 9 is_stmt 1 view .LVU8548
	.loc 1 31712 34 is_stmt 0 view .LVU8549
	addq	$1, %rsi
.LVL2195:
	.loc 1 31712 23 is_stmt 1 view .LVU8550
	cmpq	%rsi, %r8
	jne	.L1188
	jmp	.L1192
.LVL2196:
.L1131:
	.loc 1 31712 23 is_stmt 0 view .LVU8551
	leaq	(%r8,%r8,2), %rdx
.LVL2197:
	.loc 1 31712 23 view .LVU8552
.LBE4814:
.LBE4830:
.LBE4846:
.LBE4862:
.LBE4878:
.LBE4895:
.LBE6432:
.LBB6433:
.LBB5925:
.LBB5916:
.LBB5908:
.LBB5900:
.LBB5892:
.LBB5884:
.LBB5873:
	.loc 1 31266 13 view .LVU8553
	movl	$2147483648, %esi
.LVL2198:
	.loc 1 31266 13 view .LVU8554
	addq	%rbx, %rdx
.LVL2199:
.L1133:
	.loc 1 31262 13 is_stmt 1 view .LVU8555
	.loc 1 31262 38 is_stmt 0 view .LVU8556
	movzbl	(%rbx), %r8d
	.loc 1 31262 75 view .LVU8557
	movzbl	1(%rbx), %eax
.LBB5859:
.LBB5806:
.LBB5807:
.LBB5808:
.LBB5809:
.LBB5810:
.LBB5811:
.LBB5812:
.LBB5813:
	.loc 1 2440 29 view .LVU8558
	imull	$48271, %ecx, %ecx
.LBE5813:
.LBE5812:
.LBE5811:
.LBE5810:
.LBE5809:
.LBE5808:
.LBE5807:
.LBE5806:
.LBE5859:
	.loc 1 31262 103 view .LVU8559
	sall	$16, %eax
	.loc 1 31262 66 view .LVU8560
	sall	$8, %r8d
	.loc 1 31262 110 view .LVU8561
	orl	%eax, %r8d
	.loc 1 31262 113 view .LVU8562
	movzbl	2(%rbx), %eax
.LBB5860:
.LBB5850:
.LBB5828:
.LBB5825:
.LBB5822:
.LBB5820:
.LBB5818:
.LBB5816:
.LBB5814:
	.loc 1 2440 55 view .LVU8563
	movslq	%ecx, %r9
.LBE5814:
.LBE5816:
.LBE5818:
.LBE5820:
.LBE5822:
.LBE5825:
.LBE5828:
.LBE5850:
.LBE5860:
	.loc 1 31262 142 view .LVU8564
	sall	$24, %eax
	.loc 1 31262 110 view .LVU8565
	orl	%eax, %r8d
.LVL2200:
	.loc 1 31265 13 is_stmt 1 view .LVU8566
.LBB5861:
	.loc 1 2540 27 view .LVU8567
.LBE5861:
.LBE5873:
.LBE5884:
.LBE5892:
.LBE5900:
.LBE5908:
.LBE5916:
.LBE5925:
.LBE6433:
	.loc 1 2542 5 view .LVU8568
	.loc 1 2546 5 view .LVU8569
.LBB6434:
.LBB5926:
.LBB5917:
.LBB5909:
.LBB5901:
.LBB5893:
.LBB5885:
.LBB5874:
.LBB5862:
.LBB5851:
	.loc 1 2547 9 view .LVU8570
.LBB5829:
.LBI5807:
	.loc 1 2510 27 view .LVU8571
.LBE5829:
.LBE5851:
.LBE5862:
.LBE5874:
.LBE5885:
.LBE5893:
.LBE5901:
.LBE5909:
.LBE5917:
.LBE5926:
.LBE6434:
	.loc 1 2512 5 view .LVU8572
.LBB6435:
.LBB5927:
.LBB5918:
.LBB5910:
.LBB5902:
.LBB5894:
.LBB5886:
.LBB5875:
.LBB5863:
.LBB5852:
.LBB5830:
.LBB5826:
.LBI5808:
	.loc 1 2469 27 view .LVU8573
.LBB5823:
	.loc 1 2471 5 view .LVU8574
	.loc 1 2475 5 view .LVU8575
.LBB5821:
.LBI5810:
	.loc 1 2444 28 view .LVU8576
.LBB5819:
	.loc 1 2446 5 view .LVU8577
.LBB5817:
.LBI5812:
	.loc 1 2438 27 view .LVU8578
.LBB5815:
	.loc 1 2440 5 view .LVU8579
	.loc 1 2440 55 is_stmt 0 view .LVU8580
	movq	%r9, %rax
	salq	$30, %rax
	addq	%r9, %rax
	movl	%ecx, %r9d
	sarl	$31, %r9d
	sarq	$61, %rax
	subl	%r9d, %eax
	movl	%eax, %r9d
	sall	$31, %r9d
	subl	%eax, %r9d
	movl	%ecx, %eax
	subl	%r9d, %eax
	.loc 1 2441 5 is_stmt 1 view .LVU8581
.LVL2201:
	.loc 1 2441 5 is_stmt 0 view .LVU8582
.LBE5815:
.LBE5817:
.LBE5819:
.LBE5821:
.LBE5823:
.LBE5826:
.LBE5830:
	.loc 1 2548 9 is_stmt 1 view .LVU8583
.LBB5831:
.LBI5831:
	.loc 1 2510 27 view .LVU8584
.LBE5831:
.LBE5852:
.LBE5863:
.LBE5875:
.LBE5886:
.LBE5894:
.LBE5902:
.LBE5910:
.LBE5918:
.LBE5927:
.LBE6435:
	.loc 1 2512 5 view .LVU8585
.LBB6436:
.LBB5928:
.LBB5919:
.LBB5911:
.LBB5903:
.LBB5895:
.LBB5887:
.LBB5876:
.LBB5864:
.LBB5853:
.LBB5846:
.LBB5832:
.LBI5832:
	.loc 1 2469 27 view .LVU8586
.LBB5833:
	.loc 1 2471 5 view .LVU8587
	.loc 1 2475 5 view .LVU8588
.LBB5834:
.LBI5834:
	.loc 1 2444 28 view .LVU8589
.LBB5835:
	.loc 1 2446 5 view .LVU8590
.LBB5836:
.LBI5836:
	.loc 1 2438 27 view .LVU8591
.LBB5837:
	.loc 1 2440 5 view .LVU8592
	.loc 1 2440 29 is_stmt 0 view .LVU8593
	imull	$48271, %eax, %r10d
.LBE5837:
.LBE5836:
.LBE5835:
.LBE5834:
.LBE5833:
.LBE5832:
.LBE5846:
.LBB5847:
.LBB5827:
.LBB5824:
	.loc 1 2475 39 view .LVU8594
	shrl	$9, %eax
.LVL2202:
	.loc 1 2475 39 view .LVU8595
.LBE5824:
.LBE5827:
.LBE5847:
.LBB5848:
.LBB5844:
.LBB5842:
.LBB5841:
.LBB5840:
.LBB5839:
.LBB5838:
	.loc 1 2440 55 view .LVU8596
	movslq	%r10d, %r9
.LVL2203:
	.loc 1 2440 55 view .LVU8597
	movq	%r9, %rcx
.LVL2204:
	.loc 1 2440 55 view .LVU8598
	salq	$30, %rcx
	addq	%r9, %rcx
	movl	%r10d, %r9d
	sarl	$31, %r9d
	sarq	$61, %rcx
	subl	%r9d, %ecx
	movl	%ecx, %r9d
	sall	$31, %r9d
	subl	%ecx, %r9d
	movl	%r10d, %ecx
	subl	%r9d, %ecx
	.loc 1 2441 5 is_stmt 1 view .LVU8599
.LVL2205:
	.loc 1 2441 5 is_stmt 0 view .LVU8600
.LBE5838:
.LBE5839:
.LBE5840:
.LBE5841:
.LBE5842:
.LBE5844:
.LBE5848:
	.loc 1 2549 9 is_stmt 1 view .LVU8601
.LBB5849:
.LBB5845:
.LBB5843:
	.loc 1 2475 39 is_stmt 0 view .LVU8602
	movl	%ecx, %r9d
	shrl	$9, %r9d
.LVL2206:
	.loc 1 2475 39 view .LVU8603
.LBE5843:
.LBE5845:
.LBE5849:
	.loc 1 2549 20 view .LVU8604
	leal	-8388608(%rax,%r9), %r9d
.LVL2207:
	.loc 1 2549 20 view .LVU8605
.LBE5853:
.LBE5864:
	.loc 1 31266 13 is_stmt 1 view .LVU8606
	.loc 1 31266 17 is_stmt 0 view .LVU8607
	movslq	%r8d, %rax
	.loc 1 31266 31 view .LVU8608
	movslq	%r9d, %r10
	.loc 1 31266 29 view .LVU8609
	addq	%r10, %rax
	.loc 1 31266 13 view .LVU8610
	cmpq	%rsi, %rax
	jl	.L1478
.LVL2208:
	.loc 1 31272 13 is_stmt 1 view .LVU8611
	.loc 1 31273 13 view .LVU8612
	.loc 1 31274 13 view .LVU8613
.LBE5876:
	.loc 1 31261 23 is_stmt 0 view .LVU8614
	addq	$3, %rbx
.LBB5877:
	.loc 1 31274 23 view .LVU8615
	movb	$-1, (%rdi)
.LBE5877:
	.loc 1 31261 9 is_stmt 1 view .LVU8616
.LVL2209:
	.loc 1 31261 23 view .LVU8617
	addq	$1, %rdi
.LVL2210:
	.loc 1 31261 23 is_stmt 0 view .LVU8618
	cmpq	%rbx, %rdx
	jne	.L1133
	jmp	.L1134
.LVL2211:
.L1478:
.LBB5878:
	.loc 1 31267 17 is_stmt 1 view .LVU8619
	.loc 1 31272 13 view .LVU8620
	.loc 1 31273 13 view .LVU8621
	.loc 1 31274 13 view .LVU8622
	.loc 1 31267 19 is_stmt 0 view .LVU8623
	leal	(%r8,%r9), %eax
.LBE5878:
	.loc 1 31261 23 view .LVU8624
	addq	$3, %rbx
	addq	$1, %rdi
.LVL2212:
.LBB5879:
	.loc 1 31272 15 view .LVU8625
	sarl	$24, %eax
	.loc 1 31273 15 view .LVU8626
	subl	$-128, %eax
	.loc 1 31274 23 view .LVU8627
	movb	%al, -1(%rdi)
.LBE5879:
	.loc 1 31261 9 is_stmt 1 view .LVU8628
.LVL2213:
	.loc 1 31261 23 view .LVU8629
	cmpq	%rdx, %rbx
	jne	.L1133
	jmp	.L1134
.LVL2214:
.L1300:
	.loc 1 31261 23 is_stmt 0 view .LVU8630
.LBE5887:
.LBE5895:
.LBE5903:
.LBE5911:
.LBE5919:
.LBE5928:
.LBE6436:
.LBB6437:
.LBB6276:
.LBB6250:
.LBB6225:
.LBB6200:
.LBB6175:
.LBB6150:
	.loc 1 31631 16 view .LVU8631
	xorl	%eax, %eax
.LVL2215:
.L1171:
.LBB6125:
	.loc 1 31632 13 is_stmt 1 view .LVU8632
	.loc 1 31635 13 view .LVU8633
.LBB6084:
	.loc 1 2540 27 view .LVU8634
.LBE6084:
.LBE6125:
.LBE6150:
.LBE6175:
.LBE6200:
.LBE6225:
.LBE6250:
.LBE6276:
.LBE6437:
	.loc 1 2542 5 view .LVU8635
	.loc 1 2546 5 view .LVU8636
.LBB6438:
.LBB6277:
.LBB6251:
.LBB6226:
.LBB6201:
.LBB6176:
.LBB6151:
.LBB6126:
	.loc 1 31637 17 view .LVU8637
	.loc 1 31642 13 view .LVU8638
	.loc 1 31643 13 view .LVU8639
	.loc 1 31644 13 view .LVU8640
	.loc 1 31642 15 is_stmt 0 view .LVU8641
	movsbl	3(%rbx,%rax,4), %edx
	.loc 1 31643 15 view .LVU8642
	subl	$-128, %edx
	.loc 1 31644 23 view .LVU8643
	movb	%dl, (%rdi,%rax)
.LBE6126:
	.loc 1 31631 9 is_stmt 1 view .LVU8644
	.loc 1 31631 34 is_stmt 0 view .LVU8645
	addq	$1, %rax
.LVL2216:
	.loc 1 31631 23 is_stmt 1 view .LVU8646
	cmpq	%rax, %r8
	jne	.L1171
	jmp	.L1050
.LVL2217:
.L1293:
	.loc 1 31631 23 is_stmt 0 view .LVU8647
.LBE6151:
.LBE6176:
.LBE6201:
.LBE6226:
.LBE6251:
.LBE6277:
.LBE6438:
.LBB6439:
.LBB5376:
.LBB5350:
.LBB5325:
.LBB5300:
.LBB5275:
.LBB5250:
	.loc 1 30916 16 view .LVU8648
	xorl	%eax, %eax
.LVL2218:
.L1095:
.LBB5225:
	.loc 1 30917 13 is_stmt 1 view .LVU8649
	.loc 1 30920 13 view .LVU8650
.LBB5184:
	.loc 1 2540 27 view .LVU8651
.LBE5184:
.LBE5225:
.LBE5250:
.LBE5275:
.LBE5300:
.LBE5325:
.LBE5350:
.LBE5376:
.LBE6439:
	.loc 1 2542 5 view .LVU8652
	.loc 1 2546 5 view .LVU8653
.LBB6440:
.LBB5377:
.LBB5351:
.LBB5326:
.LBB5301:
.LBB5276:
.LBB5251:
.LBB5226:
	.loc 1 30922 17 view .LVU8654
	.loc 1 30927 13 view .LVU8655
	.loc 1 30928 13 view .LVU8656
	.loc 1 30929 13 view .LVU8657
	.loc 1 30927 15 is_stmt 0 view .LVU8658
	movsbw	1(%rbx,%rax,2), %dx
	.loc 1 30928 30 view .LVU8659
	subw	$-128, %dx
	.loc 1 30929 23 view .LVU8660
	movb	%dl, (%rdi,%rax)
.LBE5226:
	.loc 1 30916 9 is_stmt 1 view .LVU8661
	.loc 1 30916 34 is_stmt 0 view .LVU8662
	addq	$1, %rax
.LVL2219:
	.loc 1 30916 23 is_stmt 1 view .LVU8663
	cmpq	%rax, %r8
	jne	.L1095
	jmp	.L1050
.LVL2220:
.L1301:
	.loc 1 30916 23 is_stmt 0 view .LVU8664
.LBE5251:
.LBE5276:
.LBE5301:
.LBE5326:
.LBE5351:
.LBE5377:
.LBE6440:
.LBB6441:
.LBB4896:
.LBB4673:
.LBB4671:
.LBB4669:
.LBB4667:
.LBB4666:
	.loc 1 31705 16 view .LVU8665
	xorl	%eax, %eax
	jmp	.L1183
.LVL2221:
.L1296:
	.loc 1 31705 16 view .LVU8666
.LBE4666:
.LBE4667:
.LBE4669:
.LBE4671:
.LBE4673:
.LBE4896:
.LBE6441:
.LBB6442:
.LBB5929:
.LBB5770:
.LBB5768:
.LBB5766:
.LBB5764:
	.loc 1 31256 23 view .LVU8667
	movq	%r8, %rsi
	.loc 1 31256 16 view .LVU8668
	xorl	%edx, %edx
	jmp	.L1122
.LVL2222:
.L1304:
	.loc 1 31256 16 view .LVU8669
.LBE5764:
.LBE5766:
.LBE5768:
.LBE5770:
.LBE5929:
.LBE6442:
.LBB6443:
.LBB4897:
.LBB4879:
.LBB4863:
.LBB4847:
.LBB4831:
.LBB4815:
	.loc 1 31712 16 view .LVU8670
	xorl	%eax, %eax
	jmp	.L1189
.LBE4815:
.LBE4831:
.LBE4847:
.LBE4863:
.LBE4879:
.LBE4897:
.LBE6443:
	.cfi_endproc
.LFE146:
	.size	ma_pcm_convert, .-ma_pcm_convert
	.p2align 4
	.globl	_ZL22ma_lpf_get_heap_layoutPK13ma_lpf_configP18ma_lpf_heap_layout.lto_priv.0
	.hidden	_ZL22ma_lpf_get_heap_layoutPK13ma_lpf_configP18ma_lpf_heap_layout.lto_priv.0
	.type	_ZL22ma_lpf_get_heap_layoutPK13ma_lpf_configP18ma_lpf_heap_layout.lto_priv.0, @function
_ZL22ma_lpf_get_heap_layoutPK13ma_lpf_configP18ma_lpf_heap_layout.lto_priv.0:
.LVL2223:
.LFB159:
	.loc 1 33710 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 33710 1 is_stmt 0 view .LVU8672
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
1:	call	mcount
	.loc 1 33710 1 view .LVU8673
	.loc 1 33711 5 is_stmt 1 view .LVU8674
	.loc 1 33712 5 view .LVU8675
	.loc 1 33713 5 view .LVU8676
	.loc 1 33714 5 view .LVU8677
	.loc 1 33715 5 view .LVU8678
	.loc 1 33717 5 view .LVU8679
	.loc 1 33719 5 view .LVU8680
.LVL2224:
.LBB6482:
.LBI6482:
	.loc 1 776 23 view .LVU8681
.LBB6483:
	.loc 1 781 5 view .LVU8682
	.loc 1 782 9 view .LVU8683
	.loc 1 782 15 is_stmt 0 view .LVU8684
	pxor	%xmm0, %xmm0
	movq	$0, 16(%rsi)
.LVL2225:
	.loc 1 782 15 view .LVU8685
.LBE6483:
.LBE6482:
	.loc 1 33721 5 is_stmt 1 view .LVU8686
	.loc 1 33725 5 view .LVU8687
.LBB6485:
.LBB6484:
	.loc 1 782 15 is_stmt 0 view .LVU8688
	movups	%xmm0, (%rsi)
.LBE6484:
.LBE6485:
	.loc 1 33725 18 view .LVU8689
	movl	4(%rdi), %edx
	.loc 1 33725 5 view .LVU8690
	testl	%edx, %edx
	je	.L1485
	.loc 1 33729 5 is_stmt 1 view .LVU8691
	.loc 1 33729 18 is_stmt 0 view .LVU8692
	movl	24(%rdi), %ecx
	.loc 1 33729 5 view .LVU8693
	cmpl	$8, %ecx
	ja	.L1485
	.loc 1 33733 5 is_stmt 1 view .LVU8694
.LVL2226:
.LBB6486:
.LBI6486:
	.loc 1 33700 13 view .LVU8695
.LBB6487:
	.loc 1 33702 5 view .LVU8696
	.loc 1 33703 5 view .LVU8697
	.loc 1 33705 5 view .LVU8698
	.loc 1 33706 5 view .LVU8699
	.loc 1 33706 5 is_stmt 0 view .LVU8700
.LBE6487:
.LBE6486:
	.loc 1 33735 5 is_stmt 1 view .LVU8701
	.loc 1 33738 5 view .LVU8702
	.loc 1 33739 5 view .LVU8703
.LBB6488:
	.loc 1 33739 27 view .LVU8704
	testb	$1, %cl
	je	.L1486
.LBB6489:
	.loc 1 33740 9 view .LVU8705
	.loc 1 33741 9 view .LVU8706
.LVL2227:
.LBB6490:
.LBI6490:
	.loc 1 33232 23 view .LVU8707
.LBB6491:
	.loc 1 33234 5 view .LVU8708
	.loc 1 33236 5 view .LVU8709
	.loc 1 33236 5 is_stmt 0 view .LVU8710
.LBE6491:
.LBE6490:
.LBE6489:
.LBE6488:
	.loc 1 781 5 is_stmt 1 view .LVU8711
	.loc 1 782 9 view .LVU8712
.LBB6508:
.LBB6506:
.LBB6493:
.LBB6492:
	.loc 1 33237 5 view .LVU8713
	.loc 1 33238 5 view .LVU8714
	.loc 1 33239 5 view .LVU8715
	.loc 1 33240 5 view .LVU8716
	.loc 1 33241 5 view .LVU8717
	.loc 1 33243 5 view .LVU8718
	.loc 1 33243 5 is_stmt 0 view .LVU8719
.LBE6492:
.LBE6493:
	.loc 1 33743 9 is_stmt 1 view .LVU8720
.LBB6494:
.LBI6494:
	.loc 1 33298 18 view .LVU8721
.LBB6495:
	.loc 1 33300 5 view .LVU8722
	.loc 1 33301 5 view .LVU8723
	.loc 1 33303 5 view .LVU8724
	.loc 1 33307 5 view .LVU8725
.LBB6496:
.LBI6496:
	.loc 1 33272 18 view .LVU8726
.LBB6497:
	.loc 1 33274 5 view .LVU8727
	.loc 1 33276 5 view .LVU8728
	.loc 1 33276 5 is_stmt 0 view .LVU8729
.LBE6497:
.LBE6496:
.LBE6495:
.LBE6494:
.LBE6506:
.LBE6508:
	.loc 1 781 5 is_stmt 1 view .LVU8730
	.loc 1 782 9 view .LVU8731
.LBB6509:
.LBB6507:
.LBB6504:
.LBB6502:
.LBB6500:
.LBB6498:
	.loc 1 33278 5 view .LVU8732
	.loc 1 33282 5 view .LVU8733
	.loc 1 33286 5 view .LVU8734
	.loc 1 33289 5 view .LVU8735
	.loc 1 33290 5 view .LVU8736
	.loc 1 33293 5 view .LVU8737
	.loc 1 33295 5 view .LVU8738
	.loc 1 33295 5 is_stmt 0 view .LVU8739
.LBE6498:
.LBE6500:
	.loc 1 33308 5 is_stmt 1 view .LVU8740
	.loc 1 33312 5 view .LVU8741
	.loc 1 33314 5 view .LVU8742
	.loc 1 33314 5 is_stmt 0 view .LVU8743
.LBE6502:
.LBE6504:
	.loc 1 33744 9 is_stmt 1 view .LVU8744
	.loc 1 33748 9 view .LVU8745
.LBB6505:
.LBB6503:
.LBB6501:
.LBB6499:
	.loc 1 33290 74 is_stmt 0 view .LVU8746
	movl	%edx, %eax
	.loc 1 33293 32 view .LVU8747
	leaq	7(,%rax,4), %rax
	andq	$-8, %rax
.LBE6499:
.LBE6501:
.LBE6503:
.LBE6505:
	.loc 1 33748 34 view .LVU8748
	addq	$40, %rax
	movq	%rax, (%rsi)
	.loc 1 33748 34 view .LVU8749
.LBE6507:
	.loc 1 33739 5 is_stmt 1 view .LVU8750
.LVL2228:
	.loc 1 33739 27 view .LVU8751
.L1481:
	.loc 1 33739 27 is_stmt 0 view .LVU8752
.LBE6509:
	.loc 1 33752 5 is_stmt 1 view .LVU8753
.LBB6510:
	.loc 1 33753 27 is_stmt 0 view .LVU8754
	shrl	%ecx
.LVL2229:
	.loc 1 33753 27 view .LVU8755
.LBE6510:
	.loc 1 33752 29 view .LVU8756
	movq	%rax, 16(%rsi)
	.loc 1 33753 5 is_stmt 1 view .LVU8757
.LVL2230:
.LBB6574:
	.loc 1 33753 27 view .LVU8758
	je	.L1482
.LBB6511:
	.loc 1 33754 9 view .LVU8759
	.loc 1 33755 9 view .LVU8760
.LVL2231:
.LBB6512:
.LBI6512:
	.loc 1 33246 23 view .LVU8761
.LBB6513:
	.loc 1 33248 5 view .LVU8762
	.loc 1 33250 5 view .LVU8763
	.loc 1 33250 5 is_stmt 0 view .LVU8764
.LBE6513:
.LBE6512:
.LBE6511:
.LBE6574:
	.loc 1 781 5 is_stmt 1 view .LVU8765
	.loc 1 782 9 view .LVU8766
.LBB6575:
.LBB6564:
.LBB6517:
.LBB6514:
	.loc 1 33251 5 view .LVU8767
	.loc 1 33252 5 view .LVU8768
	.loc 1 33253 5 view .LVU8769
	.loc 1 33254 5 view .LVU8770
	.loc 1 33255 5 view .LVU8771
	.loc 1 33258 5 view .LVU8772
	.loc 1 33262 5 view .LVU8773
	.loc 1 33262 5 is_stmt 0 view .LVU8774
.LBE6514:
.LBE6517:
	.loc 1 33757 9 is_stmt 1 view .LVU8775
.LBB6518:
.LBI6518:
	.loc 1 33549 18 view .LVU8776
.LBB6519:
	.loc 1 33551 5 view .LVU8777
	.loc 1 33552 5 view .LVU8778
.LBB6520:
.LBI6520:
	.loc 1 33519 35 view .LVU8779
.LBB6521:
	.loc 1 33521 5 view .LVU8780
	.loc 1 33522 5 view .LVU8781
	.loc 1 33523 5 view .LVU8782
	.loc 1 33524 5 view .LVU8783
	.loc 1 33525 5 view .LVU8784
	.loc 1 33526 5 view .LVU8785
	.loc 1 33528 5 view .LVU8786
	.loc 1 33530 5 view .LVU8787
	.loc 1 33531 5 view .LVU8788
	.loc 1 33532 5 view .LVU8789
	.loc 1 33532 5 is_stmt 0 view .LVU8790
.LBE6521:
.LBE6520:
.LBE6519:
.LBE6518:
.LBE6564:
.LBE6575:
	.loc 1 831 5 is_stmt 1 view .LVU8791
.LBB6576:
.LBB6565:
.LBB6555:
.LBB6548:
.LBB6527:
.LBB6522:
	.loc 1 33533 5 view .LVU8792
	.loc 1 33533 5 is_stmt 0 view .LVU8793
.LBE6522:
.LBE6527:
.LBE6548:
.LBE6555:
.LBE6565:
.LBE6576:
	.loc 1 866 5 is_stmt 1 view .LVU8794
	.loc 1 831 5 view .LVU8795
.LBB6577:
.LBB6566:
.LBB6556:
.LBB6549:
.LBB6528:
.LBB6523:
	.loc 1 33534 5 view .LVU8796
	.loc 1 33536 5 view .LVU8797
	.loc 1 33537 5 view .LVU8798
	.loc 1 33538 5 view .LVU8799
	.loc 1 33539 5 view .LVU8800
	.loc 1 33540 5 view .LVU8801
	.loc 1 33541 5 view .LVU8802
	.loc 1 33543 5 view .LVU8803
	.loc 1 33544 5 view .LVU8804
	.loc 1 33546 5 view .LVU8805
	.loc 1 33546 5 is_stmt 0 view .LVU8806
.LBE6523:
.LBE6528:
	.loc 1 33554 5 is_stmt 1 view .LVU8807
.LBB6529:
.LBI6529:
	.loc 1 32966 18 view .LVU8808
.LBB6530:
	.loc 1 32968 5 view .LVU8809
	.loc 1 32969 5 view .LVU8810
	.loc 1 32971 5 view .LVU8811
	.loc 1 32975 5 view .LVU8812
	.loc 1 32977 5 view .LVU8813
.LBB6531:
.LBI6531:
	.loc 1 32936 18 view .LVU8814
.LBB6532:
	.loc 1 32938 5 view .LVU8815
	.loc 1 32940 5 view .LVU8816
	.loc 1 32940 5 is_stmt 0 view .LVU8817
.LBE6532:
.LBE6531:
.LBE6530:
.LBE6529:
.LBE6549:
.LBE6556:
.LBE6566:
.LBE6577:
	.loc 1 781 5 is_stmt 1 view .LVU8818
	.loc 1 782 9 view .LVU8819
.LBB6578:
.LBB6567:
.LBB6557:
.LBB6550:
.LBB6542:
.LBB6539:
.LBB6536:
.LBB6533:
	.loc 1 32942 5 view .LVU8820
	.loc 1 32946 5 view .LVU8821
	.loc 1 32950 5 view .LVU8822
	.loc 1 32953 5 view .LVU8823
	.loc 1 32954 5 view .LVU8824
	.loc 1 32957 5 view .LVU8825
	.loc 1 32958 5 view .LVU8826
	.loc 1 32961 5 view .LVU8827
	.loc 1 32963 5 view .LVU8828
	.loc 1 32963 5 is_stmt 0 view .LVU8829
.LBE6533:
.LBE6536:
	.loc 1 32978 5 is_stmt 1 view .LVU8830
	.loc 1 32982 5 view .LVU8831
	.loc 1 32984 5 view .LVU8832
	.loc 1 32984 5 is_stmt 0 view .LVU8833
.LBE6539:
.LBE6542:
.LBE6550:
.LBE6557:
	.loc 1 33758 9 is_stmt 1 view .LVU8834
	.loc 1 33762 9 view .LVU8835
	leaq	64(,%rdx,8), %rdi
.LVL2232:
	.loc 1 33762 34 is_stmt 0 view .LVU8836
	leaq	(%rax,%rdi), %rdx
	movq	%rdx, (%rsi)
	.loc 1 33762 34 view .LVU8837
.LBE6567:
	.loc 1 33753 5 is_stmt 1 view .LVU8838
.LVL2233:
	.loc 1 33753 27 view .LVU8839
	cmpl	$1, %ecx
	je	.L1483
.LBB6568:
	.loc 1 33754 9 view .LVU8840
	.loc 1 33755 9 view .LVU8841
.LVL2234:
.LBB6558:
	.loc 1 33246 23 view .LVU8842
.LBB6515:
	.loc 1 33248 5 view .LVU8843
	.loc 1 33250 5 view .LVU8844
	.loc 1 33250 5 is_stmt 0 view .LVU8845
.LBE6515:
.LBE6558:
.LBE6568:
.LBE6578:
	.loc 1 781 5 is_stmt 1 view .LVU8846
	.loc 1 782 9 view .LVU8847
.LBB6579:
.LBB6569:
.LBB6559:
.LBB6516:
	.loc 1 33251 5 view .LVU8848
	.loc 1 33252 5 view .LVU8849
	.loc 1 33253 5 view .LVU8850
	.loc 1 33254 5 view .LVU8851
	.loc 1 33255 5 view .LVU8852
	.loc 1 33258 5 view .LVU8853
	.loc 1 33262 5 view .LVU8854
	.loc 1 33262 5 is_stmt 0 view .LVU8855
.LBE6516:
.LBE6559:
	.loc 1 33757 9 is_stmt 1 view .LVU8856
.LBB6560:
	.loc 1 33549 18 view .LVU8857
.LBB6551:
	.loc 1 33551 5 view .LVU8858
	.loc 1 33552 5 view .LVU8859
.LBB6543:
	.loc 1 33519 35 view .LVU8860
.LBB6524:
	.loc 1 33521 5 view .LVU8861
	.loc 1 33522 5 view .LVU8862
	.loc 1 33523 5 view .LVU8863
	.loc 1 33524 5 view .LVU8864
	.loc 1 33525 5 view .LVU8865
	.loc 1 33526 5 view .LVU8866
	.loc 1 33528 5 view .LVU8867
	.loc 1 33530 5 view .LVU8868
	.loc 1 33531 5 view .LVU8869
	.loc 1 33532 5 view .LVU8870
	.loc 1 33532 5 is_stmt 0 view .LVU8871
.LBE6524:
.LBE6543:
.LBE6551:
.LBE6560:
.LBE6569:
.LBE6579:
	.loc 1 831 5 is_stmt 1 view .LVU8872
.LBB6580:
.LBB6570:
.LBB6561:
.LBB6552:
.LBB6544:
.LBB6525:
	.loc 1 33533 5 view .LVU8873
	.loc 1 33533 5 is_stmt 0 view .LVU8874
.LBE6525:
.LBE6544:
.LBE6552:
.LBE6561:
.LBE6570:
.LBE6580:
	.loc 1 866 5 is_stmt 1 view .LVU8875
	.loc 1 831 5 view .LVU8876
.LBB6581:
.LBB6571:
.LBB6562:
.LBB6553:
.LBB6545:
.LBB6526:
	.loc 1 33534 5 view .LVU8877
	.loc 1 33536 5 view .LVU8878
	.loc 1 33537 5 view .LVU8879
	.loc 1 33538 5 view .LVU8880
	.loc 1 33539 5 view .LVU8881
	.loc 1 33540 5 view .LVU8882
	.loc 1 33541 5 view .LVU8883
	.loc 1 33543 5 view .LVU8884
	.loc 1 33544 5 view .LVU8885
	.loc 1 33546 5 view .LVU8886
	.loc 1 33546 5 is_stmt 0 view .LVU8887
.LBE6526:
.LBE6545:
	.loc 1 33554 5 is_stmt 1 view .LVU8888
.LBB6546:
	.loc 1 32966 18 view .LVU8889
.LBB6540:
	.loc 1 32968 5 view .LVU8890
	.loc 1 32969 5 view .LVU8891
	.loc 1 32971 5 view .LVU8892
	.loc 1 32975 5 view .LVU8893
	.loc 1 32977 5 view .LVU8894
.LBB6537:
	.loc 1 32936 18 view .LVU8895
.LBB6534:
	.loc 1 32938 5 view .LVU8896
	.loc 1 32940 5 view .LVU8897
	.loc 1 32940 5 is_stmt 0 view .LVU8898
.LBE6534:
.LBE6537:
.LBE6540:
.LBE6546:
.LBE6553:
.LBE6562:
.LBE6571:
.LBE6581:
	.loc 1 781 5 is_stmt 1 view .LVU8899
	.loc 1 782 9 view .LVU8900
.LBB6582:
.LBB6572:
.LBB6563:
.LBB6554:
.LBB6547:
.LBB6541:
.LBB6538:
.LBB6535:
	.loc 1 32942 5 view .LVU8901
	.loc 1 32946 5 view .LVU8902
	.loc 1 32950 5 view .LVU8903
	.loc 1 32953 5 view .LVU8904
	.loc 1 32954 5 view .LVU8905
	.loc 1 32957 5 view .LVU8906
	.loc 1 32958 5 view .LVU8907
	.loc 1 32961 5 view .LVU8908
	.loc 1 32963 5 view .LVU8909
	.loc 1 32963 5 is_stmt 0 view .LVU8910
.LBE6535:
.LBE6538:
	.loc 1 32978 5 is_stmt 1 view .LVU8911
	.loc 1 32982 5 view .LVU8912
	.loc 1 32984 5 view .LVU8913
	.loc 1 32984 5 is_stmt 0 view .LVU8914
.LBE6541:
.LBE6547:
.LBE6554:
.LBE6563:
	.loc 1 33758 9 is_stmt 1 view .LVU8915
	.loc 1 33762 9 view .LVU8916
	.loc 1 33762 34 is_stmt 0 view .LVU8917
	addq	%rdi, %rdx
	.loc 1 33762 34 view .LVU8918
.LBE6572:
	.loc 1 33753 5 is_stmt 1 view .LVU8919
.LVL2235:
	.loc 1 33753 27 view .LVU8920
.LBB6573:
	.loc 1 33762 34 is_stmt 0 view .LVU8921
	cmpl	$2, %ecx
	leaq	(%rdx,%rdi), %r8
	cmovne	%r8, %rdx
	movq	%rdx, (%rsi)
.LVL2236:
.L1483:
	.loc 1 33762 34 view .LVU8922
	movl	%ecx, %ecx
	imulq	%rdi, %rcx
	addq	%rcx, %rax
.LVL2237:
.L1482:
	.loc 1 33762 34 view .LVU8923
.LBE6573:
.LBE6582:
	.loc 1 33766 5 is_stmt 1 view .LVU8924
	.loc 1 33766 32 is_stmt 0 view .LVU8925
	addq	$7, %rax
	.loc 1 33769 1 view .LVU8926
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	.loc 1 33766 32 view .LVU8927
	andq	$-8, %rax
	movq	%rax, (%rsi)
	.loc 1 33768 5 is_stmt 1 view .LVU8928
	.loc 1 33768 12 is_stmt 0 view .LVU8929
	xorl	%eax, %eax
	.loc 1 33769 1 view .LVU8930
	ret
.LVL2238:
	.p2align 4,,10
	.p2align 3
.L1486:
	.cfi_restore_state
.LBB6583:
	.loc 1 33739 27 view .LVU8931
	xorl	%eax, %eax
	jmp	.L1481
.LVL2239:
.L1485:
	.loc 1 33739 27 view .LVU8932
.LBE6583:
	.loc 1 33726 16 view .LVU8933
	movl	$-2, %eax
	.loc 1 33769 1 view .LVU8934
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE159:
	.size	_ZL22ma_lpf_get_heap_layoutPK13ma_lpf_configP18ma_lpf_heap_layout.lto_priv.0, .-_ZL22ma_lpf_get_heap_layoutPK13ma_lpf_configP18ma_lpf_heap_layout.lto_priv.0
	.p2align 4
	.type	_ZL23ma_lpf_reinit__internalPK13ma_lpf_configPvP6ma_lpfj, @function
_ZL23ma_lpf_reinit__internalPK13ma_lpf_configPvP6ma_lpfj:
.LVL2240:
.LFB163:
	.loc 1 33772 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 33772 1 is_stmt 0 view .LVU8936
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$200, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
1:	call	mcount
	.loc 1 33772 1 view .LVU8937
	.loc 1 33773 5 is_stmt 1 view .LVU8938
	.loc 1 33774 5 view .LVU8939
	.loc 1 33775 5 view .LVU8940
	.loc 1 33776 5 view .LVU8941
	.loc 1 33777 5 view .LVU8942
	.loc 1 33778 5 view .LVU8943
	.loc 1 33780 5 view .LVU8944
	.loc 1 33785 5 view .LVU8945
	.loc 1 33785 18 is_stmt 0 view .LVU8946
	movl	(%rdi), %r15d
	.loc 1 33772 1 view .LVU8947
	movq	%rsi, -200(%rbp)
	movq	%rdi, %r13
	movq	%rdx, %r12
	movl	%ecx, -176(%rbp)
	.loc 1 33785 42 view .LVU8948
	cmpl	$5, %r15d
	je	.L1573
	cmpl	$2, %r15d
	jne	.L1565
.L1573:
	.loc 1 33790 5 is_stmt 1 view .LVU8949
	.loc 1 33790 15 is_stmt 0 view .LVU8950
	movl	(%r12), %eax
	.loc 1 33790 43 view .LVU8951
	cmpl	%eax, %r15d
	je	.L1574
	testl	%eax, %eax
	jne	.L1567
.L1574:
	.loc 1 33795 5 is_stmt 1 view .LVU8952
	.loc 1 33795 15 is_stmt 0 view .LVU8953
	movl	4(%r12), %eax
	.loc 1 33795 5 view .LVU8954
	testl	%eax, %eax
	jne	.L1657
.L1499:
	.loc 1 33799 5 is_stmt 1 view .LVU8955
	.loc 1 33799 18 is_stmt 0 view .LVU8956
	movl	24(%r13), %eax
	.loc 1 33799 5 view .LVU8957
	cmpl	$8, %eax
	ja	.L1565
	.loc 1 33803 5 is_stmt 1 view .LVU8958
.LVL2241:
.LBB6715:
.LBI6715:
	.loc 1 33700 13 view .LVU8959
.LBB6716:
	.loc 1 33702 5 view .LVU8960
	.loc 1 33703 5 view .LVU8961
	.loc 1 33705 5 view .LVU8962
	.loc 1 33705 25 is_stmt 0 view .LVU8963
	movl	%eax, %ecx
.LVL2242:
	.loc 1 33705 25 view .LVU8964
.LBE6716:
.LBE6715:
	.loc 1 33806 5 view .LVU8965
	movl	-176(%rbp), %esi
.LVL2243:
.LBB6718:
.LBB6717:
	.loc 1 33706 25 view .LVU8966
	shrl	%eax
.LVL2244:
	.loc 1 33705 25 view .LVU8967
	andl	$1, %ecx
.LVL2245:
	.loc 1 33706 25 view .LVU8968
	movl	%eax, -188(%rbp)
	.loc 1 33705 25 view .LVU8969
	movl	%ecx, -172(%rbp)
.LVL2246:
	.loc 1 33706 5 is_stmt 1 view .LVU8970
	.loc 1 33706 5 is_stmt 0 view .LVU8971
.LBE6717:
.LBE6718:
	.loc 1 33806 5 is_stmt 1 view .LVU8972
	testl	%esi, %esi
	jne	.L1500
	.loc 1 33807 9 view .LVU8973
	cmpl	%ecx, 12(%r12)
	jne	.L1567
	.loc 1 33807 42 is_stmt 0 discriminator 1 view .LVU8974
	cmpl	%eax, 16(%r12)
	jne	.L1567
	.loc 1 33812 5 is_stmt 1 view .LVU8975
	.loc 1 33824 9 view .LVU8976
.LVL2247:
.LBB6719:
.LBI6719:
	.loc 1 776 23 view .LVU8977
.LBB6720:
	.loc 1 781 5 view .LVU8978
	.loc 1 782 9 view .LVU8979
.LBE6720:
.LBE6719:
.LBB6723:
	.loc 1 33827 27 is_stmt 0 view .LVU8980
	movl	-172(%rbp), %r11d
.LBE6723:
.LBB6844:
.LBB6721:
	.loc 1 782 15 view .LVU8981
	pxor	%xmm0, %xmm0
	movq	$0, -128(%rbp)
.LVL2248:
	.loc 1 782 15 view .LVU8982
.LBE6721:
.LBE6844:
.LBB6845:
	.loc 1 33827 27 is_stmt 1 view .LVU8983
	movd	%r15d, %xmm1
.LBB6724:
	.loc 1 33828 102 is_stmt 0 view .LVU8984
	movl	8(%r13), %r14d
	.loc 1 33828 83 view .LVU8985
	movl	4(%r13), %ebx
.LBE6724:
.LBE6845:
.LBB6846:
.LBB6722:
	.loc 1 782 15 view .LVU8986
	movaps	%xmm0, -144(%rbp)
.LBE6722:
.LBE6846:
.LBB6847:
	.loc 1 33827 27 view .LVU8987
	testl	%r11d, %r11d
	je	.L1652
.LBB6836:
.LBB6725:
.LBB6726:
	.loc 1 33241 14 view .LVU8988
	movq	.LC117(%rip), %rax
.LVL2249:
	.loc 1 33241 14 view .LVU8989
	movd	%ebx, %xmm5
	.loc 1 33239 23 view .LVU8990
	movl	%r14d, -104(%rbp)
.LBE6726:
.LBE6725:
	.loc 1 33828 123 view .LVU8991
	movsd	16(%r13), %xmm0
	punpckldq	%xmm5, %xmm1
	.loc 1 33828 9 is_stmt 1 view .LVU8992
.LVL2250:
.LBB6735:
.LBI6725:
	.loc 1 33232 23 view .LVU8993
.LBB6731:
	.loc 1 33234 5 view .LVU8994
	.loc 1 33236 5 view .LVU8995
.LBB6727:
.LBI6727:
	.loc 1 776 23 view .LVU8996
.LBB6728:
	.loc 1 781 5 view .LVU8997
	.loc 1 782 9 view .LVU8998
	.loc 1 782 15 is_stmt 0 view .LVU8999
	movl	$0, -100(%rbp)
.LVL2251:
	.loc 1 782 15 view .LVU9000
.LBE6728:
.LBE6727:
	.loc 1 33237 5 is_stmt 1 view .LVU9001
	.loc 1 33238 5 view .LVU9002
	.loc 1 33241 14 is_stmt 0 view .LVU9003
	movq	%rax, -88(%rbp)
.LBE6731:
.LBE6735:
.LBB6736:
	.loc 1 33838 57 view .LVU9004
	movq	24(%r12), %rax
.LBE6736:
.LBB6826:
.LBB6732:
	.loc 1 33237 19 view .LVU9005
	movq	%xmm1, -112(%rbp)
	.loc 1 33239 5 is_stmt 1 view .LVU9006
	.loc 1 33240 5 view .LVU9007
	.loc 1 33240 28 is_stmt 0 view .LVU9008
	movsd	%xmm0, -96(%rbp)
	.loc 1 33241 5 is_stmt 1 view .LVU9009
	.loc 1 33243 5 view .LVU9010
.LVL2252:
	.loc 1 33243 5 is_stmt 0 view .LVU9011
.LBE6732:
.LBE6826:
	.loc 1 33830 9 is_stmt 1 view .LVU9012
.LBB6827:
	.loc 1 33838 13 view .LVU9013
.LBB6737:
.LBI6737:
	.loc 1 33382 18 view .LVU9014
.LBB6738:
	.loc 1 33384 5 view .LVU9015
	.loc 1 33386 5 view .LVU9016
	testq	%rax, %rax
	je	.L1565
	.loc 1 33391 5 view .LVU9017
	.loc 1 33391 42 is_stmt 0 view .LVU9018
	cmpl	$2, %r15d
	je	.L1578
	cmpl	$5, %r15d
	jne	.L1565
.L1578:
	.loc 1 33396 5 is_stmt 1 view .LVU9019
	.loc 1 33396 15 is_stmt 0 view .LVU9020
	movl	(%rax), %edx
.LVL2253:
	.loc 1 33396 43 view .LVU9021
	cmpl	%edx, %r15d
	je	.L1579
	testl	%edx, %edx
	jne	.L1567
.L1579:
	.loc 1 33401 5 is_stmt 1 view .LVU9022
	.loc 1 33401 15 is_stmt 0 view .LVU9023
	movl	4(%rax), %edx
	.loc 1 33401 29 view .LVU9024
	cmpl	%ebx, %edx
	je	.L1580
	testl	%edx, %edx
	jne	.L1567
.L1580:
	.loc 1 33405 5 is_stmt 1 view .LVU9025
	.loc 1 33406 5 view .LVU9026
	.loc 1 33408 16 is_stmt 0 view .LVU9027
	movl	%r14d, %edx
	pxor	%xmm2, %xmm2
	.loc 1 33405 20 view .LVU9028
	movq	%xmm1, (%rax)
	.loc 1 33408 30 view .LVU9029
	mulsd	.LC114(%rip), %xmm0
	.loc 1 33408 16 view .LVU9030
	cvtsi2sdq	%rdx, %xmm2
	.loc 1 33405 20 view .LVU9031
	movq	%rax, -168(%rbp)
	.loc 1 33408 5 is_stmt 1 view .LVU9032
.LBB6739:
.LBI6739:
	.loc 1 834 25 view .LVU9033
.LBB6740:
	.loc 1 837 5 view .LVU9034
.LBE6740:
.LBE6739:
	.loc 1 33405 20 is_stmt 0 view .LVU9035
	movq	%xmm1, -184(%rbp)
	.loc 1 33408 16 view .LVU9036
	divsd	%xmm2, %xmm0
.LBB6742:
.LBB6741:
	.loc 1 837 15 view .LVU9037
	call	exp
.LVL2254:
	.loc 1 837 15 view .LVU9038
.LBE6741:
.LBE6742:
	.loc 1 33409 5 is_stmt 1 view .LVU9039
	cmpl	$5, %r15d
	movq	-168(%rbp), %rax
	movq	-184(%rbp), %xmm1
	je	.L1658
.LVL2255:
	.loc 1 33412 9 view .LVU9040
.LBB6743:
.LBI6743:
	.loc 1 32906 17 view .LVU9041
.LBB6744:
	.loc 1 32908 5 view .LVU9042
	.loc 1 32908 25 is_stmt 0 view .LVU9043
	mulsd	.LC3(%rip), %xmm0
.LVL2256:
	.loc 1 32908 61 view .LVU9044
	cvttsd2sil	%xmm0, %edx
	movl	%edx, 8(%rax)
.LVL2257:
	.loc 1 32908 61 view .LVU9045
.LBE6744:
.LBE6743:
.LBE6738:
.LBE6737:
.LBE6827:
	.loc 1 33841 9 is_stmt 1 view .LVU9046
.L1525:
	.loc 1 33841 9 is_stmt 0 view .LVU9047
.LBE6836:
.LBE6847:
.LBB6848:
	.loc 1 33852 27 is_stmt 1 view .LVU9048
	movl	-188(%rbp), %r10d
	testl	%r10d, %r10d
	je	.L1506
.LBB6849:
.LBB6850:
.LBB6851:
	.loc 1 33872 65 is_stmt 0 view .LVU9049
	movl	-188(%rbp), %eax
	xorl	%r9d, %r9d
.LBE6851:
.LBE6850:
.LBB7056:
.LBB7057:
	movq	%r12, -184(%rbp)
	movq	%r13, %r12
.LVL2258:
	.loc 1 33872 65 view .LVU9050
	movq	%xmm1, -168(%rbp)
	movl	%r14d, %r13d
.LVL2259:
	.loc 1 33872 65 view .LVU9051
	movq	%r9, %r14
.LBE7057:
.LBE7056:
.LBB7065:
.LBB7006:
	salq	$6, %rax
	movq	%rax, -240(%rbp)
	jmp	.L1558
.LVL2260:
	.p2align 4,,10
	.p2align 3
.L1660:
	.loc 1 33872 65 view .LVU9052
.LBE7006:
.LBE7065:
	.loc 1 33859 13 is_stmt 1 view .LVU9053
	.loc 1 33859 41 is_stmt 0 view .LVU9054
	pxor	%xmm3, %xmm3
	movsd	.LC115(%rip), %xmm2
	.loc 1 33859 31 view .LVU9055
	leal	1(%r14), %esi
	pxor	%xmm0, %xmm0
	.loc 1 33859 41 view .LVU9056
	cvtsi2sdq	%rax, %xmm3
	.loc 1 33859 31 view .LVU9057
	cvtsi2sdl	%esi, %xmm0
	.loc 1 33859 41 view .LVU9058
	divsd	%xmm3, %xmm2
	.loc 1 33859 15 view .LVU9059
	mulsd	%xmm2, %xmm0
.LVL2261:
.L1529:
	.loc 1 33863 9 is_stmt 1 view .LVU9060
.LBB7066:
.LBI7066:
	.loc 1 864 25 view .LVU9061
.LBB7067:
	.loc 1 866 5 view .LVU9062
.LBB7068:
.LBI7068:
	.loc 1 828 25 view .LVU9063
.LBB7069:
	.loc 1 831 5 view .LVU9064
.LBE7069:
.LBE7068:
	.loc 1 866 19 is_stmt 0 view .LVU9065
	movsd	.LC116(%rip), %xmm1
	subsd	%xmm0, %xmm1
.LVL2262:
.LBB7071:
.LBB7070:
	.loc 1 831 15 view .LVU9066
	movapd	%xmm1, %xmm0
.LVL2263:
	.loc 1 831 15 view .LVU9067
	call	sin
.LVL2264:
	.loc 1 831 15 view .LVU9068
.LBE7070:
.LBE7071:
.LBE7067:
.LBE7066:
.LBB7072:
.LBB7062:
	.loc 1 33258 5 view .LVU9069
	pxor	%xmm7, %xmm7
	.loc 1 33253 23 view .LVU9070
	movl	%r13d, -104(%rbp)
.LBE7062:
.LBE7072:
	.loc 1 33863 11 view .LVU9071
	movsd	.LC117(%rip), %xmm3
	.loc 1 33865 108 view .LVU9072
	movsd	16(%r12), %xmm2
.LBB7073:
.LBB7063:
	.loc 1 33251 19 view .LVU9073
	movq	-168(%rbp), %rax
.LBB7058:
.LBB7059:
	.loc 1 782 15 view .LVU9074
	movl	$0, -100(%rbp)
.LBE7059:
.LBE7058:
.LBE7063:
.LBE7073:
	.loc 1 33863 11 view .LVU9075
	divsd	%xmm0, %xmm3
.LVL2265:
	.loc 1 33865 9 is_stmt 1 view .LVU9076
.LBB7074:
.LBI7056:
	.loc 1 33246 23 view .LVU9077
.LBB7064:
	.loc 1 33248 5 view .LVU9078
	.loc 1 33250 5 view .LVU9079
.LBB7061:
.LBI7058:
	.loc 1 776 23 view .LVU9080
.LBB7060:
	.loc 1 781 5 view .LVU9081
	.loc 1 782 9 view .LVU9082
	.loc 1 782 9 is_stmt 0 view .LVU9083
.LBE7060:
.LBE7061:
	.loc 1 33251 5 is_stmt 1 view .LVU9084
	.loc 1 33252 5 view .LVU9085
	.loc 1 33251 19 is_stmt 0 view .LVU9086
	movq	%rax, -112(%rbp)
	.loc 1 33253 5 is_stmt 1 view .LVU9087
	.loc 1 33254 5 view .LVU9088
	.loc 1 33254 28 is_stmt 0 view .LVU9089
	movsd	%xmm2, -96(%rbp)
	.loc 1 33255 5 is_stmt 1 view .LVU9090
	.loc 1 33258 5 view .LVU9091
	comisd	%xmm7, %xmm3
	jne	.L1532
	movq	.LC113(%rip), %rax
	movq	%rax, %xmm3
.LVL2266:
.L1532:
	.loc 1 33262 5 view .LVU9092
	.loc 1 33262 5 is_stmt 0 view .LVU9093
.LBE7064:
.LBE7074:
	.loc 1 33867 9 is_stmt 1 view .LVU9094
.LBB7075:
	movl	-176(%rbp), %r8d
	testl	%r8d, %r8d
	je	.L1533
.LBB7007:
	.loc 1 33868 13 view .LVU9095
	.loc 1 33870 13 view .LVU9096
.LVL2267:
.LBB6852:
.LBI6852:
	.loc 1 33549 18 view .LVU9097
.LBB6853:
	.loc 1 33551 5 view .LVU9098
	.loc 1 33552 5 view .LVU9099
.LBB6854:
.LBI6854:
	.loc 1 33519 35 view .LVU9100
.LBB6855:
	.loc 1 33521 5 view .LVU9101
	.loc 1 33522 5 view .LVU9102
	.loc 1 33523 5 view .LVU9103
	.loc 1 33524 5 view .LVU9104
	.loc 1 33525 5 view .LVU9105
	.loc 1 33526 5 view .LVU9106
	.loc 1 33528 5 view .LVU9107
	.loc 1 33530 5 view .LVU9108
	.loc 1 33531 5 view .LVU9109
	.loc 1 33532 5 view .LVU9110
.LBB6856:
.LBI6856:
	.loc 1 828 25 view .LVU9111
.LBB6857:
	.loc 1 831 5 view .LVU9112
	.loc 1 831 5 is_stmt 0 view .LVU9113
.LBE6857:
.LBE6856:
	.loc 1 33533 5 is_stmt 1 view .LVU9114
.LBB6860:
.LBI6860:
	.loc 1 864 25 view .LVU9115
.LBB6861:
	.loc 1 866 5 view .LVU9116
.LBB6862:
.LBI6862:
	.loc 1 828 25 view .LVU9117
.LBB6863:
	.loc 1 831 5 view .LVU9118
	.loc 1 831 5 is_stmt 0 view .LVU9119
.LBE6863:
.LBE6862:
.LBE6861:
.LBE6860:
	.loc 1 33534 5 is_stmt 1 view .LVU9120
	.loc 1 33536 5 view .LVU9121
	.loc 1 33537 5 view .LVU9122
	.loc 1 33538 5 view .LVU9123
	.loc 1 33539 5 view .LVU9124
	.loc 1 33540 5 view .LVU9125
	.loc 1 33541 5 view .LVU9126
	.loc 1 33543 5 view .LVU9127
	.loc 1 33544 5 view .LVU9128
	.loc 1 33546 5 view .LVU9129
	.loc 1 33546 5 is_stmt 0 view .LVU9130
.LBE6855:
.LBE6854:
	.loc 1 33554 5 is_stmt 1 view .LVU9131
.LBB6881:
.LBI6881:
	.loc 1 32966 18 view .LVU9132
.LBB6882:
	.loc 1 32968 5 view .LVU9133
	.loc 1 32969 5 view .LVU9134
	.loc 1 32971 5 view .LVU9135
	.loc 1 32975 5 view .LVU9136
	.loc 1 32977 5 view .LVU9137
.LBB6883:
.LBI6883:
	.loc 1 32936 18 view .LVU9138
.LBB6884:
	.loc 1 32938 5 view .LVU9139
	.loc 1 32940 5 view .LVU9140
	.loc 1 32940 5 is_stmt 0 view .LVU9141
.LBE6884:
.LBE6883:
.LBE6882:
.LBE6881:
.LBE6853:
.LBE6852:
.LBE7007:
.LBE7075:
.LBE6849:
.LBE6848:
	.loc 1 781 5 is_stmt 1 view .LVU9142
	.loc 1 782 9 view .LVU9143
.LBB7132:
.LBB7124:
.LBB7076:
.LBB7008:
.LBB6910:
.LBB6902:
.LBB6894:
.LBB6891:
.LBB6888:
.LBB6885:
	.loc 1 32942 5 view .LVU9144
	.loc 1 32946 5 view .LVU9145
	testl	%ebx, %ebx
	je	.L1654
	.loc 1 32950 5 view .LVU9146
	.loc 1 32953 5 view .LVU9147
	.loc 1 32954 5 view .LVU9148
	.loc 1 32957 5 view .LVU9149
	.loc 1 32958 5 view .LVU9150
	.loc 1 32961 5 view .LVU9151
	.loc 1 32963 5 view .LVU9152
.LVL2268:
	.loc 1 32963 5 is_stmt 0 view .LVU9153
.LBE6885:
.LBE6888:
	.loc 1 32978 5 is_stmt 1 view .LVU9154
	.loc 1 32982 5 view .LVU9155
	.loc 1 32984 5 view .LVU9156
	.loc 1 32984 5 is_stmt 0 view .LVU9157
.LBE6891:
.LBE6894:
.LBE6902:
.LBE6910:
	.loc 1 33871 13 is_stmt 1 view .LVU9158
	.loc 1 33872 17 view .LVU9159
.LBB6911:
.LBB6912:
	.loc 1 33562 5 is_stmt 0 view .LVU9160
	movq	-184(%rbp), %rax
.LBE6912:
.LBE6911:
	.loc 1 33872 51 view .LVU9161
	movq	%r14, %r8
	salq	$6, %r8
.LVL2269:
.LBB6982:
.LBI6911:
	.loc 1 33557 18 is_stmt 1 view .LVU9162
.LBB6965:
	.loc 1 33559 5 view .LVU9163
	.loc 1 33560 5 view .LVU9164
	.loc 1 33562 5 view .LVU9165
	addq	32(%rax), %r8
.LVL2270:
	.loc 1 33562 5 is_stmt 0 view .LVU9166
	je	.L1653
.LBE6965:
.LBE6982:
.LBB6983:
.LBB6903:
.LBB6895:
.LBB6876:
	.loc 1 33531 48 view .LVU9167
	movl	%r13d, %edx
	pxor	%xmm4, %xmm4
.LBB6871:
.LBB6868:
	.loc 1 866 19 view .LVU9168
	movsd	.LC116(%rip), %xmm0
.LVL2271:
	.loc 1 866 19 view .LVU9169
	movq	%r8, -224(%rbp)
.LBE6868:
.LBE6871:
	.loc 1 33531 21 view .LVU9170
	mulsd	.LC118(%rip), %xmm2
	.loc 1 33531 48 view .LVU9171
	cvtsi2sdq	%rdx, %xmm4
	movsd	%xmm3, -232(%rbp)
	.loc 1 33531 7 view .LVU9172
	divsd	%xmm4, %xmm2
.LBB6872:
.LBB6869:
	.loc 1 866 19 view .LVU9173
	subsd	%xmm2, %xmm0
	movsd	%xmm2, -216(%rbp)
.LBB6866:
.LBB6864:
	.loc 1 831 15 view .LVU9174
	call	sin
.LVL2272:
	.loc 1 831 15 view .LVU9175
.LBE6864:
.LBE6866:
.LBE6869:
.LBE6872:
.LBB6873:
.LBB6858:
	movsd	-216(%rbp), %xmm2
.LBE6858:
.LBE6873:
.LBB6874:
.LBB6870:
.LBB6867:
.LBB6865:
	movsd	%xmm0, -208(%rbp)
.LBE6865:
.LBE6867:
.LBE6870:
.LBE6874:
.LBB6875:
.LBB6859:
	movapd	%xmm2, %xmm0
	call	sin
.LVL2273:
.LBE6859:
.LBE6875:
	.loc 1 33534 11 view .LVU9176
	mulsd	.LC117(%rip), %xmm0
	.loc 1 33534 7 view .LVU9177
	movsd	-232(%rbp), %xmm3
	.loc 1 33536 22 view .LVU9178
	movsd	.LC1(%rip), %xmm2
	movsd	-208(%rbp), %xmm4
	.loc 1 33536 27 view .LVU9179
	movsd	.LC117(%rip), %xmm1
	.loc 1 33536 27 view .LVU9180
.LBE6876:
.LBE6895:
.LBE6903:
.LBE6983:
.LBB6984:
.LBB6966:
.LBB6913:
.LBB6914:
.LBB6915:
.LBB6916:
	.loc 1 782 15 view .LVU9181
	movq	-224(%rbp), %r8
.LBE6916:
.LBE6915:
.LBE6914:
.LBE6913:
.LBE6966:
.LBE6984:
.LBB6985:
.LBB6904:
.LBB6896:
.LBB6877:
	.loc 1 33536 22 view .LVU9182
	movapd	%xmm2, %xmm5
.LBE6877:
.LBE6896:
.LBE6904:
.LBE6985:
.LBB6986:
.LBB6967:
	.loc 1 33572 50 view .LVU9183
	movq	-168(%rbp), %rax
.LBE6967:
.LBE6986:
	.loc 1 33872 65 view .LVU9184
	movq	-128(%rbp), %rdx
.LVL2274:
.LBB6987:
.LBB6968:
	.loc 1 33566 5 is_stmt 1 view .LVU9185
	.loc 1 33566 5 is_stmt 0 view .LVU9186
.LBE6968:
.LBE6987:
.LBE7008:
.LBE7076:
.LBE7124:
.LBE7132:
	.loc 1 781 5 is_stmt 1 view .LVU9187
	.loc 1 782 9 view .LVU9188
.LBB7133:
.LBB7125:
.LBB7077:
.LBB7009:
.LBB6988:
.LBB6969:
	.loc 1 33568 5 view .LVU9189
	.loc 1 33572 5 view .LVU9190
.LBB6950:
.LBI6950:
	.loc 1 33519 35 view .LVU9191
.LBB6951:
	.loc 1 33521 5 view .LVU9192
	.loc 1 33522 5 view .LVU9193
	.loc 1 33523 5 view .LVU9194
	.loc 1 33524 5 view .LVU9195
	.loc 1 33525 5 view .LVU9196
	.loc 1 33526 5 view .LVU9197
	.loc 1 33528 5 view .LVU9198
	.loc 1 33530 5 view .LVU9199
	.loc 1 33531 5 view .LVU9200
	.loc 1 33532 5 view .LVU9201
	.loc 1 33532 5 is_stmt 0 view .LVU9202
.LBE6951:
.LBE6950:
.LBE6969:
.LBE6988:
.LBE7009:
.LBE7077:
.LBE7125:
.LBE7133:
	.loc 1 831 5 is_stmt 1 view .LVU9203
.LBB7134:
.LBB7126:
.LBB7078:
.LBB7010:
.LBB6989:
.LBB6970:
.LBB6954:
.LBB6952:
	.loc 1 33533 5 view .LVU9204
	.loc 1 33533 5 is_stmt 0 view .LVU9205
.LBE6952:
.LBE6954:
.LBE6970:
.LBE6989:
.LBE7010:
.LBE7078:
.LBE7126:
.LBE7134:
	.loc 1 866 5 is_stmt 1 view .LVU9206
	.loc 1 831 5 view .LVU9207
.LBB7135:
.LBB7127:
.LBB7079:
.LBB7011:
.LBB6990:
.LBB6971:
.LBB6955:
.LBB6953:
	.loc 1 33534 5 view .LVU9208
	.loc 1 33536 5 view .LVU9209
	.loc 1 33537 5 view .LVU9210
	.loc 1 33538 5 view .LVU9211
	.loc 1 33539 5 view .LVU9212
	.loc 1 33540 5 view .LVU9213
	.loc 1 33541 5 view .LVU9214
	.loc 1 33543 5 view .LVU9215
	.loc 1 33544 5 view .LVU9216
	.loc 1 33546 5 view .LVU9217
	.loc 1 33546 5 is_stmt 0 view .LVU9218
.LBE6953:
.LBE6955:
.LBE6971:
.LBE6990:
.LBB6991:
.LBB6905:
.LBB6897:
.LBB6878:
	.loc 1 33536 22 view .LVU9219
	subsd	%xmm4, %xmm5
	.loc 1 33540 22 view .LVU9220
	mulsd	.LC119(%rip), %xmm4
	.loc 1 33534 7 view .LVU9221
	divsd	%xmm3, %xmm0
.LBE6878:
.LBE6897:
.LBE6905:
.LBE6991:
.LBB6992:
.LBB6972:
	.loc 1 33572 50 view .LVU9222
	movq	%rax, -112(%rbp)
.LBE6972:
.LBE6992:
.LBB6993:
.LBB6906:
.LBB6898:
.LBB6879:
	.loc 1 33536 27 view .LVU9223
	mulsd	%xmm5, %xmm1
	.loc 1 33536 27 view .LVU9224
.LBE6879:
.LBE6898:
.LBE6906:
.LBE6993:
.LBB6994:
.LBB6973:
	.loc 1 33572 50 view .LVU9225
	movsd	%xmm5, -96(%rbp)
	movsd	%xmm4, -72(%rbp)
	movsd	%xmm1, -104(%rbp)
	movsd	%xmm1, -88(%rbp)
.LBE6973:
.LBE6994:
.LBB6995:
.LBB6907:
.LBB6899:
.LBB6880:
	.loc 1 33539 22 view .LVU9226
	movapd	%xmm0, %xmm1
	addsd	%xmm2, %xmm1
	.loc 1 33541 22 view .LVU9227
	subsd	%xmm0, %xmm2
.LBE6880:
.LBE6899:
.LBE6907:
.LBE6995:
.LBB6996:
.LBB6974:
.LBB6956:
.LBB6941:
.LBB6919:
.LBB6917:
	.loc 1 782 15 view .LVU9228
	pxor	%xmm0, %xmm0
.LBE6917:
.LBE6919:
.LBE6941:
.LBE6956:
	.loc 1 33572 50 view .LVU9229
	movsd	%xmm1, -80(%rbp)
	movsd	%xmm2, -64(%rbp)
	.loc 1 33573 5 is_stmt 1 view .LVU9230
.LVL2275:
.LBB6957:
.LBI6913:
	.loc 1 32987 18 view .LVU9231
.LBB6942:
	.loc 1 32989 5 view .LVU9232
	.loc 1 32990 5 view .LVU9233
	.loc 1 32992 5 view .LVU9234
	.loc 1 32996 5 view .LVU9235
.LBB6920:
.LBI6915:
	.loc 1 776 23 view .LVU9236
.LBB6918:
	.loc 1 781 5 view .LVU9237
	.loc 1 782 9 view .LVU9238
	.loc 1 782 15 is_stmt 0 view .LVU9239
	movups	%xmm0, (%r8)
	movups	%xmm0, 16(%r8)
	movups	%xmm0, 32(%r8)
	movups	%xmm0, 48(%r8)
.LVL2276:
	.loc 1 782 15 view .LVU9240
.LBE6918:
.LBE6920:
	.loc 1 32998 5 is_stmt 1 view .LVU9241
.LBB6921:
.LBI6921:
	.loc 1 32936 18 view .LVU9242
.LBB6922:
	.loc 1 32938 5 view .LVU9243
	.loc 1 32940 5 view .LVU9244
	.loc 1 32940 5 is_stmt 0 view .LVU9245
.LBE6922:
.LBE6921:
.LBE6942:
.LBE6957:
.LBE6974:
.LBE6996:
.LBE7011:
.LBE7079:
.LBE7127:
.LBE7135:
	.loc 1 781 5 is_stmt 1 view .LVU9246
	.loc 1 782 9 view .LVU9247
.LBB7136:
.LBB7128:
.LBB7080:
.LBB7012:
.LBB6997:
.LBB6975:
.LBB6958:
.LBB6943:
.LBB6929:
.LBB6923:
	.loc 1 32942 5 view .LVU9248
	.loc 1 32946 5 view .LVU9249
	.loc 1 32946 18 is_stmt 0 view .LVU9250
	movl	-108(%rbp), %eax
	.loc 1 32946 5 view .LVU9251
	testl	%eax, %eax
	je	.L1654
.LBE6923:
.LBE6929:
.LBE6943:
.LBE6958:
.LBE6975:
.LBE6997:
.LBB6998:
.LBB6908:
.LBB6900:
.LBB6892:
.LBB6889:
.LBB6886:
	.loc 1 32954 74 view .LVU9252
	movl	%ebx, %edi
.LVL2277:
	.loc 1 32954 74 view .LVU9253
.LBE6886:
.LBE6889:
.LBE6892:
.LBE6900:
.LBE6908:
.LBE6998:
	.loc 1 33872 65 view .LVU9254
	addq	-240(%rbp), %rdx
.LVL2278:
.LBB6999:
.LBB6976:
.LBB6959:
.LBB6944:
.LBB6930:
.LBB6924:
	.loc 1 32954 74 view .LVU9255
	movl	%eax, %ebx
.LBE6924:
.LBE6930:
.LBB6931:
.LBB6932:
	.loc 1 782 15 view .LVU9256
	xorl	%esi, %esi
.LBE6932:
.LBE6931:
.LBE6944:
.LBE6959:
.LBE6976:
.LBE6999:
.LBB7000:
.LBB6909:
.LBB6901:
.LBB6893:
.LBB6890:
.LBB6887:
	.loc 1 32961 32 view .LVU9257
	salq	$3, %rdi
.LVL2279:
	.loc 1 32961 32 view .LVU9258
.LBE6887:
.LBE6890:
.LBE6893:
.LBE6901:
.LBE6909:
.LBE7000:
.LBB7001:
.LBB6977:
.LBB6960:
.LBB6945:
	.loc 1 33003 17 view .LVU9259
	movq	%r8, -168(%rbp)
.LBE6945:
.LBE6960:
.LBE6977:
.LBE7001:
	.loc 1 33872 65 view .LVU9260
	imulq	%r14, %rdi
	addq	%rdx, %rdi
	.loc 1 33872 51 view .LVU9261
	addq	-200(%rbp), %rdi
.LBB7002:
.LBB6978:
.LBB6961:
.LBB6946:
.LBB6935:
.LBB6925:
	.loc 1 32950 5 is_stmt 1 view .LVU9262
	.loc 1 32953 5 view .LVU9263
	.loc 1 32954 5 view .LVU9264
	.loc 1 32957 5 view .LVU9265
	.loc 1 32958 5 view .LVU9266
	.loc 1 32961 5 view .LVU9267
	.loc 1 32963 5 view .LVU9268
.LVL2280:
	.loc 1 32963 5 is_stmt 0 view .LVU9269
.LBE6925:
.LBE6935:
	.loc 1 32999 5 is_stmt 1 view .LVU9270
	.loc 1 33003 5 view .LVU9271
	.loc 1 33004 5 view .LVU9272
.LBB6936:
.LBI6931:
	.loc 1 776 23 view .LVU9273
.LBB6933:
	.loc 1 781 5 view .LVU9274
	.loc 1 782 9 view .LVU9275
.LBE6933:
.LBE6936:
.LBB6937:
.LBB6926:
	.loc 1 32961 32 is_stmt 0 view .LVU9276
	leaq	0(,%rbx,8), %rdx
.LBE6926:
.LBE6937:
	.loc 1 33003 17 view .LVU9277
	movq	%rdi, 48(%r8)
.LBB6938:
.LBB6934:
	.loc 1 782 15 view .LVU9278
	call	memset
.LVL2281:
	.loc 1 782 15 view .LVU9279
.LBE6934:
.LBE6938:
	.loc 1 33006 5 is_stmt 1 view .LVU9280
	.loc 1 33006 14 is_stmt 0 view .LVU9281
	movq	-168(%rbp), %r8
.LBE6946:
.LBE6961:
.LBE6978:
.LBE7002:
.LBE7012:
.LBB7013:
.LBB7014:
	.loc 1 33630 30 view .LVU9282
	leaq	-112(%rbp), %rdi
.LVL2282:
	.loc 1 33630 30 view .LVU9283
.LBE7014:
.LBE7013:
.LBB7048:
.LBB7003:
.LBB6979:
.LBB6962:
.LBB6947:
	.loc 1 33006 14 view .LVU9284
	movq	%rax, 32(%r8)
	.loc 1 33007 5 is_stmt 1 view .LVU9285
	.loc 1 33007 16 is_stmt 0 view .LVU9286
	leaq	(%rax,%rbx,4), %rax
	.loc 1 33009 28 view .LVU9287
	movq	%r8, %rsi
	.loc 1 33007 16 view .LVU9288
	movq	%rax, 40(%r8)
	.loc 1 33009 5 is_stmt 1 view .LVU9289
.LBE6947:
.LBE6962:
.LBE6979:
.LBE7003:
.LBE7048:
.LBB7049:
.LBB7043:
	.loc 1 33630 30 is_stmt 0 view .LVU9290
	call	ma_biquad_reinit
.LVL2283:
	.loc 1 33630 30 view .LVU9291
	movl	%eax, %ebx
.LVL2284:
	.loc 1 33631 5 is_stmt 1 view .LVU9292
	testl	%eax, %eax
	jne	.L1659
.LVL2285:
.L1542:
	.loc 1 33631 5 is_stmt 0 view .LVU9293
.LBE7043:
.LBE7049:
.LBE7080:
.LBE7128:
	.loc 1 33852 5 is_stmt 1 view .LVU9294
	.loc 1 33852 27 view .LVU9295
.LBE7136:
	.loc 1 33896 33 is_stmt 0 view .LVU9296
	movl	(%r12), %r15d
	.loc 1 33897 33 view .LVU9297
	movl	4(%r12), %ebx
.LBB7137:
	.loc 1 33852 27 view .LVU9298
	addq	$1, %r14
.LVL2286:
	.loc 1 33852 27 view .LVU9299
.LBE7137:
	.loc 1 33898 33 view .LVU9300
	movl	8(%r12), %r13d
.LBB7138:
	.loc 1 33852 27 view .LVU9301
	cmpl	%r14d, -188(%rbp)
	jbe	.L1648
	movd	%r15d, %xmm6
	movd	%ebx, %xmm4
	punpckldq	%xmm4, %xmm6
	movq	%xmm6, -168(%rbp)
.LVL2287:
.L1558:
.LBB7129:
	.loc 1 33858 9 view .LVU9302
	movl	-172(%rbp), %r9d
	.loc 1 33859 52 view .LVU9303
	movl	24(%r12), %eax
	movl	%r14d, %r15d
.LVL2288:
	.loc 1 33853 9 is_stmt 1 view .LVU9304
	.loc 1 33854 9 view .LVU9305
	.loc 1 33855 9 view .LVU9306
	.loc 1 33858 9 view .LVU9307
	testl	%r9d, %r9d
	jne	.L1660
	.loc 1 33861 13 view .LVU9308
	.loc 1 33861 41 is_stmt 0 view .LVU9309
	pxor	%xmm3, %xmm3
	.loc 1 33861 31 view .LVU9310
	leal	1(%r14,%r14), %esi
	pxor	%xmm0, %xmm0
	.loc 1 33861 57 view .LVU9311
	addl	%eax, %eax
	.loc 1 33861 41 view .LVU9312
	cvtsi2sdq	%rax, %xmm3
	movsd	.LC115(%rip), %xmm2
	.loc 1 33861 31 view .LVU9313
	cvtsi2sdl	%esi, %xmm0
	.loc 1 33861 41 view .LVU9314
	divsd	%xmm3, %xmm2
	.loc 1 33861 15 view .LVU9315
	mulsd	%xmm2, %xmm0
.LVL2289:
	.loc 1 33861 15 view .LVU9316
	jmp	.L1529
.LVL2290:
	.p2align 4,,10
	.p2align 3
.L1565:
	.loc 1 33861 15 view .LVU9317
.LBE7129:
.LBE7138:
	.loc 1 33786 16 view .LVU9318
	movl	$-2, %ebx
.LVL2291:
.L1495:
	.loc 1 33901 1 view .LVU9319
	addq	$200, %rsp
	movl	%ebx, %eax
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL2292:
	.p2align 4,,10
	.p2align 3
.L1657:
	.cfi_restore_state
	.loc 1 33795 29 discriminator 1 view .LVU9320
	cmpl	4(%r13), %eax
	je	.L1499
.LVL2293:
	.p2align 4,,10
	.p2align 3
.L1567:
	.loc 1 33791 16 view .LVU9321
	movl	$-3, %ebx
	jmp	.L1495
.LVL2294:
	.p2align 4,,10
	.p2align 3
.L1500:
	.loc 1 33812 5 is_stmt 1 view .LVU9322
	.loc 1 33813 9 view .LVU9323
	.loc 1 33813 40 is_stmt 0 view .LVU9324
	leaq	-144(%rbp), %rsi
	movq	%r13, %rdi
.LVL2295:
	.loc 1 33813 40 view .LVU9325
	call	_ZL22ma_lpf_get_heap_layoutPK13ma_lpf_configP18ma_lpf_heap_layout.lto_priv.0
.LVL2296:
	.loc 1 33813 40 view .LVU9326
	movl	%eax, %ebx
.LVL2297:
	.loc 1 33814 9 is_stmt 1 view .LVU9327
	testl	%eax, %eax
	jne	.L1495
	.loc 1 33818 9 view .LVU9328
	.loc 1 33818 22 is_stmt 0 view .LVU9329
	movq	-200(%rbp), %rax
.LVL2298:
	.loc 1 33819 9 view .LVU9330
	movq	-144(%rbp), %rdx
	.loc 1 33818 22 view .LVU9331
	movq	%rax, 40(%r12)
	.loc 1 33819 9 is_stmt 1 view .LVU9332
.LVL2299:
.LBB7139:
.LBI7139:
	.loc 1 776 23 view .LVU9333
.LBB7140:
	.loc 1 781 5 view .LVU9334
	testq	%rdx, %rdx
	jne	.L1661
.LVL2300:
.L1502:
	.loc 1 781 5 is_stmt 0 view .LVU9335
.LBE7140:
.LBE7139:
	.loc 1 33821 9 is_stmt 1 view .LVU9336
	.loc 1 33821 23 is_stmt 0 view .LVU9337
	movq	-200(%rbp), %xmm0
	movdqu	-136(%rbp), %xmm6
.LBB7142:
	.loc 1 33827 27 view .LVU9338
	movl	-172(%rbp), %edx
.LBE7142:
	.loc 1 33821 33 view .LVU9339
	movq	-136(%rbp), %rax
	.loc 1 33822 9 is_stmt 1 view .LVU9340
	.loc 1 33821 23 is_stmt 0 view .LVU9341
	punpcklqdq	%xmm0, %xmm0
	paddq	%xmm6, %xmm0
	.loc 1 33821 21 view .LVU9342
	movups	%xmm0, 24(%r12)
.LBB7143:
.LBB6837:
	.loc 1 33828 66 view .LVU9343
	movl	0(%r13), %r15d
.LVL2301:
	.loc 1 33828 66 view .LVU9344
.LBE6837:
	.loc 1 33827 27 is_stmt 1 view .LVU9345
.LBB6838:
	.loc 1 33828 102 is_stmt 0 view .LVU9346
	movl	8(%r13), %r14d
	.loc 1 33828 83 view .LVU9347
	movl	4(%r13), %ebx
.LVL2302:
	.loc 1 33828 83 view .LVU9348
	movd	%r15d, %xmm1
.LBE6838:
	.loc 1 33827 27 view .LVU9349
	testl	%edx, %edx
	je	.L1652
.LBB6839:
	.loc 1 33828 123 view .LVU9350
	movsd	16(%r13), %xmm0
	movd	%ebx, %xmm7
.LBB6828:
.LBB6733:
	.loc 1 33239 23 view .LVU9351
	movl	%r14d, -104(%rbp)
	.loc 1 33241 14 view .LVU9352
	movq	.LC117(%rip), %rcx
	punpckldq	%xmm7, %xmm1
	.loc 1 33241 14 view .LVU9353
.LBE6733:
.LBE6828:
	.loc 1 33828 9 is_stmt 1 view .LVU9354
.LVL2303:
.LBB6829:
	.loc 1 33232 23 view .LVU9355
.LBB6734:
	.loc 1 33234 5 view .LVU9356
	.loc 1 33236 5 view .LVU9357
.LBB6730:
	.loc 1 776 23 view .LVU9358
.LBB6729:
	.loc 1 781 5 view .LVU9359
	.loc 1 782 9 view .LVU9360
	.loc 1 782 15 is_stmt 0 view .LVU9361
	movl	$0, -100(%rbp)
.LVL2304:
	.loc 1 782 15 view .LVU9362
.LBE6729:
.LBE6730:
	.loc 1 33237 5 is_stmt 1 view .LVU9363
	.loc 1 33238 5 view .LVU9364
	.loc 1 33237 19 is_stmt 0 view .LVU9365
	movq	%xmm1, -112(%rbp)
	.loc 1 33239 5 is_stmt 1 view .LVU9366
	.loc 1 33240 5 view .LVU9367
	.loc 1 33241 14 is_stmt 0 view .LVU9368
	movq	%rcx, -88(%rbp)
	.loc 1 33240 28 view .LVU9369
	movsd	%xmm0, -96(%rbp)
	.loc 1 33241 5 is_stmt 1 view .LVU9370
	.loc 1 33243 5 view .LVU9371
.LVL2305:
	.loc 1 33243 5 is_stmt 0 view .LVU9372
.LBE6734:
.LBE6829:
	.loc 1 33830 9 is_stmt 1 view .LVU9373
.LBB6830:
.LBB6746:
	.loc 1 33831 13 view .LVU9374
	.loc 1 33833 13 view .LVU9375
.LBB6747:
.LBI6747:
	.loc 1 33298 18 view .LVU9376
.LBB6748:
	.loc 1 33300 5 view .LVU9377
	.loc 1 33301 5 view .LVU9378
	.loc 1 33303 5 view .LVU9379
	.loc 1 33307 5 view .LVU9380
.LBB6749:
.LBI6749:
	.loc 1 33272 18 view .LVU9381
.LBB6750:
	.loc 1 33274 5 view .LVU9382
	.loc 1 33276 5 view .LVU9383
	.loc 1 33276 5 is_stmt 0 view .LVU9384
.LBE6750:
.LBE6749:
.LBE6748:
.LBE6747:
.LBE6746:
.LBE6830:
.LBE6839:
.LBE7143:
	.loc 1 781 5 is_stmt 1 view .LVU9385
	.loc 1 782 9 view .LVU9386
.LBB7144:
.LBB6840:
.LBB6831:
.LBB6821:
.LBB6763:
.LBB6759:
.LBB6755:
.LBB6751:
	.loc 1 33278 5 view .LVU9387
	.loc 1 33282 5 view .LVU9388
	testl	%ebx, %ebx
	je	.L1565
	.loc 1 33286 5 view .LVU9389
	.loc 1 33289 5 view .LVU9390
	.loc 1 33290 5 view .LVU9391
	.loc 1 33293 5 view .LVU9392
	.loc 1 33295 5 view .LVU9393
.LVL2306:
	.loc 1 33295 5 is_stmt 0 view .LVU9394
.LBE6751:
.LBE6755:
	.loc 1 33308 5 is_stmt 1 view .LVU9395
	.loc 1 33312 5 view .LVU9396
	.loc 1 33314 5 view .LVU9397
	.loc 1 33314 5 is_stmt 0 view .LVU9398
.LBE6759:
.LBE6763:
	.loc 1 33834 13 is_stmt 1 view .LVU9399
	.loc 1 33835 17 view .LVU9400
	.loc 1 33835 181 is_stmt 0 view .LVU9401
	movq	24(%r12), %r9
.LVL2307:
.LBB6764:
.LBI6764:
	.loc 1 33317 18 is_stmt 1 view .LVU9402
.LBB6765:
	.loc 1 33319 5 view .LVU9403
	.loc 1 33320 5 view .LVU9404
	.loc 1 33322 5 view .LVU9405
	testq	%r9, %r9
	je	.L1565
.LBE6765:
.LBE6764:
	.loc 1 33835 51 is_stmt 0 view .LVU9406
	movq	-200(%rbp), %rcx
.LBB6811:
.LBB6804:
.LBB6766:
.LBB6767:
	.loc 1 782 15 view .LVU9407
	pxor	%xmm2, %xmm2
.LBE6767:
.LBE6766:
.LBE6804:
.LBE6811:
.LBB6812:
.LBB6760:
.LBB6756:
.LBB6752:
	.loc 1 33290 74 view .LVU9408
	movl	%ebx, %edx
.LBE6752:
.LBE6756:
.LBE6760:
.LBE6812:
.LBB6813:
.LBB6805:
.LBB6771:
.LBB6772:
	.loc 1 782 15 view .LVU9409
	xorl	%esi, %esi
.LBE6772:
.LBE6771:
.LBB6774:
.LBB6768:
	movups	%xmm2, 16(%r9)
.LBE6768:
.LBE6774:
.LBE6805:
.LBE6813:
.LBB6814:
.LBB6761:
.LBB6757:
.LBB6753:
	.loc 1 33293 32 view .LVU9410
	leaq	7(,%rdx,4), %rdx
.LBE6753:
.LBE6757:
.LBE6761:
.LBE6814:
	.loc 1 33835 51 view .LVU9411
	leaq	40(%rcx,%rax), %rdi
.LBB6815:
.LBB6806:
	.loc 1 33326 5 is_stmt 1 view .LVU9412
.LVL2308:
.LBB6775:
.LBI6766:
	.loc 1 776 23 view .LVU9413
.LBB6769:
	.loc 1 781 5 view .LVU9414
	.loc 1 782 9 view .LVU9415
	.loc 1 782 15 is_stmt 0 view .LVU9416
	movq	$0, 32(%r9)
.LVL2309:
	.loc 1 782 15 view .LVU9417
.LBE6769:
.LBE6775:
	.loc 1 33328 5 is_stmt 1 view .LVU9418
.LBB6776:
.LBI6776:
	.loc 1 33272 18 view .LVU9419
.LBB6777:
	.loc 1 33274 5 view .LVU9420
	.loc 1 33276 5 view .LVU9421
.LBB6778:
.LBI6778:
	.loc 1 776 23 view .LVU9422
.LBB6779:
	.loc 1 781 5 view .LVU9423
	.loc 1 782 9 view .LVU9424
.LBE6779:
.LBE6778:
.LBE6777:
.LBE6776:
.LBE6806:
.LBE6815:
.LBB6816:
.LBB6762:
.LBB6758:
.LBB6754:
	.loc 1 33293 32 is_stmt 0 view .LVU9425
	andq	$-8, %rdx
.LBE6754:
.LBE6758:
.LBE6762:
.LBE6816:
.LBB6817:
.LBB6807:
	.loc 1 33333 18 view .LVU9426
	movq	%rdi, 24(%r9)
.LBB6783:
.LBB6770:
	.loc 1 782 15 view .LVU9427
	movups	%xmm2, (%r9)
.LBE6770:
.LBE6783:
	.loc 1 33333 18 view .LVU9428
	movq	%r9, -168(%rbp)
	movq	%xmm1, -208(%rbp)
	movsd	%xmm0, -184(%rbp)
.LBB6784:
.LBB6782:
.LBB6781:
.LBB6780:
	.loc 1 782 15 view .LVU9429
	movq	$0, -152(%rbp)
.LVL2310:
	.loc 1 782 15 view .LVU9430
.LBE6780:
.LBE6781:
	.loc 1 33278 5 is_stmt 1 view .LVU9431
	.loc 1 33282 5 view .LVU9432
	.loc 1 33286 5 view .LVU9433
	.loc 1 33289 5 view .LVU9434
	.loc 1 33290 5 view .LVU9435
	.loc 1 33293 5 view .LVU9436
	.loc 1 33293 30 is_stmt 0 view .LVU9437
	movq	%rdx, -160(%rbp)
	.loc 1 33295 5 is_stmt 1 view .LVU9438
.LVL2311:
	.loc 1 33295 5 is_stmt 0 view .LVU9439
.LBE6782:
.LBE6784:
	.loc 1 33329 5 is_stmt 1 view .LVU9440
	.loc 1 33333 5 view .LVU9441
	.loc 1 33334 5 view .LVU9442
.LBB6785:
.LBI6771:
	.loc 1 776 23 view .LVU9443
.LBB6773:
	.loc 1 781 5 view .LVU9444
	.loc 1 782 9 view .LVU9445
	.loc 1 782 15 is_stmt 0 view .LVU9446
	call	memset
.LVL2312:
	.loc 1 782 15 view .LVU9447
.LBE6773:
.LBE6785:
	.loc 1 33336 5 is_stmt 1 view .LVU9448
	.loc 1 33336 15 is_stmt 0 view .LVU9449
	movq	-168(%rbp), %r9
.LBB6786:
.LBB6787:
	.loc 1 33391 42 view .LVU9450
	cmpl	$2, %r15d
	movsd	-184(%rbp), %xmm0
	movq	-208(%rbp), %xmm1
.LBE6787:
.LBE6786:
	.loc 1 33336 15 view .LVU9451
	movq	%rax, 16(%r9)
	.loc 1 33338 5 is_stmt 1 view .LVU9452
.LVL2313:
.LBB6800:
.LBI6786:
	.loc 1 33382 18 view .LVU9453
.LBB6796:
	.loc 1 33384 5 view .LVU9454
	.loc 1 33386 5 view .LVU9455
	.loc 1 33391 5 view .LVU9456
	.loc 1 33391 42 is_stmt 0 view .LVU9457
	je	.L1575
	cmpl	$5, %r15d
	jne	.L1565
.L1575:
	.loc 1 33396 5 is_stmt 1 view .LVU9458
	.loc 1 33396 15 is_stmt 0 view .LVU9459
	movl	(%r9), %eax
	.loc 1 33396 43 view .LVU9460
	testl	%eax, %eax
	je	.L1576
	cmpl	%r15d, %eax
	jne	.L1567
.L1576:
	.loc 1 33401 5 is_stmt 1 view .LVU9461
	.loc 1 33401 15 is_stmt 0 view .LVU9462
	movl	4(%r9), %eax
	.loc 1 33401 29 view .LVU9463
	cmpl	%eax, %ebx
	je	.L1577
	testl	%eax, %eax
	jne	.L1567
.L1577:
	.loc 1 33405 5 is_stmt 1 view .LVU9464
	.loc 1 33406 5 view .LVU9465
	.loc 1 33405 20 is_stmt 0 view .LVU9466
	movq	%xmm1, (%r9)
	.loc 1 33408 16 view .LVU9467
	movl	%r14d, %ecx
	pxor	%xmm1, %xmm1
	.loc 1 33408 30 view .LVU9468
	mulsd	.LC114(%rip), %xmm0
	.loc 1 33408 16 view .LVU9469
	cvtsi2sdq	%rcx, %xmm1
	.loc 1 33405 20 view .LVU9470
	movq	%r9, -168(%rbp)
.LVL2314:
	.loc 1 33408 5 is_stmt 1 view .LVU9471
.LBB6788:
.LBI6788:
	.loc 1 834 25 view .LVU9472
.LBB6789:
	.loc 1 837 5 view .LVU9473
.LBE6789:
.LBE6788:
	.loc 1 33408 16 is_stmt 0 view .LVU9474
	divsd	%xmm1, %xmm0
.LBB6791:
.LBB6790:
	.loc 1 837 15 view .LVU9475
	call	exp
.LVL2315:
	.loc 1 837 15 view .LVU9476
.LBE6790:
.LBE6791:
	.loc 1 33409 5 is_stmt 1 view .LVU9477
	cmpl	$5, %r15d
	movq	-168(%rbp), %r9
	je	.L1662
.LVL2316:
	.loc 1 33412 9 view .LVU9478
.LBB6792:
.LBI6792:
	.loc 1 32906 17 view .LVU9479
.LBB6793:
	.loc 1 32908 5 view .LVU9480
	.loc 1 32908 25 is_stmt 0 view .LVU9481
	mulsd	.LC3(%rip), %xmm0
.LVL2317:
	.loc 1 32908 25 view .LVU9482
.LBE6793:
.LBE6792:
.LBE6796:
.LBE6800:
.LBE6807:
.LBE6817:
.LBE6821:
.LBE6831:
.LBE6840:
.LBE7144:
	.loc 1 33897 33 view .LVU9483
	movl	4(%r13), %ebx
	movd	0(%r13), %xmm1
	.loc 1 33898 33 view .LVU9484
	movl	8(%r13), %r14d
	movd	%ebx, %xmm6
	punpckldq	%xmm6, %xmm1
.LBB7145:
.LBB6841:
.LBB6832:
.LBB6822:
.LBB6818:
.LBB6808:
.LBB6801:
.LBB6797:
.LBB6795:
.LBB6794:
	.loc 1 32908 61 view .LVU9485
	cvttsd2sil	%xmm0, %eax
	movl	%eax, 8(%r9)
.LVL2318:
	.loc 1 32908 61 view .LVU9486
.LBE6794:
.LBE6795:
.LBE6797:
.LBE6801:
.LBE6808:
.LBE6818:
.LBE6822:
.LBE6832:
	.loc 1 33841 9 is_stmt 1 view .LVU9487
	jmp	.L1525
.LVL2319:
	.p2align 4,,10
	.p2align 3
.L1533:
	.loc 1 33841 9 is_stmt 0 view .LVU9488
.LBE6841:
.LBE7145:
.LBB7146:
.LBB7130:
.LBB7081:
	.loc 1 33875 13 is_stmt 1 view .LVU9489
.LBB7050:
.LBB7044:
	.loc 1 33625 5 is_stmt 0 view .LVU9490
	movq	-184(%rbp), %rax
.LBE7044:
.LBE7050:
	.loc 1 33875 36 view .LVU9491
	movq	%r14, %rsi
	salq	$6, %rsi
.LVL2320:
.LBB7051:
.LBI7013:
	.loc 1 33620 18 is_stmt 1 view .LVU9492
.LBB7045:
	.loc 1 33622 5 view .LVU9493
	.loc 1 33623 5 view .LVU9494
	.loc 1 33625 5 view .LVU9495
	addq	32(%rax), %rsi
.LVL2321:
	.loc 1 33625 5 is_stmt 0 view .LVU9496
	movq	%rsi, %rbx
	je	.L1653
.LBB7015:
.LBB7016:
	.loc 1 33531 48 view .LVU9497
	movl	%r13d, %edx
	pxor	%xmm4, %xmm4
	movsd	%xmm3, -216(%rbp)
.LBE7016:
.LBE7015:
	.loc 1 33629 5 is_stmt 1 view .LVU9498
.LVL2322:
.LBB7038:
.LBI7015:
	.loc 1 33519 35 view .LVU9499
.LBB7033:
	.loc 1 33521 5 view .LVU9500
	.loc 1 33522 5 view .LVU9501
	.loc 1 33523 5 view .LVU9502
	.loc 1 33524 5 view .LVU9503
	.loc 1 33525 5 view .LVU9504
	.loc 1 33526 5 view .LVU9505
	.loc 1 33528 5 view .LVU9506
	.loc 1 33530 5 view .LVU9507
	.loc 1 33531 5 view .LVU9508
	.loc 1 33531 21 is_stmt 0 view .LVU9509
	mulsd	.LC118(%rip), %xmm2
	.loc 1 33531 48 view .LVU9510
	cvtsi2sdq	%rdx, %xmm4
	.loc 1 33531 7 view .LVU9511
	divsd	%xmm4, %xmm2
.LVL2323:
	.loc 1 33532 5 is_stmt 1 view .LVU9512
.LBB7017:
.LBI7017:
	.loc 1 828 25 view .LVU9513
.LBB7018:
	.loc 1 831 5 view .LVU9514
	.loc 1 831 15 is_stmt 0 view .LVU9515
	movapd	%xmm2, %xmm0
.LVL2324:
	.loc 1 831 15 view .LVU9516
	movsd	%xmm2, -208(%rbp)
	call	sin
.LVL2325:
	.loc 1 831 15 view .LVU9517
.LBE7018:
.LBE7017:
.LBB7020:
.LBB7021:
	.loc 1 866 19 view .LVU9518
	movsd	-208(%rbp), %xmm2
.LBE7021:
.LBE7020:
.LBB7030:
.LBB7019:
	.loc 1 831 15 view .LVU9519
	movq	%xmm0, %r13
.LVL2326:
	.loc 1 831 15 view .LVU9520
.LBE7019:
.LBE7030:
	.loc 1 33533 5 is_stmt 1 view .LVU9521
.LBB7031:
.LBI7020:
	.loc 1 864 25 view .LVU9522
.LBB7028:
	.loc 1 866 5 view .LVU9523
.LBB7022:
.LBI7022:
	.loc 1 828 25 view .LVU9524
.LBB7023:
	.loc 1 831 5 view .LVU9525
.LBE7023:
.LBE7022:
	.loc 1 866 19 is_stmt 0 view .LVU9526
	movsd	.LC116(%rip), %xmm0
.LVL2327:
	.loc 1 866 19 view .LVU9527
	subsd	%xmm2, %xmm0
.LVL2328:
.LBB7026:
.LBB7024:
	.loc 1 831 15 view .LVU9528
	call	sin
.LVL2329:
	.loc 1 831 15 view .LVU9529
.LBE7024:
.LBE7026:
.LBE7028:
.LBE7031:
	.loc 1 33534 7 view .LVU9530
	movsd	-216(%rbp), %xmm3
.LBE7033:
.LBE7038:
	.loc 1 33630 30 view .LVU9531
	movq	%rbx, %rsi
	leaq	-112(%rbp), %rdi
.LBB7039:
.LBB7034:
.LBB7032:
.LBB7029:
.LBB7027:
.LBB7025:
	.loc 1 831 15 view .LVU9532
	movapd	%xmm0, %xmm2
.LVL2330:
	.loc 1 831 15 view .LVU9533
.LBE7025:
.LBE7027:
.LBE7029:
.LBE7032:
	.loc 1 33534 5 is_stmt 1 view .LVU9534
	.loc 1 33534 11 is_stmt 0 view .LVU9535
	movq	%r13, %xmm0
.LVL2331:
	.loc 1 33536 27 view .LVU9536
	movsd	.LC117(%rip), %xmm1
	.loc 1 33536 27 view .LVU9537
.LBE7034:
.LBE7039:
	.loc 1 33629 50 view .LVU9538
	movq	-168(%rbp), %rax
.LBB7040:
.LBB7035:
	.loc 1 33534 11 view .LVU9539
	mulsd	.LC117(%rip), %xmm0
.LBE7035:
.LBE7040:
	.loc 1 33629 50 view .LVU9540
	movq	%rax, -112(%rbp)
.LBB7041:
.LBB7036:
	.loc 1 33534 7 view .LVU9541
	divsd	%xmm3, %xmm0
.LVL2332:
	.loc 1 33536 5 is_stmt 1 view .LVU9542
	.loc 1 33536 22 is_stmt 0 view .LVU9543
	movsd	.LC1(%rip), %xmm3
	movapd	%xmm3, %xmm5
	subsd	%xmm2, %xmm5
	.loc 1 33540 22 view .LVU9544
	mulsd	.LC119(%rip), %xmm2
.LVL2333:
	.loc 1 33536 27 view .LVU9545
	mulsd	%xmm5, %xmm1
	.loc 1 33537 5 is_stmt 1 view .LVU9546
	.loc 1 33538 5 view .LVU9547
	.loc 1 33539 5 view .LVU9548
	.loc 1 33540 5 view .LVU9549
	.loc 1 33541 5 view .LVU9550
	.loc 1 33543 5 view .LVU9551
	.loc 1 33544 5 view .LVU9552
	.loc 1 33546 5 view .LVU9553
.LVL2334:
	.loc 1 33546 5 is_stmt 0 view .LVU9554
.LBE7036:
.LBE7041:
	.loc 1 33629 50 view .LVU9555
	movsd	%xmm5, -96(%rbp)
	movsd	%xmm2, -72(%rbp)
	movsd	%xmm1, -104(%rbp)
	movsd	%xmm1, -88(%rbp)
.LBB7042:
.LBB7037:
	.loc 1 33539 22 view .LVU9556
	movapd	%xmm0, %xmm1
	addsd	%xmm3, %xmm1
	.loc 1 33541 22 view .LVU9557
	subsd	%xmm0, %xmm3
.LBE7037:
.LBE7042:
	.loc 1 33629 50 view .LVU9558
	movsd	%xmm1, -80(%rbp)
	movsd	%xmm3, -64(%rbp)
	.loc 1 33630 5 is_stmt 1 view .LVU9559
	.loc 1 33630 30 is_stmt 0 view .LVU9560
	call	ma_biquad_reinit
.LVL2335:
	movl	%eax, %ebx
.LVL2336:
	.loc 1 33631 5 is_stmt 1 view .LVU9561
	testl	%eax, %eax
	je	.L1542
.LVL2337:
.L1659:
	.loc 1 33631 5 is_stmt 0 view .LVU9562
	movq	-184(%rbp), %r12
.LVL2338:
.L1537:
	.loc 1 33631 5 view .LVU9563
.LBE7045:
.LBE7051:
.LBE7081:
.LBB7082:
	.loc 1 33882 24 view .LVU9564
	xorl	%r14d, %r14d
.LVL2339:
	.p2align 4,,10
	.p2align 3
.L1548:
	.loc 1 33882 35 is_stmt 1 discriminator 1 view .LVU9565
	cmpl	-172(%rbp), %r14d
	jnb	.L1547
.L1663:
	.loc 1 33883 17 view .LVU9566
	.loc 1 33883 39 is_stmt 0 view .LVU9567
	movq	24(%r12), %rax
.LVL2340:
.LBB7083:
.LBI7083:
	.loc 1 33371 13 is_stmt 1 view .LVU9568
.LBB7084:
	.loc 1 33373 5 view .LVU9569
.LBE7084:
.LBE7083:
	.loc 1 33882 54 is_stmt 0 view .LVU9570
	movl	$1, %r14d
.LVL2341:
.LBB7090:
.LBB7089:
	.loc 1 33373 5 view .LVU9571
	testq	%rax, %rax
	je	.L1548
	.loc 1 33377 5 is_stmt 1 view .LVU9572
	movl	32(%rax), %edi
	testl	%edi, %edi
	je	.L1548
	.loc 1 33378 9 view .LVU9573
	.loc 1 33378 16 is_stmt 0 view .LVU9574
	movq	24(%rax), %rdi
.LVL2342:
.LBB7085:
.LBI7085:
	.loc 1 44086 13 is_stmt 1 view .LVU9575
.LBB7086:
	.loc 1 44088 5 view .LVU9576
	testq	%rdi, %rdi
	je	.L1548
	.loc 1 44092 5 view .LVU9577
	.loc 1 44099 9 view .LVU9578
.LVL2343:
.LBB7087:
.LBI7087:
	.loc 1 1893 13 view .LVU9579
.LBB7088:
	.loc 1 1895 5 view .LVU9580
	.loc 1 1896 5 view .LVU9581
	call	free
.LVL2344:
	.loc 1 1896 5 is_stmt 0 view .LVU9582
.LBE7088:
.LBE7087:
.LBE7086:
.LBE7085:
.LBE7089:
.LBE7090:
	.loc 1 33882 35 is_stmt 1 view .LVU9583
	cmpl	-172(%rbp), %r14d
	jb	.L1663
.LVL2345:
.L1547:
	.loc 1 33886 35 view .LVU9584
	testl	%r15d, %r15d
	je	.L1495
	.loc 1 33887 17 view .LVU9585
	.loc 1 33887 39 is_stmt 0 view .LVU9586
	movq	32(%r12), %rax
.LVL2346:
.LBB7091:
.LBI7091:
	.loc 1 33611 13 is_stmt 1 view .LVU9587
.LBB7092:
	.loc 1 33613 5 view .LVU9588
	testq	%rax, %rax
	je	.L1553
	.loc 1 33617 5 view .LVU9589
.LVL2347:
.LBB7093:
.LBI7093:
	.loc 1 33042 13 view .LVU9590
.LBB7094:
	.loc 1 33044 5 view .LVU9591
	.loc 1 33048 5 view .LVU9592
	movl	56(%rax), %esi
	testl	%esi, %esi
	jne	.L1664
.LVL2348:
.L1553:
	.loc 1 33048 5 is_stmt 0 view .LVU9593
.LBE7094:
.LBE7093:
.LBE7092:
.LBE7091:
	.loc 1 33886 13 is_stmt 1 view .LVU9594
	.loc 1 33886 35 view .LVU9595
	cmpl	$1, %r15d
	je	.L1495
	.loc 1 33887 17 view .LVU9596
	.loc 1 33887 39 is_stmt 0 view .LVU9597
	movq	32(%r12), %rax
.LVL2349:
.LBB7116:
	.loc 1 33611 13 is_stmt 1 view .LVU9598
.LBB7113:
	.loc 1 33613 5 view .LVU9599
	.loc 1 33617 5 view .LVU9600
.LBB7110:
	.loc 1 33042 13 view .LVU9601
.LBB7107:
	.loc 1 33044 5 view .LVU9602
	.loc 1 33048 5 view .LVU9603
	movl	120(%rax), %ecx
	testl	%ecx, %ecx
	jne	.L1665
.LVL2350:
.L1555:
	.loc 1 33048 5 is_stmt 0 view .LVU9604
.LBE7107:
.LBE7110:
.LBE7113:
.LBE7116:
	.loc 1 33886 13 is_stmt 1 view .LVU9605
	.loc 1 33886 35 view .LVU9606
	cmpl	$2, %r15d
	je	.L1495
	.loc 1 33887 17 view .LVU9607
	.loc 1 33887 39 is_stmt 0 view .LVU9608
	movq	32(%r12), %rax
.LVL2351:
.LBB7117:
	.loc 1 33611 13 is_stmt 1 view .LVU9609
.LBB7114:
	.loc 1 33613 5 view .LVU9610
	.loc 1 33617 5 view .LVU9611
.LBB7111:
	.loc 1 33042 13 view .LVU9612
.LBB7108:
	.loc 1 33044 5 view .LVU9613
	.loc 1 33048 5 view .LVU9614
	movl	184(%rax), %edx
	testl	%edx, %edx
	je	.L1495
	.loc 1 33049 9 view .LVU9615
	.loc 1 33049 16 is_stmt 0 view .LVU9616
	movq	176(%rax), %rdi
.LVL2352:
.LBB7095:
.LBI7095:
	.loc 1 44086 13 is_stmt 1 view .LVU9617
.LBB7096:
	.loc 1 44088 5 view .LVU9618
	testq	%rdi, %rdi
	je	.L1495
	.loc 1 44092 5 view .LVU9619
	.loc 1 44099 9 view .LVU9620
.LVL2353:
.LBB7097:
.LBI7097:
	.loc 1 1893 13 view .LVU9621
.LBB7098:
	.loc 1 1895 5 view .LVU9622
	.loc 1 1896 5 view .LVU9623
	call	free
.LVL2354:
	.loc 1 1896 5 is_stmt 0 view .LVU9624
	jmp	.L1495
.LVL2355:
	.p2align 4,,10
	.p2align 3
.L1658:
	.loc 1 1896 5 view .LVU9625
.LBE7098:
.LBE7097:
.LBE7096:
.LBE7095:
.LBE7108:
.LBE7111:
.LBE7114:
.LBE7117:
.LBE7082:
.LBE7130:
.LBE7146:
.LBB7147:
.LBB6842:
.LBB6833:
.LBB6823:
.LBB6745:
	.loc 1 33410 9 is_stmt 1 view .LVU9626
	.loc 1 33410 23 is_stmt 0 view .LVU9627
	cvtsd2ss	%xmm0, %xmm0
.LVL2356:
	.loc 1 33410 23 view .LVU9628
	movss	%xmm0, 8(%rax)
.LVL2357:
	.loc 1 33410 23 view .LVU9629
.LBE6745:
.LBE6823:
.LBE6833:
	.loc 1 33841 9 is_stmt 1 view .LVU9630
	jmp	.L1525
.LVL2358:
	.p2align 4,,10
	.p2align 3
.L1662:
.LBB6834:
.LBB6824:
.LBB6819:
.LBB6809:
.LBB6802:
.LBB6798:
	.loc 1 33410 9 view .LVU9631
.LBE6798:
.LBE6802:
.LBE6809:
.LBE6819:
.LBE6824:
.LBE6834:
.LBE6842:
.LBE7147:
	.loc 1 33897 33 is_stmt 0 view .LVU9632
	movl	4(%r13), %ebx
	movd	0(%r13), %xmm1
.LBB7148:
.LBB6843:
.LBB6835:
.LBB6825:
.LBB6820:
.LBB6810:
.LBB6803:
.LBB6799:
	.loc 1 33410 23 view .LVU9633
	cvtsd2ss	%xmm0, %xmm0
.LVL2359:
	.loc 1 33410 23 view .LVU9634
	movss	%xmm0, 8(%r9)
.LVL2360:
	.loc 1 33410 23 view .LVU9635
.LBE6799:
.LBE6803:
.LBE6810:
.LBE6820:
.LBE6825:
.LBE6835:
	.loc 1 33841 9 is_stmt 1 view .LVU9636
.LBE6843:
.LBE7148:
	.loc 1 33898 33 is_stmt 0 view .LVU9637
	movl	8(%r13), %r14d
	movd	%ebx, %xmm7
	punpckldq	%xmm7, %xmm1
	jmp	.L1525
.LVL2361:
	.p2align 4,,10
	.p2align 3
.L1648:
	.loc 1 33898 33 view .LVU9638
	movd	%r15d, %xmm1
	movd	%ebx, %xmm4
	movq	-184(%rbp), %r12
.LVL2362:
	.loc 1 33898 33 view .LVU9639
	movl	%r13d, %r14d
	punpckldq	%xmm4, %xmm1
.LVL2363:
.L1506:
	.loc 1 33894 5 is_stmt 1 view .LVU9640
	.loc 1 33895 5 view .LVU9641
	.loc 1 33896 22 is_stmt 0 view .LVU9642
	movd	-172(%rbp), %xmm7
	movd	%r14d, %xmm0
	.loc 1 33895 22 view .LVU9643
	movl	-188(%rbp), %eax
	.loc 1 33900 12 view .LVU9644
	xorl	%ebx, %ebx
	.loc 1 33896 22 view .LVU9645
	punpckldq	%xmm7, %xmm0
	.loc 1 33895 22 view .LVU9646
	movl	%eax, 16(%r12)
	.loc 1 33896 5 is_stmt 1 view .LVU9647
	.loc 1 33897 5 view .LVU9648
	.loc 1 33898 5 view .LVU9649
	.loc 1 33896 22 is_stmt 0 view .LVU9650
	punpcklqdq	%xmm0, %xmm1
	movups	%xmm1, (%r12)
	.loc 1 33900 5 is_stmt 1 view .LVU9651
	.loc 1 33900 12 is_stmt 0 view .LVU9652
	jmp	.L1495
.LVL2364:
	.p2align 4,,10
	.p2align 3
.L1661:
.LBB7149:
.LBB7141:
	.loc 1 782 9 is_stmt 1 view .LVU9653
	.loc 1 782 15 is_stmt 0 view .LVU9654
	xorl	%esi, %esi
	movq	%rax, %rdi
	call	memset
.LVL2365:
	.loc 1 782 15 view .LVU9655
	jmp	.L1502
.LVL2366:
.L1653:
	.loc 1 782 15 view .LVU9656
.LBE7141:
.LBE7149:
.LBB7150:
.LBB7131:
.LBB7119:
.LBB7052:
.LBB7046:
	.loc 1 33626 16 view .LVU9657
	movq	%rax, %r12
.LVL2367:
	.loc 1 33626 16 view .LVU9658
.LBE7046:
.LBE7052:
.LBE7119:
	.loc 1 33878 9 is_stmt 1 view .LVU9659
.LBB7120:
.LBB7053:
.LBB7047:
	.loc 1 33626 16 is_stmt 0 view .LVU9660
	movl	$-2, %ebx
	jmp	.L1537
.LVL2368:
.L1652:
	.loc 1 33626 16 view .LVU9661
	movd	%ebx, %xmm6
	punpckldq	%xmm6, %xmm1
	jmp	.L1525
.LVL2369:
.L1664:
	.loc 1 33626 16 view .LVU9662
.LBE7047:
.LBE7053:
.LBE7120:
.LBB7121:
.LBB7118:
.LBB7115:
.LBB7112:
.LBB7109:
	.loc 1 33049 9 is_stmt 1 view .LVU9663
	.loc 1 33049 16 is_stmt 0 view .LVU9664
	movq	48(%rax), %rdi
.LVL2370:
.LBB7105:
	.loc 1 44086 13 is_stmt 1 view .LVU9665
.LBB7103:
	.loc 1 44088 5 view .LVU9666
	testq	%rdi, %rdi
	je	.L1553
	.loc 1 44092 5 view .LVU9667
	.loc 1 44099 9 view .LVU9668
.LVL2371:
.LBB7101:
	.loc 1 1893 13 view .LVU9669
.LBB7099:
	.loc 1 1895 5 view .LVU9670
	.loc 1 1896 5 view .LVU9671
	call	free
.LVL2372:
	.loc 1 1896 5 is_stmt 0 view .LVU9672
	jmp	.L1553
.LVL2373:
.L1665:
	.loc 1 1896 5 view .LVU9673
.LBE7099:
.LBE7101:
.LBE7103:
.LBE7105:
	.loc 1 33049 9 is_stmt 1 view .LVU9674
	.loc 1 33049 16 is_stmt 0 view .LVU9675
	movq	112(%rax), %rdi
.LVL2374:
.LBB7106:
	.loc 1 44086 13 is_stmt 1 view .LVU9676
.LBB7104:
	.loc 1 44088 5 view .LVU9677
	testq	%rdi, %rdi
	je	.L1555
	.loc 1 44092 5 view .LVU9678
	.loc 1 44099 9 view .LVU9679
.LVL2375:
.LBB7102:
	.loc 1 1893 13 view .LVU9680
.LBB7100:
	.loc 1 1895 5 view .LVU9681
	.loc 1 1896 5 view .LVU9682
	call	free
.LVL2376:
	.loc 1 1896 5 is_stmt 0 view .LVU9683
	jmp	.L1555
.LVL2377:
.L1654:
	.loc 1 1896 5 view .LVU9684
.LBE7100:
.LBE7102:
.LBE7104:
.LBE7106:
.LBE7109:
.LBE7112:
.LBE7115:
.LBE7118:
.LBE7121:
.LBB7122:
.LBB7054:
.LBB7004:
.LBB6980:
.LBB6963:
.LBB6948:
.LBB6939:
.LBB6927:
	.loc 1 32947 16 view .LVU9685
	movq	-184(%rbp), %r12
.LVL2378:
	.loc 1 32947 16 view .LVU9686
.LBE6927:
.LBE6939:
	.loc 1 32999 5 is_stmt 1 view .LVU9687
	.loc 1 32999 5 is_stmt 0 view .LVU9688
.LBE6948:
.LBE6963:
	.loc 1 33574 5 is_stmt 1 view .LVU9689
	.loc 1 33575 9 view .LVU9690
	.loc 1 33575 9 is_stmt 0 view .LVU9691
.LBE6980:
.LBE7004:
.LBE7054:
.LBE7122:
	.loc 1 33878 9 is_stmt 1 view .LVU9692
.LBB7123:
.LBB7055:
.LBB7005:
.LBB6981:
.LBB6964:
.LBB6949:
.LBB6940:
.LBB6928:
	.loc 1 32947 16 is_stmt 0 view .LVU9693
	movl	$-2, %ebx
	jmp	.L1537
.LBE6928:
.LBE6940:
.LBE6949:
.LBE6964:
.LBE6981:
.LBE7005:
.LBE7055:
.LBE7123:
.LBE7131:
.LBE7150:
	.cfi_endproc
.LFE163:
	.size	_ZL23ma_lpf_reinit__internalPK13ma_lpf_configPvP6ma_lpfj, .-_ZL23ma_lpf_reinit__internalPK13ma_lpf_configPvP6ma_lpfj
	.p2align 4
	.type	_ZL43ma_resampling_backend_get_heap_size__linearPvPK19ma_resampler_configPm, @function
_ZL43ma_resampling_backend_get_heap_size__linearPvPK19ma_resampler_configPm:
.LVL2379:
.LFB170:
	.loc 1 39231 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 39231 1 is_stmt 0 view .LVU9695
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$96, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
1:	call	mcount
	.loc 1 39231 1 view .LVU9696
	.loc 1 39232 5 is_stmt 1 view .LVU9697
	.loc 1 39234 5 view .LVU9698
	.loc 1 39236 5 view .LVU9699
.LVL2380:
.LBB7170:
.LBI7170:
	.loc 1 39220 35 view .LVU9700
.LBB7171:
	.loc 1 39222 5 view .LVU9701
	.loc 1 39224 5 view .LVU9702
	.loc 1 39224 61 is_stmt 0 view .LVU9703
	movl	(%rsi), %edi
.LVL2381:
	.loc 1 39225 45 view .LVU9704
	movl	40(%rsi), %eax
.LBE7171:
.LBE7170:
	.loc 1 39231 1 view .LVU9705
	movq	%rdx, %r12
.LBB7178:
.LBB7176:
	.loc 1 39224 78 view .LVU9706
	movl	4(%rsi), %edx
.LVL2382:
.LBB7172:
.LBI7172:
	.loc 1 38406 35 is_stmt 1 view .LVU9707
.LBB7173:
	.loc 1 38408 5 view .LVU9708
	.loc 1 38409 5 view .LVU9709
	.loc 1 38409 5 is_stmt 0 view .LVU9710
.LBE7173:
.LBE7172:
.LBE7176:
.LBE7178:
	.loc 1 781 5 is_stmt 1 view .LVU9711
	.loc 1 782 9 view .LVU9712
.LBB7179:
.LBB7177:
.LBB7175:
.LBB7174:
	.loc 1 38410 5 view .LVU9713
	.loc 1 38411 5 view .LVU9714
	.loc 1 38412 5 view .LVU9715
	.loc 1 38413 5 view .LVU9716
	.loc 1 38414 5 view .LVU9717
	.loc 1 38415 5 view .LVU9718
	.loc 1 38417 5 view .LVU9719
	.loc 1 38417 5 is_stmt 0 view .LVU9720
.LBE7174:
.LBE7175:
	.loc 1 39225 5 is_stmt 1 view .LVU9721
	.loc 1 39227 5 view .LVU9722
	.loc 1 39227 5 is_stmt 0 view .LVU9723
.LBE7177:
.LBE7179:
	.loc 1 39238 5 is_stmt 1 view .LVU9724
.LBB7180:
.LBI7180:
	.loc 1 38566 18 view .LVU9725
.LBB7181:
	.loc 1 38568 5 view .LVU9726
	.loc 1 38569 5 view .LVU9727
	.loc 1 38571 5 view .LVU9728
	testq	%r12, %r12
	je	.L1673
	.loc 1 38575 5 view .LVU9729
.LBB7182:
.LBB7183:
.LBB7184:
.LBB7185:
	.loc 1 782 15 is_stmt 0 view .LVU9730
	pxor	%xmm0, %xmm0
.LBE7185:
.LBE7184:
.LBE7183:
.LBE7182:
	.loc 1 38575 23 view .LVU9731
	movq	$0, (%r12)
	.loc 1 38577 5 is_stmt 1 view .LVU9732
.LVL2383:
.LBB7218:
.LBI7182:
	.loc 1 38509 18 view .LVU9733
.LBB7215:
	.loc 1 38511 5 view .LVU9734
	.loc 1 38513 5 view .LVU9735
.LBB7187:
.LBI7184:
	.loc 1 776 23 view .LVU9736
.LBB7186:
	.loc 1 781 5 view .LVU9737
	.loc 1 782 9 view .LVU9738
	.loc 1 782 15 is_stmt 0 view .LVU9739
	movups	%xmm0, -80(%rbp)
.LVL2384:
	.loc 1 782 15 view .LVU9740
.LBE7186:
.LBE7187:
	.loc 1 38515 5 is_stmt 1 view .LVU9741
	.loc 1 38519 5 view .LVU9742
	cmpl	$5, %edi
	je	.L1682
	.loc 1 38523 5 view .LVU9743
	testl	%edx, %edx
	je	.L1673
	cmpl	$2, %edi
	jne	.L1673
	.loc 1 38527 5 view .LVU9744
	.loc 1 38530 5 view .LVU9745
	.loc 1 38531 5 view .LVU9746
	.loc 1 38534 9 view .LVU9747
	.loc 1 38534 65 is_stmt 0 view .LVU9748
	movl	%edx, %ebx
	.loc 1 38538 5 is_stmt 1 view .LVU9749
	.loc 1 38534 54 is_stmt 0 view .LVU9750
	leaq	(%rbx,%rbx), %rcx
	.loc 1 38542 34 view .LVU9751
	salq	$2, %rbx
	.loc 1 38534 54 view .LVU9752
	movq	%rcx, -64(%rbp)
	.loc 1 38539 5 is_stmt 1 view .LVU9753
	.loc 1 38542 9 view .LVU9754
	.loc 1 38542 34 is_stmt 0 view .LVU9755
	movq	%rbx, -80(%rbp)
.L1671:
	.loc 1 38546 5 is_stmt 1 view .LVU9756
	.loc 1 38546 30 is_stmt 0 view .LVU9757
	leaq	7(%rbx), %rcx
.LBB7188:
.LBB7189:
.LBB7190:
	.loc 1 33683 28 view .LVU9758
	movl	%edi, -48(%rbp)
.LBB7191:
.LBB7192:
	.loc 1 782 15 view .LVU9759
	pxor	%xmm0, %xmm0
.LBE7192:
.LBE7191:
.LBE7190:
.LBE7189:
.LBB7203:
.LBB7204:
	.loc 1 33914 36 view .LVU9760
	leaq	-112(%rbp), %rsi
.LVL2385:
	.loc 1 33914 36 view .LVU9761
.LBE7204:
.LBE7203:
.LBB7207:
.LBB7199:
	.loc 1 33686 28 view .LVU9762
	movq	.LC1(%rip), %rdi
.LBE7199:
.LBE7207:
.LBE7188:
	.loc 1 38546 30 view .LVU9763
	andq	$-8, %rcx
.LBB7213:
.LBB7208:
.LBB7200:
	.loc 1 33684 28 view .LVU9764
	movl	%edx, -44(%rbp)
	.loc 1 33687 30 view .LVU9765
	cmpl	$8, %eax
	movl	$8, %edx
.LBB7196:
.LBB7193:
	.loc 1 782 15 view .LVU9766
	movups	%xmm0, -40(%rbp)
.LBE7193:
.LBE7196:
	.loc 1 33687 30 view .LVU9767
	cmova	%edx, %eax
	.loc 1 33686 28 view .LVU9768
	movq	%rdi, -32(%rbp)
.LBE7200:
.LBE7208:
.LBB7209:
.LBB7205:
	.loc 1 33914 36 view .LVU9769
	leaq	-48(%rbp), %rdi
.LBE7205:
.LBE7209:
.LBB7210:
.LBB7201:
.LBB7197:
.LBB7194:
	.loc 1 782 15 view .LVU9770
	movq	$0, -24(%rbp)
.LBE7194:
.LBE7197:
.LBE7201:
.LBE7210:
.LBE7213:
	.loc 1 38546 30 view .LVU9771
	movq	%rcx, -56(%rbp)
	.loc 1 38547 5 is_stmt 1 view .LVU9772
.LBB7214:
	.loc 1 38548 9 view .LVU9773
	.loc 1 38549 9 view .LVU9774
	.loc 1 38550 9 view .LVU9775
.LVL2386:
.LBB7211:
.LBI7189:
	.loc 1 33678 22 view .LVU9776
.LBB7202:
	.loc 1 33680 5 view .LVU9777
	.loc 1 33682 5 view .LVU9778
.LBB7198:
.LBI7191:
	.loc 1 776 23 view .LVU9779
.LBB7195:
	.loc 1 781 5 view .LVU9780
	.loc 1 782 9 view .LVU9781
	.loc 1 782 9 is_stmt 0 view .LVU9782
.LBE7195:
.LBE7198:
	.loc 1 33683 5 is_stmt 1 view .LVU9783
	.loc 1 33684 5 view .LVU9784
	.loc 1 33685 5 view .LVU9785
	.loc 1 33685 28 is_stmt 0 view .LVU9786
	movl	$1, -40(%rbp)
	.loc 1 33686 5 is_stmt 1 view .LVU9787
	.loc 1 33687 5 view .LVU9788
	.loc 1 33687 28 is_stmt 0 view .LVU9789
	movl	%eax, -24(%rbp)
	.loc 1 33689 5 is_stmt 1 view .LVU9790
.LVL2387:
	.loc 1 33689 5 is_stmt 0 view .LVU9791
.LBE7202:
.LBE7211:
	.loc 1 38552 9 is_stmt 1 view .LVU9792
.LBB7212:
.LBI7203:
	.loc 1 33903 18 view .LVU9793
.LBB7206:
	.loc 1 33905 5 view .LVU9794
	.loc 1 33906 5 view .LVU9795
	.loc 1 33908 5 view .LVU9796
	.loc 1 33912 5 view .LVU9797
	.loc 1 33914 5 view .LVU9798
	.loc 1 33914 36 is_stmt 0 view .LVU9799
	call	_ZL22ma_lpf_get_heap_layoutPK13ma_lpf_configP18ma_lpf_heap_layout.lto_priv.0
.LVL2388:
	.loc 1 33915 5 is_stmt 1 view .LVU9800
	testl	%eax, %eax
	jne	.L1666
	.loc 1 33919 5 view .LVU9801
.LVL2389:
	.loc 1 33921 5 view .LVU9802
	.loc 1 33921 5 is_stmt 0 view .LVU9803
.LBE7206:
.LBE7212:
	.loc 1 38553 9 is_stmt 1 view .LVU9804
	.loc 1 38557 9 view .LVU9805
	.loc 1 38557 9 is_stmt 0 view .LVU9806
.LBE7214:
	.loc 1 38561 5 is_stmt 1 view .LVU9807
	.loc 1 38563 5 view .LVU9808
	.loc 1 38563 5 is_stmt 0 view .LVU9809
.LBE7215:
.LBE7218:
	.loc 1 38578 5 is_stmt 1 view .LVU9810
	.loc 1 38582 5 view .LVU9811
.LBB7219:
.LBB7216:
	.loc 1 38561 32 is_stmt 0 view .LVU9812
	movq	-112(%rbp), %rdx
	leaq	7(%rbx,%rdx), %rdx
	andq	$-8, %rdx
	movq	%rdx, (%r12)
.LBE7216:
.LBE7219:
	.loc 1 38584 5 is_stmt 1 view .LVU9813
.LVL2390:
.L1666:
	.loc 1 38584 5 is_stmt 0 view .LVU9814
.LBE7181:
.LBE7180:
	.loc 1 39239 1 view .LVU9815
	addq	$96, %rsp
	popq	%rbx
	popq	%r12
.LVL2391:
	.loc 1 39239 1 view .LVU9816
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL2392:
	.p2align 4,,10
	.p2align 3
.L1682:
	.cfi_restore_state
.LBB7222:
.LBB7221:
.LBB7220:
.LBB7217:
	.loc 1 38523 5 is_stmt 1 view .LVU9817
	testl	%edx, %edx
	je	.L1673
	.loc 1 38527 5 view .LVU9818
	.loc 1 38530 5 view .LVU9819
	.loc 1 38531 5 view .LVU9820
	.loc 1 38532 9 view .LVU9821
	.loc 1 38532 62 is_stmt 0 view .LVU9822
	movl	%edx, %ebx
	.loc 1 38538 5 is_stmt 1 view .LVU9823
	.loc 1 38532 51 is_stmt 0 view .LVU9824
	leaq	0(,%rbx,4), %rcx
	.loc 1 38540 34 view .LVU9825
	salq	$3, %rbx
	.loc 1 38532 51 view .LVU9826
	movq	%rcx, -64(%rbp)
	.loc 1 38539 5 is_stmt 1 view .LVU9827
	.loc 1 38540 9 view .LVU9828
	.loc 1 38540 34 is_stmt 0 view .LVU9829
	movq	%rbx, -80(%rbp)
	jmp	.L1671
.LVL2393:
	.p2align 4,,10
	.p2align 3
.L1673:
	.loc 1 38540 34 view .LVU9830
.LBE7217:
.LBE7220:
	.loc 1 38572 16 view .LVU9831
	movl	$-2, %eax
	jmp	.L1666
.LBE7221:
.LBE7222:
	.cfi_endproc
.LFE170:
	.size	_ZL43ma_resampling_backend_get_heap_size__linearPvPK19ma_resampler_configPm, .-_ZL43ma_resampling_backend_get_heap_size__linearPvPK19ma_resampler_configPm
	.p2align 4
	.globl	_ZL30ma_spatializer_get_heap_layoutPK21ma_spatializer_configP26ma_spatializer_heap_layout.lto_priv.0
	.hidden	_ZL30ma_spatializer_get_heap_layoutPK21ma_spatializer_configP26ma_spatializer_heap_layout.lto_priv.0
	.type	_ZL30ma_spatializer_get_heap_layoutPK21ma_spatializer_configP26ma_spatializer_heap_layout.lto_priv.0, @function
_ZL30ma_spatializer_get_heap_layoutPK21ma_spatializer_configP26ma_spatializer_heap_layout.lto_priv.0:
.LVL2394:
.LFB173:
	.loc 1 37512 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 37512 1 is_stmt 0 view .LVU9833
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
1:	call	mcount
	.loc 1 37512 1 view .LVU9834
	.loc 1 37513 5 is_stmt 1 view .LVU9835
	.loc 1 37515 5 view .LVU9836
	.loc 1 37517 5 view .LVU9837
.LVL2395:
.LBB7240:
.LBI7240:
	.loc 1 776 23 view .LVU9838
.LBB7241:
	.loc 1 781 5 view .LVU9839
	.loc 1 782 9 view .LVU9840
	.loc 1 782 15 is_stmt 0 view .LVU9841
	pxor	%xmm0, %xmm0
	movups	%xmm0, (%rsi)
	movups	%xmm0, 16(%rsi)
.LVL2396:
	.loc 1 782 15 view .LVU9842
.LBE7241:
.LBE7240:
	.loc 1 37519 5 is_stmt 1 view .LVU9843
	.loc 1 37523 5 view .LVU9844
.LBB7242:
.LBI7242:
	.loc 1 37492 18 view .LVU9845
.LBB7243:
	.loc 1 37494 5 view .LVU9846
	.loc 1 37496 5 view .LVU9847
	.loc 1 37496 18 is_stmt 0 view .LVU9848
	movl	(%rdi), %eax
	.loc 1 37496 5 view .LVU9849
	testl	%eax, %eax
	je	.L1687
	.loc 1 37496 46 view .LVU9850
	movl	4(%rdi), %edx
	.loc 1 37496 34 view .LVU9851
	testl	%edx, %edx
	je	.L1687
.LVL2397:
	.loc 1 37496 34 view .LVU9852
.LBE7243:
.LBE7242:
	.loc 1 37524 5 is_stmt 1 view .LVU9853
	.loc 1 37528 5 view .LVU9854
	.loc 1 37531 5 view .LVU9855
	.loc 1 37531 37 is_stmt 0 view .LVU9856
	movl	$4294967295, %ecx
	movq	%rcx, 8(%rsi)
	.loc 1 37532 5 is_stmt 1 view .LVU9857
	xorl	%ecx, %ecx
	cmpq	$0, 8(%rdi)
	je	.L1685
	.loc 1 37533 9 view .LVU9858
	.loc 1 37534 37 is_stmt 0 view .LVU9859
	addq	$7, %rax
	.loc 1 37533 41 view .LVU9860
	movq	$0, 8(%rsi)
	.loc 1 37534 9 is_stmt 1 view .LVU9861
	.loc 1 37534 37 is_stmt 0 view .LVU9862
	andq	$-8, %rax
	movq	%rax, %rcx
.L1685:
.LVL2398:
.LBB7245:
.LBI7245:
	.loc 1 37511 18 is_stmt 1 view .LVU9863
.LBB7246:
	.loc 1 37539 33 is_stmt 0 view .LVU9864
	leaq	7(,%rdx,4), %rax
	.loc 1 37538 40 view .LVU9865
	movq	%rcx, 16(%rsi)
.LBE7246:
.LBE7245:
	.loc 1 37558 1 view .LVU9866
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
.LBB7259:
.LBB7257:
	.loc 1 37539 33 view .LVU9867
	andq	$-8, %rax
	.loc 1 37539 30 view .LVU9868
	addq	%rcx, %rax
.LVL2399:
.LBB7247:
.LBB7248:
.LBB7249:
.LBB7250:
.LBI7250:
	.loc 1 36297 18 is_stmt 1 view .LVU9869
.LBB7251:
	.loc 1 36299 5 view .LVU9870
	.loc 1 36301 5 view .LVU9871
	.loc 1 36301 5 is_stmt 0 view .LVU9872
.LBE7251:
.LBE7250:
.LBE7249:
.LBE7248:
.LBE7247:
.LBE7257:
.LBE7259:
	.loc 1 781 5 is_stmt 1 view .LVU9873
	.loc 1 782 9 view .LVU9874
.LBB7260:
.LBB7258:
.LBB7256:
.LBB7255:
.LBB7254:
.LBB7253:
.LBB7252:
	.loc 1 36303 5 view .LVU9875
	.loc 1 36307 5 view .LVU9876
	.loc 1 36311 5 view .LVU9877
	.loc 1 36314 5 view .LVU9878
	.loc 1 36315 5 view .LVU9879
	.loc 1 36318 5 view .LVU9880
	.loc 1 36319 5 view .LVU9881
	.loc 1 36322 5 view .LVU9882
	.loc 1 36324 5 view .LVU9883
	.loc 1 36324 5 is_stmt 0 view .LVU9884
.LBE7252:
.LBE7253:
.LBE7254:
.LBE7255:
	.loc 1 37553 35 view .LVU9885
	movq	%rax, 24(%rsi)
	.loc 1 37554 34 view .LVU9886
	leaq	(%rax,%rdx,8), %rax
	movq	%rax, (%rsi)
.LVL2400:
	.loc 1 37554 34 view .LVU9887
.LBE7256:
	.loc 1 37557 12 view .LVU9888
	xorl	%eax, %eax
.LBE7258:
.LBE7260:
	.loc 1 37558 1 view .LVU9889
	ret
.LVL2401:
	.p2align 4,,10
	.p2align 3
.L1687:
	.cfi_restore_state
.LBB7261:
.LBB7244:
	.loc 1 37497 16 view .LVU9890
	movl	$-2, %eax
.LVL2402:
	.loc 1 37497 16 view .LVU9891
.LBE7244:
.LBE7261:
	.loc 1 37558 1 view .LVU9892
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE173:
	.size	_ZL30ma_spatializer_get_heap_layoutPK21ma_spatializer_configP26ma_spatializer_heap_layout.lto_priv.0, .-_ZL30ma_spatializer_get_heap_layoutPK21ma_spatializer_configP26ma_spatializer_heap_layout.lto_priv.0
	.p2align 4
	.globl	_ZL37ma_linear_resampler_set_rate_internalP19ma_linear_resamplerPvP31ma_linear_resampler_heap_layoutjjj.lto_priv.0
	.hidden	_ZL37ma_linear_resampler_set_rate_internalP19ma_linear_resamplerPvP31ma_linear_resampler_heap_layoutjjj.lto_priv.0
	.type	_ZL37ma_linear_resampler_set_rate_internalP19ma_linear_resamplerPvP31ma_linear_resampler_heap_layoutjjj.lto_priv.0, @function
_ZL37ma_linear_resampler_set_rate_internalP19ma_linear_resamplerPvP31ma_linear_resampler_heap_layoutjjj.lto_priv.0:
.LVL2403:
.LFB176:
	.loc 1 38449 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 38449 1 is_stmt 0 view .LVU9894
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$64, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
1:	call	mcount
	.loc 1 38449 1 view .LVU9895
	.loc 1 38450 5 is_stmt 1 view .LVU9896
	.loc 1 38451 5 view .LVU9897
	.loc 1 38452 5 view .LVU9898
	.loc 1 38453 5 view .LVU9899
	.loc 1 38454 5 view .LVU9900
	.loc 1 38455 5 view .LVU9901
	.loc 1 38457 5 view .LVU9902
	.loc 1 38449 1 is_stmt 0 view .LVU9903
	movq	%rdi, %rbx
	movq	%rdx, %r10
	movq	%rsi, %rdi
.LVL2404:
	.loc 1 38449 1 view .LVU9904
	movl	%ecx, %esi
.LVL2405:
	.loc 1 38457 5 view .LVU9905
	testq	%rbx, %rbx
	je	.L1692
	.loc 1 38461 5 is_stmt 1 view .LVU9906
	testl	%ecx, %ecx
	je	.L1692
	testl	%r8d, %r8d
	je	.L1692
	.loc 1 38465 5 view .LVU9907
	.loc 1 38465 22 is_stmt 0 view .LVU9908
	movl	%ecx, %eax
	movl	12(%rbx), %r12d
.LVL2406:
	.loc 1 38467 5 is_stmt 1 view .LVU9909
	.loc 1 38468 5 view .LVU9910
	.loc 1 38471 5 view .LVU9911
.LBB7278:
.LBI7278:
	.loc 1 2376 28 view .LVU9912
	.loc 1 2376 28 is_stmt 0 view .LVU9913
.LBE7278:
	.loc 1 2378 5 is_stmt 1 view .LVU9914
	.loc 1 2379 9 view .LVU9915
	.loc 1 38465 22 is_stmt 0 view .LVU9916
	movl	%r8d, %ecx
.LVL2407:
	.loc 1 38465 22 view .LVU9917
	jmp	.L1693
.LVL2408:
	.p2align 4,,10
	.p2align 3
.L1702:
.LBB7284:
.LBB7279:
.LBB7280:
	.loc 1 38465 22 view .LVU9918
	movl	%edx, %ecx
.LVL2409:
.L1693:
.LBB7281:
	.loc 1 2382 13 is_stmt 1 view .LVU9919
	.loc 1 2383 13 view .LVU9920
	.loc 1 2384 13 view .LVU9921
	.loc 1 2384 15 is_stmt 0 view .LVU9922
	xorl	%edx, %edx
	divl	%ecx
.LVL2410:
	.loc 1 2384 15 view .LVU9923
.LBE7281:
.LBE7280:
	.loc 1 2378 5 is_stmt 1 view .LVU9924
	.loc 1 2378 5 is_stmt 0 view .LVU9925
.LBE7279:
.LBE7284:
	.loc 1 2378 5 is_stmt 1 view .LVU9926
	.loc 1 2379 9 view .LVU9927
	movl	%ecx, %eax
.LBB7285:
.LBB7283:
.LBB7282:
	testl	%edx, %edx
	jne	.L1702
.LVL2411:
	.loc 1 2379 9 is_stmt 0 view .LVU9928
.LBE7282:
.LBE7283:
.LBE7285:
	.loc 1 2388 5 is_stmt 1 view .LVU9929
	.loc 1 38472 5 view .LVU9930
	.loc 1 38472 38 is_stmt 0 view .LVU9931
	movl	%esi, %eax
.LVL2412:
	.loc 1 38472 38 view .LVU9932
	xorl	%edx, %edx
	divl	%ecx
	.loc 1 38473 38 view .LVU9933
	xorl	%edx, %edx
	.loc 1 38472 38 view .LVU9934
	movl	%eax, %esi
.LVL2413:
	.loc 1 38473 5 is_stmt 1 view .LVU9935
	.loc 1 38473 38 is_stmt 0 view .LVU9936
	movl	%r8d, %eax
	divl	%ecx
	.loc 1 38472 38 view .LVU9937
	movd	%esi, %xmm0
	.loc 1 38473 38 view .LVU9938
	movl	%eax, %r8d
.LVL2414:
	.loc 1 38476 28 view .LVU9939
	movl	16(%rbx), %eax
	.loc 1 38472 38 view .LVU9940
	movd	%r8d, %xmm3
	punpckldq	%xmm3, %xmm0
	movq	%xmm0, 8(%rbx)
	.loc 1 38476 5 is_stmt 1 view .LVU9941
	cmpl	$8, %eax
	ja	.L1692
	.loc 1 38480 5 view .LVU9942
	cmpl	%r8d, %esi
	movl	%r8d, %edx
	cmovnb	%esi, %edx
.LVL2415:
	.loc 1 38481 5 view .LVU9943
	.loc 1 38481 112 is_stmt 0 view .LVU9944
	jb	.L1703
	.loc 1 38481 112 discriminator 2 view .LVU9945
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%r8, %xmm0
	mulsd	.LC117(%rip), %xmm0
.L1697:
	.loc 1 38481 24 discriminator 4 view .LVU9946
	mulsd	24(%rbx), %xmm0
.LVL2416:
	.loc 1 38483 5 is_stmt 1 discriminator 4 view .LVU9947
.LBB7286:
.LBI7286:
	.loc 1 33678 22 discriminator 4 view .LVU9948
.LBB7287:
	.loc 1 33680 5 discriminator 4 view .LVU9949
	.loc 1 33682 5 discriminator 4 view .LVU9950
.LBB7288:
.LBI7288:
	.loc 1 776 23 discriminator 4 view .LVU9951
.LBB7289:
	.loc 1 781 5 discriminator 4 view .LVU9952
	.loc 1 782 9 discriminator 4 view .LVU9953
.LBE7289:
.LBE7288:
	.loc 1 33683 28 is_stmt 0 discriminator 4 view .LVU9954
	movd	(%rbx), %xmm1
.LBB7292:
.LBB7290:
	.loc 1 782 15 discriminator 4 view .LVU9955
	pxor	%xmm2, %xmm2
	movq	$0, -24(%rbp)
.LVL2417:
	.loc 1 782 15 discriminator 4 view .LVU9956
.LBE7290:
.LBE7292:
	.loc 1 33683 5 is_stmt 1 discriminator 4 view .LVU9957
	.loc 1 33684 5 discriminator 4 view .LVU9958
	.loc 1 33683 28 is_stmt 0 discriminator 4 view .LVU9959
	movd	4(%rbx), %xmm4
.LBB7293:
.LBB7291:
	.loc 1 782 15 discriminator 4 view .LVU9960
	movups	%xmm2, -40(%rbp)
.LBE7291:
.LBE7293:
	.loc 1 33687 28 discriminator 4 view .LVU9961
	movl	%eax, -24(%rbp)
	.loc 1 33683 28 discriminator 4 view .LVU9962
	punpckldq	%xmm4, %xmm1
	.loc 1 33685 28 discriminator 4 view .LVU9963
	movl	%edx, -40(%rbp)
.LBE7287:
.LBE7286:
	.loc 1 38490 31 discriminator 4 view .LVU9964
	leaq	64(%rbx), %rdx
.LVL2418:
.LBB7296:
.LBB7294:
	.loc 1 33683 28 discriminator 4 view .LVU9965
	movq	%xmm1, -48(%rbp)
	.loc 1 33685 5 is_stmt 1 discriminator 4 view .LVU9966
	.loc 1 33686 5 discriminator 4 view .LVU9967
.LBE7294:
.LBE7296:
	.loc 1 38483 154 is_stmt 0 discriminator 4 view .LVU9968
	movdqu	-48(%rbp), %xmm5
.LBB7297:
.LBB7295:
	.loc 1 33686 28 discriminator 4 view .LVU9969
	movsd	%xmm0, -32(%rbp)
	.loc 1 33687 5 is_stmt 1 discriminator 4 view .LVU9970
	.loc 1 33689 5 discriminator 4 view .LVU9971
.LVL2419:
	.loc 1 33689 5 is_stmt 0 discriminator 4 view .LVU9972
.LBE7295:
.LBE7297:
	.loc 1 38483 154 discriminator 4 view .LVU9973
	movdqu	-32(%rbp), %xmm6
	movups	%xmm5, -80(%rbp)
	movups	%xmm6, -64(%rbp)
	.loc 1 38489 5 is_stmt 1 discriminator 4 view .LVU9974
	testl	%r9d, %r9d
	je	.L1700
	.loc 1 38490 9 view .LVU9975
.LVL2420:
.LBB7298:
.LBI7298:
	.loc 1 33987 18 view .LVU9976
.LBB7299:
	.loc 1 33989 5 view .LVU9977
	.loc 1 33989 35 is_stmt 0 view .LVU9978
	xorl	%ecx, %ecx
.LVL2421:
	.loc 1 33989 35 view .LVU9979
	xorl	%esi, %esi
	leaq	-80(%rbp), %rdi
.LVL2422:
	.loc 1 33989 35 view .LVU9980
	call	_ZL23ma_lpf_reinit__internalPK13ma_lpf_configPvP6ma_lpfj
.LVL2423:
	.loc 1 33989 35 view .LVU9981
	movl	%eax, %r8d
.LVL2424:
.L1701:
	.loc 1 33989 35 view .LVU9982
.LBE7299:
.LBE7298:
	.loc 1 38495 5 is_stmt 1 view .LVU9983
	testl	%r8d, %r8d
	jne	.L1689
	.loc 1 38500 5 view .LVU9984
	.loc 1 38500 86 is_stmt 0 view .LVU9985
	movl	12(%rbx), %ecx
	movl	8(%rbx), %eax
	xorl	%edx, %edx
	divl	%ecx
	.loc 1 38500 31 view .LVU9986
	movl	%eax, 32(%rbx)
	.loc 1 38501 5 is_stmt 1 view .LVU9987
	movl	44(%rbx), %eax
	.loc 1 38501 31 is_stmt 0 view .LVU9988
	movl	%edx, 36(%rbx)
	.loc 1 38504 5 is_stmt 1 view .LVU9989
.LVL2425:
.LBB7300:
.LBI7300:
	.loc 1 38430 13 view .LVU9990
.LBB7301:
	.loc 1 38436 5 view .LVU9991
	xorl	%edx, %edx
	divl	%r12d
	movl	%eax, %esi
.LVL2426:
	.loc 1 38437 5 view .LVU9992
	.loc 1 38439 5 view .LVU9993
	.loc 1 38444 5 view .LVU9994
	.loc 1 38441 28 is_stmt 0 view .LVU9995
	movl	%edx, %eax
.LVL2427:
	.loc 1 38441 48 view .LVU9996
	xorl	%edx, %edx
.LVL2428:
	.loc 1 38441 28 view .LVU9997
	imull	%ecx, %eax
.LVL2429:
	.loc 1 38440 28 view .LVU9998
	imull	%ecx, %esi
.LVL2430:
	.loc 1 38441 48 view .LVU9999
	divl	%r12d
	xorl	%edx, %edx
	.loc 1 38440 48 view .LVU10000
	addl	%esi, %eax
	divl	%ecx
	.loc 1 38444 27 view .LVU10001
	addl	%eax, 40(%rbx)
	.loc 1 38445 5 is_stmt 1 view .LVU10002
	.loc 1 38445 28 is_stmt 0 view .LVU10003
	movl	%edx, 44(%rbx)
.LVL2431:
	.loc 1 38445 28 view .LVU10004
.LBE7301:
.LBE7300:
	.loc 1 38506 5 is_stmt 1 view .LVU10005
.L1689:
	.loc 1 38507 1 is_stmt 0 view .LVU10006
	addq	$64, %rsp
	movl	%r8d, %eax
	popq	%rbx
.LVL2432:
	.loc 1 38507 1 view .LVU10007
	popq	%r12
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL2433:
	.p2align 4,,10
	.p2align 3
.L1703:
	.cfi_restore_state
	.loc 1 38481 112 discriminator 1 view .LVU10008
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rsi, %xmm0
	mulsd	.LC117(%rip), %xmm0
	jmp	.L1697
.LVL2434:
	.p2align 4,,10
	.p2align 3
.L1700:
	.loc 1 38492 9 is_stmt 1 view .LVU10009
	.loc 1 38492 42 is_stmt 0 view .LVU10010
	addq	24(%r10), %rdi
.LVL2435:
.LBB7302:
.LBB7303:
.LBB7304:
.LBB7305:
	.loc 1 782 15 view .LVU10011
	movups	%xmm2, 64(%rbx)
.LBE7305:
.LBE7304:
	.loc 1 33932 35 view .LVU10012
	movl	$1, %ecx
.LVL2436:
.LBB7309:
.LBB7306:
	.loc 1 782 15 view .LVU10013
	movq	$0, 48(%rdx)
.LBE7306:
.LBE7309:
.LBE7303:
.LBE7302:
	.loc 1 38492 42 view .LVU10014
	movq	%rdi, %rsi
.LVL2437:
.LBB7313:
.LBI7302:
	.loc 1 33924 18 is_stmt 1 view .LVU10015
.LBB7312:
	.loc 1 33926 5 view .LVU10016
	.loc 1 33930 5 view .LVU10017
.LBB7310:
.LBI7304:
	.loc 1 776 23 view .LVU10018
.LBB7307:
	.loc 1 781 5 view .LVU10019
	.loc 1 782 9 view .LVU10020
	.loc 1 782 9 is_stmt 0 view .LVU10021
.LBE7307:
.LBE7310:
	.loc 1 33932 5 is_stmt 1 view .LVU10022
	.loc 1 33932 35 is_stmt 0 view .LVU10023
	leaq	-80(%rbp), %rdi
.LVL2438:
.LBB7311:
.LBB7308:
	.loc 1 782 15 view .LVU10024
	movups	%xmm2, 16(%rdx)
	movups	%xmm2, 32(%rdx)
.LBE7308:
.LBE7311:
	.loc 1 33932 35 view .LVU10025
	call	_ZL23ma_lpf_reinit__internalPK13ma_lpf_configPvP6ma_lpfj
.LVL2439:
	.loc 1 33932 35 view .LVU10026
	movl	%eax, %r8d
	.loc 1 33932 74 view .LVU10027
	jmp	.L1701
.LVL2440:
.L1692:
	.loc 1 33932 74 view .LVU10028
.LBE7312:
.LBE7313:
	.loc 1 38458 16 view .LVU10029
	movl	$-2, %r8d
	jmp	.L1689
	.cfi_endproc
.LFE176:
	.size	_ZL37ma_linear_resampler_set_rate_internalP19ma_linear_resamplerPvP31ma_linear_resampler_heap_layoutjjj.lto_priv.0, .-_ZL37ma_linear_resampler_set_rate_internalP19ma_linear_resamplerPvP31ma_linear_resampler_heap_layoutjjj.lto_priv.0
	.p2align 4
	.type	_ZL38ma_resampling_backend_set_rate__linearPvS_jj, @function
_ZL38ma_resampling_backend_set_rate__linearPvS_jj:
.LVL2441:
.LFB178:
	.loc 1 39276 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 39276 1 is_stmt 0 view .LVU10031
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
1:	call	mcount
	.loc 1 39276 1 view .LVU10032
	.loc 1 39277 5 is_stmt 1 view .LVU10033
	.loc 1 39279 5 view .LVU10034
.LBB7314:
.LBB7315:
	.loc 1 39064 49 is_stmt 0 view .LVU10035
	movl	$1, %r9d
.LBE7315:
.LBE7314:
	.loc 1 39280 1 view .LVU10036
	popq	%rbp
	.cfi_def_cfa 7, 8
	.loc 1 39276 1 view .LVU10037
	movq	%rsi, %rdi
.LVL2442:
	.loc 1 39276 1 view .LVU10038
	movl	%ecx, %r8d
.LVL2443:
.LBB7317:
.LBI7314:
	.loc 1 39062 18 is_stmt 1 view .LVU10039
.LBB7316:
	.loc 1 39064 5 view .LVU10040
	.loc 1 39064 49 is_stmt 0 view .LVU10041
	xorl	%esi, %esi
.LVL2444:
	.loc 1 39064 49 view .LVU10042
	movl	%edx, %ecx
.LVL2445:
	.loc 1 39064 49 view .LVU10043
	xorl	%edx, %edx
.LVL2446:
	.loc 1 39064 49 view .LVU10044
	jmp	_ZL37ma_linear_resampler_set_rate_internalP19ma_linear_resamplerPvP31ma_linear_resampler_heap_layoutjjj.lto_priv.0
.LVL2447:
	.loc 1 39064 49 view .LVU10045
.LBE7316:
.LBE7317:
	.cfi_endproc
.LFE178:
	.size	_ZL38ma_resampling_backend_set_rate__linearPvS_jj, .-_ZL38ma_resampling_backend_set_rate__linearPvS_jj
	.p2align 4
	.globl	_ZL35ma_linear_resampler_get_heap_layoutPK26ma_linear_resampler_configP31ma_linear_resampler_heap_layout.lto_priv.0
	.hidden	_ZL35ma_linear_resampler_get_heap_layoutPK26ma_linear_resampler_configP31ma_linear_resampler_heap_layout.lto_priv.0
	.type	_ZL35ma_linear_resampler_get_heap_layoutPK26ma_linear_resampler_configP31ma_linear_resampler_heap_layout.lto_priv.0, @function
_ZL35ma_linear_resampler_get_heap_layoutPK26ma_linear_resampler_configP31ma_linear_resampler_heap_layout.lto_priv.0:
.LVL2448:
.LFB172:
	.loc 1 38510 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 38510 1 is_stmt 0 view .LVU10047
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
1:	call	mcount
	.loc 1 38510 1 view .LVU10048
	.loc 1 38511 5 is_stmt 1 view .LVU10049
	.loc 1 38513 5 view .LVU10050
.LVL2449:
.LBB7318:
.LBI7318:
	.loc 1 776 23 view .LVU10051
.LBB7319:
	.loc 1 781 5 view .LVU10052
	.loc 1 782 9 view .LVU10053
	.loc 1 782 15 is_stmt 0 view .LVU10054
	pxor	%xmm0, %xmm0
	movups	%xmm0, (%rsi)
.LBE7319:
.LBE7318:
	.loc 1 38510 1 view .LVU10055
	movq	%rsi, %rbx
.LBB7321:
.LBB7320:
	.loc 1 782 15 view .LVU10056
	movups	%xmm0, 16(%rsi)
.LVL2450:
	.loc 1 782 15 view .LVU10057
.LBE7320:
.LBE7321:
	.loc 1 38515 5 is_stmt 1 view .LVU10058
	.loc 1 38519 5 view .LVU10059
	.loc 1 38519 18 is_stmt 0 view .LVU10060
	movl	(%rdi), %ecx
	.loc 1 38519 5 view .LVU10061
	cmpl	$5, %ecx
	je	.L1706
	.loc 1 38519 42 discriminator 1 view .LVU10062
	cmpl	$2, %ecx
	jne	.L1715
	.loc 1 38523 5 is_stmt 1 view .LVU10063
	.loc 1 38523 18 is_stmt 0 view .LVU10064
	movl	4(%rdi), %edx
	.loc 1 38523 5 view .LVU10065
	testl	%edx, %edx
	je	.L1715
	.loc 1 38527 5 is_stmt 1 view .LVU10066
	.loc 1 38530 5 view .LVU10067
	.loc 1 38531 5 view .LVU10068
	.loc 1 38534 9 view .LVU10069
	.loc 1 38534 65 is_stmt 0 view .LVU10070
	movl	%edx, %eax
	.loc 1 38538 5 is_stmt 1 view .LVU10071
	.loc 1 38534 54 is_stmt 0 view .LVU10072
	leaq	(%rax,%rax), %rsi
.LVL2451:
	.loc 1 38542 34 view .LVU10073
	salq	$2, %rax
	.loc 1 38534 54 view .LVU10074
	movq	%rsi, 16(%rbx)
	.loc 1 38539 5 is_stmt 1 view .LVU10075
	.loc 1 38542 9 view .LVU10076
	.loc 1 38542 34 is_stmt 0 view .LVU10077
	movq	%rax, (%rbx)
.L1709:
	.loc 1 38546 5 is_stmt 1 view .LVU10078
	.loc 1 38546 30 is_stmt 0 view .LVU10079
	addq	$7, %rax
.LBB7322:
.LBB7323:
.LBB7324:
	.loc 1 33684 28 view .LVU10080
	movl	%edx, -44(%rbp)
	.loc 1 33687 30 view .LVU10081
	movl	$8, %edx
.LBB7325:
.LBB7326:
	.loc 1 782 15 view .LVU10082
	pxor	%xmm0, %xmm0
.LBE7326:
.LBE7325:
.LBE7324:
.LBE7323:
.LBE7322:
	.loc 1 38546 30 view .LVU10083
	andq	$-8, %rax
.LBB7347:
.LBB7337:
.LBB7333:
	.loc 1 33683 28 view .LVU10084
	movl	%ecx, -48(%rbp)
.LBE7333:
.LBE7337:
.LBB7338:
.LBB7339:
	.loc 1 33914 36 view .LVU10085
	leaq	-80(%rbp), %rsi
.LBE7339:
.LBE7338:
.LBB7342:
.LBB7334:
	.loc 1 33686 28 view .LVU10086
	movq	.LC1(%rip), %rcx
.LBE7334:
.LBE7342:
.LBE7347:
	.loc 1 38546 30 view .LVU10087
	movq	%rax, 24(%rbx)
	.loc 1 38547 5 is_stmt 1 view .LVU10088
.LBB7348:
	.loc 1 38548 9 view .LVU10089
	.loc 1 38549 9 view .LVU10090
	.loc 1 38550 9 view .LVU10091
	.loc 1 38550 105 is_stmt 0 view .LVU10092
	movl	16(%rdi), %eax
.LVL2452:
.LBB7343:
.LBI7323:
	.loc 1 33678 22 is_stmt 1 view .LVU10093
.LBB7335:
	.loc 1 33680 5 view .LVU10094
	.loc 1 33682 5 view .LVU10095
.LBB7330:
.LBI7325:
	.loc 1 776 23 view .LVU10096
.LBB7327:
	.loc 1 781 5 view .LVU10097
	.loc 1 782 9 view .LVU10098
.LBE7327:
.LBE7330:
.LBE7335:
.LBE7343:
.LBB7344:
.LBB7340:
	.loc 1 33914 36 is_stmt 0 view .LVU10099
	leaq	-48(%rbp), %rdi
.LVL2453:
	.loc 1 33914 36 view .LVU10100
.LBE7340:
.LBE7344:
.LBB7345:
.LBB7336:
.LBB7331:
.LBB7328:
	.loc 1 782 15 view .LVU10101
	movups	%xmm0, -40(%rbp)
.LBE7328:
.LBE7331:
	.loc 1 33687 30 view .LVU10102
	cmpl	$8, %eax
.LBB7332:
.LBB7329:
	.loc 1 782 15 view .LVU10103
	movq	$0, -24(%rbp)
.LVL2454:
	.loc 1 782 15 view .LVU10104
.LBE7329:
.LBE7332:
	.loc 1 33683 5 is_stmt 1 view .LVU10105
	.loc 1 33684 5 view .LVU10106
	.loc 1 33685 5 view .LVU10107
	.loc 1 33687 30 is_stmt 0 view .LVU10108
	cmova	%edx, %eax
.LVL2455:
	.loc 1 33685 28 view .LVU10109
	movl	$1, -40(%rbp)
	.loc 1 33686 5 is_stmt 1 view .LVU10110
	.loc 1 33686 28 is_stmt 0 view .LVU10111
	movq	%rcx, -32(%rbp)
	.loc 1 33687 5 is_stmt 1 view .LVU10112
	.loc 1 33687 28 is_stmt 0 view .LVU10113
	movl	%eax, -24(%rbp)
	.loc 1 33689 5 is_stmt 1 view .LVU10114
.LVL2456:
	.loc 1 33689 5 is_stmt 0 view .LVU10115
.LBE7336:
.LBE7345:
	.loc 1 38552 9 is_stmt 1 view .LVU10116
.LBB7346:
.LBI7338:
	.loc 1 33903 18 view .LVU10117
.LBB7341:
	.loc 1 33905 5 view .LVU10118
	.loc 1 33906 5 view .LVU10119
	.loc 1 33908 5 view .LVU10120
	.loc 1 33912 5 view .LVU10121
	.loc 1 33914 5 view .LVU10122
	.loc 1 33914 36 is_stmt 0 view .LVU10123
	call	_ZL22ma_lpf_get_heap_layoutPK13ma_lpf_configP18ma_lpf_heap_layout.lto_priv.0
.LVL2457:
	.loc 1 33914 36 view .LVU10124
	movl	%eax, %r8d
.LVL2458:
	.loc 1 33915 5 is_stmt 1 view .LVU10125
	testl	%eax, %eax
	jne	.L1705
	.loc 1 33919 5 view .LVU10126
.LVL2459:
	.loc 1 33921 5 view .LVU10127
	.loc 1 33921 5 is_stmt 0 view .LVU10128
.LBE7341:
.LBE7346:
	.loc 1 38553 9 is_stmt 1 view .LVU10129
	.loc 1 38557 9 view .LVU10130
	.loc 1 38557 9 is_stmt 0 view .LVU10131
.LBE7348:
	.loc 1 38561 5 is_stmt 1 view .LVU10132
	.loc 1 38561 32 is_stmt 0 view .LVU10133
	movq	-80(%rbp), %rax
	addq	$7, %rax
	addq	(%rbx), %rax
	andq	$-8, %rax
	movq	%rax, (%rbx)
	.loc 1 38563 5 is_stmt 1 view .LVU10134
.LVL2460:
.L1705:
	.loc 1 38564 1 is_stmt 0 view .LVU10135
	movq	-8(%rbp), %rbx
.LVL2461:
	.loc 1 38564 1 view .LVU10136
	movl	%r8d, %eax
	leave
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL2462:
	.p2align 4,,10
	.p2align 3
.L1706:
	.cfi_restore_state
	.loc 1 38523 5 is_stmt 1 view .LVU10137
	.loc 1 38523 18 is_stmt 0 view .LVU10138
	movl	4(%rdi), %edx
	.loc 1 38523 5 view .LVU10139
	testl	%edx, %edx
	je	.L1715
	.loc 1 38527 5 is_stmt 1 view .LVU10140
	.loc 1 38530 5 view .LVU10141
	.loc 1 38531 5 view .LVU10142
	.loc 1 38532 9 view .LVU10143
	.loc 1 38532 62 is_stmt 0 view .LVU10144
	movl	%edx, %eax
	.loc 1 38538 5 is_stmt 1 view .LVU10145
	.loc 1 38532 51 is_stmt 0 view .LVU10146
	leaq	0(,%rax,4), %rsi
	.loc 1 38540 34 view .LVU10147
	salq	$3, %rax
	.loc 1 38532 51 view .LVU10148
	movq	%rsi, 16(%rbx)
	.loc 1 38539 5 is_stmt 1 view .LVU10149
	.loc 1 38540 9 view .LVU10150
	.loc 1 38540 34 is_stmt 0 view .LVU10151
	movq	%rax, (%rbx)
	jmp	.L1709
	.p2align 4,,10
	.p2align 3
.L1715:
	.loc 1 38520 16 view .LVU10152
	movl	$-2, %r8d
	jmp	.L1705
	.cfi_endproc
.LFE172:
	.size	_ZL35ma_linear_resampler_get_heap_layoutPK26ma_linear_resampler_configP31ma_linear_resampler_heap_layout.lto_priv.0, .-_ZL35ma_linear_resampler_get_heap_layoutPK26ma_linear_resampler_configP31ma_linear_resampler_heap_layout.lto_priv.0
	.p2align 4
	.type	_ZL34ma_resampling_backend_init__linearPvPK19ma_resampler_configS_PS_, @function
_ZL34ma_resampling_backend_init__linearPvPK19ma_resampler_configS_PS_:
.LVL2463:
.LFB179:
	.loc 1 39242 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 39242 1 is_stmt 0 view .LVU10154
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$64, %rsp
	.cfi_offset 14, -24
	.cfi_offset 13, -32
	.cfi_offset 12, -40
	.cfi_offset 3, -48
1:	call	mcount
	.loc 1 39242 1 view .LVU10155
	.loc 1 39243 5 is_stmt 1 view .LVU10156
.LVL2464:
	.loc 1 39244 5 view .LVU10157
	.loc 1 39245 5 view .LVU10158
	.loc 1 39247 5 view .LVU10159
	.loc 1 39249 5 view .LVU10160
.LBB7361:
.LBI7361:
	.loc 1 39220 35 view .LVU10161
.LBB7362:
	.loc 1 39222 5 view .LVU10162
	.loc 1 39224 5 view .LVU10163
.LBB7363:
.LBI7363:
	.loc 1 38406 35 view .LVU10164
.LBB7364:
	.loc 1 38408 5 view .LVU10165
	.loc 1 38409 5 view .LVU10166
	.loc 1 38409 5 is_stmt 0 view .LVU10167
.LBE7364:
.LBE7363:
.LBE7362:
.LBE7361:
	.loc 1 781 5 is_stmt 1 view .LVU10168
	.loc 1 782 9 view .LVU10169
.LBB7368:
.LBB7367:
.LBB7366:
.LBB7365:
	.loc 1 38410 5 view .LVU10170
	.loc 1 38411 5 view .LVU10171
	.loc 1 38412 5 view .LVU10172
	.loc 1 38413 5 view .LVU10173
	.loc 1 38414 5 view .LVU10174
	.loc 1 38415 5 view .LVU10175
	.loc 1 38417 5 view .LVU10176
	.loc 1 38417 5 is_stmt 0 view .LVU10177
.LBE7365:
.LBE7366:
	.loc 1 39225 5 is_stmt 1 view .LVU10178
	.loc 1 39225 45 is_stmt 0 view .LVU10179
	movl	40(%rsi), %eax
	.loc 1 39227 5 is_stmt 1 view .LVU10180
.LVL2465:
	.loc 1 39227 5 is_stmt 0 view .LVU10181
.LBE7367:
.LBE7368:
	.loc 1 39249 68 view .LVU10182
	movd	8(%rsi), %xmm1
	movd	12(%rsi), %xmm2
	movd	(%rsi), %xmm0
	movd	4(%rsi), %xmm3
	punpckldq	%xmm2, %xmm1
	movl	%eax, -80(%rbp)
	punpckldq	%xmm3, %xmm0
	.loc 1 39251 51 view .LVU10183
	leaq	40(%rdi), %r13
	.loc 1 39242 1 view .LVU10184
	movq	%rdi, %rbx
	.loc 1 39249 68 view .LVU10185
	punpcklqdq	%xmm1, %xmm0
.LBB7369:
.LBB7370:
.LBB7371:
.LBB7372:
	.loc 1 782 15 view .LVU10186
	leaq	48(%rdi), %rdi
.LVL2466:
	.loc 1 782 15 view .LVU10187
.LBE7372:
.LBE7371:
.LBE7370:
.LBE7369:
	.loc 1 39242 1 view .LVU10188
	movq	%rcx, %r12
.LBB7385:
.LBB7381:
.LBB7375:
.LBB7373:
	.loc 1 782 15 view .LVU10189
	movq	%r13, %rcx
.LVL2467:
	.loc 1 782 15 view .LVU10190
.LBE7373:
.LBE7375:
.LBE7381:
.LBE7385:
	.loc 1 39249 68 view .LVU10191
	movq	.LC1(%rip), %rax
	movaps	%xmm0, -96(%rbp)
.LBB7386:
.LBB7382:
	.loc 1 38598 49 view .LVU10192
	leaq	-64(%rbp), %rsi
.LVL2468:
	.loc 1 38598 49 view .LVU10193
.LBE7382:
.LBE7386:
	.loc 1 39242 1 view .LVU10194
	movq	%rdx, %r14
	.loc 1 39249 68 view .LVU10195
	movq	%rax, -72(%rbp)
	.loc 1 39251 5 is_stmt 1 view .LVU10196
.LVL2469:
.LBB7387:
.LBI7369:
	.loc 1 38587 18 view .LVU10197
.LBB7383:
	.loc 1 38589 5 view .LVU10198
	.loc 1 38590 5 view .LVU10199
	.loc 1 38592 5 view .LVU10200
	.loc 1 38596 5 view .LVU10201
.LBB7376:
.LBI7371:
	.loc 1 776 23 view .LVU10202
.LBB7374:
	.loc 1 781 5 view .LVU10203
	.loc 1 782 9 view .LVU10204
	.loc 1 782 15 is_stmt 0 view .LVU10205
	xorl	%eax, %eax
	movq	$0, -8(%rdi)
	movq	$0, 120(%rdi)
	andq	$-8, %rdi
	subq	%rdi, %rcx
.LVL2470:
	.loc 1 782 15 view .LVU10206
	addl	$136, %ecx
	shrl	$3, %ecx
	rep stosq
.LVL2471:
	.loc 1 782 15 view .LVU10207
.LBE7374:
.LBE7376:
	.loc 1 38598 5 is_stmt 1 view .LVU10208
	.loc 1 38598 49 is_stmt 0 view .LVU10209
	leaq	-96(%rbp), %rdi
.LVL2472:
	.loc 1 38598 49 view .LVU10210
	call	_ZL35ma_linear_resampler_get_heap_layoutPK26ma_linear_resampler_configP31ma_linear_resampler_heap_layout.lto_priv.0
.LVL2473:
	.loc 1 38599 5 is_stmt 1 view .LVU10211
	testl	%eax, %eax
	jne	.L1719
	.loc 1 38603 5 view .LVU10212
	.loc 1 38603 24 is_stmt 0 view .LVU10213
	movdqa	-96(%rbp), %xmm4
	movdqa	-80(%rbp), %xmm5
	.loc 1 38605 24 view .LVU10214
	movq	%r14, 160(%rbx)
	.loc 1 38606 5 view .LVU10215
	movq	-64(%rbp), %rdx
	.loc 1 38603 24 view .LVU10216
	movups	%xmm4, 40(%rbx)
	movups	%xmm5, 56(%rbx)
	.loc 1 38605 5 is_stmt 1 view .LVU10217
	.loc 1 38606 5 view .LVU10218
.LVL2474:
.LBB7377:
.LBI7377:
	.loc 1 776 23 view .LVU10219
.LBB7378:
	.loc 1 781 5 view .LVU10220
	testq	%rdx, %rdx
	jne	.L1728
.LVL2475:
.L1721:
	.loc 1 781 5 is_stmt 0 view .LVU10221
.LBE7378:
.LBE7377:
	.loc 1 38608 5 is_stmt 1 view .LVU10222
	.loc 1 38609 30 is_stmt 0 view .LVU10223
	movq	-56(%rbp), %rax
	.loc 1 38610 30 view .LVU10224
	movq	-48(%rbp), %rdx
	.loc 1 38609 30 view .LVU10225
	addq	%r14, %rax
	.loc 1 38610 30 view .LVU10226
	addq	%r14, %rdx
	.loc 1 38608 5 view .LVU10227
	cmpl	$5, -96(%rbp)
	.loc 1 38609 28 view .LVU10228
	movq	%rax, %xmm0
	.loc 1 38608 5 view .LVU10229
	je	.L1729
	.loc 1 38612 9 is_stmt 1 view .LVU10230
	.loc 1 38613 9 view .LVU10231
	.loc 1 38612 28 is_stmt 0 view .LVU10232
	movq	%rdx, %xmm6
	punpcklqdq	%xmm6, %xmm0
	movups	%xmm0, 88(%rbx)
.L1723:
	.loc 1 38617 5 is_stmt 1 view .LVU10233
	.loc 1 38617 51 is_stmt 0 view .LVU10234
	movl	-84(%rbp), %r8d
	movl	-88(%rbp), %ecx
	xorl	%r9d, %r9d
	leaq	-64(%rbp), %rdx
	movq	%r14, %rsi
	movq	%r13, %rdi
	call	_ZL37ma_linear_resampler_set_rate_internalP19ma_linear_resamplerPvP31ma_linear_resampler_heap_layoutjjj.lto_priv.0
.LVL2476:
	.loc 1 38618 5 is_stmt 1 view .LVU10235
	testl	%eax, %eax
	jne	.L1719
	.loc 1 38622 5 view .LVU10236
	.loc 1 38623 5 view .LVU10237
	.loc 1 38622 28 is_stmt 0 view .LVU10238
	movq	.LC4(%rip), %rdx
	movq	%rdx, 80(%rbx)
	.loc 1 38625 5 is_stmt 1 view .LVU10239
.LVL2477:
	.loc 1 38625 5 is_stmt 0 view .LVU10240
.LBE7383:
.LBE7387:
	.loc 1 39252 5 is_stmt 1 view .LVU10241
	.loc 1 39256 5 view .LVU10242
	.loc 1 39256 16 is_stmt 0 view .LVU10243
	movq	%r13, (%r12)
	.loc 1 39258 5 is_stmt 1 view .LVU10244
.LVL2478:
.L1719:
	.loc 1 39259 1 is_stmt 0 view .LVU10245
	addq	$64, %rsp
	popq	%rbx
.LVL2479:
	.loc 1 39259 1 view .LVU10246
	popq	%r12
.LVL2480:
	.loc 1 39259 1 view .LVU10247
	popq	%r13
.LVL2481:
	.loc 1 39259 1 view .LVU10248
	popq	%r14
.LVL2482:
	.loc 1 39259 1 view .LVU10249
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL2483:
	.p2align 4,,10
	.p2align 3
.L1729:
	.cfi_restore_state
.LBB7388:
.LBB7384:
	.loc 1 38609 9 is_stmt 1 view .LVU10250
	.loc 1 38610 9 view .LVU10251
	.loc 1 38609 28 is_stmt 0 view .LVU10252
	movq	%rdx, %xmm7
	punpcklqdq	%xmm7, %xmm0
	movups	%xmm0, 88(%rbx)
	jmp	.L1723
.LVL2484:
	.p2align 4,,10
	.p2align 3
.L1728:
.LBB7380:
.LBB7379:
	.loc 1 782 9 is_stmt 1 view .LVU10253
	.loc 1 782 15 is_stmt 0 view .LVU10254
	xorl	%esi, %esi
	movq	%r14, %rdi
	call	memset
.LVL2485:
	.loc 1 782 15 view .LVU10255
	jmp	.L1721
.LBE7379:
.LBE7380:
.LBE7384:
.LBE7388:
	.cfi_endproc
.LFE179:
	.size	_ZL34ma_resampling_backend_init__linearPvPK19ma_resampler_configS_PS_, .-_ZL34ma_resampling_backend_init__linearPvPK19ma_resampler_configS_PS_
	.section	.rodata.str1.8
	.align 8
.LC120:
	.string	"ma_result ma_linear_resampler_process_pcm_frames_s16(ma_linear_resampler*, const void*, ma_uint64*, void*, ma_uint64*)"
	.section	.rodata.str1.1
.LC121:
	.string	"pResampler != __null"
	.section	.rodata.str1.8
	.align 8
.LC122:
	.string	"ma_result ma_linear_resampler_process_pcm_frames_s16_downsample(ma_linear_resampler*, const void*, ma_uint64*, void*, ma_uint64*)"
	.section	.rodata.str1.1
.LC123:
	.string	"pFrameCountIn != __null"
.LC124:
	.string	"pFrameCountOut != __null"
	.section	.rodata.str1.8
	.align 8
.LC125:
	.string	"void ma_lpf_process_pcm_frame_s16(ma_lpf*, ma_int16*, const ma_int16*)"
	.section	.rodata.str1.1
.LC126:
	.string	"pLPF->format == ma_format_s16"
	.section	.rodata.str1.8
	.align 8
.LC127:
	.string	"ma_result ma_linear_resampler_process_pcm_frames_s16_upsample(ma_linear_resampler*, const void*, ma_uint64*, void*, ma_uint64*)"
	.text
	.p2align 4
	.globl	_ZL42ma_linear_resampler_process_pcm_frames_s16P19ma_linear_resamplerPKvPyPvS3_.lto_priv.0
	.hidden	_ZL42ma_linear_resampler_process_pcm_frames_s16P19ma_linear_resamplerPKvPyPvS3_.lto_priv.0
	.type	_ZL42ma_linear_resampler_process_pcm_frames_s16P19ma_linear_resamplerPKvPyPvS3_.lto_priv.0, @function
_ZL42ma_linear_resampler_process_pcm_frames_s16P19ma_linear_resamplerPKvPyPvS3_.lto_priv.0:
.LVL2486:
.LFB181:
	.loc 1 38873 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 38873 1 is_stmt 0 view .LVU10257
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$168, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
1:	call	mcount
	.loc 1 38873 1 view .LVU10258
	.loc 1 38874 5 is_stmt 1 view .LVU10259
	.loc 1 38873 1 is_stmt 0 view .LVU10260
	movq	%rdx, -136(%rbp)
	movq	%rsi, %r12
	movq	%r8, -144(%rbp)
	.loc 1 38874 5 view .LVU10261
	testq	%rdi, %rdi
	je	.L1885
	.loc 1 38876 5 is_stmt 1 view .LVU10262
	movl	12(%rdi), %eax
	cmpl	%eax, 8(%rdi)
	jbe	.L1732
	.loc 1 38877 9 view .LVU10263
.LVL2487:
.LBB7429:
.LBI7429:
	.loc 1 38724 18 view .LVU10264
.LBB7430:
	.loc 1 38726 5 view .LVU10265
	.loc 1 38727 11 view .LVU10266
	.loc 1 38728 5 view .LVU10267
	.loc 1 38729 5 view .LVU10268
	.loc 1 38730 5 view .LVU10269
	.loc 1 38731 5 view .LVU10270
	.loc 1 38733 5 view .LVU10271
	.loc 1 38734 5 view .LVU10272
	cmpq	$0, -136(%rbp)
	je	.L1886
	.loc 1 38735 5 view .LVU10273
	cmpq	$0, -144(%rbp)
	je	.L1887
	.loc 1 38737 5 view .LVU10274
.LVL2488:
	.loc 1 38738 5 view .LVU10275
	.loc 1 38739 5 view .LVU10276
	.loc 1 38739 24 is_stmt 0 view .LVU10277
	movq	(%rdx), %rax
	movq	%rax, -56(%rbp)
.LVL2489:
	.loc 1 38740 5 is_stmt 1 view .LVU10278
	.loc 1 38740 24 is_stmt 0 view .LVU10279
	movq	-144(%rbp), %rax
.LVL2490:
	.loc 1 38740 24 view .LVU10280
	movq	(%rax), %rax
	movq	%rax, -200(%rbp)
.LVL2491:
	.loc 1 38741 5 is_stmt 1 view .LVU10281
	.loc 1 38742 5 view .LVU10282
	.loc 1 38744 5 view .LVU10283
	.loc 1 38744 31 view .LVU10284
	testq	%rax, %rax
	je	.L1824
.LBB7431:
	.loc 1 38746 28 is_stmt 0 view .LVU10285
	movl	40(%rdi), %esi
.LVL2492:
	.loc 1 38746 28 view .LVU10286
	movq	%rcx, -184(%rbp)
.LBE7431:
	.loc 1 38741 24 view .LVU10287
	xorl	%r8d, %r8d
.LVL2493:
	.loc 1 38741 24 view .LVU10288
	movq	%r12, %rbx
	.loc 1 38742 24 view .LVU10289
	movq	$0, -176(%rbp)
	movq	%rdi, %r13
	movq	%r8, %r12
.LVL2494:
	.loc 1 38742 24 view .LVU10290
	movl	%esi, %r14d
.LVL2495:
.L1736:
.LBB7468:
	.loc 1 38746 9 is_stmt 1 view .LVU10291
	.loc 1 38746 42 view .LVU10292
	testl	%r14d, %r14d
	je	.L1737
	.loc 1 38746 42 is_stmt 0 view .LVU10293
	cmpq	-56(%rbp), %r12
	jnb	.L1826
.LBB7432:
	.loc 1 38750 66 view .LVU10294
	movl	4(%r13), %r11d
.LBB7433:
.LBB7434:
	.loc 1 34035 5 view .LVU10295
	movl	64(%r13), %eax
.LBE7434:
.LBE7433:
	.loc 1 38758 50 view .LVU10296
	pxor	%xmm0, %xmm0
	.loc 1 38751 67 view .LVU10297
	movq	56(%r13), %r10
.LBB7454:
.LBB7448:
	.loc 1 34035 5 view .LVU10298
	movl	%eax, -72(%rbp)
	leal	-1(%r11), %eax
	movl	%eax, -88(%rbp)
	movl	%r11d, %eax
	shrl	$3, %eax
	subl	$1, %eax
	addq	$1, %rax
	salq	$4, %rax
	movq	%rax, -104(%rbp)
	movl	%r11d, %eax
	andl	$-8, %eax
	movl	%eax, -96(%rbp)
.LBE7448:
.LBE7454:
	.loc 1 38754 52 view .LVU10299
	movl	%r11d, %eax
	movq	%rax, -192(%rbp)
	.loc 1 38754 30 view .LVU10300
	addq	%rax, %rax
	movq	%rax, -112(%rbp)
	movl	%r11d, %eax
	andl	$7, %eax
	movl	%eax, -124(%rbp)
	subl	$1, %eax
	movl	%eax, -128(%rbp)
	movq	%rbx, %rax
	movl	%r11d, %ebx
.LVL2496:
	.loc 1 38754 30 view .LVU10301
	movl	%r14d, %r11d
	movq	%r13, %r14
	movq	%r10, %r13
.LVL2497:
	.loc 1 38754 30 view .LVU10302
	movq	%rax, %r10
.LVL2498:
	.p2align 4,,10
	.p2align 3
.L1738:
	.loc 1 38747 13 is_stmt 1 view .LVU10303
	.loc 1 38749 13 view .LVU10304
	testq	%r10, %r10
	je	.L1739
.LVL2499:
	.loc 1 38750 45 view .LVU10305
	testl	%ebx, %ebx
	je	.L1749
	.loc 1 38751 36 is_stmt 0 view .LVU10306
	movq	48(%r14), %rax
	movl	-88(%rbp), %edi
	leaq	15(%rax), %rdx
	movq	%rdx, %rcx
	subq	%r13, %rcx
	cmpq	$30, %rcx
	seta	%sil
	cmpl	$2, %edi
	seta	%cl
	subq	%r10, %rdx
	andl	%esi, %ecx
	cmpq	$30, %rdx
	seta	%dl
	testb	%dl, %cl
	je	.L1741
	leaq	2(%r10), %rcx
	movq	%r13, %rdx
	subq	%rcx, %rdx
	cmpq	$12, %rdx
	jbe	.L1741
	cmpl	$6, %edi
	jbe	.L1827
	movq	-104(%rbp), %rcx
	xorl	%edx, %edx
.LVL2500:
.L1743:
	.loc 1 38751 21 is_stmt 1 view .LVU10307
	.loc 1 38751 50 is_stmt 0 view .LVU10308
	movdqu	0(%r13,%rdx), %xmm2
	movups	%xmm2, (%rax,%rdx)
	.loc 1 38752 21 is_stmt 1 view .LVU10309
	.loc 1 38752 50 is_stmt 0 view .LVU10310
	movdqu	(%r10,%rdx), %xmm3
	movups	%xmm3, 0(%r13,%rdx)
	.loc 1 38750 17 is_stmt 1 view .LVU10311
	.loc 1 38750 45 view .LVU10312
	addq	$16, %rdx
	cmpq	%rdx, %rcx
	jne	.L1743
	movl	-96(%rbp), %edx
	cmpl	%ebx, %edx
	je	.L1747
	cmpl	$2, -128(%rbp)
	movl	-124(%rbp), %edi
	jbe	.L1745
.L1742:
	.loc 1 38750 45 is_stmt 0 view .LVU10313
	movl	%edx, %ecx
	leaq	0(%r13,%rcx,2), %rsi
	.loc 1 38751 21 is_stmt 1 view .LVU10314
	.loc 1 38751 79 is_stmt 0 view .LVU10315
	movq	(%rsi), %r8
	.loc 1 38751 50 view .LVU10316
	movq	%r8, (%rax,%rcx,2)
	.loc 1 38752 21 is_stmt 1 view .LVU10317
	.loc 1 38752 73 is_stmt 0 view .LVU10318
	movq	(%r10,%rcx,2), %rcx
	.loc 1 38752 50 view .LVU10319
	movq	%rcx, (%rsi)
	.loc 1 38750 17 is_stmt 1 view .LVU10320
	.loc 1 38750 45 view .LVU10321
	movl	%edi, %ecx
	andl	$-4, %ecx
	addl	%ecx, %edx
	cmpl	%ecx, %edi
	je	.L1747
.L1745:
.LVL2501:
	.loc 1 38751 21 view .LVU10322
	.loc 1 38751 71 is_stmt 0 view .LVU10323
	movl	%edx, %ecx
	.loc 1 38751 79 view .LVU10324
	leaq	0(%r13,%rcx,2), %rsi
	movzwl	(%rsi), %edi
	.loc 1 38751 50 view .LVU10325
	movw	%di, (%rax,%rcx,2)
	.loc 1 38752 21 is_stmt 1 view .LVU10326
	.loc 1 38752 73 is_stmt 0 view .LVU10327
	movzwl	(%r10,%rcx,2), %ecx
	.loc 1 38752 50 view .LVU10328
	movw	%cx, (%rsi)
	.loc 1 38750 17 is_stmt 1 view .LVU10329
	.loc 1 38750 85 is_stmt 0 view .LVU10330
	leal	1(%rdx), %ecx
.LVL2502:
	.loc 1 38750 45 is_stmt 1 view .LVU10331
	cmpl	%ebx, %ecx
	jnb	.L1747
	.loc 1 38751 21 view .LVU10332
	.loc 1 38751 79 is_stmt 0 view .LVU10333
	leaq	0(%r13,%rcx,2), %rsi
	.loc 1 38750 85 view .LVU10334
	addl	$2, %edx
	.loc 1 38751 79 view .LVU10335
	movzwl	(%rsi), %edi
	.loc 1 38751 50 view .LVU10336
	movw	%di, (%rax,%rcx,2)
	.loc 1 38752 21 is_stmt 1 view .LVU10337
	.loc 1 38752 73 is_stmt 0 view .LVU10338
	movzwl	(%r10,%rcx,2), %ecx
.LVL2503:
	.loc 1 38752 50 view .LVU10339
	movw	%cx, (%rsi)
	.loc 1 38750 17 is_stmt 1 view .LVU10340
	.loc 1 38750 45 view .LVU10341
	cmpl	%ebx, %edx
	jnb	.L1747
	.loc 1 38751 21 view .LVU10342
	.loc 1 38751 79 is_stmt 0 view .LVU10343
	leaq	0(%r13,%rdx,2), %rcx
	movzwl	(%rcx), %esi
	.loc 1 38751 50 view .LVU10344
	movw	%si, (%rax,%rdx,2)
	.loc 1 38752 21 is_stmt 1 view .LVU10345
	.loc 1 38752 73 is_stmt 0 view .LVU10346
	movzwl	(%r10,%rdx,2), %eax
	.loc 1 38752 50 view .LVU10347
	movw	%ax, (%rcx)
	.loc 1 38750 17 is_stmt 1 view .LVU10348
	.loc 1 38750 45 view .LVU10349
.L1747:
	.loc 1 38754 30 is_stmt 0 view .LVU10350
	addq	-112(%rbp), %r10
.LVL2504:
	.loc 1 38754 17 is_stmt 1 view .LVU10351
.L1749:
	.loc 1 38763 13 view .LVU10352
.LBB7455:
.LBI7433:
	.loc 1 34030 23 view .LVU10353
.LBB7449:
	.loc 1 34032 5 view .LVU10354
	.loc 1 34033 5 view .LVU10355
	.loc 1 34035 5 view .LVU10356
	cmpl	$2, -72(%rbp)
	jne	.L1806
	.loc 1 34037 5 view .LVU10357
.LVL2505:
	.loc 1 34037 5 is_stmt 0 view .LVU10358
.LBE7449:
.LBE7455:
.LBE7432:
.LBE7468:
.LBE7430:
.LBE7429:
	.loc 2 2066 91 is_stmt 1 view .LVU10359
.LBB7486:
.LBB7478:
.LBB7469:
.LBB7460:
.LBB7456:
.LBB7450:
	.loc 1 34039 5 view .LVU10360
	.loc 1 34039 27 view .LVU10361
	.loc 1 34039 35 is_stmt 0 view .LVU10362
	movl	76(%r14), %eax
	.loc 1 34039 27 view .LVU10363
	testl	%eax, %eax
	je	.L1766
	.loc 1 34040 46 view .LVU10364
	movq	88(%r14), %rdx
	subl	$1, %eax
	leaq	(%rax,%rax,4), %rax
	leaq	4(%rdx), %rcx
	leaq	44(%rdx,%rax,8), %r9
.LVL2506:
	.p2align 4,,10
	.p2align 3
.L1767:
	.loc 1 34040 9 is_stmt 1 view .LVU10365
.LBB7435:
.LBI7435:
	.loc 1 33453 23 view .LVU10366
.LBB7436:
	.loc 1 33455 5 view .LVU10367
	.loc 1 33456 5 view .LVU10368
	.loc 1 33457 20 is_stmt 0 view .LVU10369
	movl	4(%rcx), %r15d
	.loc 1 33458 20 view .LVU10370
	movl	$16384, %r8d
	.loc 1 33456 21 view .LVU10371
	movl	(%rcx), %esi
.LVL2507:
	.loc 1 33457 5 is_stmt 1 view .LVU10372
	.loc 1 33458 5 view .LVU10373
	.loc 1 33458 20 is_stmt 0 view .LVU10374
	subl	%r15d, %r8d
	movl	%r8d, -64(%rbp)
.LVL2508:
	.loc 1 33460 5 is_stmt 1 view .LVU10375
	.loc 1 33460 5 view .LVU10376
.LBB7437:
	.loc 1 33461 19 view .LVU10377
	testl	%esi, %esi
	je	.L1768
.LBB7438:
	.loc 1 33462 29 is_stmt 0 view .LVU10378
	movq	12(%rcx), %rdi
	xorl	%eax, %eax
.LVL2509:
	.p2align 4,,10
	.p2align 3
.L1769:
	.loc 1 33462 9 is_stmt 1 view .LVU10379
	.loc 1 33463 9 view .LVU10380
	.loc 1 33464 9 view .LVU10381
	.loc 1 33466 9 view .LVU10382
	.loc 1 33466 21 is_stmt 0 view .LVU10383
	movl	(%rdi,%rax,4), %r8d
	.loc 1 33463 18 view .LVU10384
	movswl	0(%r13,%rax,2), %edx
	.loc 1 33466 15 view .LVU10385
	imull	-64(%rbp), %edx
	.loc 1 33466 21 view .LVU10386
	imull	%r15d, %r8d
	.loc 1 33466 18 view .LVU10387
	addl	%r8d, %edx
	.loc 1 33466 11 view .LVU10388
	sarl	$14, %edx
.LVL2510:
	.loc 1 33468 9 is_stmt 1 view .LVU10389
	.loc 1 33468 26 is_stmt 0 view .LVU10390
	movw	%dx, 0(%r13,%rax,2)
.LVL2511:
	.loc 1 33469 9 is_stmt 1 view .LVU10391
	.loc 1 33469 26 is_stmt 0 view .LVU10392
	movl	%edx, (%rdi,%rax,4)
.LBE7438:
	.loc 1 33461 5 is_stmt 1 view .LVU10393
.LVL2512:
	.loc 1 33461 19 view .LVU10394
	addq	$1, %rax
.LVL2513:
	.loc 1 33461 19 is_stmt 0 view .LVU10395
	cmpq	%rax, %rsi
	jne	.L1769
.LVL2514:
.L1768:
	.loc 1 33461 19 view .LVU10396
.LBE7437:
.LBE7436:
.LBE7435:
	.loc 1 34039 5 is_stmt 1 view .LVU10397
	.loc 1 34039 27 view .LVU10398
	addq	$40, %rcx
	cmpq	%rcx, %r9
	jne	.L1767
.L1766:
.LVL2515:
	.loc 1 34043 27 view .LVU10399
	.loc 1 34043 35 is_stmt 0 view .LVU10400
	movl	80(%r14), %edx
	.loc 1 34043 27 view .LVU10401
	testl	%edx, %edx
	je	.L1771
	.loc 1 34044 46 view .LVU10402
	movq	96(%r14), %rcx
	subl	$1, %edx
	salq	$6, %rdx
	leaq	68(%rcx,%rdx), %rdi
	leaq	4(%rcx), %rax
	movq	%rdi, -80(%rbp)
.LVL2516:
	.p2align 4,,10
	.p2align 3
.L1772:
	.loc 1 34044 9 is_stmt 1 view .LVU10403
.LBB7439:
.LBI7439:
	.loc 1 33649 23 view .LVU10404
.LBE7439:
.LBE7450:
.LBE7456:
.LBE7460:
.LBE7469:
.LBE7478:
.LBE7486:
	.loc 1 33651 5 view .LVU10405
.LBB7487:
.LBB7479:
.LBB7470:
.LBB7461:
.LBB7457:
.LBB7451:
.LBB7446:
.LBB7440:
.LBI7440:
	.loc 1 33176 23 view .LVU10406
.LBE7440:
.LBE7446:
.LBE7451:
.LBE7457:
.LBE7461:
.LBE7470:
.LBE7479:
.LBE7487:
	.loc 1 33178 5 view .LVU10407
.LBB7488:
.LBB7480:
.LBB7471:
.LBB7462:
.LBB7458:
.LBB7452:
.LBB7447:
.LBB7445:
.LBB7441:
.LBI7441:
	.loc 1 33149 23 view .LVU10408
.LBB7442:
	.loc 1 33151 5 view .LVU10409
	.loc 1 33152 5 view .LVU10410
	.loc 1 33153 20 is_stmt 0 view .LVU10411
	movl	4(%rax), %edi
	.loc 1 33152 21 view .LVU10412
	movl	(%rax), %edx
.LVL2517:
	.loc 1 33153 5 is_stmt 1 view .LVU10413
	.loc 1 33153 20 is_stmt 0 view .LVU10414
	movl	%edi, -148(%rbp)
.LVL2518:
	.loc 1 33154 5 is_stmt 1 view .LVU10415
	.loc 1 33154 20 is_stmt 0 view .LVU10416
	movl	8(%rax), %edi
.LVL2519:
	.loc 1 33154 20 view .LVU10417
	movl	%edi, -152(%rbp)
.LVL2520:
	.loc 1 33155 5 is_stmt 1 view .LVU10418
	.loc 1 33155 20 is_stmt 0 view .LVU10419
	movl	12(%rax), %edi
.LVL2521:
	.loc 1 33155 20 view .LVU10420
	movl	%edi, -156(%rbp)
.LVL2522:
	.loc 1 33156 5 is_stmt 1 view .LVU10421
	.loc 1 33156 20 is_stmt 0 view .LVU10422
	movl	16(%rax), %edi
.LVL2523:
	.loc 1 33156 20 view .LVU10423
	movl	%edi, -160(%rbp)
.LVL2524:
	.loc 1 33157 5 is_stmt 1 view .LVU10424
	.loc 1 33157 20 is_stmt 0 view .LVU10425
	movl	20(%rax), %edi
.LVL2525:
	.loc 1 33157 20 view .LVU10426
	movl	%edi, -164(%rbp)
.LVL2526:
	.loc 1 33159 5 is_stmt 1 view .LVU10427
	.loc 1 33159 5 view .LVU10428
.LBB7443:
	.loc 1 33160 19 view .LVU10429
	testl	%edx, %edx
	je	.L1773
	movl	%edx, %edi
.LVL2527:
.LBB7444:
	.loc 1 33161 28 is_stmt 0 view .LVU10430
	movq	28(%rax), %r9
	.loc 1 33162 28 view .LVU10431
	movq	36(%rax), %r8
	xorl	%edx, %edx
.LVL2528:
	.loc 1 33162 28 view .LVU10432
	movq	%rdi, -64(%rbp)
.LVL2529:
	.p2align 4,,10
	.p2align 3
.L1774:
	.loc 1 33161 9 is_stmt 1 view .LVU10433
	.loc 1 33162 9 view .LVU10434
	.loc 1 33163 9 view .LVU10435
	.loc 1 33163 18 is_stmt 0 view .LVU10436
	movswl	0(%r13,%rdx,2), %esi
.LVL2530:
	.loc 1 33164 9 is_stmt 1 view .LVU10437
	.loc 1 33166 9 view .LVU10438
	.loc 1 33166 17 is_stmt 0 view .LVU10439
	movl	-148(%rbp), %ecx
	.loc 1 33167 17 view .LVU10440
	movl	-152(%rbp), %edi
	.loc 1 33167 24 view .LVU10441
	movl	-160(%rbp), %r15d
	.loc 1 33166 17 view .LVU10442
	imull	%esi, %ecx
	.loc 1 33166 27 view .LVU10443
	addl	(%r9,%rdx,4), %ecx
	.loc 1 33166 12 view .LVU10444
	sarl	$14, %ecx
.LVL2531:
	.loc 1 33167 9 is_stmt 1 view .LVU10445
	.loc 1 33168 9 view .LVU10446
	.loc 1 33170 9 view .LVU10447
	.loc 1 33167 17 is_stmt 0 view .LVU10448
	imull	%esi, %edi
	.loc 1 33167 24 view .LVU10449
	imull	%ecx, %r15d
	.loc 1 33167 20 view .LVU10450
	subl	%r15d, %edi
	.loc 1 33170 37 view .LVU10451
	movl	$32767, %r15d
	.loc 1 33167 12 view .LVU10452
	addl	(%r8,%rdx,4), %edi
	.loc 1 33170 37 view .LVU10453
	cmpl	$32767, %ecx
	cmovle	%ecx, %r15d
	.loc 1 33167 12 view .LVU10454
	movl	%edi, -120(%rbp)
.LVL2532:
	.loc 1 33170 25 view .LVU10455
	movl	$-32768, %edi
	cmpl	$-32768, %r15d
	cmovl	%edi, %r15d
	.loc 1 33168 17 view .LVU10456
	imull	-156(%rbp), %esi
.LVL2533:
	.loc 1 33171 25 view .LVU10457
	movl	-120(%rbp), %edi
	.loc 1 33168 24 view .LVU10458
	imull	-164(%rbp), %ecx
.LVL2534:
	.loc 1 33170 25 view .LVU10459
	movw	%r15w, 0(%r13,%rdx,2)
.LVL2535:
	.loc 1 33171 9 is_stmt 1 view .LVU10460
	.loc 1 33171 25 is_stmt 0 view .LVU10461
	movl	%edi, (%r9,%rdx,4)
	.loc 1 33172 9 is_stmt 1 view .LVU10462
	.loc 1 33168 12 is_stmt 0 view .LVU10463
	subl	%ecx, %esi
.LVL2536:
	.loc 1 33168 12 view .LVU10464
	movl	%esi, (%r8,%rdx,4)
.LBE7444:
	.loc 1 33160 5 is_stmt 1 view .LVU10465
.LVL2537:
	.loc 1 33160 19 view .LVU10466
	addq	$1, %rdx
.LVL2538:
	.loc 1 33160 19 is_stmt 0 view .LVU10467
	cmpq	%rdx, -64(%rbp)
	jne	.L1774
.LVL2539:
.L1773:
	.loc 1 33160 19 view .LVU10468
.LBE7443:
.LBE7442:
.LBE7441:
.LBE7445:
.LBE7447:
	.loc 1 34043 5 is_stmt 1 view .LVU10469
	.loc 1 34043 27 view .LVU10470
	addq	$64, %rax
.LVL2540:
	.loc 1 34043 27 is_stmt 0 view .LVU10471
	cmpq	-80(%rbp), %rax
	jne	.L1772
.LVL2541:
.L1771:
	.loc 1 34043 27 view .LVU10472
.LBE7452:
.LBE7458:
	.loc 1 38765 13 is_stmt 1 view .LVU10473
	.loc 1 38765 35 is_stmt 0 view .LVU10474
	addq	$1, %r12
.LVL2542:
	.loc 1 38766 13 is_stmt 1 view .LVU10475
	.loc 1 38766 35 is_stmt 0 view .LVU10476
	subl	$1, %r11d
	movl	%r11d, 40(%r14)
	.loc 1 38766 35 view .LVU10477
.LBE7462:
	.loc 1 38746 9 is_stmt 1 view .LVU10478
	.loc 1 38746 42 view .LVU10479
	je	.L1888
	cmpq	%r12, -56(%rbp)
	jne	.L1738
.LVL2543:
.L1735:
	.loc 1 38746 42 is_stmt 0 view .LVU10480
.LBE7471:
	.loc 1 38792 5 is_stmt 1 view .LVU10481
	.loc 1 38792 21 is_stmt 0 view .LVU10482
	movq	-136(%rbp), %rax
	movq	-56(%rbp), %rbx
	movq	%rbx, (%rax)
	.loc 1 38793 5 is_stmt 1 view .LVU10483
	.loc 1 38793 21 is_stmt 0 view .LVU10484
	movq	-144(%rbp), %rax
	movq	-176(%rbp), %rbx
	movq	%rbx, (%rax)
	.loc 1 38795 5 is_stmt 1 view .LVU10485
.LVL2544:
	.loc 1 38795 5 is_stmt 0 view .LVU10486
.LBE7480:
.LBE7488:
	.loc 1 38877 134 view .LVU10487
	jmp	.L1883
.LVL2545:
.L1732:
	.loc 1 38879 9 is_stmt 1 view .LVU10488
.LBB7489:
.LBI7489:
	.loc 1 38798 18 view .LVU10489
.LBB7490:
	.loc 1 38800 5 view .LVU10490
	.loc 1 38801 11 view .LVU10491
	.loc 1 38802 5 view .LVU10492
	.loc 1 38803 5 view .LVU10493
	.loc 1 38804 5 view .LVU10494
	.loc 1 38805 5 view .LVU10495
	.loc 1 38807 5 view .LVU10496
	.loc 1 38808 5 view .LVU10497
	cmpq	$0, -136(%rbp)
	je	.L1889
	.loc 1 38809 5 view .LVU10498
	cmpq	$0, -144(%rbp)
	je	.L1890
	.loc 1 38811 5 view .LVU10499
.LVL2546:
	.loc 1 38812 5 view .LVU10500
	.loc 1 38813 5 view .LVU10501
	.loc 1 38813 24 is_stmt 0 view .LVU10502
	movq	(%rdx), %rax
	movq	%rax, -64(%rbp)
.LVL2547:
	.loc 1 38814 5 is_stmt 1 view .LVU10503
	.loc 1 38814 24 is_stmt 0 view .LVU10504
	movq	-144(%rbp), %rax
.LVL2548:
	.loc 1 38814 24 view .LVU10505
	movq	(%rax), %rax
	movq	%rax, -104(%rbp)
.LVL2549:
	.loc 1 38815 5 is_stmt 1 view .LVU10506
	.loc 1 38816 5 view .LVU10507
	.loc 1 38818 5 view .LVU10508
	.loc 1 38818 31 view .LVU10509
	testq	%rax, %rax
	je	.L1831
	.loc 1 38815 24 is_stmt 0 view .LVU10510
	xorl	%r13d, %r13d
.LBB7491:
	.loc 1 38820 28 view .LVU10511
	movl	40(%rdi), %ebx
.LBB7492:
	.loc 1 38832 50 view .LVU10512
	pxor	%xmm1, %xmm1
	movq	%rdi, %r14
.LBE7492:
.LBE7491:
	.loc 1 38816 24 view .LVU10513
	movq	$0, -80(%rbp)
	movq	%rcx, %r12
	movq	%r13, -72(%rbp)
	movq	%rsi, %r13
.LVL2550:
.L1780:
.LBB7527:
	.loc 1 38820 9 is_stmt 1 view .LVU10514
	.loc 1 38820 42 view .LVU10515
	testl	%ebx, %ebx
	je	.L1781
	.loc 1 38820 42 is_stmt 0 view .LVU10516
	movq	-72(%rbp), %r10
	cmpq	%r10, -64(%rbp)
	jbe	.L1833
.LBB7493:
	.loc 1 38824 66 view .LVU10517
	movl	4(%r14), %r8d
	movq	%r12, -112(%rbp)
	movl	%r8d, %eax
	movq	%r8, %rdi
	leal	-1(%r8), %r9d
	shrl	$3, %eax
	subl	$1, %eax
	addq	$1, %rax
	salq	$4, %rax
	movq	%rax, %r15
	movl	%r8d, %eax
	andl	$-8, %eax
	movl	%eax, -56(%rbp)
	.loc 1 38828 30 view .LVU10518
	leaq	(%r8,%r8), %rax
	movq	%rax, -72(%rbp)
.LVL2551:
	.loc 1 38828 30 view .LVU10519
	movl	%r8d, %eax
	andl	$7, %eax
	movl	%eax, -88(%rbp)
	subl	$1, %eax
	movl	%eax, -96(%rbp)
.LVL2552:
.L1782:
	.loc 1 38821 13 is_stmt 1 view .LVU10520
	.loc 1 38823 13 view .LVU10521
	testq	%r13, %r13
	je	.L1783
.LVL2553:
	.loc 1 38824 45 view .LVU10522
	testl	%edi, %edi
	je	.L1793
	.loc 1 38825 67 is_stmt 0 view .LVU10523
	movq	56(%r14), %rax
	.loc 1 38825 36 view .LVU10524
	movq	48(%r14), %rdx
	leaq	15(%rax), %rcx
	subq	%rdx, %rcx
	cmpq	$30, %rcx
	seta	%sil
	cmpl	$2, %r9d
	seta	%cl
	andl	%esi, %ecx
	leaq	15(%rdx), %rsi
	subq	%r13, %rsi
	cmpq	$30, %rsi
	seta	%sil
	testb	%sil, %cl
	je	.L1785
	leaq	2(%r13), %rsi
	movq	%rax, %rcx
	subq	%rsi, %rcx
	cmpq	$12, %rcx
	jbe	.L1785
	cmpl	$6, %r9d
	jbe	.L1834
	xorl	%ecx, %ecx
.LVL2554:
.L1787:
	.loc 1 38825 21 is_stmt 1 view .LVU10525
	.loc 1 38825 50 is_stmt 0 view .LVU10526
	movdqu	(%rax,%rcx), %xmm6
	movups	%xmm6, (%rdx,%rcx)
	.loc 1 38826 21 is_stmt 1 view .LVU10527
	.loc 1 38826 50 is_stmt 0 view .LVU10528
	movdqu	0(%r13,%rcx), %xmm7
	movups	%xmm7, (%rax,%rcx)
	.loc 1 38824 17 is_stmt 1 view .LVU10529
	.loc 1 38824 45 view .LVU10530
	addq	$16, %rcx
	cmpq	%r15, %rcx
	jne	.L1787
	movl	-56(%rbp), %ecx
	cmpl	%ecx, %edi
	je	.L1791
	cmpl	$2, -96(%rbp)
	movl	-88(%rbp), %r12d
	jbe	.L1789
.L1786:
	.loc 1 38824 45 is_stmt 0 view .LVU10531
	movl	%ecx, %esi
	leaq	(%rax,%rsi,2), %r11
	.loc 1 38825 21 is_stmt 1 view .LVU10532
	.loc 1 38825 79 is_stmt 0 view .LVU10533
	movq	(%r11), %xmm0
	.loc 1 38825 50 view .LVU10534
	movq	%xmm0, (%rdx,%rsi,2)
	.loc 1 38826 21 is_stmt 1 view .LVU10535
	.loc 1 38826 73 is_stmt 0 view .LVU10536
	movq	0(%r13,%rsi,2), %rsi
	.loc 1 38826 50 view .LVU10537
	movq	%rsi, (%r11)
	.loc 1 38824 17 is_stmt 1 view .LVU10538
	.loc 1 38824 45 view .LVU10539
	movl	%r12d, %esi
	andl	$-4, %esi
	addl	%esi, %ecx
	cmpl	%r12d, %esi
	je	.L1791
.L1789:
.LVL2555:
	.loc 1 38825 21 view .LVU10540
	.loc 1 38825 71 is_stmt 0 view .LVU10541
	movl	%ecx, %esi
	.loc 1 38825 79 view .LVU10542
	leaq	(%rax,%rsi,2), %r11
	movzwl	(%r11), %r12d
	.loc 1 38825 50 view .LVU10543
	movw	%r12w, (%rdx,%rsi,2)
	.loc 1 38826 21 is_stmt 1 view .LVU10544
	.loc 1 38826 73 is_stmt 0 view .LVU10545
	movzwl	0(%r13,%rsi,2), %esi
	.loc 1 38826 50 view .LVU10546
	movw	%si, (%r11)
	.loc 1 38824 17 is_stmt 1 view .LVU10547
	.loc 1 38824 85 is_stmt 0 view .LVU10548
	leal	1(%rcx), %esi
.LVL2556:
	.loc 1 38824 45 is_stmt 1 view .LVU10549
	cmpl	%edi, %esi
	jnb	.L1791
	.loc 1 38825 21 view .LVU10550
	.loc 1 38825 79 is_stmt 0 view .LVU10551
	leaq	(%rax,%rsi,2), %r11
	.loc 1 38824 85 view .LVU10552
	addl	$2, %ecx
	.loc 1 38825 79 view .LVU10553
	movzwl	(%r11), %r12d
	.loc 1 38825 50 view .LVU10554
	movw	%r12w, (%rdx,%rsi,2)
	.loc 1 38826 21 is_stmt 1 view .LVU10555
	.loc 1 38826 73 is_stmt 0 view .LVU10556
	movzwl	0(%r13,%rsi,2), %esi
.LVL2557:
	.loc 1 38826 50 view .LVU10557
	movw	%si, (%r11)
	.loc 1 38824 17 is_stmt 1 view .LVU10558
	.loc 1 38824 45 view .LVU10559
	cmpl	%edi, %ecx
	jnb	.L1791
	.loc 1 38825 21 view .LVU10560
	.loc 1 38825 79 is_stmt 0 view .LVU10561
	leaq	(%rax,%rcx,2), %rax
	movzwl	(%rax), %esi
	.loc 1 38825 50 view .LVU10562
	movw	%si, (%rdx,%rcx,2)
	.loc 1 38826 21 is_stmt 1 view .LVU10563
	.loc 1 38826 73 is_stmt 0 view .LVU10564
	movzwl	0(%r13,%rcx,2), %edx
	.loc 1 38826 50 view .LVU10565
	movw	%dx, (%rax)
	.loc 1 38824 17 is_stmt 1 view .LVU10566
	.loc 1 38824 45 view .LVU10567
.L1791:
	.loc 1 38828 30 is_stmt 0 view .LVU10568
	addq	-72(%rbp), %r13
.LVL2558:
	.loc 1 38828 17 is_stmt 1 view .LVU10569
.L1793:
	.loc 1 38836 13 view .LVU10570
	.loc 1 38836 35 is_stmt 0 view .LVU10571
	addq	$1, %r10
.LVL2559:
	.loc 1 38837 13 is_stmt 1 view .LVU10572
	.loc 1 38837 35 is_stmt 0 view .LVU10573
	subl	$1, %ebx
	movl	%ebx, 40(%r14)
	.loc 1 38837 35 view .LVU10574
.LBE7493:
	.loc 1 38820 9 is_stmt 1 view .LVU10575
	.loc 1 38820 42 view .LVU10576
	je	.L1891
.L1884:
	.loc 1 38820 42 is_stmt 0 view .LVU10577
	cmpq	%r10, -64(%rbp)
	jne	.L1782
.LVL2560:
.L1779:
	.loc 1 38820 42 view .LVU10578
.LBE7527:
	.loc 1 38866 5 is_stmt 1 view .LVU10579
	.loc 1 38866 21 is_stmt 0 view .LVU10580
	movq	-136(%rbp), %rax
	movq	-64(%rbp), %rbx
	movq	%rbx, (%rax)
	.loc 1 38867 5 is_stmt 1 view .LVU10581
	.loc 1 38867 21 is_stmt 0 view .LVU10582
	movq	-144(%rbp), %rax
	movq	-80(%rbp), %rbx
	movq	%rbx, (%rax)
	.loc 1 38869 5 is_stmt 1 view .LVU10583
.LVL2561:
.L1883:
	.loc 1 38869 5 is_stmt 0 view .LVU10584
.LBE7490:
.LBE7489:
	.loc 1 38881 1 view .LVU10585
	addq	$168, %rsp
	xorl	%eax, %eax
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL2562:
.L1739:
	.cfi_restore_state
.LBB7542:
.LBB7481:
.LBB7472:
.LBB7463:
	.loc 1 38756 45 is_stmt 1 view .LVU10586
	testl	%ebx, %ebx
	je	.L1749
	.loc 1 38757 36 is_stmt 0 view .LVU10587
	movq	48(%r14), %rax
	leaq	15(%rax), %rdx
	subq	%r13, %rdx
	cmpq	$30, %rdx
	jbe	.L1751
	movl	-88(%rbp), %edi
	cmpl	$2, %edi
	jbe	.L1751
	cmpl	$6, %edi
	jbe	.L1829
	movq	-104(%rbp), %rcx
	xorl	%edx, %edx
.LVL2563:
	.p2align 4,,10
	.p2align 3
.L1754:
	.loc 1 38757 21 is_stmt 1 view .LVU10588
	.loc 1 38757 50 is_stmt 0 view .LVU10589
	movdqu	0(%r13,%rdx), %xmm4
	movups	%xmm4, (%rax,%rdx)
	.loc 1 38758 21 is_stmt 1 view .LVU10590
	.loc 1 38758 50 is_stmt 0 view .LVU10591
	movups	%xmm0, 0(%r13,%rdx)
	.loc 1 38756 17 is_stmt 1 view .LVU10592
	.loc 1 38756 45 view .LVU10593
	addq	$16, %rdx
	cmpq	%rdx, %rcx
	jne	.L1754
	movl	-96(%rbp), %edx
	cmpl	%ebx, %edx
	je	.L1749
	cmpl	$2, -128(%rbp)
	movl	-124(%rbp), %edi
	jbe	.L1757
.L1752:
	movl	%edx, %esi
	leaq	0(%r13,%rsi,2), %rcx
	.loc 1 38757 21 view .LVU10594
	.loc 1 38757 79 is_stmt 0 view .LVU10595
	movq	(%rcx), %r8
	.loc 1 38757 50 view .LVU10596
	movq	%r8, (%rax,%rsi,2)
	.loc 1 38758 21 is_stmt 1 view .LVU10597
	.loc 1 38758 50 is_stmt 0 view .LVU10598
	movq	$0, (%rcx)
	.loc 1 38756 17 is_stmt 1 view .LVU10599
	.loc 1 38756 45 view .LVU10600
	movl	%edi, %ecx
	andl	$-4, %ecx
	addl	%ecx, %edx
	cmpl	%edi, %ecx
	je	.L1749
.L1757:
.LVL2564:
	.loc 1 38757 21 view .LVU10601
	.loc 1 38757 71 is_stmt 0 view .LVU10602
	movl	%edx, %esi
	.loc 1 38757 79 view .LVU10603
	leaq	0(%r13,%rsi,2), %rcx
	movzwl	(%rcx), %edi
	.loc 1 38757 50 view .LVU10604
	movw	%di, (%rax,%rsi,2)
	.loc 1 38758 21 is_stmt 1 view .LVU10605
	.loc 1 38758 50 is_stmt 0 view .LVU10606
	xorl	%esi, %esi
	movw	%si, (%rcx)
	.loc 1 38756 17 is_stmt 1 view .LVU10607
	.loc 1 38756 85 is_stmt 0 view .LVU10608
	leal	1(%rdx), %ecx
.LVL2565:
	.loc 1 38756 45 is_stmt 1 view .LVU10609
	cmpl	%ecx, %ebx
	jbe	.L1749
	.loc 1 38757 21 view .LVU10610
	.loc 1 38757 79 is_stmt 0 view .LVU10611
	leaq	0(%r13,%rcx,2), %rsi
	.loc 1 38756 85 view .LVU10612
	addl	$2, %edx
	.loc 1 38757 79 view .LVU10613
	movzwl	(%rsi), %edi
	.loc 1 38757 50 view .LVU10614
	movw	%di, (%rax,%rcx,2)
	.loc 1 38758 21 is_stmt 1 view .LVU10615
	.loc 1 38758 50 is_stmt 0 view .LVU10616
	xorl	%ecx, %ecx
.LVL2566:
	.loc 1 38758 50 view .LVU10617
	movw	%cx, (%rsi)
	.loc 1 38756 17 is_stmt 1 view .LVU10618
	.loc 1 38756 45 view .LVU10619
	cmpl	%ebx, %edx
	jnb	.L1749
	.loc 1 38757 21 view .LVU10620
	.loc 1 38757 79 is_stmt 0 view .LVU10621
	leaq	0(%r13,%rdx,2), %rcx
	movzwl	(%rcx), %esi
	.loc 1 38757 50 view .LVU10622
	movw	%si, (%rax,%rdx,2)
	.loc 1 38758 21 is_stmt 1 view .LVU10623
	.loc 1 38758 50 is_stmt 0 view .LVU10624
	xorl	%eax, %eax
	movw	%ax, (%rcx)
	.loc 1 38756 17 is_stmt 1 view .LVU10625
	.loc 1 38756 45 view .LVU10626
	jmp	.L1749
.LVL2567:
.L1783:
	.loc 1 38756 45 is_stmt 0 view .LVU10627
.LBE7463:
.LBE7472:
.LBE7481:
.LBE7542:
.LBB7543:
.LBB7535:
.LBB7528:
.LBB7494:
	.loc 1 38830 45 is_stmt 1 view .LVU10628
	testl	%edi, %edi
	je	.L1793
	.loc 1 38831 67 is_stmt 0 view .LVU10629
	movq	56(%r14), %rax
	.loc 1 38831 36 view .LVU10630
	movq	48(%r14), %rdx
	leaq	15(%rax), %rcx
	subq	%rdx, %rcx
	cmpq	$30, %rcx
	jbe	.L1795
	cmpl	$2, %r9d
	jbe	.L1795
	cmpl	$6, %r9d
	jbe	.L1836
	xorl	%ecx, %ecx
.LVL2568:
	.p2align 4,,10
	.p2align 3
.L1798:
	.loc 1 38831 21 is_stmt 1 view .LVU10631
	.loc 1 38831 50 is_stmt 0 view .LVU10632
	movdqu	(%rax,%rcx), %xmm5
	movups	%xmm5, (%rdx,%rcx)
	.loc 1 38832 21 is_stmt 1 view .LVU10633
	.loc 1 38832 50 is_stmt 0 view .LVU10634
	movups	%xmm1, (%rax,%rcx)
	.loc 1 38830 17 is_stmt 1 view .LVU10635
	.loc 1 38830 45 view .LVU10636
	addq	$16, %rcx
	cmpq	%r15, %rcx
	jne	.L1798
	movl	-56(%rbp), %ecx
	cmpl	%ecx, %edi
	je	.L1793
	cmpl	$2, -96(%rbp)
	movl	-88(%rbp), %r12d
	jbe	.L1801
.L1796:
	movl	%ecx, %r11d
	leaq	(%rax,%r11,2), %rsi
	.loc 1 38831 21 view .LVU10637
	.loc 1 38831 79 is_stmt 0 view .LVU10638
	movq	(%rsi), %xmm0
	.loc 1 38831 50 view .LVU10639
	movq	%xmm0, (%rdx,%r11,2)
	.loc 1 38832 21 is_stmt 1 view .LVU10640
	.loc 1 38832 50 is_stmt 0 view .LVU10641
	movq	$0, (%rsi)
	.loc 1 38830 17 is_stmt 1 view .LVU10642
	.loc 1 38830 45 view .LVU10643
	movl	%r12d, %esi
	andl	$-4, %esi
	addl	%esi, %ecx
	cmpl	%esi, %r12d
	je	.L1793
.L1801:
.LVL2569:
	.loc 1 38831 21 view .LVU10644
	.loc 1 38831 71 is_stmt 0 view .LVU10645
	movl	%ecx, %r11d
	.loc 1 38831 79 view .LVU10646
	leaq	(%rax,%r11,2), %rsi
	movzwl	(%rsi), %r12d
	.loc 1 38831 50 view .LVU10647
	movw	%r12w, (%rdx,%r11,2)
	.loc 1 38832 21 is_stmt 1 view .LVU10648
	.loc 1 38832 50 is_stmt 0 view .LVU10649
	xorl	%r11d, %r11d
	movw	%r11w, (%rsi)
	.loc 1 38830 17 is_stmt 1 view .LVU10650
	.loc 1 38830 85 is_stmt 0 view .LVU10651
	leal	1(%rcx), %esi
.LVL2570:
	.loc 1 38830 45 is_stmt 1 view .LVU10652
	cmpl	%edi, %esi
	jnb	.L1793
	.loc 1 38831 21 view .LVU10653
	.loc 1 38831 79 is_stmt 0 view .LVU10654
	leaq	(%rax,%rsi,2), %r11
	.loc 1 38830 85 view .LVU10655
	addl	$2, %ecx
	.loc 1 38831 79 view .LVU10656
	movzwl	(%r11), %r12d
	.loc 1 38831 50 view .LVU10657
	movw	%r12w, (%rdx,%rsi,2)
	.loc 1 38832 21 is_stmt 1 view .LVU10658
	.loc 1 38832 50 is_stmt 0 view .LVU10659
	xorl	%r12d, %r12d
	movw	%r12w, (%r11)
	.loc 1 38830 17 is_stmt 1 view .LVU10660
.LVL2571:
	.loc 1 38830 45 view .LVU10661
	cmpl	%edi, %ecx
	jnb	.L1793
	.loc 1 38831 21 view .LVU10662
	.loc 1 38831 79 is_stmt 0 view .LVU10663
	leaq	(%rax,%rcx,2), %rax
	.loc 1 38832 50 view .LVU10664
	xorl	%r11d, %r11d
	.loc 1 38836 35 view .LVU10665
	addq	$1, %r10
.LVL2572:
	.loc 1 38837 35 view .LVU10666
	subl	$1, %ebx
	.loc 1 38831 79 view .LVU10667
	movzwl	(%rax), %esi
	.loc 1 38831 50 view .LVU10668
	movw	%si, (%rdx,%rcx,2)
	.loc 1 38832 21 is_stmt 1 view .LVU10669
	.loc 1 38832 50 is_stmt 0 view .LVU10670
	movw	%r11w, (%rax)
	.loc 1 38830 17 is_stmt 1 view .LVU10671
	.loc 1 38830 45 view .LVU10672
	.loc 1 38836 13 view .LVU10673
.LVL2573:
	.loc 1 38837 13 view .LVU10674
	.loc 1 38837 35 is_stmt 0 view .LVU10675
	movl	%ebx, 40(%r14)
	.loc 1 38837 35 view .LVU10676
.LBE7494:
	.loc 1 38820 9 is_stmt 1 view .LVU10677
	.loc 1 38820 42 view .LVU10678
	jne	.L1884
.L1891:
	.loc 1 38820 42 is_stmt 0 view .LVU10679
	movq	%r10, -72(%rbp)
	movq	-112(%rbp), %r12
.LVL2574:
.L1781:
	.loc 1 38840 9 is_stmt 1 view .LVU10680
	.loc 1 38845 9 view .LVU10681
	xorl	%ebx, %ebx
	testq	%r12, %r12
	jne	.L1892
.LVL2575:
.L1809:
	.loc 1 38855 9 view .LVU10682
	.loc 1 38858 9 view .LVU10683
	.loc 1 38860 58 is_stmt 0 view .LVU10684
	movl	12(%r14), %edx
	.loc 1 38859 32 view .LVU10685
	movl	36(%r14), %eax
	.loc 1 38858 32 view .LVU10686
	addl	32(%r14), %ebx
	.loc 1 38859 32 view .LVU10687
	addl	44(%r14), %eax
	.loc 1 38855 28 view .LVU10688
	addq	$1, -80(%rbp)
.LVL2576:
	.loc 1 38858 32 view .LVU10689
	movl	%ebx, 40(%r14)
	.loc 1 38859 9 is_stmt 1 view .LVU10690
	.loc 1 38859 32 is_stmt 0 view .LVU10691
	movl	%eax, 44(%r14)
	.loc 1 38860 9 is_stmt 1 view .LVU10692
	cmpl	%edx, %eax
	jb	.L1820
	.loc 1 38861 13 view .LVU10693
	.loc 1 38861 36 is_stmt 0 view .LVU10694
	subl	%edx, %eax
	.loc 1 38862 36 view .LVU10695
	addl	$1, %ebx
	.loc 1 38861 36 view .LVU10696
	movl	%eax, 44(%r14)
	.loc 1 38862 13 is_stmt 1 view .LVU10697
	.loc 1 38862 36 is_stmt 0 view .LVU10698
	movl	%ebx, 40(%r14)
.L1820:
.LVL2577:
	.loc 1 38862 36 view .LVU10699
.LBE7528:
	.loc 1 38818 5 is_stmt 1 view .LVU10700
	.loc 1 38818 31 view .LVU10701
	movq	-80(%rbp), %rdi
	cmpq	%rdi, -104(%rbp)
	jne	.L1780
	movq	-72(%rbp), %r13
.LVL2578:
	.loc 1 38818 31 is_stmt 0 view .LVU10702
	movq	%r13, -64(%rbp)
.LVL2579:
	.loc 1 38818 31 view .LVU10703
	jmp	.L1779
.LVL2580:
	.p2align 4,,10
	.p2align 3
.L1741:
	.loc 1 38818 31 view .LVU10704
.LBE7535:
.LBE7543:
.LBB7544:
.LBB7482:
.LBB7473:
.LBB7464:
	.loc 1 38751 36 view .LVU10705
	movq	-192(%rbp), %rsi
	xorl	%edx, %edx
.LVL2581:
	.p2align 4,,10
	.p2align 3
.L1748:
	.loc 1 38751 21 is_stmt 1 view .LVU10706
	.loc 1 38751 79 is_stmt 0 view .LVU10707
	movzwl	0(%r13,%rdx,2), %ecx
	.loc 1 38751 50 view .LVU10708
	movw	%cx, (%rax,%rdx,2)
	.loc 1 38752 21 is_stmt 1 view .LVU10709
	.loc 1 38752 73 is_stmt 0 view .LVU10710
	movzwl	(%r10,%rdx,2), %ecx
	.loc 1 38752 50 view .LVU10711
	movw	%cx, 0(%r13,%rdx,2)
	.loc 1 38750 17 is_stmt 1 view .LVU10712
.LVL2582:
	.loc 1 38750 45 view .LVU10713
	addq	$1, %rdx
.LVL2583:
	.loc 1 38750 45 is_stmt 0 view .LVU10714
	cmpq	%rsi, %rdx
	jne	.L1748
	jmp	.L1747
.LVL2584:
.L1785:
	.loc 1 38750 45 view .LVU10715
.LBE7464:
.LBE7473:
.LBE7482:
.LBE7544:
.LBB7545:
.LBB7536:
.LBB7529:
.LBB7495:
	.loc 1 38825 36 view .LVU10716
	xorl	%ecx, %ecx
.LVL2585:
	.p2align 4,,10
	.p2align 3
.L1792:
	.loc 1 38825 21 is_stmt 1 view .LVU10717
	.loc 1 38825 79 is_stmt 0 view .LVU10718
	movzwl	(%rax,%rcx,2), %esi
	.loc 1 38825 50 view .LVU10719
	movw	%si, (%rdx,%rcx,2)
	.loc 1 38826 21 is_stmt 1 view .LVU10720
	.loc 1 38826 73 is_stmt 0 view .LVU10721
	movzwl	0(%r13,%rcx,2), %esi
	.loc 1 38826 50 view .LVU10722
	movw	%si, (%rax,%rcx,2)
	.loc 1 38824 17 is_stmt 1 view .LVU10723
.LVL2586:
	.loc 1 38824 45 view .LVU10724
	addq	$1, %rcx
.LVL2587:
	.loc 1 38824 45 is_stmt 0 view .LVU10725
	cmpq	%r8, %rcx
	jne	.L1792
	jmp	.L1791
.LVL2588:
.L1888:
	.loc 1 38824 45 view .LVU10726
.LBE7495:
.LBE7529:
.LBE7536:
.LBE7545:
.LBB7546:
.LBB7483:
.LBB7474:
	movq	%r14, %r13
	movq	%r10, %rbx
.LVL2589:
.L1737:
	.loc 1 38769 9 is_stmt 1 view .LVU10727
	.loc 1 38774 9 view .LVU10728
	xorl	%eax, %eax
	cmpq	$0, -184(%rbp)
	je	.L1822
	.loc 1 38775 13 view .LVU10729
	.loc 1 38776 13 view .LVU10730
	.loc 1 38776 54 is_stmt 0 view .LVU10731
	movq	-184(%rbp), %r15
	movq	%r13, %rdi
	movq	%r15, %rsi
	call	_ZL41ma_linear_resampler_interpolate_frame_s16P19ma_linear_resamplerPs
.LVL2590:
	.loc 1 38778 13 is_stmt 1 view .LVU10732
	.loc 1 38778 49 is_stmt 0 view .LVU10733
	movl	4(%r13), %eax
	.loc 1 38778 27 view .LVU10734
	leaq	(%r15,%rax,2), %rax
	movq	%rax, -184(%rbp)
.LVL2591:
	.loc 1 38784 32 view .LVU10735
	movl	40(%r13), %eax
.LVL2592:
.L1822:
	.loc 1 38781 9 is_stmt 1 view .LVU10736
	.loc 1 38784 9 view .LVU10737
	.loc 1 38784 32 is_stmt 0 view .LVU10738
	addl	32(%r13), %eax
	.loc 1 38786 58 view .LVU10739
	movl	12(%r13), %edx
	.loc 1 38784 32 view .LVU10740
	movl	%eax, 40(%r13)
	.loc 1 38785 9 is_stmt 1 view .LVU10741
	.loc 1 38784 32 is_stmt 0 view .LVU10742
	movl	%eax, %r14d
	.loc 1 38785 32 view .LVU10743
	movl	36(%r13), %eax
	addl	44(%r13), %eax
	.loc 1 38781 28 view .LVU10744
	addq	$1, -176(%rbp)
.LVL2593:
	.loc 1 38785 32 view .LVU10745
	movl	%eax, 44(%r13)
	.loc 1 38786 9 is_stmt 1 view .LVU10746
	cmpl	%edx, %eax
	jb	.L1775
	.loc 1 38787 13 view .LVU10747
	.loc 1 38787 36 is_stmt 0 view .LVU10748
	subl	%edx, %eax
	.loc 1 38788 36 view .LVU10749
	addl	$1, %r14d
	.loc 1 38787 36 view .LVU10750
	movl	%eax, 44(%r13)
	.loc 1 38788 13 is_stmt 1 view .LVU10751
	.loc 1 38788 36 is_stmt 0 view .LVU10752
	movl	%r14d, 40(%r13)
.L1775:
.LVL2594:
	.loc 1 38788 36 view .LVU10753
.LBE7474:
	.loc 1 38744 5 is_stmt 1 view .LVU10754
	.loc 1 38744 31 view .LVU10755
	movq	-176(%rbp), %rdi
	cmpq	%rdi, -200(%rbp)
	jne	.L1736
.L1826:
.LBB7475:
	.loc 1 38746 42 is_stmt 0 view .LVU10756
	movq	%r12, -56(%rbp)
.LVL2595:
	.loc 1 38746 42 view .LVU10757
	jmp	.L1735
.LVL2596:
.L1827:
.LBB7465:
	.loc 1 38751 36 view .LVU10758
	movl	%ebx, %edi
	.loc 1 38750 31 view .LVU10759
	xorl	%edx, %edx
	jmp	.L1742
.L1751:
	.loc 1 38757 36 view .LVU10760
	movq	-192(%rbp), %rsi
	xorl	%edx, %edx
.LVL2597:
.L1760:
	.loc 1 38757 21 is_stmt 1 view .LVU10761
	.loc 1 38757 79 is_stmt 0 view .LVU10762
	movzwl	0(%r13,%rdx,2), %ecx
	.loc 1 38758 50 view .LVU10763
	xorl	%r15d, %r15d
	.loc 1 38757 50 view .LVU10764
	movw	%cx, (%rax,%rdx,2)
	.loc 1 38758 21 is_stmt 1 view .LVU10765
	.loc 1 38758 50 is_stmt 0 view .LVU10766
	movw	%r15w, 0(%r13,%rdx,2)
	.loc 1 38756 17 is_stmt 1 view .LVU10767
.LVL2598:
	.loc 1 38756 45 view .LVU10768
	addq	$1, %rdx
.LVL2599:
	.loc 1 38756 45 is_stmt 0 view .LVU10769
	cmpq	%rdx, %rsi
	jne	.L1760
	jmp	.L1749
.LVL2600:
.L1795:
	.loc 1 38756 45 view .LVU10770
.LBE7465:
.LBE7475:
.LBE7483:
.LBE7546:
.LBB7547:
.LBB7537:
.LBB7530:
.LBB7496:
	.loc 1 38831 36 view .LVU10771
	xorl	%ecx, %ecx
.LVL2601:
.L1804:
	.loc 1 38831 21 is_stmt 1 view .LVU10772
	.loc 1 38831 79 is_stmt 0 view .LVU10773
	movzwl	(%rax,%rcx,2), %esi
	.loc 1 38831 50 view .LVU10774
	movw	%si, (%rdx,%rcx,2)
	.loc 1 38832 21 is_stmt 1 view .LVU10775
	.loc 1 38832 50 is_stmt 0 view .LVU10776
	xorl	%esi, %esi
	movw	%si, (%rax,%rcx,2)
	.loc 1 38830 17 is_stmt 1 view .LVU10777
.LVL2602:
	.loc 1 38830 45 view .LVU10778
	addq	$1, %rcx
.LVL2603:
	.loc 1 38830 45 is_stmt 0 view .LVU10779
	cmpq	%rcx, %r8
	jne	.L1804
	jmp	.L1793
.LVL2604:
.L1834:
	.loc 1 38825 36 view .LVU10780
	movl	%edi, %r12d
	.loc 1 38824 31 view .LVU10781
	xorl	%ecx, %ecx
	jmp	.L1786
.LVL2605:
.L1829:
	.loc 1 38824 31 view .LVU10782
.LBE7496:
.LBE7530:
.LBE7537:
.LBE7547:
.LBB7548:
.LBB7484:
.LBB7476:
.LBB7466:
	.loc 1 38757 36 view .LVU10783
	movl	%ebx, %edi
	.loc 1 38756 31 view .LVU10784
	xorl	%edx, %edx
	jmp	.L1752
.LVL2606:
.L1892:
	.loc 1 38756 31 view .LVU10785
.LBE7466:
.LBE7476:
.LBE7484:
.LBE7548:
.LBB7549:
.LBB7538:
.LBB7531:
	.loc 1 38846 13 is_stmt 1 view .LVU10786
	.loc 1 38847 13 view .LVU10787
	.loc 1 38847 54 is_stmt 0 view .LVU10788
	movq	%r12, %rsi
	movq	%r14, %rdi
	call	_ZL41ma_linear_resampler_interpolate_frame_s16P19ma_linear_resamplerPs
.LVL2607:
	.loc 1 38850 13 is_stmt 1 view .LVU10789
.LBB7497:
.LBI7497:
	.loc 1 34030 23 view .LVU10790
.LBB7498:
	.loc 1 34032 5 view .LVU10791
	.loc 1 34033 5 view .LVU10792
	.loc 1 34035 5 view .LVU10793
	cmpl	$2, 64(%r14)
	jne	.L1806
	.loc 1 34037 5 view .LVU10794
.LVL2608:
	.loc 1 34037 5 is_stmt 0 view .LVU10795
.LBE7498:
.LBE7497:
.LBE7531:
.LBE7538:
.LBE7549:
	.loc 2 2066 91 is_stmt 1 view .LVU10796
.LBB7550:
.LBB7539:
.LBB7532:
.LBB7523:
.LBB7520:
	.loc 1 34039 5 view .LVU10797
	.loc 1 34039 27 view .LVU10798
	.loc 1 34039 35 is_stmt 0 view .LVU10799
	movl	76(%r14), %edx
	.loc 1 34039 27 view .LVU10800
	pxor	%xmm1, %xmm1
	testl	%edx, %edx
	je	.L1811
	.loc 1 34040 46 view .LVU10801
	movq	88(%r14), %rax
	subl	$1, %edx
.LBB7499:
.LBB7500:
	.loc 1 33458 20 view .LVU10802
	movl	$16384, %ebx
	leaq	(%rdx,%rdx,4), %rdx
	leaq	4(%rax), %r10
	leaq	44(%rax,%rdx,8), %r11
.LVL2609:
.L1812:
	.loc 1 33458 20 view .LVU10803
.LBE7500:
.LBE7499:
	.loc 1 34040 9 is_stmt 1 view .LVU10804
.LBB7504:
.LBI7499:
	.loc 1 33453 23 view .LVU10805
.LBB7503:
	.loc 1 33455 5 view .LVU10806
	.loc 1 33456 5 view .LVU10807
	.loc 1 33457 20 is_stmt 0 view .LVU10808
	movl	4(%r10), %edi
	.loc 1 33456 21 view .LVU10809
	movl	(%r10), %esi
.LVL2610:
	.loc 1 33457 5 is_stmt 1 view .LVU10810
	.loc 1 33458 5 view .LVU10811
	.loc 1 33458 20 is_stmt 0 view .LVU10812
	movl	%ebx, %r8d
	subl	%edi, %r8d
.LVL2611:
	.loc 1 33460 5 is_stmt 1 view .LVU10813
	.loc 1 33460 5 view .LVU10814
.LBB7501:
	.loc 1 33461 19 view .LVU10815
	testl	%esi, %esi
	je	.L1813
.LBB7502:
	.loc 1 33462 29 is_stmt 0 view .LVU10816
	movq	12(%r10), %rcx
	xorl	%edx, %edx
.LVL2612:
	.p2align 4,,10
	.p2align 3
.L1814:
	.loc 1 33462 9 is_stmt 1 view .LVU10817
	.loc 1 33463 9 view .LVU10818
	.loc 1 33464 9 view .LVU10819
	.loc 1 33466 9 view .LVU10820
	.loc 1 33463 18 is_stmt 0 view .LVU10821
	movswl	(%r12,%rdx,2), %eax
	.loc 1 33466 21 view .LVU10822
	movl	(%rcx,%rdx,4), %r9d
	.loc 1 33466 15 view .LVU10823
	imull	%r8d, %eax
	.loc 1 33466 21 view .LVU10824
	imull	%edi, %r9d
	.loc 1 33466 18 view .LVU10825
	addl	%r9d, %eax
	.loc 1 33466 11 view .LVU10826
	sarl	$14, %eax
.LVL2613:
	.loc 1 33468 9 is_stmt 1 view .LVU10827
	.loc 1 33468 26 is_stmt 0 view .LVU10828
	movw	%ax, (%r12,%rdx,2)
.LVL2614:
	.loc 1 33469 9 is_stmt 1 view .LVU10829
	.loc 1 33469 26 is_stmt 0 view .LVU10830
	movl	%eax, (%rcx,%rdx,4)
.LBE7502:
	.loc 1 33461 5 is_stmt 1 view .LVU10831
.LVL2615:
	.loc 1 33461 19 view .LVU10832
	addq	$1, %rdx
.LVL2616:
	.loc 1 33461 19 is_stmt 0 view .LVU10833
	cmpq	%rsi, %rdx
	jne	.L1814
.LVL2617:
.L1813:
	.loc 1 33461 19 view .LVU10834
.LBE7501:
.LBE7503:
.LBE7504:
	.loc 1 34039 5 is_stmt 1 view .LVU10835
	.loc 1 34039 27 view .LVU10836
	addq	$40, %r10
	cmpq	%r10, %r11
	jne	.L1812
.L1811:
.LVL2618:
	.loc 1 34043 27 view .LVU10837
	.loc 1 34043 35 is_stmt 0 view .LVU10838
	movl	80(%r14), %eax
	.loc 1 34043 27 view .LVU10839
	testl	%eax, %eax
	je	.L1816
	.loc 1 34044 46 view .LVU10840
	movq	96(%r14), %rdx
	subl	$1, %eax
.LBB7505:
.LBB7506:
.LBB7507:
.LBB7508:
.LBB7509:
.LBB7510:
	.loc 1 33170 25 view .LVU10841
	movq	%r14, -112(%rbp)
	salq	$6, %rax
	movq	%r13, -120(%rbp)
	leaq	68(%rdx,%rax), %rax
	leaq	4(%rdx), %r10
	movq	%rax, -96(%rbp)
.LVL2619:
.L1817:
	.loc 1 33170 25 view .LVU10842
.LBE7510:
.LBE7509:
.LBE7508:
.LBE7507:
.LBE7506:
.LBE7505:
	.loc 1 34044 9 is_stmt 1 view .LVU10843
.LBB7517:
.LBI7505:
	.loc 1 33649 23 view .LVU10844
.LBE7517:
.LBE7520:
.LBE7523:
.LBE7532:
.LBE7539:
.LBE7550:
	.loc 1 33651 5 view .LVU10845
.LBB7551:
.LBB7540:
.LBB7533:
.LBB7524:
.LBB7521:
.LBB7518:
.LBB7515:
.LBI7506:
	.loc 1 33176 23 view .LVU10846
.LBE7515:
.LBE7518:
.LBE7521:
.LBE7524:
.LBE7533:
.LBE7540:
.LBE7551:
	.loc 1 33178 5 view .LVU10847
.LBB7552:
.LBB7541:
.LBB7534:
.LBB7525:
.LBB7522:
.LBB7519:
.LBB7516:
.LBB7514:
.LBI7507:
	.loc 1 33149 23 view .LVU10848
.LBB7513:
	.loc 1 33151 5 view .LVU10849
	.loc 1 33152 5 view .LVU10850
	.loc 1 33152 21 is_stmt 0 view .LVU10851
	movl	(%r10), %r9d
.LVL2620:
	.loc 1 33153 5 is_stmt 1 view .LVU10852
	.loc 1 33153 20 is_stmt 0 view .LVU10853
	movl	4(%r10), %eax
.LVL2621:
	.loc 1 33154 5 is_stmt 1 view .LVU10854
	.loc 1 33154 20 is_stmt 0 view .LVU10855
	movl	8(%r10), %r11d
.LVL2622:
	.loc 1 33155 5 is_stmt 1 view .LVU10856
	.loc 1 33155 20 is_stmt 0 view .LVU10857
	movl	12(%r10), %ebx
.LVL2623:
	.loc 1 33156 5 is_stmt 1 view .LVU10858
	.loc 1 33156 20 is_stmt 0 view .LVU10859
	movl	16(%r10), %r13d
.LVL2624:
	.loc 1 33157 5 is_stmt 1 view .LVU10860
	.loc 1 33157 20 is_stmt 0 view .LVU10861
	movl	20(%r10), %r14d
.LVL2625:
	.loc 1 33159 5 is_stmt 1 view .LVU10862
	.loc 1 33159 5 view .LVU10863
.LBB7512:
	.loc 1 33160 19 view .LVU10864
	testl	%r9d, %r9d
	je	.L1818
.LBB7511:
	.loc 1 33161 28 is_stmt 0 view .LVU10865
	movq	28(%r10), %r8
	.loc 1 33162 28 view .LVU10866
	movq	36(%r10), %rdi
	movq	%r9, -56(%rbp)
	xorl	%edx, %edx
	movq	%r10, -88(%rbp)
	movl	%eax, %r10d
.LVL2626:
	.p2align 4,,10
	.p2align 3
.L1819:
	.loc 1 33161 9 is_stmt 1 view .LVU10867
	.loc 1 33162 9 view .LVU10868
	.loc 1 33163 9 view .LVU10869
	.loc 1 33163 18 is_stmt 0 view .LVU10870
	movswl	(%r12,%rdx,2), %ecx
.LVL2627:
	.loc 1 33164 9 is_stmt 1 view .LVU10871
	.loc 1 33166 9 view .LVU10872
	.loc 1 33166 17 is_stmt 0 view .LVU10873
	movl	%r10d, %eax
	.loc 1 33167 17 view .LVU10874
	movl	%r11d, %esi
	.loc 1 33167 24 view .LVU10875
	movl	%r13d, %r15d
	.loc 1 33170 25 view .LVU10876
	movl	$-32768, %r9d
	.loc 1 33166 17 view .LVU10877
	imull	%ecx, %eax
	.loc 1 33166 27 view .LVU10878
	addl	(%r8,%rdx,4), %eax
	.loc 1 33166 12 view .LVU10879
	sarl	$14, %eax
.LVL2628:
	.loc 1 33167 9 is_stmt 1 view .LVU10880
	.loc 1 33167 17 is_stmt 0 view .LVU10881
	imull	%ecx, %esi
	.loc 1 33167 24 view .LVU10882
	imull	%eax, %r15d
	.loc 1 33167 20 view .LVU10883
	subl	%r15d, %esi
	.loc 1 33170 37 view .LVU10884
	movl	$32767, %r15d
	.loc 1 33167 12 view .LVU10885
	addl	(%rdi,%rdx,4), %esi
.LVL2629:
	.loc 1 33168 9 is_stmt 1 view .LVU10886
	.loc 1 33170 9 view .LVU10887
	.loc 1 33170 37 is_stmt 0 view .LVU10888
	cmpl	$32767, %eax
	cmovle	%eax, %r15d
	.loc 1 33170 25 view .LVU10889
	cmpl	$-32768, %r15d
	cmovl	%r9d, %r15d
	.loc 1 33168 17 view .LVU10890
	imull	%ebx, %ecx
.LVL2630:
	.loc 1 33168 24 view .LVU10891
	imull	%r14d, %eax
.LVL2631:
	.loc 1 33170 25 view .LVU10892
	movw	%r15w, (%r12,%rdx,2)
.LVL2632:
	.loc 1 33171 9 is_stmt 1 view .LVU10893
	.loc 1 33171 25 is_stmt 0 view .LVU10894
	movl	%esi, (%r8,%rdx,4)
	.loc 1 33172 9 is_stmt 1 view .LVU10895
	.loc 1 33168 12 is_stmt 0 view .LVU10896
	subl	%eax, %ecx
.LVL2633:
	.loc 1 33168 12 view .LVU10897
	movl	%ecx, (%rdi,%rdx,4)
.LBE7511:
	.loc 1 33160 5 is_stmt 1 view .LVU10898
.LVL2634:
	.loc 1 33160 19 view .LVU10899
	addq	$1, %rdx
.LVL2635:
	.loc 1 33160 19 is_stmt 0 view .LVU10900
	cmpq	-56(%rbp), %rdx
	jne	.L1819
	movq	-88(%rbp), %r10
.LVL2636:
.L1818:
	.loc 1 33160 19 view .LVU10901
.LBE7512:
.LBE7513:
.LBE7514:
.LBE7516:
.LBE7519:
	.loc 1 34043 5 is_stmt 1 view .LVU10902
	.loc 1 34043 27 view .LVU10903
	addq	$64, %r10
.LVL2637:
	.loc 1 34043 27 is_stmt 0 view .LVU10904
	cmpq	%r10, -96(%rbp)
	jne	.L1817
	movq	-112(%rbp), %r14
	movq	-120(%rbp), %r13
.LVL2638:
.L1816:
	.loc 1 34043 27 view .LVU10905
.LBE7522:
.LBE7525:
	.loc 1 38852 13 is_stmt 1 view .LVU10906
	.loc 1 38852 49 is_stmt 0 view .LVU10907
	movl	4(%r14), %eax
	.loc 1 38858 32 view .LVU10908
	movl	40(%r14), %ebx
	.loc 1 38852 27 view .LVU10909
	leaq	(%r12,%rax,2), %r12
.LVL2639:
	.loc 1 38852 27 view .LVU10910
	jmp	.L1809
.LVL2640:
.L1836:
.LBB7526:
	.loc 1 38831 36 view .LVU10911
	movl	%edi, %r12d
	.loc 1 38830 31 view .LVU10912
	xorl	%ecx, %ecx
	jmp	.L1796
.LVL2641:
.L1833:
	.loc 1 38830 31 view .LVU10913
.LBE7526:
	.loc 1 38820 42 view .LVU10914
	movq	%r10, -64(%rbp)
.LVL2642:
	.loc 1 38820 42 view .LVU10915
	jmp	.L1779
.LVL2643:
.L1889:
	.loc 1 38820 42 view .LVU10916
.LBE7534:
	.loc 1 38808 5 view .LVU10917
	movl	$.LC127, %ecx
.LVL2644:
	.loc 1 38808 5 view .LVU10918
	movl	$38808, %edx
.LVL2645:
	.loc 1 38808 5 view .LVU10919
	movl	$.LC8, %esi
.LVL2646:
	.loc 1 38808 5 view .LVU10920
	movl	$.LC123, %edi
.LVL2647:
	.loc 1 38808 5 view .LVU10921
	call	__assert_fail
.LVL2648:
.L1890:
	.loc 1 38809 5 view .LVU10922
	movl	$.LC127, %ecx
.LVL2649:
	.loc 1 38809 5 view .LVU10923
	movl	$38809, %edx
.LVL2650:
	.loc 1 38809 5 view .LVU10924
	movl	$.LC8, %esi
.LVL2651:
	.loc 1 38809 5 view .LVU10925
	movl	$.LC124, %edi
.LVL2652:
	.loc 1 38809 5 view .LVU10926
	call	__assert_fail
.LVL2653:
	.p2align 4,,10
	.p2align 3
.L1831:
	.loc 1 38816 24 view .LVU10927
	movq	$0, -80(%rbp)
	.loc 1 38815 24 view .LVU10928
	movq	$0, -64(%rbp)
.LVL2654:
	.loc 1 38815 24 view .LVU10929
	jmp	.L1779
.LVL2655:
.L1886:
	.loc 1 38815 24 view .LVU10930
.LBE7541:
.LBE7552:
.LBB7553:
.LBB7485:
	.loc 1 38734 5 view .LVU10931
	movl	$.LC122, %ecx
.LVL2656:
	.loc 1 38734 5 view .LVU10932
	movl	$38734, %edx
.LVL2657:
	.loc 1 38734 5 view .LVU10933
	movl	$.LC8, %esi
.LVL2658:
	.loc 1 38734 5 view .LVU10934
	movl	$.LC123, %edi
.LVL2659:
	.loc 1 38734 5 view .LVU10935
	call	__assert_fail
.LVL2660:
.L1887:
	.loc 1 38735 5 view .LVU10936
	movl	$.LC122, %ecx
.LVL2661:
	.loc 1 38735 5 view .LVU10937
	movl	$38735, %edx
.LVL2662:
	.loc 1 38735 5 view .LVU10938
	movl	$.LC8, %esi
.LVL2663:
	.loc 1 38735 5 view .LVU10939
	movl	$.LC124, %edi
.LVL2664:
	.loc 1 38735 5 view .LVU10940
	call	__assert_fail
.LVL2665:
	.p2align 4,,10
	.p2align 3
.L1824:
	.loc 1 38742 24 view .LVU10941
	movq	$0, -176(%rbp)
	.loc 1 38741 24 view .LVU10942
	movq	$0, -56(%rbp)
	jmp	.L1735
.LVL2666:
.L1806:
.LBB7477:
.LBB7467:
.LBB7459:
.LBB7453:
	.loc 1 34035 5 view .LVU10943
	movl	$.LC125, %ecx
	movl	$34035, %edx
	movl	$.LC8, %esi
	movl	$.LC126, %edi
	call	__assert_fail
.LVL2667:
.L1885:
	.loc 1 34035 5 view .LVU10944
.LBE7453:
.LBE7459:
.LBE7467:
.LBE7477:
.LBE7485:
.LBE7553:
	.loc 1 38874 5 discriminator 1 view .LVU10945
	movl	$.LC120, %ecx
.LVL2668:
	.loc 1 38874 5 discriminator 1 view .LVU10946
	movl	$38874, %edx
.LVL2669:
	.loc 1 38874 5 discriminator 1 view .LVU10947
	movl	$.LC8, %esi
.LVL2670:
	.loc 1 38874 5 discriminator 1 view .LVU10948
	movl	$.LC121, %edi
.LVL2671:
	.loc 1 38874 5 discriminator 1 view .LVU10949
	call	__assert_fail
.LVL2672:
	.loc 1 38874 5 discriminator 1 view .LVU10950
	.cfi_endproc
.LFE181:
	.size	_ZL42ma_linear_resampler_process_pcm_frames_s16P19ma_linear_resamplerPKvPyPvS3_.lto_priv.0, .-_ZL42ma_linear_resampler_process_pcm_frames_s16P19ma_linear_resamplerPKvPyPvS3_.lto_priv.0
	.section	.rodata.str1.8
	.align 8
.LC128:
	.string	"ma_result ma_linear_resampler_process_pcm_frames_f32(ma_linear_resampler*, const void*, ma_uint64*, void*, ma_uint64*)"
	.align 8
.LC129:
	.string	"ma_result ma_linear_resampler_process_pcm_frames_f32_downsample(ma_linear_resampler*, const void*, ma_uint64*, void*, ma_uint64*)"
	.align 8
.LC130:
	.string	"void ma_lpf_process_pcm_frame_f32(ma_lpf*, float*, const void*)"
	.section	.rodata.str1.1
.LC131:
	.string	"pLPF->format == ma_format_f32"
	.section	.rodata.str1.8
	.align 8
.LC132:
	.string	"ma_result ma_linear_resampler_process_pcm_frames_f32_upsample(ma_linear_resampler*, const void*, ma_uint64*, void*, ma_uint64*)"
	.text
	.p2align 4
	.globl	_ZL42ma_linear_resampler_process_pcm_frames_f32P19ma_linear_resamplerPKvPyPvS3_.lto_priv.0
	.hidden	_ZL42ma_linear_resampler_process_pcm_frames_f32P19ma_linear_resamplerPKvPyPvS3_.lto_priv.0
	.type	_ZL42ma_linear_resampler_process_pcm_frames_f32P19ma_linear_resamplerPKvPyPvS3_.lto_priv.0, @function
_ZL42ma_linear_resampler_process_pcm_frames_f32P19ma_linear_resamplerPKvPyPvS3_.lto_priv.0:
.LVL2673:
.LFB184:
	.loc 1 39033 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 39033 1 is_stmt 0 view .LVU10952
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$152, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
1:	call	mcount
	.loc 1 39033 1 view .LVU10953
	.loc 1 39034 5 is_stmt 1 view .LVU10954
	.loc 1 39033 1 is_stmt 0 view .LVU10955
	movq	%rdx, -112(%rbp)
	movq	%rdi, %r13
	movq	%rsi, %r15
	movq	%rcx, %r11
	movq	%r8, -120(%rbp)
	.loc 1 39034 5 view .LVU10956
	testq	%rdi, %rdi
	je	.L2048
	.loc 1 39036 5 is_stmt 1 view .LVU10957
	.loc 1 39036 62 is_stmt 0 view .LVU10958
	movl	12(%rdi), %eax
	movl	%eax, -132(%rbp)
	.loc 1 39036 5 view .LVU10959
	cmpl	%eax, 8(%rdi)
	jbe	.L1895
	.loc 1 39037 9 is_stmt 1 view .LVU10960
.LVL2674:
.LBB7618:
.LBI7618:
	.loc 1 38884 18 view .LVU10961
.LBB7619:
	.loc 1 38886 5 view .LVU10962
	.loc 1 38887 11 view .LVU10963
	.loc 1 38888 5 view .LVU10964
	.loc 1 38889 5 view .LVU10965
	.loc 1 38890 5 view .LVU10966
	.loc 1 38891 5 view .LVU10967
	.loc 1 38893 5 view .LVU10968
	.loc 1 38894 5 view .LVU10969
	cmpq	$0, -112(%rbp)
	je	.L2049
	.loc 1 38895 5 view .LVU10970
	cmpq	$0, -120(%rbp)
	je	.L2050
	.loc 1 38897 5 view .LVU10971
.LVL2675:
	.loc 1 38898 5 view .LVU10972
	.loc 1 38899 5 view .LVU10973
	.loc 1 38899 24 is_stmt 0 view .LVU10974
	movq	(%rdx), %rax
	movq	%rax, -56(%rbp)
.LVL2676:
	.loc 1 38900 5 is_stmt 1 view .LVU10975
	.loc 1 38900 24 is_stmt 0 view .LVU10976
	movq	-120(%rbp), %rax
.LVL2677:
	.loc 1 38900 24 view .LVU10977
	movq	(%rax), %rax
	movq	%rax, -184(%rbp)
.LVL2678:
	.loc 1 38901 5 is_stmt 1 view .LVU10978
	.loc 1 38902 5 view .LVU10979
	.loc 1 38904 5 view .LVU10980
	.loc 1 38904 31 view .LVU10981
	testq	%rax, %rax
	je	.L1991
.LBB7620:
.LBB7621:
.LBB7622:
	.loc 1 38715 39 is_stmt 0 view .LVU10982
	pxor	%xmm0, %xmm0
	movq	%rcx, -128(%rbp)
.LBE7622:
.LBE7621:
	.loc 1 38906 28 view .LVU10983
	movl	40(%rdi), %r9d
.LBE7620:
	.loc 1 38901 24 view .LVU10984
	xorl	%r14d, %r14d
.LBB7696:
.LBB7657:
.LBB7652:
	.loc 1 38715 39 view .LVU10985
	movl	-132(%rbp), %eax
.LVL2679:
	.loc 1 38715 39 view .LVU10986
.LBE7652:
.LBE7657:
.LBB7658:
	.loc 1 38918 50 view .LVU10987
	pxor	%xmm1, %xmm1
	movss	.LC77(%rip), %xmm9
.LBE7658:
.LBE7696:
	.loc 1 38902 24 view .LVU10988
	movq	$0, -144(%rbp)
.LBB7697:
.LBB7684:
.LBB7653:
	.loc 1 38715 39 view .LVU10989
	cvtsi2ssq	%rax, %xmm0
	movaps	%xmm9, %xmm4
	divss	%xmm0, %xmm4
.LVL2680:
.L1901:
	.loc 1 38715 39 view .LVU10990
.LBE7653:
.LBE7684:
	.loc 1 38906 9 is_stmt 1 view .LVU10991
	.loc 1 38906 42 view .LVU10992
	testl	%r9d, %r9d
	je	.L1902
	.loc 1 38906 42 is_stmt 0 view .LVU10993
	cmpq	%r14, -56(%rbp)
	jbe	.L1993
.LBB7685:
	.loc 1 38910 66 view .LVU10994
	movl	4(%r13), %r12d
	.loc 1 38911 67 view .LVU10995
	movq	56(%r13), %rax
.LBB7659:
.LBB7660:
	.loc 1 34017 5 view .LVU10996
	movl	64(%r13), %esi
	movl	%r12d, %edx
	movl	%r12d, %ebx
	andl	$-4, %ebx
	shrl	$2, %edx
	movl	%esi, -64(%rbp)
.LBE7660:
.LBE7659:
	.loc 1 38910 66 view .LVU10997
	movq	%r12, %rsi
	leal	-1(%rdx), %ecx
	.loc 1 38917 71 view .LVU10998
	movl	%ebx, %edx
	movl	%ebx, -84(%rbp)
	.loc 1 38917 79 view .LVU10999
	salq	$2, %rdx
	addq	$1, %rcx
	movq	%rdx, -104(%rbp)
	leaq	(%rax,%rdx), %r10
	.loc 1 38916 85 view .LVU11000
	leal	1(%rbx), %edx
	salq	$4, %rcx
	movl	%edx, -88(%rbp)
	.loc 1 38917 79 view .LVU11001
	salq	$2, %rdx
	movq	%rdx, -152(%rbp)
	addq	%rax, %rdx
	movq	%rdx, -160(%rbp)
	.loc 1 38916 85 view .LVU11002
	leal	2(%rbx), %edx
	.loc 1 38917 79 view .LVU11003
	leaq	0(,%rdx,4), %rbx
	.loc 1 38916 85 view .LVU11004
	movl	%edx, -136(%rbp)
	.loc 1 38917 79 view .LVU11005
	movq	%rbx, -176(%rbp)
	addq	%rax, %rbx
	movq	%rbx, -168(%rbp)
	.loc 1 38914 30 view .LVU11006
	leaq	0(,%r12,4), %rbx
	movq	%rbx, -96(%rbp)
	leal	-1(%r12), %ebx
	movl	%ebx, -80(%rbp)
	.p2align 4,,10
	.p2align 3
.L1903:
	.loc 1 38907 13 is_stmt 1 view .LVU11007
	.loc 1 38909 13 view .LVU11008
	testq	%r15, %r15
	je	.L1904
.LVL2681:
	.loc 1 38910 45 view .LVU11009
	testl	%esi, %esi
	je	.L1911
	.loc 1 38911 36 is_stmt 0 view .LVU11010
	movq	48(%r13), %rdx
	leaq	15(%rdx), %rdi
	movq	%rdi, %r8
	subq	%rax, %r8
	cmpq	$30, %r8
	seta	%r11b
	cmpl	$2, -80(%rbp)
	seta	%r8b
	subq	%r15, %rdi
	andl	%r11d, %r8d
	cmpq	$30, %rdi
	seta	%dil
	testb	%dil, %r8b
	je	.L1906
	leaq	4(%r15), %r8
	movq	%rax, %rdi
	subq	%r8, %rdi
	cmpq	$8, %rdi
	jbe	.L1906
	xorl	%edi, %edi
.LVL2682:
.L1907:
	.loc 1 38911 21 is_stmt 1 view .LVU11011
	.loc 1 38911 50 is_stmt 0 view .LVU11012
	movups	(%rax,%rdi), %xmm6
	movups	%xmm6, (%rdx,%rdi)
	.loc 1 38912 21 is_stmt 1 view .LVU11013
	.loc 1 38912 50 is_stmt 0 view .LVU11014
	movups	(%r15,%rdi), %xmm7
	movups	%xmm7, (%rax,%rdi)
	.loc 1 38910 17 is_stmt 1 view .LVU11015
	.loc 1 38910 45 view .LVU11016
	addq	$16, %rdi
	cmpq	%rcx, %rdi
	jne	.L1907
	cmpl	%esi, -84(%rbp)
	je	.L1909
.LVL2683:
	.loc 1 38911 21 view .LVU11017
	.loc 1 38911 79 is_stmt 0 view .LVU11018
	movss	(%r10), %xmm0
	.loc 1 38911 50 view .LVU11019
	movq	-104(%rbp), %rbx
	movss	%xmm0, (%rdx,%rbx)
	.loc 1 38912 21 is_stmt 1 view .LVU11020
	.loc 1 38912 73 is_stmt 0 view .LVU11021
	movss	(%r15,%rbx), %xmm0
	.loc 1 38912 50 view .LVU11022
	movss	%xmm0, (%r10)
	.loc 1 38910 17 is_stmt 1 view .LVU11023
.LVL2684:
	.loc 1 38910 45 view .LVU11024
	cmpl	%esi, -88(%rbp)
	jnb	.L1909
	.loc 1 38911 21 view .LVU11025
	.loc 1 38911 79 is_stmt 0 view .LVU11026
	movq	-160(%rbp), %rbx
	.loc 1 38911 50 view .LVU11027
	movq	-152(%rbp), %rdi
	.loc 1 38911 79 view .LVU11028
	movss	(%rbx), %xmm0
	.loc 1 38911 50 view .LVU11029
	movss	%xmm0, (%rdx,%rdi)
	.loc 1 38912 21 is_stmt 1 view .LVU11030
	.loc 1 38912 73 is_stmt 0 view .LVU11031
	movss	(%r15,%rdi), %xmm0
	.loc 1 38912 50 view .LVU11032
	movss	%xmm0, (%rbx)
	.loc 1 38910 17 is_stmt 1 view .LVU11033
.LVL2685:
	.loc 1 38910 45 view .LVU11034
	cmpl	%esi, -136(%rbp)
	jnb	.L1909
	.loc 1 38911 21 view .LVU11035
	.loc 1 38911 79 is_stmt 0 view .LVU11036
	movq	-168(%rbp), %rbx
	.loc 1 38911 50 view .LVU11037
	movq	-176(%rbp), %rdi
	.loc 1 38911 79 view .LVU11038
	movss	(%rbx), %xmm0
	.loc 1 38911 50 view .LVU11039
	movss	%xmm0, (%rdx,%rdi)
	.loc 1 38912 21 is_stmt 1 view .LVU11040
	.loc 1 38912 73 is_stmt 0 view .LVU11041
	movss	(%r15,%rdi), %xmm0
	.loc 1 38912 50 view .LVU11042
	movss	%xmm0, (%rbx)
	.loc 1 38910 17 is_stmt 1 view .LVU11043
.LVL2686:
	.loc 1 38910 45 view .LVU11044
.L1909:
	.loc 1 38914 30 is_stmt 0 view .LVU11045
	addq	-96(%rbp), %r15
.LVL2687:
	.loc 1 38914 17 is_stmt 1 view .LVU11046
.L1911:
	.loc 1 38923 13 view .LVU11047
.LBB7679:
.LBI7659:
	.loc 1 34012 23 view .LVU11048
.LBB7674:
	.loc 1 34014 5 view .LVU11049
	.loc 1 34015 5 view .LVU11050
	.loc 1 34017 5 view .LVU11051
	cmpl	$5, -64(%rbp)
	jne	.L1972
	.loc 1 34019 5 view .LVU11052
.LVL2688:
	.loc 1 34019 5 is_stmt 0 view .LVU11053
.LBE7674:
.LBE7679:
.LBE7685:
.LBE7697:
.LBE7619:
.LBE7618:
	.loc 2 2066 91 is_stmt 1 view .LVU11054
.LBB7719:
.LBB7709:
.LBB7698:
.LBB7686:
.LBB7680:
.LBB7675:
	.loc 1 34021 5 view .LVU11055
	.loc 1 34021 27 view .LVU11056
	.loc 1 34021 35 is_stmt 0 view .LVU11057
	movl	76(%r13), %edi
	.loc 1 34021 27 view .LVU11058
	testl	%edi, %edi
	je	.L1925
	.loc 1 34022 46 view .LVU11059
	movq	88(%r13), %r8
	subl	$1, %edi
	leaq	(%rdi,%rdi,4), %rdi
	leaq	4(%r8), %rdx
	leaq	44(%r8,%rdi,8), %rbx
.LVL2689:
	.p2align 4,,10
	.p2align 3
.L1926:
	.loc 1 34022 9 is_stmt 1 view .LVU11060
.LBB7661:
.LBI7661:
	.loc 1 33433 23 view .LVU11061
.LBB7662:
	.loc 1 33435 5 view .LVU11062
	.loc 1 33436 5 view .LVU11063
	.loc 1 33437 17 is_stmt 0 view .LVU11064
	movss	4(%rdx), %xmm2
	.loc 1 33436 21 view .LVU11065
	movl	(%rdx), %edi
.LVL2690:
	.loc 1 33437 5 is_stmt 1 view .LVU11066
	.loc 1 33438 5 view .LVU11067
	.loc 1 33438 17 is_stmt 0 view .LVU11068
	movaps	%xmm9, %xmm5
	subss	%xmm2, %xmm5
.LVL2691:
	.loc 1 33440 5 is_stmt 1 view .LVU11069
	.loc 1 33440 5 view .LVU11070
.LBB7663:
	.loc 1 33441 19 view .LVU11071
	testl	%edi, %edi
	je	.L1927
.LBB7664:
	.loc 1 33442 26 is_stmt 0 view .LVU11072
	movq	12(%rdx), %r11
	xorl	%r8d, %r8d
.LVL2692:
	.p2align 4,,10
	.p2align 3
.L1928:
	.loc 1 33442 9 is_stmt 1 view .LVU11073
	.loc 1 33443 9 view .LVU11074
	.loc 1 33444 9 view .LVU11075
	.loc 1 33446 9 view .LVU11076
	.loc 1 33446 14 is_stmt 0 view .LVU11077
	movss	(%rax,%r8,4), %xmm0
	.loc 1 33446 20 view .LVU11078
	movss	(%r11,%r8,4), %xmm3
	.loc 1 33446 14 view .LVU11079
	mulss	%xmm5, %xmm0
	.loc 1 33446 20 view .LVU11080
	mulss	%xmm2, %xmm3
	.loc 1 33446 11 view .LVU11081
	addss	%xmm3, %xmm0
.LVL2693:
	.loc 1 33448 9 is_stmt 1 view .LVU11082
	.loc 1 33448 25 is_stmt 0 view .LVU11083
	movss	%xmm0, (%rax,%r8,4)
.LVL2694:
	.loc 1 33449 9 is_stmt 1 view .LVU11084
	.loc 1 33449 26 is_stmt 0 view .LVU11085
	movss	%xmm0, (%r11,%r8,4)
.LBE7664:
	.loc 1 33441 5 is_stmt 1 view .LVU11086
.LVL2695:
	.loc 1 33441 19 view .LVU11087
	addq	$1, %r8
.LVL2696:
	.loc 1 33441 19 is_stmt 0 view .LVU11088
	cmpq	%rdi, %r8
	jne	.L1928
.LVL2697:
.L1927:
	.loc 1 33441 19 view .LVU11089
.LBE7663:
.LBE7662:
.LBE7661:
	.loc 1 34021 5 is_stmt 1 view .LVU11090
	.loc 1 34021 27 view .LVU11091
	addq	$40, %rdx
	cmpq	%rbx, %rdx
	jne	.L1926
.L1925:
.LVL2698:
	.loc 1 34025 27 view .LVU11092
	.loc 1 34025 35 is_stmt 0 view .LVU11093
	movl	80(%r13), %edi
	.loc 1 34025 27 view .LVU11094
	testl	%edi, %edi
	je	.L1930
	.loc 1 34026 46 view .LVU11095
	movq	96(%r13), %r8
	subl	$1, %edi
	salq	$6, %rdi
	leaq	68(%r8,%rdi), %rbx
	leaq	4(%r8), %rdx
	movq	%rbx, -72(%rbp)
.LVL2699:
	.p2align 4,,10
	.p2align 3
.L1931:
	.loc 1 34026 9 is_stmt 1 view .LVU11096
.LBB7665:
.LBI7665:
	.loc 1 33654 23 view .LVU11097
.LBE7665:
.LBE7675:
.LBE7680:
.LBE7686:
.LBE7698:
.LBE7709:
.LBE7719:
	.loc 1 33656 5 view .LVU11098
.LBB7720:
.LBB7710:
.LBB7699:
.LBB7687:
.LBB7681:
.LBB7676:
.LBB7672:
.LBB7666:
.LBI7666:
	.loc 1 33144 23 view .LVU11099
.LBE7666:
.LBE7672:
.LBE7676:
.LBE7681:
.LBE7687:
.LBE7699:
.LBE7710:
.LBE7720:
	.loc 1 33146 5 view .LVU11100
.LBB7721:
.LBB7711:
.LBB7700:
.LBB7688:
.LBB7682:
.LBB7677:
.LBB7673:
.LBB7671:
.LBB7667:
.LBI7667:
	.loc 1 33117 23 view .LVU11101
.LBB7668:
	.loc 1 33119 5 view .LVU11102
	.loc 1 33120 5 view .LVU11103
	.loc 1 33120 21 is_stmt 0 view .LVU11104
	movl	(%rdx), %r8d
.LVL2700:
	.loc 1 33121 5 is_stmt 1 view .LVU11105
	.loc 1 33121 17 is_stmt 0 view .LVU11106
	movss	4(%rdx), %xmm5
.LVL2701:
	.loc 1 33122 5 is_stmt 1 view .LVU11107
	.loc 1 33122 17 is_stmt 0 view .LVU11108
	movss	8(%rdx), %xmm6
.LVL2702:
	.loc 1 33123 5 is_stmt 1 view .LVU11109
	.loc 1 33123 17 is_stmt 0 view .LVU11110
	movss	12(%rdx), %xmm7
.LVL2703:
	.loc 1 33124 5 is_stmt 1 view .LVU11111
	.loc 1 33124 17 is_stmt 0 view .LVU11112
	movss	16(%rdx), %xmm8
.LVL2704:
	.loc 1 33125 5 is_stmt 1 view .LVU11113
	.loc 1 33125 17 is_stmt 0 view .LVU11114
	movss	20(%rdx), %xmm10
.LVL2705:
	.loc 1 33127 5 is_stmt 1 view .LVU11115
	.loc 1 33127 5 view .LVU11116
.LBB7669:
	.loc 1 33128 19 view .LVU11117
	testl	%r8d, %r8d
	je	.L1932
.LBB7670:
	.loc 1 33129 25 is_stmt 0 view .LVU11118
	movq	28(%rdx), %rbx
	.loc 1 33130 25 view .LVU11119
	movq	36(%rdx), %r11
	xorl	%edi, %edi
.LVL2706:
	.p2align 4,,10
	.p2align 3
.L1933:
	.loc 1 33129 9 is_stmt 1 view .LVU11120
	.loc 1 33130 9 view .LVU11121
	.loc 1 33131 9 view .LVU11122
	.loc 1 33131 15 is_stmt 0 view .LVU11123
	movss	(%rax,%rdi,4), %xmm0
.LVL2707:
	.loc 1 33132 9 is_stmt 1 view .LVU11124
	.loc 1 33134 9 view .LVU11125
	.loc 1 33134 16 is_stmt 0 view .LVU11126
	movaps	%xmm5, %xmm2
	.loc 1 33135 16 view .LVU11127
	movaps	%xmm6, %xmm3
	.loc 1 33135 23 view .LVU11128
	movaps	%xmm8, %xmm11
	.loc 1 33134 16 view .LVU11129
	mulss	%xmm0, %xmm2
	.loc 1 33134 12 view .LVU11130
	addss	(%rbx,%rdi,4), %xmm2
.LVL2708:
	.loc 1 33135 9 is_stmt 1 view .LVU11131
	.loc 1 33135 16 is_stmt 0 view .LVU11132
	mulss	%xmm0, %xmm3
	.loc 1 33135 12 view .LVU11133
	addss	(%r11,%rdi,4), %xmm3
	.loc 1 33136 16 view .LVU11134
	mulss	%xmm7, %xmm0
.LVL2709:
	.loc 1 33138 25 view .LVU11135
	movss	%xmm2, (%rax,%rdi,4)
.LVL2710:
	.loc 1 33135 23 view .LVU11136
	mulss	%xmm2, %xmm11
	.loc 1 33136 23 view .LVU11137
	mulss	%xmm10, %xmm2
.LVL2711:
	.loc 1 33135 12 view .LVU11138
	subss	%xmm11, %xmm3
.LVL2712:
	.loc 1 33136 9 is_stmt 1 view .LVU11139
	.loc 1 33138 9 view .LVU11140
	.loc 1 33139 9 view .LVU11141
	.loc 1 33136 12 is_stmt 0 view .LVU11142
	subss	%xmm2, %xmm0
	.loc 1 33139 25 view .LVU11143
	movss	%xmm3, (%rbx,%rdi,4)
.LVL2713:
	.loc 1 33140 9 is_stmt 1 view .LVU11144
	.loc 1 33140 25 is_stmt 0 view .LVU11145
	movss	%xmm0, (%r11,%rdi,4)
.LBE7670:
	.loc 1 33128 5 is_stmt 1 view .LVU11146
.LVL2714:
	.loc 1 33128 19 view .LVU11147
	addq	$1, %rdi
.LVL2715:
	.loc 1 33128 19 is_stmt 0 view .LVU11148
	cmpq	%rdi, %r8
	jne	.L1933
.LVL2716:
.L1932:
	.loc 1 33128 19 view .LVU11149
.LBE7669:
.LBE7668:
.LBE7667:
.LBE7671:
.LBE7673:
	.loc 1 34025 5 is_stmt 1 view .LVU11150
	.loc 1 34025 27 view .LVU11151
	addq	$64, %rdx
.LVL2717:
	.loc 1 34025 27 is_stmt 0 view .LVU11152
	cmpq	%rdx, -72(%rbp)
	jne	.L1931
.LVL2718:
.L1930:
	.loc 1 34025 27 view .LVU11153
.LBE7677:
.LBE7682:
	.loc 1 38925 13 is_stmt 1 view .LVU11154
	.loc 1 38925 35 is_stmt 0 view .LVU11155
	addq	$1, %r14
.LVL2719:
	.loc 1 38926 13 is_stmt 1 view .LVU11156
	.loc 1 38926 35 is_stmt 0 view .LVU11157
	subl	$1, %r9d
	movl	%r9d, 40(%r13)
	.loc 1 38926 35 view .LVU11158
.LBE7688:
	.loc 1 38906 9 is_stmt 1 view .LVU11159
	.loc 1 38906 42 view .LVU11160
	je	.L1902
	cmpq	%r14, -56(%rbp)
	jne	.L1903
.LVL2720:
.L1898:
	.loc 1 38906 42 is_stmt 0 view .LVU11161
.LBE7700:
	.loc 1 38952 5 is_stmt 1 view .LVU11162
	.loc 1 38952 21 is_stmt 0 view .LVU11163
	movq	-112(%rbp), %rax
	movq	-56(%rbp), %rsi
	movq	%rsi, (%rax)
.LVL2721:
	.loc 1 38953 5 is_stmt 1 view .LVU11164
	.loc 1 38953 21 is_stmt 0 view .LVU11165
	movq	-120(%rbp), %rax
	movq	-144(%rbp), %rsi
	movq	%rsi, (%rax)
	.loc 1 38955 5 is_stmt 1 view .LVU11166
.LVL2722:
	.loc 1 38955 5 is_stmt 0 view .LVU11167
.LBE7711:
.LBE7721:
	.loc 1 39037 134 view .LVU11168
	jmp	.L2046
.LVL2723:
.L1895:
	.loc 1 39039 9 is_stmt 1 view .LVU11169
.LBB7722:
.LBI7722:
	.loc 1 38958 18 view .LVU11170
.LBB7723:
	.loc 1 38960 5 view .LVU11171
	.loc 1 38961 11 view .LVU11172
	.loc 1 38962 5 view .LVU11173
	.loc 1 38963 5 view .LVU11174
	.loc 1 38964 5 view .LVU11175
	.loc 1 38965 5 view .LVU11176
	.loc 1 38967 5 view .LVU11177
	.loc 1 38968 5 view .LVU11178
	cmpq	$0, -112(%rbp)
	je	.L2051
	.loc 1 38969 5 view .LVU11179
	cmpq	$0, -120(%rbp)
	je	.L2052
	.loc 1 38971 5 view .LVU11180
.LVL2724:
	.loc 1 38972 5 view .LVU11181
	.loc 1 38973 5 view .LVU11182
	.loc 1 38973 24 is_stmt 0 view .LVU11183
	movq	(%rdx), %rax
	movq	%rax, -64(%rbp)
.LVL2725:
	.loc 1 38974 5 is_stmt 1 view .LVU11184
	.loc 1 38974 24 is_stmt 0 view .LVU11185
	movq	-120(%rbp), %rax
.LVL2726:
	.loc 1 38974 24 view .LVU11186
	movq	(%rax), %rax
	movq	%rax, -128(%rbp)
.LVL2727:
	.loc 1 38975 5 is_stmt 1 view .LVU11187
	.loc 1 38976 5 view .LVU11188
	.loc 1 38978 5 view .LVU11189
	.loc 1 38978 31 view .LVU11190
	testq	%rax, %rax
	je	.L1995
.LBB7724:
.LBB7725:
.LBB7726:
	.loc 1 38715 39 is_stmt 0 view .LVU11191
	movl	-132(%rbp), %eax
.LVL2728:
	.loc 1 38715 39 view .LVU11192
	pxor	%xmm0, %xmm0
.LBE7726:
.LBE7725:
	.loc 1 38980 28 view .LVU11193
	movl	40(%rdi), %ebx
.LBE7724:
	.loc 1 38975 24 view .LVU11194
	xorl	%r14d, %r14d
	movss	.LC77(%rip), %xmm9
	.loc 1 38976 24 view .LVU11195
	movq	$0, -80(%rbp)
.LBB7790:
.LBB7760:
	.loc 1 38992 50 view .LVU11196
	pxor	%xmm8, %xmm8
.LBE7760:
.LBB7761:
.LBB7756:
	.loc 1 38715 39 view .LVU11197
	cvtsi2ssq	%rax, %xmm0
	movaps	%xmm9, %xmm10
	divss	%xmm0, %xmm10
.LVL2729:
.L1947:
	.loc 1 38715 39 view .LVU11198
.LBE7756:
.LBE7761:
	.loc 1 38980 9 is_stmt 1 view .LVU11199
	.loc 1 38980 42 view .LVU11200
	testl	%ebx, %ebx
	je	.L1948
	.loc 1 38980 42 is_stmt 0 view .LVU11201
	movq	-64(%rbp), %rdx
	cmpq	%rdx, %r14
	jnb	.L1997
.LBE7790:
.LBE7723:
.LBE7722:
.LBB7810:
.LBB7712:
.LBB7701:
.LBB7689:
	.loc 1 38910 66 view .LVU11202
	movl	4(%r13), %r9d
	movq	%r11, -144(%rbp)
	movq	%rdx, %r11
.LVL2730:
	.loc 1 38910 66 view .LVU11203
	movl	%r9d, %eax
	movl	%r9d, %r12d
	movq	%r9, %rcx
	andl	$-4, %r12d
	shrl	$2, %eax
	leal	-1(%rax), %esi
.LBE7689:
.LBE7701:
.LBE7712:
.LBE7810:
.LBB7811:
.LBB7801:
.LBB7791:
.LBB7762:
	.loc 1 38990 85 view .LVU11204
	leal	1(%r12), %eax
	.loc 1 38991 71 view .LVU11205
	movl	%r12d, %r10d
	.loc 1 38990 85 view .LVU11206
	movl	%eax, -84(%rbp)
	.loc 1 38991 79 view .LVU11207
	salq	$2, %rax
	addq	$1, %rsi
	salq	$2, %r10
	movq	%rax, -104(%rbp)
	.loc 1 38990 85 view .LVU11208
	leal	2(%r12), %eax
	salq	$4, %rsi
	movl	%eax, -88(%rbp)
	.loc 1 38991 79 view .LVU11209
	salq	$2, %rax
	movq	%rax, -96(%rbp)
	.loc 1 38988 30 view .LVU11210
	leaq	0(,%r9,4), %rax
	movq	%rax, -72(%rbp)
	leal	-1(%r9), %eax
	movl	%eax, -56(%rbp)
.L1949:
	.loc 1 38981 13 is_stmt 1 view .LVU11211
	.loc 1 38983 13 view .LVU11212
	testq	%r15, %r15
	je	.L1950
.LVL2731:
	.loc 1 38984 45 view .LVU11213
	testl	%ecx, %ecx
	je	.L1957
	.loc 1 38985 67 is_stmt 0 view .LVU11214
	movq	56(%r13), %rax
	.loc 1 38985 36 view .LVU11215
	movq	48(%r13), %rdx
	leaq	15(%rax), %rdi
	subq	%rdx, %rdi
	cmpq	$30, %rdi
	seta	%r8b
	cmpl	$2, -56(%rbp)
	seta	%dil
	andl	%r8d, %edi
	leaq	15(%rdx), %r8
	subq	%r15, %r8
	cmpq	$30, %r8
	seta	%r8b
	testb	%r8b, %dil
	je	.L1952
	leaq	4(%r15), %r8
	movq	%rax, %rdi
	subq	%r8, %rdi
	cmpq	$8, %rdi
	jbe	.L1952
	xorl	%edi, %edi
.LVL2732:
.L1953:
	.loc 1 38985 21 is_stmt 1 view .LVU11216
	.loc 1 38985 50 is_stmt 0 view .LVU11217
	movups	(%rax,%rdi), %xmm4
	movups	%xmm4, (%rdx,%rdi)
	.loc 1 38986 21 is_stmt 1 view .LVU11218
	.loc 1 38986 50 is_stmt 0 view .LVU11219
	movups	(%r15,%rdi), %xmm4
	movups	%xmm4, (%rax,%rdi)
	.loc 1 38984 17 is_stmt 1 view .LVU11220
	.loc 1 38984 45 view .LVU11221
	addq	$16, %rdi
	cmpq	%rsi, %rdi
	jne	.L1953
	cmpl	%ecx, %r12d
	je	.L1955
.LVL2733:
	.loc 1 38985 21 view .LVU11222
	.loc 1 38985 79 is_stmt 0 view .LVU11223
	leaq	(%rax,%r10), %rdi
	movss	(%rdi), %xmm0
	.loc 1 38985 50 view .LVU11224
	movss	%xmm0, (%rdx,%r10)
	.loc 1 38986 21 is_stmt 1 view .LVU11225
	.loc 1 38986 73 is_stmt 0 view .LVU11226
	movss	(%r15,%r10), %xmm0
	.loc 1 38986 50 view .LVU11227
	movss	%xmm0, (%rdi)
	.loc 1 38984 17 is_stmt 1 view .LVU11228
.LVL2734:
	.loc 1 38984 45 view .LVU11229
	cmpl	-84(%rbp), %ecx
	jbe	.L1955
	.loc 1 38985 21 view .LVU11230
	.loc 1 38985 79 is_stmt 0 view .LVU11231
	movq	-104(%rbp), %r8
	leaq	(%rax,%r8), %rdi
	movss	(%rdi), %xmm0
	.loc 1 38985 50 view .LVU11232
	movss	%xmm0, (%rdx,%r8)
	.loc 1 38986 21 is_stmt 1 view .LVU11233
	.loc 1 38986 73 is_stmt 0 view .LVU11234
	movss	(%r15,%r8), %xmm0
	.loc 1 38986 50 view .LVU11235
	movss	%xmm0, (%rdi)
	.loc 1 38984 17 is_stmt 1 view .LVU11236
.LVL2735:
	.loc 1 38984 45 view .LVU11237
	cmpl	-88(%rbp), %ecx
	jbe	.L1955
	.loc 1 38985 21 view .LVU11238
	.loc 1 38985 79 is_stmt 0 view .LVU11239
	movq	-96(%rbp), %rdi
	addq	%rdi, %rax
	movss	(%rax), %xmm0
	.loc 1 38985 50 view .LVU11240
	movss	%xmm0, (%rdx,%rdi)
	.loc 1 38986 21 is_stmt 1 view .LVU11241
	.loc 1 38986 73 is_stmt 0 view .LVU11242
	movss	(%r15,%rdi), %xmm0
	.loc 1 38986 50 view .LVU11243
	movss	%xmm0, (%rax)
	.loc 1 38984 17 is_stmt 1 view .LVU11244
.LVL2736:
	.loc 1 38984 45 view .LVU11245
.L1955:
	.loc 1 38988 30 is_stmt 0 view .LVU11246
	addq	-72(%rbp), %r15
.LVL2737:
	.loc 1 38988 17 is_stmt 1 view .LVU11247
.L1957:
	.loc 1 38996 13 view .LVU11248
	.loc 1 38996 35 is_stmt 0 view .LVU11249
	addq	$1, %r14
.LVL2738:
	.loc 1 38997 13 is_stmt 1 view .LVU11250
	.loc 1 38997 35 is_stmt 0 view .LVU11251
	subl	$1, %ebx
	movl	%ebx, 40(%r13)
	.loc 1 38997 35 view .LVU11252
.LBE7762:
	.loc 1 38980 9 is_stmt 1 view .LVU11253
	.loc 1 38980 42 view .LVU11254
	je	.L2053
.L2047:
	.loc 1 38980 42 is_stmt 0 view .LVU11255
	cmpq	%r14, %r11
	jne	.L1949
.LVL2739:
.L1944:
	.loc 1 38980 42 view .LVU11256
.LBE7791:
	.loc 1 39026 5 is_stmt 1 view .LVU11257
	.loc 1 39026 21 is_stmt 0 view .LVU11258
	movq	-112(%rbp), %rax
	movq	-64(%rbp), %rsi
	movq	%rsi, (%rax)
.LVL2740:
	.loc 1 39027 5 is_stmt 1 view .LVU11259
	.loc 1 39027 21 is_stmt 0 view .LVU11260
	movq	-120(%rbp), %rax
	movq	-80(%rbp), %rsi
	movq	%rsi, (%rax)
	.loc 1 39029 5 is_stmt 1 view .LVU11261
.LVL2741:
.L2046:
	.loc 1 39029 5 is_stmt 0 view .LVU11262
.LBE7801:
.LBE7811:
	.loc 1 39041 1 view .LVU11263
	addq	$152, %rsp
	xorl	%eax, %eax
	popq	%rbx
	popq	%r12
	popq	%r13
.LVL2742:
	.loc 1 39041 1 view .LVU11264
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL2743:
.L1904:
	.cfi_restore_state
.LBB7812:
.LBB7713:
.LBB7702:
.LBB7690:
	.loc 1 38916 45 is_stmt 1 view .LVU11265
	testl	%esi, %esi
	je	.L1911
	.loc 1 38917 36 is_stmt 0 view .LVU11266
	movq	48(%r13), %rdi
	leaq	15(%rdi), %rdx
	subq	%rax, %rdx
	cmpq	$30, %rdx
	movl	$0, %edx
	jbe	.L1919
	cmpl	$2, -80(%rbp)
	jbe	.L1919
.LVL2744:
	.p2align 4,,10
	.p2align 3
.L1915:
	.loc 1 38917 21 is_stmt 1 view .LVU11267
	.loc 1 38917 50 is_stmt 0 view .LVU11268
	movups	(%rax,%rdx), %xmm5
	movups	%xmm5, (%rdi,%rdx)
	.loc 1 38918 21 is_stmt 1 view .LVU11269
	.loc 1 38918 50 is_stmt 0 view .LVU11270
	movups	%xmm1, (%rax,%rdx)
	.loc 1 38916 17 is_stmt 1 view .LVU11271
	.loc 1 38916 45 view .LVU11272
	addq	$16, %rdx
	cmpq	%rcx, %rdx
	jne	.L1915
	cmpl	%esi, -84(%rbp)
	je	.L1911
.LVL2745:
	.loc 1 38917 21 view .LVU11273
	.loc 1 38917 79 is_stmt 0 view .LVU11274
	movss	(%r10), %xmm0
	.loc 1 38917 50 view .LVU11275
	movq	-104(%rbp), %rbx
	movss	%xmm0, (%rdi,%rbx)
	.loc 1 38918 21 is_stmt 1 view .LVU11276
	.loc 1 38918 50 is_stmt 0 view .LVU11277
	movl	$0x00000000, (%r10)
	.loc 1 38916 17 is_stmt 1 view .LVU11278
.LVL2746:
	.loc 1 38916 45 view .LVU11279
	cmpl	%esi, -88(%rbp)
	jnb	.L1911
	.loc 1 38917 21 view .LVU11280
	.loc 1 38917 79 is_stmt 0 view .LVU11281
	movq	-160(%rbp), %rbx
	.loc 1 38917 50 view .LVU11282
	movq	-152(%rbp), %rdx
	.loc 1 38917 79 view .LVU11283
	movss	(%rbx), %xmm0
	.loc 1 38917 50 view .LVU11284
	movss	%xmm0, (%rdi,%rdx)
	.loc 1 38918 21 is_stmt 1 view .LVU11285
	.loc 1 38918 50 is_stmt 0 view .LVU11286
	movl	$0x00000000, (%rbx)
	.loc 1 38916 17 is_stmt 1 view .LVU11287
.LVL2747:
	.loc 1 38916 45 view .LVU11288
	cmpl	%esi, -136(%rbp)
	jnb	.L1911
	.loc 1 38917 21 view .LVU11289
	.loc 1 38917 79 is_stmt 0 view .LVU11290
	movq	-168(%rbp), %rbx
	.loc 1 38917 50 view .LVU11291
	movq	-176(%rbp), %rdx
	.loc 1 38917 79 view .LVU11292
	movss	(%rbx), %xmm0
	.loc 1 38917 50 view .LVU11293
	movss	%xmm0, (%rdi,%rdx)
	.loc 1 38918 21 is_stmt 1 view .LVU11294
	.loc 1 38918 50 is_stmt 0 view .LVU11295
	movl	$0x00000000, (%rbx)
	.loc 1 38916 17 is_stmt 1 view .LVU11296
.LVL2748:
	.loc 1 38916 45 view .LVU11297
	jmp	.L1911
.LVL2749:
.L1919:
	.loc 1 38917 21 view .LVU11298
	.loc 1 38917 79 is_stmt 0 view .LVU11299
	movss	(%rax,%rdx,4), %xmm0
	.loc 1 38917 50 view .LVU11300
	movss	%xmm0, (%rdi,%rdx,4)
	.loc 1 38918 21 is_stmt 1 view .LVU11301
	.loc 1 38918 50 is_stmt 0 view .LVU11302
	movl	$0x00000000, (%rax,%rdx,4)
	.loc 1 38916 17 is_stmt 1 view .LVU11303
.LVL2750:
	.loc 1 38916 45 view .LVU11304
	addq	$1, %rdx
.LVL2751:
	.loc 1 38916 45 is_stmt 0 view .LVU11305
	cmpq	%r12, %rdx
	jne	.L1919
	jmp	.L1911
.LVL2752:
.L1950:
	.loc 1 38916 45 view .LVU11306
.LBE7690:
.LBE7702:
.LBE7713:
.LBE7812:
.LBB7813:
.LBB7802:
.LBB7792:
.LBB7763:
	.loc 1 38990 45 is_stmt 1 view .LVU11307
	testl	%ecx, %ecx
	je	.L1957
	.loc 1 38991 67 is_stmt 0 view .LVU11308
	movq	56(%r13), %rdx
	.loc 1 38991 36 view .LVU11309
	movq	48(%r13), %rdi
	leaq	15(%rdx), %rax
	subq	%rdi, %rax
	cmpq	$30, %rax
	movl	$0, %eax
	jbe	.L1965
	cmpl	$2, -56(%rbp)
	jbe	.L1965
.LVL2753:
	.p2align 4,,10
	.p2align 3
.L1961:
	.loc 1 38991 21 is_stmt 1 view .LVU11310
	.loc 1 38991 50 is_stmt 0 view .LVU11311
	movups	(%rdx,%rax), %xmm4
	movups	%xmm4, (%rdi,%rax)
	.loc 1 38992 21 is_stmt 1 view .LVU11312
	.loc 1 38992 50 is_stmt 0 view .LVU11313
	movups	%xmm8, (%rdx,%rax)
	.loc 1 38990 17 is_stmt 1 view .LVU11314
	.loc 1 38990 45 view .LVU11315
	addq	$16, %rax
	cmpq	%rsi, %rax
	jne	.L1961
	cmpl	%ecx, %r12d
	je	.L1957
.LVL2754:
	.loc 1 38991 21 view .LVU11316
	.loc 1 38991 79 is_stmt 0 view .LVU11317
	leaq	(%rdx,%r10), %rax
	movss	(%rax), %xmm0
	.loc 1 38991 50 view .LVU11318
	movss	%xmm0, (%rdi,%r10)
	.loc 1 38992 21 is_stmt 1 view .LVU11319
	.loc 1 38992 50 is_stmt 0 view .LVU11320
	movl	$0x00000000, (%rax)
	.loc 1 38990 17 is_stmt 1 view .LVU11321
.LVL2755:
	.loc 1 38990 45 view .LVU11322
	cmpl	-84(%rbp), %ecx
	jbe	.L1957
	.loc 1 38991 21 view .LVU11323
	.loc 1 38991 79 is_stmt 0 view .LVU11324
	movq	-104(%rbp), %r8
	leaq	(%rdx,%r8), %rax
	movss	(%rax), %xmm0
	.loc 1 38991 50 view .LVU11325
	movss	%xmm0, (%rdi,%r8)
	.loc 1 38992 21 is_stmt 1 view .LVU11326
	.loc 1 38992 50 is_stmt 0 view .LVU11327
	movl	$0x00000000, (%rax)
	.loc 1 38990 17 is_stmt 1 view .LVU11328
.LVL2756:
	.loc 1 38990 45 view .LVU11329
	cmpl	-88(%rbp), %ecx
	jbe	.L1957
	.loc 1 38991 21 view .LVU11330
	.loc 1 38991 79 is_stmt 0 view .LVU11331
	movq	-96(%rbp), %rax
	.loc 1 38996 35 view .LVU11332
	addq	$1, %r14
.LVL2757:
	.loc 1 38991 79 view .LVU11333
	addq	%rax, %rdx
	.loc 1 38997 35 view .LVU11334
	subl	$1, %ebx
	.loc 1 38991 79 view .LVU11335
	movss	(%rdx), %xmm0
	.loc 1 38991 50 view .LVU11336
	movss	%xmm0, (%rdi,%rax)
	.loc 1 38992 21 is_stmt 1 view .LVU11337
	.loc 1 38992 50 is_stmt 0 view .LVU11338
	movl	$0x00000000, (%rdx)
	.loc 1 38990 17 is_stmt 1 view .LVU11339
.LVL2758:
	.loc 1 38990 45 view .LVU11340
	.loc 1 38996 13 view .LVU11341
	.loc 1 38997 13 view .LVU11342
	.loc 1 38997 35 is_stmt 0 view .LVU11343
	movl	%ebx, 40(%r13)
	.loc 1 38997 35 view .LVU11344
.LBE7763:
	.loc 1 38980 9 is_stmt 1 view .LVU11345
	.loc 1 38980 42 view .LVU11346
	jne	.L2047
.LVL2759:
.L2053:
	.loc 1 38980 42 is_stmt 0 view .LVU11347
	movq	-144(%rbp), %r11
.LVL2760:
.L1948:
	.loc 1 39000 9 is_stmt 1 view .LVU11348
	.loc 1 39005 9 view .LVU11349
.LBB7764:
.LBB7757:
	.loc 1 38715 28 is_stmt 0 view .LVU11350
	movl	44(%r13), %r9d
.LBE7757:
.LBE7764:
	.loc 1 39005 9 view .LVU11351
	testq	%r11, %r11
	jne	.L2054
.L1975:
.LVL2761:
	.loc 1 39015 9 is_stmt 1 view .LVU11352
	.loc 1 39018 9 view .LVU11353
	.loc 1 39018 47 is_stmt 0 view .LVU11354
	movl	32(%r13), %ebx
	.loc 1 39020 9 view .LVU11355
	movl	-132(%rbp), %eax
	.loc 1 39019 32 view .LVU11356
	addl	36(%r13), %r9d
	.loc 1 39015 28 view .LVU11357
	addq	$1, -80(%rbp)
.LVL2762:
	.loc 1 39018 32 view .LVU11358
	movl	%ebx, 40(%r13)
	.loc 1 39019 9 is_stmt 1 view .LVU11359
	.loc 1 39020 9 view .LVU11360
	cmpl	%r9d, %eax
	ja	.L1986
	.loc 1 39021 13 view .LVU11361
	.loc 1 39021 36 is_stmt 0 view .LVU11362
	subl	%eax, %r9d
	.loc 1 39022 36 view .LVU11363
	addl	$1, %ebx
	.loc 1 39021 36 view .LVU11364
	movl	%r9d, 44(%r13)
	.loc 1 39022 13 is_stmt 1 view .LVU11365
	.loc 1 39022 36 is_stmt 0 view .LVU11366
	movl	%ebx, 40(%r13)
.L1987:
.LVL2763:
	.loc 1 39022 36 view .LVU11367
.LBE7792:
	.loc 1 38978 5 is_stmt 1 view .LVU11368
	.loc 1 38978 31 view .LVU11369
	movq	-80(%rbp), %rsi
	cmpq	%rsi, -128(%rbp)
	jne	.L1947
.L1997:
.LBB7793:
	.loc 1 38980 42 is_stmt 0 view .LVU11370
	movq	%r14, -64(%rbp)
.LVL2764:
	.loc 1 38980 42 view .LVU11371
	jmp	.L1944
.LVL2765:
.L1965:
.LBB7765:
	.loc 1 38991 21 is_stmt 1 view .LVU11372
	.loc 1 38991 79 is_stmt 0 view .LVU11373
	movss	(%rdx,%rax,4), %xmm0
	.loc 1 38991 50 view .LVU11374
	movss	%xmm0, (%rdi,%rax,4)
	.loc 1 38992 21 is_stmt 1 view .LVU11375
	.loc 1 38992 50 is_stmt 0 view .LVU11376
	movl	$0x00000000, (%rdx,%rax,4)
	.loc 1 38990 17 is_stmt 1 view .LVU11377
.LVL2766:
	.loc 1 38990 45 view .LVU11378
	addq	$1, %rax
.LVL2767:
	.loc 1 38990 45 is_stmt 0 view .LVU11379
	cmpq	%r9, %rax
	jne	.L1965
	jmp	.L1957
.LVL2768:
.L1906:
	.loc 1 38990 45 view .LVU11380
.LBE7765:
.LBE7793:
.LBE7802:
.LBE7813:
.LBB7814:
.LBB7714:
.LBB7703:
.LBB7691:
	.loc 1 38911 36 view .LVU11381
	xorl	%edi, %edi
.LVL2769:
	.p2align 4,,10
	.p2align 3
.L1910:
	.loc 1 38911 21 is_stmt 1 view .LVU11382
	.loc 1 38911 79 is_stmt 0 view .LVU11383
	movss	(%rax,%rdi,4), %xmm0
	.loc 1 38911 50 view .LVU11384
	movss	%xmm0, (%rdx,%rdi,4)
	.loc 1 38912 21 is_stmt 1 view .LVU11385
	.loc 1 38912 73 is_stmt 0 view .LVU11386
	movss	(%r15,%rdi,4), %xmm0
	.loc 1 38912 50 view .LVU11387
	movss	%xmm0, (%rax,%rdi,4)
	.loc 1 38910 17 is_stmt 1 view .LVU11388
.LVL2770:
	.loc 1 38910 45 view .LVU11389
	addq	$1, %rdi
.LVL2771:
	.loc 1 38910 45 is_stmt 0 view .LVU11390
	cmpq	%r12, %rdi
	jne	.L1910
	jmp	.L1909
.LVL2772:
.L1952:
	.loc 1 38910 45 view .LVU11391
.LBE7691:
.LBE7703:
.LBE7714:
.LBE7814:
.LBB7815:
.LBB7803:
.LBB7794:
.LBB7766:
	.loc 1 38985 36 view .LVU11392
	xorl	%edi, %edi
.LVL2773:
	.p2align 4,,10
	.p2align 3
.L1956:
	.loc 1 38985 21 is_stmt 1 view .LVU11393
	.loc 1 38985 79 is_stmt 0 view .LVU11394
	movss	(%rax,%rdi,4), %xmm0
	.loc 1 38985 50 view .LVU11395
	movss	%xmm0, (%rdx,%rdi,4)
	.loc 1 38986 21 is_stmt 1 view .LVU11396
	.loc 1 38986 73 is_stmt 0 view .LVU11397
	movss	(%r15,%rdi,4), %xmm0
	.loc 1 38986 50 view .LVU11398
	movss	%xmm0, (%rax,%rdi,4)
	.loc 1 38984 17 is_stmt 1 view .LVU11399
.LVL2774:
	.loc 1 38984 45 view .LVU11400
	addq	$1, %rdi
.LVL2775:
	.loc 1 38984 45 is_stmt 0 view .LVU11401
	cmpq	%r9, %rdi
	jne	.L1956
	jmp	.L1955
.LVL2776:
.L1902:
	.loc 1 38984 45 view .LVU11402
.LBE7766:
.LBE7794:
.LBE7803:
.LBE7815:
.LBB7816:
.LBB7715:
.LBB7704:
	.loc 1 38929 9 is_stmt 1 view .LVU11403
	.loc 1 38934 9 view .LVU11404
	cmpq	$0, -128(%rbp)
.LBB7692:
.LBB7654:
	.loc 1 38715 28 is_stmt 0 view .LVU11405
	movl	44(%r13), %ecx
.LBE7654:
.LBE7692:
	.loc 1 38934 9 view .LVU11406
	je	.L1989
	.loc 1 38935 13 is_stmt 1 view .LVU11407
	.loc 1 38936 13 view .LVU11408
.LVL2777:
.LBB7693:
.LBI7621:
	.loc 1 38706 13 view .LVU11409
.LBB7655:
	.loc 1 38708 5 view .LVU11410
	.loc 1 38709 5 view .LVU11411
	.loc 1 38710 5 view .LVU11412
	.loc 1 38715 9 is_stmt 0 view .LVU11413
	movl	%ecx, %eax
	pxor	%xmm2, %xmm2
	.loc 1 38710 21 view .LVU11414
	movl	4(%r13), %edx
.LVL2778:
	.loc 1 38712 5 is_stmt 1 view .LVU11415
	.loc 1 38713 5 view .LVU11416
	.loc 1 38715 5 view .LVU11417
.LBB7623:
.LBB7624:
	.loc 1 38719 73 is_stmt 0 view .LVU11418
	movq	56(%r13), %rsi
.LBE7624:
.LBE7623:
	.loc 1 38715 9 view .LVU11419
	cvtsi2ssq	%rax, %xmm2
.LBB7649:
.LBB7643:
	.loc 1 38719 50 view .LVU11420
	movq	48(%r13), %rdi
	leal	-1(%rdx), %eax
.LBE7643:
.LBE7649:
	.loc 1 38715 7 view .LVU11421
	mulss	%xmm4, %xmm2
.LVL2779:
	.loc 1 38717 5 is_stmt 1 view .LVU11422
	.loc 1 38717 5 view .LVU11423
.LBB7650:
	.loc 1 38718 19 view .LVU11424
	cmpl	$2, %eax
	jbe	.L1994
	movl	%edx, %r8d
.LBB7644:
	.loc 1 38719 50 is_stmt 0 view .LVU11425
	movq	-128(%rbp), %r9
	movaps	%xmm2, %xmm3
	xorl	%eax, %eax
	shrl	$2, %r8d
	shufps	$0, %xmm3, %xmm3
	salq	$4, %r8
.LVL2780:
.L1937:
	.loc 1 38719 9 is_stmt 1 view .LVU11426
.LBB7625:
.LBI7625:
	.loc 1 2330 24 view .LVU11427
.LBB7626:
	.loc 1 2332 5 view .LVU11428
	.loc 1 2333 5 view .LVU11429
	.loc 1 2334 5 view .LVU11430
	.loc 1 2334 5 is_stmt 0 view .LVU11431
.LBE7626:
.LBE7625:
	.loc 1 38720 9 is_stmt 1 view .LVU11432
.LBB7635:
.LBB7627:
	.loc 1 2332 11 is_stmt 0 view .LVU11433
	movups	(%rdi,%rax), %xmm6
	movups	(%rsi,%rax), %xmm0
	subps	%xmm6, %xmm0
	.loc 1 2333 11 view .LVU11434
	mulps	%xmm3, %xmm0
	.loc 1 2334 16 view .LVU11435
	addps	%xmm6, %xmm0
.LBE7627:
.LBE7635:
	.loc 1 38720 22 view .LVU11436
	movups	%xmm0, (%r9,%rax)
	.loc 1 38720 22 view .LVU11437
.LBE7644:
	.loc 1 38718 5 is_stmt 1 view .LVU11438
	.loc 1 38718 19 view .LVU11439
	addq	$16, %rax
	cmpq	%r8, %rax
	jne	.L1937
	movl	%edx, %eax
	andl	$-4, %eax
	testb	$3, %dl
	je	.L1938
.L1936:
.LVL2781:
.LBB7645:
	.loc 1 38719 9 view .LVU11440
	.loc 1 38719 77 is_stmt 0 view .LVU11441
	movl	%eax, %r8d
	.loc 1 38720 22 view .LVU11442
	movq	-128(%rbp), %rbx
	.loc 1 38719 34 view .LVU11443
	movss	(%rdi,%r8,4), %xmm3
.LVL2782:
.LBB7636:
	.loc 1 2330 24 is_stmt 1 view .LVU11444
.LBB7628:
	.loc 1 2332 5 view .LVU11445
	.loc 1 2333 5 view .LVU11446
	.loc 1 2334 5 view .LVU11447
	.loc 1 2334 5 is_stmt 0 view .LVU11448
.LBE7628:
.LBE7636:
	.loc 1 38720 9 is_stmt 1 view .LVU11449
.LBB7637:
.LBB7629:
	.loc 1 2332 11 is_stmt 0 view .LVU11450
	movss	(%rsi,%r8,4), %xmm0
	subss	%xmm3, %xmm0
	.loc 1 2333 11 view .LVU11451
	mulss	%xmm2, %xmm0
	.loc 1 2334 16 view .LVU11452
	addss	%xmm3, %xmm0
.LBE7629:
.LBE7637:
	.loc 1 38720 22 view .LVU11453
	movss	%xmm0, (%rbx,%r8,4)
.LBE7645:
	.loc 1 38718 5 is_stmt 1 view .LVU11454
	.loc 1 38718 33 is_stmt 0 view .LVU11455
	leal	1(%rax), %r8d
.LVL2783:
	.loc 1 38718 19 is_stmt 1 view .LVU11456
	cmpl	%r8d, %edx
	jbe	.L1938
.LBB7646:
	.loc 1 38719 9 view .LVU11457
	.loc 1 38719 34 is_stmt 0 view .LVU11458
	movss	(%rdi,%r8,4), %xmm3
.LVL2784:
.LBB7638:
	.loc 1 2330 24 is_stmt 1 view .LVU11459
.LBB7630:
	.loc 1 2332 5 view .LVU11460
	.loc 1 2333 5 view .LVU11461
	.loc 1 2334 5 view .LVU11462
	.loc 1 2334 5 is_stmt 0 view .LVU11463
.LBE7630:
.LBE7638:
	.loc 1 38720 9 is_stmt 1 view .LVU11464
.LBB7639:
.LBB7631:
	.loc 1 2332 11 is_stmt 0 view .LVU11465
	movss	(%rsi,%r8,4), %xmm0
.LBE7631:
.LBE7639:
.LBE7646:
	.loc 1 38718 33 view .LVU11466
	addl	$2, %eax
.LBB7647:
.LBB7640:
.LBB7632:
	.loc 1 2332 11 view .LVU11467
	subss	%xmm3, %xmm0
	.loc 1 2333 11 view .LVU11468
	mulss	%xmm2, %xmm0
	.loc 1 2334 16 view .LVU11469
	addss	%xmm3, %xmm0
.LBE7632:
.LBE7640:
	.loc 1 38720 22 view .LVU11470
	movss	%xmm0, (%rbx,%r8,4)
.LBE7647:
	.loc 1 38718 5 is_stmt 1 view .LVU11471
.LVL2785:
	.loc 1 38718 19 view .LVU11472
	cmpl	%eax, %edx
	jbe	.L1938
.LBB7648:
	.loc 1 38719 9 view .LVU11473
	.loc 1 38719 34 is_stmt 0 view .LVU11474
	movss	(%rdi,%rax,4), %xmm3
.LVL2786:
.LBB7641:
	.loc 1 2330 24 is_stmt 1 view .LVU11475
.LBB7633:
	.loc 1 2332 5 view .LVU11476
	.loc 1 2333 5 view .LVU11477
	.loc 1 2334 5 view .LVU11478
	.loc 1 2334 5 is_stmt 0 view .LVU11479
.LBE7633:
.LBE7641:
	.loc 1 38720 9 is_stmt 1 view .LVU11480
.LBB7642:
.LBB7634:
	.loc 1 2332 11 is_stmt 0 view .LVU11481
	movss	(%rsi,%rax,4), %xmm0
	subss	%xmm3, %xmm0
	.loc 1 2333 11 view .LVU11482
	mulss	%xmm2, %xmm0
	.loc 1 2334 16 view .LVU11483
	addss	%xmm3, %xmm0
.LBE7634:
.LBE7642:
	.loc 1 38720 22 view .LVU11484
	movss	%xmm0, (%rbx,%rax,4)
.LBE7648:
	.loc 1 38718 5 is_stmt 1 view .LVU11485
	.loc 1 38718 19 view .LVU11486
.LVL2787:
.L1938:
	.loc 1 38718 19 is_stmt 0 view .LVU11487
.LBE7650:
.LBE7655:
.LBE7693:
	.loc 1 38938 13 is_stmt 1 view .LVU11488
	.loc 1 38938 27 is_stmt 0 view .LVU11489
	movq	-128(%rbp), %rax
	leaq	(%rax,%rdx,4), %rax
	movq	%rax, -128(%rbp)
.LVL2788:
.L1989:
	.loc 1 38941 9 is_stmt 1 view .LVU11490
	.loc 1 38944 9 view .LVU11491
	.loc 1 38944 47 is_stmt 0 view .LVU11492
	movl	32(%r13), %r9d
	.loc 1 38946 9 view .LVU11493
	movl	-132(%rbp), %eax
	.loc 1 38945 32 view .LVU11494
	addl	36(%r13), %ecx
	.loc 1 38941 28 view .LVU11495
	addq	$1, -144(%rbp)
.LVL2789:
	.loc 1 38944 32 view .LVU11496
	movl	%r9d, 40(%r13)
	.loc 1 38945 9 is_stmt 1 view .LVU11497
	.loc 1 38946 9 view .LVU11498
	cmpl	%ecx, %eax
	ja	.L1939
	.loc 1 38947 13 view .LVU11499
	.loc 1 38947 36 is_stmt 0 view .LVU11500
	subl	%eax, %ecx
	.loc 1 38948 36 view .LVU11501
	addl	$1, %r9d
	.loc 1 38947 36 view .LVU11502
	movl	%ecx, 44(%r13)
	.loc 1 38948 13 is_stmt 1 view .LVU11503
	.loc 1 38948 36 is_stmt 0 view .LVU11504
	movl	%r9d, 40(%r13)
.L1940:
.LVL2790:
	.loc 1 38948 36 view .LVU11505
.LBE7704:
	.loc 1 38904 5 is_stmt 1 view .LVU11506
	.loc 1 38904 31 view .LVU11507
	movq	-144(%rbp), %rsi
	cmpq	%rsi, -184(%rbp)
	jne	.L1901
.L1993:
.LBB7705:
	.loc 1 38906 42 is_stmt 0 view .LVU11508
	movq	%r14, -56(%rbp)
	jmp	.L1898
.LVL2791:
.L1986:
	.loc 1 38906 42 view .LVU11509
.LBE7705:
.LBE7715:
.LBE7816:
.LBB7817:
.LBB7804:
.LBB7795:
	.loc 1 39019 32 view .LVU11510
	movl	%r9d, 44(%r13)
	jmp	.L1987
.LVL2792:
.L1939:
	.loc 1 39019 32 view .LVU11511
.LBE7795:
.LBE7804:
.LBE7817:
.LBB7818:
.LBB7716:
.LBB7706:
	.loc 1 38945 32 view .LVU11512
	movl	%ecx, 44(%r13)
	jmp	.L1940
.LVL2793:
.L2054:
	.loc 1 38945 32 view .LVU11513
.LBE7706:
.LBE7716:
.LBE7818:
.LBB7819:
.LBB7805:
.LBB7796:
	.loc 1 39006 13 is_stmt 1 view .LVU11514
	.loc 1 39007 13 view .LVU11515
.LBB7767:
.LBI7725:
	.loc 1 38706 13 view .LVU11516
.LBB7758:
	.loc 1 38708 5 view .LVU11517
	.loc 1 38709 5 view .LVU11518
	.loc 1 38710 5 view .LVU11519
	.loc 1 38715 9 is_stmt 0 view .LVU11520
	movl	%r9d, %eax
	pxor	%xmm1, %xmm1
	.loc 1 38710 21 view .LVU11521
	movl	4(%r13), %r8d
.LVL2794:
	.loc 1 38712 5 is_stmt 1 view .LVU11522
	.loc 1 38713 5 view .LVU11523
	.loc 1 38715 5 view .LVU11524
.LBB7727:
.LBB7728:
	.loc 1 38719 73 is_stmt 0 view .LVU11525
	movq	56(%r13), %rdx
.LBE7728:
.LBE7727:
	.loc 1 38715 9 view .LVU11526
	cvtsi2ssq	%rax, %xmm1
.LBB7753:
.LBB7747:
	.loc 1 38719 50 view .LVU11527
	movq	48(%r13), %rcx
	leal	-1(%r8), %eax
.LBE7747:
.LBE7753:
	.loc 1 38715 7 view .LVU11528
	mulss	%xmm10, %xmm1
.LVL2795:
	.loc 1 38717 5 is_stmt 1 view .LVU11529
	.loc 1 38717 5 view .LVU11530
.LBB7754:
	.loc 1 38718 19 view .LVU11531
	cmpl	$2, %eax
	jbe	.L1998
	movl	%r8d, %esi
	movaps	%xmm1, %xmm2
.LBB7748:
	.loc 1 38719 50 is_stmt 0 view .LVU11532
	xorl	%eax, %eax
	shrl	$2, %esi
	shufps	$0, %xmm2, %xmm2
	salq	$4, %rsi
.LVL2796:
.L1970:
	.loc 1 38719 9 is_stmt 1 view .LVU11533
.LBB7729:
.LBI7729:
	.loc 1 2330 24 view .LVU11534
.LBB7730:
	.loc 1 2332 5 view .LVU11535
	.loc 1 2333 5 view .LVU11536
	.loc 1 2334 5 view .LVU11537
	.loc 1 2334 5 is_stmt 0 view .LVU11538
.LBE7730:
.LBE7729:
	.loc 1 38720 9 is_stmt 1 view .LVU11539
.LBB7739:
.LBB7731:
	.loc 1 2332 11 is_stmt 0 view .LVU11540
	movups	(%rcx,%rax), %xmm6
	movups	(%rdx,%rax), %xmm0
	subps	%xmm6, %xmm0
	.loc 1 2333 11 view .LVU11541
	mulps	%xmm2, %xmm0
	.loc 1 2334 16 view .LVU11542
	addps	%xmm6, %xmm0
.LBE7731:
.LBE7739:
	.loc 1 38720 22 view .LVU11543
	movups	%xmm0, (%r11,%rax)
	.loc 1 38720 22 view .LVU11544
.LBE7748:
	.loc 1 38718 5 is_stmt 1 view .LVU11545
	.loc 1 38718 19 view .LVU11546
	addq	$16, %rax
	cmpq	%rsi, %rax
	jne	.L1970
	movl	%r8d, %eax
	andl	$-4, %eax
	testb	$3, %r8b
	je	.L1971
.L1969:
.LVL2797:
.LBB7749:
	.loc 1 38719 9 view .LVU11547
	.loc 1 38719 77 is_stmt 0 view .LVU11548
	movl	%eax, %esi
	.loc 1 38719 34 view .LVU11549
	movss	(%rcx,%rsi,4), %xmm2
.LVL2798:
.LBB7740:
	.loc 1 2330 24 is_stmt 1 view .LVU11550
.LBB7732:
	.loc 1 2332 5 view .LVU11551
	.loc 1 2333 5 view .LVU11552
	.loc 1 2334 5 view .LVU11553
	.loc 1 2334 5 is_stmt 0 view .LVU11554
.LBE7732:
.LBE7740:
	.loc 1 38720 9 is_stmt 1 view .LVU11555
.LBB7741:
.LBB7733:
	.loc 1 2332 11 is_stmt 0 view .LVU11556
	movss	(%rdx,%rsi,4), %xmm0
	subss	%xmm2, %xmm0
	.loc 1 2333 11 view .LVU11557
	mulss	%xmm1, %xmm0
	.loc 1 2334 16 view .LVU11558
	addss	%xmm2, %xmm0
.LBE7733:
.LBE7741:
	.loc 1 38720 22 view .LVU11559
	movss	%xmm0, (%r11,%rsi,4)
.LBE7749:
	.loc 1 38718 5 is_stmt 1 view .LVU11560
	.loc 1 38718 33 is_stmt 0 view .LVU11561
	leal	1(%rax), %esi
.LVL2799:
	.loc 1 38718 19 is_stmt 1 view .LVU11562
	cmpl	%esi, %r8d
	jbe	.L1971
.LBB7750:
	.loc 1 38719 9 view .LVU11563
	.loc 1 38719 34 is_stmt 0 view .LVU11564
	movss	(%rcx,%rsi,4), %xmm2
.LVL2800:
.LBB7742:
	.loc 1 2330 24 is_stmt 1 view .LVU11565
.LBB7734:
	.loc 1 2332 5 view .LVU11566
	.loc 1 2333 5 view .LVU11567
	.loc 1 2334 5 view .LVU11568
	.loc 1 2334 5 is_stmt 0 view .LVU11569
.LBE7734:
.LBE7742:
	.loc 1 38720 9 is_stmt 1 view .LVU11570
.LBB7743:
.LBB7735:
	.loc 1 2332 11 is_stmt 0 view .LVU11571
	movss	(%rdx,%rsi,4), %xmm0
.LBE7735:
.LBE7743:
.LBE7750:
	.loc 1 38718 33 view .LVU11572
	addl	$2, %eax
.LBB7751:
.LBB7744:
.LBB7736:
	.loc 1 2332 11 view .LVU11573
	subss	%xmm2, %xmm0
	.loc 1 2333 11 view .LVU11574
	mulss	%xmm1, %xmm0
	.loc 1 2334 16 view .LVU11575
	addss	%xmm2, %xmm0
.LBE7736:
.LBE7744:
	.loc 1 38720 22 view .LVU11576
	movss	%xmm0, (%r11,%rsi,4)
.LBE7751:
	.loc 1 38718 5 is_stmt 1 view .LVU11577
.LVL2801:
	.loc 1 38718 19 view .LVU11578
	cmpl	%r8d, %eax
	jnb	.L1971
.LBB7752:
	.loc 1 38719 9 view .LVU11579
	.loc 1 38719 34 is_stmt 0 view .LVU11580
	movss	(%rcx,%rax,4), %xmm2
.LVL2802:
.LBB7745:
	.loc 1 2330 24 is_stmt 1 view .LVU11581
.LBB7737:
	.loc 1 2332 5 view .LVU11582
	.loc 1 2333 5 view .LVU11583
	.loc 1 2334 5 view .LVU11584
	.loc 1 2334 5 is_stmt 0 view .LVU11585
.LBE7737:
.LBE7745:
	.loc 1 38720 9 is_stmt 1 view .LVU11586
.LBB7746:
.LBB7738:
	.loc 1 2332 11 is_stmt 0 view .LVU11587
	movss	(%rdx,%rax,4), %xmm0
	subss	%xmm2, %xmm0
	.loc 1 2333 11 view .LVU11588
	mulss	%xmm1, %xmm0
	.loc 1 2334 16 view .LVU11589
	addss	%xmm2, %xmm0
.LBE7738:
.LBE7746:
	.loc 1 38720 22 view .LVU11590
	movss	%xmm0, (%r11,%rax,4)
.LBE7752:
	.loc 1 38718 5 is_stmt 1 view .LVU11591
	.loc 1 38718 19 view .LVU11592
.LVL2803:
.L1971:
	.loc 1 38718 19 is_stmt 0 view .LVU11593
.LBE7754:
.LBE7758:
.LBE7767:
	.loc 1 39010 13 is_stmt 1 view .LVU11594
.LBB7768:
.LBI7768:
	.loc 1 34012 23 view .LVU11595
.LBB7769:
	.loc 1 34014 5 view .LVU11596
	.loc 1 34015 5 view .LVU11597
	.loc 1 34017 5 view .LVU11598
	cmpl	$5, 64(%r13)
	jne	.L1972
	.loc 1 34019 5 view .LVU11599
.LVL2804:
	.loc 1 34019 5 is_stmt 0 view .LVU11600
.LBE7769:
.LBE7768:
.LBE7796:
.LBE7805:
.LBE7819:
	.loc 2 2066 91 is_stmt 1 view .LVU11601
.LBB7820:
.LBB7806:
.LBB7797:
.LBB7786:
.LBB7783:
	.loc 1 34021 5 view .LVU11602
	.loc 1 34021 27 view .LVU11603
	.loc 1 34021 35 is_stmt 0 view .LVU11604
	movl	76(%r13), %edx
	.loc 1 34021 27 view .LVU11605
	testl	%edx, %edx
	je	.L1977
	.loc 1 34022 46 view .LVU11606
	movq	88(%r13), %rax
	subl	$1, %edx
	leaq	(%rdx,%rdx,4), %rdx
	leaq	4(%rax), %rsi
	leaq	44(%rax,%rdx,8), %rdi
.LVL2805:
.L1978:
	.loc 1 34022 9 is_stmt 1 view .LVU11607
.LBB7770:
.LBI7770:
	.loc 1 33433 23 view .LVU11608
.LBB7771:
	.loc 1 33435 5 view .LVU11609
	.loc 1 33436 5 view .LVU11610
	.loc 1 33437 17 is_stmt 0 view .LVU11611
	movss	4(%rsi), %xmm2
	.loc 1 33436 21 view .LVU11612
	movl	(%rsi), %ecx
.LVL2806:
	.loc 1 33437 5 is_stmt 1 view .LVU11613
	.loc 1 33438 5 view .LVU11614
	.loc 1 33438 17 is_stmt 0 view .LVU11615
	movaps	%xmm9, %xmm3
	subss	%xmm2, %xmm3
.LVL2807:
	.loc 1 33440 5 is_stmt 1 view .LVU11616
	.loc 1 33440 5 view .LVU11617
.LBB7772:
	.loc 1 33441 19 view .LVU11618
	testl	%ecx, %ecx
	je	.L1979
.LBB7773:
	.loc 1 33442 26 is_stmt 0 view .LVU11619
	movq	12(%rsi), %rdx
	xorl	%eax, %eax
.LVL2808:
	.p2align 4,,10
	.p2align 3
.L1980:
	.loc 1 33442 9 is_stmt 1 view .LVU11620
	.loc 1 33443 9 view .LVU11621
	.loc 1 33444 9 view .LVU11622
	.loc 1 33446 9 view .LVU11623
	.loc 1 33446 14 is_stmt 0 view .LVU11624
	movss	(%r11,%rax,4), %xmm0
	.loc 1 33446 20 view .LVU11625
	movss	(%rdx,%rax,4), %xmm1
	.loc 1 33446 14 view .LVU11626
	mulss	%xmm3, %xmm0
	.loc 1 33446 20 view .LVU11627
	mulss	%xmm2, %xmm1
	.loc 1 33446 11 view .LVU11628
	addss	%xmm1, %xmm0
.LVL2809:
	.loc 1 33448 9 is_stmt 1 view .LVU11629
	.loc 1 33448 25 is_stmt 0 view .LVU11630
	movss	%xmm0, (%r11,%rax,4)
.LVL2810:
	.loc 1 33449 9 is_stmt 1 view .LVU11631
	.loc 1 33449 26 is_stmt 0 view .LVU11632
	movss	%xmm0, (%rdx,%rax,4)
.LBE7773:
	.loc 1 33441 5 is_stmt 1 view .LVU11633
.LVL2811:
	.loc 1 33441 19 view .LVU11634
	addq	$1, %rax
.LVL2812:
	.loc 1 33441 19 is_stmt 0 view .LVU11635
	cmpq	%rcx, %rax
	jne	.L1980
.LVL2813:
.L1979:
	.loc 1 33441 19 view .LVU11636
.LBE7772:
.LBE7771:
.LBE7770:
	.loc 1 34021 5 is_stmt 1 view .LVU11637
	.loc 1 34021 27 view .LVU11638
	addq	$40, %rsi
	cmpq	%rdi, %rsi
	jne	.L1978
.L1977:
.LVL2814:
	.loc 1 34025 27 view .LVU11639
	.loc 1 34025 35 is_stmt 0 view .LVU11640
	movl	80(%r13), %eax
	.loc 1 34025 27 view .LVU11641
	testl	%eax, %eax
	je	.L1982
	.loc 1 34026 46 view .LVU11642
	movq	96(%r13), %rdx
	subl	$1, %eax
	salq	$6, %rax
	leaq	4(%rdx), %rdi
	leaq	68(%rdx,%rax), %r10
.LVL2815:
.L1983:
	.loc 1 34026 9 is_stmt 1 view .LVU11643
.LBB7774:
.LBI7774:
	.loc 1 33654 23 view .LVU11644
.LBE7774:
.LBE7783:
.LBE7786:
.LBE7797:
.LBE7806:
.LBE7820:
	.loc 1 33656 5 view .LVU11645
.LBB7821:
.LBB7807:
.LBB7798:
.LBB7787:
.LBB7784:
.LBB7781:
.LBB7775:
.LBI7775:
	.loc 1 33144 23 view .LVU11646
.LBE7775:
.LBE7781:
.LBE7784:
.LBE7787:
.LBE7798:
.LBE7807:
.LBE7821:
	.loc 1 33146 5 view .LVU11647
.LBB7822:
.LBB7808:
.LBB7799:
.LBB7788:
.LBB7785:
.LBB7782:
.LBB7780:
.LBB7776:
.LBI7776:
	.loc 1 33117 23 view .LVU11648
.LBB7777:
	.loc 1 33119 5 view .LVU11649
	.loc 1 33120 5 view .LVU11650
	.loc 1 33120 21 is_stmt 0 view .LVU11651
	movl	(%rdi), %esi
.LVL2816:
	.loc 1 33121 5 is_stmt 1 view .LVU11652
	.loc 1 33121 17 is_stmt 0 view .LVU11653
	movss	4(%rdi), %xmm3
.LVL2817:
	.loc 1 33122 5 is_stmt 1 view .LVU11654
	.loc 1 33122 17 is_stmt 0 view .LVU11655
	movss	8(%rdi), %xmm4
.LVL2818:
	.loc 1 33123 5 is_stmt 1 view .LVU11656
	.loc 1 33123 17 is_stmt 0 view .LVU11657
	movss	12(%rdi), %xmm5
.LVL2819:
	.loc 1 33124 5 is_stmt 1 view .LVU11658
	.loc 1 33124 17 is_stmt 0 view .LVU11659
	movss	16(%rdi), %xmm6
.LVL2820:
	.loc 1 33125 5 is_stmt 1 view .LVU11660
	.loc 1 33125 17 is_stmt 0 view .LVU11661
	movss	20(%rdi), %xmm7
.LVL2821:
	.loc 1 33127 5 is_stmt 1 view .LVU11662
	.loc 1 33127 5 view .LVU11663
.LBB7778:
	.loc 1 33128 19 view .LVU11664
	testl	%esi, %esi
	je	.L1984
.LBB7779:
	.loc 1 33129 25 is_stmt 0 view .LVU11665
	movq	28(%rdi), %rcx
	.loc 1 33130 25 view .LVU11666
	movq	36(%rdi), %rdx
	xorl	%eax, %eax
.LVL2822:
	.p2align 4,,10
	.p2align 3
.L1985:
	.loc 1 33129 9 is_stmt 1 view .LVU11667
	.loc 1 33130 9 view .LVU11668
	.loc 1 33131 9 view .LVU11669
	.loc 1 33131 15 is_stmt 0 view .LVU11670
	movss	(%r11,%rax,4), %xmm0
.LVL2823:
	.loc 1 33132 9 is_stmt 1 view .LVU11671
	.loc 1 33134 9 view .LVU11672
	.loc 1 33134 16 is_stmt 0 view .LVU11673
	movaps	%xmm3, %xmm1
	.loc 1 33135 16 view .LVU11674
	movaps	%xmm4, %xmm2
	.loc 1 33135 23 view .LVU11675
	movaps	%xmm6, %xmm11
	.loc 1 33134 16 view .LVU11676
	mulss	%xmm0, %xmm1
	.loc 1 33134 12 view .LVU11677
	addss	(%rcx,%rax,4), %xmm1
.LVL2824:
	.loc 1 33135 9 is_stmt 1 view .LVU11678
	.loc 1 33135 16 is_stmt 0 view .LVU11679
	mulss	%xmm0, %xmm2
	.loc 1 33135 12 view .LVU11680
	addss	(%rdx,%rax,4), %xmm2
	.loc 1 33136 16 view .LVU11681
	mulss	%xmm5, %xmm0
.LVL2825:
	.loc 1 33138 25 view .LVU11682
	movss	%xmm1, (%r11,%rax,4)
.LVL2826:
	.loc 1 33135 23 view .LVU11683
	mulss	%xmm1, %xmm11
	.loc 1 33136 23 view .LVU11684
	mulss	%xmm7, %xmm1
.LVL2827:
	.loc 1 33135 12 view .LVU11685
	subss	%xmm11, %xmm2
.LVL2828:
	.loc 1 33136 9 is_stmt 1 view .LVU11686
	.loc 1 33138 9 view .LVU11687
	.loc 1 33139 9 view .LVU11688
	.loc 1 33136 12 is_stmt 0 view .LVU11689
	subss	%xmm1, %xmm0
	.loc 1 33139 25 view .LVU11690
	movss	%xmm2, (%rcx,%rax,4)
.LVL2829:
	.loc 1 33140 9 is_stmt 1 view .LVU11691
	.loc 1 33140 25 is_stmt 0 view .LVU11692
	movss	%xmm0, (%rdx,%rax,4)
.LBE7779:
	.loc 1 33128 5 is_stmt 1 view .LVU11693
.LVL2830:
	.loc 1 33128 19 view .LVU11694
	addq	$1, %rax
.LVL2831:
	.loc 1 33128 19 is_stmt 0 view .LVU11695
	cmpq	%rsi, %rax
	jne	.L1985
.LVL2832:
.L1984:
	.loc 1 33128 19 view .LVU11696
.LBE7778:
.LBE7777:
.LBE7776:
.LBE7780:
.LBE7782:
	.loc 1 34025 5 is_stmt 1 view .LVU11697
	.loc 1 34025 27 view .LVU11698
	addq	$64, %rdi
.LVL2833:
	.loc 1 34025 27 is_stmt 0 view .LVU11699
	cmpq	%r10, %rdi
	jne	.L1983
.LVL2834:
.L1982:
	.loc 1 34025 27 view .LVU11700
.LBE7785:
.LBE7788:
	.loc 1 39012 13 is_stmt 1 view .LVU11701
	.loc 1 39012 27 is_stmt 0 view .LVU11702
	leaq	(%r11,%r8,4), %r11
.LVL2835:
	.loc 1 39012 27 view .LVU11703
	jmp	.L1975
.LVL2836:
.L1994:
	.loc 1 39012 27 view .LVU11704
.LBE7799:
.LBE7808:
.LBE7822:
.LBB7823:
.LBB7717:
.LBB7707:
.LBB7694:
.LBB7656:
.LBB7651:
	.loc 1 38718 12 view .LVU11705
	xorl	%eax, %eax
	jmp	.L1936
.LVL2837:
.L1998:
	.loc 1 38718 12 view .LVU11706
.LBE7651:
.LBE7656:
.LBE7694:
.LBE7707:
.LBE7717:
.LBE7823:
.LBB7824:
.LBB7809:
.LBB7800:
.LBB7789:
.LBB7759:
.LBB7755:
	xorl	%eax, %eax
	jmp	.L1969
.LVL2838:
.L2051:
	.loc 1 38718 12 view .LVU11707
.LBE7755:
.LBE7759:
.LBE7789:
.LBE7800:
	.loc 1 38968 5 view .LVU11708
	movl	$.LC132, %ecx
.LVL2839:
	.loc 1 38968 5 view .LVU11709
	movl	$38968, %edx
.LVL2840:
	.loc 1 38968 5 view .LVU11710
	movl	$.LC8, %esi
.LVL2841:
	.loc 1 38968 5 view .LVU11711
	movl	$.LC123, %edi
.LVL2842:
	.loc 1 38968 5 view .LVU11712
	call	__assert_fail
.LVL2843:
.L2052:
	.loc 1 38969 5 view .LVU11713
	movl	$.LC132, %ecx
.LVL2844:
	.loc 1 38969 5 view .LVU11714
	movl	$38969, %edx
.LVL2845:
	.loc 1 38969 5 view .LVU11715
	movl	$.LC8, %esi
.LVL2846:
	.loc 1 38969 5 view .LVU11716
	movl	$.LC124, %edi
.LVL2847:
	.loc 1 38969 5 view .LVU11717
	call	__assert_fail
.LVL2848:
	.p2align 4,,10
	.p2align 3
.L1995:
	.loc 1 38976 24 view .LVU11718
	movq	$0, -80(%rbp)
	.loc 1 38975 24 view .LVU11719
	movq	$0, -64(%rbp)
.LVL2849:
	.loc 1 38975 24 view .LVU11720
	jmp	.L1944
.LVL2850:
.L2049:
	.loc 1 38975 24 view .LVU11721
.LBE7809:
.LBE7824:
.LBB7825:
.LBB7718:
	.loc 1 38894 5 view .LVU11722
	movl	$.LC129, %ecx
.LVL2851:
	.loc 1 38894 5 view .LVU11723
	movl	$38894, %edx
.LVL2852:
	.loc 1 38894 5 view .LVU11724
	movl	$.LC8, %esi
.LVL2853:
	.loc 1 38894 5 view .LVU11725
	movl	$.LC123, %edi
.LVL2854:
	.loc 1 38894 5 view .LVU11726
	call	__assert_fail
.LVL2855:
.L2050:
	.loc 1 38895 5 view .LVU11727
	movl	$.LC129, %ecx
.LVL2856:
	.loc 1 38895 5 view .LVU11728
	movl	$38895, %edx
.LVL2857:
	.loc 1 38895 5 view .LVU11729
	movl	$.LC8, %esi
.LVL2858:
	.loc 1 38895 5 view .LVU11730
	movl	$.LC124, %edi
.LVL2859:
	.loc 1 38895 5 view .LVU11731
	call	__assert_fail
.LVL2860:
	.p2align 4,,10
	.p2align 3
.L1991:
	.loc 1 38902 24 view .LVU11732
	movq	$0, -144(%rbp)
	.loc 1 38901 24 view .LVU11733
	movq	$0, -56(%rbp)
	jmp	.L1898
.LVL2861:
.L1972:
.LBB7708:
.LBB7695:
.LBB7683:
.LBB7678:
	.loc 1 34017 5 view .LVU11734
	movl	$.LC130, %ecx
	movl	$34017, %edx
	movl	$.LC8, %esi
	movl	$.LC131, %edi
	call	__assert_fail
.LVL2862:
.L2048:
	.loc 1 34017 5 view .LVU11735
.LBE7678:
.LBE7683:
.LBE7695:
.LBE7708:
.LBE7718:
.LBE7825:
	.loc 1 39034 5 discriminator 1 view .LVU11736
	movl	$.LC128, %ecx
.LVL2863:
	.loc 1 39034 5 discriminator 1 view .LVU11737
	movl	$39034, %edx
.LVL2864:
	.loc 1 39034 5 discriminator 1 view .LVU11738
	movl	$.LC8, %esi
.LVL2865:
	.loc 1 39034 5 discriminator 1 view .LVU11739
	movl	$.LC121, %edi
.LVL2866:
	.loc 1 39034 5 discriminator 1 view .LVU11740
	call	__assert_fail
.LVL2867:
	.loc 1 39034 5 discriminator 1 view .LVU11741
	.cfi_endproc
.LFE184:
	.size	_ZL42ma_linear_resampler_process_pcm_frames_f32P19ma_linear_resamplerPKvPyPvS3_.lto_priv.0, .-_ZL42ma_linear_resampler_process_pcm_frames_f32P19ma_linear_resamplerPKvPyPvS3_.lto_priv.0
	.p2align 4
	.type	_ZL37ma_resampling_backend_process__linearPvS_PKvPyS_S2_, @function
_ZL37ma_resampling_backend_process__linearPvS_PKvPyS_S2_:
.LVL2868:
.LFB189:
	.loc 1 39269 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 39269 1 is_stmt 0 view .LVU11743
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
1:	call	mcount
	.loc 1 39269 1 view .LVU11744
	movq	%rsi, %rdi
.LVL2869:
	.loc 1 39269 1 view .LVU11745
	movq	%rdx, %rsi
.LVL2870:
	.loc 1 39269 1 view .LVU11746
	movq	%rcx, %rdx
.LVL2871:
	.loc 1 39269 1 view .LVU11747
	movq	%r8, %rcx
.LVL2872:
	.loc 1 39270 5 is_stmt 1 view .LVU11748
	.loc 1 39272 5 view .LVU11749
.LBB7828:
.LBI7828:
	.loc 1 39044 18 view .LVU11750
.LBB7829:
	.loc 1 39046 5 view .LVU11751
.LBE7829:
.LBE7828:
	.loc 1 39269 1 is_stmt 0 view .LVU11752
	movq	%r9, %r8
.LVL2873:
.LBB7834:
.LBB7830:
	.loc 1 39046 5 view .LVU11753
	testq	%rdi, %rdi
	je	.L2056
	.loc 1 39050 12 is_stmt 1 view .LVU11754
	.loc 1 39050 35 is_stmt 0 view .LVU11755
	movl	(%rdi), %eax
	.loc 1 39050 12 view .LVU11756
	cmpl	$2, %eax
	je	.L2059
	.loc 1 39052 12 is_stmt 1 view .LVU11757
	cmpl	$5, %eax
	jne	.L2058
	.loc 1 39053 9 view .LVU11758
.LBE7830:
.LBE7834:
	.loc 1 39273 1 is_stmt 0 view .LVU11759
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
.LBB7835:
.LBB7831:
	.loc 1 39053 58 view .LVU11760
	jmp	_ZL42ma_linear_resampler_process_pcm_frames_f32P19ma_linear_resamplerPKvPyPvS3_.lto_priv.0
.LVL2874:
	.p2align 4,,10
	.p2align 3
.L2059:
	.cfi_restore_state
	.loc 1 39051 9 is_stmt 1 view .LVU11761
.LBE7831:
.LBE7835:
	.loc 1 39273 1 is_stmt 0 view .LVU11762
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
.LBB7836:
.LBB7832:
	.loc 1 39051 58 view .LVU11763
	jmp	_ZL42ma_linear_resampler_process_pcm_frames_s16P19ma_linear_resamplerPKvPyPvS3_.lto_priv.0
.LVL2875:
.L2056:
	.cfi_restore_state
	.loc 1 39051 58 view .LVU11764
.LBE7832:
.LBE7836:
	.loc 1 39273 1 view .LVU11765
	movl	$-2, %eax
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL2876:
.L2058:
	.cfi_restore_state
.LBB7837:
.LBB7833:
	.loc 1 39273 1 view .LVU11766
	call	ma_linear_resampler_process_pcm_frames.part.0
.LVL2877:
	.loc 1 39273 1 view .LVU11767
.LBE7833:
.LBE7837:
	.cfi_endproc
.LFE189:
	.size	_ZL37ma_resampling_backend_process__linearPvS_PKvPyS_S2_, .-_ZL37ma_resampling_backend_process__linearPvS_PKvPyS_S2_
	.p2align 4
	.globl	_ZL34ma_channel_map_get_conversion_pathPKhjS0_j19ma_channel_mix_mode.lto_priv.0
	.hidden	_ZL34ma_channel_map_get_conversion_pathPKhjS0_j19ma_channel_mix_mode.lto_priv.0
	.type	_ZL34ma_channel_map_get_conversion_pathPKhjS0_j19ma_channel_mix_mode.lto_priv.0, @function
_ZL34ma_channel_map_get_conversion_pathPKhjS0_j19ma_channel_mix_mode.lto_priv.0:
.LVL2878:
.LFB191:
	.loc 1 39826 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 39826 1 is_stmt 0 view .LVU11769
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
1:	call	mcount
	.loc 1 39826 1 view .LVU11770
	movl	%r8d, -60(%rbp)
	movq	%rdi, %r12
	movl	%esi, %r13d
	movl	%ecx, %ebx
	.loc 1 39827 5 is_stmt 1 view .LVU11771
.LVL2879:
.LBB7899:
.LBI7899:
	.loc 1 39816 18 view .LVU11772
.LBB7900:
	.loc 1 39818 5 view .LVU11773
	cmpl	%ecx, %esi
	jne	.L2061
	.loc 1 39819 9 view .LVU11774
.LVL2880:
.LBB7901:
.LBI7901:
	.loc 1 43051 18 view .LVU11775
.LBB7902:
	.loc 1 43053 5 view .LVU11776
	.loc 1 43055 5 view .LVU11777
	cmpq	%rdx, %rdi
	je	.L2087
.LVL2881:
.LBB7903:
.LBB7904:
	.loc 1 43059 33 view .LVU11778
	testl	%esi, %esi
	je	.L2087
	testq	%rdx, %rdx
	je	.L2063
	testq	%rdi, %rdi
	je	.L2064
	movl	%esi, %ecx
.LVL2882:
	.loc 1 43059 33 is_stmt 0 view .LVU11779
	xorl	%eax, %eax
	jmp	.L2066
.LVL2883:
	.p2align 4,,10
	.p2align 3
.L2129:
	.loc 1 43059 5 is_stmt 1 view .LVU11780
	.loc 1 43059 33 view .LVU11781
	addq	$1, %rax
.LVL2884:
	.loc 1 43059 33 is_stmt 0 view .LVU11782
	cmpq	%rax, %rcx
	je	.L2087
.L2066:
.LVL2885:
	.loc 1 43060 9 is_stmt 1 view .LVU11783
.LBB7905:
.LBI7905:
	.loc 1 42261 19 view .LVU11784
.LBB7906:
	.loc 1 42263 5 view .LVU11785
	.loc 1 42266 9 view .LVU11786
	.loc 1 42270 9 view .LVU11787
	.loc 1 42270 9 is_stmt 0 view .LVU11788
.LBE7906:
.LBE7905:
.LBB7920:
.LBI7920:
	.loc 1 42261 19 is_stmt 1 view .LVU11789
.LBB7921:
	.loc 1 42263 5 view .LVU11790
	.loc 1 42266 9 view .LVU11791
	.loc 1 42270 9 view .LVU11792
	.loc 1 42270 9 is_stmt 0 view .LVU11793
.LBE7921:
.LBE7920:
	.loc 1 43060 9 view .LVU11794
	movzbl	(%r12,%rax), %esi
	cmpb	%sil, (%rdx,%rax)
	je	.L2129
.LVL2886:
.L2065:
	.loc 1 43060 9 view .LVU11795
.LBE7904:
.LBE7903:
.LBE7902:
.LBE7901:
.LBE7900:
.LBE7899:
	.loc 1 39831 5 is_stmt 1 view .LVU11796
	cmpl	$1, %ebx
	je	.L2081
.L2080:
	.loc 1 39835 5 view .LVU11797
	cmpl	$1, %r13d
	je	.L2079
	.loc 1 39839 5 view .LVU11798
	.loc 1 39847 5 view .LVU11799
.LBB7963:
	cmpl	$2, -60(%rbp)
	je	.L2127
	cmpl	%ebx, %r13d
	jne	.L2127
.LVL2887:
	.loc 1 39847 5 is_stmt 0 view .LVU11800
.LBE7963:
.LBB7964:
.LBI7964:
	.loc 1 39825 35 is_stmt 1 view .LVU11801
.LBB7965:
	.loc 1 39848 9 view .LVU11802
	.loc 1 39849 9 view .LVU11803
	.loc 1 39850 9 view .LVU11804
.LBB7966:
	.loc 1 39850 41 view .LVU11805
.LBE7966:
	.loc 1 39864 20 is_stmt 0 view .LVU11806
	movl	$4, %eax
.LBB8002:
	.loc 1 39850 41 view .LVU11807
	testl	%r13d, %r13d
	je	.L2060
.LBB7967:
	.loc 1 39851 13 is_stmt 1 view .LVU11808
.LVL2888:
	.loc 1 39852 13 view .LVU11809
.LBB7968:
.LBI7968:
	.loc 1 42261 19 view .LVU11810
.LBB7969:
	.loc 1 42263 5 view .LVU11811
.LBB7970:
.LBB7971:
.LBB7972:
.LBB7973:
.LBB7974:
	.loc 1 42303 32 is_stmt 0 view .LVU11812
	movl	$2, %r14d
.LBE7974:
.LBE7973:
.LBE7972:
.LBE7971:
.LBE7970:
	.loc 1 42263 5 view .LVU11813
	testq	%r12, %r12
	je	.L2074
.LBE7969:
.LBE7968:
.LBE7967:
.LBE8002:
.LBE7965:
.LBE7964:
	.loc 1 39835 69 view .LVU11814
	movzbl	(%r12), %r14d
.LBB8014:
.LBB8008:
.LBB8003:
.LBB7997:
.LBB7976:
.LBB7975:
	.loc 1 42266 9 is_stmt 1 view .LVU11815
	.loc 1 42270 9 view .LVU11816
	.loc 1 42270 40 is_stmt 0 view .LVU11817
	jmp	.L2074
.LVL2889:
	.p2align 4,,10
	.p2align 3
.L2061:
	.loc 1 42270 40 view .LVU11818
.LBE7975:
.LBE7976:
.LBE7997:
.LBE8003:
.LBE8008:
.LBE8014:
	.loc 1 39831 5 is_stmt 1 view .LVU11819
	cmpl	$1, %ecx
	je	.L2130
.LVL2890:
.L2070:
	.loc 1 39835 5 view .LVU11820
	cmpl	$1, %r13d
	jne	.L2127
.L2079:
	.loc 1 39835 25 is_stmt 0 discriminator 1 view .LVU11821
	testq	%r12, %r12
	je	.L2091
	.loc 1 39835 69 discriminator 2 view .LVU11822
	movzbl	(%r12), %r14d
	.loc 1 39835 51 discriminator 2 view .LVU11823
	cmpb	$1, %r14b
	je	.L2091
	.loc 1 39839 5 is_stmt 1 view .LVU11824
	.loc 1 39847 5 view .LVU11825
.LBB8015:
	cmpl	$2, -60(%rbp)
	je	.L2127
	cmpl	$1, %ebx
	jne	.L2127
.L2074:
.LVL2891:
	.loc 1 39847 5 is_stmt 0 view .LVU11826
.LBE8015:
.LBB8016:
.LBB8009:
.LBB8004:
.LBB7998:
.LBB7977:
.LBI7977:
	.loc 1 43086 18 is_stmt 1 view .LVU11827
.LBE7977:
.LBE7998:
.LBE8004:
.LBE8009:
.LBE8016:
	.loc 1 43088 5 view .LVU11828
.LBB8017:
.LBB8010:
.LBB8005:
.LBB7999:
.LBB7994:
.LBB7978:
.LBI7978:
	.loc 1 43091 18 view .LVU11829
.LBB7979:
	.loc 1 43093 5 view .LVU11830
	.loc 1 43095 5 view .LVU11831
	.loc 1 43099 33 view .LVU11832
	testl	%ebx, %ebx
	je	.L2127
	testq	%rdx, %rdx
	je	.L2096
	leal	-1(%rbx), %ecx
	addq	%rdx, %rcx
	jmp	.L2076
.LVL2892:
	.p2align 4,,10
	.p2align 3
.L2131:
	.loc 1 43099 5 view .LVU11833
	.loc 1 43099 33 view .LVU11834
	leaq	1(%rdx), %rax
	cmpq	%rdx, %rcx
	je	.L2127
	.loc 1 43099 33 is_stmt 0 view .LVU11835
	movq	%rax, %rdx
.LVL2893:
.L2076:
	.loc 1 43100 9 is_stmt 1 view .LVU11836
.LBB7980:
.LBI7980:
	.loc 1 42261 19 view .LVU11837
.LBB7981:
	.loc 1 42263 5 view .LVU11838
	.loc 1 42266 9 view .LVU11839
	.loc 1 42270 9 view .LVU11840
	.loc 1 42270 9 is_stmt 0 view .LVU11841
.LBE7981:
.LBE7980:
	.loc 1 43100 9 view .LVU11842
	cmpb	%r14b, (%rdx)
	jne	.L2131
.LVL2894:
.L2099:
	.loc 1 43100 9 view .LVU11843
.LBE7979:
.LBE7978:
.LBE7994:
.LBE7999:
.LBE8005:
.LBE8010:
.LBE8017:
	.loc 1 39870 1 view .LVU11844
	addq	$40, %rsp
.LBB8018:
.LBB8011:
	.loc 1 39864 20 view .LVU11845
	movl	$4, %eax
.LBE8011:
.LBE8018:
	.loc 1 39870 1 view .LVU11846
	popq	%rbx
.LVL2895:
	.loc 1 39870 1 view .LVU11847
	popq	%r12
	popq	%r13
.LVL2896:
	.loc 1 39870 1 view .LVU11848
	popq	%r14
.LVL2897:
	.loc 1 39870 1 view .LVU11849
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL2898:
	.p2align 4,,10
	.p2align 3
.L2127:
	.cfi_restore_state
	.loc 1 39869 12 view .LVU11850
	movl	$5, %eax
.L2060:
	.loc 1 39870 1 view .LVU11851
	addq	$40, %rsp
	popq	%rbx
.LVL2899:
	.loc 1 39870 1 view .LVU11852
	popq	%r12
	popq	%r13
.LVL2900:
	.loc 1 39870 1 view .LVU11853
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL2901:
	.p2align 4,,10
	.p2align 3
.L2130:
	.cfi_restore_state
	.loc 1 39831 26 discriminator 1 view .LVU11854
	testq	%rdx, %rdx
	je	.L2089
.LVL2902:
.L2081:
	.loc 1 39831 53 discriminator 2 view .LVU11855
	cmpb	$1, (%rdx)
	jne	.L2070
.L2089:
	.loc 1 39832 16 view .LVU11856
	movl	$2, %eax
	jmp	.L2060
.LVL2903:
	.p2align 4,,10
	.p2align 3
.L2087:
	.loc 1 39870 1 view .LVU11857
	addq	$40, %rsp
	.loc 1 39828 16 view .LVU11858
	movl	$1, %eax
	.loc 1 39870 1 view .LVU11859
	popq	%rbx
.LVL2904:
	.loc 1 39870 1 view .LVU11860
	popq	%r12
.LVL2905:
	.loc 1 39870 1 view .LVU11861
	popq	%r13
.LVL2906:
	.loc 1 39870 1 view .LVU11862
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL2907:
	.p2align 4,,10
	.p2align 3
.L2064:
	.cfi_restore_state
	.loc 1 39870 1 view .LVU11863
	movl	%esi, %eax
.LBB8019:
.LBB7959:
.LBB7955:
.LBB7951:
.LBB7947:
.LBB7943:
	.loc 1 43059 33 view .LVU11864
	xorl	%r15d, %r15d
	movq	%rax, -72(%rbp)
	jmp	.L2067
.LVL2908:
	.p2align 4,,10
	.p2align 3
.L2132:
	.loc 1 43059 5 is_stmt 1 view .LVU11865
	.loc 1 43059 33 view .LVU11866
	addq	$1, %r15
.LVL2909:
	.loc 1 43059 33 is_stmt 0 view .LVU11867
	cmpq	-72(%rbp), %r15
	je	.L2087
.L2067:
.LVL2910:
	.loc 1 43060 9 is_stmt 1 view .LVU11868
.LBB7934:
	.loc 1 42261 19 view .LVU11869
.LBB7915:
	.loc 1 42263 5 view .LVU11870
	.loc 1 42266 9 view .LVU11871
	.loc 1 42270 9 view .LVU11872
	.loc 1 42270 40 is_stmt 0 view .LVU11873
	movzbl	(%rdx,%r15), %r14d
.LBE7915:
.LBE7934:
.LBB7935:
.LBB7930:
.LBB7922:
.LBB7923:
.LBB7924:
.LBB7925:
	.loc 1 42987 66 view .LVU11874
	movl	%r15d, %esi
	movl	%ebx, %edi
.LBE7925:
.LBE7924:
.LBE7923:
.LBE7922:
.LBE7930:
.LBE7935:
.LBB7936:
.LBB7916:
	.loc 1 42270 40 view .LVU11875
	movq	%rdx, -56(%rbp)
.LVL2911:
	.loc 1 42270 40 view .LVU11876
.LBE7916:
.LBE7936:
.LBB7937:
	.loc 1 42261 19 is_stmt 1 view .LVU11877
.LBB7931:
	.loc 1 42263 5 view .LVU11878
	.loc 1 42264 9 view .LVU11879
	.loc 1 42264 9 is_stmt 0 view .LVU11880
.LBE7931:
.LBE7937:
.LBE7943:
.LBE7947:
.LBE7951:
.LBE7955:
.LBE7959:
.LBE8019:
	.loc 1 42947 5 is_stmt 1 view .LVU11881
.LBB8020:
.LBB7960:
.LBB7956:
.LBB7952:
.LBB7948:
.LBB7944:
.LBB7938:
.LBB7932:
.LBB7929:
.LBI7922:
	.loc 1 42261 19 view .LVU11882
.LBB7928:
.LBB7927:
.LBI7924:
	.loc 1 42945 19 view .LVU11883
.LBB7926:
	.loc 1 42987 66 is_stmt 0 view .LVU11884
	call	_ZL46ma_channel_map_init_standard_channel_microsoftjj.lto_priv.0
.LVL2912:
	.loc 1 42987 66 view .LVU11885
.LBE7926:
.LBE7927:
.LBE7928:
.LBE7929:
.LBE7932:
.LBE7938:
	.loc 1 43060 9 view .LVU11886
	movq	-56(%rbp), %rdx
	cmpb	%al, %r14b
	je	.L2132
.LVL2913:
	.loc 1 43060 9 view .LVU11887
	jmp	.L2065
.LVL2914:
	.p2align 4,,10
	.p2align 3
.L2091:
	.loc 1 43060 9 view .LVU11888
.LBE7944:
.LBE7948:
.LBE7952:
.LBE7956:
.LBE7960:
.LBE8020:
	.loc 1 39836 16 view .LVU11889
	movl	$3, %eax
	jmp	.L2060
.LVL2915:
	.p2align 4,,10
	.p2align 3
.L2063:
	.loc 1 39828 16 view .LVU11890
	movl	$1, %eax
	testq	%rdi, %rdi
	je	.L2060
	movl	%esi, %r14d
.LBB8021:
.LBB7961:
.LBB7957:
.LBB7953:
.LBB7949:
.LBB7945:
	.loc 1 43059 33 view .LVU11891
	xorl	%r15d, %r15d
	jmp	.L2069
.LVL2916:
	.p2align 4,,10
	.p2align 3
.L2133:
	.loc 1 43059 5 is_stmt 1 view .LVU11892
	.loc 1 43059 33 view .LVU11893
	addq	$1, %r15
.LVL2917:
	.loc 1 43059 33 is_stmt 0 view .LVU11894
	cmpq	%r15, %r14
	je	.L2087
.L2069:
.LBB7939:
.LBB7917:
.LBB7907:
.LBB7908:
.LBB7909:
.LBB7910:
	.loc 1 42987 66 view .LVU11895
	movl	%r15d, %esi
	movl	%ebx, %edi
	movq	%rdx, -56(%rbp)
.LVL2918:
	.loc 1 42987 66 view .LVU11896
.LBE7910:
.LBE7909:
.LBE7908:
.LBE7907:
.LBE7917:
.LBE7939:
	.loc 1 43060 9 is_stmt 1 view .LVU11897
.LBB7940:
	.loc 1 42261 19 view .LVU11898
.LBB7918:
	.loc 1 42263 5 view .LVU11899
	.loc 1 42264 9 view .LVU11900
	.loc 1 42264 9 is_stmt 0 view .LVU11901
.LBE7918:
.LBE7940:
.LBE7945:
.LBE7949:
.LBE7953:
.LBE7957:
.LBE7961:
.LBE8021:
	.loc 1 42947 5 is_stmt 1 view .LVU11902
.LBB8022:
.LBB7962:
.LBB7958:
.LBB7954:
.LBB7950:
.LBB7946:
.LBB7941:
.LBB7919:
.LBB7914:
.LBI7907:
	.loc 1 42261 19 view .LVU11903
.LBB7913:
.LBB7912:
.LBI7909:
	.loc 1 42945 19 view .LVU11904
.LBB7911:
	.loc 1 42987 66 is_stmt 0 view .LVU11905
	call	_ZL46ma_channel_map_init_standard_channel_microsoftjj.lto_priv.0
.LVL2919:
	.loc 1 42987 66 view .LVU11906
.LBE7911:
.LBE7912:
.LBE7913:
.LBE7914:
.LBE7919:
.LBE7941:
.LBB7942:
	.loc 1 42261 19 is_stmt 1 view .LVU11907
.LBB7933:
	.loc 1 42263 5 view .LVU11908
	.loc 1 42266 9 view .LVU11909
	.loc 1 42270 9 view .LVU11910
	.loc 1 42270 9 is_stmt 0 view .LVU11911
.LBE7933:
.LBE7942:
	.loc 1 43060 9 view .LVU11912
	cmpb	(%r12,%r15), %al
	movq	-56(%rbp), %rdx
	je	.L2133
.LVL2920:
	.loc 1 43060 9 view .LVU11913
.LBE7946:
.LBE7950:
.LBE7954:
.LBE7958:
.LBE7962:
.LBE8022:
	.loc 1 39831 5 is_stmt 1 view .LVU11914
	.loc 1 39832 16 is_stmt 0 view .LVU11915
	movl	$2, %eax
	.loc 1 39831 5 view .LVU11916
	cmpl	$1, %ebx
	jne	.L2080
	jmp	.L2060
.LVL2921:
	.p2align 4,,10
	.p2align 3
.L2096:
.LBB8023:
.LBB8012:
.LBB8006:
.LBB8000:
.LBB7995:
.LBB7992:
.LBB7990:
	.loc 1 43099 33 view .LVU11917
	xorl	%r12d, %r12d
.LVL2922:
	.loc 1 43099 33 view .LVU11918
	jmp	.L2075
.LVL2923:
	.p2align 4,,10
	.p2align 3
.L2134:
	.loc 1 43099 5 is_stmt 1 view .LVU11919
	addl	$1, %r12d
.LVL2924:
	.loc 1 43099 33 view .LVU11920
	cmpl	%r12d, %ebx
	je	.L2127
.LVL2925:
.L2075:
	.loc 1 43100 9 view .LVU11921
.LBB7988:
	.loc 1 42261 19 view .LVU11922
.LBB7986:
	.loc 1 42263 5 view .LVU11923
	.loc 1 42264 9 view .LVU11924
	.loc 1 42264 9 is_stmt 0 view .LVU11925
.LBE7986:
.LBE7988:
.LBE7990:
.LBE7992:
.LBE7995:
.LBE8000:
.LBE8006:
.LBE8012:
.LBE8023:
	.loc 1 42947 5 is_stmt 1 view .LVU11926
.LBB8024:
.LBB8013:
.LBB8007:
.LBB8001:
.LBB7996:
.LBB7993:
.LBB7991:
.LBB7989:
.LBB7987:
.LBB7982:
.LBI7982:
	.loc 1 42261 19 view .LVU11927
.LBB7983:
.LBB7984:
.LBI7984:
	.loc 1 42945 19 view .LVU11928
.LBB7985:
	.loc 1 42987 66 is_stmt 0 view .LVU11929
	movl	%r12d, %esi
	movl	%ebx, %edi
	call	_ZL46ma_channel_map_init_standard_channel_microsoftjj.lto_priv.0
.LVL2926:
	.loc 1 42987 66 view .LVU11930
.LBE7985:
.LBE7984:
.LBE7983:
.LBE7982:
.LBE7987:
.LBE7989:
	.loc 1 43100 9 view .LVU11931
	cmpb	%al, %r14b
	jne	.L2134
	jmp	.L2099
.LBE7991:
.LBE7993:
.LBE7996:
.LBE8001:
.LBE8007:
.LBE8013:
.LBE8024:
	.cfi_endproc
.LFE191:
	.size	_ZL34ma_channel_map_get_conversion_pathPKhjS0_j19ma_channel_mix_mode.lto_priv.0, .-_ZL34ma_channel_map_get_conversion_pathPKhjS0_j19ma_channel_mix_mode.lto_priv.0
	.p2align 4
	.type	_ZL33ma_data_converter_get_heap_layoutPK24ma_data_converter_configP29ma_data_converter_heap_layout, @function
_ZL33ma_data_converter_get_heap_layoutPK24ma_data_converter_configP29ma_data_converter_heap_layout:
.LVL2927:
.LFB197:
	.loc 1 41191 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 41191 1 is_stmt 0 view .LVU11933
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$104, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
1:	call	mcount
	.loc 1 41191 1 view .LVU11934
	.loc 1 41192 5 is_stmt 1 view .LVU11935
	.loc 1 41194 5 view .LVU11936
	.loc 1 41196 5 view .LVU11937
.LVL2928:
.LBB8092:
.LBI8092:
	.loc 1 776 23 view .LVU11938
.LBB8093:
	.loc 1 781 5 view .LVU11939
	.loc 1 782 9 view .LVU11940
	.loc 1 782 15 is_stmt 0 view .LVU11941
	pxor	%xmm0, %xmm0
	movq	$0, 16(%rsi)
.LVL2929:
	.loc 1 782 15 view .LVU11942
.LBE8093:
.LBE8092:
	.loc 1 41198 5 is_stmt 1 view .LVU11943
	.loc 1 41202 5 view .LVU11944
	.loc 1 41191 1 is_stmt 0 view .LVU11945
	movq	%rdi, %r12
	movq	%rsi, %rbx
.LBB8095:
.LBB8094:
	.loc 1 782 15 view .LVU11946
	movups	%xmm0, (%rsi)
.LBE8094:
.LBE8095:
	.loc 1 41202 18 view .LVU11947
	movl	8(%rdi), %r15d
	.loc 1 41202 5 view .LVU11948
	testl	%r15d, %r15d
	je	.L2166
	.loc 1 41202 46 discriminator 1 view .LVU11949
	movl	12(%rdi), %r14d
	.loc 1 41202 34 discriminator 1 view .LVU11950
	testl	%r14d, %r14d
	je	.L2166
	.loc 1 41206 5 is_stmt 1 view .LVU11951
	.loc 1 41209 5 view .LVU11952
	.loc 1 41210 5 view .LVU11953
.LBB8096:
	.loc 1 41211 9 view .LVU11954
	.loc 1 41212 9 view .LVU11955
.LVL2930:
.LBB8097:
.LBI8097:
	.loc 1 41155 36 view .LVU11956
.LBB8098:
	.loc 1 41157 5 view .LVU11957
	.loc 1 41159 5 view .LVU11958
	.loc 1 41161 5 view .LVU11959
	.loc 1 41161 214 is_stmt 0 view .LVU11960
	movl	44(%rdi), %eax
.LBB8099:
.LBB8100:
.LBB8101:
	.loc 1 41126 21 view .LVU11961
	movl	64(%rdi), %ecx
.LBE8101:
.LBE8100:
.LBE8099:
	.loc 1 41161 189 view .LVU11962
	movq	32(%rdi), %r13
	.loc 1 41161 214 view .LVU11963
	movl	%eax, -132(%rbp)
	.loc 1 41161 143 view .LVU11964
	movq	24(%rdi), %rax
.LBB8106:
.LBB8104:
.LBB8102:
	.loc 1 41126 21 view .LVU11965
	movl	%ecx, -136(%rbp)
.LBE8102:
.LBE8104:
.LBE8106:
	.loc 1 41161 143 view .LVU11966
	movq	%rax, -128(%rbp)
.LVL2931:
.LBB8107:
.LBI8099:
	.loc 1 41129 18 is_stmt 1 view .LVU11967
.LBE8107:
.LBE8098:
.LBE8097:
.LBE8096:
	.loc 1 41131 5 view .LVU11968
	.loc 1 41142 5 view .LVU11969
.LBB8206:
.LBB8115:
.LBB8113:
.LBB8108:
.LBB8105:
.LBI8100:
	.loc 1 41122 18 view .LVU11970
.LBB8103:
	.loc 1 41124 5 view .LVU11971
	.loc 1 41126 5 view .LVU11972
	.loc 1 41126 5 is_stmt 0 view .LVU11973
.LBE8103:
.LBE8105:
.LBE8108:
.LBB8109:
.LBI8109:
	.loc 1 39757 36 is_stmt 1 view .LVU11974
.LBB8110:
	.loc 1 39759 5 view .LVU11975
	.loc 1 39761 5 view .LVU11976
	.loc 1 39761 5 is_stmt 0 view .LVU11977
.LBE8110:
.LBE8109:
.LBE8113:
.LBE8115:
.LBE8206:
	.loc 1 781 5 is_stmt 1 view .LVU11978
	.loc 1 782 9 view .LVU11979
.LBB8207:
.LBB8116:
.LBB8114:
.LBB8112:
.LBB8111:
	.loc 1 39762 5 view .LVU11980
	.loc 1 39763 5 view .LVU11981
	.loc 1 39764 5 view .LVU11982
	.loc 1 39765 5 view .LVU11983
	.loc 1 39766 5 view .LVU11984
	.loc 1 39767 5 view .LVU11985
	.loc 1 39769 5 view .LVU11986
	.loc 1 39769 5 is_stmt 0 view .LVU11987
.LBE8111:
.LBE8112:
	.loc 1 41162 5 is_stmt 1 view .LVU11988
	.loc 1 41163 5 view .LVU11989
	.loc 1 41165 5 view .LVU11990
	.loc 1 41165 5 is_stmt 0 view .LVU11991
.LBE8114:
.LBE8116:
	.loc 1 41214 9 is_stmt 1 view .LVU11992
.LBB8117:
.LBI8117:
	.loc 1 40427 18 view .LVU11993
.LBB8118:
	.loc 1 40429 5 view .LVU11994
	.loc 1 40430 5 view .LVU11995
	.loc 1 40432 5 view .LVU11996
	.loc 1 40436 5 view .LVU11997
	.loc 1 40438 5 view .LVU11998
.LBB8119:
.LBI8119:
	.loc 1 40366 18 view .LVU11999
.LBB8120:
	.loc 1 40368 5 view .LVU12000
	.loc 1 40370 5 view .LVU12001
	.loc 1 40372 5 view .LVU12002
	.loc 1 40376 5 view .LVU12003
	.loc 1 40380 5 view .LVU12004
.LBB8121:
.LBI8121:
	.loc 1 43031 18 view .LVU12005
.LBE8121:
.LBE8120:
.LBE8119:
.LBE8118:
.LBE8117:
.LBE8207:
	.loc 1 43034 5 view .LVU12006
	.loc 1 43039 5 view .LVU12007
.LBB8208:
.LBB8198:
.LBB8190:
.LBB8182:
.LBB8174:
.LBB8139:
.LBB8122:
	cmpl	$1, %r15d
	je	.L2137
	testq	%rax, %rax
	je	.L2167
	leal	-1(%r15), %edx
	leaq	1(%rax,%rdx), %rdx
.LVL2932:
	.p2align 4,,10
	.p2align 3
.L2141:
	.loc 1 43039 5 is_stmt 0 view .LVU12008
.LBE8122:
.LBB8123:
.LBB8124:
	.loc 1 43042 13 is_stmt 1 view .LVU12009
.LBB8125:
.LBI8125:
	.loc 1 42261 19 view .LVU12010
.LBB8126:
	.loc 1 42263 5 view .LVU12011
	.loc 1 42266 9 view .LVU12012
	.loc 1 42270 9 view .LVU12013
	.loc 1 42270 9 is_stmt 0 view .LVU12014
.LBE8126:
.LBE8125:
	.loc 1 43042 13 view .LVU12015
	cmpb	$1, (%rax)
	je	.L2166
	.loc 1 43041 9 is_stmt 1 view .LVU12016
.LVL2933:
	.loc 1 43041 37 view .LVU12017
	addq	$1, %rax
.LVL2934:
	.loc 1 43041 37 is_stmt 0 view .LVU12018
	cmpq	%rax, %rdx
	jne	.L2141
.LVL2935:
	.loc 1 43041 37 view .LVU12019
.LBE8124:
.LBE8123:
.LBE8139:
	.loc 1 40384 5 is_stmt 1 view .LVU12020
.LBB8140:
.LBI8140:
	.loc 1 43031 18 view .LVU12021
.LBE8140:
.LBE8174:
.LBE8182:
.LBE8190:
.LBE8198:
.LBE8208:
	.loc 1 43034 5 view .LVU12022
	.loc 1 43039 5 view .LVU12023
.LBB8209:
.LBB8199:
.LBB8191:
.LBB8183:
.LBB8175:
.LBB8160:
.LBB8141:
	cmpl	$1, %r14d
	je	.L2162
.LVL2936:
	.p2align 4,,10
	.p2align 3
.L2164:
	.loc 1 43039 5 is_stmt 0 view .LVU12024
	testq	%r13, %r13
	je	.L2168
	leal	-1(%r14), %edx
	movq	%r13, %rax
	leaq	1(%r13,%rdx), %rdx
	.p2align 4,,10
	.p2align 3
.L2146:
.LVL2937:
	.loc 1 43039 5 view .LVU12025
.LBE8141:
.LBB8142:
.LBB8143:
	.loc 1 43042 13 is_stmt 1 view .LVU12026
.LBB8144:
.LBI8144:
	.loc 1 42261 19 view .LVU12027
.LBB8145:
	.loc 1 42263 5 view .LVU12028
	.loc 1 42266 9 view .LVU12029
	.loc 1 42270 9 view .LVU12030
	.loc 1 42270 9 is_stmt 0 view .LVU12031
.LBE8145:
.LBE8144:
	.loc 1 43042 13 view .LVU12032
	cmpb	$1, (%rax)
	je	.L2166
	.loc 1 43041 9 is_stmt 1 view .LVU12033
.LVL2938:
	.loc 1 43041 37 view .LVU12034
	addq	$1, %rax
.LVL2939:
	.loc 1 43041 37 is_stmt 0 view .LVU12035
	cmpq	%rdx, %rax
	jne	.L2146
.LVL2940:
	.loc 1 43041 37 view .LVU12036
.LBE8143:
.LBE8142:
.LBE8160:
	.loc 1 40388 5 is_stmt 1 view .LVU12037
	.loc 1 40391 5 view .LVU12038
	.loc 1 40392 5 view .LVU12039
	xorl	%eax, %eax
	cmpq	$0, -128(%rbp)
	jne	.L2162
	jmp	.L2163
.LVL2941:
	.p2align 4,,10
	.p2align 3
.L2137:
	.loc 1 40384 5 view .LVU12040
.LBB8161:
	.loc 1 43031 18 view .LVU12041
.LBE8161:
.LBE8175:
.LBE8183:
.LBE8191:
.LBE8199:
.LBE8209:
	.loc 1 43034 5 view .LVU12042
	.loc 1 43039 5 view .LVU12043
.LBB8210:
.LBB8200:
.LBB8192:
.LBB8184:
.LBB8176:
.LBB8162:
.LBB8156:
	cmpl	$1, %r14d
	jne	.L2164
.LVL2942:
	.loc 1 43039 5 is_stmt 0 view .LVU12044
.LBE8156:
.LBE8162:
	.loc 1 40388 5 is_stmt 1 view .LVU12045
	.loc 1 40391 5 view .LVU12046
	.loc 1 40392 5 view .LVU12047
	xorl	%eax, %eax
	cmpq	$0, -128(%rbp)
	je	.L2148
.LVL2943:
.L2162:
	.loc 1 40393 9 view .LVU12048
	.loc 1 40393 9 is_stmt 0 view .LVU12049
	movl	%r15d, %eax
.LVL2944:
.L2148:
	.loc 1 40397 5 is_stmt 1 view .LVU12050
	.loc 1 40398 5 view .LVU12051
	testq	%r13, %r13
	je	.L2149
.L2163:
	.loc 1 40399 9 view .LVU12052
	.loc 1 40399 67 is_stmt 0 view .LVU12053
	movl	%r14d, %edx
	.loc 1 40399 34 view .LVU12054
	addq	%rdx, %rax
.LVL2945:
.L2149:
	.loc 1 40403 5 is_stmt 1 view .LVU12055
	.loc 1 40403 32 is_stmt 0 view .LVU12056
	addq	$7, %rax
.LVL2946:
.LBB8163:
.LBB8164:
	.loc 1 40363 46 view .LVU12057
	movq	-128(%rbp), %rdi
	movl	%r14d, %ecx
	movq	%r13, %rdx
	movl	-132(%rbp), %r8d
.LBE8164:
.LBE8163:
	.loc 1 40403 32 view .LVU12058
	andq	$-8, %rax
.LVL2947:
.LBB8167:
.LBB8165:
	.loc 1 40363 46 view .LVU12059
	movl	%r15d, %esi
.LBE8165:
.LBE8167:
	.loc 1 40403 32 view .LVU12060
	movq	%rax, -120(%rbp)
.LVL2948:
	.loc 1 40406 5 is_stmt 1 view .LVU12061
.LBB8168:
.LBI8163:
	.loc 1 40361 35 view .LVU12062
.LBB8166:
	.loc 1 40363 5 view .LVU12063
	.loc 1 40363 46 is_stmt 0 view .LVU12064
	call	_ZL34ma_channel_map_get_conversion_pathPKhjS0_j19ma_channel_mix_mode.lto_priv.0
.LVL2949:
	.loc 1 40363 46 view .LVU12065
.LBE8166:
.LBE8168:
	.loc 1 40409 5 is_stmt 1 view .LVU12066
	.loc 1 40410 5 view .LVU12067
	movq	-120(%rbp), %r10
	cmpl	$4, %eax
	je	.L2199
	.loc 1 40415 5 view .LVU12068
	.loc 1 40416 5 view .LVU12069
	cmpl	$5, %eax
	jne	.L2151
	.loc 1 40417 9 view .LVU12070
	.loc 1 40418 9 view .LVU12071
	.loc 1 40418 85 is_stmt 0 view .LVU12072
	movl	%r14d, %ecx
	.loc 1 40417 63 view .LVU12073
	movl	%r15d, %r9d
	.loc 1 40418 34 view .LVU12074
	leaq	8(,%rcx,4), %rax
.LVL2950:
	.loc 1 40418 34 view .LVU12075
	imulq	%rax, %r9
	addq	%r9, %r10
.LVL2951:
.L2151:
	.loc 1 40422 5 is_stmt 1 view .LVU12076
	.loc 1 40422 32 is_stmt 0 view .LVU12077
	leaq	7(%r10), %rax
.LBE8176:
.LBE8184:
.LBE8192:
.LBE8200:
.LBE8210:
.LBB8211:
.LBB8212:
.LBB8213:
	.loc 1 41126 44 view .LVU12078
	movl	-136(%rbp), %edx
.LBE8213:
.LBE8212:
.LBE8211:
.LBB8228:
.LBB8201:
.LBB8193:
.LBB8185:
.LBB8177:
	.loc 1 40422 32 view .LVU12079
	andq	$-8, %rax
.LVL2952:
	.loc 1 40424 5 is_stmt 1 view .LVU12080
	.loc 1 40424 5 is_stmt 0 view .LVU12081
.LBE8177:
.LBE8185:
	.loc 1 40439 5 is_stmt 1 view .LVU12082
	.loc 1 40443 5 view .LVU12083
	.loc 1 40445 5 view .LVU12084
	.loc 1 40445 5 is_stmt 0 view .LVU12085
.LBE8193:
.LBE8201:
	.loc 1 41215 9 is_stmt 1 view .LVU12086
	.loc 1 41219 9 view .LVU12087
	.loc 1 41219 34 is_stmt 0 view .LVU12088
	movq	%rax, (%rbx)
.LVL2953:
	.loc 1 41219 34 view .LVU12089
.LBE8228:
	.loc 1 41223 5 is_stmt 1 view .LVU12090
	.loc 1 41223 34 is_stmt 0 view .LVU12091
	movq	%rax, 16(%rbx)
	.loc 1 41224 5 is_stmt 1 view .LVU12092
.LVL2954:
.LBB8229:
.LBB8215:
.LBI8212:
	.loc 1 41122 18 view .LVU12093
.LBB8214:
	.loc 1 41124 5 view .LVU12094
	.loc 1 41126 5 view .LVU12095
	.loc 1 41126 44 is_stmt 0 view .LVU12096
	testl	%edx, %edx
	jne	.L2154
	movl	20(%r12), %ecx
	cmpl	%ecx, 16(%r12)
	je	.L2155
.L2154:
.LVL2955:
	.loc 1 41126 44 view .LVU12097
.LBE8214:
.LBE8215:
.LBB8216:
	.loc 1 41225 9 is_stmt 1 view .LVU12098
	.loc 1 41226 9 view .LVU12099
	.loc 1 41226 106 is_stmt 0 view .LVU12100
	leaq	-96(%rbp), %r13
	movq	%r12, %rsi
	movq	%r13, %rdi
	call	_ZL51ma_resampler_config_init_from_data_converter_configPK24ma_data_converter_config
.LVL2956:
	.loc 1 41228 9 is_stmt 1 view .LVU12101
.LBB8217:
.LBI8217:
	.loc 1 39380 18 view .LVU12102
.LBB8218:
	.loc 1 39382 5 view .LVU12103
	.loc 1 39383 5 view .LVU12104
	.loc 1 39384 5 view .LVU12105
	.loc 1 39386 5 view .LVU12106
	.loc 1 39390 5 view .LVU12107
.LBB8219:
.LBB8220:
	.loc 1 39360 22 is_stmt 0 view .LVU12108
	movl	-80(%rbp), %eax
.LBE8220:
.LBE8219:
	.loc 1 39390 23 view .LVU12109
	movq	$0, -104(%rbp)
	.loc 1 39392 5 is_stmt 1 view .LVU12110
	.loc 1 39396 5 view .LVU12111
.LVL2957:
.LBB8223:
.LBI8219:
	.loc 1 39350 18 view .LVU12112
.LBB8221:
	.loc 1 39352 5 view .LVU12113
	.loc 1 39353 5 view .LVU12114
	.loc 1 39354 5 view .LVU12115
	.loc 1 39357 5 view .LVU12116
	.loc 1 39358 5 view .LVU12117
	.loc 1 39360 5 view .LVU12118
	testl	%eax, %eax
	je	.L2156
	cmpl	$1, %eax
	jne	.L2166
	.loc 1 39368 9 view .LVU12119
	.loc 1 39369 9 view .LVU12120
	.loc 1 39370 13 view .LVU12121
	.loc 1 39370 36 is_stmt 0 view .LVU12122
	movq	-72(%rbp), %rax
.LVL2958:
	.loc 1 39371 13 is_stmt 1 view .LVU12123
	.loc 1 39371 36 is_stmt 0 view .LVU12124
	movq	-64(%rbp), %rdi
.LVL2959:
	.loc 1 39372 11 is_stmt 1 view .LVU12125
	.loc 1 39372 11 is_stmt 0 view .LVU12126
.LBE8221:
.LBE8223:
	.loc 1 39397 5 is_stmt 1 view .LVU12127
	.loc 1 39401 5 view .LVU12128
	testq	%rax, %rax
	je	.L2161
.LVL2960:
.L2159:
	.loc 1 39401 37 is_stmt 0 view .LVU12129
	movq	(%rax), %rax
	.loc 1 39401 25 view .LVU12130
	testq	%rax, %rax
	je	.L2161
	.loc 1 39405 5 is_stmt 1 view .LVU12131
	.loc 1 39405 36 is_stmt 0 view .LVU12132
	leaq	-104(%rbp), %rdx
.LVL2961:
	.loc 1 39405 36 view .LVU12133
	movq	%r13, %rsi
	call	*%rax
.LVL2962:
	.loc 1 39406 5 is_stmt 1 view .LVU12134
	testl	%eax, %eax
	jne	.L2135
.LVL2963:
	.loc 1 39406 5 is_stmt 0 view .LVU12135
.LBE8218:
.LBE8217:
	.loc 1 41229 9 is_stmt 1 view .LVU12136
	.loc 1 41233 9 view .LVU12137
	.loc 1 41233 34 is_stmt 0 view .LVU12138
	movq	-104(%rbp), %rax
	addq	(%rbx), %rax
.L2155:
	.loc 1 41233 34 view .LVU12139
.LBE8216:
.LBE8229:
	.loc 1 41237 5 is_stmt 1 view .LVU12140
	.loc 1 41237 32 is_stmt 0 view .LVU12141
	addq	$7, %rax
	andq	$-8, %rax
	movq	%rax, (%rbx)
	.loc 1 41239 5 is_stmt 1 view .LVU12142
	.loc 1 41240 1 is_stmt 0 view .LVU12143
	addq	$104, %rsp
	.loc 1 41239 12 view .LVU12144
	xorl	%eax, %eax
	.loc 1 41240 1 view .LVU12145
	popq	%rbx
.LVL2964:
	.loc 1 41240 1 view .LVU12146
	popq	%r12
.LVL2965:
	.loc 1 41240 1 view .LVU12147
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL2966:
	.p2align 4,,10
	.p2align 3
.L2166:
	.cfi_restore_state
	.loc 1 41203 16 view .LVU12148
	movl	$-2, %eax
.L2135:
	.loc 1 41240 1 view .LVU12149
	addq	$104, %rsp
	popq	%rbx
.LVL2967:
	.loc 1 41240 1 view .LVU12150
	popq	%r12
.LVL2968:
	.loc 1 41240 1 view .LVU12151
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL2969:
	.p2align 4,,10
	.p2align 3
.L2199:
	.cfi_restore_state
.LBB8230:
.LBB8202:
.LBB8194:
.LBB8186:
.LBB8178:
	.loc 1 40411 9 is_stmt 1 view .LVU12152
	.loc 1 40411 65 is_stmt 0 view .LVU12153
	movl	%r14d, %ecx
	.loc 1 40411 34 view .LVU12154
	addq	%rcx, %r10
.LVL2970:
	.loc 1 40415 5 is_stmt 1 view .LVU12155
	.loc 1 40416 5 view .LVU12156
	jmp	.L2151
.LVL2971:
	.p2align 4,,10
	.p2align 3
.L2167:
.LBB8169:
.LBB8137:
.LBB8135:
	.loc 1 43041 23 is_stmt 0 view .LVU12157
	xorl	%edx, %edx
.LVL2972:
	.p2align 4,,10
	.p2align 3
.L2138:
	.loc 1 43042 13 is_stmt 1 view .LVU12158
.LBB8133:
	.loc 1 42261 19 view .LVU12159
.LBB8131:
	.loc 1 42263 5 view .LVU12160
	.loc 1 42264 9 view .LVU12161
	.loc 1 42264 9 is_stmt 0 view .LVU12162
.LBE8131:
.LBE8133:
.LBE8135:
.LBE8137:
.LBE8169:
.LBE8178:
.LBE8186:
.LBE8194:
.LBE8202:
.LBE8230:
	.loc 1 42947 5 is_stmt 1 view .LVU12163
.LBB8231:
.LBB8203:
.LBB8195:
.LBB8187:
.LBB8179:
.LBB8170:
.LBB8138:
.LBB8136:
.LBB8134:
.LBB8132:
.LBB8127:
.LBI8127:
	.loc 1 42261 19 view .LVU12164
.LBB8128:
.LBB8129:
.LBI8129:
	.loc 1 42945 19 view .LVU12165
.LBB8130:
	.loc 1 42987 66 is_stmt 0 view .LVU12166
	movl	%edx, %esi
	movl	%r15d, %edi
	movl	%edx, -120(%rbp)
	call	_ZL46ma_channel_map_init_standard_channel_microsoftjj.lto_priv.0
.LVL2973:
	.loc 1 42987 66 view .LVU12167
.LBE8130:
.LBE8129:
.LBE8128:
.LBE8127:
.LBE8132:
.LBE8134:
	.loc 1 43042 13 view .LVU12168
	cmpb	$1, %al
	je	.L2166
	.loc 1 43041 9 is_stmt 1 view .LVU12169
	movl	-120(%rbp), %edx
	addl	$1, %edx
.LVL2974:
	.loc 1 43041 37 view .LVU12170
	cmpl	%edx, %r15d
	jne	.L2138
.LVL2975:
	.loc 1 43041 37 is_stmt 0 view .LVU12171
.LBE8136:
.LBE8138:
.LBE8170:
	.loc 1 40384 5 is_stmt 1 view .LVU12172
.LBB8171:
	.loc 1 43031 18 view .LVU12173
.LBE8171:
.LBE8179:
.LBE8187:
.LBE8195:
.LBE8203:
.LBE8231:
	.loc 1 43034 5 view .LVU12174
	.loc 1 43039 5 view .LVU12175
.LBB8232:
.LBB8204:
.LBB8196:
.LBB8188:
.LBB8180:
.LBB8172:
.LBB8157:
	xorl	%eax, %eax
	cmpl	$1, %r14d
	jne	.L2164
	jmp	.L2148
	.p2align 4,,10
	.p2align 3
.L2168:
	.loc 1 43039 5 is_stmt 0 view .LVU12176
.LBE8157:
.LBB8158:
.LBB8154:
	.loc 1 43041 23 view .LVU12177
	xorl	%edx, %edx
	.p2align 4,,10
	.p2align 3
.L2144:
.LVL2976:
	.loc 1 43042 13 is_stmt 1 view .LVU12178
.LBB8152:
	.loc 1 42261 19 view .LVU12179
.LBB8150:
	.loc 1 42263 5 view .LVU12180
	.loc 1 42264 9 view .LVU12181
	.loc 1 42264 9 is_stmt 0 view .LVU12182
.LBE8150:
.LBE8152:
.LBE8154:
.LBE8158:
.LBE8172:
.LBE8180:
.LBE8188:
.LBE8196:
.LBE8204:
.LBE8232:
	.loc 1 42947 5 is_stmt 1 view .LVU12183
.LBB8233:
.LBB8205:
.LBB8197:
.LBB8189:
.LBB8181:
.LBB8173:
.LBB8159:
.LBB8155:
.LBB8153:
.LBB8151:
.LBB8146:
.LBI8146:
	.loc 1 42261 19 view .LVU12184
.LBB8147:
.LBB8148:
.LBI8148:
	.loc 1 42945 19 view .LVU12185
.LBB8149:
	.loc 1 42987 66 is_stmt 0 view .LVU12186
	movl	%edx, %esi
	movl	%r14d, %edi
	movl	%edx, -120(%rbp)
	call	_ZL46ma_channel_map_init_standard_channel_microsoftjj.lto_priv.0
.LVL2977:
	.loc 1 42987 66 view .LVU12187
.LBE8149:
.LBE8148:
.LBE8147:
.LBE8146:
.LBE8151:
.LBE8153:
	.loc 1 43042 13 view .LVU12188
	cmpb	$1, %al
	je	.L2166
	.loc 1 43041 9 is_stmt 1 view .LVU12189
	movl	-120(%rbp), %edx
	addl	$1, %edx
.LVL2978:
	.loc 1 43041 37 view .LVU12190
	cmpl	%edx, %r14d
	jne	.L2144
.LVL2979:
	.loc 1 43041 37 is_stmt 0 view .LVU12191
.LBE8155:
.LBE8159:
.LBE8173:
	.loc 1 40388 5 is_stmt 1 view .LVU12192
	.loc 1 40391 5 view .LVU12193
	.loc 1 40392 5 view .LVU12194
	xorl	%eax, %eax
	cmpq	$0, -128(%rbp)
	jne	.L2162
	jmp	.L2149
.LVL2980:
	.p2align 4,,10
	.p2align 3
.L2156:
	.loc 1 40392 5 is_stmt 0 view .LVU12195
.LBE8181:
.LBE8189:
.LBE8197:
.LBE8205:
.LBE8233:
.LBB8234:
.LBB8227:
.LBB8226:
.LBB8225:
.LBB8224:
.LBB8222:
	.loc 1 39365 25 view .LVU12196
	xorl	%edi, %edi
	.loc 1 39364 25 view .LVU12197
	movl	$_ZL28g_ma_linear_resampler_vtable, %eax
	jmp	.L2159
.LVL2981:
.L2161:
	.loc 1 39364 25 view .LVU12198
	movl	$-29, %eax
	jmp	.L2135
.LBE8222:
.LBE8224:
.LBE8225:
.LBE8226:
.LBE8227:
.LBE8234:
	.cfi_endproc
.LFE197:
	.size	_ZL33ma_data_converter_get_heap_layoutPK24ma_data_converter_configP29ma_data_converter_heap_layout, .-_ZL33ma_data_converter_get_heap_layoutPK24ma_data_converter_configP29ma_data_converter_heap_layout
	.p2align 4
	.globl	_ZL24ma_channel_map_apply_f32PfPKhjPKfS1_jy19ma_channel_mix_mode22ma_mono_expansion_mode.lto_priv.0
	.hidden	_ZL24ma_channel_map_apply_f32PfPKhjPKfS1_jy19ma_channel_mix_mode22ma_mono_expansion_mode.lto_priv.0
	.type	_ZL24ma_channel_map_apply_f32PfPKhjPKfS1_jy19ma_channel_mix_mode22ma_mono_expansion_mode.lto_priv.0, @function
_ZL24ma_channel_map_apply_f32PfPKhjPKfS1_jy19ma_channel_mix_mode22ma_mono_expansion_mode.lto_priv.0:
.LVL2982:
.LFB204:
	.loc 1 40254 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 40254 1 is_stmt 0 view .LVU12200
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$4216, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
1:	call	mcount
	.loc 1 40254 1 view .LVU12201
	.loc 1 40255 5 is_stmt 1 view .LVU12202
	.loc 1 40254 1 is_stmt 0 view .LVU12203
	movq	16(%rbp), %rax
	movl	32(%rbp), %ebx
	movq	%rax, -4240(%rbp)
	movl	24(%rbp), %eax
	movq	%r8, %r12
	movq	%rcx, %r13
	movq	%rdi, -4216(%rbp)
	.loc 1 40255 83 view .LVU12204
	movl	%edx, %ecx
.LVL2983:
	.loc 1 40255 83 view .LVU12205
	movq	%r12, %rdi
.LVL2984:
	.loc 1 40254 1 view .LVU12206
	movl	%r9d, %r14d
	movq	%rsi, -4208(%rbp)
	.loc 1 40255 83 view .LVU12207
	movl	%eax, %r8d
.LVL2985:
	.loc 1 40254 1 view .LVU12208
	movl	%edx, -4200(%rbp)
	.loc 1 40255 83 view .LVU12209
	movq	%rsi, %rdx
.LVL2986:
	.loc 1 40255 83 view .LVU12210
	movl	%r9d, %esi
.LVL2987:
	.loc 1 40254 1 view .LVU12211
	movl	%eax, -4228(%rbp)
	.loc 1 40255 83 view .LVU12212
	call	_ZL34ma_channel_map_get_conversion_pathPKhjS0_j19ma_channel_mix_mode.lto_priv.0
.LVL2988:
	.loc 1 40258 5 is_stmt 1 view .LVU12213
	cmpl	$1, %eax
	je	.L2309
	.loc 1 40264 5 view .LVU12214
	cmpl	$2, %eax
	je	.L2310
	.loc 1 40270 5 view .LVU12215
	cmpl	$3, %eax
	je	.L2311
	.loc 1 40276 5 view .LVU12216
.LBB8349:
	cmpl	$254, -4200(%rbp)
	ja	.L2208
.LBB8350:
	.loc 1 40277 9 view .LVU12217
	.loc 1 40279 9 view .LVU12218
.LBB8351:
	cmpl	$1, -4228(%rbp)
	je	.L2312
.LBB8352:
	.loc 1 40292 13 view .LVU12219
	.loc 1 40293 13 view .LVU12220
	.loc 1 40294 13 view .LVU12221
	.loc 1 40295 13 view .LVU12222
	.loc 1 40301 13 view .LVU12223
.LBB8353:
	cmpl	$32, %r14d
	ja	.L2220
	movl	-4200(%rbp), %eax
.LVL2989:
	.loc 1 40301 13 is_stmt 0 view .LVU12224
	cmpl	$32, %eax
	ja	.L2220
.LVL2990:
.LBB8354:
	.loc 1 40303 51 is_stmt 1 view .LVU12225
	testl	%eax, %eax
	je	.L2200
	leaq	-4144(%rbp), %rsi
	movq	%rax, -4224(%rbp)
	movl	%r14d, %r15d
	movq	%rsi, -4168(%rbp)
	movq	$0, -4152(%rbp)
	movl	%r14d, -4160(%rbp)
	movq	%r13, -4184(%rbp)
	movq	%rsi, %r13
.LVL2991:
	.p2align 4,,10
	.p2align 3
.L2226:
.LBB8355:
	.loc 1 40304 21 view .LVU12226
.LBB8356:
.LBI8356:
	.loc 1 42261 19 view .LVU12227
.LBB8357:
	.loc 1 42263 5 view .LVU12228
	cmpq	$0, -4208(%rbp)
	je	.L2313
	.loc 1 42266 9 view .LVU12229
	.loc 1 42270 9 view .LVU12230
	.loc 1 42270 40 is_stmt 0 view .LVU12231
	movq	-4208(%rbp), %rax
	movq	-4152(%rbp), %rdi
	movzbl	(%rax,%rdi), %eax
.L2223:
.LVL2992:
	.loc 1 42270 40 view .LVU12232
.LBE8357:
.LBE8356:
	.loc 1 40305 21 is_stmt 1 view .LVU12233
.LBB8364:
	.loc 1 40305 53 view .LVU12234
	movl	-4160(%rbp), %edx
	testl	%edx, %edx
	je	.L2231
.LBB8365:
	.loc 1 40307 108 is_stmt 0 view .LVU12235
	movzbl	%al, %ebx
	testq	%r12, %r12
	je	.L2227
	xorl	%r14d, %r14d
.LVL2993:
	.p2align 4,,10
	.p2align 3
.L2229:
	.loc 1 40306 25 is_stmt 1 view .LVU12236
.LBB8366:
.LBI8366:
	.loc 1 42261 19 view .LVU12237
.LBB8367:
	.loc 1 42263 5 view .LVU12238
	.loc 1 42266 9 view .LVU12239
	.loc 1 42270 9 view .LVU12240
	.loc 1 42270 9 is_stmt 0 view .LVU12241
.LBE8367:
.LBE8366:
	.loc 1 40307 25 is_stmt 1 view .LVU12242
	.loc 1 40307 108 is_stmt 0 view .LVU12243
	movzbl	(%r12,%r14), %esi
	movl	%ebx, %edi
	call	_ZL48ma_calculate_channel_position_rectangular_weighthh
.LVL2994:
	.loc 1 40307 58 view .LVU12244
	movss	%xmm0, 0(%r13,%r14,4)
.LBE8365:
	.loc 1 40305 21 is_stmt 1 view .LVU12245
.LVL2995:
	.loc 1 40305 53 view .LVU12246
	addq	$1, %r14
.LVL2996:
	.loc 1 40305 53 is_stmt 0 view .LVU12247
	cmpq	%r14, %r15
	jne	.L2229
.LVL2997:
.L2231:
	.loc 1 40305 53 view .LVU12248
.LBE8364:
.LBE8355:
	.loc 1 40303 17 is_stmt 1 view .LVU12249
	.loc 1 40303 51 view .LVU12250
	addq	$1, -4152(%rbp)
.LVL2998:
	.loc 1 40303 51 is_stmt 0 view .LVU12251
	subq	$-128, %r13
	movq	-4152(%rbp), %rax
	cmpq	-4224(%rbp), %rax
	jne	.L2226
.LBE8354:
.LBB8385:
	.loc 1 40311 41 view .LVU12252
	cmpq	$0, -4240(%rbp)
.LBE8385:
.LBB8401:
	movq	-4184(%rbp), %r13
	movl	-4160(%rbp), %r14d
.LVL2999:
	.loc 1 40311 41 view .LVU12253
.LBE8401:
.LBB8402:
	.loc 1 40311 41 is_stmt 1 view .LVU12254
	je	.L2200
.LBB8386:
	.loc 1 40322 32 is_stmt 0 view .LVU12255
	movq	-4224(%rbp), %r12
	.loc 1 40323 35 view .LVU12256
	movl	%r14d, %eax
	movl	%r14d, %r8d
	movl	%r14d, %r11d
	.loc 1 40323 32 view .LVU12257
	leaq	0(,%rax,4), %r10
	leal	-1(%r14), %ebx
	shrl	$2, %r8d
	andl	$-4, %r11d
	.loc 1 40322 32 view .LVU12258
	leaq	0(,%r12,4), %r15
	movq	%r10, -4160(%rbp)
.LVL3000:
	.loc 1 40322 32 view .LVU12259
.LBE8386:
	.loc 1 40311 29 view .LVU12260
	movl	-4228(%rbp), %r9d
	movq	%r15, -4152(%rbp)
	movq	-4216(%rbp), %r10
.LVL3001:
	.p2align 4,,10
	.p2align 3
.L2238:
.LBB8395:
.LBB8387:
	.loc 1 40312 55 is_stmt 1 view .LVU12261
	movq	-4168(%rbp), %rcx
.LBE8387:
.LBE8395:
	.loc 1 40311 29 is_stmt 0 view .LVU12262
	xorl	%esi, %esi
	jmp	.L2236
.LVL3002:
	.p2align 4,,10
	.p2align 3
.L2315:
	.loc 1 40311 29 view .LVU12263
	cmpl	$2, %ebx
	jbe	.L2252
.LVL3003:
.LBB8396:
.LBB8392:
.LBB8388:
	.loc 1 40316 29 is_stmt 1 view .LVU12264
	.loc 1 40316 67 is_stmt 0 view .LVU12265
	movups	0(%r13), %xmm0
	mulps	(%rcx), %xmm0
	.loc 1 40315 25 is_stmt 1 view .LVU12266
	.loc 1 40315 57 view .LVU12267
	cmpl	$1, %r8d
	jbe	.L2234
	.loc 1 40316 29 view .LVU12268
	.loc 1 40316 67 is_stmt 0 view .LVU12269
	movups	16(%r13), %xmm1
	mulps	16(%rcx), %xmm1
	.loc 1 40316 42 view .LVU12270
	addps	%xmm1, %xmm0
	.loc 1 40315 25 is_stmt 1 view .LVU12271
	.loc 1 40315 57 view .LVU12272
	cmpl	$2, %r8d
	je	.L2234
	.loc 1 40316 29 view .LVU12273
	.loc 1 40316 67 is_stmt 0 view .LVU12274
	movups	32(%r13), %xmm1
	mulps	32(%rcx), %xmm1
	.loc 1 40316 42 view .LVU12275
	addps	%xmm1, %xmm0
	.loc 1 40315 25 is_stmt 1 view .LVU12276
	.loc 1 40315 57 view .LVU12277
	cmpl	$3, %r8d
	je	.L2234
	.loc 1 40316 29 view .LVU12278
	.loc 1 40316 67 is_stmt 0 view .LVU12279
	movups	48(%r13), %xmm1
	mulps	48(%rcx), %xmm1
	.loc 1 40316 42 view .LVU12280
	addps	%xmm1, %xmm0
	.loc 1 40315 25 is_stmt 1 view .LVU12281
	.loc 1 40315 57 view .LVU12282
	cmpl	$4, %r8d
	je	.L2234
	.loc 1 40316 29 view .LVU12283
	.loc 1 40316 67 is_stmt 0 view .LVU12284
	movups	64(%r13), %xmm1
	mulps	64(%rcx), %xmm1
	.loc 1 40316 42 view .LVU12285
	addps	%xmm1, %xmm0
	.loc 1 40315 25 is_stmt 1 view .LVU12286
	.loc 1 40315 57 view .LVU12287
	cmpl	$5, %r8d
	je	.L2234
	.loc 1 40316 29 view .LVU12288
	.loc 1 40316 67 is_stmt 0 view .LVU12289
	movups	80(%r13), %xmm1
	mulps	80(%rcx), %xmm1
	.loc 1 40316 42 view .LVU12290
	addps	%xmm1, %xmm0
	.loc 1 40315 25 is_stmt 1 view .LVU12291
	.loc 1 40315 57 view .LVU12292
	cmpl	$6, %r8d
	je	.L2234
	.loc 1 40316 29 view .LVU12293
	.loc 1 40316 67 is_stmt 0 view .LVU12294
	movups	96(%r13), %xmm1
	mulps	96(%rcx), %xmm1
	.loc 1 40316 42 view .LVU12295
	addps	%xmm1, %xmm0
	.loc 1 40315 25 is_stmt 1 view .LVU12296
	.loc 1 40315 57 view .LVU12297
	cmpl	$7, %r8d
	je	.L2234
	.loc 1 40316 29 discriminator 2 view .LVU12298
	.loc 1 40316 67 is_stmt 0 discriminator 2 view .LVU12299
	movups	112(%r13), %xmm1
	mulps	112(%rcx), %xmm1
	.loc 1 40316 42 discriminator 2 view .LVU12300
	addps	%xmm1, %xmm0
	.loc 1 40315 25 is_stmt 1 discriminator 2 view .LVU12301
	.loc 1 40315 57 discriminator 2 view .LVU12302
.L2234:
	movaps	%xmm0, %xmm1
	.loc 1 40313 31 is_stmt 0 view .LVU12303
	movl	%r11d, %edx
	movhlps	%xmm0, %xmm1
	addps	%xmm0, %xmm1
	movaps	%xmm1, %xmm0
	shufps	$85, %xmm1, %xmm0
	addps	%xmm1, %xmm0
	cmpl	%r11d, %r14d
	je	.L2232
.L2233:
.LVL3004:
	.loc 1 40316 29 is_stmt 1 view .LVU12304
	.loc 1 40316 55 is_stmt 0 view .LVU12305
	movl	%edx, %edi
	.loc 1 40316 100 view .LVU12306
	salq	$5, %rax
	leaq	(%rax,%rdi), %r15
	.loc 1 40316 67 view .LVU12307
	movss	0(%r13,%rdi,4), %xmm1
	.loc 1 40315 82 view .LVU12308
	leal	1(%rdx), %edi
	.loc 1 40316 67 view .LVU12309
	mulss	-4144(%rbp,%r15,4), %xmm1
	.loc 1 40316 42 view .LVU12310
	addss	%xmm1, %xmm0
.LVL3005:
	.loc 1 40315 25 is_stmt 1 view .LVU12311
	.loc 1 40315 57 view .LVU12312
	cmpl	%edi, %r14d
	jbe	.L2232
	.loc 1 40316 29 view .LVU12313
	.loc 1 40316 100 is_stmt 0 view .LVU12314
	leaq	(%rax,%rdi), %r15
	.loc 1 40316 67 view .LVU12315
	movss	0(%r13,%rdi,4), %xmm1
	.loc 1 40315 82 view .LVU12316
	addl	$2, %edx
	.loc 1 40316 67 view .LVU12317
	mulss	-4144(%rbp,%r15,4), %xmm1
	.loc 1 40316 42 view .LVU12318
	addss	%xmm1, %xmm0
.LVL3006:
	.loc 1 40315 25 is_stmt 1 view .LVU12319
	.loc 1 40315 57 view .LVU12320
	cmpl	%edx, %r14d
	jbe	.L2232
	.loc 1 40316 29 view .LVU12321
	.loc 1 40316 100 is_stmt 0 view .LVU12322
	addq	%rdx, %rax
	.loc 1 40316 67 view .LVU12323
	movss	0(%r13,%rdx,4), %xmm1
	mulss	-4144(%rbp,%rax,4), %xmm1
	.loc 1 40316 42 view .LVU12324
	addss	%xmm1, %xmm0
.LVL3007:
	.loc 1 40315 25 is_stmt 1 view .LVU12325
	.loc 1 40315 57 view .LVU12326
.L2232:
	.loc 1 40319 25 discriminator 2 view .LVU12327
	.loc 1 40319 49 is_stmt 0 discriminator 2 view .LVU12328
	movss	%xmm0, (%r10,%rsi,4)
.LBE8388:
	.loc 1 40312 21 is_stmt 1 discriminator 2 view .LVU12329
.LVL3008:
	.loc 1 40312 55 discriminator 2 view .LVU12330
	addq	$1, %rsi
.LVL3009:
	.loc 1 40312 55 is_stmt 0 discriminator 2 view .LVU12331
	subq	$-128, %rcx
	cmpq	%rsi, %r12
	je	.L2314
.L2236:
	.loc 1 40312 55 discriminator 2 view .LVU12332
	movl	%esi, %eax
.LVL3010:
.LBB8389:
	.loc 1 40315 57 is_stmt 1 view .LVU12333
	testl	%r14d, %r14d
	jne	.L2315
	.loc 1 40313 31 is_stmt 0 view .LVU12334
	pxor	%xmm0, %xmm0
	jmp	.L2232
.LVL3011:
.L2208:
	.loc 1 40313 31 view .LVU12335
.LBE8389:
.LBE8392:
.LBE8396:
.LBE8402:
.LBE8353:
.LBE8352:
.LBE8351:
.LBE8350:
	.loc 1 40347 9 is_stmt 1 view .LVU12336
.LBB8508:
.LBI8508:
	.loc 1 30066 13 view .LVU12337
.LBE8508:
.LBE8349:
	.loc 1 30068 5 view .LVU12338
.LBB8524:
.LBB8518:
.LBB8509:
.LBI8509:
	.loc 1 30066 13 view .LVU12339
.LBB8510:
.LBB8511:
.LBB8512:
	.loc 2 2066 132 is_stmt 0 view .LVU12340
	movl	-4200(%rbp), %ebx
	sall	$2, %ebx
.LBE8512:
.LBE8511:
	.loc 1 30075 26 view .LVU12341
	imulq	-4240(%rbp), %rbx
.LVL3012:
.LBB8513:
.LBB8514:
	.loc 1 1815 24 view .LVU12342
	testq	%rbx, %rbx
	je	.L2200
	movq	-4216(%rbp), %rcx
	movl	$4294967295, %r13d
.LVL3013:
	.p2align 4,,10
	.p2align 3
.L2249:
	.loc 1 1815 24 view .LVU12343
	cmpq	%r13, %rbx
	movq	%r13, %r12
.LBB8515:
.LBB8516:
.LBB8517:
	.loc 1 782 15 view .LVU12344
	movq	%rcx, %rdi
	cmovbe	%rbx, %r12
.LVL3014:
	.loc 1 782 15 view .LVU12345
	xorl	%esi, %esi
	movq	%r12, %rdx
	call	memset
.LVL3015:
	.loc 1 782 15 view .LVU12346
	movq	%rax, %rcx
.LVL3016:
	.loc 1 782 15 view .LVU12347
.LBE8517:
.LBE8516:
	.loc 1 1824 13 view .LVU12348
	addq	%r12, %rcx
.LVL3017:
	.loc 1 1824 13 view .LVU12349
.LBE8515:
	.loc 1 1815 24 view .LVU12350
	subq	%r12, %rbx
.LVL3018:
	.loc 1 1815 24 view .LVU12351
	jne	.L2249
.LVL3019:
.L2200:
	.loc 1 1815 24 view .LVU12352
.LBE8514:
.LBE8513:
.LBE8510:
.LBE8509:
.LBE8518:
.LBE8524:
	.loc 1 40349 1 view .LVU12353
	addq	$4216, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.LVL3020:
.L2309:
	.cfi_restore_state
	.loc 1 40259 9 is_stmt 1 view .LVU12354
.LBB8525:
.LBI8525:
	.loc 1 30057 13 view .LVU12355
.LBB8526:
	.loc 1 30059 5 view .LVU12356
	movq	-4216(%rbp), %rcx
	cmpq	%r13, %rcx
	je	.L2200
.LVL3021:
.LBB8527:
.LBI8527:
	.loc 1 30057 13 view .LVU12357
.LBB8528:
	.loc 1 30063 5 view .LVU12358
.LBB8529:
.LBI8529:
	.loc 2 2066 28 view .LVU12359
.LBB8530:
	.loc 2 2066 91 view .LVU12360
	.loc 2 2066 91 is_stmt 0 view .LVU12361
.LBE8530:
.LBE8529:
.LBE8528:
.LBE8527:
.LBE8526:
.LBE8525:
	.loc 1 44156 5 is_stmt 1 view .LVU12362
	.loc 1 44164 5 view .LVU12363
.LBB8539:
.LBB8538:
.LBB8537:
.LBB8536:
.LBB8532:
.LBB8531:
	.loc 2 2066 132 is_stmt 0 view .LVU12364
	movl	-4200(%rbp), %r12d
.LVL3022:
	.loc 2 2066 132 view .LVU12365
	sall	$2, %r12d
.LBE8531:
.LBE8532:
	.loc 1 30063 22 view .LVU12366
	imulq	-4240(%rbp), %r12
.LVL3023:
.LBB8533:
.LBI8533:
	.loc 1 1790 23 is_stmt 1 view .LVU12367
.LBB8534:
	.loc 1 1795 5 view .LVU12368
	.loc 1 1795 24 view .LVU12369
	testq	%r12, %r12
	je	.L2200
	movl	$4294967295, %r14d
.LVL3024:
	.p2align 4,,10
	.p2align 3
.L2205:
.LBB8535:
	.loc 1 1796 9 view .LVU12370
	.loc 1 1797 9 view .LVU12371
	cmpq	%r14, %r12
	movq	%r14, %rbx
	.loc 1 1801 9 is_stmt 0 view .LVU12372
	movq	%r13, %rsi
	movq	%rcx, %rdi
	cmovbe	%r12, %rbx
.LVL3025:
	.loc 1 1801 9 is_stmt 1 view .LVU12373
	movq	%rbx, %rdx
	.loc 1 1805 13 is_stmt 0 view .LVU12374
	addq	%rbx, %r13
.LVL3026:
	.loc 1 1801 9 view .LVU12375
	call	memcpy
.LVL3027:
	.loc 1 1801 9 view .LVU12376
	movq	%rax, %rcx
	.loc 1 1803 9 is_stmt 1 view .LVU12377
.LVL3028:
	.loc 1 1804 9 view .LVU12378
	.loc 1 1804 13 is_stmt 0 view .LVU12379
	addq	%rbx, %rcx
.LVL3029:
	.loc 1 1805 9 is_stmt 1 view .LVU12380
	.loc 1 1805 9 is_stmt 0 view .LVU12381
.LBE8535:
	.loc 1 1795 5 is_stmt 1 view .LVU12382
	.loc 1 1795 24 view .LVU12383
	subq	%rbx, %r12
.LVL3030:
	.loc 1 1795 24 is_stmt 0 view .LVU12384
	jne	.L2205
	jmp	.L2200
.LVL3031:
.L2220:
	.loc 1 1795 24 view .LVU12385
.LBE8534:
.LBE8533:
.LBE8536:
.LBE8537:
.LBE8538:
.LBE8539:
.LBB8540:
.LBB8519:
.LBB8503:
.LBB8482:
.LBB8477:
.LBB8403:
	.loc 1 40327 41 is_stmt 1 view .LVU12386
	cmpq	$0, -4240(%rbp)
	je	.L2200
.LBB8404:
	.loc 1 40340 35 is_stmt 0 view .LVU12387
	movl	-4200(%rbp), %eax
	.loc 1 40341 35 view .LVU12388
	movl	%r14d, %r15d
	.loc 1 40340 35 view .LVU12389
	movq	%rax, -4224(%rbp)
	movq	%rax, %rsi
	.loc 1 40340 32 view .LVU12390
	salq	$2, %rax
	movq	%rax, -4248(%rbp)
	.loc 1 40341 32 view .LVU12391
	leaq	0(,%r15,4), %rax
	movq	%rax, -4256(%rbp)
	testl	%esi, %esi
	je	.L2200
	movq	%r15, %rax
	movq	%r13, %r15
	movq	%r12, %r13
.LVL3032:
	.loc 1 40341 32 view .LVU12392
	movq	%rax, %r12
.LVL3033:
	.p2align 4,,10
	.p2align 3
.L2248:
.LBB8405:
	.loc 1 40328 55 is_stmt 1 view .LVU12393
.LBE8405:
.LBE8404:
.LBE8403:
.LBB8469:
.LBB8397:
.LBB8393:
.LBB8390:
	.loc 1 40313 31 is_stmt 0 view .LVU12394
	movq	$0, -4160(%rbp)
.LVL3034:
	.p2align 4,,10
	.p2align 3
.L2240:
	.loc 1 40313 31 view .LVU12395
.LBE8390:
.LBE8393:
.LBE8397:
.LBE8469:
.LBB8470:
.LBB8463:
.LBB8459:
.LBB8406:
	.loc 1 40329 25 is_stmt 1 view .LVU12396
	.loc 1 40330 25 view .LVU12397
.LBB8407:
.LBI8407:
	.loc 1 42261 19 view .LVU12398
.LBB8408:
	.loc 1 42263 5 view .LVU12399
	cmpq	$0, -4208(%rbp)
	je	.L2316
	.loc 1 42266 9 view .LVU12400
	.loc 1 42270 9 view .LVU12401
	.loc 1 42270 40 is_stmt 0 view .LVU12402
	movq	-4208(%rbp), %rax
	movq	-4160(%rbp), %rsi
	movzbl	(%rax,%rsi), %eax
.LVL3035:
	.loc 1 42270 40 view .LVU12403
.LBE8408:
.LBE8407:
	.loc 1 40332 25 is_stmt 1 view .LVU12404
.LBB8415:
	.loc 1 40332 57 view .LVU12405
	testl	%r14d, %r14d
	je	.L2253
.L2317:
.LBB8416:
.LBB8417:
.LBB8418:
	.loc 1 39747 51 is_stmt 0 view .LVU12406
	movzbl	%al, %eax
	.loc 1 39747 51 view .LVU12407
	leaq	(%rax,%rax,2), %rdx
	leaq	_ZL22g_maChannelPlaneRatios.lto_priv.0(,%rdx,8), %rax
.LVL3036:
	.loc 1 39747 51 view .LVU12408
	movss	_ZL22g_maChannelPlaneRatios.lto_priv.0(,%rdx,8), %xmm2
	.loc 1 39748 51 view .LVU12409
	movss	4(%rax), %xmm3
	.loc 1 39749 51 view .LVU12410
	movss	8(%rax), %xmm4
	.loc 1 39750 51 view .LVU12411
	movss	12(%rax), %xmm5
	.loc 1 39751 51 view .LVU12412
	movss	16(%rax), %xmm6
	.loc 1 39752 51 view .LVU12413
	movss	20(%rax), %xmm7
	testq	%r13, %r13
	je	.L2244
	xorl	%edx, %edx
.LBE8418:
.LBE8417:
.LBE8416:
.LBE8415:
	.loc 1 40329 31 view .LVU12414
	pxor	%xmm1, %xmm1
.LVL3037:
	.p2align 4,,10
	.p2align 3
.L2246:
.LBB8449:
.LBB8443:
	.loc 1 40333 29 is_stmt 1 view .LVU12415
.LBB8423:
.LBI8423:
	.loc 1 42261 19 view .LVU12416
.LBB8424:
	.loc 1 42263 5 view .LVU12417
	.loc 1 42266 9 view .LVU12418
	.loc 1 42270 9 view .LVU12419
	.loc 1 42270 9 is_stmt 0 view .LVU12420
.LBE8424:
.LBE8423:
	.loc 1 40334 29 is_stmt 1 view .LVU12421
.LBB8436:
.LBI8417:
	.loc 1 39714 14 view .LVU12422
.LBB8419:
	.loc 1 39750 97 is_stmt 0 view .LVU12423
	movzbl	0(%r13,%rdx), %eax
	leaq	(%rax,%rax,2), %rcx
	leaq	_ZL22g_maChannelPlaneRatios.lto_priv.0(,%rcx,8), %rax
	.loc 1 39747 53 view .LVU12424
	movss	_ZL22g_maChannelPlaneRatios.lto_priv.0(,%rcx,8), %xmm9
	.loc 1 39750 53 view .LVU12425
	movss	12(%rax), %xmm0
	.loc 1 39749 53 view .LVU12426
	movss	8(%rax), %xmm8
	.loc 1 39747 53 view .LVU12427
	mulss	%xmm2, %xmm9
	.loc 1 39749 53 view .LVU12428
	mulss	%xmm4, %xmm8
	.loc 1 39750 53 view .LVU12429
	mulss	%xmm5, %xmm0
	.loc 1 39746 11 view .LVU12430
	addss	%xmm8, %xmm0
	.loc 1 39748 53 view .LVU12431
	movss	4(%rax), %xmm8
	mulss	%xmm3, %xmm8
	.loc 1 39746 11 view .LVU12432
	addss	%xmm9, %xmm8
	.loc 1 39751 53 view .LVU12433
	movss	16(%rax), %xmm9
	mulss	%xmm6, %xmm9
	.loc 1 39746 11 view .LVU12434
	addss	%xmm8, %xmm0
	.loc 1 39752 53 view .LVU12435
	movss	20(%rax), %xmm8
	mulss	%xmm7, %xmm8
	.loc 1 39746 11 view .LVU12436
	addss	%xmm9, %xmm8
	addss	%xmm8, %xmm0
.LBE8419:
.LBE8436:
	.loc 1 40334 67 view .LVU12437
	mulss	(%r15,%rdx,4), %xmm0
.LBE8443:
	.loc 1 40332 57 view .LVU12438
	addq	$1, %rdx
.LVL3038:
.LBB8444:
	.loc 1 40334 42 view .LVU12439
	addss	%xmm0, %xmm1
.LVL3039:
	.loc 1 40334 42 view .LVU12440
.LBE8444:
	.loc 1 40332 25 is_stmt 1 view .LVU12441
	.loc 1 40332 57 view .LVU12442
	cmpq	%rdx, %r12
	jne	.L2246
.LVL3040:
.L2243:
	.loc 1 40332 57 is_stmt 0 view .LVU12443
.LBE8449:
	.loc 1 40337 25 is_stmt 1 discriminator 2 view .LVU12444
	.loc 1 40337 49 is_stmt 0 discriminator 2 view .LVU12445
	movq	-4160(%rbp), %rax
	movq	-4216(%rbp), %rsi
	movss	%xmm1, (%rsi,%rax,4)
.LBE8406:
	.loc 1 40328 21 is_stmt 1 discriminator 2 view .LVU12446
.LVL3041:
	.loc 1 40328 55 discriminator 2 view .LVU12447
	addq	$1, %rax
.LVL3042:
	.loc 1 40328 55 is_stmt 0 discriminator 2 view .LVU12448
	movq	%rax, -4160(%rbp)
.LVL3043:
	.loc 1 40328 55 discriminator 2 view .LVU12449
	cmpq	%rax, -4224(%rbp)
	jne	.L2240
.LBE8459:
	.loc 1 40340 21 is_stmt 1 view .LVU12450
.LVL3044:
	.loc 1 40341 21 view .LVU12451
.LBE8463:
	.loc 1 40327 62 is_stmt 0 view .LVU12452
	addl	$1, -4228(%rbp)
.LVL3045:
.LBB8464:
	.loc 1 40340 32 view .LVU12453
	movq	-4248(%rbp), %rsi
.LVL3046:
	.loc 1 40340 32 view .LVU12454
.LBE8464:
	.loc 1 40327 62 view .LVU12455
	movl	-4228(%rbp), %eax
.LVL3047:
.LBB8465:
	.loc 1 40340 32 view .LVU12456
	addq	%rsi, -4216(%rbp)
.LVL3048:
	.loc 1 40341 32 view .LVU12457
	addq	-4256(%rbp), %r15
.LVL3049:
	.loc 1 40341 32 view .LVU12458
.LBE8465:
	.loc 1 40327 17 is_stmt 1 view .LVU12459
	.loc 1 40327 41 view .LVU12460
	cmpq	-4240(%rbp), %rax
	jb	.L2248
	jmp	.L2200
.LVL3050:
	.p2align 4,,10
	.p2align 3
.L2316:
.LBB8466:
.LBB8460:
.LBB8456:
.LBB8450:
.LBB8413:
	.loc 1 42264 9 view .LVU12461
	.loc 1 42264 9 is_stmt 0 view .LVU12462
.LBE8413:
.LBE8450:
.LBE8456:
.LBE8460:
.LBE8466:
.LBE8470:
.LBE8477:
.LBE8482:
.LBE8503:
.LBE8519:
.LBE8540:
	.loc 1 42947 5 is_stmt 1 view .LVU12463
.LBB8541:
.LBB8520:
.LBB8504:
.LBB8483:
.LBB8478:
.LBB8471:
.LBB8467:
.LBB8461:
.LBB8457:
.LBB8451:
.LBB8414:
.LBB8409:
.LBI8409:
	.loc 1 42261 19 view .LVU12464
.LBB8410:
.LBB8411:
.LBI8411:
	.loc 1 42945 19 view .LVU12465
.LBB8412:
	.loc 1 42987 66 is_stmt 0 view .LVU12466
	movl	-4160(%rbp), %esi
	movl	-4200(%rbp), %edi
	call	_ZL46ma_channel_map_init_standard_channel_microsoftjj.lto_priv.0
.LVL3051:
	.loc 1 42987 66 view .LVU12467
.LBE8412:
.LBE8411:
.LBE8410:
.LBE8409:
.LBE8414:
.LBE8451:
	.loc 1 40332 25 is_stmt 1 view .LVU12468
.LBB8452:
	.loc 1 40332 57 view .LVU12469
	testl	%r14d, %r14d
	jne	.L2317
.L2253:
	.loc 1 40332 57 is_stmt 0 view .LVU12470
.LBE8452:
	.loc 1 40329 31 view .LVU12471
	pxor	%xmm1, %xmm1
	jmp	.L2243
.LVL3052:
	.p2align 4,,10
	.p2align 3
.L2244:
.LBB8453:
.LBB8445:
.LBB8437:
.LBB8420:
	.loc 1 39752 51 view .LVU12472
	xorl	%ebx, %ebx
.LBE8420:
.LBE8437:
.LBE8445:
.LBE8453:
	.loc 1 40329 31 view .LVU12473
	pxor	%xmm1, %xmm1
	movss	%xmm2, -4168(%rbp)
	movss	%xmm3, -4176(%rbp)
	movss	%xmm4, -4184(%rbp)
	movss	%xmm5, -4188(%rbp)
	movss	%xmm6, -4192(%rbp)
	movss	%xmm7, -4196(%rbp)
.LVL3053:
	.p2align 4,,10
	.p2align 3
.L2247:
.LBB8454:
.LBB8446:
.LBB8438:
.LBB8433:
.LBB8425:
.LBB8426:
.LBB8427:
.LBB8428:
	.loc 1 42987 66 view .LVU12474
	movl	%ebx, %esi
	movl	%r14d, %edi
	movss	%xmm1, -4152(%rbp)
.LVL3054:
	.loc 1 42987 66 view .LVU12475
.LBE8428:
.LBE8427:
.LBE8426:
.LBE8425:
.LBE8433:
.LBE8438:
	.loc 1 40333 29 is_stmt 1 view .LVU12476
.LBB8439:
	.loc 1 42261 19 view .LVU12477
.LBB8434:
	.loc 1 42263 5 view .LVU12478
	.loc 1 42264 9 view .LVU12479
	.loc 1 42264 9 is_stmt 0 view .LVU12480
.LBE8434:
.LBE8439:
.LBE8446:
.LBE8454:
.LBE8457:
.LBE8461:
.LBE8467:
.LBE8471:
.LBE8478:
.LBE8483:
.LBE8504:
.LBE8520:
.LBE8541:
	.loc 1 42947 5 is_stmt 1 view .LVU12481
.LBB8542:
.LBB8521:
.LBB8505:
.LBB8484:
.LBB8479:
.LBB8472:
.LBB8468:
.LBB8462:
.LBB8458:
.LBB8455:
.LBB8447:
.LBB8440:
.LBB8435:
.LBB8432:
.LBI8425:
	.loc 1 42261 19 view .LVU12482
.LBB8431:
.LBB8430:
.LBI8427:
	.loc 1 42945 19 view .LVU12483
.LBB8429:
	.loc 1 42987 66 is_stmt 0 view .LVU12484
	call	_ZL46ma_channel_map_init_standard_channel_microsoftjj.lto_priv.0
.LVL3055:
	.loc 1 42987 66 view .LVU12485
.LBE8429:
.LBE8430:
.LBE8431:
.LBE8432:
.LBE8435:
.LBE8440:
	.loc 1 40334 29 is_stmt 1 view .LVU12486
.LBB8441:
	.loc 1 39714 14 view .LVU12487
.LBB8421:
	.loc 1 39749 53 is_stmt 0 view .LVU12488
	movss	-4184(%rbp), %xmm0
	.loc 1 39750 53 view .LVU12489
	movss	-4188(%rbp), %xmm8
	.loc 1 39749 97 view .LVU12490
	movzbl	%al, %eax
	.loc 1 39749 97 view .LVU12491
.LBE8421:
.LBE8441:
	.loc 1 40334 42 view .LVU12492
	movss	-4152(%rbp), %xmm1
.LBB8442:
.LBB8422:
	.loc 1 39748 53 view .LVU12493
	movss	-4176(%rbp), %xmm9
	.loc 1 39749 97 view .LVU12494
	leaq	(%rax,%rax,2), %rcx
	leaq	_ZL22g_maChannelPlaneRatios.lto_priv.0(,%rcx,8), %rax
.LVL3056:
	.loc 1 39750 53 view .LVU12495
	mulss	12(%rax), %xmm8
	.loc 1 39749 53 view .LVU12496
	mulss	8(%rax), %xmm0
	.loc 1 39748 53 view .LVU12497
	mulss	4(%rax), %xmm9
	.loc 1 39746 11 view .LVU12498
	addss	%xmm8, %xmm0
	.loc 1 39747 53 view .LVU12499
	movss	-4168(%rbp), %xmm8
	mulss	_ZL22g_maChannelPlaneRatios.lto_priv.0(,%rcx,8), %xmm8
	.loc 1 39746 11 view .LVU12500
	addss	%xmm9, %xmm8
	.loc 1 39752 53 view .LVU12501
	movss	-4196(%rbp), %xmm9
	mulss	20(%rax), %xmm9
	.loc 1 39746 11 view .LVU12502
	addss	%xmm8, %xmm0
	.loc 1 39751 53 view .LVU12503
	movss	-4192(%rbp), %xmm8
	mulss	16(%rax), %xmm8
	.loc 1 39746 11 view .LVU12504
	addss	%xmm9, %xmm8
	addss	%xmm8, %xmm0
.LBE8422:
.LBE8442:
	.loc 1 40334 67 view .LVU12505
	mulss	(%r15,%rbx,4), %xmm0
.LBE8447:
	.loc 1 40332 57 view .LVU12506
	addq	$1, %rbx
.LVL3057:
.LBB8448:
	.loc 1 40334 42 view .LVU12507
	addss	%xmm0, %xmm1
.LVL3058:
	.loc 1 40334 42 view .LVU12508
.LBE8448:
	.loc 1 40332 25 is_stmt 1 view .LVU12509
	.loc 1 40332 57 view .LVU12510
	cmpq	%rbx, %r12
	jne	.L2247
	jmp	.L2243
.LVL3059:
	.p2align 4,,10
	.p2align 3
.L2314:
	.loc 1 40332 57 is_stmt 0 view .LVU12511
.LBE8455:
.LBE8458:
.LBE8462:
.LBE8468:
.LBE8472:
.LBB8473:
.LBB8398:
	.loc 1 40322 21 is_stmt 1 view .LVU12512
.LBE8398:
	.loc 1 40311 62 is_stmt 0 view .LVU12513
	leal	1(%r9), %eax
.LBB8399:
	.loc 1 40322 32 view .LVU12514
	addq	-4152(%rbp), %r10
.LVL3060:
	.loc 1 40323 21 is_stmt 1 view .LVU12515
	.loc 1 40323 32 is_stmt 0 view .LVU12516
	addq	-4160(%rbp), %r13
.LVL3061:
	.loc 1 40323 32 view .LVU12517
.LBE8399:
	.loc 1 40311 17 is_stmt 1 view .LVU12518
	.loc 1 40311 62 is_stmt 0 view .LVU12519
	movq	%rax, %r9
.LVL3062:
	.loc 1 40311 41 is_stmt 1 view .LVU12520
	cmpq	-4240(%rbp), %rax
	jb	.L2238
	jmp	.L2200
.LVL3063:
.L2252:
.LBB8400:
.LBB8394:
.LBB8391:
	.loc 1 40315 41 is_stmt 0 view .LVU12521
	movl	-4228(%rbp), %edx
	.loc 1 40313 31 view .LVU12522
	pxor	%xmm0, %xmm0
	jmp	.L2233
.LVL3064:
.L2313:
	.loc 1 40313 31 view .LVU12523
.LBE8391:
.LBE8394:
.LBE8400:
.LBE8473:
.LBB8474:
.LBB8382:
.LBB8378:
.LBB8362:
	.loc 1 42264 9 is_stmt 1 view .LVU12524
	.loc 1 42264 9 is_stmt 0 view .LVU12525
.LBE8362:
.LBE8378:
.LBE8382:
.LBE8474:
.LBE8479:
.LBE8484:
.LBE8505:
.LBE8521:
.LBE8542:
	.loc 1 42947 5 is_stmt 1 view .LVU12526
.LBB8543:
.LBB8522:
.LBB8506:
.LBB8485:
.LBB8480:
.LBB8475:
.LBB8383:
.LBB8379:
.LBB8363:
.LBB8358:
.LBI8358:
	.loc 1 42261 19 view .LVU12527
.LBB8359:
.LBB8360:
.LBI8360:
	.loc 1 42945 19 view .LVU12528
.LBB8361:
	.loc 1 42987 66 is_stmt 0 view .LVU12529
	movl	-4152(%rbp), %esi
	movl	-4200(%rbp), %edi
	call	_ZL46ma_channel_map_init_standard_channel_microsoftjj.lto_priv.0
.LVL3065:
	.loc 1 42987 66 view .LVU12530
	jmp	.L2223
.LVL3066:
.L2227:
	.loc 1 42987 66 view .LVU12531
.LBE8361:
.LBE8360:
.LBE8359:
.LBE8358:
.LBE8363:
.LBE8379:
.LBB8380:
.LBB8376:
	.loc 1 40307 108 view .LVU12532
	xorl	%edx, %edx
	movl	-4160(%rbp), %r14d
	movq	%r12, -4176(%rbp)
	movq	%rdx, %r12
.LVL3067:
	.p2align 4,,10
	.p2align 3
.L2230:
	.loc 1 40306 25 is_stmt 1 view .LVU12533
.LBB8374:
	.loc 1 42261 19 view .LVU12534
.LBB8372:
	.loc 1 42263 5 view .LVU12535
	.loc 1 42264 9 view .LVU12536
	.loc 1 42264 9 is_stmt 0 view .LVU12537
.LBE8372:
.LBE8374:
.LBE8376:
.LBE8380:
.LBE8383:
.LBE8475:
.LBE8480:
.LBE8485:
.LBE8506:
.LBE8522:
.LBE8543:
	.loc 1 42947 5 is_stmt 1 view .LVU12538
.LBB8544:
.LBB8523:
.LBB8507:
.LBB8486:
.LBB8481:
.LBB8476:
.LBB8384:
.LBB8381:
.LBB8377:
.LBB8375:
.LBB8373:
.LBB8368:
.LBI8368:
	.loc 1 42261 19 view .LVU12539
.LBB8369:
.LBB8370:
.LBI8370:
	.loc 1 42945 19 view .LVU12540
.LBB8371:
	.loc 1 42987 66 is_stmt 0 view .LVU12541
	movl	%r12d, %esi
	movl	%r14d, %edi
	call	_ZL46ma_channel_map_init_standard_channel_microsoftjj.lto_priv.0
.LVL3068:
	.loc 1 42987 66 view .LVU12542
.LBE8371:
.LBE8370:
.LBE8369:
.LBE8368:
.LBE8373:
.LBE8375:
	.loc 1 40307 25 is_stmt 1 view .LVU12543
	.loc 1 40307 108 is_stmt 0 view .LVU12544
	movl	%ebx, %edi
	movzbl	%al, %esi
	call	_ZL48ma_calculate_channel_position_rectangular_weighthh
.LVL3069:
	.loc 1 40307 58 view .LVU12545
	movss	%xmm0, 0(%r13,%r12,4)
.LBE8377:
	.loc 1 40305 21 is_stmt 1 view .LVU12546
.LVL3070:
	.loc 1 40305 53 view .LVU12547
	addq	$1, %r12
.LVL3071:
	.loc 1 40305 53 is_stmt 0 view .LVU12548
	cmpq	%r15, %r12
	jne	.L2230
	movq	-4176(%rbp), %r12
	jmp	.L2231
.LVL3072:
.L2312:
	.loc 1 40305 53 view .LVU12549
.LBE8381:
.LBE8384:
.LBE8476:
.LBE8481:
.LBE8486:
.LBB8487:
	.loc 1 40280 13 is_stmt 1 view .LVU12550
	.loc 1 40282 13 view .LVU12551
.LBB8488:
.LBI8488:
	.loc 1 39873 18 view .LVU12552
.LBB8489:
	.loc 1 39875 5 view .LVU12553
	.loc 1 39876 5 view .LVU12554
	.loc 1 39878 5 view .LVU12555
	.loc 1 39878 54 is_stmt 0 view .LVU12556
	testl	%r14d, %r14d
	je	.L2200
	movl	-4200(%rbp), %r15d
	testl	%r15d, %r15d
	je	.L2200
	leaq	-4144(%rbp), %rax
.LVL3073:
	.loc 1 39878 54 view .LVU12557
	movl	%r15d, %ecx
	movl	%r14d, %esi
	movq	%r12, %rdi
	movq	-4208(%rbp), %rdx
	movq	%rax, %r8
	movq	%rax, -4168(%rbp)
	call	_ZL34ma_channel_map_build_shuffle_tablePKhjS0_jPh.part.0.lto_priv.0
.LVL3074:
	.loc 1 39878 54 view .LVU12558
.LBE8489:
.LBE8488:
	.loc 1 40283 13 is_stmt 1 view .LVU12559
	testl	%eax, %eax
	jne	.L2200
	.loc 1 40287 13 view .LVU12560
.LVL3075:
.LBB8490:
.LBI8490:
	.loc 1 40049 18 view .LVU12561
.LBB8491:
	.loc 1 40051 5 view .LVU12562
	movq	-4216(%rbp), %r9
	testq	%r9, %r9
	je	.L2200
	testq	%r13, %r13
	je	.L2200
.LVL3076:
.LBB8492:
.LBB8493:
.LBB8494:
	.loc 1 40034 29 view .LVU12563
	movq	-4240(%rbp), %rbx
	testq	%rbx, %rbx
	je	.L2200
.LBB8495:
	.loc 1 40044 23 is_stmt 0 view .LVU12564
	movl	%r15d, %r8d
	.loc 1 40045 23 view .LVU12565
	movl	%r14d, %edi
.LBE8495:
	.loc 1 40034 17 view .LVU12566
	movq	-4168(%rbp), %r11
	xorl	%esi, %esi
.LBB8500:
	.loc 1 40044 23 view .LVU12567
	movq	%r8, %r10
	.loc 1 40045 20 view .LVU12568
	salq	$2, %rdi
	.loc 1 40044 20 view .LVU12569
	salq	$2, %r8
.LVL3077:
.L2219:
.LBB8496:
	.loc 1 40035 43 is_stmt 1 view .LVU12570
.LBE8496:
.LBE8500:
	.loc 1 40034 17 is_stmt 0 view .LVU12571
	xorl	%eax, %eax
	jmp	.L2218
.LVL3078:
	.p2align 4,,10
	.p2align 3
.L2319:
.LBB8501:
.LBB8499:
.LBB8497:
	.loc 1 40038 17 is_stmt 1 view .LVU12572
	.loc 1 40038 63 is_stmt 0 view .LVU12573
	movss	0(%r13,%rcx,4), %xmm0
	.loc 1 40038 41 view .LVU12574
	movss	%xmm0, (%r9,%rax,4)
.LBE8497:
	.loc 1 40035 9 is_stmt 1 view .LVU12575
.LVL3079:
	.loc 1 40035 43 view .LVU12576
	addq	$1, %rax
.LVL3080:
	.loc 1 40035 43 is_stmt 0 view .LVU12577
	cmpl	%eax, %r10d
	jbe	.L2318
.LVL3081:
.L2218:
.LBB8498:
	.loc 1 40036 13 is_stmt 1 view .LVU12578
	.loc 1 40036 22 is_stmt 0 view .LVU12579
	movzbl	(%rax,%r11), %ecx
.LVL3082:
	.loc 1 40037 13 is_stmt 1 view .LVU12580
	cmpl	%ecx, %r14d
	ja	.L2319
	.loc 1 40040 17 view .LVU12581
	.loc 1 40040 41 is_stmt 0 view .LVU12582
	movl	$0x00000000, (%r9,%rax,4)
.LBE8498:
	.loc 1 40035 9 is_stmt 1 view .LVU12583
.LVL3083:
	.loc 1 40035 43 view .LVU12584
	addq	$1, %rax
.LVL3084:
	.loc 1 40035 43 is_stmt 0 view .LVU12585
	cmpl	%eax, %r10d
	ja	.L2218
.L2318:
	.loc 1 40035 43 view .LVU12586
.LBE8499:
	.loc 1 40044 9 is_stmt 1 view .LVU12587
.LBE8501:
	.loc 1 40034 50 is_stmt 0 view .LVU12588
	addq	$1, %rsi
.LVL3085:
.LBB8502:
	.loc 1 40044 20 view .LVU12589
	addq	%r8, %r9
.LVL3086:
	.loc 1 40045 9 is_stmt 1 view .LVU12590
	.loc 1 40045 20 is_stmt 0 view .LVU12591
	addq	%rdi, %r13
.LVL3087:
	.loc 1 40045 20 view .LVU12592
.LBE8502:
	.loc 1 40034 5 is_stmt 1 view .LVU12593
	.loc 1 40034 29 view .LVU12594
	cmpq	%rsi, %rbx
	jne	.L2219
	jmp	.L2200
.LVL3088:
.L2310:
	.loc 1 40034 29 is_stmt 0 view .LVU12595
.LBE8494:
.LBE8493:
.LBE8492:
.LBE8491:
.LBE8490:
.LBE8487:
.LBE8507:
.LBE8523:
.LBE8544:
	.loc 1 40265 9 is_stmt 1 view .LVU12596
	.loc 1 40265 42 is_stmt 0 view .LVU12597
	movq	-4240(%rbp), %r8
	movl	%r14d, %ecx
	movq	%r12, %rdx
	movq	%r13, %rsi
	movq	-4216(%rbp), %rdi
	.loc 1 40349 1 view .LVU12598
	addq	$4216, %rsp
	popq	%rbx
	popq	%r12
.LVL3089:
	.loc 1 40349 1 view .LVU12599
	popq	%r13
.LVL3090:
	.loc 1 40349 1 view .LVU12600
	popq	%r14
.LVL3091:
	.loc 1 40349 1 view .LVU12601
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	.loc 1 40265 42 view .LVU12602
	jmp	_ZL33ma_channel_map_apply_mono_out_f32PfPKfPKhjy.isra.0
.LVL3092:
.L2311:
	.cfi_restore_state
	.loc 1 40271 9 is_stmt 1 view .LVU12603
	.loc 1 40271 41 is_stmt 0 view .LVU12604
	movq	-4240(%rbp), %r8
	movl	-4200(%rbp), %edx
	movl	%ebx, %r9d
	movq	%r13, %rcx
	movq	-4208(%rbp), %rsi
	movq	-4216(%rbp), %rdi
	.loc 1 40349 1 view .LVU12605
	addq	$4216, %rsp
	popq	%rbx
	popq	%r12
.LVL3093:
	.loc 1 40349 1 view .LVU12606
	popq	%r13
.LVL3094:
	.loc 1 40349 1 view .LVU12607
	popq	%r14
.LVL3095:
	.loc 1 40349 1 view .LVU12608
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	.loc 1 40271 41 view .LVU12609
	jmp	_ZL32ma_channel_map_apply_mono_in_f32PfPKhjPKfy22ma_mono_expansion_mode.isra.0
.LVL3096:
	.loc 1 40271 41 view .LVU12610
	.cfi_endproc
.LFE204:
	.size	_ZL24ma_channel_map_apply_f32PfPKhjPKfS1_jy19ma_channel_mix_mode22ma_mono_expansion_mode.lto_priv.0, .-_ZL24ma_channel_map_apply_f32PfPKhjPKfS1_jy19ma_channel_mix_mode22ma_mono_expansion_mode.lto_priv.0
	.section	.rodata.str1.8
	.align 8
.LC133:
	.string	"ma_result ma_channel_converter_process_pcm_frames__mono_out(ma_channel_converter*, void*, const void*, ma_uint64)"
	.section	.rodata.str1.1
.LC134:
	.string	"pConverter->channelsOut == 1"
	.section	.rodata.str1.8
	.align 8
.LC135:
	.string	"ma_result ma_channel_converter_process_pcm_frames__mono_in(ma_channel_converter*, void*, const void*, ma_