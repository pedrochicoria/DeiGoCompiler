Line 20, column 19: illegal character (:)
declare i32 @atoi(i8*)
declare i32 @printf(i8*, ...)
@global.var.a = common global i32 0, align 4
@global.var.b = common global i32 0, align 4
define i32 @main() {
	ret i32 1
}
define i32 @funcao(i32 %a, i1 %b, double %f) {
	%a.addr = alloca i32 , align 4
	%b.addr = alloca i1 , align 4
	%f.addr = alloca double , align 8
	%a2 = alloca i32 , align 4
	%b2 = alloca i1 , align 4
	%f2 = alloca double , align 8
	%str1 = alloca 	%str2 = alloca 	store i32 %a, i32* %a.addr, align 4
	store i1 %b, i1* %b.addr, align 4
	store double %f, double* %f.addr, align 8
	@.str.0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
	@.str.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
	ret i32 1
}
