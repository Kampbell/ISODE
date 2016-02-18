#ifndef	Echo_h_
#define Echo_h_

	enum class Mode {
		echo = 1,
		sink = 2
	};

	class Echo {
	protected:
		Mode		mode = Mode::echo;
	};

#endif