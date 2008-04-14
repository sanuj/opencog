/*
 * FUNCTION:
 * Base classe for SQL-backed persistent storage.
 *
 * HISTORY:
 * Copyright (c) 2008 Linas Vepstas <linas@linas.org>
 */

#ifndef PERSITENT_ATOM_STORAGE_H_
#define PERSITENT_ATOM_STORAGE_H_

#include "odbcxx.h"

#include <map>

#include "Atom.h"

class AtomStorage
{
	private:
		ODBCConnection *db_conn;

		// Utility for handling responses on stack.
		class Response;

		// Set of atoms that we know about.
		std::map<Handle,Atom *> handle_map;

		void storeOutgoing(Atom *, Handle);

	public:
		AtomStorage(void);
		~AtomStorage();

		void storeAtom(Atom *);
		bool atomExists(Handle);
		Atom * getAtom(Handle);
};

#endif /* PERSITENT_ATOM_STORAGE_H_ */

