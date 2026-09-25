#pragma once


class Field {

};


class GameLogic {
	Field field;

public:
	GameLogic() {};

	const Field& getField() const {
		return field;
	}

};

