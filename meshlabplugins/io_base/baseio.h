/****************************************************************************
* MeshLab                                                           o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2005                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/
#ifndef BASEIOPLUGIN_H
#define BASEIOPLUGIN_H

#include <common/interfaces.h>

class BaseMeshIOPlugin : public QObject, public MeshIOInterface
{
	Q_OBJECT
		MESHLAB_PLUGIN_IID_EXPORTER(MESH_IO_INTERFACE_IID)
		Q_INTERFACES(MeshIOInterface)


public:

	BaseMeshIOPlugin() : MeshIOInterface() {}

	QList<Format> importFormats() const;
	QList<Format> exportFormats() const;

	void GetExportMaskCapability(QString &format, int &capability, int &defaultBits) const;

	bool open(const QString &formatName, const QString &fileName, MeshModel &m, int& mask, const RichParameterSet & par, vcg::CallBackPos *cb = 0, QWidget *parent = 0);
	bool save(const QString &formatName, const QString &fileName, MeshModel &m, const int mask, const RichParameterSet & par, vcg::CallBackPos *cb = 0, QWidget *parent = 0);
	//void initOpenParameter(const QString &format, MeshModel &/*m*/, RichParameterSet & par);
	//void applyOpenParameter(const QString &format, MeshModel &m, const RichParameterSet &par);
	void initPreOpenParameter(const QString &formatName, const QString &filename, RichParameterSet &parlst);
	void initSaveParameter(const QString &format, MeshModel &/*m*/, RichParameterSet & par);

	void initGlobalParameterSet(QAction * /*format*/, RichParameterSet & /*globalparam*/);
private:
	static QString stlUnifyParName() { return QString("MeshLab::IO::STL::UnifyVertices"); }
};

#endif
