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
		int getM() const;	// getM�� ��� ������ �ٲ��� �ʴ´ٴ� ����

};
