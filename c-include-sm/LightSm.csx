#!/usr/bin/env dotnet-script
// If you have any questions about this file, check out https://github.com/StateSmith/tutorial-2
#r "nuget: StateSmith, 0.9.12-alpha"

using StateSmith.Runner;
SmRunner runner = new(diagramPath: "LightSm.drawio", transpilerId: TranspilerId.C99);
runner.Run();
