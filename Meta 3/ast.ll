; ModuleID = 'ast.c'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.14.0"

%struct.node = type { i32, i32, %struct.node*, %struct.node*, i8*, i8*, i8* }

@.str = private unnamed_addr constant [5 x i8] c"NULL\00", align 1
@.str.1 = private unnamed_addr constant [3 x i8] c"..\00", align 1
@.str.2 = private unnamed_addr constant [7 x i8] c"%s(%s)\00", align 1
@.str.3 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@.str.4 = private unnamed_addr constant [5 x i8] c"none\00", align 1
@.str.5 = private unnamed_addr constant [6 x i8] c" - %s\00", align 1
@.str.6 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

; Function Attrs: nounwind ssp uwtable
define %struct.node* @newNode(i8* %type, i8* %value, i32 %line, i32 %column) #0 {
entry:
  %retval = alloca %struct.node*, align 8
  %type.addr = alloca i8*, align 8
  %value.addr = alloca i8*, align 8
  %line.addr = alloca i32, align 4
  %column.addr = alloca i32, align 4
  %new = alloca %struct.node*, align 8
  store i8* %type, i8** %type.addr, align 8
  store i8* %value, i8** %value.addr, align 8
  store i32 %line, i32* %line.addr, align 4
  store i32 %column, i32* %column.addr, align 4
  %call = call i8* @malloc(i64 48)
  %0 = bitcast i8* %call to %struct.node*
  store %struct.node* %0, %struct.node** %new, align 8
  %1 = load i8*, i8** %type.addr, align 8
  %call1 = call i8* @strdup(i8* %1)
  %2 = load %struct.node*, %struct.node** %new, align 8
  %type2 = getelementptr inbounds %struct.node, %struct.node* %2, i32 0, i32 5
  store i8* %call1, i8** %type2, align 8
  %3 = load %struct.node*, %struct.node** %new, align 8
  %child = getelementptr inbounds %struct.node, %struct.node* %3, i32 0, i32 2
  store %struct.node* null, %struct.node** %child, align 8
  %4 = load %struct.node*, %struct.node** %new, align 8
  %brother = getelementptr inbounds %struct.node, %struct.node* %4, i32 0, i32 3
  store %struct.node* null, %struct.node** %brother, align 8
  %5 = load i32, i32* %line.addr, align 4
  %6 = load %struct.node*, %struct.node** %new, align 8
  %line3 = getelementptr inbounds %struct.node, %struct.node* %6, i32 0, i32 1
  store i32 %5, i32* %line3, align 4
  %7 = load i32, i32* %column.addr, align 4
  %8 = load %struct.node*, %struct.node** %new, align 8
  %column4 = getelementptr inbounds %struct.node, %struct.node* %8, i32 0, i32 0
  store i32 %7, i32* %column4, align 8
  %9 = load %struct.node*, %struct.node** %new, align 8
  %note = getelementptr inbounds %struct.node, %struct.node* %9, i32 0, i32 6
  store i8* null, i8** %note, align 8
  %10 = load i8*, i8** %value.addr, align 8
  %cmp = icmp eq i8* %10, null
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %11 = load %struct.node*, %struct.node** %new, align 8
  %value5 = getelementptr inbounds %struct.node, %struct.node* %11, i32 0, i32 4
  store i8* null, i8** %value5, align 8
  %12 = load %struct.node*, %struct.node** %new, align 8
  store %struct.node* %12, %struct.node** %retval, align 8
  br label %return

if.end:                                           ; preds = %entry
  %13 = load i8*, i8** %value.addr, align 8
  %call6 = call i8* @strdup(i8* %13)
  %14 = load %struct.node*, %struct.node** %new, align 8
  %value7 = getelementptr inbounds %struct.node, %struct.node* %14, i32 0, i32 4
  store i8* %call6, i8** %value7, align 8
  %15 = load %struct.node*, %struct.node** %new, align 8
  store %struct.node* %15, %struct.node** %retval, align 8
  br label %return

return:                                           ; preds = %if.end, %if.then
  %16 = load %struct.node*, %struct.node** %retval, align 8
  ret %struct.node* %16
}

