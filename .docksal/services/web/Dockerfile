ARG NGINX_VER

FROM wodby/nginx:${NGINX_VER}

ARG HOST_UID
ARG HOST_GID

USER root

RUN set -ex; \
    apk --no-cache add shadow; \
    usermod -u $HOST_UID wodby; \
    groupmod -g $HOST_GID wodby

USER wodby
