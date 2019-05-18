declare i32 @atoi(i8*)
declare i32 @printf(i8*, ...)
define i32 @main() {
	%a = alloca i32 , align 4
	%1 = load i32, i32* %a, align 4
	%call1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.0, i32 0, i32 0), i32 %1)
	%2 = load i32, i32* %1, align 4
	%call2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i32 0, i32 0), i32 %2)
	ret i32 1
}
@.str.0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@.str.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