declare i8* @malloc(i64) #1

declare i8* @strdup(i8*) #1

; Function Attrs: nounwind ssp uwtable
define void @addNote(%struct.node* %nodeAux, i8* %note) #0 {
entry:
  %nodeAux.addr = alloca %struct.node*, align 8
  %note.addr = alloca i8*, align 8
  store %struct.node* %nodeAux, %struct.node** %nodeAux.addr, align 8
  store i8* %note, i8** %note.addr, align 8
  %0 = load i8*, i8** %note.addr, align 8
  %call = call i8* @strdup(i8* %0)
  %1 = load %struct.node*, %struct.node** %nodeAux.addr, align 8
  %note1 = getelementptr inbounds %struct.node, %struct.node* %1, i32 0, i32 6
  store i8* %call, i8** %note1, align 8
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @addBrother(%struct.node* %brother, %struct.node* %newBrother) #0 {
entry:
  %brother.addr = alloca %struct.node*, align 8
  %newBrother.addr = alloca %struct.node*, align 8
  %auxBrother = alloca %struct.node*, align 8
  store %struct.node* %brother, %struct.node** %brother.addr, align 8
  store %struct.node* %newBrother, %struct.node** %newBrother.addr, align 8
  %0 = load %struct.node*, %struct.node** %brother.addr, align 8
  %cmp = icmp ne %struct.node* %0, null
  br i1 %cmp, label %land.lhs.true, label %if.end

land.lhs.true:                                    ; preds = %entry
  %1 = load %struct.node*, %struct.node** %newBrother.addr, align 8
  %cmp1 = icmp ne %struct.node* %1, null
  br i1 %cmp1, label %if.then, label %if.end

if.then:                                          ; preds = %land.lhs.true
  %2 = load %struct.node*, %struct.node** %brother.addr, align 8
  store %struct.node* %2, %struct.node** %auxBrother, align 8
  br label %while.cond

while.cond:                                       ; preds = %while.body, %if.then
  %3 = load %struct.node*, %struct.node** %auxBrother, align 8
  %brother2 = getelementptr inbounds %struct.node, %struct.node* %3, i32 0, i32 3
  %4 = load %struct.node*, %struct.node** %brother2, align 8
  %cmp3 = icmp ne %struct.node* %4, null
  br i1 %cmp3, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %5 = load %struct.node*, %struct.node** %auxBrother, align 8
  %brother4 = getelementptr inbounds %struct.node, %struct.node* %5, i32 0, i32 3
  %6 = load %struct.node*, %struct.node** %brother4, align 8
  store %struct.node* %6, %struct.node** %auxBrother, align 8
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %7 = load %struct.node*, %struct.node** %newBrother.addr, align 8
  %8 = load %struct.node*, %struct.node** %auxBrother, align 8
  %brother5 = getelementptr inbounds %struct.node, %struct.node* %8, i32 0, i32 3
  store %struct.node* %7, %struct.node** %brother5, align 8
  br label %if.end

if.end:                                           ; preds = %while.end, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @addChild(%struct.node* %dad, %struct.node* %child) #0 {
entry:
  %dad.addr = alloca %struct.node*, align 8
  %child.addr = alloca %struct.node*, align 8
  store %struct.node* %dad, %struct.node** %dad.addr, align 8
  store %struct.node* %child, %struct.node** %child.addr, align 8
  %0 = load %struct.node*, %struct.node** %dad.addr, align 8
  %cmp = icmp ne %struct.node* %0, null
  br i1 %cmp, label %land.lhs.true, label %if.end

land.lhs.true:                                    ; preds = %entry
  %1 = load %struct.node*, %struct.node** %child.addr, align 8
  %cmp1 = icmp ne %struct.node* %1, null
  br i1 %cmp1, label %if.then, label %if.end

