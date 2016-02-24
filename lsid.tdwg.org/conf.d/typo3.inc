#
# test.tdwg.gbif.org virtual host
#

<VirtualHost test.tdwg.gbif.org:80>
    ServerName test.tdwg.gbif.org
    ServerAdmin ricardo@tdwg.org
    DocumentRoot /var/www/typo3/tdwg/

    RewriteEngine On

    # DON'T enable logging for production!
    RewriteLog /etc/httpd/logs/rewrite.log
    RewriteLogLevel 0

    # Only the IP addresses listed below can see the site while in maintenance
    #RewriteCond %{REMOTE_ADDR} !201.42.185.42
    #RewriteRule /(.*)$ /ACCESS_DENIED.html [L]

    # tests for rules to be used in old MoinMoin TAPIR wiki
    RewriteRule ^/(typo3|typo3temp|typo3conf|t3lib|tslib)/ - [L]
    RewriteRule ^/(fileadmin|uploads)/ - [L]
    RewriteRule ^/(showpic\.php|test|favicon\.ico)$ - [L]
    RewriteRule ^/typo3$ - [L]
    RewriteRule ^/ldap/ - [L]
    RewriteRule ^/authority - [L]

    #RewriteRule ^/ojs/index.php/proceedings/user/register /membership/registration/ [R,L]
    #RewriteRule ^/ojs/index.php/index/user/register /membership/registration/ [R,L]

    # Rule to let OJS work independently of Typo3
    #RewriteRule ^/ojs - [L]
    #RewriteRule ^/zen-cart - [L]
    RewriteRule ^/pywrapper - [L]
    RewriteRule ^/gmaps - [L]
    RewriteRule ^/roger - [L]

    Alias /ojs /var/www/ojs
    Alias /pywrapper_www /var/www/html/pywrapper_www
    Alias /gmaps /var/www/html/gmaps
    Alias /roger /var/www/html/roger

    # let go of Tomcat stuff
    #RewriteRule ^/servlet - [L]
    #RewriteRule ^/examples - [L]
    #RewriteRule ^/tonto/ - [L]
    # not needed

    # If the file/symlink/directory does not exist => Redirect to index.php
    # Important note: If you copy/paste this into httpd.conf instead
    # of .htaccess you will need to add '%{DOCUMENT_ROOT}' left to each
    # '%{REQUEST_FILENAME}' part.
    RewriteCond {REQUEST_FILENAME} !-f
    RewriteCond {REQUEST_FILENAME} !-d
    RewriteCond {REQUEST_FILENAME} !-l

    RewriteRule /(.*)$ /index.php [L,E=ORIG_SCRIPT_NAME:/index.php]

    # for testing purposes, this vh is only visible by localhost and Ricardo
    <Directory "/var/www/typo3/tdwg">
        Order deny,allow
        #Allow from 127.0.0.1, cps.virtua.com.br, gbif.org
        #Deny from all
        #Allow from ::1
        Deny from none
        Allow from all
    </Directory>

include conf.d/ldap_test.inc

</VirtualHost>

<VirtualHost typo3.tdwg.gbif.org:80>
    ServerName typo3.tdwg.gbif.org
    ServerAdmin ricardo@tdwg.org
    DocumentRoot /var/www/html/

    RedirectMatch permanent ^(.*)$ http://www.tdwg.gbif.org$1
</VirtualHost>


<VirtualHost test.tdwg.gbif.org:443>

    DocumentRoot "/var/www/typo3/tdwg/"
    ServerName test.tdwg.gbif.org

    SSLEngine on
    SSLCipherSuite ALL:!ADH:!EXPORT56:RC4+RSA:+HIGH:+MEDIUM:+LOW:+SSLv2:+EXP
    SSLCertificateFile /etc/httpd/conf/ssl.crt/server.crt
    SSLCertificateKeyFile /etc/httpd/conf/ssl.key/server.key

    SetEnvIf User-Agent ".*MSIE.*" \
             nokeepalive ssl-unclean-shutdown \
             downgrade-1.0 force-response-1.0


    RewriteEngine On

    # DON'T enable logging for production!
    RewriteLog /etc/httpd/logs/rewrite.log
    RewriteLogLevel 9

    RewriteRule ^/(typo3|typo3temp|typo3conf|t3lib|tslib)/ - [L]
    RewriteRule ^/(fileadmin|uploads)/ - [L]
    RewriteRule ^/(showpic\.php|test|favicon\.ico)$ - [L]
    RewriteRule ^/typo3$ - [L]

    # If the file/symlink/directory does not exist => Redirect to index.php
    # Important note: If you copy/paste this into httpd.conf instead
    # of .htaccess you will need to add '%{DOCUMENT_ROOT}' left to each
    # '%{REQUEST_FILENAME}' part.
    RewriteCond {REQUEST_FILENAME} !-f
    RewriteCond {REQUEST_FILENAME} !-d
    RewriteCond {REQUEST_FILENAME} !-l

    RewriteRule /(.*)$ /index.php [L,E=ORIG_SCRIPT_NAME:/index.php]

    # for testing purposes, this vh is only visible by localhost and Ricardo
    <Directory "/var/www/typo3/tdwg">
        Order deny,allow
        Deny from all
        Allow from 127.0.0.1, virtua.com.br, gbif.org
        Allow from ::1
	#Deny from none
	#Allow from all
    </Directory>

</VirtualHost>
