#pragma once
#include "Field.h"


class GameLogic {
	Field field;

public:
	GameLogic() {};

	const Field& getField() const {
		return field;
	}

};