if.then:                                          ; preds = %land.lhs.true
  %2 = load %struct.node*, %struct.node** %child.addr, align 8
  %3 = load %struct.node*, %struct.node** %dad.addr, align 8
  %child2 = getelementptr inbounds %struct.node, %struct.node* %3, i32 0, i32 2
  store %struct.node* %2, %struct.node** %child2, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %land.lhs.true, %entry
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @printAST(%struct.node* %current, i32 %npontos) #0 {
entry:
  %current.addr = alloca %struct.node*, align 8
  %npontos.addr = alloca i32, align 4
  %i = alloca i32, align 4
  store %struct.node* %current, %struct.node** %current.addr, align 8
  store i32 %npontos, i32* %npontos.addr, align 4
  %0 = load %struct.node*, %struct.node** %current.addr, align 8
  %cmp = icmp ne %struct.node* %0, null
  br i1 %cmp, label %if.then, label %if.end47

if.then:                                          ; preds = %entry
  %1 = load %struct.node*, %struct.node** %current.addr, align 8
  %type = getelementptr inbounds %struct.node, %struct.node* %1, i32 0, i32 5
  %2 = load i8*, i8** %type, align 8
  %cmp1 = icmp ne i8* %2, null
  br i1 %cmp1, label %if.then2, label %if.end46

if.then2:                                         ; preds = %if.then
  %3 = load %struct.node*, %struct.node** %current.addr, align 8
  %type3 = getelementptr inbounds %struct.node, %struct.node* %3, i32 0, i32 5
  %4 = load i8*, i8** %type3, align 8
  %call = call i32 @strcmp(i8* %4, i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str, i32 0, i32 0))
  %cmp4 = icmp ne i32 %call, 0
  br i1 %cmp4, label %if.then5, label %if.else34

if.then5:                                         ; preds = %if.then2
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %if.then5
  %5 = load i32, i32* %i, align 4
  %6 = load i32, i32* %npontos.addr, align 4
  %cmp6 = icmp slt i32 %5, %6
  br i1 %cmp6, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %call7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.1, i32 0, i32 0))
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %7 = load i32, i32* %i, align 4
  %inc = add nsw i32 %7, 1
  store i32 %inc, i32* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  %8 = load %struct.node*, %struct.node** %current.addr, align 8
  %value = getelementptr inbounds %struct.node, %struct.node* %8, i32 0, i32 4
  %9 = load i8*, i8** %value, align 8
  %cmp8 = icmp ne i8* %9, null
  br i1 %cmp8, label %if.then9, label %if.else

if.then9:                                         ; preds = %for.end
  %10 = load %struct.node*, %struct.node** %current.addr, align 8
  %type10 = getelementptr inbounds %struct.node, %struct.node* %10, i32 0, i32 5
  %11 = load i8*, i8** %type10, align 8
  %12 = load %struct.node*, %struct.node** %current.addr, align 8
  %value11 = getelementptr inbounds %struct.node, %struct.node* %12, i32 0, i32 4
  %13 = load i8*, i8** %value11, align 8
  %call12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.2, i32 0, i32 0), i8* %11, i8* %13)
  br label %if.end

if.else:                                          ; preds = %for.end
  %14 = load %struct.node*, %struct.node** %current.addr, align 8
  %type13 = getelementptr inbounds %struct.node, %struct.node* %14, i32 0, i32 5
  %15 = load i8*, i8** %type13, align 8
  %call14 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.3, i32 0, i32 0), i8* %15)
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then9
  %16 = load %struct.node*, %struct.node** %current.addr, align 8
  %note = getelementptr inbounds %struct.node, %struct.node* %16, i32 0, i32 6
  %17 = load i8*, i8** %note, align 8
  %cmp15 = icmp ne i8* %17, null
  br i1 %cmp15, label %if.then16, label %if.end24

if.then16:                                        ; preds = %if.end
  %18 = load %struct.node*, %struct.node** %current.addr, align 8
  %note17 = getelementptr inbounds %struct.node, %struct.node* %18, i32 0, i32 6
  %19 = load i8*, i8** %note17, align 8
  %call18 = call i32 @strcmp(i8* %19, i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.4, i32 0, i32 0))
  %cmp19 = icmp ne i32 %call18, 0
  br i1 %cmp19, label %if.then20, label %if.end23

