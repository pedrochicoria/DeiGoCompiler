declare i32 @atoi(i8*)
declare i32 @printf(i8*, ...)
define i32 @factorial(i32 %n) {
	%n.addr = alloca i32 , align 4
	store i32 %n, i32* %n.addr, align 4
	%1 = load i32, i32* %n, align 4
	%2 = load i32, i32* %n, align 4
	ret i32 0
}
define i32 @main(i32 %argc, i8** %argv) {
	%argc_aux = alloca i32, align 4
	%argv_aux = alloca i8**, align 8
	store i32 %argc, i32* %argc_aux, align 4
	store i8** %argv, i8*** %argv_aux, align 8
	%argument = alloca i32 , align 4
	%3 = load i32, i32* %argument, align 4
	%4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.0, i32 0, i32 0), i32 %3)
	ret i32 0
}
@.str.0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
