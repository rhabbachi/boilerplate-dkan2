ARG PHP_VER

FROM wodby/drupal-php:${PHP_VER}

ARG HOST_UID
ARG HOST_GID

# Install additional deps:
# - shadow: usermod and groupmod
# - npm: Build DKAN Gatsby frontend.
# - autoconf, util-linux: npm packages optional deps.
USER root
RUN set -ex; \
    apk --no-cache add shadow npm autoconf util-linux; \
    usermod -u $HOST_UID wodby; \
    groupmod -g $HOST_GID wodby

USER wodby

RUN set -e; \
    # We only need the last code revision to use dktl.
    git clone --depth=1 https://github.com/GetDKAN/dkan-tools.git ~/.dktl; \
    echo 'export PATH="$PATH:/home/wodby/.dktl/bin"' >> /home/wodby/.bash_profile; \
    # Install dktl dependencies.
    cd ~/.dktl/; composer install
