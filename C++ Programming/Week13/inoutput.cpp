/*
	11월 24일
	input/output: byte의 흐름(stream)
	- ostream: output stream
	- istream: input stream

	컴퓨터에서의 모든 길은 CPU로 통함
	즉 input, output는 CPU입장.(CPU로 들어오는 거시 input)

	숙대 지하철: 가까운듯 멀음
	셔틀버스를 이용함 -> 버퍼
	버퍼에 데이터가 꽉 차면 그때 움직임(한 개씩 하기에는 비효율)
	데이터를 모아서 input, output로 나감

	<<, >> 이를 operation 오버로딩을 통해서 자유로운 활용, 확장성을 허용

	[file]

*/