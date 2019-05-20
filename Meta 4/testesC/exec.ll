declare i32 @atoi(i8*)
declare i32 @printf(i8*, ...)
@global.var.gl = common global i32 0, align 4
@global.var.g2 = common global double 0.0000e+00, align 8
@global.var.b = common global i1 0, align 4
define i32 @main(i32 %argc, i8** %argv) {
	%argc_aux = alloca i32, align 4
	%argv_aux = alloca i8**, align 8
	store i32 %argc, i32* %argc_aux, align 4
	store i8** %argv, i8*** %argv_aux, align 8
	%1 = load double, double* @global.var.g2, align 4
	%2 = fadd double 0.000000e+00, 1.0111000000e+00
	store double %2, double* @global.var.g2, align 8
	%3 = load double, double* @global.var.g2, align 4
	%4 = load double, double* @global.var.g2, align 4
	%5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.0, i32 0, i32 0), double %4)
	ret i32 0
}
define void @retorna() {
	ret void 
}
@.str.0 = private unnamed_addr constant [7 x i8] c"%.08f\0A\00", align 1
