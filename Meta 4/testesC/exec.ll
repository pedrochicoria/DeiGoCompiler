@global.var.a = common global i32 0, align 4
@global.var.b = common global i32 0, align 4
define i32 @main() {
	ret i32 1
}
define i32 @funcao(i32 %a, i1 %b, double %f) {
	%a.addr = alloca i32 , align 4
	%b.addr = alloca i1 , align 4
	%f.addr = alloca float , align 4
	%a2 = alloca i32 , align 4
	%b2 = alloca i1 , align 4
	%f2 = alloca double , align 4
	ret i32 1
}
