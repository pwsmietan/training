#!/bin/bash
set -x
docker run --name "MSSQL" \
	-e 'ACCEPT_EULA=Y' \
	-e 'SA_PASSWORD=NCC1701a' \
	-e 'MSSQL_PID=Enterprise' \
	-v /home/ctech/MSSQL/data:/var/opt/mssql/data \
	-v /home/ctech/MSSQL/log:/var/opt/mssql/log \
	-p 1433:1433 \
	--restart always \
	-d mcr.microsoft.com/mssql/server:latest
//EOJ//EOJ//EOJ//EOJ//EOJ//EOJ//EOJ//EOJ//EOJ//EOJ