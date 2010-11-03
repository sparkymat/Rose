; Copyright (c) 2010 Ajith Hussain
; All rights reserved.
; This component and the accompanying materials are made available
; under the terms of "Eclipse Public License v1.0"
; which accompanies this distribution, and is available
; at the URL "http://www.eclipse.org/legal/epl-v10.html".
;
; Initial Contributors:
; Ajith Hussain - initial contribution.
;
; Contributors:
;
; Description:
;
;

global loader
extern kmain

MODULEALIGN	equ	1<<0
MEMINFO		equ	1<<1
FLAGS		equ	MODULEALIGN | MEMINFO
MAGIC		equ	0x1BADB002
CHECKSUM	equ	-(MAGIC + FLAGS)

section .text
align 4
MultiBootHeader:
	dd MAGIC
	dd FLAGS
	dd CHECKSUM

STACKSIZE	equ	0x4000

loader:
	mov	esp, stack+STACKSIZE
	push eax
	push ebx

	call kmain

	cli
hang:
	hlt
	jmp hang

section .bss
align 4
stack:
	resb STACKSIZE
