.intel_syntax noprefix

.global trap_flag_disable 
.type trap_flag_disable,  @function

trap_flag_disable:
    pushfq
    pop rax
    and rax , ~(1<<8)
    push rax
    popfq
    ret

.global trap_flag_enable
.type trap_flag_enable, @function

trap_flag_enable:
    pushfq
    pop rax
    or rax , (1<<8)
    push rax
    popfq
    ret

.global read_flags
.type read_flags, @function

read_flags:
    pushfq
    pop rax
    ret

