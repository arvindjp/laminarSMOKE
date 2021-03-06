/*-----------------------------------------------------------------------*\
|                                                                         |
|                    ╔═══╦═╗╔═╦═══╦╗╔═╦═══╗                               |
|                    ║╔═╗║║╚╝║║╔═╗║║║╔╣╔══╝                               | 
|   ╔╗╔══╦╗╔╦╦═╗╔══╦═╣╚══╣╔╗╔╗║║ ║║╚╝╝║╚══╗                               |
|   ║║║╔╗║╚╝╠╣╔╗╣╔╗║╔╩══╗║║║║║║║ ║║╔╗║║╔══╝                               |
|   ║╚╣╔╗║║║║║║║║╔╗║║║╚═╝║║║║║║╚═╝║║║╚╣╚══╗                               |
|   ╚═╩╝╚╩╩╩╩╩╝╚╩╝╚╩╝╚═══╩╝╚╝╚╩═══╩╝╚═╩═══╝                               |
|                                                                         |
|                                                                         |
|   Authors: A. Cuoci                                                     |
|                                                                         |
|   Contacts: Alberto Cuoci                                               |
|   email: alberto.cuoci@polimi.it                                        |
|   Department of Chemistry, Materials and Chemical Engineering           |
|   Politecnico di Milano                                                 |
|   P.zza Leonardo da Vinci 32, 20133 Milano (Italy)                      |
|                                                                         |
|-------------------------------------------------------------------------|
|                                                                         |
|   This file is part of laminarSMOKE solver.                             |
|                                                                         |
|   License                                                               |
|                                                                         |
|   Copyright(C) 2016, 2015, 2014 A. Cuoci                                |
|   laminarSMOKE is free software: you can redistribute it and/or modify  |
|   it under the terms of the GNU General Public License as published by  |
|   the Free Software Foundation, either version 3 of the License, or     |
|   (at your option) any later version.                                   |
|                                                                         |
|   laminarSMOKE is distributed in the hope that it will be useful,       |
|   but WITHOUT ANY WARRANTY; without even the implied warranty of        |
|   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         |
|   GNU General Public License for more details.                          |
|                                                                         |
|   You should have received a copy of the GNU General Public License     |
|   along with laminarSMOKE. If not, see <http://www.gnu.org/licenses/>.  |
|                                                                         |
|                                                                         |
|   Application: laminarSimpleSMOKE                                       |
|                                                                         |
|   Description: steady solver for reactive flows with detailed kinetic   |
|                mechanisms.                                              |
|                                                                         |
\*-----------------------------------------------------------------------*/

// This is a steady state simulation
#define STEADYSTATE 1

// OpenSMOKE++ Definitions
#include "OpenSMOKEpp"

// CHEMKIN maps
#include "maps/Maps_CHEMKIN"
#include "utilities/soot/polimi/OpenSMOKE_PolimiSoot_Analyzer.h"

// OpenSMOKE++ Dictionaries
#include "dictionary/OpenSMOKE_Dictionary"

// OpenFOAM
#include "fvCFD.H"
#include "multivariateScheme.H"
#include "simpleControl.H"
#include "interpolation.H"
#if OPENFOAM_VERSION >= 40
	#if DEVVERSION == 1
		#include "pressureControl.H"
	#endif
	#include "fvOptions.H"
#else
	#include "fvIOoptionList.H"
#endif

// Customized radiation model
#include "OpenSMOKEradiationModel.H"

// Additional include files
#include "sparkModel.H"
#include "utilities.H"
#include "laminarSMOKEthermoClass.H"

// Linearization
#include "linearModel.H"

// Soot
#include "sootUtilities.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
	#if OPENFOAM_VERSION >= 40
		#include "laminarSimpleSMOKE.4x.H"
	#elif OPENFOAM_VERSION == 30
		#include "laminarSimpleSMOKE.3x.H"
	#else
		#include "laminarSimpleSMOKE.2x.H"
	#endif
}


// ************************************************************************* //
