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
		int getM();
		int getM() const;	// getM은 멤버 변수를 바꾸지 않는다는 선서

};
