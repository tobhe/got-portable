GOT_RELEASE=No
GOT_VERSION_NUMBER=0.47

.if ${GOT_RELEASE} == Yes
GOT_VERSION=${GOT_VERSION_NUMBER}
.else
GOT_VERSION=${GOT_VERSION_NUMBER}-current
.endif
