FROM node:18.12-bullseye

WORKDIR /app

COPY ./software/userinterface/package.json /
COPY ./software/userinterface/package-lock.json /

RUN npm install
RUN CD ./software/userinterface/
COPY . .