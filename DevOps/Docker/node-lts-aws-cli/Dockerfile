FROM node:lts-buster-slim


RUN apt-get update && apt-get install -y curl unzip && rm -rf /var/lib/apt/lists/*

# install aws-cli
RUN curl "https://awscli.amazonaws.com/awscli-exe-linux-x86_64.zip" -o "awscliv2.zip" \
  && unzip awscliv2.zip \
  && ./aws/install -i /usr/local/aws-cli -b /usr/local/bin \
  && rm -rf awscliv2.zip \
  && rm -rf aws
