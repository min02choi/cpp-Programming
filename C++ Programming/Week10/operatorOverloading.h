class Negative { };

class Sample {
	private:
		int n;
		int m;
		void setM(int x, int y);
	public:
		Sample();
		Sample(int x);
		Sample(const Sample& a);
		~Sample();
		void setM(int x);
		int getM() const;	// getM은 멤버 변수를 바꾸지 않는다는 선서
		Sample operator+(Sample& a);	// 나 자신이 기본(디폴트), 하나만을 더 요구
		friend Sample operator-(const Sample& a, const Sample& b);

};

/*
	friend뒤에 정의한 function은 멤버 function이 아님. 따라서 디폴트 나 자신이 없기 때문에 매개변수 두개 요구
*/