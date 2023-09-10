> **_NOTE:_**  
Getting Started with Docker - [Video workshop](https://youtu.be/gAGEar5HQoU)  
Creating a container from scratch - [Liz Rice's talk](https://youtu.be/8fi7uSYlOdc)

# Part 1: Overview - [Link](https://docs.docker.com/get-started/)

## What is a container?

A container is a sandboxed process running on a host machine that is isolated from all other processes running on that host machine. The isolation leverages kernel namespaces and cgroups, features that have in Linux for a long time. Docker makes these capabilities approachable and easy to use.  
To summarize, a container:
- is a runnable instance of an image
- that you can create, start, stop, move, or delete using the Docker API or CLI
- can be run on local machines, virtual machines, or deployed to the cloud
- is portable, and be run on any OS
- is isolated from other containers and runs its own software, binaries, configurations, etc.

## What is an image?

A running container uses an isolated filesystem. The isolated filesystem is provided by an image, and the image must contain everything needed to run an application - all dependencies, configurations, scripts, binaries, etc.  
The image also contains other configuraitons for teh container, such as environment variables, a dfeault command to run, and other metadata.


# Part 2: Containerize an application - [Link](https://docs.docker.com/get-started/02_our_app/)

In Linux, to use `docker` without having to typed `sudo`
``` bash
$ sudo usermod -aG docker $USER     # add current user to the docker group

# Clone the example repo
$ git clone https://github.com/docker/getting-started-app.git

# Create the Dockerfile for the app build instruction
$ cd /path/to/getting-started-app
$ vi Dockerfile
```

`Dockerfile`'s content:
``` bash
# syntax=docker/dockerfile:1

FROM node:18-alpine     # start from alpine as a base
WORKDIR /app
COPY . .
RUN yarn install --production       # copied in the application and used yarn to isntall dependencies
CMD ["node", "src/index.js"]        # specifies the default command to run when starting a container from the image
EXPOSE 3000
```

## Build the image

``` bash
$ docker build -t getting-started .
```
Explaination
- `docker build` uses the `Dockerfile` to build a new image
- `-t` flag tags the image with the name *getting-started*, this name can be refered to when you run a container
- `.` tells Docker that it should look for the `Dockerfile` in the current directory


## Start an app container

``` bash
$ docker run -dp 127.0.0.1:3000:3000 getting-started
```
Explaination
- `-d` flag for `--detach` runs the container in the background
- `-p` flag for `--public` creats a port mapping between the host and the container in the format of `HOST:CONTAINER`; where `HOST` is the address on the host, and `CONTAINER` is the port on the container. So this publishes the container's port 3000 to `127.0.0.1:3000`(`localhost:3000`) on the host. Without mapping, you won't be able to access the application from the host.

To list running container:
``` bash
$ docker ps
```


# Part 3: Update the application - [Link](https://docs.docker.com/get-started/03_updating_app/)

Making changes to the codebase/app requires rebuilding the docker image and run another instance to have the updated service.
``` bash
$ docker ps
$ docker stop <container_id>    # or docker rm <container_id>
# In the app directory, with Dockerfile presents
$ docker build -t <image_name> .
$ docker run -dp 127.0.0.1:<host_port>:<container_port> <image_name>
```

## Related information

- [Dockerfile reference](./docker_dockerfile.md)
- [docker CLI reference](https://docs.docker.com/engine/reference/commandline/cli/)
- [Build with Docker guide](https://docs.docker.com/build/guide/)


# Part 4: Share the application - [Link](https://docs.docker.com/get-started/04_sharing_app/)

## Push the image to a registry (Docker Hub)

``` bash
# Sign up/in to Docker Hub
$ docker login -u <dockerhub_username>
$ docker tag <image_name> <dockerhub_username>/<repo_name>
$ docker push <dockerhub_username>/<repo_name>
```

## Run the image on a new instance/machine

It's possible to build an image for a different platform with `--platform` tag, or even an image for *multi-platform*.
``` bash
$ docker build --platform linux/arm64 -t <username>/<repo>
```

Pull and run the image
``` bash
$ docker run -dp 0.0.0.0:3000:3000 <username>/<repo>
```
> **_NOTE:_** `$ docker run -dp 0.0.0.0:<host_port>:<container_port> <dockerhub_username>/<repo_name>`
`0.0.0.0` exposes the container's port on all interfaces of the host, making it available to the outside world.

## Related information

- [docker CLI reference](https://docs.docker.com/engine/reference/commandline/cli/)
- [Multi-platform images](https://docs.docker.com/build/building/multi-platform/)
- [Docker Hub overview](https://docs.docker.com/docker-hub/)


# Part 5: Persist the DB - [Link](https://docs.docker.com/get-started/05_persisting_data/)

## The container's filesystem

When a container runs, it uses the various layers from an image for its filesystem. Each container also gets its own "scratch spcae" to create/update/remove files. Any changes won't be seen in another container, even if they're using the same image.

``` bash
$ docker run -d ubuntu bash -c "shuf -i 1-10000 -n 1 -o /data.txt && tail -f /dev/null"
```
runs a detached ubuntu instance, and execute in bash the `-c` command(s), `tail -f` is keeping the instance from idle

``` bash
$ docker exec <container_id> cat /data.txt
$ docker run -it ubuntu ls /    # start a new instance and check if data.txt 's present
$ docker rm -f <container_id>
```

## Container volumes

Volumes provide the ability to connect specific filesystem paths of the container back to the host machine. If you monut a directory in the container, changes in that diretory are also seen on the host machine. If you mount the same directory across container restarts, you'd see the same files.

## Persist the todo data

The todo app stores its data in a SQLite database at `/etc/todos/todo.db` in the container's filesystem. SQLite is mostly for small demos and store everything in a single file (?).

It helps in this case since you can just persist one file on the host and make it available to the next container, and pick up where the list is left off. By creating a volume and attaching/mounting it to the directory where you stored the data, you can persist the data. Docker fully manages this volume, including the storage location on disk. You only need to remember the name of the volume.

### Create a volume and start the container

``` bash
$ docker volume create <volume_name>
$ docker rm -f <container_id>       # to reboot the app later
$ docker run -dp 127.0.0.1:3000:3000 --mount type=volume,src=<volume_name>,target=/etc/todos <image_name>
```
> **_NOTE:_** `--mount` specifies a volume mount, having `type`, `src` being the volume that got created by `docker volume create`, and `target` being the path in the container.

``` bash
$ docker volume inspect <volume_name>
```

## Related information

- [Volumes](https://docs.docker.com/storage/volumes/)


# Part 6: Use bind mounts - [Link](https://docs.docker.com/get-started/06_bind_mounts/)

A bind mounts is another type of mount, which lets you share a directory from the host's filesystem into the container. When wokring on an application, you can use a bind mount to mount source code into the container. The contaienr sees the changes you make to code immediately, as soon as you save a file. This means that you can run processes in the container that watch for filesystem changes and respond to them.

Using bind mounts and a tool called [nodemon](https://npmjs.com/package/nodemon) to watch for file changes, and then restart the application automatically.

## Comparison between *volume* and *bind*
|       |Named volumes      |Bind mounts|
|-------|------------------|------------|
|Host location |Docker chooses |You decide |
|`--mount` example | `type=volume,src=<volume_name>,target=/path/in/container` |`type=bind,src=/path/to/data,target=/location/in/container` |
|Populates new volume with container contents |Yes |No |
|Supports volume drivers |Yes | No |

## Trying out bind mounts
``` bash
$ docker run -it --mount type=bind,src="$(pwd)",target=/src ubuntu bash
```
Explaination:
- using `bind` mount, using the current directory as `src`, `target`/mounting to the `/src` on the container
- after which, Docker starts an interactive `bash` session in the root directory `/` of the container's filesystem, which being `ubuntu`
``` bash
$ docker run -it ubuntu bash
```

Content of the `/src` on the container is the same as on the `/path/to/data` on the host, any change on either host or container will be made on the others, syncing any differences.

## Development containers

Using bind mounts is common for local development setups. The advantage is that the development machine doesn't need to have all of the build tools and environments installed. With a single `docker run` cmd, Docker pulls dependencies and tools.

### Run your app in a development container

- Mount your source code into the container
- Install all dependencies
- Start `nodemon` to watch  for filesystem changes

``` bash
# Make sure you don't have any getting-started contaienrs running
$ docker run -dp 127.0.0.1:3000:3000 \
    -w /app --mount type=bind,src="$(pwd)",target=/app \
    node:18-alpine \
    sh -c "yarn install && yarn run dev"
```
Explaination:
- `-dp 127.0.0.1:3000:3000` - run in detached mode and create a port mapping
- `-w /app` - sets the "working directory" or current directory that the command will run fom
- `--mount type=bind,src="$(pwd)",target=/app` - bind mount the current directory from the host with the `/app` directory in the container
- `node:18-alpine` - the image to use, this is the base image for your app from the `Dockerfile`
- `sh -c "yarn install && yarn run dev"` - the command, starting a shell using `sh` (alpine doesn't have `bash`) and running `yarn install` to isntall packages and then running `yarn run dev` to start the development server. In the `package.json`, the `dev` script starts `nodemon`.

To watch the log:
``` bash
$ docker logs <container_id>     # exit with Ctrl-c
```

## Related information

- [Manage data in Docker](https://docs.docker.com/storage/)
- [docker logs](https://docs.docker.com/engine/reference/commandline/logs/)


# Part 7: Multi-container apps - [Link](https://docs.docker.com/get-started/07_multi_container/)

We will replace SQLite with MySQL so the app can be more flexible and better scalable. Doing so requires a separate container for the database. Overall, each container should do one thing and do it well. Reason beings:
- Scaling APIs and front-ends differently than databases
- Separation let you version and update verisons in isolation
- You may want to use managed service for the database in production. So with this you don't have to ship your app with the database engine.
- Running multiple processes will require a process manager (the container only starts one process), which adds complexity to container startup/shutdown.

## Container networking

By default, container runs in isolation and don't know anything about other processes or containers on the same machine. So to allow one container to talk to another, you need *networking*, can be by placing the two on the same network, or create a route etc.

## Start MySQL

Two ways to put a container on a network:
- assign the network when starting the container
- connect an already running container to a network

### Create and attach to a network

``` bash
$ docker network create todo-app
$ docker run -d \
    --network todo-app --network-alias mysql \
    -v todo-mysql-data:/var/lib/mysql1 \
    -e MYSQL_ROOT_PASSWORD=secret \
    -e MYSQL_DATABASE=todos \
    mysql:8.0
```
Explaination:
- `--network` - to attach a container to the network, and having a `--network-alias`, which defining the hostname for the container
- `-v <volume_name>:/path/on/container` - where the MySQL stores its data, eventhough the volume wasn't created with `docker volume create` before, Docker will notice you want to use and create it automatically.
- there's a few *environment variables* is defined for MySQL to initialize the database, to learn more [MySQL Docker Hub listing](https://hub.docker.com/_/mysql/)

To confirm the database is up and running
``` bash
$ docker exec -it <mysql_container_id> mysql -u root -p     # will be ask for password, which is "secret" from above
```

## Connect to MySQL

While the container for MySQL is there, how do you use it, connect to it? Answer: each container has its own IP address.

For networking, you can make use of [nicolaka/netshoot](https://github.com/nicolaka/netshoot) container, which ships with a lot of tools that are useful for troubleshooting or debugging networking issues.

``` bash
$ docker run -it --network todo-app nicolaka/netshoot   # boot up and connect netshoot to the same todo-app network
<netshoot_hostname> <gibberish>$ dig mysql
```

You will get:
``` txt
; <<>> DiG 9.18.13 <<>> mysql
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 30611
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 0

;; QUESTION SECTION:
;mysql.             IN  A

;; ANSWER SECTION:
mysql.          600 IN  A   172.18.0.2

;; Query time: 0 msec
;; SERVER: 127.0.0.11#53(127.0.0.11) (UDP)
;; WHEN: Sun Sep 10 10:52:14 UTC 2023
;; MSG SIZE  rcvd: 44
```
So `dig` managed to resolve `mysql` (this hostname is from the `--network-alias`) to `172.18.0.2`.

## Run your app with MySQL

The todo app supports the setting of a few environment variables to specify MySQL connection settings. They are:
- `MYSQL_HOST` - the hostname for the running MySQL server
- `MYSQL_USER` - the username to use for the connection
- `MYSQL_PASSWORD` - the password to use for the connect
- `MYSQL_DB` - the database to use once connected

> **_NOTE:_** While using *env vars* to set connection settings is generally accepted for development, it's highly discoraged when running application in production. Diogo Monica, a former lead of security at Docker, [wrote a blog post](https://diogomonica.com/2017/03/27/why-you-shouldnt-use-env-variables-for-secret-data/) explanining why.  
A more secure mechanism is to use the secret support provided by your container orchestration framework. In most cases, these secrets are mounted as files in the running container. You'll see many apps (including the MySQL image and the todo app) also support env vars with a `_FILE` suffix to point to a file containing the variable.  
As an example, setting the `MYSQL_PASSWORD_FILE` var will cause the app to use the contents of the referenced file as the connection password. Docker doesn't do anything to support these env vars. Your app will need to know to look for the variable and get the file contents.

``` bash
# To be run in the getting-started-app dir
$ docker run -dp 127.0.0.1:3000:3000 \
    -w /app -v "$(pwd):/app" \
    --network todo-app \
    -e MYSQL_HOST=mysql \
    -e MYSQL_USER=root \
    -e MYSQL_PASSWORD=secret \
    -e MYSQL_DB=todos \
    node:18-alpine \
    sh -c "yarn install && yarn run dev"
```
Explaination:
- `-w` set working directory, `-v` set where MySQL stores its data
- `-e` set environment variable

Checking MySQL if the items are there in the database:
``` bash
$ docker exec -it <mysql_container_id> mysql -p todos
mysql> select * from todo_items;
```

## Related information

- [Networking overview](https://docs.docker.com/network/)


# Part 8: Use Docker Compose - [Link](https://docs.docker.com/get-started/08_using_compose/)

It can be overwhelmed with everything you need to do when start up an application. You have to create a network, start containers, specify all of the environment variables, expose ports, and more. That's a lot to remember and it's certainly making things harder to pass along to someone else. Here's come the `docker compose`.  
[Docker Compose](https://docs.docker.com/compose/) is a tool that helps you define and share multi-container applications. With `compose`, you can create a YAML file to define the services and with a single command, you can spin everything up or tear it all down.

The big advantage of using Compose is you can define your application stack in a file, keep it at the root of your project repository (it's now version controlled), and easily enable someone else to contribute to your project. Someone would only need to clone your repository and start the app using Compose.

## Define the app service - [Link](https://docs.docker.com/get-started/08_using_compose/#define-the-app-service)

Now instead of the code block in [Run your app with MySQL](#run-your-app-with-mysql) to start the database service:
``` bash
# To be run in the getting-started-app dir
$ docker run -dp 127.0.0.1:3000:3000 \
    -w /app -v "$(pwd):/app" \
    --network todo-app \
    -e MYSQL_HOST=mysql \
    -e MYSQL_USER=root \
    -e MYSQL_PASSWORD=secret \
    -e MYSQL_DB=todos \
    node:18-alpine \
    sh -c "yarn install && yarn run dev"
```
VS, you will now define this service in the `compose.yaml` file:
``` yaml
services:
  app:
    image: node:18-alpine
    command: sh - c "yarn install && yarn run dev"
    ports:
      - 127.0.0.1:3000:3000
    working_dir: /app
    volumes:
      - ./:/app
    environment:
      MYSQL_HOST: mysql
      MYSQL_USER: root
      MYSQL_PASSWORD: secret
      MYSQL_DB: todos
```

## Define the MySQL service - [Link](https://docs.docker.com/get-started/08_using_compose/#define-the-mysql-service)

CLI:
``` bash
$ docker run -d \
    --network todo-app --network-alias mysql \
    -v todo-mysql-data:/var/lib/mysql1 \
    -e MYSQL_ROOT_PASSWORD=secret \
    -e MYSQL_DATABASE=todos \
    mysql:8.0
```
VS, appending to the `comepose.yaml`:
``` yaml
services:
  app:
    # the app service definition
  mysql:
    image: mysql:8.0
    volumes:
      - todo-mysql-data:/var/lib/mysql
    environment:
      MYSQL_ROOT_PASSWORD: secret
      MYSQL_DATABASE: todos

volumes:
  todo-mysql-data:
```

The complete `compose.yaml`:
``` yaml
services:
  app:
    image: node:18-alpine
    command: sh -c "yarn install && yarn run dev"
    ports:
      - 127.0.0.1:3000:3000
    working_dir: /app
    volumes:
      - ./:/app
    environment:
      MYSQL_HOST: mysql
      MYSQL_USER: root
      MYSQL_PASSWORD: secret
      MYSQL_DB: todos

  mysql:
    image: mysql:8.0
    volumes:
      - todo-mysql-data:/var/lib/mysql
    environment:
      MYSQL_ROOT_PASSWORD: secret
      MYSQL_DATABASE: todos

volumes:
  todo-mysql-data:
```
> **_NOTE:_** When you ran the container with `docker run`, Docker created the named volume automatically. However, that doesn't happen when running with Compose. You need to define the volume in the top-level `volumes:` section and then specify the mountpoint in the service config. By simply providing the volume name `todo-mysql-data:`, the defaults options are used

## Run the application stack

Now using with `compose.yaml`:
``` bash
$ docker compose up -d      # or without -d to see log for troubleshoot

[root@archow getting-started-app]# docker compose up -d
[+] Running 4/4
 ✔ Network getting-started-app_default           Created        0.5s
 ✔ Volume "getting-started-app_todo-mysql-data"  Created        0.2s
 ✔ Container getting-started-app-mysql-1         Started        1.4s
 ✔ Container getting-started-app-app-1           Started        1.2s
```
> **_NOTE:_** Docker Compose automatically creates a network specifically for the application stack.

> **_WARNING:_** There's a problem when booting up both containers, since the machine is slow, timeout of app container ran out before the mysql container could be booted up. Solution: [docker/getting-started #351](https://github.com/docker/getting-started/issues/351)  
So the app starts and waits for MySQL to be up and ready before trying to connect to it. Docker doesn't have any built-in support to wait for another container to be fully up, running and ready before starting another container.

## Tear it all down
``` bash
$ docker compose down
```
> **_NOTE:_** By default, named volumes in your compose file are not removed. You need to add `--volumes` flag. The Docker Dashboard does not remove volumes when you delete the app stack.

## Related information

- [Compose overview](https://docs.docker.com/compose/)
- [Compose file reference](https://docs.docker.com/compose/compose-file/)
- [Compose CLI reference](https://docs.docker.com/compose/reference/)


# Part 9: Image-building best practices - [Link](https://docs.docker.com/get-started/09_image_best/)

## Image layering

Seeing the command that was used to create each layer within an image:
``` bash
$ docker image history <image_name>

[root@archow getting-started-app]# docker image history getting-started
IMAGE          CREATED        CREATED BY                                      SIZE      COMMENT
9f85008495e3   22 hours ago   EXPOSE map[3000/tcp:{}]                         0B        buildkit.dockerfile.v0
<missing>      22 hours ago   CMD ["node" "src/index.js"]                     0B        buildkit.dockerfile.v0
<missing>      22 hours ago   RUN /bin/sh -c yarn install --production # b…   85.3MB    buildkit.dockerfile.v0
<missing>      22 hours ago   COPY . . # buildkit                             6.44MB    buildkit.dockerfile.v0
<missing>      24 hours ago   WORKDIR /app                                    0B        buildkit.dockerfile.v0
<missing>      4 weeks ago    /bin/sh -c #(nop)  CMD ["node"]                 0B
<missing>      4 weeks ago    /bin/sh -c #(nop)  ENTRYPOINT ["docker-entry…   0B
<missing>      4 weeks ago    /bin/sh -c #(nop) COPY file:4d192565a7220e13…   388B
<missing>      4 weeks ago    /bin/sh -c apk add --no-cache --virtual .bui…   7.77MB
<missing>      4 weeks ago    /bin/sh -c #(nop)  ENV YARN_VERSION=1.22.19     0B
<missing>      4 weeks ago    /bin/sh -c addgroup -g 1000 node     && addu…   161MB
<missing>      4 weeks ago    /bin/sh -c #(nop)  ENV NODE_VERSION=18.17.1     0B
<missing>      4 weeks ago    /bin/sh -c #(nop)  CMD ["/bin/sh"]              0B
<missing>      4 weeks ago    /bin/sh -c #(nop) ADD file:32ff5e7a78b890996…   7.33MB
```
> **_NOTE:_** Each of the lines represents a layer in the image. The display shows the base at the bottom with the newest layer at the top. Helping in seeing the size of each layer, diagnose large images.

``` bash
$ docker image history --no-trunc <image_name>      # full output
```

## Layer caching

Important lesson to learn to help decrease build times for images: Once a layer changes, all downstream layers have to be recreated as well.

The `Dockerfile` that you created from way before:
``` bash
# syntax=docker/dockerfile:1
FROM node:18-alpine
WORKDIR /app
COPY . .
RUN yarn install --production
CMD ["node", "src/index.js"]
```
Each command in the `Dockerfile` becomes a new layer in the image. You might remember that when you made a change to the image, the `yarn` dependencies had to be reinstalled. It doesn't make sense to ship around the same dependencies every time you build.

To fix it, you need to reconstructure your `Dockerfile` to help support the caching of the dependencies.  
For Node-based applications, those dependencies are defined in the `package.json` file. You can copy only that file in first, install the dependencies, and then copy in everything else. Then, you only recreate the yarn dependencies if there was a change to the `package.json`.
``` bash
# syntax=docker/dockerfile:1
FROM node:18-alpine
WORKDIR /app
COPY package.json yarn.lock ./      # copy in first
RUN yarn install --production       # install the dependencies
COPY . .                            # copy in everything else
CMD ["node", "src/index.js"]

$ echo node_modules > .dockerignore
$ docker build -t getting-started .

[root@archow getting-started-app]# docker build -t getting-started .
[+] Building 4.0s (12/12) FINISHED                                                                                                  docker:default
 => [internal] load .dockerignore                                                                                                   0.3s
 => => transferring context: 53B                                                                                                    0.0s
 => [internal] load build definition from Dockerfile                                                                                0.4s
 => => transferring dockerfile: 213B                                                                                                0.0s
 => resolve image config for docker.io/docker/dockerfile:1                                                                          1.3s
 => CACHED docker-image://docker.io/docker/dockerfile:1@sha256:ac85f380a63b13dfcefa89046420e1781752bab202122f8f50032edf31be0021     0.0s
 => [internal] load metadata for docker.io/library/node:18-alpine                                                                   0.0s
 => [internal] load build context                                                                                                   0.2s
 => => transferring context: 4.57kB                                                                                                 0.0s
 => [1/5] FROM docker.io/library/node:18-alpine                                                                                     0.0s
 => CACHED [2/5] WORKDIR /app                                                                                                       0.0s
 => CACHED [3/5] COPY package.json yarn.lock ./                                                                                     0.0s
 => CACHED [4/5] RUN yarn install --production                                                                                      0.0s
 => CACHED [5/5] COPY . .                                                                                                           0.0s
 => exporting to image                                                                                                              0.1s
 => => exporting layers                                                                                                             0.0s
 => => writing image sha256:5f93083c0d7ce57753c25f5afc9ef4b4e425dfe1e12dc16eeaa1aa57d04e0e7a                                        0.0s
 => => naming to docker.io/library/getting-started                                                                                  0.0s
```
> **_NOTE:_** `.dockerignore` files are an easy way to selectively copy only image relevant files. For more [details](https://docs.docker.com/engine/reference/builder/#dockerignore-file).  
In this case, the `node_modules` folder should be omitted in the second `COPY` step because otherwise, it would possibly overwrite files which were created by the command in the `RUN` step. For more deatails on [Dockerizing a Node.js web app](https://nodejs.org/en/docs/guides/nodejs-docker-webapp/).

## Multi-stage builds - [Link](https://docs.docker.com/get-started/09_image_best/#multi-stage-builds)

Powerful tool to help use multiple tages to create an image. Some advantages being:
- separate build-time dependencies from runtime dependencies
- reduce overall image size by shipping only what your app needs to run

Depending on the app's tech stack. For example: java - maven or gradle, react - if not doing server-side rendering then you don't need a Node enrionment for your production build just ship the static resources in a static nginx container, etc.

## Related information

- [.dockerignore](https://docs.docker.com/engine/reference/builder/#dockerignore-file)
- [Dockerfile best practices](https://docs.docker.com/develop/develop-images/dockerfile_best-practices/)


# Part 10: What next? - [Link](https://docs.docker.com/get-started/11_what_next/)

## Container orchestration

Running containers in production is tough. You don't want to log into a machine and simply run a `docker run` or `docker compose up`. Why? What if the containers die? How do you scale across serveral machines? Tools like *Kubernestes, Swarm, Nomad, and ECS* all help solve this problem.

General idea is that you have managers who receive the expected state. The managers then look at all of the machines in the cluster and delegate work to workder nodes. The manager watch for changes (such as a container quitting) and then work to make the actual state reflect the expected state.

## Cloud Native Computing Foundation (CNCF) projects

Useful links to the CNCF website:
- [Graduated and incubated projects](https://www.cncf.io/projects/)
- [CNCF Landscape](https://landscape.cncf.io/)
