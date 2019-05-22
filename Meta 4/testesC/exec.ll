declare i32 @atoi(i8*)
declare i32 @printf(i8*, ...)
define i32 @main(i32 %argc, i8** %argv) {
	%argc.addr = alloca i32, align 4
	%argv.addr = alloca i8**, align 8
	store i32 %argc, i32* %argc.addr, align 4
	store i8** %argv, i8*** %argv.addr, align 8
	%b = alloca i1 , align 4
	%a = alloca i32 , align 4

	%1 = load i1, i1* %b, align 4
	%2 = zext i1 %1 to i32
	%3 = icmp eq i32 %2, 0
	%4 = icmp eq i1 %1, 1
	br i1 %3, label %compare.if.1, label %compare.else.1

compare.if.1:
	%5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.0, i32 0, i32 0))
	br label %compare.end.1

compare.else.1:
	%6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.1, i32 0, i32 0))
	br label %compare.end.1

compare.end.1:
	%7 = load i32, i32* %a, align 4
	%8 = add i32 0, 1
	store i32 %8, i32* %a, align 4
	%9 = load i32, i32* %a, align 4
	%10 = load i32, i32* %a, align 4
	%11 = add i32 0, 2
	%12 = load i32, i32* %a, align 4
	%13 = mul i32 %11, %12
	%14 = add i32 0, 4
	%15 = add i32 0, 2
	%16 = sdiv i32 %14, %15
	%17 = sdiv i32 %13, %16
	store i32 %17, i32* %a, align 4
	%18 = load i32, i32* %a, align 4
	%19 = load i32, i32* %a, align 4
	%20 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.2, i32 0, i32 0), i32 %19)
	ret i32 0
}
define void @retorna() {

	ret void 
}
@.str.0 = private unnamed_addr constant [6 x i8] c"true\0A\00", align 1
@.str.1 = private unnamed_addr constant [7 x i8] c"false\0A\00", align 1
@.str.2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