if.then20:                                        ; preds = %if.then16
  %20 = load %struct.node*, %struct.node** %current.addr, align 8
  %note21 = getelementptr inbounds %struct.node, %struct.node* %20, i32 0, i32 6
  %21 = load i8*, i8** %note21, align 8
  %call22 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.5, i32 0, i32 0), i8* %21)
  br label %if.end23

if.end23:                                         ; preds = %if.then20, %if.then16
  br label %if.end24

if.end24:                                         ; preds = %if.end23, %if.end
  %call25 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.6, i32 0, i32 0))
  %22 = load %struct.node*, %struct.node** %current.addr, align 8
  %child = getelementptr inbounds %struct.node, %struct.node* %22, i32 0, i32 2
  %23 = load %struct.node*, %struct.node** %child, align 8
  %cmp26 = icmp ne %struct.node* %23, null
  br i1 %cmp26, label %if.then27, label %if.end29

if.then27:                                        ; preds = %if.end24
  %24 = load %struct.node*, %struct.node** %current.addr, align 8
  %child28 = getelementptr inbounds %struct.node, %struct.node* %24, i32 0, i32 2
  %25 = load %struct.node*, %struct.node** %child28, align 8
  %26 = load i32, i32* %npontos.addr, align 4
  %add = add nsw i32 %26, 1
  call void @printAST(%struct.node* %25, i32 %add)
  br label %if.end29

if.end29:                                         ; preds = %if.then27, %if.end24
  %27 = load %struct.node*, %struct.node** %current.addr, align 8
  %brother = getelementptr inbounds %struct.node, %struct.node* %27, i32 0, i32 3
  %28 = load %struct.node*, %struct.node** %brother, align 8
  %cmp30 = icmp ne %struct.node* %28, null
  br i1 %cmp30, label %if.then31, label %if.end33

if.then31:                                        ; preds = %if.end29
  %29 = load %struct.node*, %struct.node** %current.addr, align 8
  %brother32 = getelementptr inbounds %struct.node, %struct.node* %29, i32 0, i32 3
  %30 = load %struct.node*, %struct.node** %brother32, align 8
  %31 = load i32, i32* %npontos.addr, align 4
  call void @printAST(%struct.node* %30, i32 %31)
  br label %if.end33

if.end33:                                         ; preds = %if.then31, %if.end29
  br label %if.end45

if.else34:                                        ; preds = %if.then2
  %32 = load %struct.node*, %struct.node** %current.addr, align 8
  %child35 = getelementptr inbounds %struct.node, %struct.node* %32, i32 0, i32 2
  %33 = load %struct.node*, %struct.node** %child35, align 8
  %cmp36 = icmp ne %struct.node* %33, null
  br i1 %cmp36, label %if.then37, label %if.end39

if.then37:                                        ; preds = %if.else34
  %34 = load %struct.node*, %struct.node** %current.addr, align 8
  %child38 = getelementptr inbounds %struct.node, %struct.node* %34, i32 0, i32 2
  %35 = load %struct.node*, %struct.node** %child38, align 8
  %36 = load i32, i32* %npontos.addr, align 4
  call void @printAST(%struct.node* %35, i32 %36)
  br label %if.end39

if.end39:                                         ; preds = %if.then37, %if.else34
  %37 = load %struct.node*, %struct.node** %current.addr, align 8
  %brother40 = getelementptr inbounds %struct.node, %struct.node* %37, i32 0, i32 3
  %38 = load %struct.node*, %struct.node** %brother40, align 8
  %cmp41 = icmp ne %struct.node* %38, null
  br i1 %cmp41, label %if.then42, label %if.end44

if.then42:                                        ; preds = %if.end39
  %39 = load %struct.node*, %struct.node** %current.addr, align 8
  %brother43 = getelementptr inbounds %struct.node, %struct.node* %39, i32 0, i32 3
  %40 = load %struct.node*, %struct.node** %brother43, align 8
  %41 = load i32, i32* %npontos.addr, align 4
  call void @printAST(%struct.node* %40, i32 %41)
  br label %if.end44

if.end44:                                         ; preds = %if.then42, %if.end39
  br label %if.end45

if.end45:                                         ; preds = %if.end44, %if.end33
  br label %if.end46

