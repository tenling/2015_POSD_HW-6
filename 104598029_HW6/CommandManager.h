/*
 * History.h
 *
 *  Created on: 2009/11/29
 *      Author: zwshen
 */

#ifndef HISTORY_H_
#define HISTORY_H_

#include "Command.h"
#include <stack>

using namespace std;

class CommandManager {
private:
	stack<Command*> m_undoCmds;
	stack<Command*> m_redoCmds;
public:
	CommandManager();
	~CommandManager();
	void execute(Command* c);
	void redo();
	void undo();
};

#endif /* HISTORY_H_ */
