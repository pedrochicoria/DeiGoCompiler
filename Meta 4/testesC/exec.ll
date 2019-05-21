declare i32 @atoi(i8*)
declare i32 @printf(i8*, ...)
@global.var.f2 = common global double 0.0000e+00, align 8
define i32 @main(i32 %argc, i8** %argv) {
	%argc_aux = alloca i32, align 4
	%argv_aux = alloca i8**, align 8
	store i32 %argc, i32* %argc_aux, align 4
	store i8** %argv, i8*** %argv_aux, align 8
	%f1 = alloca double , align 8
	%1 = load double, double* @global.var.f2, align 4
	%2 = fadd double 0.000000e+00, 1.0000000e+00
	store double %2, double* @global.var.f2, align 8
	%3 = load double, double* @global.var.f2, align 4
	%4 = load double, double* %f1, align 4
	%5 = load double, double* @global.var.f2, align 4
	store double %5, double* %f1, align 8
	%6 = load double, double* %f1, align 4
	%7 = load double, double* %f1, align 4
	%8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.0, i32 0, i32 0), double %7)
	%9 = load double, double* %f1, align 4
	%10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.0, i32 0, i32 0), double %9)
	ret i32 0
}
@.str.0 = private unnamed_addr constant [7 x i8] c"%.08f\0A\00", align 1
@.str.1 = private unnamed_addr constant [7 x i8] c"%.08f\0A\00", align 1
