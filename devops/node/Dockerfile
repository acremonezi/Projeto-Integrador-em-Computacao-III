FROM node:18.12-bullseye as base

WORKDIR /src
COPY ../../software/userinterface/package.json /
EXPOSE 8080

FROM base as production
ENV NODE_ENV=production
RUN npm install -g nodemon && npm install
RUN npm ci
COPY . /
CMD ["node", "bin/www"]