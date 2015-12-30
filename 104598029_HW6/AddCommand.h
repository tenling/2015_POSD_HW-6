/*
 * AddCommand.h
 *
 *  Created on: 2009/11/29
 *      Author: zwshen
 */

#ifndef ADDCOMMAND_H_
#define ADDCOMMAND_H_

#include "Command.h"
#include "Model.h"
#include "Shape.h"

class AddCommand : public Command {
private:
	Model* model;
	//Shape::ShapeType m_type;
public:
//	AddCommand(Model* m, Shape::ShapeType type);
	virtual ~AddCommand();
	void execute();
	void unexecute();
};

#endif /* ADDCOMMAND_H_ */
