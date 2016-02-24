<Directory /var/www/typo3/tdwg/ldap>
#	Order allow,deny
#	Allow from none
#	Deny from all

  AuthName LDAP
  AuthType Basic
  AuthLDAPBindDN cn=admin,dc=falcon,dc=tdwg,dc=gbif,dc=org
  AuthLDAPBindPassword tdwg
  AuthLDAPUrl ldaps://falcon.tdwg.gbif.org/ou=people,dc=falcon,dc=tdwg,dc=gbif,dc=org
  require valid-user
</Directory>
