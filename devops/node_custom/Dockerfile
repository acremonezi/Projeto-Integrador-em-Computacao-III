FROM node:18.12-bullseye

WORKDIR /app

COPY ./software/userinterface/package.json /
COPY ./software/userinterface/package-lock.json /

RUN npm install
COPY . .

CMD [ "node", "./index.js" ]