if.end46:                                         ; preds = %if.end45, %if.then
  br label %if.end47

if.end47:                                         ; preds = %if.end46, %entry
  ret void
}

declare i32 @strcmp(i8*, i8*) #1

declare i32 @printf(i8*, ...) #1

; Function Attrs: nounwind ssp uwtable
define void @deleteAst(%struct.node* %current) #0 {
entry:
  %current.addr = alloca %struct.node*, align 8
  store %struct.node* %current, %struct.node** %current.addr, align 8
  %0 = load %struct.node*, %struct.node** %current.addr, align 8
  %cmp = icmp eq %struct.node* %0, null
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.node*, %struct.node** %current.addr, align 8
  %type = getelementptr inbounds %struct.node, %struct.node* %1, i32 0, i32 5
  %2 = load i8*, i8** %type, align 8
  %tobool = icmp ne i8* %2, null
  br i1 %tobool, label %if.end4, label %if.then1

if.then1:                                         ; preds = %if.end
  %3 = load %struct.node*, %struct.node** %current.addr, align 8
  %type2 = getelementptr inbounds %struct.node, %struct.node* %3, i32 0, i32 5
  %4 = load i8*, i8** %type2, align 8
  call void @free(i8* %4)
  %5 = load %struct.node*, %struct.node** %current.addr, align 8
  %type3 = getelementptr inbounds %struct.node, %struct.node* %5, i32 0, i32 5
  store i8* null, i8** %type3, align 8
  br label %if.end4

if.end4:                                          ; preds = %if.then1, %if.end
  %6 = load %struct.node*, %struct.node** %current.addr, align 8
  %value = getelementptr inbounds %struct.node, %struct.node* %6, i32 0, i32 4
  %7 = load i8*, i8** %value, align 8
  %tobool5 = icmp ne i8* %7, null
  br i1 %tobool5, label %if.end9, label %if.then6

if.then6:                                         ; preds = %if.end4
  %8 = load %struct.node*, %struct.node** %current.addr, align 8
  %value7 = getelementptr inbounds %struct.node, %struct.node* %8, i32 0, i32 4
  %9 = load i8*, i8** %value7, align 8
  call void @free(i8* %9)
  %10 = load %struct.node*, %struct.node** %current.addr, align 8
  %value8 = getelementptr inbounds %struct.node, %struct.node* %10, i32 0, i32 4
  store i8* null, i8** %value8, align 8
  br label %if.end9

if.end9:                                          ; preds = %if.then6, %if.end4
  %11 = load %struct.node*, %struct.node** %current.addr, align 8
  %child = getelementptr inbounds %struct.node, %struct.node* %11, i32 0, i32 2
  %12 = load %struct.node*, %struct.node** %child, align 8
  call void @deleteAst(%struct.node* %12)
  %13 = load %struct.node*, %struct.node** %current.addr, align 8
  %child10 = getelementptr inbounds %struct.node, %struct.node* %13, i32 0, i32 2
  store %struct.node* null, %struct.node** %child10, align 8
  %14 = load %struct.node*, %struct.node** %current.addr, align 8
  %brother = getelementptr inbounds %struct.node, %struct.node* %14, i32 0, i32 3
  %15 = load %struct.node*, %struct.node** %brother, align 8
  call void @deleteAst(%struct.node* %15)
  %16 = load %struct.node*, %struct.node** %current.addr, align 8
  %brother11 = getelementptr inbounds %struct.node, %struct.node* %16, i32 0, i32 3
  store %struct.node* null, %struct.node** %brother11, align 8
  %17 = load %struct.node*, %struct.node** %current.addr, align 8
  %18 = bitcast %struct.node* %17 to i8*
  call void @free(i8* %18)
  store %struct.node* null, %struct.node** %current.addr, align 8
  br label %return

return:                                           ; preds = %if.end9, %if.then
  ret void
}

declare void @free(i8*) #1

attributes #0 = { nounwind ssp uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+cx16,+fxsr,+mmx,+sse,+sse2,+sse3,+ssse3" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"PIC Level", i32 2}
!1 = !{!"clang version 3.8.1 (tags/RELEASE_381/final)"}
