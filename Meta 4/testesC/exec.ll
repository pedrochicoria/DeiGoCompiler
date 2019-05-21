declare i32 @atoi(i8*)
declare i32 @printf(i8*, ...)
define i32 @main(i32 %argc, i8** %argv) {
	%argc.addr = alloca i32, align 4
	%argv.addr = alloca i8**, align 8
	store i32 %argc, i32* %argc.addr, align 4
	store i8** %argv, i8*** %argv.addr, align 8
	%i2 = alloca i32 , align 4
	%1 = load i8**, i8*** %argv.addr, align 8
	%2 = add i32 0, 1
	%3 = getelementptr inbounds i8*, i8** %1, i32 %2
	%4 = load i8*, i8** %3, align 8
	%5 = call i32 @atoi(i8* %4)
	store i32 %5, i32* %i2, align 4
	%6 = load i32, i32* %i2, align 4
	%7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.0, i32 0, i32 0), i32 %6)
	%8 = load i8**, i8*** %argv.addr, align 8
	%9 = add i32 0, 2
	%10 = getelementptr inbounds i8*, i8** %8, i32 %9
	%11 = load i8*, i8** %10, align 8
	%12 = call i32 @atoi(i8* %11)
	store i32 %12, i32* %i2, align 4
	%13 = load i32, i32* %i2, align 4
	%14 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.1, i32 0, i32 0), i32 %13)
	%15 = load i8**, i8*** %argv.addr, align 8
	%16 = add i32 0, 3
	%17 = getelementptr inbounds i8*, i8** %15, i32 %16
	%18 = load i8*, i8** %17, align 8
	%19 = call i32 @atoi(i8* %18)
	store i32 %19, i32* %i2, align 4
	%20 = load i32, i32* %i2, align 4
	%21 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.2, i32 0, i32 0), i32 %20)
	ret i32 0
}
@.str.0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@.str.1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@.str.2 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
