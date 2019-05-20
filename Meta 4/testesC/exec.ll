declare i32 @atoi(i8*)
declare i32 @printf(i8*, ...)
define i32 @main() {
	%a = alloca i32 , align 4
	%d = alloca double , align 8
	%1 = load i32, i32* %a, align 4
	%call1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.0, i32 0, i32 0), i32 %1)
	%2 = add i32 0, 1
	%call2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i32 0, i32 0), i32 %2)
	%3 = load i32, i32* %a, align 4
	%call3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.2, i32 0, i32 0), i32 %3)
	%4 = add i32 0, 1
	%call4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.3, i32 0, i32 0), i32 %4)
	%5 = fadd double 0.000000e+00, 1.000000e+00
	%call5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.4, i32 0, i32 0), double %5)
	%6 = load double, double* %d, align 4
	%7 = load double, double* %d, align 4
	%call6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.5, i32 0, i32 0), double %6)
	%call7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.6, i32 0, i32 0))
	ret i32 1
}
@.str.0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@.str.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@.str.2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@.str.3 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@.str.4 = private unnamed_addr constant [7 x i8] c"%.08f\0A\00", align 1
@.str.5 = private unnamed_addr constant [7 x i8] c"%.08f\0A\00", align 1
@.str.6 = private unnamed_addr constant [5 x i8] c"asd\0A\00", align 1
