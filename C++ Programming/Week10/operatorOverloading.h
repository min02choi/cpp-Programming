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
		int getM() const;	// getM�� ��� ������ �ٲ��� �ʴ´ٴ� ����
		Sample operator+(Sample& a);	// �� �ڽ��� �⺻(����Ʈ), �ϳ����� �� �䱸
		friend Sample operator-(const Sample& a, const Sample& b);

};

/*
	friend�ڿ� ������ function�� ��� function�� �ƴ�. ���� ����Ʈ �� �ڽ��� ���� ������ �Ű����� �ΰ� �䱸
*/