t=0
while true; do
	let t++
	echo $t	
	echo $t|./rand>data.in
	printf "test\n"
	time ./test<data.in>test.out
	printf "std\n"
	time ./std<data.in>std.out
	if diff std.out test.out; then
	printf "AC\n"
	else
		printf "WA\n"
		exit 0
	fi
done

